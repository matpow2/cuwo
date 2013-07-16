# Copyright (c) Mathias Kaerlev 2013.
#
# This file is part of cuwo.
# 
# cuwo is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# cuwo is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with cuwo.  If not, see <http://www.gnu.org/licenses/>.

from cuwo.twistedreactor import install_reactor
install_reactor()
from twisted.internet.protocol import Factory, Protocol
from twisted.internet import reactor
from twisted.internet.endpoints import TCP4ClientEndpoint
from twisted.internet.task import LoopingCall

from cuwo.packet import (ServerChatMessage, PacketHandler, write_packet,
    CS_PACKETS, ClientVersion, JoinPacket, SeedData, EntityUpdate,
    ClientChatMessage, ServerChatMessage, create_entity_data, UpdateFinished,
    CurrentTime, ServerUpdate, ServerFull, ServerMismatch)
from cuwo.types import IDPool, MultikeyDict, AttributeSet
from cuwo.vector import Vector3
from cuwo import constants
from cuwo.common import get_clock_string, parse_clock, parse_command

import collections
import imp
import os
import sys

def call_handler(script, name, *arg, **kw):
    f = getattr(script, name, None)
    if f is None:
        return
    ret = f(*arg, **kw)
    if ret is False:
        return False

# initialize packet instances for sending
join_packet = JoinPacket()
seed_packet = SeedData()
chat_packet = ServerChatMessage()
entity_packet = EntityUpdate()
update_finished_packet = UpdateFinished()
time_packet = CurrentTime()
mismatch_packet = ServerMismatch()
server_full_packet = ServerFull()

class CubeWorldProtocol(Protocol):
    has_joined = False
    entity_id = None
    entity_data = None
    disconnected = False

    def __init__(self, factory, addr):
        self.address = addr
        self.factory = factory

    # connection methods

    def connectionMade(self):
        self.packet_handlers = {
            ClientVersion.packet_id : self.on_version_packet,
            EntityUpdate.packet_id : self.on_entity_packet,
            ClientChatMessage.packet_id : self.on_chat_packet
        }
        
        self.scripts = []
        self.factory.call_scripts('on_new_connection', self)
        self.packet_handler = PacketHandler(CS_PACKETS, self.on_packet)
        self.rights = AttributeSet()

    def dataReceived(self, data):
        self.packet_handler.feed(data)

    def disconnect(self):
        self.transport.loseConnection()
        self.connectionLost('Kicked by server')

    def connectionLost(self, reason):
        if self.disconnected:
            return
        self.disconnected = True
        try:
            del self.factory.connections[self]
        except KeyError:
            pass
        if self.entity_data is not None:
            del self.factory.entities[self.entity_id]
        if self.entity_id is not None:
            self.factory.entity_ids.put_back(self.entity_id)
        for script in self.scripts[:]:
            script.unload()

    # packet methods

    def send_packet(self, packet):
        self.transport.write(write_packet(packet))

    def on_packet(self, packet):
        handler = self.packet_handlers.get(packet.packet_id, None)
        if handler is None:
            # print 'Unhandled client packet: %s' % packet.packet_id
            return
        handler(packet)

    def on_version_packet(self, packet):
        if packet.version != constants.CLIENT_VERSION:
            mismatch_packet.version = constants.CLIENT_VERSION
            self.send_packet(mismatch_packet)
            self.disconnect()
            return
        if len(self.factory.connections) >= self.factory.config.max_players:
            self.send_packet(server_full_packet)
            self.disconnect()
            return
        self.entity_id = self.factory.entity_ids.pop()
        self.factory.connections[(self.entity_id,)] = self
        join_packet.entity_id = self.entity_id
        self.send_packet(join_packet)
        seed_packet.seed = self.factory.config.seed
        self.send_packet(seed_packet)

    def on_entity_packet(self, packet):
        if self.entity_data is None:
            self.entity_data = create_entity_data()
            self.factory.entities[self.entity_id] = self.entity_data
        packet.update_entity(self.entity_data)
        if not self.has_joined and self.entity_data.name:
            self.on_join()
            self.has_joined = True

    def on_chat_packet(self, packet):
        message = packet.value
        if self.on_chat(message) is False:
            return
        chat_packet.entity_id = self.entity_id
        chat_packet.value = message
        self.factory.broadcast_packet(chat_packet)

    # handlers

    def on_join(self):
        print 'Player %r joined' % self.entity_data.name
        for connection in self.factory.connections.values():
            if not connection.has_joined:
                continue
            entity_packet.set_entity(connection.entity_data,
                                     connection.entity_id)
            self.send_packet(entity_packet)
        self.call_scripts('on_join')

    def on_command(self, command, parameters):
        self.call_scripts('on_command', command, parameters)

    def on_chat(self, message):
        if message.startswith('/'):
            command, args = parse_command(message[1:])
            self.on_command(command, args)
            return False
        return self.call_scripts('on_chat', message)

    # other methods

    def send_chat(self, value):
        packet = ServerChatMessage()
        packet.entity_id = 0
        packet.value = value
        self.send_packet(packet)

    def send_lines(self, lines):
        current_time = 0
        for line in lines:
            reactor.callLater(current_time, self.send_chat, line)
            current_time += 2

    def kick(self):
        self.send_chat('You have been kicked')
        self.disconnect()
        self.factory.send_chat('%s has been kicked' % self.get_name())

    def call_scripts(self, name, *arg, **kw):
        for script in self.scripts:
            if call_handler(script, name, *arg, **kw) is False:
                return False
        return True

    # convienience methods

    def get_position(self):
        if self.entity_data is None:
            return None
        return Vector3(self.entity_data.x, 
                       self.entity_data.y,
                       self.entity_data.z)

    def get_name(self):
        if self.entity_data is None:
            return None
        return self.entity_data.name

