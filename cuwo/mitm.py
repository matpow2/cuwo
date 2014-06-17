# Copyright (c) Mathias Kaerlev 2013-2014.
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

from cuwo.packet import (PacketHandler, write_packet, ServerChatMessage,
                         CS_PACKETS, SC_PACKETS, EntityUpdate,
                         create_entity_data, JoinPacket, CurrentTime,
                         ClientChatMessage, UpdateFinished, ServerUpdate,
                         InteractPacket)
from cuwo import constants
import sys
import asyncio
import signal


class BackendProtocol(asyncio.Protocol):
    def __init__(self, protocol):
        self.protocol = protocol
        protocol.relay_client = self

    def connection_made(self, transport):
        self.transport = transport

    def data_received(self, data):
        self.protocol.server_data_received(data)


class FrontendProtocol(asyncio.Protocol):
    relay_client = None
    relay_packets = None
    entity_id = None
    disconnected = False
    update_index = 0

    def __init__(self, loop):
        self.loop = loop
        self.start_time = self.loop.time()
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
        self.loop.call_later(15, self.print_stats)

        if self.entity_id is None:
            return
        entity = self.entities[self.entity_id]
        print('Info:')
        print('Pos:', entity.pos.x, entity.pos.y, entity.pos.z)

    def send_chat(self, value):
        packet = ServerChatMessage()
        packet.entity_id = 0
        packet.value = value
        self.transport.write(write_packet(packet))

    def send_client_chat(self, value):
        packet = ClientChatMessage()
        packet.value = value
        self.relay_client.transport.write(write_packet(packet))

    def on_entity_update(self, packet):
        if packet.entity_id not in self.entities:
            entity = create_entity_data()
            self.entities[packet.entity_id] = entity
        else:
            entity = self.entities[packet.entity_id]
        packet.update_entity(entity)

    def on_server_update(self, packet):
        for static_entity in packet.static_entities:
            print(vars(static_entity))

    def on_client_packet(self, packet):
        if packet.packet_id == EntityUpdate.packet_id:
            self.on_entity_update(packet)
        if self.relay_client is None:
            self.relay_packets.append(write_packet(packet))
            return
        if packet.packet_id == InteractPacket.packet_id:
            print(vars(packet))
        self.relay_client.transport.write(write_packet(packet))
        if packet.packet_id not in (0,):
            print('Got client packet:', packet.packet_id)

    def on_server_packet(self, packet):
        if packet.packet_id == EntityUpdate.packet_id:
            self.on_entity_update(packet)
        elif packet.packet_id == JoinPacket.packet_id:
            self.entity_id = packet.entity_id
        elif packet.packet_id == CurrentTime.packet_id:
            # I hate darkness
            packet.time = constants.MAX_TIME / 2
        elif packet.packet_id == ServerUpdate.packet_id:
            self.on_server_update(packet)
        self.transport.write(write_packet(packet))
        if packet.packet_id not in (EntityUpdate.packet_id,
                                    UpdateFinished.packet_id,
                                    CurrentTime.packet_id,
                                    ServerUpdate.packet_id):
            print('Got server packet:', packet.packet_id)

    def got_relay_client(self, f):
        for data in self.relay_packets:
            self.relay_client.transport.write(data)
        self.relay_packets = None

    def connection_made(self, transport):
        self.transport = transport
        print('On connection')
        co = self.loop.create_connection(lambda: BackendProtocol(self),
                                         '127.0.0.1', 12346)
        asyncio.Task(co).add_done_callback(self.got_relay_client)

    def connection_lost(self, reason):
        self.disconnected = True
        print('Lost connection')
        if self.relay_client is not None:
            self.relay_client.transport.close()

    def server_data_received(self, data):
        # self.transport.write(data)
        self.server_handler.feed(data)

    def data_received(self, data):
        # if self.relay_client is None:
        #     self.relay_packets.append(data)
        #     return
        # self.relay_client.transport.write(data)
        self.client_handler.feed(data)


def main():
    if sys.platform == 'win32':
        from cuwo.win32 import WindowsEventLoop
        loop = WindowsEventLoop()
        asyncio.set_event_loop(loop)

        # asyncio has poor support for signals on win32.
        # use a busy loop to properly receive SIGINT
        def busy_loop():
            loop.call_later(0.1, busy_loop)
        busy_loop()
    else:
        loop = asyncio.get_event_loop()

    loop.add_signal_handler(signal.SIGINT, loop.stop)
    co = loop.create_server(lambda: FrontendProtocol(loop), '127.0.0.1', 12345)
    asyncio.Task(co)
    print('cuwo (mitm) running on port 12345')

    loop.run_forever()

if __name__ == '__main__':
    main()
