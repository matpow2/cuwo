# Copyright (c) Mathias Kaerlev, Somer Hayter, sarcengm and Jakky89 2013.
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

#from cuwo.twistedreactor import install_reactor
#install_reactor()
from twisted.internet import epollreactor
epollreactor.install()
from twisted.internet.protocol import Factory, Protocol
from twisted.internet import reactor
from twisted.internet.task import LoopingCall

from cuwo.packet import (PacketHandler, write_packet, CS_PACKETS,
                         ClientVersion, JoinPacket, SeedData, EntityUpdate,
                         ClientChatMessage, ServerChatMessage,
                         create_entity_data, UpdateFinished, CurrentTime,
                         ServerUpdate, ServerFull, ServerMismatch,
                         INTERACT_DROP, INTERACT_PICKUP, ChunkItemData,
                         ChunkItems, InteractPacket, PickupAction,
                         HitPacket, ShootPacket)
from cuwo.types import IDPool, MultikeyDict, AttributeSet
from cuwo.vector import Vector3
from cuwo import constants
from cuwo.common import (get_clock_string, parse_clock, parse_command,
                         get_chunk, filter_string,
                         get_needed_total_xp, get_power_level,
                         get_player_class_str, get_player_race_str)
from cuwo.script import ScriptManager
from cuwo import database
from cuwo import entity

import re
import collections
import imp
import zipimport
import os
import sys
import json
import random


# initialize packet instances for sending
join_packet = JoinPacket()
seed_packet = SeedData()
chat_packet = ServerChatMessage()
entity_packet = EntityUpdate()
update_finished_packet = UpdateFinished()
time_packet = CurrentTime()
mismatch_packet = ServerMismatch()
server_full_packet = ServerFull()


