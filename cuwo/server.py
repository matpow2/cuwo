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

from cuwo import packet as packets
from cuwo.types import MultikeyDict, AttributeSet
from cuwo import constants
from cuwo.common import (get_clock_string, parse_clock, parse_command,
                         get_chunk, filter_string, iterate_packet_list)
from cuwo.script import ScriptManager
from cuwo.config import ConfigObject
from cuwo import tgen_wrap as entitydata
from cuwo import static
from cuwo.loop import LoopingCall
from cuwo import world
from cuwo.vector import vec3
import faulthandler

import os
import sys
import pprint
import traceback
import asyncio
import signal
import socket
import importlib

# initialize packet instances for sending
join_packet = packets.JoinPacket()
seed_packet = packets.SeedData()
chat_packet = packets.ServerChatMessage()
entity_packet = packets.EntityUpdate()
update_finished_packet = packets.UpdateFinished()
time_packet = packets.CurrentTime()
mismatch_packet = packets.ServerMismatch()
server_full_packet = packets.ServerFull()
extra_server_update = packets.ServerUpdate()


class Entity(world.Entity):
    connection = None

    def kill(self):
        self.damage(self.hp + 100.0)

    def damage(self, damage=0, stun_duration=0):
        packet = packets.HitPacket()
        packet.entity_id = self.entity_id
        packet.target_id = self.entity_id
        packet.hit_type = packets.HIT_NORMAL
        packet.damage = damage
        packet.critical = 1
        packet.stun_duration = stun_duration
        packet.something8 = 0
        packet.pos = self.pos
        packet.hit_dir = vec3()
        packet.skill_hit = 0
        packet.show_light = 0
        self.world.server.update_packet.player_hits.append(packet)
        if self.hp <= 0:
            return
        self.hp -= damage
        if self.connection and self.hp <= 0:
            self.connection.scripts.call('on_die', killer=None)


class StaticEntity(world.StaticEntity):
    changed = False
    def __init__(self, entity_id, header, chunk):
        super().__init__(entity_id, header, chunk)
        self.packet = static.StaticEntityPacket()
        self.packet.header = header
        self.packet.entity_id = entity_id
        self.packet.chunk_x, self.packet.chunk_y = chunk.pos

    def update(self):
        super().update()
        self.changed = True
        update_packet = self.world.server.update_packet
        update_packet.static_entities.append(self.packet)


class Chunk(world.Chunk):
    def update(self):
        self.world.server.updated_chunks.add(self)

    def on_update(self, update_packet):
        item_list = packets.ChunkItems()
        item_list.chunk_x, item_list.chunk_y = self.pos
        item_list.items = self.items
        update_packet.chunk_items.append(item_list)


class World(world.World):
    chunk_class = Chunk
    entity_class = Entity
    static_entity_class = StaticEntity

    def __init__(self, server, *arg, **kw):
        super().__init__(*arg, **kw)
        self.server = server


