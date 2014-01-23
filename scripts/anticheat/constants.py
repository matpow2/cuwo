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

""" Anti Cheat script for Cuwo by Sarcen """

from cuwo.constants import (WARRIOR_CLASS, RANGER_CLASS,
                            MAGE_CLASS, ROGUE_CLASS)
from cuwo.vector import Vector3

CUWO_ANTICHEAT = "cuwo anti-cheat"

LOG_LEVEL_VERBOSE = 2
LOG_LEVEL_DEFAULT = 1
LOG_LEVEL_NONE = 0

LEGAL_CLASSES = (WARRIOR_CLASS, RANGER_CLASS, MAGE_CLASS, ROGUE_CLASS)

FLAGS_1_CLIMBING = 0
FLAGS_1_ATTACKING = 2
FLAGS_1_GLIDER_ACTIVE = 4

FLAGS_2_LANTERN_ON = 1
FLAGS_2_RANGER_STEALTH = 2

TWOHANDED_WEAPONS = (5, 6, 7, 10, 11, 15, 16, 17)

LEGAL_RECIPE_ITEMS = (3, 4, 5, 6, 7, 8)

LEGAL_ITEMS = dict({
    # Consumables
    (1, 1): (0, ),
    (1, 2): (0, ),

    (1, 4): (0, ),
    (1, 5): (0, ),
    (1, 6): (0, ),
    (1, 7): (0, ),
    (1, 8): (0, ),
    (1, 9): (0, ),
    # Weapons
    (3, 0): (1, ),   # 1h swords only iron
    (3, 1): (1, ),   # axes only iron
    (3, 2): (1, ),   # maces only iron
    (3, 3): (1, ),   # daggers only iron
    (3, 4): (1, ),   # fists only iron
    (3, 5): (1, ),   # longswords only iron
    (3, 6): (2, ),   # bows, only wood
    (3, 7): (2, ),   # crossbows, only wood
    (3, 8): (2, ),   # boomerangs, only wood

    (3, 10): (2, ),  # wands, only wood
    (3, 11): (2, ),     # staffs, only wood
    (3, 12): (11, 12),   # bracelets, silver, gold

    (3, 13): (1, ),    # shields, only iron

    (3, 15): (1, ),    # 2h, only iron
    (3, 16): (1, ),    # 2h, only iron
    (3, 17): (1, 2),   # 2h mace, iron and wood
    # Equipment

    # chest warrior (iron), mage (silk), ranger(linen), rogue(cotton)
    (4, 0): (1, 25, 26, 27),
    # gloves warrior (iron), mage (silk), ranger(linen), rogue(cotton)
    (5, 0): (1, 25, 26, 27),
    # boots warrior (iron), mage (silk), ranger(linen), rogue(cotton)
    (6, 0): (1, 25, 26, 27),
    # shoulder warrior (iron), mage (silk), ranger(linen), rogue(cotton)
    (7, 0): (1, 25, 26, 27),
    (8, 0): (11, 12),  # rings, gold and silver
    (9, 0): (11, 12),  # amulets, gold and silver
    (11, 0): (1, 11, 12, 13, 14, 15, 16),
    (11, 1): (2, ),
    (11, 2): (19, ),   # I've only ever seen parrot feathers, are there others?
    (11, 5): (21, ),
    (11, 6): (0, ),
    (11, 9): (26, 27),
    (11, 11): (27, ),
    (11, 12): (24, ),

    (11, 14): (128, 129, 130, 131),
    (11, 15): (0, ),
    (11, 16): (0, ),
    (11, 17): (0, ),
    (11, 18): (0, ),
    (11, 19): (9, ),
    (11, 20): (0, ),
    (11, 21): (0, ),
    (11, 22): (0, ),
    (11, 23): (0, ),
    (11, 24): (0, ),

    (11, 26): (0, ),
    (11, 27): (0, ),

    (14, 0): (0, ),    # leftovers
    (18, 0): (0, ),    # candle
    (18, 1): (0, ),    # candle
    (23, 0): (2, ),    # wood hanglider
    (23, 1): (2, ),    # wood boat
    (24, 0): (1, ),    # lamp, iron
})

