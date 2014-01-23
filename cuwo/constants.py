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
CHUNK_SCALE = BLOCK_SCALE * 256
SECTOR_SCALE = CHUNK_SCALE * 64
MAX_POS = SECTOR_SCALE * 1024

# block constants
AIR_BLOCK = 0
SOLID_BLOCK = 1
WATER_BLOCK = 2
FLAT_WATER_BLOCK = 3

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

ITEM_NAMES = {
    0: 'Crash',
    2: 'Formula',
    4: 'Chest',
    5: 'Gloves',
    6: 'Boots',
    7: 'Shoulders',
    8: 'Amulet',
    9: 'Ring',
    10: 'Cube',
    11: 'Item',
    12: 'Coin',
    13: 'Platinum Coin',
    14: 'Leftovers',
    15: 'Beak',
    16: 'Painting',
    17: 'Vase',
    18: 'Candle',
    19: 'Pet:',
    20: 'Pet Food',
    21: 'Quest Item',
    22: 'Unknown',
    23: 'Special',
    24: 'Lamp'
}

CONSUMABLE_NAMES = {
    0: 'Cookie',
    1: 'Life Potion',
    2: 'Cactus Potion',
    3: 'Mana Potion',
    4: 'Ginseng Soup',
    5: 'Snowberry Mash',
    6: 'Mushroom Spit',
    7: 'Bomb',
    8: 'Pineapple Slice',
    9: 'Pumpkin Muffin',
    10: 'Mushroom?'
}

WEAPON_NAMES = {
    0: 'Sword',
    1: 'Axe',
    2: 'Mace',
    3: 'Dagger',
    4: 'Fist',
    5: 'Longsword',
    6: 'Bow',
    7: 'Crossbow',
    8: 'Boomerang',
    9: 'Arrow',
    10: 'Staff',
    11: 'Wand',
    12: 'Bracelet',
    13: 'Shield',
    14: 'Quiver',
    15: 'Greatsword',
    16: 'Greataxe',
    17: 'Greatmace',
    18: 'Pitchfork',
    19: 'Pickaxe',
    20: 'Torch'
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

NPC_NAMES = {
    0: 'Elf (Male)',
    1: 'Elf (Female)',
    2: 'Human (Male)',
    3: 'Human (Female)',
    4: 'Goblin (Male)',
    5: 'Goblin (Female)',
    6: 'Terrier (Bull)',
    7: 'Lizardman (Male)',
    8: 'Lizardman (Female)',
    9: 'Dwarf (Male)',
    10: 'Dwarf (Female)',
    11: 'Orc (Male)',
    12: 'Orc (Female)',
    13: 'Frogman (Male)',
    14: 'Frogman (Female)',
    15: 'Undead (Male)',
    16: 'Undead (Female)',
    17: 'Skeleton',
    18: 'Old Man',
    19: 'Collie',
    20: 'Shepherd Dog',
    21: 'Skull Bull',
    22: 'Alpaca',
    23: 'Alpaca (Brown)',
    24: 'Egg',
    25: 'Turtle',
    26: 'Terrier',
    27: 'Terrier (Scottish)',
    28: 'Wolf',
    29: 'Panther',
    30: 'Cat',
    31: 'Cat (Brown)',
    32: 'Cat (White)',
    33: 'Pig',
    34: 'Sheep',
    35: 'Bunny',
    36: 'Porcupine',
    37: 'Slime (Green)',
    38: 'Slime (Pink)',
    39: 'Slime (Yellow)',
    40: 'Slime (Blue)',
    41: 'Frightener',
    42: 'Sandhorror',
    43: 'Wizard',
    44: 'Bandit',
    45: 'Witch',
    46: 'Ogre',
    47: 'Rockling',
    48: 'Gnoll',
    49: 'Gnoll (Polar)',
    50: 'Monkey',
    51: 'Gnobold',
    52: 'Insectoid',
    53: 'Hornet',
    54: 'Insect Guard',
    55: 'Crow',
    56: 'Chicken',
    57: 'Seagull',
    58: 'Parrot',
    59: 'Bat',
    60: 'Fly',
    61: 'Midge',
    62: 'Mosquito',
    63: 'Runner (Plain)',
    64: 'Runner (Leaf)',
    65: 'Runner (Snow)',
    66: 'Runner (Desert)',
    67: 'Peacock',
    68: 'Frog',
    69: 'Creature (Plant)',
    70: 'Creature (Radish)',
    71: 'Onionling',
    72: 'Onionling (Desert)',
    73: 'Devourer',
    74: 'Duckbill',
    75: 'Crocodile',
    76: 'Creature (Spike)',
    77: 'Anubis',
    78: 'Horus',
    79: 'Jester',
    80: 'Spectrino',
    81: 'Djinn',
    82: 'Minotaur',
    83: 'Nomad (Male)',
    84: 'Nomad (Female)',
    85: 'Imp',
    86: 'Spitter',
    87: 'Mole',
    88: 'Biter',
    89: 'Koala',
    90: 'Squirrel',
    91: 'Raccoon',
    92: 'Owl',
    93: 'Penguin',
    94: 'Werewolf',
    95: 'Santa?',
    96: 'Zombie',
    97: 'Vampire',
    98: 'Horse',
    99: 'Camel',
    100: 'Cow',
    101: 'Dragon',
    102: 'Beetle (Dark)',
    103: 'Beetle (Fire)',
    104: 'Beetle (Snout)',
    105: 'Beetle (Lemon)',
    106: 'Crab',
    107: 'Crab (Sea)',
    108: 'Troll',
    109: 'Troll (Dark)',
    110: 'Helldemon',
    111: 'Golem',
    112: 'Golem (Ember)',
    113: 'Golem (Snow)',
    114: 'Yeti',
    115: 'Cyclops',
    116: 'Mammoth',
    117: 'Lich',
    118: 'Runegiant',
    119: 'Saurian',
    120: 'Bush',
    121: 'Bush (Snow)',
    122: 'Bush (Snowberry)',
    123: 'Plant (Cotton)',
    124: 'Scrub',
    125: 'Scrub (Cobweg)',
    126: 'Scrub (Fire)',
    127: 'Ginseng',
    128: 'Cactus',
    129: 'Christmas Tree',
    130: 'Thorntree',
    131: 'Deposit (Gold)',
    132: 'Deposit (Iron)',
    133: 'Deposit (Silver)',
    134: 'Deposit (Sandstone)',
    135: 'Deposit (Emerald)',
    136: 'Deposit (Sapphire)',
    137: 'Deposit (Ruby)',
    138: 'Deposit (Diamond)',
    139: 'Deposit (Icecrystal)',
    140: 'Scarecrow',
    141: 'Aim',
    142: 'Dummy',
    143: 'Vase',
    144: 'Bomb',
    145: 'Fish (Sapphire)',
    146: 'Fish (Lemon)',
    147: 'Seahorse',
    148: 'Mermaid',
    149: 'Merman',
    150: 'Shark',
    151: 'Bumblebee',
    152: 'Lanternfish',
    153: 'Mawfish',
    154: 'Piranha',
    155: 'Blowfish'
}
