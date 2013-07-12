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
from cuwo.packet import (PacketHandler, write_packet, ServerChatMessage,
    CS_PACKETS, SC_PACKETS, EntityUpdate)

class debug:
    packets_printed = 0
    max_packets = 4

class RelayClient(Protocol):
    def __init__(self, protocol):
        self.protocol = protocol

    def dataReceived(self, data):
        self.protocol.serverDataReceived(data)

class RelayFactory(Factory):
    def __init__(self, protocol):
        self.protocol = protocol

    def buildProtocol(self, addr):
        return RelayClient(self.protocol)

import collections

server_ids = collections.Counter()
client_ids = collections.Counter()

class CubeWorldProtocol(Protocol):
    relay_client = None
    relay_packets = None

    def __init__(self, server):
        self.server = server
        self.client_handler = PacketHandler(CS_PACKETS,
                                            self.on_client_packet)
        self.server_handler = PacketHandler(SC_PACKETS,
                                            self.on_server_packet)
        self.relay_packets = []
        self.print_stats()

    def print_stats(self):
        return
        reactor.callLater(3, self.print_stats)
        print 'Server packets:', server_ids
        print 'Client packets:', client_ids 

    def send_welcome(self):
        lines = [u'Hello %s! Welcome to the server!' % self.name,
                 u'(server powered by cuwo)']
        for line in reversed(lines):
            self.send_chat(line)

    def send_chat(self, value):
        packet = ServerChatMessage()
        packet.entity_id = 0
        packet.value = value
        self.transport.write(write_packet(packet))

    def on_client_packet(self, packet):
        if packet.packet_id in (12, 11):
            return
        if self.relay_client is None:
            self.relay_packets.append(write_packet(packet))
            return
        self.relay_client.transport.write(write_packet(packet))
        client_ids[packet.packet_id] += 1
        if packet.packet_id == EntityUpdate.packet_id:
            try:
                name = packet.entity.name
                if not name:
                    return
                self.name = name
                reactor.callLater(10, self.send_welcome)
            except AttributeError:
                pass
            return
        if packet.packet_id in (11, 12):
            return # ignore for now
        print 'Got client packet:', packet.packet_id

    def on_server_packet(self, packet):
        self.transport.write(write_packet(packet))
        server_ids[packet.packet_id] += 1
        if packet.packet_id in (0, 2, 4, 5):
            return
        print 'Got server packet:', packet.packet_id

    def got_relay_client(self, p):
        self.relay_client = p
        for data in self.relay_packets:
            self.relay_client.transport.write(data)
        self.relay_packets = None

    def connectionMade(self):
        point = TCP4ClientEndpoint(reactor, "127.0.0.1", 12346)
        d = point.connect(RelayFactory(self))
        d.addCallback(self.got_relay_client)
        print 'Connected'

    def connectionLost(self, reason):
        print 'Lost connection'
        if self.relay_client is not None:
            self.relay_client.transport.loseConnection()

    def serverDataReceived(self, data):
        self.server_handler.feed(data)

    def dataReceived(self, data):
        self.client_handler.feed(data)

class CubeWorldServer(Factory):
    def __init__(self):
        print 'cuwo (mitm) running on port 12345'

    def buildProtocol(self, addr):
        return CubeWorldProtocol(self)

def main():
    reactor.listenTCP(12345, CubeWorldServer())
    reactor.run()

if __name__ == '__main__':
    main()