class CubeWorldConnection(Protocol):
    """
    Protocol used for players
    """
    connection_state = -1
    entity_id = None
    entity_data = None
    change_index = -1
    scripts = None

    last_pos = None
    last_health = None
    last_level = None
    last_xp = None

    # used for anti chat spamming
    time_last_chat    = -1
    chat_messages_burst = 0

    # used for detecting dead connections
    time_last_packet  = -1
    # used for basic DoS protection
    packet_burst = 0

    def __init__(self, server, addr):
        self.address = addr
        self.server = server

    # connection methods

    def connectionMade(self):
        if len(self.server.connections) >= self.server.config.max_players:
            res = self.scripts.call('on_join_full_server')
            # For being able to allow joining by external scritps when server is full
            if not res:
                self.send_packet(server_full_packet)
                self.disconnect()
                print '[INFO] %s tried to join full server' % self.address.host
                return

        print '[INFO] Processing connection from %s ...' % self.address.host

        self.packet_handlers = {
            ClientVersion.packet_id: self.on_version_packet,
            EntityUpdate.packet_id: self.on_entity_packet,
            ClientChatMessage.packet_id: self.on_chat_packet,
            InteractPacket.packet_id: self.on_interact_packet,
            HitPacket.packet_id: self.on_hit_packet,
            ShootPacket.packet_id: self.on_shoot_packet
        }

        self.packet_handler = PacketHandler(CS_PACKETS, self.on_packet)

        self.server.connections.add(self)
        self.rights = AttributeSet()

        self.scripts = ScriptManager()
        self.server.scripts.call('on_new_connection', connection=self)

    def dataReceived(self, data):
        self.packet_handler.feed(data)

    def disconnect(self, reason=None):
        self.transport.loseConnection()
        self.connectionLost(reason)

    def connectionLost(self, reason):
        if self.connection_state <= 0:
            return
        self.connection_state = -1
        del self.server.players[self]
        if self.connection_state > 0:
            self.server.connections.discard(self)
            print '[INFO] Player %s left the game.' % self.name
            self.server.send_chat('<<< %s left the game' % self.name)
        if self.entity_data is not None:
            del self.server.entities[self.entity_id]
        if self.entity_id is not None:
            self.server.entity_ids.put_back(self.entity_id)
        if self.scripts is not None:
            self.scripts.unload()


    # packet methods

    def send_packet(self, packet):
        self.transport.write(write_packet(packet))

    def on_packet(self, packet):
        handler = self.packet_handlers.get(packet.packet_id, None)
        if handler is None:
            return
        time_last_packet = reactor.seconds()
        handler(packet)

    def on_version_packet(self, packet):
        if packet.version != constants.CLIENT_VERSION:
            mismatch_packet.version = constants.CLIENT_VERSION
            self.send_packet(mismatch_packet)
            self.disconnect(None)
            return
        server = self.server
        self.entity_id = server.entity_ids.pop()
        join_packet.entity_id = self.entity_id
        self.send_packet(join_packet)
        seed_packet.seed = server.config.seed
        self.send_packet(seed_packet)

    def on_entity_packet(self, packet):
        if self.entity_data is None:
            self.entity_data = create_entity_data()
            self.server.entities[self.entity_id] = self.entity_data
        mask = packet.update_entity(self.entity_data)
        self.entity_data.mask |= mask
        if self.entity_data.entity_type >= constants.ENTITY_TYPE_PLAYER_MIN_ID and self.entity_data.entity_type <= constants.ENTITY_TYPE_PLAYER_MAX_ID and getattr(self.entity_data, 'name', None):
            if self.connection_state == 0:
                self.on_join()
                return
        if entity.is_mode_set(mask):
            self.scripts.call('on_mode_update')
        if entity.is_class_set(mask):
            self.scripts.call('on_class_update')
        if entity.is_multiplier_set(mask):
            self.scripts.call('on_multiplier_update')
        if entity.is_level_set(mask):
            self.scripts.call('on_level_update')
        if entity.is_equipment_set(mask):
            self.scripts.call('on_equipment_update')
        if entity.is_name_set(mask):
            if self.check_name():
                if self.scripts.call('on_name_update') is False:
                    self.entity_data.name = oldname
                    self.kick('Name update denied')
                    return
        if entity.is_skill_set(mask):
            self.scripts.call('on_skill_update')

    def on_chat_packet(self, packet):
        if self.time_last_chat < (reactor.seconds() - constants.ANTISPAM_LIMIT_CHAT):
            self.chat_messages_burst = 0
        elif self.chat_messages_burst >= constants.ANTISPAM_BURST_CHAT:
            self.time_last_chat = reactor.seconds()
            res = self.scripts.call('on_spamming_chat')
            if not res:
                # As we do not want to spam back only do this when
                # burst limit is reached for the first time
                if self.chat_messages_burst == constants.ANTISPAM_BURST_CHAT:
                    if config.auto_kick_spam:
                        self.kick('Kicked for chat spamming')
                    else:
                        self.send_chat('[ANTISPAM] Please do not spam in chat!')
                self.chat_messages_burst += 1
            else:
                # When a script allowed spamming reset burst limit
                self.chat_messages_burst = 0
            return
        message = filter_string(packet.value).strip()
        if not message:
            return
        message = self.on_chat(message)
        if not message:
            return
        chat_packet.entity_id = self.entity_id
        chat_packet.value = message
        self.server.broadcast_packet(chat_packet)
        print '%s: %s' % (self.name, message)

    def on_interact_packet(self, packet):
        interact_type = packet.interact_type
        item = packet.item_data
        if interact_type == INTERACT_DROP:
            pos = self.position.copy()
            pos.z -= constants.BLOCK_SCALE
            if self.scripts.call('on_drop', item=item, pos=pos) is False:
                return
            self.server.drop_item(item, pos)
        elif interact_type == INTERACT_PICKUP:
            res = self.scripts.call('on_pickup')
            if res is False:
                return
            chunk = (packet.chunk_x, packet.chunk_y)
            try:
                item = self.server.remove_item(chunk, packet.item_index)
                self.give_item(item)
            except KeyError:
                pass

    def on_hit_packet(self, packet):
        try:
            target = self.server.entities[packet.target_id]
        except KeyError:
            return
        if constants.MAX_HIT_DISTANCE > 0:
            edist = common.get_distance_3d(self.entity_data.x,
                                           self.entity_data.y,
                                           self.entity_data.z,
                                           target.entity_data.x,
                                           target.entity_data.y,
                                           target.entity_data.z)
            if edist > constants.MAX_HIT_DISTANCE:
                print '[ANTICHEAT] Player %s tried to attack target that is %s away!' % (self.name, edist)
                self.kick('Range error')
                return
        res = self.scripts.call('on_hit', target, packet.damage)
        if res is False:
            return
        self.server.update_packet.player_hits.append(packet)
        if packet.damage <= 0:
            return
        if target.hp <= 0:
            target.hp = 0
            return
        if packet.damage > 1000:
            packet.damage = 1000
        if target.hp > packet.damage:
            res = self.scripts.call('on_damage', target, packet.damage)
            if res is False or res <= 0:
                return
            target.hp -= packet.damage
        else:
            target.hp = 0
            self.scripts.call('on_kill', target=target)


    def on_shoot_packet(self, packet):
        self.server.update_packet.shoot_actions.append(packet)


    def do_anticheat_actions(self):
        if not constants.ANTICHEAT_SYSTEM_ENABLED:
            return False
        if self.entity_data.entity_type < constants.ENTITY_TYPE_PLAYER_MIN_ID or self.entity_data.entity_type > constants.ENTITY_TYPE_PLAYER_MAX_ID:
            print '[ANTICHEAT] Player %s tried to join with invalid entity type id: %s!' % (self.name, self.entity_data.entity_type)
            self.kick('Invalid entity type submitted')
            return True
        if self.entity_data.class_type < constants.ENTITY_CLASS_PLAYER_MIN_ID or self.entity_data.class_type > constants.ENTITY_CLASS_PLAYER_MAX_ID :
            self.kick('Invalid character class submitted')
            print '[ANTICHEAT] Player %s tried to join with an invalid character class! Kicked.' % self.name
            return True
        if self.entity_data.hp > 1000:
            self.kick('Abnormal health points submitted')
            print '[ANTICHEAT] Player %s tried to join with an abnormal health points! Kicked.' % self.name
            return True
        if self.entity_data.level < 1 or self.entity_data.level > constants.PLAYER_MAX_LEVEL:
            self.kick('Abnormal level submitted')
            print '[ANTICHEAT] Player %s tried to join with an abnormal character level! Kicked.' % self.name
            return True
        # This seems to filter prevent cheaters from joining
        needed_xp = get_needed_total_xp(self.entity_data.level)
        if needed_xp > self.entity_data.current_xp:
            self.kick('Invalid character level')
            print '[ANTICHEAT] Player %s tried to join with character level %s that is higher than total xp needed for it (%s/%s)! Kicked.' % (self.name, self.entity_data.level, self.entity_data.current_xp, needed_xp)
            return True
        #if self.entity_data.inventory...... in constants.FORBIDDEN_ITEMS_POSSESSION
        return False


    # handlers

    def on_join(self):
        # Call join script
        if self.scripts.call('on_join').result is False:
            return
        if self.connection_state != 0:
            self.kick('Tried to join more than once!')
            return
        if not self.check_name():
            return
        self.connection_state = 1
        if self.entity_data.level < config.join_level_min:
            print '[INFO] Level of player %s #%s (%s) [%s] is lower than minimum of %s' % (self.name, self.entity_id, common.get_entity_type_level_str(self.entity_data), self.address.host, config.join_level_min)
            self.kick('Your level has to be at least %s' % config.join_level_min)
            return
        if self.entity_data.level > config.join_level_max:
            print '[INFO] Level of player %s #%s (%s) [%s] is higher than maximum of %s' % (self.name, self.entity_id, common.get_entity_type_level_str(self.entity_data), self.address.host, config.join_level_max)
            self.kick('Your level has to be lower than %s' % config.join_level_max)
            return
        # we dont want cheaters being able joining the server
        if self.do_anticheat_actions():
            self.server.send_chat('[ANTICHEAT] Player %s (%s) has been kicked for cheating.' % (self.name,
                                                                                                common.get_entity_type_level_str(self.entity_data)))
            return
        print '[INFO] Player %s #%s (%s) [%s] joined the game' % (self.name,
                                                                  common.get_entity_type_level_str(self.entity_data),
                                                                  self.entity_id,
                                                                  self.address.host)
        self.server.send_chat('>>> %s (%s) joined the game' % (self.name,
                                                               common.get_entity_type_level_str(self.entity_data)))
        for player in self.server.players.values():
            entity_packet.set_entity(player.entity_data, player.entity_id)
            self.send_packet(entity_packet)
        self.server.players[(self.entity_id,)] = self
        # connection successful -> continue
        self.connection_state = 3


    def on_command(self, command, parameters):
        if self.connection_state <= 0:
            return
        self.scripts.call('on_command', command=command, args=parameters)

    def on_chat(self, message):
        if self.connection_state <= 0:
            return
        if message.startswith('/'):
            command, args = parse_command(message[1:])
            self.on_command(command, args)
            print '[COMMAND] %s: /%s' % (self.entity_data.name, command)
            return
        event = self.scripts.call('on_chat', message=message)
        if event.result is False:
            return
        return event.message

    def on_equipment_update(self):
        # TODO
        return True

    def on_level_update(self):
        # TODO
        return True

    def on_skill_update(self):
        # TODO
        return True


    # other methods

    def send_chat(self, value):
        packet = ServerChatMessage()
        packet.entity_id = 0
        packet.value = value
        self.send_packet(packet)

    def give_item(self, item):
        action = PickupAction()
        action.entity_id = self.entity_id
        action.item_data = item
        res = self.scripts.call('on_give_item', action=action)
        if res is False:
            return False
        # Processed by the server and clients in next update task run
        self.server.update_packet.pickups.append(action)
        self.entity_data.changed = True

    def send_lines(self, lines):
        current_time = 0
        for line in lines:
            reactor.callLater(current_time, self.send_chat, line)
            current_time += 2

    def heal(self, amount=None, reason=None):
        if (amount is not None and amount <= 0) or (hp >= constants.PLAYER_MAX_HEALTH):
            return False
        res = self.scripts.call('on_heal', amount, reason)
        if res is False:
            return False
        if amount is None or amount + hp > constants.PLAYER_MAX_HEALTH:
            self.entity_data.hp = constants.PLAYER_MAX_HEALTH
        else:
            self.entity_data.hp += amount
        self.entity_data.changed = True
        for connection in self.server.connections.values():
            entity_packet.set_entity(self.entity_data, self.entity_id)
            connection.send_packet(entity_packet)
        if reason is None:
            self.send_chat('[INFO] You have been healed.')
        elif reason is not False:
            self.send_chat(reason)

    def damage(self, damage=0, critical=0, stun_duration=0, reason=None):
        res = self.scripts.call('on_damage', damage, critical, stun_duration, reason)
        if res is False:
            return False
        packet = HitPacket()
        packet.entity_id = self.entity_id
        packet.target_id = self.entity_id
        packet.hit_type = HIT_NORMAL
        packet.damage = damage
        packet.critical = critical
        packet.stun_duration = stun_duration
        packet.something8 = 0
        packet.pos = self.position
        packet.hit_dir = Vector3()
        packet.skill_hit = 0
        packet.show_light = 0
        # Processed by the server and clients in next update task run
        self.server.update_packet.player_hits.append(packet)
        self.entity_data.changed = True
        if reason:
            self.send_chat(reason)
        return True

    def kill(self, killer=None, reason=None):
        if not damage(self.entity_data.hp + 100, 1, 0):
            return False
        res = self.scripts.call('on_kill', killer=killer, reason=reason)
        if res is False:
            return False
        packet = KillAction()
        if killer is None:
            packet.entity_id = self.entity_id
        else:
            packet.entity_id = killer.entity_id
        packet.target_id = self.entity_id
        packet.xp_gained = 0
        # Processed by the server and clients in next update task run
        self.server.update_packet.kill_actions.append(packet)
        self.entity_data.changed = True
        if reason is None:
            if killer is self:
                self.send_chat('+ You commited suicide')
            else:
                self.send_chat('+ You have been killed by %s' % killer.entity_data.name)
        elif reason is not False:
            self.send_chat(reason)
        return True

    def kick(self, reason=None):
        res = self.scripts.call('on_kick', reason=reason)
        if res is False:
            return
        if reason is None:
            self.send_chat('You have been kicked')
        elif reason is not False:
            self.send_chat(reason)
        self.disconnect()
        if self.entity_data.name:
            self.server.send_chat('<<< %s has been kicked' % self.entity_data.name)

    def teleport(self, to_x, to_y, to_z):
        res = self.scripts.call('on_teleport', pos=Vector3(to_x, to_y, to_z))
        if res is False:
            return
        self.entity_data.x = to_x
        self.entity_data.y = to_y
        self.entity_data.z = to_z
        self.entity_data.changed = True
        for connection in self.server.connections.values():
            entity_packet.set_entity(self.entity_data, self.entity_id)
            connection.send_packet(entity_packet)
        self.send_chat('[INFO] You have been teleported.')

    def check_name(self):
        server = self.server
        self.entity_data.name = self.entity_data.name.strip()
        if not self.entity_data.name or re.search(server.config.name_filter, self.name) is None:
            self.kick('Illegal name')
            print '[INFO] Player #%s [%s] had illegal name' % (self.entity_id, self.address.host)
            return False
        return True

    def check_items(self):
        server = self.server
        for slotindex in range(13):
            item = entity_data.equipment[slotindex]
            if not item or item.type == 0:
                continue
            if item.level < 0:
                self.kick('Illegal item')
                print '[INFO] Player %s #%s (%s) [%s] had item with level lover than 0' % (self.entity_data.name, self.entity_id, common.get_entity_type_level_str(self.entity_data), self.address.host)
                return False
            if item.material in server.config.forbid_item_possession:
                self.kick('Forbidden item')
                print '[INFO] Player %s #%s (%s) [%s] had forbidden item #%s' % (self.entity_data.name, self.entity_id, common.get_entity_type_level_str(self.entity_data), self.address.host, item.material)
                return False
        return True


    # convienience methods

    @property
    def position(self):
        if not self.entity_data:
            return None
        return Vector3(self.entity_data.x,
                       self.entity_data.y,
                       self.entity_data.z)


    @property
    def name(self):
        if not self.entity_data:
            return None
        return self.entity_data.name