LEGAL_PETS = (19, 22, 23, 25, 26, 27, 30, 33, 34, 35, 36, 37, 38, 39, 40, 50,
              53, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 74, 75,
              86, 87, 88, 90, 91, 92, 93, 98, 99, 102, 103, 104, 105, 106, 151)


# generate pets and petfood in the legal item list based on legal pets
def generate_pets():
    for pet in LEGAL_PETS:
        LEGAL_ITEMS[(19, pet)] = (0, )
        LEGAL_ITEMS[(20, pet)] = (0, )


generate_pets()

LEGAL_ITEMSLOTS = dict({
    3: (6, 7),
    4: (2, ),
    5: (4, ),
    6: (3, ),
    7: (5, ),
    8: (1, ),
    9: (8, 9),
    19: (12, ),
    20: (12, ),
    23: (11, ),
    24: (10, ),
})

ARMOR_IDS = (4, 5, 6, 7)

CLASS_WEAPONS = dict({
    WARRIOR_CLASS: (0, 1, 2, 13, 15, 16, 17),  # Warrior
    RANGER_CLASS: (6, 7, 8),                   # Ranger
    MAGE_CLASS: (10, 11, 12),                  # Mage
    ROGUE_CLASS: (3, 4, 5)                     # Rogue
})

CLASS_ARMOR = dict({
    WARRIOR_CLASS: (1, ),                      # Warrior
    RANGER_CLASS: (26, ),                      # Ranger
    MAGE_CLASS: (25, ),                        # Mage
    ROGUE_CLASS: (27, )                        # Rogue
})

ALL_BUT_MAGE = (ROGUE_CLASS, RANGER_CLASS, WARRIOR_CLASS)

