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

from cuwo.loader import Loader
from cuwo.common import is_bit_set

FLAGS_1_HOSTILE = 0x20

class ItemUpgrade(Loader):
    def read(self, reader):
        self.x = reader.read_int8()
        self.y = reader.read_int8()
        self.z = reader.read_int8()
        self.material = reader.read_int8()
        self.level = reader.read_uint32()
    
    def write(self, writer):
        writer.write_int8(self.x)
        writer.write_int8(self.y)
        writer.write_int8(self.z)
        writer.write_int8(self.material)
        writer.write_uint32(self.level)
    
class ItemData(Loader):
    def read(self, reader):
        self.type = reader.read_uint8()
        self.sub_type = reader.read_uint8()
        reader.skip(2)
        self.modifier = reader.read_uint32()
        self.minus_modifier = reader.read_uint32()
        self.rarity = reader.read_uint8()
        self.material = reader.read_uint8()
        self.flags = reader.read_uint8()
        reader.skip(1)
        self.level = reader.read_uint16()
        reader.skip(2)
        self.items = []
        for _ in xrange(32):
            new_item = ItemUpgrade()
            new_item.read(reader)
            self.items.append(new_item)
        self.upgrade_count = reader.read_uint32()
    
    def write(self, writer):
        writer.write_uint8(self.type)
        writer.write_uint8(self.sub_type)
        writer.pad(2)
        writer.write_uint32(self.modifier)
        writer.write_uint32(self.minus_modifier)
        writer.write_uint8(self.rarity)
        writer.write_uint8(self.material)
        writer.write_uint8(self.flags)
        writer.pad(1)
        writer.write_uint16(self.level)
        writer.pad(2)
        for item in self.items:
            item.write(writer)
        writer.write_uint32(self.upgrade_count)
    
class AppearanceData(Loader):
    def read(self, reader):
        self.not_used_1 = reader.read_uint8()
        self.not_used_2 = reader.read_uint8()
        self.hair_red = reader.read_uint8()
        self.hair_green = reader.read_uint8()
        self.hair_blue = reader.read_uint8()
        reader.skip(1)
        self.movement_flags = reader.read_uint8()
        self.entity_flags = reader.read_uint8()
        self.scale = reader.read_float()
        self.bounding_radius = reader.read_float()
        self.bounding_height = reader.read_float()
        self.head_model = reader.read_uint16()
        self.hair_model = reader.read_uint16()
        self.hand_model = reader.read_uint16()
        self.foot_model = reader.read_uint16()
        self.body_model = reader.read_uint16()
        self.back_model = reader.read_uint16()
        self.shoulder_model = reader.read_uint16()
        self.wing_model = reader.read_uint16()
        self.head_scale = reader.read_float()
        self.body_scale = reader.read_float()
        self.hand_scale = reader.read_float()
        self.foot_scale = reader.read_float()
        self.shoulder_scale = reader.read_float()
        self.weapon_scale = reader.read_float()
        self.back_scale = reader.read_float()
        self.unknown = reader.read_float()
        self.wing_scale = reader.read_float()
        self.body_pitch = reader.read_float()
        self.arm_pitch = reader.read_float()
        self.arm_roll = reader.read_float()
        self.arm_yaw = reader.read_float()
        self.feet_pitch = reader.read_float()
        self.wing_pitch = reader.read_float()
        self.back_pitch = reader.read_float()
        self.body_offset = reader.read_vec3()
        self.head_offset = reader.read_vec3()
        self.hand_offset = reader.read_vec3()
        self.foot_offset = reader.read_vec3()
        self.back_offset = reader.read_vec3()
        self.wing_offset = reader.read_vec3()
    
    def write(self, writer):
        writer.write_uint8(self.not_used_1)
        writer.write_uint8(self.not_used_2)
        writer.write_uint8(self.hair_red)
        writer.write_uint8(self.hair_green)
        writer.write_uint8(self.hair_blue)
        writer.pad(1)
        writer.write_uint8(self.movement_flags)
        writer.write_uint8(self.entity_flags)
        writer.write_float(self.scale)
        writer.write_float(self.bounding_radius)
        writer.write_float(self.bounding_height)
        writer.write_uint16(self.head_model)
        writer.write_uint16(self.hair_model)
        writer.write_uint16(self.hand_model)
        writer.write_uint16(self.foot_model)
        writer.write_uint16(self.body_model)
        writer.write_uint16(self.back_model)
        writer.write_uint16(self.shoulder_model)
        writer.write_uint16(self.wing_model)
        writer.write_float(self.head_scale)
        writer.write_float(self.body_scale)
        writer.write_float(self.hand_scale)
        writer.write_float(self.foot_scale)
        writer.write_float(self.shoulder_scale)
        writer.write_float(self.weapon_scale)
        writer.write_float(self.back_scale)
        writer.write_float(self.unknown)
        writer.write_float(self.wing_scale)
        writer.write_float(self.body_pitch)
        writer.write_float(self.arm_pitch)
        writer.write_float(self.arm_roll)
        writer.write_float(self.arm_yaw)
        writer.write_float(self.feet_pitch)
        writer.write_float(self.wing_pitch)
        writer.write_float(self.back_pitch)
        writer.write_vec3(self.body_offset)
        writer.write_vec3(self.head_offset)
        writer.write_vec3(self.hand_offset)
        writer.write_vec3(self.foot_offset)
        writer.write_vec3(self.back_offset)
        writer.write_vec3(self.wing_offset)
    
