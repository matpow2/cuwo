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
LOG_MESSAGE = "{playername}({ip}) was removed for: {reason}."
DISCONNECT_MESSAGE = "{name} - You are being removed for: {reason}."
WELCOME_MESSAGE = "{name} - No cheats detected! (yet)"

LOG_LEVEL_VERBOSE = 2
LOG_LEVEL_DEFAULT = 1
LOG_LEVEL_NONE = 0

LOG_LEVEL = LOG_LEVEL_VERBOSE

# Regex name filter, anyone that does not match this will be removed.
# currently all keys normally on a keyboard. cubeworld really isnt picky.
NAME_FILTER = "^[a-zA-Z0-9_!@#$%\^&*()\[\]|:;'.,/\-+ <>\\\"{}~`=?]{2,16}$"
# If we allow the dual wield bug (equiping a 2h and a 1h at the same time)
ALLOW_DUALWIELD_BUG = True
# Max allowed level
# Even players who level up legitly while playing will be removed
LEGAL_LEVEL = 1000
# Highest level rarity level, 4 is gold
LEGAL_RARITY = 4

LEGAL_CLASSES = (1, 2, 3, 4)

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


def generate_pets():
    for pet in LEGAL_PETS:
        LEGAL_ITEMS[(19, pet)] = (0, )
        LEGAL_ITEMS[(20, pet)] = (0, )


# generate pets and petfood in the legal item list based on legal pets
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
    23: (11, ),
    24: (10, ),
})

ARMOR_IDS = (4, 5, 6, 7)

CLASS_WARRIOR = 1
CLASS_RANGER = 2
CLASS_MAGE = 3
CLASS_ROGUE = 4

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

from cuwo.script import (ServerScript,
                         ConnectionScript, command, admin,
                         get_player)
from cuwo.packet import ServerUpdate, PickupAction
import re


class AntiCheatConnection(ConnectionScript):
    def on_join(self):

        if not self.on_name_update():
            return False

        if not self.on_class_update():
            return False

        if not self.on_equipment_update():
            return False

        if not self.on_level_update():
            return False

        if not self.on_skill_update():
            return False

        if not self.on_multiplier_update():
            return False

        self.connection.send_chat(WELCOME_MESSAGE.format(name=CUWO_ANTICHEAT))

        return True

    def on_name_update(self):
        if has_illegal_name(self.connection.entity_data):
            remove_cheater(self.connection, 'illegal character name')
            return False
        return True

    def on_equipment_update(self):
        if has_illegal_items(self.connection.entity_data):
            remove_cheater(self.connection, 'illegal items are equiped')
            return False
        return True

    def on_level_update(self):
        if has_illegal_level(self.connection.entity_data):
            remove_cheater(self.connection, 'illegal character level')
            return False

        return True

    def on_skill_update(self):
        if has_illegal_skills(self.connection.entity_data):
            remove_cheater(self.connection, 'illegal skill distribution')
            return False

        return True

    def on_mode_update(self):
        if has_illegal_mode(self.connection.entity_data):
            remove_cheater(self.connection, 'illegal character mode (ability)')
            return False

        return True

    def on_class_update(self):
        if has_illegal_class(self.connection.entity_data):
            remove_cheater(self.connection, 'illegal character class')
            return False

        return True

    def on_multiplier_update(self):
        if has_illegal_multiplier(self.connection.entity_data):
            remove_cheater(self.connection, 'illegal attribute multiplier')
            return False

        return True

    def on_drop(self, item, pos):
        if is_item_illegal(item):
            pack = ServerUpdate()
            pack.reset()
            action = PickupAction()
            action.entity_id = self.connection.entity_id
            action.item_data = item
            pack.pickups.append(action)

            self.connection.send_packet(pack)

            remove_cheater(self.connection, 'illegal item dropped')
            return False

        return True


class AntiCheatServer(ServerScript):
    connection_class = AntiCheatConnection


def log(message, loglevel=LOG_LEVEL_DEFAULT):
    if LOG_LEVEL >= loglevel:
        print CUWO_ANTICHEAT + " - " + message


def get_class():
    return AntiCheatServer


def calc_power_level(level):
    return int(((1.0 - (1.0 / (((float(level) - 1.0) * 0.05)
                + 1.0))) * 100.0) + 1.0)


def remove_cheater(connection, reason):
    log(LOG_MESSAGE.format(playername=connection.name,
                           ip=connection.address.host,
                           reason=reason))

    connection.send_chat(DISCONNECT_MESSAGE.
                         format(name=CUWO_ANTICHEAT,
                                reason=reason))
    connection.disconnect()


