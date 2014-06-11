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

from cuwo.loader import Loader
from cuwo.defs import STATIC_NAMES


ORIENT_SOUTH = 0
ORIENT_EAST = 1
ORIENT_NORTH = 2
ORIENT_WEST = 3


class StaticEntityHeader(Loader):
    def read(self, reader):
        # memory header starts here (size 72)
        self.entity_type = reader.read_uint32()
        reader.skip(4)  # 64bit struct padding
        self.pos = reader.read_qvec3()
        self.orientation = reader.read_uint32()
        self.size = reader.read_vec3()
        self.closed = reader.read_uint8()
        reader.skip(3)
        # time offset to use for e.g. opening doors
        # seems to be in ms, for windows/doors goes from 0-1000
        self.time_offset = reader.read_uint32()
        self.something8 = reader.read_uint32()
        reader.skip(4)  # 64bit padding
        # the entity which is using this static entity
        self.user_id = reader.read_uint64()

    def get_type_name(self):
        return STATIC_NAMES[self.entity_type]

    def write(self, writer):
        writer.write_uint32(self.entity_type)
        writer.pad(4)
        writer.write_qvec3(self.pos)
        writer.write_uint32(self.orientation)
        writer.write_vec3(self.size)
        writer.write_uint8(self.closed)
        writer.pad(3)
        writer.write_uint32(self.time_offset)
        writer.write_uint32(self.something8)
        writer.pad(4)
        writer.write_uint64(self.user_id)


class StaticEntity(Loader):
    def read(self, reader):
        pass

    def write(self, writer):
        pass