class EntityData(Loader):
    def read(self, reader):
        self.x = reader.read_int64()
        self.y = reader.read_int64()
        self.z = reader.read_int64()
        self.body_roll = reader.read_float()
        self.body_pitch = reader.read_float()
        self.body_yaw = reader.read_float()
        self.velocity = reader.read_vec3()
        self.accel = reader.read_vec3()
        self.extra_vel = reader.read_vec3()
        self.look_pitch = reader.read_float()
        self.physics_flags = reader.read_uint32()
        self.speed_flags = reader.read_uint8()
        reader.skip(3)
        self.entity_type = reader.read_uint32()
        self.current_mode = reader.read_uint8()
        reader.skip(3)
        self.last_shoot_time = reader.read_uint32()
        self.hit_counter = reader.read_uint32()
        self.last_hit_time = reader.read_uint32()
        self.appearance = AppearanceData()
        self.appearance.read(reader)
        self.flags_1 = reader.read_uint8()
        self.flags_2 = reader.read_uint8()
        reader.skip(2)
        self.roll_time = reader.read_uint32()
        self.stun_time = reader.read_int32()
        self.slowed_time = reader.read_uint32()
        self.make_blue_time = reader.read_uint32()
        self.speed_up_time = reader.read_uint32()
        self.show_patch_time = reader.read_float()
        self.class_type = reader.read_uint8()
        self.specialization = reader.read_uint8()
        reader.skip(2)
        self.charged_mp = reader.read_float()
        self.not_used_1 = reader.read_uint32()
        self.not_used_2 = reader.read_uint32()
        self.not_used_3 = reader.read_uint32()
        self.not_used_4 = reader.read_uint32()
        self.not_used_5 = reader.read_uint32()
        self.not_used_6 = reader.read_uint32()
        self.ray_hit = reader.read_vec3()
        self.hp = reader.read_float()
        self.mp = reader.read_float()
        self.block_power = reader.read_float()
        self.max_hp_multiplier = reader.read_float()
        self.shoot_speed = reader.read_float()
        self.damage_multiplier = reader.read_float()
        self.armor_multiplier = reader.read_float()
        self.resi_multiplier = reader.read_float()
        self.not_used7 = reader.read_uint8()
        self.not_used8 = reader.read_uint8()
        reader.skip(2)
        self.character_level = reader.read_uint32()
        self.current_xp = reader.read_uint32()
        self.parent_owner = reader.read_uint64()
        self.unknown_or_not_used1 = reader.read_uint32()
        self.unknown_or_not_used2 = reader.read_uint32()
        self.unknown_or_not_used3 = reader.read_uint8()
        reader.skip(3)
        self.unknown_or_not_used4 = reader.read_uint32()
        self.unknown_or_not_used5 = reader.read_uint32()
        self.not_used11 = reader.read_uint32()
        self.not_used12 = reader.read_uint32()
        self.super_weird = reader.read_uint32()
        self.not_used13 = reader.read_uint32()
        self.not_used14 = reader.read_uint32()
        self.not_used15 = reader.read_uint32()
        self.not_used16 = reader.read_uint32()
        self.not_used17 = reader.read_uint32()
        self.not_used18 = reader.read_uint32()
        self.not_used19 = reader.read_uint8()
        reader.skip(3)
        self.not_used20 = reader.read_uint32()
        self.not_used21 = reader.read_uint32()
        self.not_used22 = reader.read_uint32()
        self.item_data = ItemData()
        self.item_data.read(reader)
        self.equipment = []
        for _ in xrange(13):
            new_item = ItemData()
            new_item.read(reader)
            self.equipment.append(new_item)
        self.skills = []
        for _ in xrange(11):
            self.skills.append(reader.read_uint32())
        self.mana_cubes = reader.read_uint32()
        self.name = reader.read_string(16)
    
    def write(self, writer):
        writer.write_int64(self.x)
        writer.write_int64(self.y)
        writer.write_int64(self.z)
        writer.write_float(self.body_roll)
        writer.write_float(self.body_pitch)
        writer.write_float(self.body_yaw)
        writer.write_vec3(self.velocity)
        writer.write_vec3(self.accel)
        writer.write_vec3(self.extra_vel)
        writer.write_float(self.look_pitch)
        writer.write_uint32(self.physics_flags)
        writer.write_uint8(self.speed_flags)
        writer.pad(3)
        writer.write_uint32(self.entity_type)
        writer.write_uint8(self.current_mode)
        writer.pad(3)
        writer.write_uint32(self.last_shoot_time)
        writer.write_uint32(self.hit_counter)
        writer.write_uint32(self.last_hit_time)
        self.appearance.write(writer)
        writer.write_uint8(self.flags_1)
        writer.write_uint8(self.flags_2)
        writer.pad(2)
        writer.write_uint32(self.roll_time)
        writer.write_int32(self.stun_time)
        writer.write_uint32(self.slowed_time)
        writer.write_uint32(self.make_blue_time)
        writer.write_uint32(self.speed_up_time)
        writer.write_float(self.show_patch_time)
        writer.write_uint8(self.class_type)
        writer.write_uint8(self.specialization)
        writer.pad(2)
        writer.write_float(self.charged_mp)
        writer.write_uint32(self.not_used_1)
        writer.write_uint32(self.not_used_2)
        writer.write_uint32(self.not_used_3)
        writer.write_uint32(self.not_used_4)
        writer.write_uint32(self.not_used_5)
        writer.write_uint32(self.not_used_6)
        writer.write_vec3(self.ray_hit)
        writer.write_float(self.hp)
        writer.write_float(self.mp)
        writer.write_float(self.block_power)
        writer.write_float(self.max_hp_multiplier)
        writer.write_float(self.shoot_speed)
        writer.write_float(self.damage_multiplier)
        writer.write_float(self.armor_multiplier)
        writer.write_float(self.resi_multiplier)
        writer.write_uint8(self.not_used7)
        writer.write_uint8(self.not_used8)
        writer.pad(2)
        writer.write_uint32(self.character_level)
        writer.write_uint32(self.current_xp)
        writer.write_uint64(self.parent_owner)
        writer.write_uint32(self.unknown_or_not_used1)
        writer.write_uint32(self.unknown_or_not_used2)
        writer.write_uint8(self.unknown_or_not_used3)
        writer.pad(3)
        writer.write_uint32(self.unknown_or_not_used4)
        writer.write_uint32(self.unknown_or_not_used5)
        writer.write_uint32(self.not_used11)
        writer.write_uint32(self.not_used12)
        writer.write_uint32(self.super_weird)
        writer.write_uint32(self.not_used13)
        writer.write_uint32(self.not_used14)
        writer.write_uint32(self.not_used15)
        writer.write_uint32(self.not_used16)
        writer.write_uint32(self.not_used17)
        writer.write_uint32(self.not_used18)
        writer.write_uint8(self.not_used19)
        writer.pad(3)
        writer.write_uint32(self.not_used20)
        writer.write_uint32(self.not_used21)
        writer.write_uint32(self.not_used22)
        self.item_data.write(writer)
        for item in self.equipment:
            item.write(writer)
        for item in self.skills:
            writer.write_uint32(item)
        writer.write_uint32(self.mana_cubes)
        writer.write_string(self.name, 16)
    
