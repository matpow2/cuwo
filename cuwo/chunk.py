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
from cuwo.world import World
from cuwo import database
from cuwo import entity

import cuwo.common
import collections


class Chunk(Loader):
    def __init__(self, world, pos):
        self.pos = pos
        self.world = world
        self.entities = {}

    def get_entity(self, pos, max_distance):


    def register_entity(self, id, entity):
        self.entities[id] = entity

    def unregister_entity(self, id):
        try:
            return self.entities.pop(id)
        except KeyError:
            return None
