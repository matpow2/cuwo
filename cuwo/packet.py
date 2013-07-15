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
    read_masked_data, write_masked_data, get_masked_size, SOUNDS)
from cuwo.loader import Loader
from cuwo.common import get_hex_string
from bytes import ByteReader, ByteWriter, OutOfData
import zlib

def create_entity_data():
    data = EntityData()
    data.appearance = AppearanceData()
    data.equipment_1 = EquipmentData()
    data.equipment = []
    for _ in xrange(13):
        data.equipment.append(EquipmentData())
    return data

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
        # wrap seed because user may provide a silly one
        writer.write_uint32(self.seed & 0xFFFFFFFF)

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

    def write(self, writer):
        writer.write_uint32(self.something)
        writer.write_uint32(self.something2)
        writer.write_uint32(self.something3)
        writer.write_uint8(self.something4)
        writer.write_uint8(self.something5)
        writer.write_uint8(self.something6)
        writer.write_uint8(self.something7)
        writer.write_uint32(self.something8)

class Unknown4(Packet):
    def read(self, reader):
        size = reader.read_uint32()
        decompressed_data = zlib.decompress(reader.read(size))
        reader = ByteReader(decompressed_data)

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

        # make sound
        self.items_4 = []
        for _ in xrange(reader.read_uint32()):
            pos = reader.read_vec3() * 65536.0
            sound_index = reader.read_uint32()
            pitch = reader.read_float()
            volume = reader.read_float()
            self.items_4.append((pos, sound_index, pitch, volume))

        # shoot arrow?
        self.items_5 = []
        for _ in xrange(reader.read_uint32()):
            item = ShootPacket()
            item.read(reader)
            self.items_5.append(item)

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
            self.items_8.append((something, sub_items))

        # item picked up
        self.items_9 = []
        for _ in xrange(reader.read_uint32()):
            entity_id = reader.read_uint64()
            item = EquipmentData()
            item.read(reader)
            self.items_9.append((entity_id, item))

        # killed by, gives xp
        self.items_10 = []
        for _ in xrange(reader.read_uint32()):
            entity_id = reader.read_uint64() # killer
            target_id = reader.read_uint64() # killed
            # see below about padding
            reader.skip(4)
            xp_gained = reader.read_int32()
            self.items_10.append((entity_id, target_id, xp_gained))

        # set entity damage
        self.items_11 = []
        for _ in xrange(reader.read_uint32()):
            target_id = reader.read_uint64()
            entity_id = reader.read_uint64()
            damage = reader.read_float()
            # is this actually padding? copied as part of MOVQ, but may just be
            # optimization. not used in client, it seems.
            # could also be related to items_10, seems to use similar list
            # copy implementation
            reader.skip(4)
            self.items_11.append((target_id, entity_id, damage))

        self.items_12 = []
        for _ in xrange(reader.read_uint32()):
            self.items_12.append(reader.read(40))

        self.items_13 = []
        for _ in xrange(reader.read_uint32()):
            self.items_13.append(reader.read(56))

        debug = False
        if debug:
            v = vars(self).copy()
            del v['items_11']
            del v['items_10']
            del v['items_9']
            for k, v in v.iteritems():
                if not v:
                    continue
                print k, v

        if len(decompressed_data) != reader.tell():
            raise NotImplementedError()

    def write(self, writer):
        data = ByteWriter()

        data.write_uint32(len(self.items_1))
        for item in self.items_1:
            item.write(data)

        data.write_uint32(len(self.items_2))
        for item in self.items_2:
            data.write(item)

        data.write_uint32(len(self.items_3))
        for item in self.items_3:
            data.write(item)

        data.write_uint32(len(self.items_4))
        for item in self.items_4:
            pos, index, pitch, volume = item
            data.write_vec3(vec / 65536.0)
            data.write_uint32(index)
            data.write_float(pitch)
            data.write_float(volume)

        data.write_uint32(len(self.items_5))
        for item in self.items_5:
            item.write(data)

        data.write_uint32(len(self.items_6))
        for item in self.items_6:
            data.write(item)

        data.write_uint32(len(self.items_7))
        for item in self.items_7:
            something, sub_items = item
            data.write_uint64(something)
            data.write_uint32(len(sub_items))
            for item in sub_items:
                equipment, d = item
                equipment.write(data)
                data.write(d)

        data.write_uint32(len(self.items_8))
        for item in self.items_8:
            something, sub_items = item
            data.write_uint64(something)
            data.write_uint32(len(sub_items))
            for item in sub_items:
                data.write(item)

        data.write_uint32(len(self.items_9))
        for item in self.items_9:
            entity_id, equipment = item
            data.write_uint64(entity_id)
            equipment.write(data)

        data.write_uint32(len(self.items_10))
        for item in self.items_10:
            entity_id, entity_id2, xp_gained = item
            data.write_uint64(entity_id)
            data.write_uint64(entity_id2)
            data.pad(4)
            data.write_int32(xp_gained)

        data.write_uint32(len(self.items_11))
        for item in self.items_11:
            entity_id, target_id, damage = item
            data.write_uint64(entity_id)
            data.write_uint64(target_id)
            data.write_float(damage)
            data.pad(4)

        data.write_uint32(len(self.items_12))
        for item in self.items_12:
            data.write(item)

        data.write_uint32(len(self.items_13))
        for item in self.items_13:
            data.write(item)

        compressed_data = zlib.compress(data.get())
        writer.write_uint32(len(compressed_data))
        writer.write(compressed_data)

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
        self.something3 = reader.read_int32()
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
        writer.write_int32(self.something3)
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
        self.hit_pos = reader.read_qvec3()
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
        writer.pad(3)
        writer.write_uint32(self.stun_duration)
        writer.write_uint32(self.something8)
        writer.write_qvec3(self.hit_pos)
        writer.write_uint32(self.something15)
        writer.write_uint32(self.something16)
        writer.write_uint32(self.something17)
        writer.write_uint8(self.skill_hit)
        writer.write_uint8(self.evading)
        writer.write_uint8(self.something20)
        writer.pad(1)

