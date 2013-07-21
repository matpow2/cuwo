# Copyright (c) Mathias Kaerlev, Somer Hayter and Julien Kross 2013.
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

from cuwo.twistedreactor import install_reactor
install_reactor()
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
from cuwo.script import call_scripts
from cuwo import database

import collections
import imp
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
    connection_state = 0
    entity_id = None
    entity_data = None
    disconnected = False
    change_index = -1

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
        self.packet_handlers = {
            ClientVersion.packet_id: self.on_version_packet,
            EntityUpdate.packet_id: self.on_entity_packet,
            ClientChatMessage.packet_id: self.on_chat_packet,
            InteractPacket.packet_id: self.on_interact_packet,
            HitPacket.packet_id: self.on_hit_packet,
            ShootPacket.packet_id: self.on_shoot_packet
        }


        self.scripts = []
        self.server.call_scripts('on_new_connection', self)
        self.packet_handler = PacketHandler(CS_PACKETS, self.on_packet)
        self.rights = AttributeSet()


    def dataReceived(self, data):
        self.packet_handler.feed(data)


    def disconnect(self, reason=None):
        self.time_disconnected = self.server.last_secondly_check
        self.transport.loseConnection()
        self.connectionLost(reason)


    def connectionLost(self, reason=None):
        if self.connection_state == 0:
            return
        self.connection_state = 0
        try:
            del self.server.connections[self]
        except KeyError:
            pass
        finally:
            if not (self.entity_id is None):
                try:
                    del self.server.entities[self.entity_id]
                except KeyError:
                    pass
                else:
                    self.server.entity_ids.put_back(self.entity_id)
            for script in self.scripts[:]:
                script.unload()
            if self.connection_state > 0:
                self.connection_state = 0
                print '[INFO] Player %s [%s] left the game' % (self.name, self.address.host)
                self.server.send_chat('<<< %s left the game' % self.name)


    # packet methods

    def send_packet(self, packet):
        self.transport.write(write_packet(packet))


    def on_packet(self, packet):
        self.time_last_packet = self.server.last_secondly_check
        handler = self.packet_handlers.get(packet.packet_id, None)
        if handler is None:
            print '[WARNING] Unhandled client packet: %s' % packet.packet_id
            return
        # packets are normally sent at least once per second by the client
        handler(packet)


    def on_version_packet(self, packet):
        if packet.version != constants.CLIENT_VERSION:
            mismatch_packet.version = constants.CLIENT_VERSION
            self.send_packet(mismatch_packet)
            self.disconnect()
            print '[INFO] Player %s [%s] is using an incompatible client version (%s != %s)' % (self.name, self.address.host, packet.version, constants.CLIENT_VERSION)
            return
        if len(self.server.connections) >= self.server.config.max_players:
            self.send_packet(server_full_packet)
            self.disconnect()
            print '[INFO] Player %s [%s] tried to join full server' % (self.name, self.address.host)
            return
        self.entity_id = self.server.entity_ids.pop()
        self.server.connections[(self.entity_id,)] = self
        join_packet.entity_id = self.entity_id
        self.send_packet(join_packet)
        seed_packet.seed = self.server.config.seed
        self.send_packet(seed_packet)


    def on_entity_packet(self, packet):
        if self.entity_data is None:
            self.entity_data = create_entity_data()
            self.server.entities[self.entity_id] = self.entity_data;
        self.entity_data.mask |= packet.update_entity(self.entity_data)
        if self.entity_data.entity_type >= constants.ENTITY_TYPE_PLAYER_MIN_ID and self.entity_data.entity_type <= constants.ENTITY_TYPE_PLAYER_MAX_ID and getattr(self.entity_data, 'name', None):
            if self.connection_state == 0:
                self.on_join()
            else:
                if is_bit_set(mask, 9):
                    self.call_scripts('on_mode_update')
                if is_bit_set(mask, 21):
                    self.call_scripts('on_class_update')
                if is_bit_set(mask, 33):
                    self.call_scripts('on_level_update')
                if is_bit_set(mask, 44):
                    self.call_scripts('on_equipment_update')
                if is_bit_set(mask, 45):
                    self.call_scripts('on_name_update')
                if is_bit_set(mask, 46):
                    self.call_scripts('on_skill_update')
        else:
            print '[INFO] Invalid entity type for player with packet from %' % self.address.host


    def on_chat_packet(self, packet):
        # Spammer stopped for a defined amount of seconds - reset burst score
        if self.time_last_chat < (self.last_secondly_check - constants.ANTISPAM_LIMIT_CHAT):
            self.chat_messages_burst = 0
        # When spammer continues with spamming, antichat time is increased
        self.time_last_chat = self.last_secondly_check
        message = filter_string(packet.value).strip()
        if not message:
            return
        if not self.on_chat(message):
            return
        if self.chat_messages_burst < constants.ANTISPAM_BURST_CHAT:
            self.chat_messages_burst += 1
            chat_packet.entity_id = self.entity_id
            chat_packet.value = message
            self.server.broadcast_packet(chat_packet)
            print '%s: %s' % (self.name, message)
        else:
            if config.auto_kick_spam:
                self.kick('Kicked for chat spamming')
            else:
                self.send_chat('[ANTISPAM] Please do not spam in chat!')


    def on_interact_packet(self, packet):
        interact_type = packet.interact_type
        if interact_type == INTERACT_DROP:
            pos = self.position.copy()
            pos.z -= constants.BLOCK_SCALE
            if self.server.drop_item(packet.item_data, self):
                print '[DEBUG] Player %s dropped item #%s at (%r,%r,%r)' % (self.name, self.entity_id, pos.x, pos.y, pos.z)
            else:
                self.send_chat('[HINT] Items can not be dropped here.')
        elif interact_type == INTERACT_PICKUP:
            chunk = (packet.chunk_x, packet.chunk_y)
            try:
                item = self.server.remove_item(chunk, packet.item_index)
                self.give_item(item)
                print '[DEBUG] Player %s picked up item #%s at chunk (%r,%r)' % (self.name, packet.item_index, packet.chunk_x, packet.chunk_y)
            except KeyError:
                print '[DEBUG] Exception while %s tried to interact with #%s at chunk (%r,%r)' % (self.name, packet.item_index, packet.chunk_x, packet.chunk_y)
        else:
            print '[DEBUG] Player %s interacted with unimplemented type %s, id %s, packet index %s at pos (%r,%r)' % (self.name, interact_type, self.entity_id, packet.item_index, packet.chunk_x, packet.chunk_y)


    def on_hit_packet(self, packet):
        try:
            target = self.server.entities[packet.target_id]
        except KeyError:
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
            target.hp -= packet.damage
        else:
            target.hp = 0
            self.call_scripts('on_kill', target)


    def on_shoot_packet(self, packet):
        self.server.update_packet.shoot_actions.append(packet)


    def do_anticheat_actions(self):
        if not constants.ANTICHEAT_SYSTEM_ENABLED:
            return False
        if self.entity_data.entity_type < constants.ENTITY_TYPE_PLAYER_MIN_ID or self.entity_data.entity_type > constants.ENTITY_TYPE_PLAYER_MAX_ID:
            print '[ANTICHEAT] Player %s tried to join with invalid entity type id: %s!' % (self.entity_data.name, self.entity_data.entity_type)
            self.kick('Invalid entity type submitted')
            return True
        if self.entity_data.class_type < constants.ENTITY_CLASS_PLAYER_MIN_ID or self.entity_data.class_type > constants.ENTITY_CLASS_PLAYER_MAX_ID :
            self.kick('Invalid character class submitted')
            print '[ANTICHEAT] Player %s tried to join with an invalid character class! Kicked.' % self.entity_data.name
            return True
        if self.entity_data.hp > 1000:
            self.kick('Abnormal health points submitted')
            print '[ANTICHEAT] Player %s tried to join with an abnormal health points! Kicked.' % self.entity_data.name
            return True
        if self.entity_data.character_level < 1 or self.entity_data.character_level > constants.PLAYER_MAX_LEVEL:
            self.kick('Abnormal level submitted')
            print '[ANTICHEAT] Player %s tried to join with an abnormal character level! Kicked.' % self.entity_data.name
            return True
        # This seems to filter prevent cheaters from joining
        needed_xp = get_needed_total_xp(self.entity_data.character_level)
        if needed_xp > self.entity_data.current_xp:
            self.kick('Invalid character level')
            print '[ANTICHEAT] Player %s tried to join with character level %s that is higher than total xp needed for it (%s/%s)! Kicked.' % (self.entity_data.name, self.entity_data.character_level, self.entity_data.current_xp, needed_xp)
            return True
        #if self.entity_data.inventory...... in constants.FORBIDDEN_ITEMS_POSSESSION
        return False


    # handlers

    def on_join(self):
        if self.connection_state != 0:
            return
        # lock
        self.connection_state = 5
        if self.entity_data.character_level < config.join_level_min:
            print '[INFO] Level of player %s (%s) (%s level %s) is lower than minimum of %s' % (self.entity_data.name, self.address.host, self.entity_id, get_player_class_str(self.entity_data.class_type), self.entity_data.character_level, constants.LEVEL_MIN)
            self.kick('Your level has to be at least %s' % config.join_level_min)
            return
        if self.entity_data.character_level > config.join_level_max:
            print '[INFO] Level of player %s (%s) (%s level %s) is higher than maximum of %s' % (self.entity_data.name, self.address.host, self.entity_id, get_player_class_str(self.entity_data.class_type), self.entity_data.character_level, constants.LEVEL_MAX)
            self.kick('Your level has to be lower than %s' % config.join_level_max)
            return
        # we dont want cheaters being able joining the server
        if self.do_anticheat_actions():
            self.connection_state = -3
            self.server.send_chat('[ANTICHEAT] Player %s has been kicked for cheating.' % self.entity_data.name)
        else:
            print '>>> Player %s (IP: %s, ID: %s, class: %s, level: %s) joined the game' % (self.entity_data.name, self.address.host, self.entity_id, get_player_class_str(self.entity_data.class_type), self.entity_data.character_level)
            for connection in self.server.connections.values():
                entity_packet.set_entity(connection.entity_data, connection.entity_id)
                self.send_packet(entity_packet)
            self.call_scripts('on_join')
            self.server.send_chat('>>> %s (%s level %s) joined the game' % (self.entity_data.name, get_player_class_str(self.entity_data.class_type), self.entity_data.character_level))
            self.connection_state = 1


    def on_command(self, command, parameters):
        self.call_scripts('on_command', command, parameters)


    def on_chat(self, message):
        if message.startswith('/'):
            command, args = parse_command(message[1:])
            self.on_command(command, args)
            print '[COMMAND] %s: /%s' % (self.name, command)
            return False
        self.call_scripts('on_chat', message)


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
        self.server.update_packet.pickups.append(action)


    def send_lines(self, lines):
        current_time = 0
        for line in lines:
            reactor.callLater(current_time, self.send_chat, line)
            current_time += 2


    def kick(self, reason = None):
        if reason is None:
            self.send_chat('You have been kicked')
        elif reason is not False:
            self.send_chat(reason)
        self.disconnect()
        if self.name:
            self.server.send_chat('<<< %s has been kicked' % self.name)


    def call_scripts(self, name, *arg, **kw):
        return call_scripts(self.scripts, name, *arg, **kw)


    # convienience methods

    @property
    def position(self):
        if self.entity_data is None:
            return None
        return Vector3(self.entity_data.x,
                       self.entity_data.y,
                       self.entity_data.z)


    @property
    def name(self):
        if self.entity_data is None:
            return None
        return getattr(self.entity_data, 'name', None)



