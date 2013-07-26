# Copyright (c) Julien Kross 2013.
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


from cuwo.types import MultikeyDict, AttributeSet
from cuwo.vector import Vector3
from cuwo import constants
from cuwo.chunk import Chunk
from cuwo import database
from cuwo import entity

import cuwo.common
import collections
import math


# Returns set of entities in range
def get_entities_in_range(entity_iter, ex, ey, ez, max_distance=3):
    if not entity_iter:
        return None
    max_distance = math.abs(max_distance)
    entity_set = set([])
    while True:
        try:
            etv = next(entity_iter)
            if not etv:
                continue
            etd = common.get_distance_3d(ex,
                                         ey,
                                         ez,
                                         etv.entity_data.x,
                                         etv.entity_data.y,
                                         etv.entity_data.z)
            if ( etd <= max_distance ):
                entity_set.add(etv)
        except StopIteration:
            break
        except:
            continue
    return entity_set

# Returns single closest entity in range
def get_closest_entity(entity_iter, ex, ey, ez, max_distance=3):
    if not entity_iter:
        return None
    max_distance = math.abs(max_distance)
    closest_dst = None
    closest_ent = None
    while True:
        try:
            etv = next(entity_iter)
            if not etv:
                continue
            etd = common.get_distance_3d(ex,
                                         ey,
                                         ez,
                                         etv.entity_data.x,
                                         etv.entity_data.y,
                                         etv.entity_data.z)
            if ( (not max_distance) or (etd <= max_distance) ) and ( (not closest_dst) or (not closest_ent) or (etd < closest_dst) ):
                closest_dst = etd
                closest_ent = etv
        except StopIteration:
            break
        except:
            continue
    return closest_ent

def get_scaled_xy(px, py, pscale):
    return list(math.floor( px / pscale ),
                math.floor( py / pscale ))

def get_scaled_min_max_xy(rx, ry, rdist, rscale):
    rx_center = rx / rscale
    ry_center = ry / rscale
    rdist_scaled = math.ceil( rdist / rscale )
    return list(math.floor( rx_center - rdist_scaled ),
                math.ceil(  rx_center + rdist_scaled ),
                math.floor( ry_center - rdist_scaled ),
                math.ceil(  ry_center + rdist_scaled ))


class Chunk(Loader):
    # chunk_pos = Vector2 of chunk position within sector
    def __init__(self, sector, cx, cy):
        self.sector = sector
        self.chunk_x = cx
        self.chunk_y = cy
        self.entities = set()

    def is_in_chunk(self, px, py):
        mmp = get_scaled_xy( px, py, constants.CHUNK_SCALE )
        if ( mmp[0] == self.chunk_x ) and ( mmp[1] == self.chunk_y ):
            return True
        return False

    # Returns single closest entity
    def get_entity(self, ex, ey, ez, max_distance=3):
        if len(self.entities) < 1:
            return None
        if is_in_chunk(ex, ey) is False:
            return None
        return get_closest_entity( iter(self.entities), ex, ey, ez, max_distance )

    # Returns set of entities in range
    def get_entities(self, ex, ey, ez, max_distance=3):
        if len(self.entities) < 1:
            return None
        if is_in_chunk(ex, ey) is False:
            return None
        return get_entities_in_range( iter(self.entities), ex, ey, ez, max_distance )

    def register_entity(self, entity):
        if not entity:
            return
        self.entities.add(entity)

    def unregister_entity(self, entity):
        if (not entity) or (len(self.entities) < 1):
            return None
        return self.entities.pop(entity)


