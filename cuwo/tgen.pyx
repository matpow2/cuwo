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
Terraingen wrapper
"""


from cuwo.packet import ChunkItemData
from cuwo.bytes cimport ByteReader


cdef extern from "terraingen.h":
    cdef struct ChunkEntry:
        unsigned char r, g, b, a

    cdef struct ChunkXY:
        int a, b # b is not actually used
        unsigned int size
        ChunkEntry * items

    cdef struct ChunkData:
        int x, y
        ChunkXY items[256*256]
        size_t item_size
        char * item_data

    void tgen_init() nogil
    void tgen_set_path(const char * dir)
    void tgen_set_seed(unsigned int seed) nogil
    ChunkData * tgen_generate_chunk(unsigned int, unsigned int) nogil
    void tgen_destroy_chunk(ChunkData *) nogil
    void tgen_dump_mem(const char * filename) nogil


# alpha:
# - 5 bits, block type
#   - 0: empty
#   - 2: water
#   - 3: also water?
#   - 4: grass
#   - 6: mountain, layer under grass
#   - 8: trees
# - 1 bit, unknown (not used in mesh renderer?)
# - 1 bit, used in mesh renderer (caves, darkness? should be empty)


cdef enum:
    EMPTY_TYPE = 0
    WATER_TYPE = 2
    WATER2_TYPE = 3
    GRASS_TYPE = 4
    MOUNTAIN_TYPE = 6
    TREE_TYPE = 8


def initialize(seed):
    tgen_set_seed(seed)
    tgen_set_path('./data/')
    tgen_init()


def generate(x, y):
    return ChunkProxy(x, y)


def dump_mem(filename):
    tgen_dump_mem(filename)


cdef int get_block_type(ChunkEntry * block):
    return block.a & 0x1F


cdef tuple get_block_tuple(ChunkEntry * block):
    return (block.r, block.g, block.b)


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
        return get_block_tuple(data)


cdef class ChunkProxy:
    cdef ChunkData * data
    cdef public:
        list items
    
    def __init__(self, x, y):
        self.data = tgen_generate_chunk(x, y)

        # read items
        self.items = []
        cdef ByteReader reader
        reader = ByteReader(self.data.item_data[:self.data.item_size])
        while reader.get_left() > 0:
            item = ChunkItemData()
            item.read(reader)
            self.items.append(item)

    property x:
        def __get__(self):
            return self.data.x

    property y:
        def __get__(self):
            return self.data.y

    cpdef bint get_solid(self, int x, int y, int z):
        if x < 0 or x >= 256 or y < 0 or y >= 256 or z < 0 or z >= 256:
            return True
        cdef ChunkXY * data = self.get_xy(x, y)
        if z < data.a:
            return True
        z -= data.a
        if z >= <int>data.size:
            return False
        return get_block_type(&data.items[z]) != EMPTY_TYPE

    cdef ChunkXY * get_xy(self, int x, int y):
        return &self.data.items[x + y * 256]

    cpdef bint get_neighbor_solid(self, int x, int y, int z):
        return (self.get_solid(x - 1, y, z) and
                self.get_solid(x + 1, y, z) and
                self.get_solid(x, y + 1, z) and
                self.get_solid(x, y - 1, z) and
                self.get_solid(x, y, z + 1) and
                self.get_solid(x, y, z - 1))

    def get_dict(self):
        cdef dict blocks = {}

        cdef int x, y, i, n, z
        cdef ChunkXY * xy
        cdef ChunkEntry * block
        for i in range(256*256):
            x = i % 256
            y = i / 256
            xy = &self.data.items[i]
            for z in range(0, <int>(xy.a + xy.size)):
                if self.get_neighbor_solid(x, y, z):
                    continue
                if z < xy.a:
                    blocks[(x, y, z)] = get_block_tuple(&xy.items[0])
                    continue
                block = &xy.items[z - xy.a]
                if get_block_type(block) == EMPTY_TYPE:
                    continue
                blocks[(x, y, z)] = get_block_tuple(block)

        return blocks

    def __getitem__(self, index):
        cdef XYProxy proxy = XYProxy()
        proxy.data = &self.data.items[index]
        return proxy

    def __dealloc__(self):
        tgen_destroy_chunk(self.data)