class BanProtocol(Protocol):
    """
    Protocol used for banned players.
    Ignores data from client and only sends JoinPacket/ServerChatMessage
    """

    def __init__(self, message=None):
        self.message = message


    def send_packet(self, packet):
        self.transport.write(write_packet(packet))


    def connectionMade(self):
        join_packet.entity_id = 1
        self.send_packet(join_packet)
        self.disconnect_call = reactor.callLater(0.1, self.disconnect)


    def disconnect(self):
        if self.message is not None:
            chat_packet.entity_id = 0
            chat_packet.value = self.message
        self.send_packet(chat_packet)
        self.transport.loseConnection()


    def connectionLost(self, reason):
        if self.disconnect_call.active():
            self.disconnect_call.cancel()



class CubeWorldServer(Factory):
    items_changed = False

    last_secondly_check = -1
    next_items_autoremoval = -1
    ticks_since_last_second = -1
    ticks_per_second = -1
    current_change_index = 0


    def __init__(self, config):
        self.config = config

        # GAME RELATED
        self.update_packet = ServerUpdate()
        self.update_packet.reset()

        self.connections = MultikeyDict()

        self.entities = {}
        self.entity_ids = IDPool(1)

        self.chunk_items = collections.defaultdict(list)

        self.update_loop = LoopingCall(self.update)
        self.update_loop.start(1.0 / constants.UPDATE_FPS, False)

        # SERVER RELATED
        self.git_rev = getattr(config, 'git_rev', None)

        self.passwords = {}
        for k, v in config.passwords.iteritems():
            self.passwords[k.lower()] = v

        self.scripts = []
        for script in config.scripts:
            self.load_script(script)

        # INGAME TIME
        self.extra_elapsed_time = 0.0
        self.start_time = reactor.seconds()
        self.set_clock('12:00')


    def buildProtocol(self, addr):
        message = self.call_scripts('on_connection_attempt', addr)
        if message is False:
            return BanProtocol(message)
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


    def drop_item(self, item_data, pos):
        try:
            chunk_items = self.chunk_items[get_chunk(pos)]
            if len(chunk_items) < constants.MAX_ITEMS_PER_CHUNK:
                item = ChunkItemData()
                item.drop_time = 750 # ?
                item.scale = 0.1
                item.rotation = 185.0
                item.something3 = item.something5 = item.something6 = 0
                item.pos = pos
                item.item_data = item_data
                item.despawn_time = item.drop_time + constants.MAX_ITEM_LIFETIME
                chunk_items.append(item)
                if item.despawn_time < self.next_items_autoremoval:
                    self.next_items_autoremoval = item.despawn_time
                self.items_changed = True
                return True
            else:
                return False
        except KeyError:
            pass
        except IndexError:
            pass
        return False


    def update(self):
        # secondly update check
        uxtime = int(reactor.seconds())
        update_seconds_delta = uxtime - self.last_secondly_check
        if update_seconds_delta == 0:
            self.ticks_since_last_second += 1
        else:
            self.last_secondly_check = uxtime
            if update_seconds_delta > 0:
                self.call_scripts('update')
                self.ticks_per_second = (self.ticks_per_second + (self.ticks_since_last_second / update_seconds_delta)) / 2
                self.ticks_since_last_second = 0
                if self.ticks_per_second < 25:
                    print '[WARNING] The amount of TPS is as low as %s' % self.ticks_per_second
            else:
                print '[WARNING] Seems like the reactor time went backwards! Ignoring.'
                update_seconds_delta = 0

        # entity updates
        for entity_id, entity in self.entities.iteritems():
            if entity.changed:
                entity.changed = False
                entity_packet.set_entity(entity, entity_id, entity.mask)
                entity.mask = 0
                self.broadcast_packet(entity_packet)
        self.broadcast_packet(update_finished_packet)

        # other updates
        update_packet = self.update_packet

        # item updates
        if self.last_secondly_check >= self.next_items_autoremoval:
            self.next_items_autoremoval = self.last_secondly_check + 300
            item_despawn_time = self.last_secondly_check - constants.MAX_ITEM_LIFETIME
            for chunk, items in self.chunk_items.iteritems():
                new_chunk_items = []
                for item in items:
                    # items that stay forever
                    if item.drop_time < 0:
                        new_chunk_items.append(item)
                    else:
                        if item.drop_time > item_despawn_time:
                            new_chunk_items.append(item)
                            item_lifetime = item.drop_time + constants.MAX_ITEM_LIFETIME
                            if (item.drop_time + constants.MAX_ITEM_LIFETIME) < self.next_items_autoremoval:
                                self.next_items_autoremoval = item.drop_time + constants.MAX_ITEM_LIFETIME
                        else:
                            self.items_changed = True
                self.chunk_items[chunk] = new_chunk_items

        if self.items_changed:
            self.items_changed = False
            for chunk, items in self.chunk_items.iteritems():
                item_list = ChunkItems()
                item_list.chunk_x, item_list.chunk_y = chunk
                item_list.items = items
                update_packet.chunk_items.append(item_list)

        self.broadcast_packet(update_packet)
        update_packet.reset()

        if update_seconds_delta != 0:
            for connection in self.connections.values():
                if connection.time_last_packet > (uxtime - constants.CLIENT_RECV_TIMEOUT):
                    if connection.entity_data.changed:
                        connection.entity_data.changed = False
                        connection.do_anticheat_actions()
                    self.broadcast_time()
                else:
                    print '[WARNING] Connection timed out for Player %s (ID: %s)' % (connection.entity_data.name, connection.entity_id)
                    connection.kick('Connection timed out')


    def send_chat(self, value):
        packet = ServerChatMessage()
        packet.entity_id = 0
        packet.value = value
        self.broadcast_packet(packet)


    def broadcast_packet(self, packet):
        data = write_packet(packet)
        for connection in self.connections.values():
            connection.transport.write(data)


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

    def load_script(self, name):
        path = './scripts/%s.py' % name
        try:
            mod = imp.load_source(name, path)
        except IOError:
            return None
        script = mod.get_class()(self)
        print '[INFO] Loaded additional Script: %s' % name
        return script


    def call_scripts(self, name, *arg, **kw):
        return call_scripts(self.scripts, name, *arg, **kw)


    # data store methods

    def load_data(self, name, default = None):
        try:
            return database.load_data(name, default)
            #path = './data/%s' % name
            #try:
            #    with open(path, 'rb') as fp:
            #        return json.load(fp)
        except:
            print '[ERROR] Could not load data of key %s' % name
        return default


    def save_data(self, name, value):
        try:
            return database.save_data(name, value)
            # move to database instead of files ... later
            #path = './data/%s' % name
            #try:
            #    create_file_path(path)
            #    data = pprint.pformat(value, width = 1)
            #    with open(path, 'wb') as fp:
            #        fp.write(data)
        except:
            print '[ERROR] Could not save data of key %s' % name
        return False


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



def main():
    # for py2exe
    if hasattr(sys, 'frozen'):
        path = os.path.dirname(
            unicode(sys.executable, sys.getfilesystemencoding()))
        sys.path.append(path)

    import config
    reactor.listenTCP(constants.SERVER_PORT, CubeWorldServer(config))
    print '[INFO] cuwo is running on port %s now' % constants.SERVER_PORT
    if config.profile_file is None:
        reactor.run()
    else:
        import cProfile
        cProfile.run('reactor.run()', filename=config.profile_file)


if __name__ == '__main__':
    main()
