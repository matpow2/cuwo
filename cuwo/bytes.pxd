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
from libc.stdint cimport int64_t, uint64_t
from libc.string cimport memcpy


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


cdef bint raise_out_of_data(ByteReader reader) except True


@cython.final
cdef class ByteReader:
    cdef:
        char * start
        char * end
        char * pos
        object py_data

    @cython.final
    cdef inline void init(self, char * data, size_t size):
        self.start = data
        self.end = data + size
        self.pos = self.start

    @cython.final
    cpdef inline unsigned int tell(self):
        return self.pos - self.start

    @cython.final
    cpdef inline seek(self, int pos, int whence=?)

    @cython.final
    cpdef str read_ascii(self, unsigned int size)

    cdef inline bint read_c(self, void * data, unsigned int size) except False:
        cdef char * pos = self.check_available(size)
        memcpy(data, pos, size)
        return True

    @cython.final
    cpdef inline bytes read(self, unsigned int size=?)

    @cython.final
    cpdef inline unsigned int get_left(self):
        return self.end - self.pos

    @cython.final
    cdef inline char * check_available(self, unsigned int size) except NULL:
        cdef char * data = self.pos
        if data + size > self.end:
            raise_out_of_data(self)
            return NULL
        self.pos += size
        return data

    @cython.final
    cpdef inline bytes read_string(self, unsigned int size):
        cdef char * data = self.check_available(size)
        cdef unsigned int i
        for i in range(size):
            if data[i] == 0:
                break
        else:
            return data[:size]
        return data[:i]

    @cython.final
    cpdef inline skip(self, unsigned int size):
        cdef unsigned int end_pos = self.tell() + size
        self.seek(end_pos)
        if end_pos != self.tell():
            raise_out_of_data(self)

    @cython.final
    cpdef inline rewind(self, int size):
        self.seek(-size, 1)

    @cython.final
    cpdef inline char read_int8(self) except *:
        cdef char * data = self.check_available(1)
        return read_int8(data)

    @cython.final
    cpdef inline unsigned char read_uint8(self) except *:
        cdef char * data = self.check_available(1)
        return read_uint8(data)

    @cython.final
    cpdef inline short read_int16(self) except *:
        cdef char * data = self.check_available(2)
        return read_int16(data)

    @cython.final
    cpdef inline unsigned short read_uint16(self) except *:
        cdef char * data = self.check_available(2)
        return read_uint16(data)

    @cython.final
    cpdef inline int read_int32(self) except *:
        cdef char * data = self.check_available(4)
        return read_int32(data)

    @cython.final
    cpdef inline unsigned int read_uint32(self) except *:
        cdef char * data = self.check_available(4)
        return read_uint32(data)

    @cython.final
    cpdef inline int64_t read_int64(self) except *:
        cdef char * data = self.check_available(8)
        return read_int64(data)

    @cython.final
    cpdef inline uint64_t read_uint64(self) except *:
        cdef char * data = self.check_available(8)
        return read_uint64(data)

    @cython.final
    cpdef inline double read_float(self) except *:
        cdef char * data = self.check_available(4)
        return read_float(data)

    @cython.final
    cpdef inline double read_double(self) except *:
        cdef char * data = self.check_available(8)
        return read_double(data)

    @cython.final
    cpdef object read_vec3(self)

    @cython.final
    cpdef object read_ivec3(self)

    @cython.final
    cpdef object read_qvec3(self)


@cython.final
cdef class ByteWriter:
    cdef:
        void * stream

    @cython.final
    cpdef inline size_t tell(self):
        return get_write_pos(self.stream)

    cdef inline bint write_c(self, void * data, size_t size):
        write(self.stream, <char*>data, size)
        return True

    @cython.final
    cpdef inline bint write(self, bytes data):
        write(self.stream, data, len(data))
        return True

    @cython.final
    cpdef inline bint write_string(self, bytes value, size_t size):
        cdef size_t string_size = len(value)
        cdef size_t write_size = min(size, string_size)
        write(self.stream, value, write_size)
        write_pad(self.stream, size - write_size)
        return True

    @cython.final
    cpdef inline bint write_ascii(self, str value, size_t size):
        cdef bytes new_value = value.encode('ascii', 'ignore')
        self.write_string(new_value, size)
        return True

    @cython.final
    cpdef inline bint pad(self, size_t size):
        write_pad(self.stream, size)
        return True

    @cython.final
    cpdef inline bint write_int8(self, char value):
        write_int8(self.stream, value)
        return True

    @cython.final
    cpdef inline bint write_uint8(self, unsigned char value):
        write_uint8(self.stream, value)
        return True

    @cython.final
    cpdef inline bint write_int16(self, short value):
        write_int16(self.stream, value)
        return True

    @cython.final
    cpdef inline bint write_uint16(self, unsigned short value):
        write_uint16(self.stream, value)
        return True

    @cython.final
    cpdef inline bint write_int32(self, int value):
        write_int32(self.stream, value)
        return True

    @cython.final
    cpdef inline bint write_uint32(self, unsigned int value):
        write_uint32(self.stream, value)
        return True

    @cython.final
    cpdef inline bint write_int64(self, int64_t value):
        write_int64(self.stream, value)
        return True

    @cython.final
    cpdef inline bint write_uint64(self, uint64_t value):
        write_uint64(self.stream, value)
        return True

    @cython.final
    cpdef inline bint write_float(self, double value):
        write_float(self.stream, value)
        return True

    @cython.final
    cpdef inline bint write_double(self, double value):
        write_double(self.stream, value)
        return True

    @cython.final
    cpdef bint write_vec3(self, value) except *

    @cython.final
    cpdef bint write_ivec3(self, value) except *

    @cython.final
    cpdef bint write_qvec3(self, value) except *

    @cython.final
    cpdef bytes get(self)


cdef inline ByteReader create_reader(char * data, size_t size):
    cdef ByteReader reader = ByteReader.__new__(ByteReader)
    reader.init(data, size)
    return reader