def has_illegal_name(entity_data):
    if re.search(NAME_FILTER, entity_data.name) is None:
        log("character name does not meet requirements: {name}".format(
            name=entity_data.name), LOG_LEVEL_VERBOSE)
        return True

    return False


def has_illegal_items(entity_data):
    for slotindex in range(13):
        if entity_data.equipment[slotindex].type == 0:
            continue

        if is_item_illegal(entity_data.equipment[slotindex]):
            return True

        if is_equiped_illegal(entity_data.equipment[slotindex],
                              entity_data, slotindex):
            return True

    return False


def is_item_illegal(item):
    # Negative item levels... almost as bad as rarity 255
    if item.level < 0:
        log("negative item level: level = {level}"
            .format(level=item.level), LOG_LEVEL_VERBOSE)
        return True

    # Rarity is what makes the items truely broken and overpowered,
    # A rarity of 255 will make even a lvl 1 weapon do 2 billion damage.
    if item.rarity > LEGAL_RARITY:
        log("item rarity: {rarity}".format(
            rarity=item.rarity), LOG_LEVEL_VERBOSE)
        return True

    # Item type 2 is a recipe they are handled differently.
    # minus modifier is the item type of the crafted item
    if item.type == 2:
        if not item.minus_modifier in LEGAL_RECIPE_ITEMS:
            log("invalid recipe:type={type} subtype={subtype} material={mat}"
                .format(type=item.minus_modifier,
                        subtype=item.sub_type,
                        mat=item.material), LOG_LEVEL_VERBOSE)
            return True

        if not (item.material in
                LEGAL_ITEMS[(item.minus_modifier, item.sub_type)]):
            log("invalid recipe:type={type} subtype={subtype} material={mat}"
                .format(type=item.minus_modifier,
                        subtype=item.sub_type,
                        mat=item.material), LOG_LEVEL_VERBOSE)
            return True

        return False

    if not (item.type, item.sub_type) in LEGAL_ITEMS:
        log("invalid item:type={type} subtype={subtype} material={material}"
            .format(type=item.type,
                    subtype=item.sub_type,
                    material=item.material), LOG_LEVEL_VERBOSE)
        return True

    if not item.material in LEGAL_ITEMS[(item.type, item.sub_type)]:
        log("invalid material:type={type} subtype={subtype} material={mat}"
            .format(type=item.type,
                    subtype=item.sub_type,
                    mat=item.material), LOG_LEVEL_VERBOSE)
        return True

    return False


def is_equiped_illegal(item, entity_data, in_slotindex):

    power_item = calc_power_level(item.level)
    power_char = calc_power_level(entity_data.character_level)
    if power_item > power_char:
        log("item level too high for character " +
            "item: lv{level1}=pw{power1} character: lv{level2}=pw{power2}"
            .format(level1=item.level,
                    power1=power_item,
                    level2=entity_data.character_level,
                    power2=power_char), LOG_LEVEL_VERBOSE)
        return True

    if not item.type in LEGAL_ITEMSLOTS:
        log("non equipable item slot:type={type} subtype={subtype} slot={slot}"
            .format(type=item.type,
                    subtype=item.sub_type,
                    slot=in_slotindex), LOG_LEVEL_VERBOSE)
        return True

    if not in_slotindex in LEGAL_ITEMSLOTS[item.type]:
        log("item in invalid slot:type={type} subtype={subtype} slot={slot}"
            .format(type=item.type,
                    subtype=item.sub_type,
                    slot=in_slotindex), LOG_LEVEL_VERBOSE)
        return True

    if in_slotindex == 6 and item.type in TWOHANDED_WEAPONS:

        if ALLOW_DUALWIELD_BUG is False and entity_data.equipment[7].type != 0:
            log("Dual wield bug active", LOG_LEVEL_VERBOSE)
            return True

        if entity_data.equipment[7].sub_type in TWOHANDED_WEAPONS:
            log("Wielding 2 twohanders", LOG_LEVEL_VERBOSE)
            return True

    if in_slotindex == 7 and item.type in TWOHANDED_WEAPONS:

        if ALLOW_DUALWIELD_BUG is False and entity_data.equipment[6].type != 0:
            log("Dual wield bug active", LOG_LEVEL_VERBOSE)
            return True

        if entity_data.equipment[6].sub_type in TWOHANDED_WEAPONS:
            log("Wielding 2 twohanders", LOG_LEVEL_VERBOSE)
            return True

    if (item.type == 3 and
            not item.sub_type in CLASS_WEAPONS[entity_data.class_type]):
        log("weapon not allowed for class subtype={subtype} class={classid}"
            .format(subtype=item.sub_type,
                    classid=entity_data.class_type), LOG_LEVEL_VERBOSE)
        return True

    if (item.type in ARMOR_IDS and
            not item.material in CLASS_ARMOR[entity_data.class_type]):
        log("armor not allowed for class material={material} class={classid}"
            .format(material=item.material,
                    classid=entity_data.class_type), LOG_LEVEL_VERBOSE)
        return True

    return False