ABILITIES = dict({
    # One handed
    1: {'class': (WARRIOR_CLASS, ),
        'weapon': (0, 1, 2)},
    2: {'class': (WARRIOR_CLASS, ),
        'weapon': (0, 1, 2)},
    68: {'class': (WARRIOR_CLASS, ),
         'weapon': (0, 1, 2)},

    # Mouse 2 Longsword skill
    5: {'class': (ROGUE_CLASS, ),
        'weapon': (5, )},

    # Mouse 1 Unarmed\fist skills
    6: {'class': ALL_BUT_MAGE,
        'weapon': (-1, 4)},
    7: {'class': ALL_BUT_MAGE,
        'weapon': (-1, 4)},

    # Shield skills
    8: {'class': (WARRIOR_CLASS, ),
        'weapon': (13, )},
    9: {'class': (WARRIOR_CLASS, ),
        'weapon': (13, )},
    10: {'class': (WARRIOR_CLASS, ),
         'weapon': (13, )},

    # Mouse 2 Unarmed skills
    11: {'weapon': (-1, 0, 1, 2)},
    63: {'weapon': (-1, 0, 1, 2)},

    # Fist skill
    20: {'class': (ROGUE_CLASS, ),
         'weapon': (4, )},

    # Mouse 1 Longsword skills
    13: {'class': (ROGUE_CLASS, ),
         'weapon': (5, )},
    14: {'class': (ROGUE_CLASS, ),
         'weapon': (5, )},

    # Dagger skills
    17: {'class': (ROGUE_CLASS, ),
         'weapon': (3, ),
         'mana_consumption': 1.0},
    18: {'class': (ROGUE_CLASS, ),
         'weapon': (3, )},
    19: {'class': (ROGUE_CLASS, ),
         'weapon': (3, )},

    # Ranger skill 2 (Retreat)
    21: {'class': (RANGER_CLASS, ), },

    # Bow and crossbow basic attack
    22: {'class': (RANGER_CLASS, ),
         'weapon': (6, 7)},

    # Crossbow skills
    23: {'class': (RANGER_CLASS, ),
         'weapon': (7, )},
    24: {'class': (RANGER_CLASS, ),
         'weapon': (7, )},

    # Bow skills
    25: {'class': (RANGER_CLASS, ),
         'weapon': (6, )},
    55: {'class': (RANGER_CLASS, ),
         'weapon': (6, ),
         'mana_consumption': 0.0},

    # Boomerang skills
    26: {'class': (RANGER_CLASS, ),
         'weapon': (8, )},
    27: {'class': (RANGER_CLASS, ),
         'weapon': (8, )},

    # Fire Staff skills
    30: {'class': (MAGE_CLASS, ),
         'spec': 0,
         'weapon': (10, )},
    31: {'class': (MAGE_CLASS, ),
         'spec': 0,
         'weapon': (10, )},

    # Water Staff skills
    32: {'class': (MAGE_CLASS, ),
         'spec': 1,
         'weapon': (10, )},
    33: {'class': (MAGE_CLASS, ),
         'spec': 1,
         'weapon': (10, )},

    # Water Mage skill 1 (heal)
    34: {'class': (MAGE_CLASS, ),
         'spec': 1},

    # Fire Bracelet\unarmed skills
    37: {'class': (MAGE_CLASS, ),
         'spec': 0,
         'weapon': (12, -1)},
    39: {'class': (MAGE_CLASS, ),
         'spec': 0,
         'weapon': (12, -1)},
    40: {'class': (MAGE_CLASS, ),
         'spec': 0,
         'weapon': (12, -1)},

    # Fire Wand skills
    38: {'class': (MAGE_CLASS, ),
         'spec': 0,
         'weapon': (11, )},
    46: {'class': (MAGE_CLASS, ),
         'spec': 0,
         'weapon': (11, )},

    # Water Bracelet\Unarmed skills
    41: {'class': (MAGE_CLASS, ),
         'spec': 1,
         'weapon': (12, -1)},
    42: {'class': (MAGE_CLASS, ),
         'spec': 1,
         'weapon': (12, -1)},
    43: {'class': (MAGE_CLASS, ),
         'spec': 1,
         'weapon': (12, -1)},

    # Water Wand skills
    44: {'class': (MAGE_CLASS, ),
         'spec': 1,
         'weapon': (11, )},
    45: {'class': (MAGE_CLASS, ),
         'spec': 1,
         'weapon': (11, )},

    # Rogue skill 1 (Charge)
    48: {'class': (ROGUE_CLASS, ),
         'cooldown': 8.0},

    # Mage skill 3 (Teleport)
    49: {'class': (MAGE_CLASS, ),
         'cooldown': 6.0},

    # Warrior skill 1 (Slam)
    54: {'class': (WARRIOR_CLASS, ),
         'cooldown': 6.0},

    # Two handed skills
    57: {'class': (WARRIOR_CLASS, ),
         'weapon': (15, 16, 17)},
    58: {'class': (WARRIOR_CLASS, ),
         'weapon': (15, 16, 17)},
    59: {'class': (WARRIOR_CLASS, ),
         'weapon': (15, 16, 17)},
    60: {'class': (WARRIOR_CLASS, ),
         'weapon': (15, 16, 17)},
    61: {'class': (WARRIOR_CLASS, ),
         'weapon': (15, 16, 17)},
    67: {'class': (WARRIOR_CLASS, ),
         'weapon': (15, 16, 17)},

    # Rogue Skill 2 (Stealth)
    79: {'class': (ROGUE_CLASS, ), },

    # Mage Skill 1 (Fire Explosion)
    88: {'class': (MAGE_CLASS, ),
         'spec': 0},

    # Warrior Skill 2 (Spinning blade attack)
    86: {'class': (WARRIOR_CLASS, ),
         'cooldown': 20.0},

    # Rogue Skill 3 (Ninja stars)
    96: {'class': (ROGUE_CLASS, ),
         'spec': 1,
         'cooldown': 6.0},

    # Warrior Skill 3 (Bulwark)
    101: {'class': (WARRIOR_CLASS, ),
          'spec': 1},

    # Mage Skill 2 (Mana shield)
    103: {'class': (MAGE_CLASS, ), },

    # Shield
    104: {'class': (WARRIOR_CLASS, ),
          'weapon': (13, )},


    # Generic
    80: {},     # Drink potion
    81: {},     # Eat
    82: {},     # Present pet food
    83: {},     # Sit
    84: {},     # Sleep
    106: {},    # Ride pet
    107: {}     # Sailing
})