class CubeWorldServer(Factory):
    exit_code = 0
    items_changed = False
    last_secondly_check = -1
    next_items_autoremoval = -1
    ticks_since_last_second = -1
    ticks_per_second = -1
    current_change_index = 0

    def __init__(self, config):
        self.config = config

        self.db_con = database.get_connection()
        database.create_structure(self.db_con)

        # GAME RELATED
        self.update_packet = ServerUpdate()
        self.update_packet.reset()

        self.connections = set()
        self.players = MultikeyDict()

        self.chunk_items = collections.defaultdict(list)
        self.entities = {}
        self.entity_ids = IDPool(1)

        self.update_loop = LoopingCall(self.update)
        self.update_loop.start(1.0 / constants.UPDATE_FPS, False)

        # SERVER RELATED
        self.git_rev = getattr(config, 'git_rev', None)

        self.passwords = {}
        for k, v in config.passwords.iteritems():
            self.passwords[k.lower()] = v

        self.scripts = ScriptManager()
        for script in config.scripts:
            self.load_script(script)

        # INGAME TIME
        self.extra_elapsed_time = 0.0
        self.start_time = reactor.seconds()
        self.set_clock('12:00')

        reactor.listenTCP(config.port, self)

    def buildProtocol(self, addr):
        max_count = self.config.max_connections_per_ip
        for connection in self.connections:
            if connection.address.host == addr.host:
                if max_count <= 1:
                    max_count = 0
                    print '[WARNING] Too many connections from %s, closing...' % addr.host
                    return
                else:
                    max_count -= 1
        ret = self.scripts.call('on_connection_attempt', address=addr).result
        if ret is False:
            return None
        return CubeWorldConnection(self, addr)

    def remove_item(self, chunk, index):
        try:
            items = self.chunk_items[chunk]
            ret = items.pop(index)
            self.items_changed = True
            return ret
        except KeyError:
            return None
        except IndexError:
            return None

    def drop_item(self, item_data, pos, lifetime=None):
        try:
            chunk_items = self.chunk_items[get_chunk(pos)]
            if len(chunk_items) > constants.MAX_ITEMS_PER_CHUNK:
                return
            item = ChunkItemData()
            item.drop_time = 750 # ?
            item.scale = 0.1
            item.rotation = 185.0
            item.something3 = item.something5 = item.something6 = 0
            item.pos = pos
            item.item_data = item_data
            if lifetime is None:
                item.despawn_time = reactor.seconds() + constants.MAX_ITEM_LIFETIME
            elif lifetime is not False:
                item.despawn_time = reactor.seconds() + lifetime
            else:
                item.despawn_time = None
            chunk_items.append(item)
            self.items_changed = True
            if item.despawn_time < self.next_items_autoremoval:
                self.next_items_autoremoval = item.despawn_time
            return
        except KeyError:
            pass
        except IndexError:
            pass

    def update(self):
        # secondly update check
        uxtime = int(reactor.seconds())
        update_seconds_delta = uxtime - self.last_secondly_check
        if update_seconds_delta == 0:
            self.ticks_since_last_second += 1
        else:
            self.last_secondly_check = uxtime
            if update_seconds_delta > 0:
                self.scripts.call('update')
                self.ticks_per_second = (self.ticks_per_second + (self.ticks_since_last_second / update_seconds_delta)) / 2
                self.ticks_since_last_second = 0
                if self.ticks_per_second < 20:
                    print '[WARNING] The amount of TPS is as low as %s' % self.ticks_per_second
            else:
                print '[WARNING] Seems like the reactor time went backwards! Ignoring.'

        # entity updates
        for entity_id, entity in self.entities.iteritems():
            entity_packet.set_entity(entity, entity_id, entity.mask)
            entity.mask = 0
            self.broadcast_packet(entity_packet)
        self.broadcast_packet(update_finished_packet)

        # other updates
        update_packet = self.update_packet

        # item updates
        if uxtime >= self.next_items_autoremoval:
            self.next_items_autoremoval = self.last_secondly_check + 300
            for chunk, items in self.chunk_items.iteritems():
                new_chunk_items = []
                for item in items:
                    if not item.despawn_time or item.despawn_time > uxtime:
                        new_chunk_items.append(item)
                    else:
                        if item.despawn_time < self.next_items_autoremoval:
                            self.next_items_autoremoval = item.despawn_time
                        self.items_changed = True
                self.chunk_items[chunk] = new_chunk_items

        if self.items_changed:
            for chunk, items in self.chunk_items.iteritems():
                item_list = ChunkItems()
                item_list.chunk_x, item_list.chunk_y = chunk
                item_list.items = items
                update_packet.chunk_items.append(item_list)
        self.broadcast_packet(update_packet)
        update_packet.reset()

        # reset drop times
        if self.items_changed:
            for items in self.chunk_items.values():
                for item in items:
                    item.drop_time = 0
            self.items_changed = False

        if update_seconds_delta != 0:
            for player in self.players:
                if player.time_last_packet > (uxtime - constants.CLIENT_RECV_TIMEOUT):
                    if player.entity_data.changed:
                        player.entity_data.changed = False
                        player.do_anticheat_actions()
                else:
                    print '[WARNING] Connection timed out for Player %s (ID: %s)' % (player.entity_data.name, player.entity_id)
                    player.kick('Connection timed out')
            self.broadcast_time()

    def send_chat(self, value):
        packet = ServerChatMessage()
        packet.entity_id = 0
        packet.value = value
        self.broadcast_packet(packet)

    def broadcast_packet(self, packet):
        data = write_packet(packet)
        for player in self.players:
            player.transport.write(data)

    def broadcast_time(self):
        time_packet.time = self.get_time()
        time_packet.day = self.get_day()
        self.broadcast_packet(time_packet)

    # line/string formatting options based on config

    def format(self, value):
        format_dict = {'server_name': self.config.server_name}
        return value % format_dict

    def format_lines(self, value):
        lines = []
        for line in value:
            lines.append(self.format(line))
        return lines


    # script methods

    def load_script_source(self, name):
        path = './scripts/%s.py' % name
        try:
            return imp.load_source(name, path)
        except IOError:
            pass

    def load_script_zip(self, name):
        path = './scripts/%s.zip' % name
        try:
            return zipimport.zipimporter(path).load_module(name)
        except ImportError:
            pass
        except zipimport.ZipImportError:
            pass

    def load_script(self, name):
        for f in (self.load_script_source, self.load_script_zip):
            mod = f(name)
            if mod:
                break
        else:
            return None
        script = mod.get_class()(self)
        print '[INFO] Loaded script "%r"' % name
        return script

    def call_command(self, user, command, args):
        """
        Calls a command from an external interface, e.g. IRC, console
        """
        return self.scripts.call('on_command', user=user, command=command, args=args).result


    # data store methods

    def load_data(self, name, default=None):
        return database.load_data(self.db_con, name, default)


    def save_data(self, name, value):
        return database.save_data(self.db_con, name, value)


    # time methods

    def set_clock(self, value):
        day = self.get_day()
        time = parse_clock(value)
        self.start_time = reactor.seconds()
        self.extra_elapsed_time = day * constants.MAX_TIME + time


    def get_elapsed_time(self):
        dt = reactor.seconds() - self.start_time
        dt *= self.config.time_modifier * constants.NORMAL_TIME_SPEED
        return dt * 1000 + self.extra_elapsed_time


    def get_time(self):
        return int(self.get_elapsed_time() % constants.MAX_TIME)

    def get_day(self):
        return int(self.get_elapsed_time() / constants.MAX_TIME)

    def get_clock(self):
        return get_clock_string(self.get_time())

    def stop(self, code=None):
        self.exit_code = code
        reactor.stop()


    # twisted wrappers

    def listen_tcp(self, *arg, **kw):
        interface = self.config.network_interface
        return reactor.listenTCP(*arg, interface=interface, **kw)

    def connect_tcp(self, *arg, **kw):
        interface = self.config.network_interface
        return reactor.connectTCP(*arg, bindAddress=(interface, 0), **kw)



def main():
    # for py2exe
    if hasattr(sys, 'frozen'):
        path = os.path.dirname(
            unicode(sys.executable, sys.getfilesystemencoding()))
        sys.path.append(path)

    import config
    server = CubeWorldServer(config)
    print '[INFO] Server is listening on port %s using cuwo %s' % (config.port, getattr(config, 'git_rev', None))
    if config.profile_file is None:
        reactor.run()
    else:
        import cProfile
        cProfile.run('reactor.run()', filename=config.profile_file)

    sys.exit(server.exit_code)

if __name__ == '__main__':
    main()