def read_masked_data(entity, reader):
    mask = reader.read_uint64()
    if is_bit_set(mask, 0):
        entity.x = reader.read_int64()
        entity.y = reader.read_int64()
        entity.z = reader.read_int64()
    if is_bit_set(mask, 1):
        entity.body_roll = reader.read_float()
        entity.body_pitch = reader.read_float()
        entity.body_yaw = reader.read_float()
    if is_bit_set(mask, 2):
        entity.velocity = reader.read_vec3()
    if is_bit_set(mask, 3):
        entity.accel = reader.read_vec3()
    if is_bit_set(mask, 4):
        entity.extra_vel = reader.read_vec3()
    if is_bit_set(mask, 5):
        entity.look_pitch = reader.read_float()
    if is_bit_set(mask, 6):
        entity.physics_flags = reader.read_uint32()
    if is_bit_set(mask, 7):
        entity.speed_flags = reader.read_uint8()
    if is_bit_set(mask, 8):
        entity.entity_type = reader.read_uint32()
    if is_bit_set(mask, 9):
        entity.current_mode = reader.read_uint8()
    if is_bit_set(mask, 10):
        entity.last_shoot_time = reader.read_uint32()
    if is_bit_set(mask, 11):
        entity.hit_counter = reader.read_uint32()
    if is_bit_set(mask, 12):
        entity.last_hit_time = reader.read_uint32()
    if is_bit_set(mask, 13):
        entity.appearance.read(reader)
    if is_bit_set(mask, 14):
        entity.flags_1 = reader.read_uint8()
        entity.flags_2 = reader.read_uint8()
    if is_bit_set(mask, 15):
        entity.roll_time = reader.read_uint32()
    if is_bit_set(mask, 16):
        entity.stun_time = reader.read_int32()
    if is_bit_set(mask, 17):
        entity.slowed_time = reader.read_uint32()
    if is_bit_set(mask, 18):
        entity.make_blue_time = reader.read_uint32()
    if is_bit_set(mask, 19):
        entity.speed_up_time = reader.read_uint32()
    if is_bit_set(mask, 20):
        entity.show_patch_time = reader.read_float()
    if is_bit_set(mask, 21):
        entity.class_type = reader.read_uint8()
    if is_bit_set(mask, 22):
        entity.specialization = reader.read_uint8()
    if is_bit_set(mask, 23):
        entity.charged_mp = reader.read_float()
    if is_bit_set(mask, 24):
        entity.not_used_1 = reader.read_uint32()
        entity.not_used_2 = reader.read_uint32()
        entity.not_used_3 = reader.read_uint32()
    if is_bit_set(mask, 25):
        entity.not_used_4 = reader.read_uint32()
        entity.not_used_5 = reader.read_uint32()
        entity.not_used_6 = reader.read_uint32()
    if is_bit_set(mask, 26):
        entity.ray_hit = reader.read_vec3()
    if is_bit_set(mask, 27):
        entity.hp = reader.read_float()
    if is_bit_set(mask, 28):
        entity.mp = reader.read_float()
    if is_bit_set(mask, 29):
        entity.block_power = reader.read_float()
    if is_bit_set(mask, 30):
        entity.max_hp_multiplier = reader.read_float()
        entity.shoot_speed = reader.read_float()
        entity.damage_multiplier = reader.read_float()
        entity.armor_multiplier = reader.read_float()
        entity.resi_multiplier = reader.read_float()
    if is_bit_set(mask, 31):
        entity.not_used7 = reader.read_uint8()
    if is_bit_set(mask, 32):
        entity.not_used8 = reader.read_uint8()
    if is_bit_set(mask, 33):
        entity.character_level = reader.read_uint32()
    if is_bit_set(mask, 34):
        entity.current_xp = reader.read_uint32()
    if is_bit_set(mask, 35):
        entity.parent_owner = reader.read_uint64()
    if is_bit_set(mask, 36):
        entity.unknown_or_not_used1 = reader.read_uint32()
        entity.unknown_or_not_used2 = reader.read_uint32()
    if is_bit_set(mask, 37):
        entity.unknown_or_not_used3 = reader.read_uint8()
    if is_bit_set(mask, 38):
        entity.unknown_or_not_used4 = reader.read_uint32()
    if is_bit_set(mask, 39):
        entity.unknown_or_not_used5 = reader.read_uint32()
        entity.not_used11 = reader.read_uint32()
        entity.not_used12 = reader.read_uint32()
    if is_bit_set(mask, 40):
        entity.not_used13 = reader.read_uint32()
        entity.not_used14 = reader.read_uint32()
        entity.not_used15 = reader.read_uint32()
        entity.not_used16 = reader.read_uint32()
        entity.not_used17 = reader.read_uint32()
        entity.not_used18 = reader.read_uint32()
    if is_bit_set(mask, 41):
        entity.not_used20 = reader.read_uint32()
        entity.not_used21 = reader.read_uint32()
        entity.not_used22 = reader.read_uint32()
    if is_bit_set(mask, 42):
        entity.not_used19 = reader.read_uint8()
    if is_bit_set(mask, 43):
        entity.item_data.read(reader)
    if is_bit_set(mask, 44):
        for item in entity.equipment:
            item.read(reader)
    if is_bit_set(mask, 45):
        entity.name = reader.read_string(16)
    if is_bit_set(mask, 46):
        entity.skills = []
        for _ in xrange(11):
            entity.skills.append(reader.read_uint32())
    if is_bit_set(mask, 47):
        entity.mana_cubes = reader.read_uint32()

