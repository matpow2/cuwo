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

# prtocol constants
CLIENT_VERSION = 3
SERVER_PORT = 12345
FULL_MASK = 0x0000FFFFFFFFFFFF

# time constants
MAX_TIME = 24 * 60 * 60 * 1000
NORMAL_TIME_SPEED = 10.0
SLEEP_TIME_SPEED = 100.0

# scale constants, relative to native coordinates
BLOCK_SCALE = 0x10000
CHUNK_SCALE = BLOCK_SCALE * 256 # ZONE_SCALE
SECTOR_SCALE = CHUNK_SCALE * 64 # REGION_SCALE
MAX_POS = SECTOR_SCALE * 1024
MAX_CHUNK = MAX_POS // CHUNK_SCALE # MAX_ZONE

# block constants
AIR_BLOCK = 0
SOLID_BLOCK = 1
WATER_BLOCK = 2
FLAT_WATER_BLOCK = 3

# hostile constants
HOSTILE_FLAG = 1 << 5

FRIENDLY_PLAYER_TYPE = 0
HOSTILE_TYPE = 1
FRIENDLY_TYPE = 2 # also 4, 5

# hostile const, XXX verify these through RE
NAMED_FRIENDLY_TYPE = 3
TARGET_TYPE = 6

# entity flags
CLIMBING_FLAG = 1 << 0
ATTACKING_FLAG = 1 << 2
GLIDER_FLAG = 1 << 4
LANTERN_FLAG = 1 << 9
STEALTH_FLAG = 1 << 10

# appearance flags
IMMOVABLE_FLAG = 1 << 8

# particles
SOLID_PARTICLE = 0
BOMB_PARTICLE = 1
NO_SPREAD_PARTICLE = 2
NO_ACCELERATION_PARTICLE = 3
NO_GRAVITY_PARTICLE = 4

# class types
WARRIOR_CLASS = 1
BERSERKER = 0
GUARDIAN = 1

RANGER_CLASS = 2
SNIPER = 0
SCOUT = 1

MAGE_CLASS = 3
FIRE_MAGE = 0
WATER_MAGE = 1

ROGUE_CLASS = 4
ASSASSIN = 0
NINJA = 1

CLASS_NAMES = {
    WARRIOR_CLASS: 'Warrior',
    RANGER_CLASS: 'Ranger',
    MAGE_CLASS: 'Mage',
    ROGUE_CLASS: 'Rogue'
}

CLASS_SPECIALIZATIONS = {
    WARRIOR_CLASS: {
        BERSERKER: 'Berserker',
        GUARDIAN: 'Guardian'
    },
    RANGER_CLASS: {
        SNIPER: 'Sniper',
        SCOUT: 'Scout'
    },
    MAGE_CLASS: {
        FIRE_MAGE: 'Fire',
        WATER_MAGE: 'Water'
    },
    ROGUE_CLASS: {
        ASSASSIN: 'Assassin',
        NINJA: 'Ninja'
    }
}

MATERIAL_NAMES = {
    1: 'Iron',
    2: 'Wood',
    5: 'Obsidian',
    7: 'Bone',
    11: 'Gold',
    12: 'Silver',
    13: 'Emerald',
    14: 'Sapphire',
    15: 'Ruby',
    16: 'Diamond',
    17: 'Sandstone',
    18: 'Saurian',
    19: 'Parrot',
    20: 'Mammoth',
    21: 'Plant',
    22: 'Ice',
    23: 'Licht',
    24: 'Glass',
    25: 'Silk',
    26: 'Linen',
    27: 'Cotton',
    128: 'Fire',
    129: 'Unholy',
    130: 'Ice',
    131: 'Wind'
}
