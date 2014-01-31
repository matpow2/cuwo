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

# --
# note: please give credit where credit is due. a lot of time was spent
# reverse-engineering these structures, so if you're going to use these
# definitions in your own work, it would be nice with a little notice of
# where you got them from (i.e. cuwo) :-)

from cuwo.entity import (EntityData, AppearanceData, ItemData,
                         read_masked_data, write_masked_data, get_masked_size)
from cuwo.sounds import SOUNDS
from cuwo.loader import Loader
from cuwo.bytes import ByteReader, ByteWriter
from cuwo.constants import FULL_MASK, BLOCK_SCALE 
from cuwo.exceptions import OutOfData
import zlib


def create_entity_data():
    data = EntityData()
    data.appearance = AppearanceData()
    data.consumable = ItemData()
    data.equipment = []
    for _ in xrange(13):
        data.equipment.append(ItemData())
    return data


def read_list(reader, item_class):
    items = []
    for _ in xrange(reader.read_uint32()):
        item = item_class()
        item.read(reader)
        items.append(item)
    return items


def write_list(writer, items):
    writer.write_uint32(len(items))
    for item in items:
        item.write(writer)


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


class JoinPacket(Packet):
    data = None

    def read(self, reader):
        if reader.read_uint32() != 0:
            raise NotImplementedError()
            return
        self.entity_id = reader.read_uint64()  # must be > 1 and < 10
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
        return read_masked_data(entity, reader)

    def set_entity(self, entity, entity_id, mask=None):
        if mask is None:
            mask = FULL_MASK
        writer = ByteWriter()
        writer.write_uint64(entity_id)
        write_masked_data(entity, writer, mask)
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
        for item in self.items:
            entity_id, masked_data = item
            writer.write_uint64(entity_id)
            writer.write(masked_data)


class UpdateFinished(Packet):
    # called when entity update (packet 0) is finished
    pass


class Unknown3(Packet):
    # not actually used - probably a legacy packet (or inventory-related?)
    def read(self, reader):
        count = reader.read_uint32()
        self.data = reader.read(120 * count)

    def write(self, writer):
        writer.write_uint32(len(self.data) / 120)
        writer.write(self.data)


class Packet4Struct1(Loader):
    def read(self, reader):
        self.block_pos = reader.read_ivec3()
        self.color_red = reader.read_uint8()
        self.color_green = reader.read_uint8()
        self.color_blue = reader.read_uint8()
        # v  0 = Invisible, 1 = Solid, 2 = Water, 3 = Flat water, ...
        self.block_type = reader.read_uint8()
        self.something8 = reader.read_uint32()

    def write(self, writer):
        writer.write_ivec3(self.block_pos)
        writer.write_uint8(self.color_red)
        writer.write_uint8(self.color_green)
        writer.write_uint8(self.color_blue)
        writer.write_uint8(self.block_type)
        writer.write_uint32(self.something8)


class ParticleData(Loader):
    def read(self, reader):
        self.pos = reader.read_qvec3()
        self.accel = reader.read_vec3()
        self.color_red = reader.read_float()
        self.color_blue = reader.read_float()
        self.color_green = reader.read_float()
        self.color_alpha = reader.read_float()
        self.scale = reader.read_float()
        self.count = reader.read_uint32()
        # v  0 = Solid, 1 = Bombs, 3 = No accel/spread, 4 = No Gravity, ...
        self.particle_type = reader.read_uint32()
        self.spreading = reader.read_float()
        self.something18 = reader.read_uint32()

    def write(self, writer):
        writer.write_qvec3(self.pos)
        writer.write_vec3(self.accel)
        writer.write_float(self.color_red)
        writer.write_float(self.color_blue)
        writer.write_float(self.color_green)
        writer.write_float(self.color_alpha)
        writer.write_float(self.scale)
        writer.write_uint32(self.count)
        writer.write_uint32(self.particle_type)
        writer.write_float(self.spreading)
        writer.write_uint32(self.something18)