def get_masked_size(mask):
    size = 0
    if is_bit_set(mask, 0):
        size += 24
    if is_bit_set(mask, 1):
        size += 12
    if is_bit_set(mask, 2):
        size += 12
    if is_bit_set(mask, 3):
        size += 12
    if is_bit_set(mask, 4):
        size += 12
    if is_bit_set(mask, 5):
        size += 4
    if is_bit_set(mask, 6):
        size += 4
    if is_bit_set(mask, 7):
        size += 1
    if is_bit_set(mask, 8):
        size += 4
    if is_bit_set(mask, 9):
        size += 1
    if is_bit_set(mask, 10):
        size += 4
    if is_bit_set(mask, 11):
        size += 4
    if is_bit_set(mask, 12):
        size += 4
    if is_bit_set(mask, 13):
        size += 172
    if is_bit_set(mask, 14):
        size += 2
    if is_bit_set(mask, 15):
        size += 4
    if is_bit_set(mask, 16):
        size += 4
    if is_bit_set(mask, 17):
        size += 4
    if is_bit_set(mask, 18):
        size += 4
    if is_bit_set(mask, 19):
        size += 4
    if is_bit_set(mask, 20):
        size += 4
    if is_bit_set(mask, 21):
        size += 1
    if is_bit_set(mask, 22):
        size += 1
    if is_bit_set(mask, 23):
        size += 4
    if is_bit_set(mask, 24):
        size += 12
    if is_bit_set(mask, 25):
        size += 12
    if is_bit_set(mask, 26):
        size += 12
    if is_bit_set(mask, 27):
        size += 4
    if is_bit_set(mask, 28):
        size += 4
    if is_bit_set(mask, 29):
        size += 4
    if is_bit_set(mask, 30):
        size += 20
    if is_bit_set(mask, 31):
        size += 1
    if is_bit_set(mask, 32):
        size += 1
    if is_bit_set(mask, 33):
        size += 4
    if is_bit_set(mask, 34):
        size += 4
    if is_bit_set(mask, 35):
        size += 8
    if is_bit_set(mask, 36):
        size += 8
    if is_bit_set(mask, 37):
        size += 1
    if is_bit_set(mask, 38):
        size += 4
    if is_bit_set(mask, 39):
        size += 12
    if is_bit_set(mask, 40):
        size += 24
    if is_bit_set(mask, 41):
        size += 12
    if is_bit_set(mask, 42):
        size += 1
    if is_bit_set(mask, 43):
        size += 280
    if is_bit_set(mask, 44):
        size += 3640
    if is_bit_set(mask, 45):
        size += 16
    if is_bit_set(mask, 46):
        size += 44
    if is_bit_set(mask, 47):
        size += 4

