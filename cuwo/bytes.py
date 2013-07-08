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

"""
High-level byte read/writing and pack/unpacking from files and data
""" 

from cStringIO import StringIO
import struct

INT8 = struct.Struct('<b')
UINT8 = struct.Struct('<B')
INT32 = struct.Struct('<i')
UINT32 = struct.Struct('<I')
INT64 = struct.Struct('<q')
UINT64 = struct.Struct('<Q')

class OutOfData(struct.error):
    pass

class ByteWriter(object):
    def __init__(self, fp = None):
        if fp is None:
            fp = StringIO()
        self.fp = fp
        self.write = fp.write
        self.seek = fp.seek
        self.close = fp.close
        self.tell = fp.tell
        try:
            self.get = fp.getvalue
        except AttributeError:
            pass

    def pad(self, size):
        self.write('\x00' * size)

    def write_struct(self, format, value):
        self.write(format.pack(value))

    def write_int8(self, value):
        self.write_struct(INT8, value)

    def write_uint8(self, value):
        self.write_struct(UINT8, value)

    def write_int32(self, value):
        self.write_struct(INT32, value)

    def write_uint32(self, value):
        self.write_struct(UINT32, value)

    def write_int64(self, value):
        self.write_struct(INT64, value)

    def write_uint64(self, value):
        self.write_struct(UINT64, value)

class ByteReader(object):
    def __init__(self, data = None, fp = None):
        if data is not None:
            fp = StringIO(data)
        if fp is None:
            raise ValueError('need to specify data or fp')
        self.fp = fp
        self.seek = fp.seek
        self.close = fp.close
        self.tell = fp.tell

    def read(self, size = None):
        if size is None:
            return self.fp.read()
        data = self.fp.read(size)
        if len(data) < size:
            raise OutOfData()
        return data

    def skip(self, size):
        self.seek(self.tell() + size)

    def read_struct(self, format):
        value = format.unpack(self.read(format.size))
        if len(value) == 1:
            return value[0]
        return value

    def read_int8(self):
        return self.read_struct(INT8)

    def read_uint8(self):
        return self.read_struct(UINT8)

    def read_int32(self):
        return self.read_struct(INT32)

    def read_uint32(self):
        return self.read_struct(UINT32)

    def read_int64(self):
        return self.read_struct(INT64)

    def read_uint64(self):
        return self.read_struct(UINT64)