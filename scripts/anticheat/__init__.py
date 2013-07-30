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

from cuwo.constants import (WARRIOR_CLASS, RANGER_CLASS,
                            MAGE_CLASS, ROGUE_CLASS)
from cuwo.script import (ServerScript,
                         ConnectionScript, command, admin,
                         get_player)
from cuwo.common import get_power, get_item_name, is_bit_set
from cuwo.packet import ServerUpdate, PickupAction
from constants import *
import re
import time


class AntiCheatConnection(ConnectionScript):

    combat_end_time = 0
    last_glider_active = 0
    last_attacking = 0

    glider_count = 0
    attack_count = 0

    ability_cooldown = {}

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
        self.glider_abuse_count = config.glider_abuse_count
        self.cooldown_margin = config.cooldown_margin

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

        if self.on_consumable_update() is False:
            return False

        if self.on_flags_update() is False:
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

    def on_consumable_update(self, event=None):
        if self.has_illegal_consumable():
            self.remove_cheater('illegal consumable equiped')
            return False

    def on_flags_update(self, event=None):
        if self.has_illegal_flags():
            self.remove_cheater('illegal character flags')
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
        if loglevel >= self.log_level:
            print CUWO_ANTICHEAT + " - " + message
        if loglevel >= self.irc_log_level:
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
                self.server.config.anticheat.irc_log_level = 0

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

        if item.type == 1 and item.rarity > 0:
            self.log(("consumable with rarity above 0, item={item}" +
                     " item rarity: {rarity}")
                     .format(item=get_item_name(item),
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

        power_item = get_power(item.level)
        power_char = get_power(entity_data.level)
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

    def has_illegal_consumable(self):
        entity_data = self.connection.entity_data
        item = entity_data.consumable

        # no consumable equiped
        if item.type == 0:
            return False

        if self.is_item_illegal(item):
            return True

        power_item = get_power(item.level)
        power_char = get_power(entity_data.level)
        if power_item > power_char:
            self.log(("consumable level too high for character " +
                     "item: level:{level1} (power: {power1}) " +
                     "character: level:{level2} (power: {power2})")
                     .format(level1=item.level,
                             power1=power_item,
                             level2=entity_data.level,
                             power2=power_char), LOG_LEVEL_VERBOSE)
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

        return False

    def has_illegal_flags(self):
        entity_data = self.connection.entity_data
        # This is when holding control, doesnt need to be on a wall
        FLAGS_1_CLIMBING = 0
        FLAGS_1_ATTACKING = 2
        FLAGS_1_GLIDER_ACTIVE = 4

        FLAGS_2_LANTERN_ON = 1
        FLAGS_2_RANGER_STEALTH = 2

        flags_1 = entity_data.flags_1
        flags_2 = entity_data.flags_2

        if (is_bit_set(flags_2, FLAGS_2_RANGER_STEALTH) and
                entity_data.class_type != RANGER_CLASS):
            self.log("none ranger class using ranger stealth. class={classid}"
                     .format(classid=entity_data.class_type),
                     LOG_LEVEL_VERBOSE)
            return True

        # Glider resetting attack animations bug
        # Rapidly switching between will be seen as bug abusing.
        if is_bit_set(flags_1, FLAGS_1_ATTACKING):
            self.last_attacking = time.time()
            self.attack_count += 1

        if is_bit_set(flags_1, FLAGS_1_GLIDER_ACTIVE):
            self.last_glider_active = time.time()
            self.glider_count += 1

        # Reset if either attacking or gliding has not happend for a time
        if (time.time() - self.last_glider_active > 0.75 or
                time.time() - self.last_attacking > 0.75):
            self.glider_count = 0
            self.attack_count = 0

        if (self.glider_count > self.glider_abuse_count and
                self.attack_count > self.glider_abuse_count):
            self.log("glider reset attack animation bug abuse."
                     .format(classid=entity_data.class_type),
                     LOG_LEVEL_VERBOSE)
            return True

        return False


class AntiCheatServer(ServerScript):
    connection_class = AntiCheatConnection


def get_class():
    return AntiCheatServer
