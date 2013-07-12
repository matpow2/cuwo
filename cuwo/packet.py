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

# --
# note: please give credit where credit is due. a lot of time was spent
# reverse-engineering these structures, so if you're going to use these
# definitions in your own work, it would be nice with a little notice of
# where you got them from (i.e. cuwo) :-)

from cuwo.entity import (EntityData, AppearanceData, EquipmentData, 
    read_masked_data, write_masked_data)
from cuwo.loader import Loader
from bytes import ByteReader, ByteWriter, OutOfData
import zlib

class Packet(Loader):
    packet_id = None

class ClientVersion(Packet):
    def read(self, reader):
        self.version = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.version)

class ServerFull(Packet):
    pass

class ServerMismatch(Packet):
    pass

class ServerData(Packet):
    data = None
    def read(self, reader):
        if reader.read_uint32() != 0:
            raise NotImplementedError()
            return
        self.entity_id = reader.read_uint64() # must be > 1 and < 10
        self.data = EntityData()
        self.data.read(reader)

    def write(self, writer):
        writer.write_uint32(0)
        writer.write_uint64(self.entity_id)
        if self.data is None:
            writer.write('\x00' * 0x1168)
        else:
            self.data.write(writer)

class SeedData(Packet):
    def read(self, reader):
        self.seed = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.seed)

class EntityUpdate(Packet):
    def read(self, reader):
        size = reader.read_uint32()
        self.data = zlib.decompress(reader.read(size))
        reader = ByteReader(self.data)
        self.entity_id = reader.read_uint64()

    def update_entity(self, entity):
        reader = ByteReader(self.data)
        reader.skip(8)
        read_masked_data(entity, reader)

    def set_entity(self, entity, entity_id):
        writer = ByteWriter()
        writer.write_uint64(entity_id)
        write_masked_data(entity, writer)
        self.data = writer.get()

    def write(self, writer):
        data = zlib.compress(self.data)
        writer.write_uint32(len(data))
        writer.write(data)

class Unknown1(Packet):
    def read(self, reader):
        count = reader.read_uint32()
        self.items = []
        for i in xrange(count):
            something = reader.read_uint64()
            # breaks off here
            something2 = reader.read_uint64()
            # socket reads, as follows:
            # 24, 12, 12, 12, 12, 4, 4, 1, 4, 1, 4, 4, 4, 172, 2, 4, 4, 4, 4,
            # 4, 4, 1, 1, 4, 12, 12, 12, 4, 4, 4, 20, 1, 1, 4, 4, 8, 8, 1, 4,
            # 12, 24, 12, 1, 280, 3640, 16, 44, 4
            # sum: 4434
            data = reader.read(4434)
            self.items.append((something, something2, data))

    def write(self, writer):
        writer.write_uint32(len(self.items))
        for item in items:
            something, something2, data = item
            writer.write_uint64(something)
            writer.write_uint64(something2)
            writer.write(data)

class Unknown2(Packet):
    pass

class Unknown3(Packet):
    def read(self, reader):
        count = reader.read_uint32()
        self.data = reader.read(120 * count)

    def write(self, writer):
        writer.write_uint32(len(self.data) / 120)
        writer.write(self.data)

class debug:
    should_open = True

class Unknown4(Packet):
    def read(self, reader):
        size = reader.read_uint32()
        self.data = zlib.decompress(reader.read(size))
        reader = ByteReader(self.data)
        items = reader.read_uint32()

    def write(self, writer):
        data = zlib.compress(self.data)
        writer.write_uint32(len(data))
        writer.write(data)

class Unknown5(Packet):
    def read(self, reader):
        self.something = reader.read_uint32()
        self.something2 = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.something)
        writer.write_uint32(self.something2)

INTERACT_NPC = 2
INTERACT_NORMAL = 3
INTERACT_PICKUP = 5
INTERACT_DROP = 6
INTERACT_EXAMINE = 8

class InteractPacket(Packet):
    def read(self, reader):
        self.equipment = EquipmentData()
        self.equipment.read(reader)
        self.something = reader.read_int32()
        self.something2 = reader.read_int32()
        self.something3 = reader.read_int32()
        #
        self.something4 = reader.read_uint32()
        self.interact_type = reader.read_uint8()
        self.something6 = reader.read_uint8()
        self.something7 = reader.read_uint16()
        print vars(self)

    def write(self, writer):
        self.equipment.write(writer)
        writer.write_int32(self.something)
        writer.write_int32(self.something2)
        writer.write_int32(self.something3)
        writer.write_uint32(self.something4)
        writer.write_uint8(self.something5)
        writer.write_uint8(self.something6)
        writer.write_uint16(self.something7)