class CubeWorldFactory(Factory):
    def __init__(self, config):
        self.config = config

        # game-related
        self.update_packet = ServerUpdate()
        self.update_packet.reset()
        self.connections = MultikeyDict()

        self.items = []
        self.entities = {}
        self.entity_ids = IDPool(1)

        self.update_loop = LoopingCall(self.update)
        self.update_loop.start(1.0 / constants.UPDATE_FPS, False)

        # server-related
        self.git_rev = getattr(config, 'git_rev', None)

        self.passwords = {}
        for k, v in config.passwords.iteritems():
            self.passwords[k.lower()] = v

        self.scripts = []
        for script in config.scripts:
            self.load_script(script)

        # time
        self.extra_elapsed_time = 0.0
        self.start_time = reactor.seconds()
        self.set_time('12:00')

    def buildProtocol(self, addr):
        # return None here to refuse the connection.
        # will use this later to hardban e.g. DoS
        return CubeWorldProtocol(self, addr)

    def update(self):
        # entity updates
        for entity_id, entity in self.entities.iteritems():
            entity_packet.set_entity(entity, entity_id)
            self.broadcast_packet(entity_packet)
        self.broadcast_packet(update_finished_packet)

        # other updates
        # chunk_items = collections.defaultdict(list)
        # for item in self.items:
        #     chunk_x, chunk_y = get_chunk(item.pos)
        #     chunk_items[(chunk_x, chunk_y)].append
        self.broadcast_packet(self.update_packet)
        self.update_packet.reset()

        # time update
        time_packet.time = self.get_time()
        time_packet.day = self.get_day()
        self.broadcast_packet(time_packet)

    def send_chat(self, value):
        packet = ServerChatMessage()
        packet.entity_id = 0
        packet.value = value
        self.broadcast_packet(packet)

    def broadcast_packet(self, packet):
        data = write_packet(packet)
        for connection in self.connections.values():
            connection.transport.write(data)

    # line/string formatting options based on config

    def format(self, value):
        format_dict = {'server_name' : self.config.server_name}
        return value % format_dict

    def format_lines(self, value):
        lines = []
        for line in value:
            lines.append(self.format(line))
        return lines

    # script methods

    def load_script(self, name):
        path = './scripts/%s.py' % name
        try:
            mod = imp.load_source(name, path)
        except IOError:
            return None
        script = mod.get_class()(self)
        print 'Loaded script %r' % name
        return script

    def call_scripts(self, name, *arg, **kw):
        for script in self.scripts:
            if call_handler(script, name, *arg, **kw) is False:
                return False
        return True

    # time methods

    def set_time(self, value):
        day = self.get_day()
        time = parse_clock(value)
        self.start_time = reactor.seconds()
        self.extra_elapsed_time = day * constants.MAX_TIME + time

    def get_elapsed_time(self):
        dt = reactor.seconds() - self.start_time
        dt *= self.config.time_modifier * constants.NORMAL_TIME_SPEED
        return dt * 1000 + self.extra_elapsed_time

    def get_time(self):
        return int(self.get_elapsed_time() % constants.MAX_TIME)

    def get_day(self):
        return int(self.get_elapsed_time() / constants.MAX_TIME)

    def get_clock(self):
        return get_clock_string(self.get_time())

def main():
    # for py2exe
    if hasattr(sys, 'frozen'):
        path = os.path.dirname(
            unicode(sys.executable, sys.getfilesystemencoding()))
        sys.path.append(path)

    import config
    reactor.listenTCP(constants.SERVER_PORT, CubeWorldFactory(config))
    print 'cuwo running on port %s' % constants.SERVER_PORT
    reactor.run()

if __name__ == '__main__':
    main()