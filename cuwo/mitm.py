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
    CS_PACKETS, SC_PACKETS, EntityUpdate, create_entity_data, ServerData,
    CurrentTime, ShootPacket, Unknown4)
from cuwo import constants
from cuwo.common import get_chunk

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
    entity_id = None

    def __init__(self, server):
        self.server = server
        self.start_time = reactor.seconds()
        self.client_handler = PacketHandler(CS_PACKETS,
                                            self.on_client_packet)
        self.server_handler = PacketHandler(SC_PACKETS,
                                            self.on_server_packet)
        self.entities = {}
        self.relay_packets = []
        self.print_stats()
        # self.send_debug()

    def send_debug(self):
        reactor.callLater(0.01, self.send_debug)
        if self.entity_id is None:
            return
        entity = self.entities[self.entity_id]
        from cuwo.vector import Vector3
        shoot = ShootPacket()
        shoot.entity_id = 2
        shoot.chunk_x, shoot.chunk_y = get_chunk(
            Vector3(entity.x, entity.y, entity.z))
        import random
        shoot.something5 = random.randrange(0, 10)
        shoot.something13 = 0
        shoot.something14 = 0
        shoot.something15 = 0
        shoot.something19 = 10.49137020111084
        shoot.something20 = 0.5
        shoot.something21 = 1.0
        shoot.something22 = 0.0
        shoot.something23 = 0
        shoot.something24 = 0
        shoot.something25 = 0
        shoot.something26 = 0
        shoot.something27 = 0
        shoot.something28 = 0
        shoot.pos = Vector3(entity.x, entity.y, entity.z + 150000)
        shoot.velocity = Vector3(93.929801940, -34.1773529054, -3.0167741775)
        self.relay_client.transport.write(write_packet(shoot))

    def print_stats(self):
        reactor.callLater(4, self.print_stats)

        if self.entity_id is None:
            return
        entity = self.entities[self.entity_id]
        print 'Info:'
        print 'Pos:', entity.x, entity.y, entity.z

    def send_chat(self, value):
        packet = ServerChatMessage()
        packet.entity_id = 0
        packet.value = value
        self.transport.write(write_packet(packet))

    def on_entity_update(self, packet):
        if packet.entity_id not in self.entities:
            entity = create_entity_data()
            self.entities[packet.entity_id] = entity
        else:
            entity = self.entities[packet.entity_id]
        packet.update_entity(entity)

    def on_client_packet(self, packet):
        if packet.packet_id == EntityUpdate.packet_id:
            self.on_entity_update(packet)
        if self.relay_client is None:
            self.relay_packets.append(write_packet(packet))
            return
        self.relay_client.transport.write(write_packet(packet))
        if packet.packet_id not in (0,):
            print 'Got client packet:', packet.packet_id

    def on_server_packet(self, packet):
        if packet.packet_id == EntityUpdate.packet_id:
            self.on_entity_update(packet)
        elif packet.packet_id == ServerData.packet_id:
            self.entity_id = packet.entity_id
        elif packet.packet_id == CurrentTime.packet_id:
            # I hate darkness
            packet.time = constants.MAX_TIME / 2
        self.transport.write(write_packet(packet))
        if packet.packet_id not in (0, 2, 4, 5):
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