class HitPacket(Packet):
    def read(self, reader):
        self.something = reader.read_uint32()
        self.something2 = reader.read_uint32()
        self.something3 = reader.read_uint32()
        self.something4 = reader.read_uint32()
        self.something5 = reader.read_uint32()
        self.something6 = reader.read_uint8()
        reader.skip(3)
        self.something7 = reader.read_uint32()
        self.something8 = reader.read_uint32()
        self.something9 = reader.read_uint32()
        self.something10 = reader.read_uint32()
        self.something11 = reader.read_uint32()
        self.something12 = reader.read_uint32()
        self.something13 = reader.read_uint32()
        self.something14 = reader.read_uint32()
        self.something15 = reader.read_uint32()
        self.something16 = reader.read_uint32()
        self.something17 = reader.read_uint32()
        self.something18 = reader.read_uint8()
        self.something19 = reader.read_uint8()
        self.something20 = reader.read_uint8()
        reader.skip(1)
        print vars(self)

    def write(self, writer):
        writer.write_uint32(self.something)
        writer.write_uint32(self.something2)
        writer.write_uint32(self.something3)
        writer.write_uint32(self.something4)
        writer.write_uint32(self.something5)
        writer.write_uint8(self.something6)
        writer.pad(3)
        writer.write_uint32(self.something7)
        writer.write_uint32(self.something8)
        writer.write_uint32(self.something9)
        writer.write_uint32(self.something10)
        writer.write_uint32(self.something11)
        writer.write_uint32(self.something12)
        writer.write_uint32(self.something13)
        writer.write_uint32(self.something14)
        writer.write_uint32(self.something15)
        writer.write_uint32(self.something16)
        writer.write_uint32(self.something17)
        writer.write_uint8(self.something18)
        writer.write_uint8(self.something19)
        writer.write_uint8(self.something20)
        writer.pad(1)

class Unknown8(Packet):
    def read(self, reader):
        self.data = reader.read(40)

    def write(self, writer):
        writer.write(self.data)

class Unknown9(Packet):
    def read(self, reader):
        self.data = reader.read(112)

    def write(self, writer):
        writer.write(self.data)

ENCODING = 'utf_16_le'

class ServerChatMessage(Packet):
    def read(self, reader):
        self.entity_id = reader.read_uint64()
        size = reader.read_uint32()
        data = reader.read(size * 2)
        self.value = data.decode(ENCODING)

    def write(self, writer):
        writer.write_uint64(self.entity_id)
        data = self.value.encode(ENCODING)
        writer.write_uint32(len(data) / 2)
        writer.write(data)

class ClientChatMessage(Packet):
    def read(self, reader):
        size = reader.read_uint32()
        data = reader.read(size * 2)
        self.value = data.decode(ENCODING)

    def write(self, writer):
        data = self.value.encode(ENCODING)
        writer.write_uint32(len(data) / 2)
        writer.write(data)

class ClientReadChunk(Packet):
    def read(self, reader):
        self.x = reader.read_uint32()
        self.y = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.x)
        writer.write_uint32(self.y)

class Unknown12(Packet):
    # something to do with chunk-loading as well
    def read(self, reader):
        self.x = reader.read_uint32()
        self.y = reader.read_uint32()   

    def write(self, writer):
        writer.write_uint32(self.x)
        writer.write_uint32(self.y)

CS_PACKETS = {
    0 : EntityUpdate,
    6 : InteractPacket,
    7 : HitPacket,
    8 : Unknown8, # stealth
    9 : Unknown9, # shoot arrow
    10 : ClientChatMessage,
    11 : ClientReadChunk, # sent when client has loaded new chunk in memory
    12 : Unknown12, # related to chunk loading, uses the same routine as above
    17 : ClientVersion
}

SC_PACKETS = {
    0 : EntityUpdate,
    1 : Unknown1,
    2 : Unknown2,
    3 : Unknown3,
    4 : Unknown4,
    5 : Unknown5,
    10 : ServerChatMessage,
    18 : ServerMismatch,
    17 : ServerFull,
    16 : ServerData,
    15 : SeedData
}

def read_packet(reader, table):
    packet_id = reader.read_uint32()
    packet = table[packet_id]()
    packet.read(reader)
    return packet

def write_packet(packet):
    writer = ByteWriter()
    writer.write_uint32(packet.packet_id)
    packet.write(writer)
    return writer.get()

for table in (CS_PACKETS, SC_PACKETS):
    for k, v in table.iteritems():
        v.packet_id = k

class PacketHandler(object):
    data = ''

    def __init__(self, table, callback):
        self.table = table
        self.callback = callback

    def feed(self, data):
        self.data += data
        reader = ByteReader(self.data)
        while True:
            pos = reader.tell()
            if pos >= len(self.data):
                break
            try:
                packet = read_packet(reader, self.table)
            except OutOfData:
                break
            self.callback(packet)
        self.data = self.data[pos:]