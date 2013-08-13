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
from cuwo.common import (get_power, get_item_name, is_bit_set,
                         get_entity_max_health)
from cuwo.packet import ServerUpdate, PickupAction
from constants import *
from twisted.internet import reactor

import re
import math


def is_similar(float1, float2):
    return float1 > float2 - 0.1 and float1 < float2 + 0.1


class AntiCheatConnection(ConnectionScript):

    def on_load(self):
        self.combat_end_time = 0
        self.last_glider_active = 0
        self.last_attacking = 0

        self.glider_count = 0
        self.attack_count = 0

        self.time_since_update = 0
        self.last_entity_update = 0
        self.last_update_mode = 0

        self.max_health = 0
        self.last_mana = 0
        self.last_health = 0

        self.mana = 0
        self.health = 0

        self.air_time = 0
        self.hit_distance_strikes = 0
        self.is_dead = False

        self.last_pos = None
        self.last_speed_check = 0
        self.time_traveled = 0
        self.distance_traveled = 0

        self.cooldown_strikes = 0
        self.ability_cooldown = {}
        self.last_entity_update = reactor.seconds()

        self.last_hit_time = 0
        self.last_hit_strikes = 0
        self.last_hit_check = 0
        self.hit_counter = 0
        self.hit_counter_strikes = 0
        self.max_hp_strikes = 0

        # allow for extra catch ups during join
        self.last_hit_time_catchup = reactor.seconds() + 10
        self.last_hit_time_catchup_count = -10

        config = self.server.config.anticheat
        self.level_cap = config.level_cap
        self.allow_dual_wield = config.allow_dual_wield
        self.rarity_cap = config.rarity_cap
        self.name_filter = config.name_filter
        self.log_level = config.log_level
        self.log_message = config.log_message
        self.disconnect_message = config.disconnect_message
        self.irc_log_level = config.irc_log_level
        self.glider_abuse_count = config.glider_abuse_count
        self.cooldown_margin = config.cooldown_margin
        self.max_hit_distance = config.max_hit_distance ** 2
        self.max_hit_distance_strikes = config.max_hit_distance_strikes
        self.max_cooldown_strikes = config.max_cooldown_strikes
        self.max_air_time = config.max_air_time
        self.speed_margin = config.speed_margin
        self.last_hit_margin = config.last_hit_margin
        self.max_last_hit_strikes = config.max_last_hit_strikes
        self.max_hit_counter_strikes = config.max_hit_counter_strikes
        self.max_hit_counter_difference = config.max_hit_counter_difference
        self.max_max_hp_strikes = config.max_max_hp_strikes
        self.max_last_hit_time_catchup = config.max_last_hit_time_catchup

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

        if self.on_flags_update() is False:
            return False

        if self.on_appearance_update() is False:
            return False

        if self.check_hostile_type() is False:
            return False

        self.update_max_health()
        if self.check_max_health(True) is False:
            return False

    def update_max_health(self):
        entity_data = self.connection.entity_data
        self.max_health = get_entity_max_health(entity_data)

    def check_max_health(self, no_strikes=False):
        entity_data = self.connection.entity_data
        if entity_data.hp > self.max_health + 1:
            self.max_hp_strikes += 1

            if no_strikes or self.max_hp_strikes > self.max_max_hp_strikes:
                self.log("character hp higher than max hp: {hp}/{max}"
                         .format(hp=entity_data.hp,
                                 max=self.max_health), LOG_LEVEL_VERBOSE)
                self.remove_cheater('health hack')
                return False
        else:
            self.max_hp_strikes = 0

    def on_name_update(self, event=None):
        if self.has_illegal_name():
            self.remove_cheater('illegal character name')
            return False

    def on_equipment_update(self, event=None):
        if self.has_illegal_items():
            self.remove_cheater('illegal items are equipped')
            return False

        self.update_max_health()

    def on_level_update(self, event=None):
        if self.has_illegal_level():
            self.remove_cheater('illegal character level, max:' +
                                str(self.level_cap))
            return False

        self.update_max_health()

    def on_skill_update(self, event=None):
        if self.has_illegal_skills():
            self.remove_cheater('illegal skill distribution')
            return False

    def on_mode_update(self, event=None):
        entity_data = self.connection.entity_data

        if (entity_data.current_mode == 0
                and self.combat_end_time == 0):
            self.combat_end_time = reactor.seconds()

        if entity_data.current_mode != 0:
            self.combat_end_time = 0

        if self.has_illegal_mode():
            self.remove_cheater('illegal character mode (ability)')
            return False

        if entity_data.current_mode != 0:
            if self.use_ability(entity_data.current_mode) is False:
                self.remove_cheater('cooldown hack')
                return True

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

    def on_appearance_update(self, event=None):
        if self.has_illegal_appearance():
            self.remove_cheater('illegal character appearance')
            return False

    def on_entity_update(self, event):
        entity_data = self.connection.entity_data
        self.time_since_update = reactor.seconds() - self.last_entity_update
        self.last_entity_update = reactor.seconds()

        self.last_mana = self.mana
        self.last_health = self.health

        self.mana = entity_data.mp
        self.health = entity_data.hp
        
        if is_bit_set(event.mask, 7):
            if self.check_hostile_type() is False:
                return False

        if is_bit_set(event.mask, 27):
            if self.check_max_health() is False:
                return False

        if reactor.seconds() - self.last_hit_check > 1.0:
            self.last_hit_check = reactor.seconds()
            if self.check_last_hit() is False:
                return False