class SoundAction(Loader):
    def read(self, reader):
        self.pos = reader.read_vec3() * float(BLOCK_SCALE)
        self.sound_index = reader.read_uint32()
        self.pitch = reader.read_float()
        self.volume = reader.read_float()

    def get_name(self):
        return SOUNDS[self.sound_index]

    def write(self, writer):
        writer.write_vec3(self.pos / float(BLOCK_SCALE))
        writer.write_uint32(self.sound_index)
        writer.write_float(self.pitch)
        writer.write_float(self.volume)


class PickupAction(Loader):
    def read(self, reader):
        self.entity_id = reader.read_uint64()  # player who picked up
        self.item_data = ItemData()
        self.item_data.read(reader)

    def write(self, writer):
        writer.write_uint64(self.entity_id)
        self.item_data.write(writer)


class KillAction(Loader):
    def read(self, reader):
        self.entity_id = reader.read_uint64()  # killer
        self.target_id = reader.read_uint64()  # killed
        # is this actually padding? copied as part of MOVQ, but may just be
        # optimization. not used in client, it seems.
        # could also be related to DamageAction, seems to use same list
        # copy implementation
        reader.skip(4)
        self.xp_gained = reader.read_int32()

    def write(self, writer):
        writer.write_uint64(self.entity_id)
        writer.write_uint64(self.target_id)
        writer.pad(4)
        writer.write_int32(self.xp_gained)


class DamageAction(Loader):
    def read(self, reader):
        self.target_id = reader.read_uint64()
        self.entity_id = reader.read_uint64()
        self.damage = reader.read_float()
        # se above for KillAction padding
        reader.skip(4)

    def write(self, writer):
        writer.write_uint64(self.target_id)
        writer.write_uint64(self.entity_id)
        writer.write_float(self.damage)
        writer.pad(4)


class ChunkItemData(Loader):
    def read(self, reader):
        self.item_data = ItemData()
        self.item_data.read(reader)
        self.pos = reader.read_qvec3()
        self.rotation = reader.read_float()  # angle something
        self.scale = reader.read_float()
        self.something3 = reader.read_uint8()
        reader.skip(3)
        self.drop_time = reader.read_uint32()  # drop time
        self.something5 = reader.read_uint32()  # 320
        self.something6 = reader.read_int32()  # 324

    def write(self, writer):
        self.item_data.write(writer)
        writer.write_qvec3(self.pos)
        writer.write_float(self.rotation)
        writer.write_float(self.scale)
        writer.write_uint8(self.something3)
        writer.pad(3)
        writer.write_uint32(self.drop_time)
        writer.write_uint32(self.something5)
        writer.write_int32(self.something6)


class ChunkItems(Loader):
    def read(self, reader):
        self.chunk_x = reader.read_int32()
        self.chunk_y = reader.read_int32()
        self.items = read_list(reader, ChunkItemData)

    def write(self, writer):
        writer.write_int32(self.chunk_x)
        writer.write_int32(self.chunk_y)
        write_list(writer, self.items)


class MissionData(Loader):
    def read(self, reader):
        self.section_x = reader.read_int32() / 8.0
        self.section_y = reader.read_int32() / 8.0
        self.something1 = reader.read_uint32()  # padding?
        self.something2 = reader.read_uint32()  # also padding???
        # --
        self.something3 = reader.read_uint32()
        self.mission_id = reader.read_uint32()
        self.something5 = reader.read_uint32()
        self.monster_id = reader.read_uint32()
        self.quest_level = reader.read_uint32()
        self.something8 = reader.read_uint8()
        # 0: ready, 1: progressing, 2: finished
        self.state = reader.read_uint8()
        reader.skip(2)
        self.something10 = reader.read_float()
        self.something11 = reader.read_float()
        self.chunk_x = reader.read_uint32()
        self.chunk_y = reader.read_uint32()

    def write(self, writer):
        writer.write_int32(self.section_x * 8.0)
        writer.write_int32(self.section_y * 8.0)
        writer.write_uint32(self.something1)
        writer.write_uint32(self.something2)
        writer.write_uint32(self.something3)
        writer.write_uint32(self.mission_id)
        writer.write_uint32(self.something5)
        writer.write_uint32(self.monster_id)
        writer.write_uint32(self.quest_level)
        writer.write_uint8(self.something8)
        writer.write_uint8(self.state)
        writer.pad(2)
        writer.write_uint32(self.something10)
        writer.write_uint32(self.something11)
        writer.write_uint32(self.chunk_x)
        writer.write_uint32(self.chunk_y)