class Sector(Loader):
    def __init__(self, world, sx, sy):
        self.world = world
        self.sector_x = sx
        self.sector_y = sy
        self.chunks = {}

    def is_in_sector(self, px, py):
        mmp = get_scaled_xy( px, py, constants.SECTOR_SCALE )
        if ( mmp[0] == self.sector_x ) and ( mmp[1] == self.sector_y ):
            return True
        return False

    def get_chunk_unscaled(self, cx, cy):
        chnk = None
        try:
            chnk = self.chunks[(cx, cy)]
        except:
            pass
        if not chnk:
            chnk = Chunk(self, cx, cy)
            self.chunks[(cx, cy)] = chnk
        return chnk

    def get_chunk_scaled(self, px, py):
        return self.get_chunk_unscaled( math.floor( px / constants.CHUNK_SCALE),
                                        math.floor( py / constants.CHUNK_SCALE))

    # 2 step targeting (WorldSector -> WorldChunks)
    # Returns entities within max_distance
    def get_entities(self, ex, ey, ez, max_distance=3):
        entitites = set()
        # scale down to chunks
        rngs = get_scaled_min_max_xy( ex, ey, max_distance, constants.CHUNK_SCALE )
        # loop through chunks in within scaled max_distance
        for cx in range(rngs[0], rngs[1]):
            for cy in range(rngs[2], rngs[3]):
                # get closest entities in current sector and add them to entities set
                nec = self.get_chunk_unscaled(cx, cy).get_entities( ex, ey, ez, max_distance )
                if not nec:
                    continue
                entities.update(nec)
        return entities

    # Returns single closest entity within max_distance
    def get_entity(self, ex, ey, ez, max_distance=3):
        entitites = set()
        # scale down to chunks
        rngs = get_scaled_min_max_xy( ex, ey, max_distance, constants.CHUNK_SCALE )
        # loop through sectors in within scaled max_distance
        for cx in range(rngs[0], rngs[1]):
            for cy in range(rngs[2], rngs[3]):
                # get closest entities in current sector and add them to entities set
                cen = self.get_chunk_unscaled(cx, cy).get_entity( ex, ey, ez, max_distance )
                if not cen:
                    continue
                entities.add(cen)
        if len(entities) < 1:
            return None
        return get_closest_entity( iter(entities), ex, ey, ez, max_distance )

    def unregister_entity(self, entity, ex, ey):
        return self.get_chunk_scaled(ex, ey).unregister_entity(entity, ex, ey)

    def register_entity_at(self, entity, ex, ey):
        self.get_chunk_scaled(ex, ey).register_entity(entity, ex, ey)

    def register_entity(self, entity):
        self.get_chunk_scaled(entity.entity_data.x, entity.entity_data.y).register_entity(entity)


class World(Loader):
    def __init__(self, server, name=None):
        self.server = server
        self.name = name
        self.sectors = {}

    # Get sector at sector position
    def get_sector_unscaled(self, sx, sy):
        secp = None
        try:
            secp = self.sectors[(sx, sy)]
        except:
            pass
        if not secp:
            secp = Sector(self, sx, sy)
            self.sectors[(sx, sy)] = secp
        return secp

    # Get sector at chunk position
    def get_chunk_sector(self, cx, cy):
        return self.get_sector_unscaled( math.floor( (cx * constants.CHUNK_SCALE) / constants.SECTOR_SCALE),
                                         math.floor( (cy * constants.CHUNK_SCALE) / constants.SECTOR_SCALE))

    # Get sector at x y position
    def get_sector_scaled(self, px, py):
        return self.get_sector_unscaled( math.floor( px / constants.SECTOR_SCALE),
                                         math.floor( py / constants.SECTOR_SCALE))

    # 3 step targeting (World -> WorldSectors -> WorldChunks)
    # Returns entities within max_distance
    def get_entities(self, ex, ey, ez, max_distance=3):
        entitites = set()
        # scale down to sectors
        rngs = get_scaled_min_max_xy( ex, ey, max_distance, constants.SECTOR_SCALE )
        # loop through sectors in within scaled max_distance
        for sx in range(rngs[0], rngs[1]):
            for sy in range(rngs[2], rngs[3]):
                # get closest entities in current sector and add them to entities set
                nes = self.get_sector_unscaled(sx, sy).get_entities( ex, ey, ez, max_distance )
                if not nes:
                    continue
                entities.update(nes)
        return entities

    # Returns single closest entity within max_distance
    def get_entity(self, ex, ey, ez, max_distance=3):
        entitites = set()
        # scale down to sectors
        rngs = get_scaled_min_max_xy( ex, ey, max_distance, constants.SECTOR_SCALE )
        # loop through sectors in within scaled max_distance
        for sx in range(rngs[0], rngs[1]):
            for sy in range(rngs[2], rngs[3]):
                # get closest entities in current sector and add them to entities set
                sen = self.get_sector_unscaled(sx, sy).get_entity( ex, ey, ez, max_distance )
                if not sen:
                    continue
                entities.add(sen)
        if len(entities) < 1:
            return None
        return get_closest_entity( iter(entities), ex, ey, ez, max_distance )

    def unregister_entity(self, entity, ex, ey):
        return self.get_sector_scaled(ex, ey).unregister_entity(entity, ex, ey)

    def register_entity_at(self, entity, ex, ey):
        self.get_sector_scaled(ex, ey).register_entity_at(entity, ex, ey)

    def register_entity(self, entity):
        self.get_sector_scaled(entity.entity_data.x, entity.entity_data.y).register_entity(entity)

    # unregisters from old chunk and registers in new
    # chunk only when moved from one chunk to another
    def move_entity(self, entity, old_x, old_y, new_x, new_y):
        old_chunk_pos = get_scaled_xy( old_x, old_y, constants.CHUNK_SCALE )
        new_chunk_pos = get_scaled_xy( new_x, new_y, constants.CHUNK_SCALE )
        if (old_chunk_pos[0] == new_chunk_pos[0]) or (old_chunk_pos[1] == new_chunk_pos[1]):
            return
        self.unregister_entity(entity, old_x, old_y)
        self.register_entity(entity, new_x, new_y)
