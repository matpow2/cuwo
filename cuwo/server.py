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
                         get_chunk, filter_string)
from cuwo.script import ScriptManager
from cuwo.config import ConfigObject
from cuwo import entity

import collections
import imp
import zipimport
import os
import sys
import pprint
import traceback

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
    has_joined = False
    entity_id = None
    entity_data = None
    disconnected = False
    scripts = None

    def __init__(self, server, addr):
        self.address = addr
        self.server = server

    # connection methods

    def connectionMade(self):
        server = self.server
        if len(server.connections) >= server.config.base.max_players:
            self.send_packet(server_full_packet)
            self.disconnect()
            return

        self.packet_handlers = {
            ClientVersion.packet_id: self.on_version_packet,
            EntityUpdate.packet_id: self.on_entity_packet,
            ClientChatMessage.packet_id: self.on_chat_packet,
            InteractPacket.packet_id: self.on_interact_packet,
            HitPacket.packet_id: self.on_hit_packet,
            ShootPacket.packet_id: self.on_shoot_packet
        }

        self.packet_handler = PacketHandler(CS_PACKETS, self.on_packet)

        server.connections.add(self)
        self.rights = AttributeSet()

        self.scripts = ScriptManager()
        server.scripts.call('on_new_connection', connection=self)

    def dataReceived(self, data):
        self.packet_handler.feed(data)

    def disconnect(self, reason=None):
        self.transport.loseConnection()
        self.connectionLost(reason)

    def connectionLost(self, reason):
        if self.disconnected:
            return
        self.disconnected = True
        self.server.connections.discard(self)
        if self.has_joined:
            del self.server.players[self]
            print 'Player %s left' % self.name
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
        if self.disconnected:
            return
        handler = self.packet_handlers.get(packet.packet_id, None)
        if handler is None:
            # print 'Unhandled client packet: %s' % packet.packet_id
            return
        handler(packet)

    def on_version_packet(self, packet):
        if packet.version != constants.CLIENT_VERSION:
            mismatch_packet.version = constants.CLIENT_VERSION
            self.send_packet(mismatch_packet)
            self.disconnect()
            return
        server = self.server
        self.entity_id = server.entity_ids.pop()
        join_packet.entity_id = self.entity_id
        self.send_packet(join_packet)
        seed_packet.seed = server.config.base.seed
        self.send_packet(seed_packet)

    def on_entity_packet(self, packet):
        if self.entity_data is None:
            self.entity_data = create_entity_data()
            self.server.entities[self.entity_id] = self.entity_data

        mask = packet.update_entity(self.entity_data)
        self.entity_data.mask |= mask
        if not self.has_joined and getattr(self.entity_data, 'name', None):
            self.on_join()
            return

        self.scripts.call('on_entity_update', mask=mask)
        # XXX clean this up
        if entity.is_pos_set(mask):
            self.scripts.call('on_pos_update')
        if entity.is_mode_set(mask):
            self.scripts.call('on_mode_update')
        if entity.is_class_set(mask):
            self.scripts.call('on_class_update')
        if entity.is_name_set(mask):
            self.scripts.call('on_name_update')
        if entity.is_multiplier_set(mask):
            self.scripts.call('on_multiplier_update')
        if entity.is_level_set(mask):
            self.scripts.call('on_level_update')
        if entity.is_equipment_set(mask):
            self.scripts.call('on_equipment_update')
        if entity.is_skill_set(mask):
            self.scripts.call('on_skill_update')
        if entity.is_appearance_set(mask):
            self.scripts.call('on_appearance_update')
        if entity.is_charged_mp_set(mask):
            self.scripts.call('on_charged_mp_update')
        if entity.is_flags_set(mask):
            self.scripts.call('on_flags_update')
        if entity.is_consumable_set(mask):
            self.scripts.call('on_consumable_update')

    def on_chat_packet(self, packet):
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
            if self.scripts.call('on_drop', item=item,
                                 pos=pos).result is False:
                return
            self.server.drop_item(packet.item_data, pos)
        elif interact_type == INTERACT_PICKUP:
            chunk = (packet.chunk_x, packet.chunk_y)
            try:
                item = self.server.remove_item(chunk, packet.item_index)
            except IndexError:
                return
            self.give_item(item)

    def on_hit_packet(self, packet):
        try:
            target = self.server.entities[packet.target_id]
        except KeyError:
            return
        self.server.update_packet.player_hits.append(packet)
        if target.hp <= 0:
            return
        target.hp -= packet.damage
        if target.hp <= 0:
            self.scripts.call('on_kill', target=target)

    def on_shoot_packet(self, packet):
        self.server.update_packet.shoot_actions.append(packet)

    # handlers

    def on_join(self):
        if self.scripts.call('on_join').result is False:
            return

        print 'Player %s joined' % self.name
        for player in self.server.players.values():
            entity_packet.set_entity(player.entity_data, player.entity_id)
            self.send_packet(entity_packet)

        self.server.players[(self.entity_id,)] = self
        self.has_joined = True

    def on_command(self, command, parameters):
        self.scripts.call('on_command', command=command, args=parameters)

    def on_chat(self, message):
        if message.startswith('/'):
            command, args = parse_command(message[1:])
            self.on_command(command, args)
            return
        event = self.scripts.call('on_chat', message=message)
        if event.result is False:
            return
        return event.message

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

    def kick(self):
        self.send_chat('You have been kicked')
        self.disconnect()
        self.server.send_chat('%s has been kicked' % self.name)

    # convienience methods

    @property
    def position(self):
        if self.entity_data is None:
            return None
        return self.entity_data.pos

    @property
    def name(self):
        if self.entity_data is None:
            return None
        return self.entity_data.name


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
    exit_code = None

    def __init__(self, config):
        self.config = config
        base = config.base

        # game-related
        self.update_packet = ServerUpdate()
        self.update_packet.reset()

        self.connections = set()
        self.players = MultikeyDict()

        self.chunk_items = collections.defaultdict(list)
        self.entities = {}
        self.entity_ids = IDPool(1)

        self.update_loop = LoopingCall(self.update)
        self.update_loop.start(1.0 / constants.UPDATE_FPS, False)

        # server-related
        self.git_rev = base.get('git_rev', None)

        self.passwords = {}
        for k, v in base.passwords.iteritems():
            self.passwords[k.lower()] = v

        self.scripts = ScriptManager()
        for script in base.scripts:
            self.load_script(script)

        # time
        self.extra_elapsed_time = 0.0
        self.start_time = reactor.seconds()
        self.set_clock('12:00')

        # start listening
        self.listen_tcp(base.port, self)

    def buildProtocol(self, addr):
        # return None here to refuse the connection.
        # will use this later to hardban e.g. DoS
        ret = self.scripts.call('on_connection_attempt', address=addr).result
        if ret is False:
            return None
        elif ret is not None:
            return BanProtocol(ret)
        return CubeWorldConnection(self, addr)

    def remove_item(self, chunk, index):
        items = self.chunk_items[chunk]
        ret = items.pop(index)
        self.items_changed = True
        return ret.item_data

    def drop_item(self, item_data, pos):
        item = ChunkItemData()
        item.drop_time = 750
        # XXX provide sane values for these
        item.scale = 0.1
        item.rotation = 185.0
        item.something3 = item.something5 = item.something6 = 0
        item.pos = pos
        item.item_data = item_data
        self.chunk_items[get_chunk(pos)].append(item)
        self.items_changed = True

    def update(self):
        self.scripts.call('update')

        # entity updates
        for entity_id, entity in self.entities.iteritems():
            entity_packet.set_entity(entity, entity_id, entity.mask)
            entity.mask = 0
            self.broadcast_packet(entity_packet)
        self.broadcast_packet(update_finished_packet)

        # other updates
        update_packet = self.update_packet
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

        # time update
        time_packet.time = self.get_time()
        time_packet.day = self.get_day()
        self.broadcast_packet(time_packet)

    def send_chat(self, value):
        packet = ServerChatMessage()
        packet.entity_id = 0
        packet.value = value
        self.broadcast_packet(packet)

    def broadcast_packet(self, packet):
        data = write_packet(packet)
        for player in self.players.values():
            player.transport.write(data)

    # line/string formatting options based on config

    def format(self, value):
        format_dict = {'server_name': self.config.base.server_name}
        return value % format_dict

    def format_lines(self, value):
        lines = []
        for line in value:
            lines.append(self.format(line))
        return lines

    # script methods

    def load_script(self, name):
        try:
            mod = __import__('scripts.%s' % name, globals(), locals(), [name])
        except ImportError, e:
            traceback.print_exc(e)
            return None
        script = mod.get_class()(self)
        print 'Loaded script %r' % name
        return script

    def call_command(self, user, command, args):
        """
        Calls a command from an external interface, e.g. IRC, console
        """
        return self.scripts.call('on_command', user=user, command=command,
                                 args=args).result

    def get_mode(self):
        return self.scripts.call('get_mode').result

    # data store methods

    def load_data(self, name, default=None):
        path = './%s.dat' % name
        try:
            with open(path, 'rU') as fp:
                data = fp.read()
        except IOError:
            return default
        return eval(data)

    def save_data(self, name, value):
        path = './%s.dat' % name
        data = pprint.pformat(value, width=1)
        with open(path, 'w') as fp:
            fp.write(data)

    # time methods

    def set_clock(self, value):
        day = self.get_day()
        time = parse_clock(value)
        self.start_time = reactor.seconds()
        self.extra_elapsed_time = day * constants.MAX_TIME + time

    def get_elapsed_time(self):
        dt = reactor.seconds() - self.start_time
        dt *= self.config.base.time_modifier * constants.NORMAL_TIME_SPEED
        return dt * 1000 + self.extra_elapsed_time

    def get_time(self):
        return int(self.get_elapsed_time() % constants.MAX_TIME)

    def get_day(self):
        return int(self.get_elapsed_time() / constants.MAX_TIME)

    def get_clock(self):
        return get_clock_string(self.get_time())

    # stop/restart

    def stop(self, code=None):
        self.exit_code = code
        reactor.stop()

    # twisted wrappers

    def listen_udp(self, *arg, **kw):
        interface = self.config.base.network_interface
        return reactor.listenUDP(*arg, interface=interface, **kw)

    def listen_tcp(self, *arg, **kw):
        interface = self.config.base.network_interface
        return reactor.listenTCP(*arg, interface=interface, **kw)

    def connect_tcp(self, *arg, **kw):
        interface = self.config.base.network_interface
        return reactor.connectTCP(*arg, bindAddress=(interface, 0), **kw)


def main():
    # for py2exe
    if hasattr(sys, 'frozen'):
        path = os.path.dirname(
            unicode(sys.executable, sys.getfilesystemencoding()))
        sys.path.append(path)

    config = ConfigObject('./config')
    server = CubeWorldServer(config)

    print 'cuwo running on port %s' % config.base.port

    if config.base.profile_file is None:
        reactor.run()
    else:
        import cProfile
        cProfile.run('reactor.run()', filename=config.base.profile_file)

    sys.exit(server.exit_code)

if __name__ == '__main__':
    main()