def has_illegal_skills(entity_data):
    total_skillpoints = 0
    for item in entity_data.skills:
        if item < 0:
            log("negative amount of skill points in a skill",
                LOG_LEVEL_VERBOSE)
            return True

        total_skillpoints = total_skillpoints + item

    if total_skillpoints > (entity_data.character_level - 1) * 2:
        log("spend more skills then are available",
            LOG_LEVEL_VERBOSE)
        return True

    if entity_data.skills[1] > 0 and entity_data.skills[0] < 5:
        log("pet master learned without enough prerequisite points",
            LOG_LEVEL_VERBOSE)
        return True

    if entity_data.skills[3] > 0 and entity_data.skills[2] < 5:
        log("hang gliding learned without enough prerequisite points",
            LOG_LEVEL_VERBOSE)
        return True

    if entity_data.skills[5] > 0 and entity_data.skills[4] < 5:
        log("sailing learned without enough prerequisite points",
            LOG_LEVEL_VERBOSE)
        return True

    if entity_data.skills[7] > 0 and entity_data.skills[6] < 5:
        log("skill 2 learned without enough prerequisite points",
            LOG_LEVEL_VERBOSE)
        return True

    if entity_data.skills[8] > 0 and entity_data.skills[7] < 5:
        log("skill 3 learned without enough prerequisite points",
            LOG_LEVEL_VERBOSE)
        return True

    return False


def has_illegal_mode(entity_data):

    mode = entity_data.current_mode

    if mode == 0:
        return False

    if not mode in ABILITIES:
        log("invalid ability or mode: mode={mode}"
            .format(mode=mode),
            LOG_LEVEL_VERBOSE)
        return True

    if 'class' in ABILITIES[mode]:
        if not entity_data.class_type in ABILITIES[mode]['class']:
            log("ability or mode not allowed for class:" +
                "mode={mode} class={classid}"
                .format(mode=mode,
                        classid=entity_data.class_type),
                LOG_LEVEL_VERBOSE)
            return True

    if 'spec' in ABILITIES[mode]:
        if entity_data.specialization != ABILITIES[mode]['spec']:
            log("ability or mode not allowed for class spec:" +
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
            log("ability or mode not allowed for weapon:" +
                "mode={mode} weapon1={weap1} weapon2={weap2}"
                .format(mode=mode,
                        weap1=weap1,
                        weap2=weap2),
                LOG_LEVEL_VERBOSE)
            return True

    return False


def has_illegal_class(entity_data):
    if not entity_data.class_type in LEGAL_CLASSES:
        log("invalid character class {classid}"
            .format(classid=entity_data.class_type),
            LOG_LEVEL_VERBOSE)
        return True
    return False


def has_illegal_level(entity_data):
    return entity_data.character_level > LEGAL_LEVEL


def has_illegal_multiplier(entity_data):
    if entity_data.max_hp_multiplier != 100:
        log("invalid max hp multiplier for mult={mult}"
            .format(mult=entity_data.max_hp_multiplier),
            LOG_LEVEL_VERBOSE)
        return True

    if entity_data.shoot_speed != 1:
        log("invalid attack speed multiplier for mult={mult}"
            .format(mult=entity_data.shoot_speed),
            LOG_LEVEL_VERBOSE)
        return True

    if entity_data.damage_multiplier != 1:
        log("invalid max damage multiplier for mult={mult}"
            .format(mult=entity_data.damage_multiplier),
            LOG_LEVEL_VERBOSE)
        return True

    if entity_data.armor_multiplier != 1:
        log("invalid max armor multiplier for mult={mult}"
            .format(mult=entity_data.armor_multiplier),
            LOG_LEVEL_VERBOSE)
        return True

    if entity_data.resi_multiplier != 1:
        log("invalid max resi multiplier for mult={mult}"
            .format(mult=entity_data.resi_multiplier),
            LOG_LEVEL_VERBOSE)
        return True

    return False
