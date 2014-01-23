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


cimport cython
from cuwo.common cimport int64_t, uint64_t


@cython.final
cdef class ByteReader:
    cdef:
        char * start
        char * end
        char * pos
        bytes py_data

    cpdef inline unsigned int tell(self)
    cpdef inline seek(self, int pos, int whence=?)

    cpdef inline unsigned int get_left(self)
    cdef inline char * check_available(self, unsigned int size) except NULL
    cpdef inline bytes read(self, unsigned int size=?)
    cpdef inline bytes read_string(self, unsigned int size)
    cpdef inline unicode read_ascii(self, unsigned int size)
    cpdef inline skip(self, unsigned int size)
    cpdef inline rewind(self, int size)
    cpdef inline char read_int8(self) except *
    cpdef inline unsigned char read_uint8(self) except *
    cpdef inline short read_int16(self) except *
    cpdef inline unsigned short read_uint16(self) except *
    cpdef inline int read_int32(self) except *
    cpdef inline unsigned int read_uint32(self) except *
    cpdef inline int64_t read_int64(self) except *
    cpdef inline uint64_t read_uint64(self) except *
    cpdef inline double read_float(self) except *
    cpdef inline double read_double(self) except *
    cpdef inline object read_vec3(self)
    cpdef inline object read_ivec3(self)
    cpdef inline object read_qvec3(self)


@cython.final
cdef class ByteWriter:
    cdef:
        void * stream

    cpdef inline size_t tell(self)
    cpdef inline write(self, bytes data)
    cpdef inline write_string(self, bytes value, size_t size)
    cpdef inline write_ascii(self, unicode value, size_t size)
    cpdef inline pad(self, size_t size)
    cpdef inline write_int8(self, char value)
    cpdef inline write_uint8(self, unsigned char value)
    cpdef inline write_int16(self, short value)
    cpdef inline write_uint16(self, unsigned short value)
    cpdef inline write_int32(self, int value)
    cpdef inline write_uint32(self, unsigned int value)
    cpdef inline write_int64(self, int64_t value)
    cpdef inline write_uint64(self, uint64_t value)
    cpdef inline write_float(self, double value)
    cpdef inline write_double(self, double value)
    cpdef inline write_vec3(self, value)
    cpdef inline write_ivec3(self, value)
    cpdef inline write_qvec3(self, value)
    cpdef inline bytes get(self)