def write_masked_data(entity, writer):
    writer.write_uint64(0x0000FFFFFFFFFFFF)
    writer.write_int64(entity.x)
    writer.write_int64(entity.y)
    writer.write_int64(entity.z)
    writer.write_float(entity.body_roll)
    writer.write_float(entity.body_pitch)
    writer.write_float(entity.body_yaw)
    writer.write_vec3(entity.velocity)
    writer.write_vec3(entity.accel)
    writer.write_vec3(entity.extra_vel)
    writer.write_float(entity.look_pitch)
    writer.write_uint32(entity.physics_flags)
    writer.write_uint8(entity.speed_flags)
    writer.write_uint32(entity.entity_type)
    writer.write_uint8(entity.current_mode)
    writer.write_uint32(entity.last_shoot_time)
    writer.write_uint32(entity.hit_counter)
    writer.write_uint32(entity.last_hit_time)
    entity.appearance.write(writer)
    writer.write_uint8(entity.flags_1)
    writer.write_uint8(entity.flags_2)
    writer.write_uint32(entity.roll_time)
    writer.write_int32(entity.stun_time)
    writer.write_uint32(entity.slowed_time)
    writer.write_uint32(entity.make_blue_time)
    writer.write_uint32(entity.speed_up_time)
    writer.write_float(entity.show_patch_time)
    writer.write_uint8(entity.class_type)
    writer.write_uint8(entity.specialization)
    writer.write_float(entity.charged_mp)
    writer.write_uint32(entity.not_used_1)
    writer.write_uint32(entity.not_used_2)
    writer.write_uint32(entity.not_used_3)
    writer.write_uint32(entity.not_used_4)
    writer.write_uint32(entity.not_used_5)
    writer.write_uint32(entity.not_used_6)
    writer.write_vec3(entity.ray_hit)
    writer.write_float(entity.hp)
    writer.write_float(entity.mp)
    writer.write_float(entity.block_power)
    writer.write_float(entity.max_hp_multiplier)
    writer.write_float(entity.shoot_speed)
    writer.write_float(entity.damage_multiplier)
    writer.write_float(entity.armor_multiplier)
    writer.write_float(entity.resi_multiplier)
    writer.write_uint8(entity.not_used7)
    writer.write_uint8(entity.not_used8)
    writer.write_uint32(entity.character_level)
    writer.write_uint32(entity.current_xp)
    writer.write_uint64(entity.parent_owner)
    writer.write_uint32(entity.unknown_or_not_used1)
    writer.write_uint32(entity.unknown_or_not_used2)
    writer.write_uint8(entity.unknown_or_not_used3)
    writer.write_uint32(entity.unknown_or_not_used4)
    writer.write_uint32(entity.unknown_or_not_used5)
    writer.write_uint32(entity.not_used11)
    writer.write_uint32(entity.not_used12)
    writer.write_uint32(entity.not_used13)
    writer.write_uint32(entity.not_used14)
    writer.write_uint32(entity.not_used15)
    writer.write_uint32(entity.not_used16)
    writer.write_uint32(entity.not_used17)
    writer.write_uint32(entity.not_used18)
    writer.write_uint32(entity.not_used20)
    writer.write_uint32(entity.not_used21)
    writer.write_uint32(entity.not_used22)
    writer.write_uint8(entity.not_used19)
    entity.item_data.write(writer)
    for item in entity.equipment:
        item.write(writer)
    writer.write_string(entity.name, 16)
    for item in entity.skills:
        writer.write_uint32(item)
    writer.write_uint32(entity.mana_cubes)

