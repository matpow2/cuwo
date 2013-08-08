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


cimport cython
ctypedef signed long long int64_t
ctypedef unsigned long long uint64_t


@cython.final
cdef class ByteReader:
    cdef:
        char * start
        char * end
        char * pos
        bytes py_data

    cpdef unsigned int tell(self)
    cpdef seek(self, int pos, int whence=?)

    cpdef unsigned int get_left(self)
    cdef char * check_available(self, unsigned int size) except NULL
    cpdef bytes read(self, unsigned int size)
    cpdef bytes read_string(self, unsigned int size)

    cpdef unicode read_ascii(self, unsigned int size)
    cpdef skip(self, unsigned int size)
    cpdef rewind(self, int size)
    cpdef char read_int8(self) except *
    cpdef unsigned char read_uint8(self) except *
    cpdef short read_int16(self) except *
    cpdef unsigned short read_uint16(self) except *
    cpdef int read_int32(self) except *
    cpdef unsigned int read_uint32(self) except *
    cpdef int64_t read_int64(self) except *
    cpdef uint64_t read_uint64(self) except *
    cpdef double read_float(self) except *
    cpdef double read_double(self) except *
    cpdef object read_vec3(self)
    cpdef object read_ivec3(self)
    cpdef object read_qvec3(self)


@cython.final
cdef class ByteWriter:
    cdef:
        void * stream

    cpdef size_t tell(self)
    cpdef write(self, bytes data)
    cpdef write_string(self, bytes value, size_t size)
    cpdef write_ascii(self, unicode value, size_t size)
    cpdef pad(self, size_t size)
    cpdef write_int8(self, char value)
    cpdef write_uint8(self, unsigned char value)
    cpdef write_int16(self, short value)
    cpdef write_uint16(self, unsigned short value)
    cpdef write_int32(self, int value)
    cpdef write_uint32(self, unsigned int value)
    cpdef write_int64(self, int64_t value)
    cpdef write_uint64(self, uint64_t value)
    cpdef write_float(self, double value)
    cpdef write_double(self, double value)
    cpdef write_vec3(self, value)
    cpdef write_ivec3(self, value)
    cpdef write_qvec3(self, value)
    cpdef bytes get(self)