class CubeWorldConnection(asyncio.Protocol):
    """
    Protocol used for players
    """
    has_joined = False
    entity_id = None
    entity = None
    disconnected = False
    scripts = None
    chunk = None
    mounted_entity = None

    def __init__(self, server):
        self.server = server
        self.world = server.world
        self.loop = server.loop

    def connection_made(self, transport):
        self.transport = transport
        self.address = transport.get_extra_info('peername')

        accept = self.server.scripts.call('on_connection_attempt',
                                          address=self.address).result
        # hardban
        if accept is False:
            self.transport.abort()
            self.disconnected = True
            return

        # enable TCP_NODELAY
        sock = transport.get_extra_info('socket')
        sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, True)

        # ban with message
        if accept is not None:
            join_packet.entity_id = 1
            self.send_packet(join_packet)

            def disconnect():
                chat_packet.entity_id = 0
                chat_packet.value = accept
                self.send_packet(chat_packet)
                self.transport.close()

            # need to add a small delay, since the client will otherwise
            # ignore our chat message
            self.loop.call_later(0.1, disconnect)
            self.disconnected = True
            self.transport.pause_reading()
            return

        server = self.server
        if len(server.connections) >= server.config.base.max_players:
            self.send_packet(server_full_packet)
            self.disconnect()
            return

        self.packet_handlers = {
            packets.ClientVersion.packet_id: self.on_version_packet,
            packets.EntityUpdate.packet_id: self.on_entity_packet,
            packets.ClientChatMessage.packet_id: self.on_chat_packet,
            packets.InteractPacket.packet_id: self.on_interact_packet,
            packets.HitPacket.packet_id: self.on_hit_packet,
            packets.ShootPacket.packet_id: self.on_shoot_packet,
            packets.PassivePacket.packet_id: self.on_passive_packet,
            packets.ChunkDiscovered.packet_id: self.on_discover_packet
        }

        self.packet_handler = packets.PacketHandler(packets.CS_PACKETS,
                                                    self.on_packet)

        server.connections.add(self)
        self.rights = AttributeSet()

        self.scripts = ScriptManager()
        server.scripts.call('on_new_connection', connection=self)

    def data_received(self, data):
        self.packet_handler.feed(data)

    def is_closing(self):
        return self.disconnected or self.transport.is_closing()

    def disconnect(self, reason=None):
        if self.is_closing():
            return
        self.transport.close()
        self.connection_lost(reason)

    def connection_lost(self, reason):
        if self.disconnected:
            return
        self.disconnected = True
        self.server.connections.discard(self)
        if self.has_joined:
            del self.server.players[self]
            print('Player %s left' % self.name)
        if self.entity is not None:
            self.entity.destroy()
        if self.entity_id is not None:
            # need to handle this here, since the player may not have an
            # entity yet
            self.world.entity_ids.put_back(self.entity_id)
        if self.scripts is not None:
            self.scripts.unload()

    # packet methods

    def send_data(self, data):
        if self.is_closing():
            return
        self.transport.write(data)

    def send_packet(self, packet):
        if self.is_closing():
            return
        self.transport.write(packets.write_packet(packet))

    def on_packet(self, packet):
        if self.is_closing():
            return
        if packet is None:
            self.on_invalid_packet('data')
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
        self.entity_id = self.world.entity_ids.pop()
        join_packet.entity_id = self.entity_id
        self.send_packet(join_packet)
        seed_packet.seed = self.server.config.base.seed
        self.send_packet(seed_packet)

    def on_entity_packet(self, packet):
        if self.entity is None:
            self.entity = self.world.create_entity(self.entity_id)
            self.entity.connection = self

        self.old_entity = self.entity.copy()
        mask = packet.update_entity(self.entity)
        if not self.has_joined and entitydata.is_name_set(mask):
            self.on_join()
            return

        self.scripts.call('on_entity_update', mask=mask)
        # XXX clean this up
        if entitydata.is_pos_set(mask):
            self.on_pos_update()
        if entitydata.is_vel_set(mask):
            if self.mounted_entity:
                self.mount(None)
        if entitydata.is_mode_set(mask):
            self.scripts.call('on_mode_update')
        if entitydata.is_class_set(mask):
            self.scripts.call('on_class_update')
        if entitydata.is_name_set(mask):
            self.on_name_update()
        if entitydata.is_multiplier_set(mask):
            self.scripts.call('on_multiplier_update')
        if entitydata.is_level_set(mask):
            self.scripts.call('on_level_update')
        if entitydata.is_equipment_set(mask):
            self.scripts.call('on_equipment_update')
        if entitydata.is_skill_set(mask):
            self.scripts.call('on_skill_update')
        if entitydata.is_appearance_set(mask):
            self.scripts.call('on_appearance_update')
        if entitydata.is_charged_mp_set(mask):
            self.scripts.call('on_charged_mp_update')
        if entitydata.is_flags_set(mask):
            self.scripts.call('on_flags_update')
        if entitydata.is_consumable_set(mask):
            self.scripts.call('on_consumable_update')

    def mount(self, entity):
        if self.mounted_entity:
            self.mounted_entity.on_unmount(self)
        self.mounted_entity = entity

    def on_name_update(self):
        if self.old_entity.name:
            print(self.old_entity.name, 'changed name to', self.entity.name)
        self.scripts.call('on_name_update')

    def on_pos_update(self):
        try:
            chunk_pos = get_chunk(self.position)
        except ValueError:
            self.on_invalid_packet('position')
            return
        if not self.chunk or chunk_pos != self.chunk.pos:
            self.chunk = self.world.get_chunk(chunk_pos)
        self.scripts.call('on_pos_update')

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
        print('%s: %s' % (self.name, message))

    def on_interact_packet(self, packet):
        interact_type = packet.interact_type
        item = packet.item_data
        if interact_type == packets.INTERACT_DROP:
            pos = self.position.copy()
            pos.z -= constants.BLOCK_SCALE
            if self.scripts.call('on_drop', item=item,
                                 pos=pos).result is False:
                return
            self.server.drop_item(packet.item_data, pos)
        elif interact_type == packets.INTERACT_PICKUP:
            chunk = self.world.get_chunk((packet.chunk_x, packet.chunk_y))
            try:
                item = chunk.remove_item(packet.item_index)
            except IndexError:
                return
            self.give_item(item)
        elif interact_type == packets.INTERACT_NORMAL:
            chunk = self.world.get_chunk((packet.chunk_x, packet.chunk_y))
            try:
                chunk.get_entity(packet.item_index).interact(self)
            except KeyError:
                return

    def on_hit_packet(self, packet):
        try:
            target = self.world.entities[packet.target_id]
        except KeyError:
            return

        if self.scripts.call('on_hit',
                             target=target,
                             packet=packet).result is False:
            return

        self.server.update_packet.player_hits.append(packet)
        if target.is_tgen:
            self.world.add_hit(packet)
            return
        if target.hp <= 0:
            return
        target.hp -= packet.damage
        if target.hp > 0:
            return
        self.scripts.call('on_kill', target=target)
        if not target.connection:
            return
        target.connection.scripts.call('on_die', killer=self.entity)

    def on_shoot_packet(self, packet):
        self.server.update_packet.shoot_actions.append(packet)

    def on_passive_packet(self, packet):
        self.server.update_packet.passive_actions.append(packet)

    def on_discover_packet(self, packet):
        # update static entities on client
        extra_server_update.reset()
        pos = (packet.x, packet.y)
        if pos in self.server.world.chunks:
            chunk = self.server.world.chunks[pos]
            chunk.on_update(extra_server_update)
            for static in chunk.static_entities.values():
                if not static.changed:
                    continue
                extra_server_update.static_entities.append(static.packet)
        self.send_packet(extra_server_update)

    # handlers

    def on_invalid_packet(self, message):
        name = self.name or self.entity_id or self.address[0]
        print('Received invalid %r data from %r, '
              'disconnecting' % (message, name))
        self.packet_handler.stop()
        self.disconnect()

    def on_join(self):
        if self.scripts.call('on_join').result is False:
            return

        print('Player %s joined' % self.name)
        for entity_id, entity in self.server.world.entities.items():
            entity_packet.set_entity(entity, entity_id)
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

    def play_sound(self, name, pos=None, pitch=1.0, volume=1.0):
        extra_server_update.reset()
        sound = packets.SoundAction()
        sound.set_name(name)
        if pos is None:
            pos = self.entity.pos
        sound.pos = pos
        sound.pitch = pitch
        sound.volume = volume
        extra_server_update.sound_actions.append(sound)
        self.send_packet(extra_server_update)

    def send_chat(self, value):
        chat_packet.entity_id = 0
        chat_packet.value = value
        self.send_packet(chat_packet)

    def give_item(self, item):
        action = packets.PickupAction()
        action.entity_id = self.entity_id
        action.item_data = item
        self.server.update_packet.pickups.append(action)

    def send_lines(self, lines):
        current_time = 0
        for line in lines:
            self.loop.call_later(current_time, self.send_chat, line)
            current_time += 2

    def kick(self, reason=None):
        postfix = ': %s' % reason if reason is not None else ''
        self.send_chat('You have been kicked%s' % postfix)
        self.server.send_chat('%s has been kicked%s' % (self.name, postfix))
        self.disconnect()

    # convenience methods

    @property
    def position(self):
        if self.entity is None:
            return None
        return self.entity.pos

    @property
    def name(self):
        if self.entity is None:
            return None
        return self.entity.name