SOUNDS = {
    0 : 'hit',
    1 : 'blade1',
    2 : 'blade2',
    3 : 'long-blade1',
    4 : 'long-blade2',
    5 : 'hit1',
    6 : 'hit2',
    7 : 'punch1',
    8 : 'punch2',
    9 : 'hit-arrow',
    10 : 'hit-arrow-critical',
    11 : 'smash1',
    12 : 'slam-ground',
    13 : 'smash-hit2',
    14 : 'smash-jump',
    15 : 'swing',
    16 : 'shield-swing',
    17 : 'swing-slow',
    18 : 'swing-slow2',
    19 : 'arrow-destroy',
    20 : 'blade1',
    21 : 'punch2',
    22 : 'salvo2',
    23 : 'sword-hit03',
    24 : 'block',
    25 : 'shield-slam',
    26 : 'roll',
    27 : 'destroy2',
    28 : 'cry',
    29 : 'levelup2',
    30 : 'missioncomplete',
    31 : 'water-splash01',
    32 : 'step2',
    33 : 'step-water',
    34 : 'step-water2',
    35 : 'step-water3',
    36 : 'channel2',
    37 : 'channel-hit',
    38 : 'fireball',
    39 : 'fire-hit',
    40 : 'magic02',
    41 : 'watersplash',
    42 : 'watersplash-hit',
    43 : 'lich-scream',
    44 : 'drink2',
    45 : 'pickup',
    46 : 'disenchant2',
    47 : 'upgrade2',
    48 : 'swirl',
    49 : 'human-voice01',
    50 : 'human-voice02',
    51 : 'gate',
    52 : 'spike-trap',
    53 : 'fire-trap',
    54 : 'lever',
    55 : 'charge2',
    56 : 'magic02',
    57 : 'drop',
    58 : 'drop-coin',
    59 : 'drop-item',
    60 : 'male-groan',
    61 : 'female-groan',
    62 : 'male-groan',
    63 : 'female-groan',
    64 : 'goblin-male-groan',
    65 : 'goblin-female-groan',
    66 : 'lizard-male-groan',
    67 : 'lizard-female-groan',
    68 : 'dwarf-male-groan',
    69 : 'dwarf-female-groan',
    70 : 'orc-male-groan',
    71 : 'orc-female-groan',
    72 : 'undead-male-groan',
    73 : 'undead-female-groan',
    74 : 'frogman-male-groan',
    75 : 'frogman-female-groan',
    76 : 'monster-groan',
    77 : 'troll-groan',
    78 : 'mole-groan',
    79 : 'slime-groan',
    80 : 'zombie-groan',
    81 : 'Explosion',
    82 : 'punch2',
    83 : 'menu-open2',
    84 : 'menu-close2',
    85 : 'menu-select',
    86 : 'menu-tab',
    87 : 'menu-grab-item',
    88 : 'menu-drop-item',
    89 : 'craft',
    90 : 'craft-proc',
    91 : 'absorb',
    92 : 'manashield',
    93 : 'bulwark',
    94 : 'bird1',
    95 : 'bird2',
    96 : 'bird3',
    97 : 'cricket1',
    98 : 'cricket2',
    99 : 'owl1',
    100 : 'owl2'
}
