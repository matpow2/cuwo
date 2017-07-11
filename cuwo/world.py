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

"""
World manager
"""

from cuwo import entity as entitydata
from cuwo import static
from cuwo.common import get_item_hp, get_max_xp, get_chunk
from cuwo.types import IDPool
from cuwo import constants
from cuwo import strings
from cuwo.vector import Vector3
from cuwo import tgen

import os
from queue import Queue
import asyncio
import math


class Entity(entitydata.EntityData):
    def __init__(self, world, entity_id=None):
        super().__init__()

        if entity_id is None:
            entity_id = world.entity_ids.pop()
            self.static_id = False
        else:
            self.static_id = True
        self.entity_id = entity_id

        world.entities[entity_id] = self
        self.world = world

    def reset(self):
        self.set_hp()
        self.mask = constants.FULL_MASK

    def set_hp(self, value=None):
        self.hp = value or self.get_max_hp()
        self.mask |= entitydata.HP_FLAG

    def set_position(self, pos):
        self.pos = pos
        self.mask |= entitydata.POS_FLAG

    def get_type(self):
        return strings.ENTITY_NAMES[self.entity_type]

    def set_type(self, name):
        if name is None:
            self.entity_type = 0xFFFFFFFF
        else:
            self.entity_type = strings.ENTITY_IDS[name]
        self.mask |= entitydata.TYPE_FLAG

    def get_ray_hit(self):
        return self.pos + self.ray_hit * constants.BLOCK_SCALE

    def get_look_dir(self):
        yaw = math.radians(self.body_yaw + 90)
        pitch = math.radians(self.body_pitch)
        x = math.cos(yaw) * math.cos(pitch)
        y = math.sin(yaw) * math.cos(pitch)
        z = math.sin(pitch)
        return Vector3(x, y, z)

    def get_max_hp(self):
        hp = self.get_base_hp()
        hp += get_item_hp(self.equipment[6])
        hp += get_item_hp(self.equipment[7])
        hp += get_item_hp(self.equipment[2])
        hp += get_item_hp(self.equipment[3])
        hp += get_item_hp(self.equipment[4])
        hp += get_item_hp(self.equipment[5])
        return hp

    def get_max_xp(self):
        return get_max_xp(self.level)

    def get_base_hp(self):
        level_health = 2 ** ((1 - (1 / (0.05 * (self.level - 1) + 1))) * 3)

        if self.hostile_type == 0:
            health = level_health * 2 * self.max_hp_multiplier
        else:
            power_health = 2 ** (self.power_base * 0.25)
            health = level_health * power_health * self.max_hp_multiplier

        if self.class_type == 1:
            health *= 1.30
            if self.specialization == 1:
                health *= 1.25

        elif self.class_type == 2:
            health *= 1.10

        elif self.class_type == 4:
            health *= 1.20

        return health

    def destroy(self):
        del self.world.entities[self.entity_id]
        if not self.static_id:
            self.world.entity_ids.put_back(self.entity_id)


class StaticEntity:
    open_time = None

    def __init__(self, entity_id, header, chunk):
        self.header = header
        self.world = chunk.world

        name = header.get_type()

        if name in static.SIT_ENTITIES:
            self.interact = self.interact_sit
        elif name in static.OPEN_ENTITIES:
            self.interact = self.interact_open
            header.closed = True

    def interact(self, player):
        pass

    def interact_open(self, player):
        offset = 1.0 - self.get_time_offset()
        self.open_time = self.world.loop.time() - offset
        self.header.closed = not self.header.closed
        self.update()

    def interact_sit(self, player):
        self.header.user_id = player.entity_id
        player.mount(self)
        self.update()

    def on_unmount(self, player):
        self.header.user_id = 0
        self.update()

    def get_time_offset(self):
        if self.open_time is None:
            return 1.0
        t = self.world.loop.time() - self.open_time
        return min(1.0, t)

    def update(self):
        self.header.time_offset = int(self.get_time_offset() * 1e3)


class Chunk:
    data = None

    def __init__(self, world, pos):
        self.world = world
        self.pos = pos
        self.items = []
        self.static_entities = {}

        if not world.use_tgen:
            return

        f = world.get_data(pos)
        f.add_done_callback(self.on_chunk)

    def on_chunk(self, f):
        self.data = f.result()

        self.items.extend(self.data.items)
        self.data.items = []

        for entity_id, data in enumerate(self.data.static_entities):
            header = data.header
            new_entity = self.world.static_entity_class(entity_id, header,
                                                        self)
            self.static_entities[entity_id] = new_entity

        if self.world.use_entities:
            for data in self.data.dynamic_entities:
                entity = self.world.create_entity(data.entity_id)
                data.set_entity(entity)
                entity.reset()

        self.update()

    def add_item(self, item):
        self.items.append(item)
        self.update()

    def remove_item(self, index):
        ret = self.items.pop(index).item_data
        self.update()
        return ret

    def get_entity(self, entity_id):
        return self.static_entities[entity_id]

    def on_post_update(self):
        for item in self.items:
            item.drop_time = 0

    def update(self):
        pass


class World:
    data_path = './data/'
    chunk_class = Chunk
    static_entity_class = StaticEntity
    entity_class = Entity

    def __init__(self, loop, seed, use_tgen=True, use_entities=True):
        if use_tgen:
            for name in ('data1.db', 'data4.db', 'Server.exe'):
                path = os.path.join(self.data_path, name)
                if os.path.isfile(path):
                    continue
                path = os.path.abspath(path)
                raise FileNotFoundError('Missing asset file %r' % path)

        self.loop = loop
        self.use_tgen = use_tgen
        self.use_entities = use_entities
        self.chunks = {}
        self.entities = {}
        self.entity_ids = IDPool(1)

        if not self.use_tgen:
            return

        self.gen_queue = Queue()
        self.cache = {}
        loop.run_in_executor(None, self.run_gen, seed)

    def create_entity(self, entity_id=None):
        return self.entity_class(self, entity_id)

    def update(self):
        pass

    def stop(self):
        self.gen_queue.put(None)

    def get_chunk(self, pos):
        try:
            return self.chunks[pos]
        except KeyError:
            pass
        chunk = self.chunk_class(self, pos)
        self.chunks[pos] = chunk
        return chunk

    def get_data(self, pos):
        f = asyncio.Future()
        self.gen_queue.put((pos, f), False)
        return f

    def get_height(self, pos):
        chunk_pos = get_chunk(pos)
        try:
            chunk = self.chunks[chunk_pos]
        except KeyError:
            return None
        if chunk.data is None:
            return None
        pos -= chunk_pos * constants.CHUNK_SCALE
        pos //= constants.BLOCK_SCALE
        return chunk.data.get_height(pos.x, pos.y) * constants.BLOCK_SCALE

    def run_gen(self, seed):
        tgen.initialize(seed, self.data_path)
        while True:
            data = self.gen_queue.get()
            if data is None:
                break
            pos, f = data
            res = tgen.generate(*pos)
            self.loop.call_soon_threadsafe(f.set_result, res)
