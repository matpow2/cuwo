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
Terraingen wrapper
"""


cdef extern from "terraingen.h":
    cdef struct ChunkEntry:
        unsigned char r, g, b, a

    cdef struct ChunkXY:
        int a, b
        unsigned int size
        ChunkEntry * items

    cdef struct ChunkData:
        int x, y
        ChunkXY items[256*256]

    void tgen_init() nogil
    void tgen_set_path(const char * data)
    void tgen_set_seed(unsigned int seed) nogil
    ChunkData * tgen_generate_chunk(unsigned int, unsigned int) nogil
    void tgen_destroy_chunk(ChunkData *) nogil
    void tgen_dump_mem(const char * filename) nogil


def initialize(seed):
    tgen_set_seed(seed)
    tgen_set_path('./data/')
    tgen_init()


def generate(x, y):
    return ChunkProxy(x, y)


def dump_mem(filename):
    tgen_dump_mem(filename)


cdef class XYProxy:
    cdef ChunkXY * data

    property a:
        def __get__(self):
            return self.data.a

    property b:
        def __get__(self):
            return self.data.b

    def __len__(self):
        return self.data.size

    def __getitem__(self, index):
        cdef ChunkEntry * data = &self.data.items[index]
        return (data.r, data.g, data.b, data.a)

cdef class ChunkProxy:
    cdef ChunkData * data
    
    def __init__(self, x, y):
        self.data = tgen_generate_chunk(x, y)

    property x:
        def __get__(self):
            return self.data.x

    property y:
        def __get__(self):
            return self.data.y

    def __getitem__(self, index):
        cdef XYProxy proxy = XYProxy()
        proxy.data = &self.data.items[index]
        return proxy

    def __dealloc__(self):
        tgen_destroy_chunk(self.data)
