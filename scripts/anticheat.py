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

""" Anti Cheat script for Cuwo by Sarcen """

CUWO_ANTICHEAT = "cuwo anti-cheat"

LOG_LEVEL_VERBOSE = 2
LOG_LEVEL_DEFAULT = 1
LOG_LEVEL_NONE = 0

CLASS_WARRIOR = 1
CLASS_RANGER = 2
CLASS_MAGE = 3
CLASS_ROGUE = 4

LEGAL_CLASSES = (CLASS_WARRIOR, CLASS_RANGER, CLASS_MAGE, CLASS_ROGUE)

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
    CLASS_WARRIOR: (0, 1, 2, 13, 15, 16, 17),  # Warrior
    CLASS_RANGER: (6, 7, 8),                   # Ranger
    CLASS_MAGE: (10, 11, 12),                  # Mage
    CLASS_ROGUE: (3, 4, 5)                     # Rogue
})

CLASS_ARMOR = dict({
    CLASS_WARRIOR: (1, ),                      # Warrior
    CLASS_RANGER: (26, ),                      # Ranger
    CLASS_MAGE: (25, ),                        # Mage
    CLASS_ROGUE: (27, )                        # Rogue
})

ALL_BUT_MAGE = (CLASS_ROGUE, CLASS_RANGER, CLASS_WARRIOR)

