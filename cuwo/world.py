# Copyright (c) tobbebia and Jakky89 2013.
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


class World(Loader):
    def __init__(self, server):
        self.server = server
        self.chunks = {}
        self.static_entities = {}

    def get_chunk(self, pos):
        cpos = common.get_chunk(pos)
        chnk = self.chunks[cpos]
        if not chnk:
            chnk = Chunk(self, cpos)
            self.chunks[cpos] = chnk
        return chnk

    def get_entity(self, pos, max_distance=1):
        try:
            chnk = self.chunks[common.get_chunk(pos)]
            if not chnk:
                return None
            return chnk.get_entity(pos, max_distance)
        except:
            pass
        return None

    def get_static_entity(self, pos):
        try:
            return self.static_entities[pos]
        except:
            pass
        return None

    # for registering doors and such
    def register_static_entity(self, entity, pos):
        self.static_entities[pos] = entity
