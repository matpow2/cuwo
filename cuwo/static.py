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


class StaticEntityHeader(Loader):
    def read(self, reader):
        # memory header starts here (size 72)
        self.entity_type = reader.read_uint32()
        reader.skip(4)  # 64bit struct padding
        self.pos = reader.read_qvec3()
        self.something2 = reader.read_uint32()  # 0, 1, 2, 3
        self.something3 = reader.read_float()
        self.something4 = reader.read_float()
        self.something5 = reader.read_float()
        self.something6 = reader.read_uint8()
        reader.skip(3)
        self.something7 = reader.read_uint32()
        self.something8 = reader.read_uint32()
        reader.skip(4)  # 64bit padding
        # following may be 64bit number?
        self.something9 = reader.read_uint32()
        self.something10 = reader.read_uint32()

    def write(self, writer):
        writer.write_uint32(self.entity_type)
        writer.pad(4)
        writer.write_qvec3(self.pos)
        writer.write_uint32(self.something2)
        writer.write_float(self.something3)
        writer.write_float(self.something4)
        writer.write_float(self.something5)
        writer.write_uint8(self.something6)
        writer.pad(3)
        writer.write_uint32(self.something7)
        writer.write_uint32(self.something8)
        writer.pad(4)
        writer.write_uint32(self.something9)
        writer.write_uint32(self.something10)


class StaticEntity(Loader):
    def read(self, reader):
        pass

    def write(self, writer):
        pass