ABILITIES = dict({
    # One handed
    1: {'class': (CLASS_WARRIOR, ),
        'weapon': (0, 1, 2)},
    2: {'class': (CLASS_WARRIOR, ),
        'weapon': (0, 1, 2)},
    68: {'class': (CLASS_WARRIOR, ),
         'weapon': (0, 1, 2)},

    # Mouse 2 Longsword skill
    5: {'class': (CLASS_ROGUE, ),
        'weapon': (5, )},

    # Mouse 1 Unarmed\fist skills
    6: {'class': ALL_BUT_MAGE,
        'weapon': (-1, 4)},
    7: {'class': ALL_BUT_MAGE,
        'weapon': (-1, 4)},

    # Shield skills
    8: {'class': (CLASS_WARRIOR, ),
        'weapon': (13, )},
    9: {'class': (CLASS_WARRIOR, ),
        'weapon': (13, )},
    10: {'class': (CLASS_WARRIOR, ),
         'weapon': (13, )},

    # Mouse 2 Unarmed skills
    11: {'weapon': (-1, 0, 1, 2)},
    63: {'weapon': (-1, 0, 1, 2)},

    # Fist skill
    20: {'class': (CLASS_ROGUE, ),
         'weapon': (4, )},

    # Mouse 1 Longsword skills
    13: {'class': (CLASS_ROGUE, ),
         'weapon': (5, )},
    14: {'class': (CLASS_ROGUE, ),
         'weapon': (5, )},

    # Dagger skills
    17: {'class': (CLASS_ROGUE, ),
         'weapon': (3, )},
    18: {'class': (CLASS_ROGUE, ),
         'weapon': (3, )},
    19: {'class': (CLASS_ROGUE, ),
         'weapon': (3, )},

    # Ranger skill 2 (Retreat)
    21: {'class': (CLASS_RANGER, ), },

    # Bow and crossbow basic attack
    22: {'class': (CLASS_RANGER, ),
         'weapon': (6, 7)},

    # Crossbow skills
    23: {'class': (CLASS_RANGER, ),
         'weapon': (7, )},
    24: {'class': (CLASS_RANGER, ),
         'weapon': (7, )},

    # Bow skills
    25: {'class': (CLASS_RANGER, ),
         'weapon': (6, )},
    55: {'class': (CLASS_RANGER, ),
         'weapon': (6, )},

    # Boomerang skills
    26: {'class': (CLASS_RANGER, ),
         'weapon': (8, )},
    27: {'class': (CLASS_RANGER, ),
         'weapon': (8, )},

    # Fire Staff skills
    30: {'class': (CLASS_MAGE, ),
         'spec': 0,
         'weapon': (10, )},
    31: {'class': (CLASS_MAGE, ),
         'spec': 0,
         'weapon': (10, )},

    # Water Staff skills
    32: {'class': (CLASS_MAGE, ),
         'spec': 1,
         'weapon': (10, )},
    33: {'class': (CLASS_MAGE, ),
         'spec': 1,
         'weapon': (10, )},

    # Water Mage skill 1 (heal)
    34: {'class': (CLASS_MAGE, ),
         'spec': 1},

    # Fire Bracelet\unarmed skills
    37: {'class': (CLASS_MAGE, ),
         'spec': 0,
         'weapon': (12, -1)},
    39: {'class': (CLASS_MAGE, ),
         'spec': 0,
         'weapon': (12, -1)},
    40: {'class': (CLASS_MAGE, ),
         'spec': 0,
         'weapon': (12, -1)},

    # Fire Wand skills
    38: {'class': (CLASS_MAGE, ),
         'spec': 0,
         'weapon': (11, )},
    46: {'class': (CLASS_MAGE, ),
         'spec': 0,
         'weapon': (11, )},

    # Water Bracelet\Unarmed skills
    41: {'class': (CLASS_MAGE, ),
         'spec': 1,
         'weapon': (12, -1)},
    42: {'class': (CLASS_MAGE, ),
         'spec': 1,
         'weapon': (12, -1)},
    43: {'class': (CLASS_MAGE, ),
         'spec': 1,
         'weapon': (12, -1)},

    # Water Wand skills
    44: {'class': (CLASS_MAGE, ),
         'spec': 1,
         'weapon': (11, )},
    45: {'class': (CLASS_MAGE, ),
         'spec': 1,
         'weapon': (11, )},

    # Rogue skill 1 (Charge)
    48: {'class': (CLASS_ROGUE, ), },

    # Mage skill 3 (Teleport)
    49: {'class': (CLASS_MAGE, ), },

    # Warrior skill 1 (Slam)
    54: {'class': (CLASS_WARRIOR, ), },

    # Two handed skills
    57: {'class': (CLASS_WARRIOR, ),
         'weapon': (15, 16, 17)},
    58: {'class': (CLASS_WARRIOR, ),
         'weapon': (15, 16, 17)},
    59: {'class': (CLASS_WARRIOR, ),
         'weapon': (15, 16, 17)},
    60: {'class': (CLASS_WARRIOR, ),
         'weapon': (15, 16, 17)},
    61: {'class': (CLASS_WARRIOR, ),
         'weapon': (15, 16, 17)},
    67: {'class': (CLASS_WARRIOR, ),
         'weapon': (15, 16, 17)},

    # Rogue Skill 2 (Stealth)
    79: {'class': (CLASS_ROGUE, ), },

    # Mage Skill 1 (Fire Explosion)
    88: {'class': (CLASS_MAGE, ),
         'spec': 0},

    # Warrior Skill 2 (Spinning blade attack)
    86: {'class': (CLASS_WARRIOR, ), },

    # Rogue Skill 3 (Ninja stars)
    96: {'class': (CLASS_ROGUE, ),
         'spec': 1},

    # Warrior Skill 3 (Bulwark)
    101: {'class': (CLASS_WARRIOR, ),
          'spec': 1},

    # Mage Skill 2 (Mana shield)
    103: {'class': (CLASS_MAGE, ), },

    # Shield
    104: {'class': (CLASS_WARRIOR, ),
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

ITEM_NAMES = {0: 'Crash',
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
              24: 'Lamp'}

CONSUMABLE_NAMES = {0: 'Cookie',
                    1: 'Life Potion',
                    2: 'Cactus Potion',
                    3: 'Mana Potion',
                    4: 'Ginseng Soup',
                    5: 'Snowberry Mash',
                    6: 'Mushroom Spit',
                    7: 'Bomb',
                    8: 'Pineapple Slice',
                    9: 'Pumpkin Muffin',
                    10: 'Mushroom?'}

WEAPON_NAMES = {0: 'Sword',
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
                20: 'Torch'}

MATERIAL_NAMES = {1: 'Iron',
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

NPC_NAMES = {0: 'Elf (Male)',
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
             129: 'Christmas Tree?',
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


from cuwo.script import (ServerScript,
                         ConnectionScript, command, admin,
                         get_player)
from cuwo.packet import ServerUpdate, PickupAction
import re
import time


def calc_power_level(level):
    return int(((1.0 - (1.0 / (((float(level) - 1.0) * 0.05)
                + 1.0))) * 100.0) + 1.0)


def get_item_name(item):
    name = ""

    if item.material in MATERIAL_NAMES:
        name = name + MATERIAL_NAMES[item.material] + " "

    if item.type in ITEM_NAMES:
        name = name + ITEM_NAMES[item.type] + " "

    if item.type == 1 and item.sub_type in CONSUMABLE_NAMES:
        name = name + CONSUMABLE_NAMES[item.sub_type] + " "

    if item.type == 3 and item.sub_type in WEAPON_NAMES:
        name = name + WEAPON_NAMES[item.sub_type] + " "

    if item.type == 19 and item.sub_type in NPC_NAMES:
        name = name + NPC_NAMES[item.sub_type] + " "

    power = calc_power_level(item.level)
    name = name + "+" + str(power)

    return name


def get_class():
    return AntiCheatServer


class AntiCheatConnection(ConnectionScript):

    combat_end_time = 0

    def on_load(self):
        config = self.server.config.anticheat
        self.level_cap = config.level_cap
        self.allow_dual_wield = config.allow_dual_wield
        self.rarity_cap = config.rarity_cap
        self.name_filter = config.name_filter
        self.log_level = config.log_level
        self.log_message = config.log_message
        self.disconnect_message = config.disconnect_message
        self.welcome_message = config.welcome_message
        self.irc_log_level = config.irc_log_level

    def on_join(self, event):

        if self.on_name_update() is False:
            return False

        if self.on_class_update() is False:
            return False

        if self.on_equipment_update() is False:
            return False

        if self.on_level_update() is False:
            return False

        if self.on_skill_update() is False:
            return False

        if self.on_multiplier_update() is False:
            return False

        self.connection.send_chat(self.welcome_message
                                  .format(name=CUWO_ANTICHEAT))

    def on_name_update(self, event=None):
        if self.has_illegal_name():
            self.remove_cheater('illegal character name')
            return False

    def on_equipment_update(self, event=None):
        if self.has_illegal_items():
            self.remove_cheater('illegal items are equipped')
            return False

    def on_level_update(self, event=None):
        if self.has_illegal_level():
            self.remove_cheater('illegal character level, max:' +
                                str(self.level_cap))
            return False

    def on_skill_update(self, event=None):
        if self.has_illegal_skills():
            self.remove_cheater('illegal skill distribution')
            return False

    def on_mode_update(self, event=None):
        entity_data = self.connection.entity_data

        if (entity_data.current_mode == 0
                and self.combat_end_time == 0):
            self.combat_end_time = time.time()

        if entity_data.current_mode != 0:
            self.combat_end_time = 0

        if self.has_illegal_mode():
            self.remove_cheater('illegal character mode (ability)')
            return False

    def on_class_update(self, event=None):
        if self.has_illegal_class():
            self.remove_cheater('illegal character class')
            return False

    def on_multiplier_update(self, event=None):
        if self.has_illegal_multiplier():
            self.remove_cheater('illegal attribute multiplier')
            return False

    def on_charged_mp_update(self, event=None):
        if self.has_illegal_charged_mp():
            self.remove_cheater('illegal charge multiplier')
            return False

    def on_drop(self, event):
        if self.is_item_illegal(event.item):
            pack = ServerUpdate()
            pack.reset()
            action = PickupAction()
            action.entity_id = self.connection.entity_id
            action.item_data = event.item
            pack.pickups.append(action)

            self.connection.send_packet(pack)

            self.remove_cheater('illegal item dropped')
            return False

    def log(self, message, loglevel=LOG_LEVEL_DEFAULT):
        if self.log_level >= loglevel:
            print CUWO_ANTICHEAT + " - " + message
        if self.irc_log_level >= loglevel:
            try:
                self.server.scripts.irc.send(CUWO_ANTICHEAT + " - " + message)
            except KeyError:
                print ("{anticheat} - irc not found, logging to " +
                       "irc automatically turned off").format(
                    anticheat=CUWO_ANTICHEAT)
            except AttributeError:
                print ("{anticheat} - irc not found, logging to " +
                       "irc automatically turned off").format(
                    anticheat=CUWO_ANTICHEAT)

                self.irc_log_level = 0

    def remove_cheater(self, reason):
        connection = self.connection
        self.log(self.log_message
                 .format(playername=connection.name,
                         ip=connection.address.host,
                         reason=reason))

        connection.send_chat(self.disconnect_message.
                             format(name=CUWO_ANTICHEAT,
                                    reason=reason))
        connection.disconnect()

    def has_illegal_name(self):
        entity_data = self.connection.entity_data

        if re.search(self.name_filter, entity_data.name) is None:
            self.log("character name does not meet requirements: {name}"
                     .format(name=entity_data.name), LOG_LEVEL_VERBOSE)
            return True

        return False

    def has_illegal_items(self):
        entity_data = self.connection.entity_data

        for slotindex in range(13):
            if entity_data.equipment[slotindex].type == 0:
                continue

            if self.is_item_illegal(entity_data.equipment[slotindex]):
                return True

            if self.is_equipped_illegal(entity_data.equipment[slotindex],
                                        slotindex):
                return True

        return False

    def is_item_illegal(self, item):
        # Negative item levels... almost as bad as rarity 255
        if item.level < 0:
            self.log("negative item level: level = {level}"
                     .format(level=item.level), LOG_LEVEL_VERBOSE)
            return True

        if item.upgrade_count > 32:
            self.log("too many customization blocks on item: " +
                     "level = {upgradecount}"
                     .format(upgradecount=item.upgrade_count),
                     LOG_LEVEL_VERBOSE)
            return True

        # Rarity is what makes the items truely broken and overpowered,
        # A rarity of 255 will make even a lvl 1 weapon do 2 billion damage.
        if item.rarity > self.rarity_cap:
            self.log("item rarity: {rarity}".format(
                     rarity=item.rarity), LOG_LEVEL_VERBOSE)
            return True

        # Item type 2 is a recipe they are handled differently.
        # minus modifier is the item type of the crafted item
        if item.type == 2:
            if not item.minus_modifier in LEGAL_RECIPE_ITEMS:
                self.log(("invalid recipe:type={type} " +
                         "subtype={stype} material={mat} item={item}")
                         .format(type=item.minus_modifier,
                                 stype=item.sub_type,
                                 mat=item.material,
                                 item=get_item_name(item)),
                         LOG_LEVEL_VERBOSE)
                return True

            if not (item.material in
                    LEGAL_ITEMS[(item.minus_modifier, item.sub_type)]):
                self.log(("invalid recipe:type={type} " +
                         "subtype={stype} material={mat} item={item}")
                         .format(type=item.minus_modifier,
                                 stype=item.sub_type,
                                 mat=item.material,
                                 item=get_item_name(item)),
                         LOG_LEVEL_VERBOSE)
                return True

            return False

        if not (item.type, item.sub_type) in LEGAL_ITEMS:
            self.log(("invalid item:type={type} " +
                     "subtype={stype} material={material} item={item}")
                     .format(type=item.type,
                             stype=item.sub_type,
                             material=item.material,
                             item=get_item_name(item)),
                     LOG_LEVEL_VERBOSE)
            return True

        if not item.material in LEGAL_ITEMS[(item.type, item.sub_type)]:
            self.log(("invalid material:type={type} " +
                     "subtype={stype} material={mat} item={item}")
                     .format(type=item.type,
                             stype=item.sub_type,
                             mat=item.material,
                             item=get_item_name(item)),
                     LOG_LEVEL_VERBOSE)
            return True

        return False

    def is_equipped_illegal(self, item, in_slotindex):
        entity_data = self.connection.entity_data

        power_item = calc_power_level(item.level)
        power_char = calc_power_level(entity_data.level)
        if power_item > power_char:
            self.log(("item level too high for character " +
                     "item: level:{level1} (power: {power1}) " +
                     "character: level:{level2} (power: {power2})")
                     .format(level1=item.level,
                             power1=power_item,
                             level2=entity_data.level,
                             power2=power_char), LOG_LEVEL_VERBOSE)
            return True

        if not item.type in LEGAL_ITEMSLOTS:
            self.log("non equipable item slot:" +
                     "type={type} subtype={subtype} slot={slot}"
                     .format(type=item.type,
                             subtype=item.sub_type,
                             slot=in_slotindex), LOG_LEVEL_VERBOSE)
            return True

        if not in_slotindex in LEGAL_ITEMSLOTS[item.type]:
            self.log("item in invalid slot:" +
                     "type={type} subtype={subtype} slot={slot}"
                     .format(type=item.type,
                             subtype=item.sub_type,
                             slot=in_slotindex), LOG_LEVEL_VERBOSE)
            return True

        if in_slotindex == 6 and item.sub_type in TWOHANDED_WEAPONS:
            if (self.allow_dual_wield is False
                    and entity_data.equipment[7].type != 0):
                self.log("dual wield bug" +
                        (" weapon (slot6) = {item1}" +
                         " weapon (slot7) = {item2}")
                         .format(item1=item.sub_type,
                                 item2=entity_data.equipment[7].sub_type),
                         LOG_LEVEL_VERBOSE)
                return True
            if entity_data.equipment[7].sub_type in TWOHANDED_WEAPONS:
                self.log("dual wield two handers" +
                        (" weapon (slot6) = {item1}" +
                         " weapon (slot7) = {item2}")
                         .format(item1=entity_data.equipment[6].sub_type,
                                 item2=entity_data.equipment[7].sub_type),
                         LOG_LEVEL_VERBOSE)
                return True

        if in_slotindex == 7 and item.sub_type in TWOHANDED_WEAPONS:
            if (self.allow_dual_wield is False
                    and entity_data.equipment[6].type != 0):
                self.log("dual wield bug" +
                        (" weapon (slot6) = {item1}" +
                         " weapon (slot7) = {item2}")
                         .format(item1=entity_data.equipment[6].sub_type,
                                 item2=item.sub_type),
                         LOG_LEVEL_VERBOSE)
                return True

        if (item.type == 3 and
                not item.sub_type in CLASS_WEAPONS[entity_data.class_type]):
            self.log("weapon not allowed for class" +
                     " subtype={subtype} class={classid} item={item}"
                     .format(subtype=item.sub_type,
                             classid=entity_data.class_type,
                             item=get_item_name(item)),
                     LOG_LEVEL_VERBOSE)
            return True

        if (item.type in ARMOR_IDS and
                not item.material in CLASS_ARMOR[entity_data.class_type]):
            self.log("armor not allowed for class " +
                     " material={material} class={classid} item={item}"
                     .format(material=item.material,
                             classid=entity_data.class_type,
                             item=get_item_name(item)),
                     LOG_LEVEL_VERBOSE)
            return True

        return False

    def has_illegal_skills(self):
        entity_data = self.connection.entity_data
        total_skillpoints = 0
        for item in entity_data.skills:
            if item < 0:
                self.log("negative amount of skill points in a skill",
                         LOG_LEVEL_VERBOSE)
                return True

            total_skillpoints = total_skillpoints + item

        if total_skillpoints > (entity_data.level - 1) * 2:
            self.log("spend more skills then are available",
                     LOG_LEVEL_VERBOSE)
            return True

        if entity_data.skills[1] > 0 and entity_data.skills[0] < 5:
            self.log("pet master learned without enough prerequisite points",
                     LOG_LEVEL_VERBOSE)
            return True

        if entity_data.skills[3] > 0 and entity_data.skills[2] < 5:
            self.log("hang gliding learned without enough prerequisite points",
                     LOG_LEVEL_VERBOSE)
            return True

        if entity_data.skills[5] > 0 and entity_data.skills[4] < 5:
            self.log("sailing learned without enough prerequisite points",
                     LOG_LEVEL_VERBOSE)
            return True

        if entity_data.skills[7] > 0 and entity_data.skills[6] < 5:
            self.log("skill 2 learned without enough prerequisite points",
                     LOG_LEVEL_VERBOSE)
            return True

        if entity_data.skills[8] > 0 and entity_data.skills[7] < 5:
            self.log("skill 3 learned without enough prerequisite points",
                     LOG_LEVEL_VERBOSE)
            return True

        return False

    def has_illegal_mode(self):
        entity_data = self.connection.entity_data
        mode = entity_data.current_mode

        if mode == 0:
            return False

        if not mode in ABILITIES:
            self.log("invalid ability or mode: mode={mode}"
                     .format(mode=mode),
                     LOG_LEVEL_VERBOSE)
            return True

        if 'class' in ABILITIES[mode]:
            if not entity_data.class_type in ABILITIES[mode]['class']:
                self.log("ability or mode not allowed for class:" +
                         "mode={mode} class={classid}"
                         .format(mode=mode,
                                 classid=entity_data.class_type),
                         LOG_LEVEL_VERBOSE)
                return True

        if 'spec' in ABILITIES[mode]:
            if entity_data.specialization != ABILITIES[mode]['spec']:
                self.log("ability or mode not allowed for class spec:" +
                         "mode={mode} class={classid} spec={spec}"
                         .format(mode=mode,
                                 classid=entity_data.class_type,
                                 spec=entity_data.specialization),
                         LOG_LEVEL_VERBOSE)
                return True

        if 'weapon' in ABILITIES[mode]:
            weap1 = entity_data.equipment[6].sub_type
            weap2 = entity_data.equipment[7].sub_type

            if entity_data.equipment[6].type == 0:
                weap1 = -1  # Treating unarmed as -1
            if entity_data.equipment[7].type == 0:
                weap2 = -1  # Treating unarmed as -1

            if (not weap1 in ABILITIES[mode]['weapon'] and
                    not weap2 in ABILITIES[mode]['weapon']):
                self.log("ability or mode not allowed for weapon:" +
                         "mode={mode} weapon1={weap1} weapon2={weap2}"
                         .format(mode=mode,
                                 weap1=weap1,
                                 weap2=weap2),
                         LOG_LEVEL_VERBOSE)
                return True

        return False

    def has_illegal_class(self):
        entity_data = self.connection.entity_data

        if not entity_data.class_type in LEGAL_CLASSES:
            self.log("invalid character class {classid}"
                     .format(classid=entity_data.class_type),
                     LOG_LEVEL_VERBOSE)
            return True
        return False

    def has_illegal_level(self):
        entity_data = self.connection.entity_data

        if entity_data.level > self.level_cap:
            return True
        return False

    def has_illegal_multiplier(self):
        entity_data = self.connection.entity_data

        if entity_data.max_hp_multiplier != 100:
            self.log("invalid max hp multiplier mult={mult}"
                     .format(mult=entity_data.max_hp_multiplier),
                     LOG_LEVEL_VERBOSE)
            return True

        if entity_data.shoot_speed != 1:
            self.log("invalid attack speed multiplier mult={mult}"
                     .format(mult=entity_data.shoot_speed),
                     LOG_LEVEL_VERBOSE)
            return True

        if entity_data.damage_multiplier != 1:
            self.log("invalid max damage multiplier mult={mult}"
                     .format(mult=entity_data.damage_multiplier),
                     LOG_LEVEL_VERBOSE)
            return True

        if entity_data.armor_multiplier != 1:
            self.log("invalid max armor multiplier mult={mult}"
                     .format(mult=entity_data.armor_multiplier),
                     LOG_LEVEL_VERBOSE)
            return True

        if entity_data.resi_multiplier != 1:
            self.log("invalid max resi multiplier mult={mult}"
                     .format(mult=entity_data.resi_multiplier),
                     LOG_LEVEL_VERBOSE)
            return True

        return False

    def has_illegal_charged_mp(self):
        entity_data = self.connection.entity_data

        if entity_data.charged_mp > 1:
            self.log("charged mp multiplier above 1, charged_mp={mult}"
                     .format(mult=entity_data.charged_mp),
                     LOG_LEVEL_VERBOSE)
            return True

        if entity_data.charged_mp < 0:
            self.log("charged mp multiplier below 0, charged_mp={mult}"
                     .format(mult=entity_data.charged_mp),
                     LOG_LEVEL_VERBOSE)
            return True


class AntiCheatServer(ServerScript):
    connection_class = AntiCheatConnection