APPEARANCES = dict({
    2: {'scale': 0.96,
        'radius': 0.96,
        'height': 2.16,
        'scale_head': 1.01,
        'scale_feet': 0.98,
        'scale_hand': 1.00,
        'scale_body': 1.00,
        'scale_back': 0.80,
        'scale_shoulder': 1.00,
        'scale_weapon': 0.98,
        'scale_wing': 1.00,
        'scale_unknown': 1.00,
        'offset_body': Vector3(0, 0, -5),
        'offset_head': Vector3(0, 0.5, 5),
        'offset_hand': Vector3(6, 0, 0),
        'offset_foot': Vector3(3, 1, -10.5),
        'offset_back': Vector3(0, -8, 2),
        'offset_wing': Vector3(0, 0, 0),
        'model_head': range(1246, 1251 + 1),
        'model_hair': range(1252, 1266 + 1),
        'model_feet': (432, ),
        'model_hand': (430, 431),
        'model_body': (1, ),
        'model_back': (-1, ),
        'model_shoulder': (-1, ),
        'model_wing': (-1, )},

    3: {'scale': 0.96,
        'radius': 0.96,
        'height': 2.16,
        'scale_head': 1.01,
        'scale_feet': 0.98,
        'scale_hand': 1.00,
        'scale_body': 1.00,
        'scale_back': 0.80,
        'scale_shoulder': 1.00,
        'scale_weapon': 0.98,
        'scale_wing': 1.00,
        'scale_unknown': 1.00,
        'offset_body': Vector3(0, 0, -5),
        'offset_head': Vector3(0, 0.5, 5),
        'offset_hand': Vector3(6, 0, 0),
        'offset_foot': Vector3(3, 1, -10.5),
        'offset_back': Vector3(0, -8, 2),
        'offset_wing': Vector3(0, 0, 0),
        'model_head': range(1267, 1272 + 1),
        'model_hair': range(1273, 1279 + 1),
        'model_feet': (432, ),
        'model_hand': (430, 431),
        'model_body': (1, ),
        'model_back': (-1, ),
        'model_shoulder': (-1, ),
        'model_wing': (-1, )},

    0: {'scale': 0.96,
        'radius': 0.96,
        'height': 2.16,
        'scale_head': 1.01,
        'scale_feet': 0.98,
        'scale_hand': 1.00,
        'scale_body': 1.00,
        'scale_back': 0.80,
        'scale_shoulder': 1.00,
        'scale_weapon': 0.98,
        'scale_wing': 1.00,
        'scale_unknown': 1.00,
        'offset_body': Vector3(0, 0, -5),
        'offset_head': Vector3(0, 0.5, 5),
        'offset_hand': Vector3(6, 0, 0),
        'offset_foot': Vector3(3, 1, -10.5),
        'offset_back': Vector3(0, -8, 2),
        'offset_wing': Vector3(0, 0, 0),
        'model_head': range(1236, 1239 + 1),
        'model_hair': range(1280, 1289 + 1),
        'model_feet': (432, ),
        'model_hand': (430, ),
        'model_body': (1, ),
        'model_back': (-1, ),
        'model_shoulder': (-1, ),
        'model_wing': (-1, )},

    1: {'scale': 0.96,
        'radius': 0.96,
        'height': 2.16,
        'scale_head': 1.01,
        'scale_feet': 0.98,
        'scale_hand': 1.00,
        'scale_body': 1.00,
        'scale_back': 0.80,
        'scale_shoulder': 1.00,
        'scale_weapon': 0.98,
        'scale_wing': 1.00,
        'scale_unknown': 1.00,
        'offset_body': Vector3(0, 0, -5),
        'offset_head': Vector3(0, 0.5, 5),
        'offset_hand': Vector3(6, 0, 0),
        'offset_foot': Vector3(3, 1, -10.5),
        'offset_back': Vector3(0, -8, 2),
        'offset_wing': Vector3(0, 0, 0),
        'model_head': range(1240, 1245 + 1),
        'model_hair': range(1290, 1299 + 1),
        'model_feet': (432, ),
        'model_hand': (430, ),
        'model_body': (0, ),
        'model_back': (-1, ),
        'model_shoulder': (-1, ),
        'model_wing': (-1, )},

    9: {'scale': 0.80,
        'radius': 0.80,
        'height': 1.80,
        'model_head': range(282, 286 + 1),
        'model_hair': range(287, 289 + 1),
        'model_hand': (430, 431),
        'model_feet': (432,),
        'model_body': (300,),
        'model_back': (-1,),
        'model_shoulder': (-1,),
        'model_wing': (-1,),
        'scale_head': 0.90,
        'scale_body': 1.00,
        'scale_hand': 1.00,
        'scale_feet': 0.98,
        'scale_weapon': 1.2,
        'scale_back': 0.80,
        'scale_shoulder': 1.00,
        'scale_wing': 1.00,
        'scale_unknown': 1.00,
        'offset_body': Vector3(0, 0, -5),
        'offset_head': Vector3(0, 0.5, 5),
        'offset_hand': Vector3(6, 0, 0),
        'offset_foot': Vector3(3, 1, -10.5),
        'offset_back': Vector3(0, -8, 2),
        'offset_wing': Vector3(0, 0, 0)},

    10: {'scale': 0.80,
         'radius': 0.80,
         'height': 1.80,
         'model_head': range(290, 294 + 1),
         'model_hair': range(295, 299 + 1),
         'model_hand': (430, 431),
         'model_feet': (432,),
         'model_body': (301,),
         'model_back': (-1,),
         'model_shoulder': (-1,),
         'model_wing': (-1,),
         'scale_head': 0.90,
         'scale_body': 1.00,
         'scale_hand': 1.00,
         'scale_feet': 0.98,
         'scale_weapon': 1.2,
         'scale_back': 0.80,
         'scale_shoulder': 1.00,
         'scale_wing': 1.00,
         'scale_unknown': 1.00,
         'offset_body': Vector3(0, 0, -5),
         'offset_head': Vector3(0, 0.5, 5),
         'offset_hand': Vector3(6, 0, 0),
         'offset_foot': Vector3(3, 1, -10.5),
         'offset_back': Vector3(0, -8, 2),
         'offset_wing': Vector3(0, 0, 0)},

    11: {'scale': 1.04,
         'radius': 1.04,
         'height': 2.34,
         'model_head': range(1300, 1304 + 1),
         'model_hair': range(1310, 1319 + 1),
         'model_hand': (302,),
         'model_feet': (432,),
         'model_body': (0,),
         'model_back': (-1,),
         'model_shoulder': (-1,),
         'model_wing': (-1,),
         'scale_head': 0.90,
         'scale_body': 1.00,
         'scale_hand': 1.00,
         'scale_feet': 0.98,
         'scale_weapon': 0.95,
         'scale_back': 0.80,
         'scale_shoulder': 1.00,
         'scale_wing': 1.00,
         'scale_unknown': 1.20,
         'offset_body': Vector3(0, 0, -5),
         'offset_head': Vector3(0, 0.5, 5),
         'offset_hand': Vector3(6, 0, 0),
         'offset_foot': Vector3(3, 1, -10.5),
         'offset_back': Vector3(0, -8, 2),
         'offset_wing': Vector3(0, 0, 0)},

    12: {'scale': 1.04,
         'radius': 1.04,
         'height': 2.34,
         'model_head': range(1305, 1309 + 1),
         'model_hair': range(1320, 1323 + 1),
         'model_hand': (302,),
         'model_feet': (432,),
         'model_body': (0,),
         'model_back': (-1,),
         'model_shoulder': (-1,),
         'model_wing': (-1,),
         'scale_head': 0.80,
         'scale_body': 0.95,
         'scale_hand': 1.00,
         'scale_feet': 0.98,
         'scale_weapon': 0.95,
         'scale_back': 0.80,
         'scale_shoulder': 1.00,
         'scale_wing': 1.00,
         'scale_unknown': 1.20,
         'offset_body': Vector3(0, 0, -5),
         'offset_head': Vector3(0.00, 1.50, 4.00),
         'offset_hand': Vector3(6, 0, 0),
         'offset_foot': Vector3(3, 1, -10.5),
         'offset_back': Vector3(0, -8, 2),
         'offset_wing': Vector3(0, 0, 0)},

    4: {'scale': 0.80,
        'radius': 0.80,
        'height': 1.80,
        'model_head': range(75, 79 + 1),
        'model_hair': range(80, 85 + 1),
        'model_hand': (97,),
        'model_feet': (432,),
        'model_body': (0,),
        'model_back': (-1,),
        'model_shoulder': (-1,),
        'model_wing': (-1,),
        'scale_head': 1.01,
        'scale_body': 1.00,
        'scale_hand': 1.00,
        'scale_feet': 0.98,
        'scale_weapon': 1.2,
        'scale_back': 0.80,
        'scale_shoulder': 1.00,
        'scale_wing': 1.00,
        'scale_unknown': 1.00,
        'offset_body': Vector3(0, 0, -5),
        'offset_head': Vector3(0, 0.5, 5),
        'offset_hand': Vector3(6, 0, 0),
        'offset_foot': Vector3(3, 1, -10.5),
        'offset_back': Vector3(0, -8, 2),
        'offset_wing': Vector3(0, 0, 0)},

    5: {'scale': 0.80,
        'radius': 0.80,
        'height': 1.80,
        'model_head': range(86, 90 + 1),
        'model_hair': range(91, 96 + 1),
        'model_hand': (97,),
        'model_feet': (432,),
        'model_body': (0,),
        'model_back': (-1, ),
        'model_shoulder': (-1, ),
        'model_wing': (-1, ),
        'scale_head': 1.01,
        'scale_body': 1.00,
        'scale_hand': 1.00,
        'scale_feet': 0.98,
        'scale_weapon': 1.20,
        'scale_back': 0.80,
        'scale_shoulder': 1.00,
        'scale_wing': 1.00,
        'scale_unknown': 1.00,
        'offset_body': Vector3(0, 0, -5),
        'offset_head': Vector3(0, 0.5, 5),
        'offset_hand': Vector3(6, 0, 0),
        'offset_foot': Vector3(3, 1, -10.5),
        'offset_back': Vector3(0, -8, 2),
        'offset_wing': Vector3(0, 0, 0)},

    7: {'scale': 0.96,
        'radius': 0.96,
        'height': 2.16,
        'model_head': range(98, 99 + 1),
        'model_hair': range(100, 105 + 1),
        'model_hand': (111,),
        'model_feet': (113,),
        'model_body': (112,),
        'model_back': (-1,),
        'model_shoulder': (-1,),
        'model_wing': (-1,),
        'scale_head': 1.01,
        'scale_body': 1.00,
        'scale_hand': 1.00,
        'scale_feet': 0.98,
        'scale_weapon': 0.95,
        'scale_back': 0.80,
        'scale_shoulder': 1.00,
        'scale_wing': 1.00,
        'scale_unknown': 1.00,
        'offset_body': Vector3(0, 0, -5),
        'offset_head': Vector3(0, 0.5, 5),
        'offset_hand': Vector3(6, 0, 0),
        'offset_foot': Vector3(3, 1, -10.5),
        'offset_back': Vector3(0, -8, 2),
        'offset_wing': Vector3(0, 0, 0)},

    8: {'scale': 0.96,
        'radius': 0.96,
        'height': 2.16,
        'model_head': range(106, 111 + 1),
        'model_hair': range(100, 105 + 1),
        'model_hand': (111,),
        'model_feet': (113,),
        'model_body': (112,),
        'model_back': (-1,),
        'model_shoulder': (-1,),
        'model_wing': (-1,),
        'scale_head': 1.01,
        'scale_body': 1.00,
        'scale_hand': 1.00,
        'scale_feet': 0.98,
        'scale_weapon': 0.95,
        'scale_back': 0.80,
        'scale_shoulder': 1.00,
        'scale_wing': 1.00,
        'scale_unknown': 1.00,
        'offset_body': Vector3(0, 0, -5),
        'offset_head': Vector3(0, 0.5, 5),
        'offset_hand': Vector3(6, 0, 0),
        'offset_foot': Vector3(3, 1, -10.5),
        'offset_back': Vector3(0, -8, 2),
        'offset_wing': Vector3(0, 0, 0)},

    15: {'scale': 0.96,
         'radius': 0.96,
         'height': 2.16,
         'model_hair': range(309, 314 + 1),
         'model_head': range(303, 308 + 1),
         'model_hand': (327,),
         'model_feet': (432,),
         'model_body': (0,),
         'model_back': (-1,),
         'model_shoulder': (-1,),
         'model_wing': (-1,),
         'scale_head': 0.90,
         'scale_body': 1.00,
         'scale_hand': 1.00,
         'scale_feet': 0.98,
         'scale_weapon': 0.95,
         'scale_back': 0.80,
         'scale_shoulder': 1.00,
         'scale_wing': 1.00,
         'scale_unknown': 1.00,
         'offset_body': Vector3(0, 0, -5),
         'offset_head': Vector3(0, 0.5, 5),
         'offset_hand': Vector3(6, 0, 0),
         'offset_foot': Vector3(3, 1, -10.5),
         'offset_back': Vector3(0, -8, 2),
         'offset_wing': Vector3(0, 0, 0)},

    16: {'scale': 0.96,
         'radius': 0.96,
         'height': 2.16,
         'model_hair': range(321, 326 + 1),
         'model_head': range(315, 320 + 1),
         'model_hand': (327, ),
         'model_feet': (432, ),
         'model_body': (0, ),
         'model_back': (-1, ),
         'model_shoulder': (-1, ),
         'model_wing': (-1, ),
         'scale_head': 0.90,
         'scale_body': 1.00,
         'scale_hand': 1.00,
         'scale_feet': 0.98,
         'scale_weapon': 0.95,
         'scale_back': 0.80,
         'scale_shoulder': 1.00,
         'scale_wing': 1.00,
         'scale_unknown': 1.00,
         'offset_body': Vector3(0, 0, -5),
         'offset_head': Vector3(0, 0.5, 5),
         'offset_hand': Vector3(6, 0, 0),
         'offset_foot': Vector3(3, 1, -10.5),
         'offset_back': Vector3(0, -8, 2),
         'offset_wing': Vector3(0, 0, 0)},

    13: {'scale': 0.96,
         'radius': 0.96,
         'height': 2.16,
         'model_head': range(1324, 1328 + 1),
         'model_hair': range(1329, 1333 + 1),
         'model_hand': (1342, ),
         'model_feet': (432, ),
         'model_body': (1, ),
         'model_back': (-1, ),
         'model_shoulder': (-1, ),
         'model_wing': (-1, ),
         'scale_head': 1.01,
         'scale_body': 1.00,
         'scale_hand': 1.00,
         'scale_feet': 0.98,
         'scale_weapon': 0.95,
         'scale_back': 0.80,
         'scale_shoulder': 1.00,
         'scale_wing': 1.00,
         'scale_unknown': 1.00,
         'offset_body': Vector3(0, 0, -5),
         'offset_head': Vector3(0, 0.5, 5),
         'offset_hand': Vector3(6, 0, 0),
         'offset_foot': Vector3(3, 1, -10.5),
         'offset_back': Vector3(0, -8, 2),
         'offset_wing': Vector3(0, 0, 0)},

    14: {'scale': 0.96,
         'radius': 0.96,
         'height': 2.16,
         'model_head': range(1334, 1337 + 1),
         'model_hair': range(1338, 1341 + 1),
         'model_hand': (1342, ),
         'model_feet': (432, ),
         'model_body': (1, ),
         'model_back': (-1, ),
         'model_shoulder': (-1, ),
         'model_wing': (-1, ),
         'scale_head': 1.01,
         'scale_body': 1.00,
         'scale_hand': 1.00,
         'scale_feet': 0.98,
         'scale_weapon': 0.95,
         'scale_back': 0.80,
         'scale_shoulder': 1.00,
         'scale_wing': 1.00,
         'scale_unknown': 1.00,
         'offset_body': Vector3(0, 0, -5),
         'offset_head': Vector3(0, 0.5, 5),
         'offset_hand': Vector3(6, 0, 0),
         'offset_foot': Vector3(3, 1, -10.5),
         'offset_back': Vector3(0, -8, 2),
         'offset_wing': Vector3(0, 0, 0)}
})