class StaticEntityData(Loader):
    def read(self, reader):
        self.chunk_x = reader.read_uint32()
        self.chunk_y = reader.read_uint32()
        self.entity_id = reader.read_uint32()
        reader.skip(4)
        # memory header starts here (size 72)
        self.entity_type = reader.read_uint32()
        reader.skip(4) # 64bit struct padding
        self.pos = reader.read_qvec3()
        self.something2 = reader.read_uint32() # 0, 1, 2, 3
        self.something3 = reader.read_float()
        self.something4 = reader.read_float()
        self.something5 = reader.read_float()
        self.something6 = reader.read_uint8()
        reader.skip(3)
        self.something7 = reader.read_uint32()
        self.something8 = reader.read_uint32()
        reader.skip(4) # 64bit padding
        # following may be 64bit number?
        self.something9 = reader.read_uint32()
        self.something10 = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.chunk_x)
        writer.write_uint32(self.chunk_y)
        writer.write_uint32(self.entity_id)
        writer.pad(4)
        writer.write_uint32(self.entity_type)
        writer.pad(4)
        writer.write_qvec3(self.pos)
        writer.write_uint32(self.something2)
        writer.write_float(self.something3)
        writer.write_float(self.something4)
        writer.write_float(self.something5)
        writer.write_uint8(self.something6)
        writer.pad(3)
        writer.write_uint32(self.something7)
        writer.write_uint32(self.something8)
        writer.pad(4)
        writer.write_uint32(self.something9)
        writer.write_uint32(self.something10)


class ServerUpdate(Packet):
    def reset(self):
        self.items_1 = []
        self.player_hits = []
        self.particles = []
        self.sound_actions = []
        self.shoot_actions = []
        self.static_entities = []
        self.chunk_items = []
        self.items_8 = []
        self.pickups = []
        self.kill_actions = []
        self.damage_actions = []
        self.items_12 = []
        self.missions = []

    def read(self, reader):
        size = reader.read_uint32()
        decompressed_data = zlib.decompress(reader.read(size))
        reader = ByteReader(decompressed_data)

        self.items_1 = read_list(reader, Packet4Struct1)
        self.player_hits = read_list(reader, HitPacket)
        self.particles = read_list(reader, ParticleData)
        self.sound_actions = read_list(reader, SoundAction)
        self.shoot_actions = read_list(reader, ShootPacket)
        self.static_entities = read_list(reader, StaticEntityData)
        self.chunk_items = read_list(reader, ChunkItems)

        self.items_8 = []
        for _ in xrange(reader.read_uint32()):
            something = reader.read_uint64()
            sub_items = []
            for _ in xrange(reader.read_uint32()):
                sub_items.append(reader.read(16))
            self.items_8.append((something, sub_items))

        self.pickups = read_list(reader, PickupAction)
        self.kill_actions = read_list(reader, KillAction)
        self.damage_actions = read_list(reader, DamageAction)

        self.items_12 = []
        for _ in xrange(reader.read_uint32()):
            self.items_12.append(reader.read(40))

        # objective/quests? not sure
        self.missions = read_list(reader, MissionData)

        debug = False
        if debug:
            v = vars(self).copy()
            # del v['kill_actions']
            # del v['player_hits']
            del v['pickups']
            del v['damage_actions']
            del v['sound_actions']
            del v['shoot_actions']
            del v['chunk_items']
            for k, v in v.iteritems():
                if not v:
                    continue
                print k, v

        if len(decompressed_data) != reader.tell():
            raise NotImplementedError()

    def write(self, writer):
        data = ByteWriter()
        write_list(data, self.items_1)
        write_list(data, self.player_hits)
        write_list(data, self.particles)
        write_list(data, self.sound_actions)
        write_list(data, self.shoot_actions)
        write_list(data, self.static_entities)
        write_list(data, self.chunk_items)

        data.write_uint32(len(self.items_8))
        for item in self.items_8:
            something, sub_items = item
            data.write_uint64(something)
            data.write_uint32(len(sub_items))
            for item in sub_items:
                data.write(item)

        write_list(data, self.pickups)
        write_list(data, self.kill_actions)
        write_list(data, self.damage_actions)

        data.write_uint32(len(self.items_12))
        for item in self.items_12:
            data.write(item)

        write_list(data, self.missions)

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
        self.item_data = ItemData()
        self.item_data.read(reader)
        self.chunk_x = reader.read_int32()
        self.chunk_y = reader.read_int32()
        # index of item in ChunkItems
        self.item_index = reader.read_int32()
        self.something4 = reader.read_uint32()
        self.interact_type = reader.read_uint8()
        self.something6 = reader.read_uint8()
        self.something7 = reader.read_uint16()

    def write(self, writer):
        self.item_data.write(writer)
        writer.write_int32(self.chunk_x)
        writer.write_int32(self.chunk_y)
        writer.write_int32(self.item_index)
        writer.write_uint32(self.something4)
        writer.write_uint8(self.interact_type)
        writer.write_uint8(self.something6)
        writer.write_uint16(self.something7)


