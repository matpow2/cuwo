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


cdef extern from "terraingen.h" nogil:
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

    void tgen_init()
    void tgen_set_path(const char * dir)
    void tgen_set_seed(unsigned int seed)
    ChunkData * tgen_generate_chunk(unsigned int, unsigned int)
    void tgen_destroy_chunk(ChunkData *)
    void tgen_dump_mem(const char * filename)
    unsigned int tgen_generate_debug_chunk(const char *,
                                           unsigned int, unsigned int)

from libcpp.vector cimport vector

cdef extern from "stddef.h" nogil:
    ctypedef unsigned int uintptr_t


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
# - 1 bit, ?

cdef enum:
    EMPTY_TYPE = 0
    WATER_TYPE = 2
    WATER2_TYPE = 3
    GRASS_TYPE = 4
    MOUNTAIN_TYPE = 6
    TREE_TYPE = 8


def initialize(seed, path=None):
    if path is None:
        path = './data/'
    tgen_set_seed(seed)
    tgen_set_path(path)
    with nogil:
        tgen_init()


def generate(x, y):
    return ChunkProxy(x, y)


def generate_debug(filename, x, y):
    return tgen_generate_debug_chunk(filename, x, y)


def dump_mem(filename):
    tgen_dump_mem(filename)


cdef int get_block_type(ChunkEntry * block) nogil:
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


cdef struct Vertex:
    float x, y, z
    float nx, ny, nz
    unsigned char r, g, b, a


cdef struct Quad:
    Vertex v1, v2, v3, v4


cdef class RenderBuffer:
    cdef vector[Quad] data
    cdef float off_x, off_y

    def __init__(self, ChunkProxy proxy, float off_x, float off_y):
        self.off_x = off_x
        self.off_y = off_y
        with nogil:
            self.fill(proxy)

    def get_data(self):
        cdef char * v = <char*>(&self.data[0])
        return v[:self.data.size()*sizeof(Quad)]

    def get_data_pointer(self):
        cdef uintptr_t v = <uintptr_t>(&self.data[0])
        return (v, self.data.size())

    cdef void fill(self, ChunkProxy proxy) nogil:
        cdef int x, y, i, n, z
        cdef ChunkXY * xy
        cdef ChunkEntry * block
        for i in range(256*256):
            x = i % 256
            y = i / 256
            xy = &proxy.data.items[i]
            for z in range(min(xy.b, 0), <int>(xy.a + xy.size)):
                if proxy.get_neighbor_solid_c(x, y, z):
                    continue
                if z < xy.a:
                    self.add_block(proxy, x, y, z, &xy.items[0])
                    continue
                block = &xy.items[z - xy.a]
                if get_block_type(block) == EMPTY_TYPE:
                    continue
                self.add_block(proxy, x, y, z, block)

    cdef void add_block(self, ChunkProxy proxy, int x, int y, int z,
                        ChunkEntry * block) nogil:
        cdef Quad q

        q.v1.r = q.v2.r = q.v3.r = q.v4.r = block.r
        q.v1.g = q.v2.g = q.v3.g = q.v4.g = block.g
        q.v1.b = q.v2.b = q.v3.b = q.v4.b = block.b
        q.v1.a = q.v2.a = q.v3.a = q.v4.a = 255

        cdef float gl_x1 = <float>x + self.off_x
        cdef float gl_x2 = gl_x1 + <float>1.0
        cdef float gl_y1 = <float>y + self.off_y
        cdef float gl_y2 = gl_y1 + <float>1.0
        cdef float gl_z1 = <float>z
        cdef float gl_z2 = gl_z1 + <float>1.0

        # Left Face
        if not proxy.get_solid_c(x, y + 1, z):
            q.v1.x = gl_x1; q.v1.y = gl_y2; q.v1.z = gl_z1
            q.v2.x = gl_x1; q.v2.y = gl_y2; q.v2.z = gl_z2
            q.v3.x = gl_x2; q.v3.y = gl_y2; q.v3.z = gl_z2
            q.v4.x = gl_x2; q.v4.y = gl_y2; q.v4.z = gl_z1
            q.v1.nx = q.v2.nx = q.v3.nx = q.v4.nx = 0.0
            q.v1.ny = q.v2.ny = q.v3.ny = q.v4.ny = 1.0
            q.v1.nz = q.v2.nz = q.v3.nz = q.v4.nz = 0.0
            self.data.push_back(q)

        # Right face
        if not proxy.get_solid_c(x, y - 1, z):
            q.v1.x = gl_x1; q.v1.y = gl_y1; q.v1.z = gl_z1
            q.v2.x = gl_x2; q.v2.y = gl_y1; q.v2.z = gl_z1
            q.v3.x = gl_x2; q.v3.y = gl_y1; q.v3.z = gl_z2
            q.v4.x = gl_x1; q.v4.y = gl_y1; q.v4.z = gl_z2
            q.v1.nx = q.v2.nx = q.v3.nx = q.v4.nx = 0.0
            q.v1.ny = q.v2.ny = q.v3.ny = q.v4.ny = -1.0
            q.v1.nz = q.v2.nz = q.v3.nz = q.v4.nz = 0.0
            self.data.push_back(q)
        

        # Top face
        if not proxy.get_solid_c(x, y, z + 1):
            q.v1.x = gl_x1; q.v1.y = gl_y1; q.v1.z = gl_z2
            q.v2.x = gl_x2; q.v2.y = gl_y1; q.v2.z = gl_z2
            q.v3.x = gl_x2; q.v3.y = gl_y2; q.v3.z = gl_z2
            q.v4.x = gl_x1; q.v4.y = gl_y2; q.v4.z = gl_z2
            q.v1.nx = q.v2.nx = q.v3.nx = q.v4.nx = 0.0
            q.v1.ny = q.v2.ny = q.v3.ny = q.v4.ny = 0.0
            q.v1.nz = q.v2.nz = q.v3.nz = q.v4.nz = -1.0
            self.data.push_back(q)
        

        # Bottom face
        if not proxy.get_solid_c(x, y, z - 1):
            q.v1.x = gl_x1; q.v1.y = gl_y1; q.v1.z = gl_z1
            q.v2.x = gl_x1; q.v2.y = gl_y2; q.v2.z = gl_z1
            q.v3.x = gl_x2; q.v3.y = gl_y2; q.v3.z = gl_z1
            q.v4.x = gl_x2; q.v4.y = gl_y1; q.v4.z = gl_z1
            q.v1.nx = q.v2.nx = q.v3.nx = q.v4.nx = 0.0
            q.v1.ny = q.v2.ny = q.v3.ny = q.v4.ny = 0.0
            q.v1.nz = q.v2.nz = q.v3.nz = q.v4.nz = 1.0
            self.data.push_back(q)
        

        # Right face
        if not proxy.get_solid_c(x + 1, y, z):
            q.v1.x = gl_x2; q.v1.y = gl_y1; q.v1.z = gl_z1
            q.v2.x = gl_x2; q.v2.y = gl_y2; q.v2.z = gl_z1
            q.v3.x = gl_x2; q.v3.y = gl_y2; q.v3.z = gl_z2
            q.v4.x = gl_x2; q.v4.y = gl_y1; q.v4.z = gl_z2
            q.v1.nx = q.v2.nx = q.v3.nx = q.v4.nx = 1.0
            q.v1.ny = q.v2.ny = q.v3.ny = q.v4.ny = 0.0
            q.v1.nz = q.v2.nz = q.v3.nz = q.v4.nz = 0.0
            self.data.push_back(q)
        

        # Left Face
        if not proxy.get_solid_c(x - 1, y, z):
            q.v1.x = gl_x1; q.v1.y = gl_y1; q.v1.z = gl_z1
            q.v2.x = gl_x1; q.v2.y = gl_y1; q.v2.z = gl_z2
            q.v3.x = gl_x1; q.v3.y = gl_y2; q.v3.z = gl_z2
            q.v4.x = gl_x1; q.v4.y = gl_y2; q.v4.z = gl_z1
            q.v1.nx = q.v2.nx = q.v3.nx = q.v4.nx = -1.0
            q.v1.ny = q.v2.ny = q.v3.ny = q.v4.ny = 0.0
            q.v1.nz = q.v2.nz = q.v3.nz = q.v4.nz = 0.0
            self.data.push_back(q)


