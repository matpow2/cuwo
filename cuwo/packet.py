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
    read_masked_data, write_masked_data, get_masked_size)
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
    def read(self, reader):
        self.version = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.version)

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

class MultipleEntityUpdate(Packet):
    def read(self, reader):
        count = reader.read_uint32()
        self.items = []
        for i in xrange(count):
            entity_id = reader.read_uint64()
            mask = reader.read_uint64()
            reader.rewind(8)
            masked_data = reader.read(get_masked_size(mask) + 8)
            self.items.append((entity_id, masked_data))

    def write(self, writer):
        writer.write_uint32(len(self.items))
        for item in items:
            entity_id, masked_data = item
            writer.write_uint64(entity_id)
            writer.write(masked_data)

class UpdateFinished(Packet):
    # called when entity update (packet 0) is finished
    pass

class Unknown3(Packet):
    def read(self, reader):
        count = reader.read_uint32()
        self.data = reader.read(120 * count)

    def write(self, writer):
        writer.write_uint32(len(self.data) / 120)
        writer.write(self.data)

class Packet4Struct1(Loader):
    def read(self, reader):
        self.something = reader.read_uint32()
        self.something2 = reader.read_uint32()
        self.something3 = reader.read_uint32()
        self.something4 = reader.read_uint8()
        self.something5 = reader.read_uint8()
        self.something6 = reader.read_uint8()
        self.something7 = reader.read_uint8()
        self.something8 = reader.read_uint32()

class Unknown4(Packet):
    def read(self, reader):
        size = reader.read_uint32()
        self.data = zlib.decompress(reader.read(size))
        reader = ByteReader(self.data)

        self.items_1 = []
        for _ in xrange(reader.read_uint32()):
            item = Packet4Struct1() # 20 bytes
            item.read(reader)
            self.items_1.append(item)

        # on hit?
        self.items_2 = []
        for _ in xrange(reader.read_uint32()):
            self.items_2.append(reader.read(72))

        self.items_3 = []
        for _ in xrange(reader.read_uint32()):
            self.items_3.append(reader.read(72))

        # perform attack?
        self.items_4 = []
        for _ in xrange(reader.read_uint32()):
            self.items_4.append(reader.read(24))

        self.items_5 = []
        for _ in xrange(reader.read_uint32()):
            self.items_5.append(reader.read(112))

        self.items_6 = []
        for _ in xrange(reader.read_uint32()):
            self.items_6.append(reader.read(88))

        self.items_7 = []
        for _ in xrange(reader.read_uint32()):
            something = reader.read_uint64()
            sub_items = []
            for _ in xrange(reader.read_uint32()):
                item = EquipmentData()
                item.read(reader)
                data = reader.read(48)
                sub_items.append((item, data))
            self.items_7.append((something, sub_items))

        self.items_8 = []
        for _ in xrange(reader.read_uint32()):
            something = reader.read_uint64()
            sub_items = []
            for _ in xrange(reader.read_uint32()):
                sub_items.append(reader.read(16))
            self.items_8.append((soemthing, sub_items))

        # pickup?
        self.items_9 = []
        for _ in xrange(reader.read_uint32()):
            item = EquipmentData()
            item.read(reader)
            something = reader.read_uint32()
            something2 = reader.read_uint32()
            self.items_9.append((item, something, something2))

        self.items_10 = []
        for _ in xrange(reader.read_uint32()):
            self.items_10.append(reader.read(24))

        # follow player?
        self.items_11 = []
        for _ in xrange(reader.read_uint32()):
            self.items_11.append(reader.read(24))

        self.items_12 = []
        for _ in xrange(reader.read_uint32()):
            self.items_12.append(reader.read(40))

        self.items_13 = []
        for _ in xrange(reader.read_uint32()):
            self.items_13.append(reader.read(56))

        debug = False
        if debug:
            v = vars(self).copy()
            del v['data']
            for k, v in v.iteritems():
                if not v:
                    continue
                print k, v

        if len(self.data) != reader.tell():
            raise NotImplementedError()

    def write(self, writer):
        data = zlib.compress(self.data)
        writer.write_uint32(len(data))
        writer.write(data)

class CurrentTime(Packet):
    def read(self, reader):
        self.day = reader.read_uint32()
        self.time = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.day)
        writer.write_uint32(self.time)

INTERACT_NPC = 2
INTERACT_NORMAL = 3
INTERACT_PICKUP = 5
INTERACT_DROP = 6
INTERACT_EXAMINE = 8

class InteractPacket(Packet):
    def read(self, reader):
        self.equipment = EquipmentData()
        self.equipment.read(reader)
        self.chunk_x = reader.read_int32()
        self.chunk_y = reader.read_int32()
        self.chunk_z = reader.read_int32()
        #
        self.something4 = reader.read_uint32()
        self.interact_type = reader.read_uint8()
        self.something6 = reader.read_uint8()
        self.something7 = reader.read_uint16()
        print vars(self)

    def write(self, writer):
        self.equipment.write(writer)
        writer.write_int32(self.chunk_x)
        writer.write_int32(self.chunk_y)
        writer.write_int32(self.chunk_z)
        writer.write_uint32(self.something4)
        writer.write_uint8(self.interact_type)
        writer.write_uint8(self.something6)
        writer.write_uint16(self.something7)

class HitPacket(Packet):
    def read(self, reader):
        self.attacker_entity = reader.read_uint64()
        self.target_entity = reader.read_uint64()
        self.damage = reader.read_float()
        self.critical = reader.read_uint8()
        reader.skip(3)
        self.stun_duration = reader.read_uint32()
        self.something8 = reader.read_uint32()
        self.hit_x = reader.read_int64()
        self.hit_y = reader.read_int64()
        self.hit_z = reader.read_int64()
        self.something15 = reader.read_uint32()
        self.something16 = reader.read_uint32()
        self.something17 = reader.read_uint32()
        self.skill_hit = reader.read_uint8()
        self.evading = reader.read_uint8()
        self.something20 = reader.read_uint8()
        reader.skip(1)

    def write(self, writer):
        writer.write_uint64(self.attacker_entity)
        writer.write_uint64(self.target_entity)
        writer.write_float(self.damage)
        writer.write_uint8(self.critical)
        reader.pad(3)
        writer.write_uint32(self.stun_duration)
        writer.write_uint32(self.something8)
        writer.write_int64(self.hit_x)
        writer.write_int64(self.hit_y)
        writer.write_int64(self.hit_z)
        writer.write_uint32(self.something15)
        writer.write_uint32(self.something16)
        writer.write_uint32(self.something17)
        writer.write_uint8(self.skill_hit)
        writer.write_uint8(self.evading)
        writer.write_uint8(self.something20)
        reader.pad(1)

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
    1 : MultipleEntityUpdate, # not used
    2 : UpdateFinished,
    3 : Unknown3, # not used
    4 : Unknown4,
    5 : CurrentTime,
    10 : ServerChatMessage,
    18 : ServerFull,
    17 : ServerMismatch,
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