HIT_NORMAL = 0
HIT_BLOCK = 1
HIT_MISS = 3
HIT_ABSORB = 5


class HitPacket(Packet):
    def read(self, reader):
        self.entity_id = reader.read_uint64()
        self.target_id = reader.read_uint64()
        self.damage = reader.read_float()
        self.critical = reader.read_uint8()
        reader.skip(3)
        self.stun_duration = reader.read_uint32()
        self.something8 = reader.read_uint32()  # padding maybe?
        self.pos = reader.read_qvec3()
        self.hit_dir = reader.read_vec3()
        self.skill_hit = reader.read_uint8()
        self.hit_type = reader.read_uint8()
        self.show_light = reader.read_uint8()
        reader.skip(1)

    def write(self, writer):
        writer.write_uint64(self.entity_id)
        writer.write_uint64(self.target_id)
        writer.write_float(self.damage)
        writer.write_uint8(self.critical)
        writer.pad(3)
        writer.write_uint32(self.stun_duration)
        writer.write_uint32(self.something8)
        writer.write_qvec3(self.pos)
        writer.write_vec3(self.hit_dir)
        writer.write_uint8(self.skill_hit)
        writer.write_uint8(self.hit_type)
        writer.write_uint8(self.show_light)
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
        reader.skip(4)  # 8byte struct alignment
        self.pos = reader.read_qvec3()
        self.something13 = reader.read_uint32()
        self.something14 = reader.read_uint32()
        self.something15 = reader.read_uint32()
        self.velocity = reader.read_vec3()
        self.something19 = reader.read_float()  # rand() something,
                                                # probably damage multiplier
        self.something20 = reader.read_float()
        self.something21 = reader.read_float()
        self.something22 = reader.read_float()  # used stamina? amount of stun?
        self.something23 = reader.read_uint32()
        self.something24 = reader.read_uint8()  # skill? is 2 for rmb shoot
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
    0: EntityUpdate,
    6: InteractPacket,
    7: HitPacket,
    8: Unknown8,  # stealth
    9: ShootPacket,
    10: ClientChatMessage,
    11: ChunkDiscovered,
    12: SectorDiscovered,
    17: ClientVersion
}

SC_PACKETS = {
    0: EntityUpdate,
    1: MultipleEntityUpdate,  # not used
    2: UpdateFinished,
    3: Unknown3,  # not used
    4: ServerUpdate,
    5: CurrentTime,
    10: ServerChatMessage,
    18: ServerFull,
    17: ServerMismatch,
    16: JoinPacket,
    15: SeedData
}


def read_packet(reader, table):
    packet_id = reader.read_uint32()
    try:
        packet = table[packet_id]()
    except KeyError:
        return None
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
        try:
            while True:
                pos = reader.tell()
                if pos >= len(self.data):
                    break
                packet = read_packet(reader, self.table)
                self.callback(packet)
        except OutOfData, e:
            if e.reader is not reader:
                raise e
        except StopIteration:
            return
        self.data = self.data[pos:]
