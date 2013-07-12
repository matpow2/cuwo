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
from cuwo.packet import (ServerChatMessage, PacketHandler, write_packet,
    CS_PACKETS, ClientVersion, ServerData, SeedData)
from cuwo.types import IDPool, MultikeyDict
from cuwo import constants

import imp

def call_handler(script, name, *arg, **kw):
    f = getattr(script, name, None)
    if f is None:
        return
    ret = f(*arg, **kw)
    if ret is False:
        return False

server_data = ServerData()
seed_data = SeedData()

class CubeWorldProtocol(Protocol):
    relay_client = None
    relay_packets = None

    def __init__(self, factory):
        self.factory = factory
        self.packet_handler = PacketHandler(CS_PACKETS, self.on_packet)
        self.scripts = []

    def send_packet(self, packet):
        self.transport.write(write_packet(packet))

    def on_packet(self, packet):
        packet_id = packet.packet_id
        if packet_id == ClientVersion.packet_id:
            if packet.version != constants.CLIENT_VERSION:
                self.disconnect()
                return
            self.entity_id = self.factory.entity_ids.pop()
            self.factory.connections[(self.entity_id,)] = self
            server_data.entity_id = self.entity_id
            self.send_packet(server_data)
            seed_data.seed = self.factory.config.seed
            self.send_packet(seed_data)

        print 'Got client packet:', packet.packet_id

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
        pass

    def connectionLost(self, reason):
        try:
            del self.factory.connections[self]
        except KeyError:
            pass
        self.call_scripts('on_disconnect')

    def dataReceived(self, data):
        self.packet_handler.feed(data)

    def call_scripts(self, name, *arg, **kw):
        for script in self.scripts:
            if call_handler(script, name, *arg, **kw) is False:
                return False
        return True

class CubeWorldFactory(Factory):
    def __init__(self):
        import config
        self.config = config

        self.connections = MultikeyDict()
        self.entity_ids = IDPool(1)

        self.scripts = []
        for script in config.scripts:
            self.load_script(script)

        print 'cuwo running on port 12345'

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

    def buildProtocol(self, addr):
        return CubeWorldProtocol(self)

def main():
    reactor.listenTCP(12345, CubeWorldFactory())
    reactor.run()

if __name__ == '__main__':
    main()