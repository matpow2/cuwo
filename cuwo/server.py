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

from twisted.internet.protocol import Factory, Protocol
from twisted.internet import reactor
from twisted.internet.endpoints import TCP4ClientEndpoint
from twisted.internet.task import LoopingCall
from cuwo.packet import (ServerChatMessage, PacketHandler, write_packet,
    CS_PACKETS, ClientVersion, ServerData, SeedData, EntityUpdate,
    ClientChatMessage, ServerChatMessage, create_entity_data)
from cuwo.entity import EntityData, AppearanceData, EquipmentData
from cuwo.types import IDPool, MultikeyDict
from cuwo import constants

import imp
import shlex

def call_handler(script, name, *arg, **kw):
    f = getattr(script, name, None)
    if f is None:
        return
    ret = f(*arg, **kw)
    if ret is False:
        return False

server_data = ServerData()
seed_data = SeedData()
chat_message = ServerChatMessage()
entity_update = EntityUpdate()

class CubeWorldProtocol(Protocol):
    has_joined = False
    entity_id = None
    entity_data = None

    def __init__(self, factory):
        self.factory = factory

    def send_packet(self, packet):
        self.transport.write(write_packet(packet))

    def on_packet(self, packet):
        packet_id = packet.packet_id
        if packet_id == ClientVersion.packet_id:
            if packet.version != constants.CLIENT_VERSION:
                self.disconnect()
                return
            self.entity_id = self.factory.entity_ids.pop()
            self.entity_data = create_entity_data()
            self.factory.entities[self.entity_id] = self.entity_data
            self.factory.connections[(self.entity_id,)] = self
            server_data.entity_id = self.entity_id
            self.send_packet(server_data)
            seed_data.seed = self.factory.config.seed
            self.send_packet(seed_data)
        elif packet_id == EntityUpdate.packet_id:
            if packet.entity_id != self.entity_id:
                raise NotImplementedError()
            packet.update_entity(self.entity_data)
            if not self.has_joined and self.entity_data.name:
                self.on_join()
                self.has_joined = True
            self.factory.broadcast_packet(packet)
        elif packet_id == ClientChatMessage.packet_id:
            message = packet.value
            if self.on_chat(message) is False:
                return
            chat_message.entity_id = self.entity_id
            chat_message.value = message
            self.factory.broadcast_packet(chat_message)
        else:
            print 'Got client packet:', packet.packet_id

    def on_join(self):
        print 'Player %r joined' % self.entity_data.name
        for connection in self.factory.connections.values():
            if not connection.has_joined:
                continue
            entity_update.set_entity(connection.entity_data,
                                     connection.entity_id)
            self.send_packet(entity_update)
        self.call_scripts('on_join')

    def on_command(self, command, parameters):
        self.call_scripts('on_command', command, parameters)

    def on_chat(self, message):
        if message.startswith('/'):
            try:
                splitted = shlex.split(message[1:])
            except ValueError:
                # shlex failed. let's just split per space
                splitted = value.split(' ')
            if splitted:
                command = splitted.pop(0)
            else:
                command = ''
            self.on_command(command, splitted)
            return False
        return self.call_scripts('on_chat', message)

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

    def disconnect(self):
        self.transport.loseConnection()

    def connectionMade(self):
        self.scripts = []
        self.factory.call_scripts('on_new_connection', self)
        self.packet_handler = PacketHandler(CS_PACKETS, self.on_packet)

    def connectionLost(self, reason):
        try:
            del self.factory.connections[self]
        except KeyError:
            pass
        if self.entity_data is not None:
            del self.factory.entities[self.entity_id]
        self.call_scripts('on_disconnect')

    def dataReceived(self, data):
        self.packet_handler.feed(data)

    def call_scripts(self, name, *arg, **kw):
        for script in self.scripts:
            if call_handler(script, name, *arg, **kw) is False:
                return False
        return True

class CubeWorldFactory(Factory):
    def __init__(self, config):
        self.config = config

        self.connections = MultikeyDict()

        self.entities = {}
        self.entity_ids = IDPool(1)

        self.scripts = []
        for script in config.scripts:
            self.load_script(script)

        self.start_time = reactor.seconds()
        self.update_loop = LoopingCall(self.update)
        self.update_loop.start(1.0 / constants.UPDATE_FPS)
        print 'cuwo running on port 12345'

    def update(self):
        pass

    def broadcast_packet(self, packet):
        data = write_packet(packet)
        for connection in self.connections.values():
            connection.transport.write(data)

    def format(self, value):
        format_dict = {'server_name' : self.config.server_name}
        return value % format_dict

    def format_lines(self, value):
        lines = []
        for line in value:
            lines.append(self.format(line))
        return lines

    def load_script(self, name):
        path = './scripts/%s.py' % name
        try:
            mod = imp.load_source(name, path)
        except IOError:
            return None
        script = mod.get_class()(self)
        return script

    def call_scripts(self, name, *arg, **kw):
        for script in self.scripts:
            if call_handler(script, name, *arg, **kw) is False:
                return False
        return True

    def buildProtocol(self, addr):
        return CubeWorldProtocol(self)

def main():
    import config
    reactor.listenTCP(12345, CubeWorldFactory(config))
    reactor.run()

if __name__ == '__main__':
    main()