cdef class ChunkProxy:
    cdef ChunkData * data
    cdef public:
        list items
    
    def __init__(self, x, y):
        cdef unsigned int x_int = x
        cdef unsigned int y_int = y

        with nogil:
            self.data = tgen_generate_chunk(x_int, y_int)

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

    cdef bint get_solid_c(self, int x, int y, int z) nogil:
        if x < 0 or x >= 256 or y < 0 or y >= 256:
            return False
        cdef ChunkXY * data = self.get_xy(x, y)
        if z < data.a:
            return True
        z -= data.a
        if z >= <int>data.size:
            return False
        return get_block_type(&data.items[z]) != EMPTY_TYPE

    def get_solid(self, x, y, z):
        return self.get_solid_c(x, y, z)

    cdef ChunkXY * get_xy(self, int x, int y) nogil:
        return &self.data.items[x + y * 256]

    cdef bint get_neighbor_solid_c(self, int x, int y, int z) nogil:
        return (self.get_solid_c(x - 1, y, z) and
                self.get_solid_c(x + 1, y, z) and
                self.get_solid_c(x, y + 1, z) and
                self.get_solid_c(x, y - 1, z) and
                self.get_solid_c(x, y, z + 1) and
                self.get_solid_c(x, y, z - 1))

    def get_neighbor_solid(self, x, y, z):
        return self.get_neighbor_solid_c(x, y, z)

    def get_dict(self):
        cdef dict blocks = {}

        cdef int x, y, i, n, z
        cdef ChunkXY * xy
        cdef ChunkEntry * block
        for i in range(256*256):
            x = i % 256
            y = i / 256
            xy = &self.data.items[i]
            for z in range(xy.b, <int>(xy.a + xy.size)):
                if self.get_neighbor_solid_c(x, y, z):
                    continue
                if z < xy.a:
                    blocks[(x, y, z)] = get_block_tuple(&xy.items[0])
                    continue
                block = &xy.items[z - xy.a]
                if get_block_type(block) == EMPTY_TYPE:
                    continue
                blocks[(x, y, z)] = get_block_tuple(block)
        return blocks

    def get_render(self, off_x=0.0, off_y=0.0):
        return RenderBuffer(self, off_x, off_y)

    def __getitem__(self, index):
        cdef XYProxy proxy = XYProxy()
        proxy.data = &self.data.items[index]
        return proxy

    def __dealloc__(self):
        tgen_destroy_chunk(self.data)
