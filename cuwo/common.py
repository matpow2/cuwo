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

from cuwo import constants

import shlex
import os


CHAR_FILTER = set([10, 13] + range(32, 127))


def filter_string(value):
    # Cube World only displays characters between 32-126 (and \r\n which both
    # produce newlines) in-game, so in case the user sent a bogus message, we
    # need to filter out those characters and replace with spaces
    new = u''
    for c in value:
        if ord(c) not in CHAR_FILTER:
            c = u' '
        new += c
    return new


def get_hex_string(value):
    v = '0x'
    for c in value:
        new_hex = hex(ord(c))[2:].upper()
        if len(new_hex) < 2:
            new_hex = '0' + new_hex
        v += new_hex
    return v


def is_bit_set(mask, index):
    return mask & (1 << index)


def set_bit(mask, index, value):
    if value:
        mask |= 1 << index
    else:
        mask &= ~(1 << index)
    return mask


def get_clock_string(value):
    hour = (value * 24) / constants.MAX_TIME
    minute = ((value * 24 * 60) / constants.MAX_TIME) % 60
    return '%02d:%02d' % (hour, minute)


def parse_clock(value):
    h, m = value.split(':')
    h = int(h)
    m = int(m)
    v = (h * constants.MAX_TIME) / 24 + (m * constants.MAX_TIME) / (24 * 60)
    return v


def get_chunk(vec):
    return (int(vec.x / constants.CHUNK_SCALE),
            int(vec.y / constants.CHUNK_SCALE))


def get_sector(vec):
    return (int(vec.x / constants.SECTOR_SCALE),
            int(vec.y / constants.SECTOR_SCALE))


def parse_command(message):
    if isinstance(message, unicode):
        # due to shlex unicode problems
        message = message.encode('utf-8')
    try:
        args = shlex.split(message)
    except ValueError:
        # shlex failed. let's just split per space
        args = message.split(' ')
    if args:
        command = args.pop(0)
    else:
        command = ''
    return command.decode('utf-8'), [arg.decode('utf-8') for arg in args]


def create_path(path):
    if path:
        try:
            os.makedirs(path)
        except OSError:
            pass


def create_file_path(path):
    create_path(os.path.dirname(path))


def open_create(filename, mode):
    create_file_path(filename)
    return open(filename, mode)


def get_entity_base_health(entity):
    level_health = 2 ** ((1 - (1 / (0.05 * (entity.level - 1) + 1))) * 3)

    if entity.hostile_type == 0:
        health = level_health * 2 * entity.max_hp_multiplier
    else:
        power_health = 2 ** (entity.power_base * 0.25)
        health = level_health * power_health * entity.max_hp_multiplier

    if entity.class_type == 1:
        health *= 1.30
        if entity.specialization == 1:
            health *= 1.25

    elif entity.class_type == 2:
        health *= 1.10

    elif entity.class_type == 4:
        health *= 1.20

    return health


def get_item_base_hp(level, rarity):
    level_health = 2 ** ((1 - (1 / (0.05 * (float(level) - 1) + 1))) * 3)
    rarity_health = 2 ** (float(rarity) * 0.25)
    return level_health * rarity_health


def get_item_hp(item):
    if item.type not in (3, 4, 5, 6, 7):
        return 0.0

    type_multiplier = 0.5
    if item.type == 4:
        type_multiplier = 1.0

    hp_mod = 8 * item.modifier % 0x15

    if hp_mod >> 31 == 1:
        hp_mod += 4294967296.0

    mod_mult = (1.0 - (hp_mod / 20.0)) + 1.0

    if item.material == 1:
        mod_mult += 1.0

    if item.material == 26:
        mod_mult += 0.5

    if item.material == 27:
        mod_mult += 0.75

    upgrade_lv = item.upgrade_count * 0.10
    base_hp = get_item_base_hp(item.level + upgrade_lv, item.rarity)
    return base_hp * 5.0 * type_multiplier * mod_mult


def get_consumable_heal(item):
    return get_item_base_hp(item.level, item.rarity) * 200


def get_entity_max_health(entity):
    health = get_entity_base_health(entity)
    health += get_item_hp(entity.equipment[6])
    health += get_item_hp(entity.equipment[7])
    health += get_item_hp(entity.equipment[2])
    health += get_item_hp(entity.equipment[3])
    health += get_item_hp(entity.equipment[4])
    health += get_item_hp(entity.equipment[5])
    return health


def get_max_xp(level):
    xp = 1050 - 1000 / (0.05 * (level - 1) + 1)
    return int(xp)


def get_power(level):
    power = 101 - 100 / (0.05 * (level - 1) + 1)
    return int(power)


def get_item_name(item):
    name = []

    if item.material in constants.MATERIAL_NAMES:
        name.append(constants.MATERIAL_NAMES[item.material])

    if item.type in constants.ITEM_NAMES:
        name.append(constants.ITEM_NAMES[item.type])

    if item.type == 1 and item.sub_type in constants.CONSUMABLE_NAMES:
        name.append(constants.CONSUMABLE_NAMES[item.sub_type])

    if item.type == 3 and item.sub_type in constants.WEAPON_NAMES:
        name.append(constants.WEAPON_NAMES[item.sub_type])

    if item.type == 19 and item.sub_type in constants.NPC_NAMES:
        name.append(constants.NPC_NAMES[item.sub_type])

    power = get_power(item.level)
    name.append("+{power}".format(power=power))

    itemname = ' '.join(name)
    return itemname