class CubeWorldServer:
    exit_code = None
    world = None

    def __init__(self, loop, config):
        self.loop = loop
        self.config = config
        base = config.base

        # game-related
        self.update_packet = packets.ServerUpdate()
        self.update_packet.reset()

        self.connections = set()
        self.players = MultikeyDict()

        self.updated_chunks = set()

        self.update_loop = LoopingCall(self.update)
        self.update_loop.start(1.0 / base.update_fps, now=False)

        # world
        self.world = World(self, self.loop, base.seed,
                           use_tgen=base.use_tgen,
                           use_entities=base.use_entities,
                           chunk_retire_time=base.chunk_retire_time)
        if base.world_debug_file is not None:
            debug_fp = open(base.world_debug_file, 'wb')
            self.world.set_debug(debug_fp)

        # server-related
        self.git_rev = base.get('git_rev', None)

        self.passwords = {}
        for k, v in base.passwords.items():
            self.passwords[k.lower()] = v

        self.scripts = ScriptManager()
        for script in base.scripts:
            self.load_script(script)

        # time
        self.extra_elapsed_time = 0.0
        self.start_time = loop.time()
        self.set_clock('12:00')

        # start listening
        self.loop.set_exception_handler(self.exception_handler)
        self.loop.create_task(self.create_server(self.build_protocol,
                                                 port=base.port,
                                                 family=socket.AF_INET))

    def exception_handler(self, loop, context):
        exception = context.get('exception')
        if isinstance(exception, TimeoutError):
            pass
        else:
            loop.default_exception_handler(context)

    def build_protocol(self):
        return CubeWorldConnection(self)

    def drop_item(self, item_data, pos):
        item = packets.ChunkItemData()
        item.drop_time = 750
        # XXX provide sane values for these
        item.scale = 0.1
        item.rotation = 185.0
        item.something3 = item.something5 = item.something6 = 0
        item.pos = pos
        item.item_data = item_data
        self.world.get_chunk(get_chunk(pos)).add_item(item)

    def add_packet_list(self, items, l, size):
        for item in iterate_packet_list(l):
            items.append(item.data)

    def handle_tgen_packets(self, packets):
        if packets is None:
            return

        p = self.update_packet
        self.add_packet_list(p.player_hits, packets.player_hits,
                             packets.player_hits_size)
        self.add_packet_list(p.sound_actions, packets.sound_actions,
                             packets.sound_actions_size)
        self.add_packet_list(p.particles, packets.particles,
                             packets.particles_size)
        self.add_packet_list(p.block_actions, packets.block_actions,
                             packets.block_actions_size)
        self.add_packet_list(p.shoot_actions, packets.shoot_packets,
                             packets.shoot_packets_size)
        self.add_packet_list(p.kill_actions, packets.kill_actions,
                             packets.kill_actions_size)
        self.add_packet_list(p.damage_actions, packets.damage_actions,
                             packets.damage_actions_size)
        self.add_packet_list(p.passive_actions, packets.passive_packets,
                             packets.passive_packets_size)
        self.add_packet_list(p.missions, packets.missions,
                             packets.missions_size)

    def update(self):
        self.scripts.call('update')

        for passive in self.update_packet.passive_actions:
            self.world.add_passive(passive)
        out_packets = self.world.update(self.update_loop.dt)
        self.handle_tgen_packets(out_packets)

        for entity_id, entity in self.world.entities.items():
            entity_packet.set_entity(entity, entity_id, entity.get_mask())
            entity.reset_mask()
            self.broadcast_packet(entity_packet)
        self.broadcast_packet(update_finished_packet)

        # other updates
        update_packet = self.update_packet
        for chunk in self.updated_chunks:
            chunk.on_update(update_packet)
        self.broadcast_packet(update_packet)
        update_packet.reset()

        # reset drop times
        for chunk in self.updated_chunks:
            chunk.on_post_update()

        self.updated_chunks.clear()

        # time update
        time_packet.time = self.get_time()
        time_packet.day = self.get_day()
        self.broadcast_packet(time_packet)

    def send_chat(self, value):
        chat_packet.entity_id = 0
        chat_packet.value = value
        self.broadcast_packet(chat_packet)

    def play_sound(self, name, pos=None, pitch=1.0, volume=1.0):
        sound = packets.SoundAction()
        sound.set_name(name)
        sound.pitch = pitch
        sound.volume = volume

        if pos is not None:
            sound.pos = pos
            self.update_packet.sound_action.append(sound)
            return

        extra_server_update.reset()

        for player in self.players.values():
            sound.pos = player.entity.pos
            extra_server_update.sound_actions = [sound]
            player.send_packet(extra_server_update)

    def broadcast_packet(self, packet):
        data = packets.write_packet(packet)
        for player in self.players.values():
            player.send_data(data)

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

    def load_script(self, name, update=False):
        try:
            return self.scripts[name]
        except KeyError:
            pass
        try:
            mod = __import__('scripts.%s' % name, globals(), locals(), [name])
            if update:
                importlib.reload(mod)
        except ImportError as e:
            traceback.print_exc()
            return None
        script = mod.get_class()(self)
        print('Loaded script %r' % name)
        return script

    def unload_script(self, name):
        try:
            self.scripts[name].unload()
        except KeyError:
            return False
        print('Unloaded script %r' % name)
        return True

    def call_command(self, user, command, args):
        """
        Calls a command from an external interface, e.g. IRC, console
        """
        return self.scripts.call('on_command', user=user, command=command,
                                 args=args).result

    def get_mode(self):
        return self.scripts.call('get_mode').result

    # command convenience methods (for /help)

    def get_commands(self):
        for script in self.scripts.get():
            if script.commands is None:
                continue
            for command in script.commands.values():
                yield command

    def get_command(self, name):
        for script in self.scripts.get():
            if script.commands is None:
                continue
            name = script.aliases.get(name, name)
            command = script.commands.get(name, None)
            if command:
                return command

    # binary data store methods

    def load_data(self, name, default=None):
        path = './save/%s.dat' % name
        try:
            with open(path, 'rU') as fp:
                data = fp.read()
        except IOError:
            return default
        return eval(data)

    def save_data(self, name, value):
        path = './save/%s.dat' % name
        data = pprint.pformat(value, width=1)
        with open(path, 'w') as fp:
            fp.write(data)

    # time methods

    def set_clock(self, value):
        day = self.get_day()
        time = parse_clock(value)
        self.start_time = self.loop.time()
        self.extra_elapsed_time = day * constants.MAX_TIME + time

    def get_elapsed_time(self):
        dt = self.loop.time() - self.start_time
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
        print('Stopping...')
        self.exit_code = code
        if self.world:
            self.world.stop()
        self.scripts.unload()
        self.loop.stop()

    # asyncio wrappers

    def get_interface(self):
        return self.config.base.network_interface

    def create_datagram_endpoint(self, *arg, port=0, **kw):
        host = self.get_interface()
        addr = (host, port)
        return self.loop.create_datagram_endpoint(*arg, local_addr=addr, **kw)

    def create_server(self, *arg, **kw):
        return self.loop.create_server(*arg, host=self.get_interface(), **kw)

    def connect_connection(self, *arg, **kw):
        host = self.get_interface()
        return self.loop.create_connection(*arg, local_addr=(host, 0), **kw)


def main():
    # make sure we enable crash logging as early as possible
    faulthandler.enable()

    # for py2exe
    if hasattr(sys, 'frozen'):
        path = os.path.dirname(sys.executable)
        root = os.path.abspath(os.path.join(path, '..'))
        sys.path.append(root)

    config = ConfigObject('./config')

    if sys.platform == 'win32':
        from cuwo.win32 import WindowsEventLoop
        loop = WindowsEventLoop()
        loop.set_clock_resolution(1 * 1e-3)
        asyncio.set_event_loop(loop)
    else:
        try:
            import uvloop
            asyncio.set_event_loop_policy(uvloop.EventLoopPolicy())
            print('(using uvloop)')
        except ImportError:
            pass
        loop = asyncio.get_event_loop()

    if config.base.use_tgen:
        from cuwo.download import download_dependencies
        download_dependencies()

    server = CubeWorldServer(loop, config)

    loop.add_signal_handler(signal.SIGINT, server.stop)

    print('cuwo running on port %s' % config.base.port)

    if config.base.profile_file is None:
        loop.run_forever()
    else:
        import cProfile
        cProfile.run('loop.run_forever()', filename=config.base.profile_file)

    sys.exit(server.exit_code)

if __name__ == '__main__':
    main()
