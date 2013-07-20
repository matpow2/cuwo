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


class CubModel(object):
    def __init__(self, reader=None):
        self.blocks = {}
        if reader is None:
            return
        self.x_size = reader.read_uint32()
        self.y_size = reader.read_uint32()
        self.z_size = reader.read_uint32()
        for z in xrange(self.z_size):
            for y in xrange(self.y_size):
                for x in xrange(self.x_size):
                    r = reader.read_uint8()
                    g = reader.read_uint8()
                    b = reader.read_uint8()
                    if r == 0 and g == 0 and b == 0:
                        continue
                    self.blocks[(x, y, z)] = (r, g, b)

    def write(self, writer):
        writer.write_uint32(self.x_size)
        writer.write_uint32(self.y_size)
        writer.write_uint32(self.z_size)
        for z in xrange(self.z_size):
            for y in xrange(self.y_size):
                for x in xrange(self.x_size):
                    r, g, b = self.blocks.get((x, y, z), (0, 0, 0))
                    writer.write_uint8(r)
                    writer.write_uint8(g)
                    writer.write_uint8(b)
