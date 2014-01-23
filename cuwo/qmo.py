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


def read_string(reader):
    return reader.read(reader.read_uint8())


def write_string(writer, value):
    writer.write_uint8(len(value))
    writer.write(value)

MAGIC = 'QBCL\x20'
VERSION = '1.02'


class QubicleModel(object):
    def __init__(self, reader=None):
        self.blocks = {}
        if reader is None:
            self.x_size = self.y_size = self.z_size = 0
            self.name = 'Empty'
            self.x_offset = self.y_offset = self.z_offset = 0
            self.hidden = 0
            return
        self.x_size = reader.read_uint32()
        self.y_size = reader.read_uint32()
        self.z_size = reader.read_uint32()
        self.name = read_string(reader)
        self.x_offset = reader.read_int32()
        self.y_offset = reader.read_int32()
        self.z_offset = reader.read_int32()
        self.hidden = reader.read_uint8()
        rle_count = reader.read_uint32()
        i = 0
        while rle_count:
            value = reader.read_uint32()
            rle_count -= 1
            if value == 2:  # repetition
                times = reader.read_uint32()
                color = reader.read_uint32()
                rle_count -= 2
            else:
                times = 1
                color = value
            if color & 0xFF000000 == 0:
                i += times
                continue
            r = int(color & 0x0000FF)
            g = int((color & 0x00FF00) >> 8)
            b = int((color & 0xFF0000) >> 16)
            for _ in xrange(times):
                x = i / (self.y_size * self.z_size)
                y = (i % (self.y_size * self.z_size)) / self.z_size
                z = i % self.z_size
                self.blocks[(int(x), int(y), int(z))] = (r, g, b)
                i += 1

    def write(self, writer):
        writer.write_uint32(self.x_size)
        writer.write_uint32(self.y_size)
        writer.write_uint32(self.z_size)
        write_string(writer, self.name)
        writer.write_int32(self.x_offset)
        writer.write_int32(self.y_offset)
        writer.write_int32(self.z_offset)
        writer.write_uint8(self.hidden)
        writer.write_uint32(self.x_size * self.y_size * self.z_size)
        for x in xrange(self.x_size):
            for y in xrange(self.y_size):
                for z in xrange(self.z_size):
                    c = self.blocks.get((x, y, z), None)
                    if c is None:
                        writer.write_uint32(0)
                        continue
                    r, g, b = c
                    c2 = r | (g << 8) | (b << 16) | (0x7F << 24)
                    writer.write_uint32(c2)


class QubicleFile(object):
    def __init__(self, reader=None):
        self.models = []
        if reader is None:
            return
        if read_string(reader) != MAGIC:
            raise NotImplementedError('invalid magic')
        elif read_string(reader) != VERSION:
            raise NotImplementedError('unsupported version')
        for _ in xrange(reader.read_uint32()):
            self.models.append(QubicleModel(reader))
        self.junk = reader.read()
        if len(self.junk) != 108:
            raise NotImplementedError

    def write(self, writer):
        write_string(writer, MAGIC)
        write_string(writer, VERSION)
        writer.write_uint32(len(self.models))
        for model in self.models:
            model.write(writer)
        writer.write('\x00' * 108)