class Unknown8(Packet):
    def read(self, reader):
        self.data = reader.read(40)

    def write(self, writer):
        writer.write(self.data)

class ShootPacket(Packet):
    def read(self, reader):
        self.entity_id = reader.read_uint64()
        self.chunk_x = reader.read_int32()
        self.chunk_y = reader.read_int32()
        self.something5 = reader.read_uint32()
        reader.skip(4) # 8byte struct alignment
        self.pos = reader.read_qvec3()
        self.something13 = reader.read_uint32()
        self.something14 = reader.read_uint32()
        self.something15 = reader.read_uint32()
        self.velocity = reader.read_vec3()
        self.something19 = reader.read_float() # rand() something, 
                                               # probably damage multiplier
        self.something20 = reader.read_float()
        self.something21 = reader.read_float()
        self.something22 = reader.read_float() # used stamina? amount of stun?
        self.something23 = reader.read_uint32()
        self.something24 = reader.read_uint8() # skill? is 2 for rmb shoot
        reader.skip(3)
        self.something25 = reader.read_uint32()
        self.something26 = reader.read_uint8()
        reader.skip(3)
        self.something27 = reader.read_uint32()
        self.something28 = reader.read_uint32()

    def write(self, writer):
        writer.write_uint64(self.entity_id)
        writer.write_int32(self.chunk_x)
        writer.write_int32(self.chunk_y)
        writer.write_uint32(self.something5)
        writer.pad(4)
        writer.write_qvec3(self.pos)
        writer.write_uint32(self.something13)
        writer.write_uint32(self.something14)
        writer.write_uint32(self.something15)
        writer.write_vec3(self.velocity)
        writer.write_float(self.something19)
        writer.write_float(self.something20)
        writer.write_float(self.something21)
        writer.write_float(self.something22)
        writer.write_uint32(self.something23)
        writer.write_uint8(self.something24)
        writer.pad(3)
        writer.write_uint32(self.something25)
        writer.write_uint8(self.something26)
        writer.pad(3)
        writer.write_uint32(self.something27)
        writer.write_uint32(self.something28)

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

class ChunkDiscovered(Packet):
    def read(self, reader):
        self.x = reader.read_uint32()
        self.y = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.x)
        writer.write_uint32(self.y)

class SectorDiscovered(Packet):
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
    9 : ShootPacket,
    10 : ClientChatMessage,
    11 : ChunkDiscovered,
    12 : SectorDiscovered,
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