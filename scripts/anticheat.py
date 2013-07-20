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

# If we allow the dual wield bug (equiping a 2h and a 1h at the same time)
ALLOW_DUALWIELD_BUG = True
# Max allowed level
# Even players who level up legitly while playing will be removed
LEGAL_LEVEL = 1000
# Highest level rarity level, 4 is gold
LEGAL_RARITY = 4

TWOHANDED_WEAPONS = (5, 6, 7, 10, 11, 15, 16, 17)

LEGAL_ITEMS = dict({
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
    (23, 0): (2, ),    # wood hanglider
    (23, 1): (2, ),    # wood boat
    (24, 0): (1, ),    # lamp, iron

    # pets
    (19, 19): (0, ),
    (19, 22): (0, ),
    (19, 23): (0, ),
    (19, 25): (0,),
    (19, 26): (0, ),
    (19, 27): (0, ),
    (19, 33): (0, ),
    (19, 34): (0, ),
    (19, 35): (0, ),
    (19, 36): (0, ),
    (19, 37): (0, ),
    (19, 38): (0, ),
    (19, 39): (0, ),
    (19, 40): (0, ),
    (19, 40): (0, ),
    (19, 50): (0, ),
    (19, 53): (0, ),
    (19, 55): (0, ),
    (19, 56): (0, ),
    (19, 57): (0, ),
    (19, 58): (0, ),
    (19, 59): (0, ),
    (19, 60): (0, ),
    (19, 61): (0, ),
    (19, 62): (0, ),
    (19, 63): (0, ),
    (19, 64): (0, ),
    (19, 65): (0, ),
    (19, 66): (0, ),
    (19, 67): (0, ),
    (19, 74): (0, ),
    (19, 75): (0, ),
    (19, 86): (0, ),
    (19, 87): (0, ),
    (19, 88): (0, ),
    (19, 90): (0, ),
    (19, 91): (0, ),
    (19, 92): (0, ),
    (19, 93): (0, ),
    (19, 98): (0, ),
    (19, 99): (0, ),
    (19, 102): (0, ),
    (19, 103): (0, ),
    (19, 104): (0, ),
    (19, 105): (0, ),
    (19, 106): (0, ),
    (19, 151): (0, ),
    })

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

from cuwo.script import (ServerScript,
                         ConnectionScript, command, admin,
                         get_player)


class AntiCheatConnection(ConnectionScript):
    def on_join(self):
        if not self.on_equipment_update():
            return False

        if not self.on_level_update():
            return False

        if not self.on_skill_update():
            return False

        self.connection.send_chat(WELCOME_MESSAGE.format(name=CUWO_ANTICHEAT))

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


class AntiCheatServer(ServerScript):
    connection_class = AntiCheatConnection


def log(message, loglevel=LOG_LEVEL_DEFAULT):
    print CUWO_ANTICHEAT + " - " + message


def get_class():
    return AntiCheatServer


def calc_power_level(level):
    return 0


def remove_cheater(connection, reason):
    log(LOG_MESSAGE.format(playername=connection.name,
                           ip=connection.address.host,
                           reason=reason))

    connection.send_chat(DISCONNECT_MESSAGE.
                         format(name=CUWO_ANTICHEAT,
                                reason=reason))
    connection.disconnect()


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
    # Rarity is what makes the items truely broken and overpowered,
    # A rarity of 255 will make even a lvl 1 weapon do 2 billion damage.
    if item.rarity > LEGAL_RARITY:
        log("item rarity: {rarity}".format(
            rarity=item.rarity), LOG_LEVEL_VERBOSE)
        return True

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

    if calc_power_level(item.level) > calc_power_level(entity_data.level):
        log("item level too high for character", LOG_LEVEL_VERBOSE)
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

    return False


def has_illegal_skills(entity_data):
    total_skillpoints = 0
    for item in entity_data.skills:
        if item < 0:
            log("negative amount of skill points in a skill",
                LOG_LEVEL_VERBOSE)
            return True

        total_skillpoints = total_skillpoints + item

    if total_skillpoints > (entity_data.level - 1) * 2:
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
        log("skill 2 without enough prerequisite points",
            LOG_LEVEL_VERBOSE)
        return True

    if entity_data.skills[8] > 0 and entity_data.skills[7] < 5:
        log("skill 3 without enough prerequisite points",
            LOG_LEVEL_VERBOSE)
        return True

    return False


def has_illegal_level(entity_data):
    return entity_data.level > LEGAL_LEVEL
