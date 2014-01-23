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
High-level byte read/writing and pack/unpacking from files and data
"""

from cuwo.vector import Vector3
from cuwo.exceptions import OutOfData
from cuwo.common import filter_string
cimport cython
from libc.limits cimport UINT_MAX


cdef extern from "bytes_c.cpp":
    # read
    char read_int8(char * data)
    unsigned char read_uint8(char * data)
    short read_int16(char * data)
    unsigned short read_uint16(char * data)
    int read_int32(char * data)
    unsigned int read_uint32(char * data)
    int64_t read_int64(char * data)
    uint64_t read_uint64(char * data)
    double read_float(char * data)
    double read_double(char * data)
    char * read_string(char * data)

    # write
    void * create_write_stream()
    void delete_write_stream(void * stream)
    void write_int8(void * stream, char value)
    void write_uint8(void * stream, unsigned char value)
    void write_int16(void * stream, short value)
    void write_uint16(void * stream, unsigned short value)
    void write_int32(void * stream, int value)
    void write_uint32(void * stream, unsigned int value)
    void write_int64(void * stream, int64_t)
    void write_uint64(void * stream, uint64_t)
    void write_float(void * stream, double value)
    void write_double(void * stream, double value)
    void write(void * stream, char * data, size_t size)
    void write_pad(void * stream, size_t size)
    object get_stream_data(void * stream)
    size_t get_stream_size(void * stream)
    size_t get_write_pos(void * stream)


@cython.final
cdef class ByteReader:
    def __init__(self, bytes data):
        self.start = data
        self.end = self.start + len(data)
        self.pos = self.start
        self.py_data = data

    cpdef unsigned int tell(self):
        return self.pos - self.start

    cpdef seek(self, int pos, int whence=0):
        if whence == 0:
            self.pos = self.start + pos
        elif whence == 1:
            self.pos += pos
        elif whence == 2:
            self.pos = self.end - pos
        self.pos = max(self.start, min(self.end, self.pos))

    cpdef unsigned int get_left(self):
        return self.end - self.pos

    cdef char * check_available(self, unsigned int size):
        cdef char * data = self.pos
        if data + size > self.end:
            raise OutOfData(self)
        self.pos += size
        return data

    cpdef bytes read(self, unsigned int size=UINT_MAX):
        if size == UINT_MAX:
            size = self.get_left()
        cdef char * pos = self.check_available(size)
        return pos[:size]

    def open_editor(self):
        if raw_input('Open editor? y/n ').strip().lower() != 'y':
            return False
        import tempfile
        import subprocess
        fp = tempfile.NamedTemporaryFile('wb', delete=False)
        fp.write(self.py_data)
        fp.close()
        name = fp.name

        try:
            subprocess.Popen(['010editor', '%s@%s' % (name, self.tell())])
        except IOError:
            pass
        raw_input('Press enter to continue...')
        return True

    cpdef bytes read_string(self, unsigned int size):
        cdef char * data = self.check_available(size)
        cdef unsigned int i
        for i in range(size):
            if data[i] == 0:
                break
        else:
            return data[:size]
        return data[:i]

    cpdef unicode read_ascii(self, unsigned int size):
        return filter_string(self.read_string(size))

    cpdef skip(self, unsigned int size):
        cdef unsigned int end_pos = self.tell() + size
        self.seek(end_pos)
        if end_pos != self.tell():
            raise OutOfData(self)

    cpdef rewind(self, int size):
        self.seek(-size, 1)

    cpdef char read_int8(self):
        cdef char * data = self.check_available(1)
        return read_int8(data)

    cpdef unsigned char read_uint8(self):
        cdef char * data = self.check_available(1)
        return read_uint8(data)

    cpdef short read_int16(self):
        cdef char * data = self.check_available(2)
        return read_int16(data)

    cpdef unsigned short read_uint16(self):
        cdef char * data = self.check_available(2)
        return read_uint16(data)

    cpdef int read_int32(self):
        cdef char * data = self.check_available(4)
        return read_int32(data)

    cpdef unsigned int read_uint32(self):
        cdef char * data = self.check_available(4)
        return read_uint32(data)

    cpdef int64_t read_int64(self):
        cdef char * data = self.check_available(8)
        return read_int64(data)

    cpdef uint64_t read_uint64(self):
        cdef char * data = self.check_available(8)
        return read_uint64(data)

    cpdef double read_float(self):
        cdef char * data = self.check_available(4)
        return read_float(data)

    cpdef double read_double(self):
        cdef char * data = self.check_available(8)
        return read_double(data)

    cpdef object read_vec3(self):
        cdef double x = self.read_float()
        cdef double y = self.read_float()
        cdef double z = self.read_float()
        return Vector3(x, y, z)

    cpdef object read_ivec3(self):
        cdef int x = self.read_int32()
        cdef int y = self.read_int32()
        cdef int z = self.read_int32()
        return Vector3(x, y, z)

    cpdef object read_qvec3(self):
        cdef int64_t x = self.read_int64()
        cdef int64_t y = self.read_int64()
        cdef int64_t z = self.read_int64()
        return Vector3(x, y, z)


cdef class ByteWriter:
    def __init__(self):
        self.stream = create_write_stream()

    def __dealloc__(self):
        delete_write_stream(self.stream)

    cpdef size_t tell(self):
        return get_write_pos(self.stream)

    cpdef write(self, bytes data):
        write(self.stream, data, len(data))

    cpdef write_string(self, bytes value, size_t size):
        cdef size_t string_size = len(value)
        cdef size_t write_size = min(size, string_size)
        write(self.stream, value, write_size)
        write_pad(self.stream, size - write_size)

    cpdef write_ascii(self, unicode value, size_t size):
        cdef bytes new_value = value.encode('ascii', 'ignore')
        self.write_string(new_value, size)

    cpdef pad(self, size_t size):
        write_pad(self.stream, size)

    cpdef write_int8(self, char value):
        write_int8(self.stream, value)

    cpdef write_uint8(self, unsigned char value):
        write_uint8(self.stream, value)

    cpdef write_int16(self, short value):
        write_int16(self.stream, value)

    cpdef write_uint16(self, unsigned short value):
        write_uint16(self.stream, value)

    cpdef write_int32(self, int value):
        write_int32(self.stream, value)

    cpdef write_uint32(self, unsigned int value):
        write_uint32(self.stream, value)

    cpdef write_int64(self, int64_t value):
        write_int64(self.stream, value)

    cpdef write_uint64(self, uint64_t value):
        write_uint64(self.stream, value)

    cpdef write_float(self, double value):
        write_float(self.stream, value)

    cpdef write_double(self, double value):
        write_double(self.stream, value)

    cpdef write_vec3(self, value):
        self.write_float(value.x)
        self.write_float(value.y)
        self.write_float(value.z)

    cpdef write_ivec3(self, value):
        self.write_int32(value.x)
        self.write_int32(value.y)
        self.write_int32(value.z)

    cpdef write_qvec3(self, value):
        self.write_int64(value.x)
        self.write_int64(value.y)
        self.write_int64(value.z)

    cpdef bytes get(self):
        return get_stream_data(self.stream)
