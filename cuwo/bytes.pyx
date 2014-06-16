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
cimport cython
from libc.limits cimport UINT_MAX
from cuwo.common import filter_bytes
from cuwo.vector import Vector3


cdef extern from "bytes_c.cpp":
    void * create_write_stream()
    void delete_write_stream(void * stream)
    object get_stream_data(void * stream)


@cython.final
cdef class ByteReader:
    def __init__(self, char[::1] data):
        self.init(&data[0], len(data))
        self.py_data = data

    cpdef seek(self, int pos, int whence=0):
        if whence == 0:
            self.pos = self.start + pos
        elif whence == 1:
            self.pos += pos
        elif whence == 2:
            self.pos = self.end - pos
        self.pos = max(self.start, min(self.end, self.pos))

    cpdef bytes read(self, unsigned int size=UINT_MAX):
        if size == UINT_MAX:
            size = self.get_left()
        cdef char * pos = self.check_available(size)
        return pos[:size]

    def open_editor(self):
        if input('Open editor? y/n ').strip().lower() != 'y':
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
        input('Press enter to continue...')
        return True

    def __dealloc__(self):
        self.py_data = None

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

    cpdef str read_ascii(self, unsigned int size):
        return filter_bytes(self.read_string(size))


cdef class ByteWriter:
    def __init__(self):
        self.stream = create_write_stream()

    def __dealloc__(self):
        delete_write_stream(self.stream)

    cpdef bytes get(self):
        return get_stream_data(self.stream)

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
