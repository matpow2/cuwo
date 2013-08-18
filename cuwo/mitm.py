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
from cuwo.packet import (PacketHandler, write_packet, ServerChatMessage,
                         CS_PACKETS, SC_PACKETS, EntityUpdate,
                         create_entity_data, JoinPacket, CurrentTime)
from cuwo import constants


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


class CubeWorldProtocol(Protocol):
    relay_client = None
    relay_packets = None
    entity_id = None
    disconnected = False

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
        self.times = []

    def print_stats(self):
        if self.disconnected:
            return
        reactor.callLater(15, self.print_stats)

        if self.entity_id is None:
            return
        entity = self.entities[self.entity_id]
        print 'Info:'
        print 'Pos:', entity.pos.x, entity.pos.y, entity.pos.z

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
        elif packet.packet_id == JoinPacket.packet_id:
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
        self.disconnected = True
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