#        if self.check_speed() is False:
#            return False

        if self.check_flying() is False:
            return False

        if not self.is_dead and self.health <= 0:
            self.is_dead = True
            self.on_death()

        if self.health > 0 and self.is_dead:
            self.is_dead = False

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

    def on_hit(self, event):
        packet = event.packet
        if packet.entity_id != self.connection.entity_id:
            # These packets are often send on join, apparently the client
            # saves his old hitpackets and sends it as soon as it connects..
            # possibly just a bug where wollay doesnt clear a list.
            return False

        # just damage packets, not healing would be negative
        if event.packet.damage >= 0:
            self.last_hit_time = reactor.seconds()
            self.hit_counter += 1

        # how far away did this hit hit from where the target actually is
        hitdistance = (packet.pos - event.target.pos).magnitude_squared()
        if hitdistance > self.max_hit_distance:
            self.hit_distance_strikes += 1
            if self.hit_distance_strikes > self.max_hit_distance_strikes:
                self.remove_cheater('hit distance too far, ' +
                                    'either cheating or lagging too much')
        else:
            self.hit_distance_strikes = 0

    def on_death(self, event=None):
        # if i get killed reset cooldowns! (this actually happens on respawn,
        # but there is no way to determine respawning as of yet)
        self.ability_cooldown = {}
        # give one catchup count back as they will probably get one from
        # respawning :d
        self.last_hit_time_catchup = reactor.seconds()
        self.last_hit_time_catchup_count = -1

    def log(self, message, loglevel=LOG_LEVEL_DEFAULT):
        if self.log_level >= loglevel:
            print CUWO_ANTICHEAT + " - " + message
        if self.irc_log_level >= loglevel:
            try:
                self.server.scripts.irc.send(CUWO_ANTICHEAT + " - " + message)
            except KeyError:
                self.disable_irc_logging()
            except AttributeError:
                self.disable_irc_logging()

    def disable_irc_logging(self):
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

        ability = ABILITIES[mode]

        if 'class' in ability:
            if not entity_data.class_type in ability['class']:
                self.log("ability or mode not allowed for class:" +
                         "mode={mode} class={classid}"
                         .format(mode=mode,
                                 classid=entity_data.class_type),
                         LOG_LEVEL_VERBOSE)
                return True

        if 'spec' in ability:
            if entity_data.specialization != ability['spec']:
                self.log("ability or mode not allowed for class spec:" +
                         "mode={mode} class={classid} spec={spec}"
                         .format(mode=mode,
                                 classid=entity_data.class_type,
                                 spec=entity_data.specialization),
                         LOG_LEVEL_VERBOSE)
                return True

        if 'weapon' in ability:
            weap1 = entity_data.equipment[6].sub_type
            weap2 = entity_data.equipment[7].sub_type

            if entity_data.equipment[6].type == 0:
                weap1 = -1  # Treating unarmed as -1
            if entity_data.equipment[7].type == 0:
                weap2 = -1  # Treating unarmed as -1

            if (not weap1 in ability['weapon'] and
                    not weap2 in ability['weapon']):
                self.log("ability or mode not allowed for weapon:" +
                         "mode={mode} weapon1={weap1} weapon2={weap2}"
                         .format(mode=mode,
                                 weap1=weap1,
                                 weap2=weap2),
                         LOG_LEVEL_VERBOSE)
                return True

        return False

    def use_ability(self, mode):
        ability = ABILITIES[mode]
        if 'cooldown' in ability:
            min_cd = ability['cooldown']
            last_used = 0

            if mode in self.ability_cooldown:
                last_used = self.ability_cooldown[mode]

            current_cd = reactor.seconds() - last_used
            if current_cd < min_cd - self.cooldown_margin:
                self.cooldown_strikes += 1
                if self.cooldown_strikes > self.max_cooldown_strikes:
                    self.log(("ability used before cooldown was ready. " +
                             "mode={mode}, min. cooldown={mincd}s, " +
                             "current cooldown={currentcd}s")
                             .format(mode=mode,
                                     mincd=min_cd,
                                     currentcd=current_cd),
                             LOG_LEVEL_VERBOSE)
                    return False
            else:
                self.cooldown_strikes = 0

            # keep track of ability usage
            self.ability_cooldown[mode] = reactor.seconds()

        return True

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

        if entity_data.class_type == 1:
            # -1 check for warriors because they have a bug that can make them
            # go negative while blocking
            if entity_data.charged_mp < -2:
                self.log("charged mp multiplier below 2, charged_mp={mult}"
                         .format(mult=entity_data.charged_mp),
                         LOG_LEVEL_VERBOSE)
                return True
        else:
            if entity_data.charged_mp < 0:
                self.log("charged mp multiplier below 0, charged_mp={mult}"
                         .format(mult=entity_data.charged_mp),
                         LOG_LEVEL_VERBOSE)
                return True

        return False

    def has_illegal_appearance(self):
        entity_data = self.connection.entity_data
        appearance = entity_data.appearance

        if appearance.movement_flags != 0:
            self.log("invalid appearance flags, movement_flags={flags}"
                     .format(flags=appearance.movement_flags),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.entity_flags != 0:
            self.log("invalid appearance flags, entity_flags={flags}"
                     .format(flags=appearance.entity_flags),
                     LOG_LEVEL_VERBOSE)
            return True

        if not entity_data.entity_type in APPEARANCES:
            self.log("invalid entity_type (race), entity_type={entity_type}"
                     .format(entity_type=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        app = APPEARANCES[entity_data.entity_type]
        if not is_similar(appearance.scale, app['scale']):
            self.log("invalid appearance, scale={field} entity_type={t}"
                     .format(field=appearance.scale,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not is_similar(appearance.bounding_radius, app['radius']):
            self.log("invalid appearance, radius={field} entity_type={t}"
                     .format(field=appearance.bounding_radius,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not is_similar(appearance.bounding_height, app['height']):
            self.log("invalid appearance, height={field} entity_type={t}"
                     .format(field=appearance.bounding_height,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not appearance.head_model in app['model_head']:
            self.log("invalid appearance, head model={field} entity_type={t}"
                     .format(field=appearance.head_model,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not appearance.hair_model in app['model_hair']:
            self.log("invalid appearance, hair model={field} entity_type={t}"
                     .format(field=appearance.hair_model,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not appearance.hand_model in app['model_hand']:
            self.log("invalid appearance, hand model={field} entity_type={t}"
                     .format(field=appearance.hand_model,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not appearance.foot_model in app['model_feet']:
            self.log("invalid appearance, foot model={field} entity_type={t}"
                     .format(field=appearance.foot_model,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not appearance.body_model in app['model_body']:
            self.log("invalid appearance, body model={field} entity_type={t}"
                     .format(field=appearance.body_model,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not appearance.back_model in app['model_back']:
            self.log("invalid appearance, back model={field} entity_type={t}"
                     .format(field=appearance.back_model,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not appearance.shoulder_model in app['model_shoulder']:
            self.log("invalid appearance, shoulder model={f} entity_type={t}"
                     .format(f=appearance.shoulder_model,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not appearance.wing_model in app['model_wing']:
            self.log("invalid appearance, wing model={field} entity_type={t}"
                     .format(field=appearance.wing_model,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not is_similar(appearance.head_scale, app['scale_head']):
            self.log("invalid appearance, head scale={field} entity_type={t}"
                     .format(field=appearance.head_scale,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not is_similar(appearance.hand_scale, app['scale_hand']):
            self.log("invalid appearance, hand scale={field} entity_type={t}"
                     .format(field=appearance.hand_scale,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not is_similar(appearance.body_scale, app['scale_body']):
            self.log("invalid appearance, body scale={field} entity_type={t}"
                     .format(field=appearance.body_scale,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not is_similar(appearance.foot_scale, app['scale_feet']):
            self.log("invalid appearance, foot scale={field} entity_type={t}"
                     .format(field=appearance.foot_scale,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not is_similar(appearance.shoulder_scale, app['scale_shoulder']):
            self.log("invalid appearance, shoulder scale={f} entity_type={t}"
                     .format(f=appearance.shoulder_scale,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not is_similar(appearance.weapon_scale, app['scale_weapon']):
            self.log("invalid appearance, weapon scale={field} entity_type={t}"
                     .format(field=appearance.weapon_scale,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not is_similar(appearance.back_scale, app['scale_back']):
            self.log("invalid appearance, back scale={field} entity_type={t}"
                     .format(field=appearance.back_scale,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not is_similar(appearance.wing_scale, app['scale_wing']):
            self.log("invalid appearance, wing scale={field} entity_type={t}"
                     .format(field=appearance.wing_scale,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if not is_similar(appearance.unknown, app['scale_unknown']):
            self.log("invalid appearance, unknown scale={f} entity_type={t}"
                     .format(f=appearance.unknown,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.body_pitch != 0:
            self.log("invalid appearance, body_pitch={field} entity_type={t}"
                     .format(field=appearance.body_pitch,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.arm_pitch != 0:
            self.log("invalid appearance, arm_pitch={field} entity_type={t}"
                     .format(field=appearance.arm_pitch,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.arm_roll != 0:
            self.log("invalid appearance, arm_roll={field} entity_type={t}"
                     .format(field=appearance.arm_roll,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.arm_yaw != 0:
            self.log("invalid appearance, arm_yaw={field} entity_type={t}"
                     .format(field=appearance.arm_yaw,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.feet_pitch != 0:
            self.log("invalid appearance, feet_pitch={field} entity_type={t}"
                     .format(field=appearance.feet_pitch,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.wing_pitch != 0:
            self.log("invalid appearance, wing_pitch={field} entity_type={t}"
                     .format(field=appearance.wing_pitch,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.back_pitch != 0:
            self.log("invalid appearance, back_pitch={field} entity_type={t}"
                     .format(field=appearance.back_pitch,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.body_offset != app['offset_body']:
            self.log("invalid appearance, body offset={field} entity_type={t}"
                     .format(field=appearance.body_offset,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.head_offset != app['offset_head']:
            self.log("invalid appearance, head offset={field} entity_type={t}"
                     .format(field=appearance.head_offset,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.hand_offset != app['offset_hand']:
            self.log("invalid appearance, hand offset={field} entity_type={t}"
                     .format(field=appearance.hand_offset,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.foot_offset != app['offset_foot']:
            self.log("invalid appearance, foot offset={field} entity_type={t}"
                     .format(field=appearance.foot_offset,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.back_offset != app['offset_back']:
            self.log("invalid appearance, back offset={field} entity_type={t}"
                     .format(field=appearance.back_offset,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

        if appearance.wing_offset != app['offset_wing']:
            self.log("invalid appearance, wing offset={field} entity_type={t}"
                     .format(field=appearance.wing_offset,
                             t=entity_data.entity_type),
                     LOG_LEVEL_VERBOSE)
            return True

    def has_illegal_flags(self):
        entity_data = self.connection.entity_data
        # This is when holding control, doesnt need to be on a wall

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
            self.last_attacking = reactor.seconds()
            self.attack_count += 1

        if is_bit_set(flags_1, FLAGS_1_GLIDER_ACTIVE):
            self.last_glider_active = reactor.seconds()
            self.glider_count += 1

        # Reset if either attacking or gliding has not happend for a time
        if (reactor.seconds() - self.last_glider_active > 0.75 or
                reactor.seconds() - self.last_attacking > 0.75):
            self.glider_count = 0
            self.attack_count = 0

        if (self.glider_count > self.glider_abuse_count and
                self.attack_count > self.glider_abuse_count):
            self.log("glider reset attack animation bug abuse."
                     .format(classid=entity_data.class_type),
                     LOG_LEVEL_VERBOSE)
            return True

        return False

    def check_flying(self):
        entity_data = self.connection.entity_data
        flags_1 = entity_data.flags_1
        # in the air when, not gliding, not "on ground", not swimming, not
        # climbing
        if not (is_bit_set(flags_1, FLAGS_1_GLIDER_ACTIVE)
                or is_bit_set(entity_data.physics_flags, 0)
                or is_bit_set(entity_data.physics_flags, 1)
                or is_bit_set(entity_data.physics_flags, 2)
                or entity_data.hp <= 0):
            self.air_time += self.time_since_update

            if self.air_time > self.max_air_time:
                self.remove_cheater('flying hack')
                return False
        else:
            self.air_time = 0

    def check_speed(self):
        entity_data = self.connection.entity_data

        if not self.last_pos is None:
            mx = (entity_data.pos.x-self.last_pos.x) ** 2
            my = (entity_data.pos.y-self.last_pos.y) ** 2
            self.distance_traveled += math.sqrt(mx + my)
        self.last_pos = entity_data.pos
        self.time_traveled += self.time_since_update
        if self.time_traveled > 0.5:
            speed = self.distance_traveled / self.time_traveled
            #print "Traveling at", speed
            self.time_traveled = 0
            self.distance_traveled = 0

    def check_hit_counter(self):
        entity_data = self.connection.entity_data

        if entity_data.hit_counter < 0:
            self.log("negative hit counter. hits={hits}"
                     .format(hits=entity_data.hit_counter),
                     LOG_LEVEL_VERBOSE)
            self.remove_cheater('illegal hit counter')
            return False

        if reactor.seconds() - self.last_hit_time > 4 + self.last_hit_margin:
            self.hit_counter = 0

        hit_counter_diff = entity_data.hit_counter - self.hit_counter
        if hit_counter_diff > self.max_hit_counter_difference:
            self.hit_counter_strikes += 1
            if self.hit_counter_strikes > self.max_hit_counter_strikes:
                self.log("hit counter mismatch, hits={hits}, expected={exp}"
                         .format(hits=entity_data.hit_counter,
                                 exp=self.hit_counter),
                         LOG_LEVEL_VERBOSE)
                self.remove_cheater('illegal hit counter')
                return False
        else:
            self.hit_counter_strikes = 0

    def check_hostile_type(self):
        entity_data = self.connection.entity_data
        if entity_data.hostile_type != 0:
            self.log("invalid hostile_type={t}"
                     .format(t=entity_data.hostile_type),
                     LOG_LEVEL_VERBOSE)
            self.remove_cheater('illegal hostile type')
            return False

    def check_last_hit(self):
        entity_data = self.connection.entity_data
        if entity_data.hp <= 0:
            return

        last_hit_rc = (float(entity_data.last_hit_time) / 1000.0)
        if self.last_hit_time == 0:
            self.last_hit_time = reactor.seconds() - last_hit_rc
        last_hit_pk = reactor.seconds() - self.last_hit_time

        time_diff = last_hit_pk - last_hit_rc
        if abs(time_diff) > self.last_hit_margin:
            self.last_hit_strikes += 1
            if self.last_hit_strikes > self.max_last_hit_strikes:
                self.log("last hit time mismatch, time={t}, expected={exp}"
                         .format(t=last_hit_rc,
                                 exp=last_hit_pk),
                         LOG_LEVEL_VERBOSE)
                self.remove_cheater('last hit time mismatch')
                return False

            # catch up time, this is only allowed twice every 15 seconds
            # it will make sure that a freeze or lagspike will be allowed
            # to catch up to (otherwise this would result in a kick)
            if (reactor.seconds() - self.last_hit_time_catchup > 15.0):
                self.last_hit_time_catchup = reactor.seconds()
                self.last_hit_time_catchup_count = 0

            if (self.last_hit_time_catchup_count <
                    self.max_last_hit_time_catchup):
                self.last_hit_time_catchup_count += 1
                self.last_hit_strikes -= 1
                self.last_hit_time = reactor.seconds() - last_hit_rc
        else:
            self.last_hit_strikes = 0

        return self.check_hit_counter()


class AntiCheatServer(ServerScript):
    connection_class = AntiCheatConnection


def get_class():
    return AntiCheatServer
