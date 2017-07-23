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
Static entity implementation
"""

from cuwo.loader import Loader
from cuwo import strings
from cuwo.tgen_wrap import WrapStaticEntityHeader


ORIENT_SOUTH = 0
ORIENT_EAST = 1
ORIENT_NORTH = 2
ORIENT_WEST = 3


SIT_ENTITIES = {
    'SleepingMat', 'Stool', 'Bench', 'Bed'
}


OPEN_ENTITIES = {
    'Window', 'CastleWindow', 'Door', 'BigDoor', 'Chest'
}


DYNAMIC_ENTITIES = SIT_ENTITIES | OPEN_ENTITIES


class StaticEntityHeader(WrapStaticEntityHeader):
    def is_dynamic(self):
        return self.get_type() in DYNAMIC_ENTITIES

    def get_type(self):
        return strings.STATIC_NAMES[self.entity_type]

    def set_type(self, name):
        self.entity_type = strings.STATIC_IDS[name]


class StaticEntityPacket(Loader):
    def read(self, reader):
        self.chunk_x = reader.read_uint32()
        self.chunk_y = reader.read_uint32()
        self.entity_id = reader.read_uint32()
        reader.skip(4)
        self.header = StaticEntityHeader()
        self.header.read(reader)

    def write(self, writer):
        writer.write_uint32(self.chunk_x)
        writer.write_uint32(self.chunk_y)
        writer.write_uint32(self.entity_id)
        writer.pad(4)
        self.header.write(writer)
