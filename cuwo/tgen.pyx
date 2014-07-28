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
from cuwo.static import StaticEntityHeader
from cuwo.bytes cimport ByteReader, create_reader
from cuwo.entity import ItemData, AppearanceData
from cuwo.common import validate_chunk_pos
from cuwo.strings import ENTITY_NAMES
from cuwo.constants import BLOCK_SCALE
from cuwo.vector import Vector3

from libc.stdint cimport uintptr_t, uint32_t, uint8_t, uint64_t, int64_t
from libc.stdlib cimport malloc, free
from libcpp.string cimport string

cdef extern from "tgen.h" nogil:
    cdef cppclass Memory:
        char * translate(uint32_t)
        uint32_t translate(char *)
        uint32_t read_dword(uint32_t)
        void read(uint32_t, char*, uint32_t)
        uint8_t read_byte(uint32_t)

    extern Memory mem

    void tgen_init()
    void tgen_set_path(const char * dir)
    void tgen_set_seed(uint32_t seed)
    uint32_t tgen_generate_chunk(uint32_t, uint32_t)
    void tgen_dump_mem(const char * filename)
    uint32_t tgen_generate_debug_chunk(const char *, uint32_t, uint32_t)
    uint32_t tgen_get_heap_base()
    uint32_t tgen_get_manager()
    void tgen_read_str(uint32_t addr, string&)
    void tgen_read_wstr(uint32_t addr, string&)

from libcpp.vector cimport vector


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


def initialize(seed, path):
    tgen_set_seed(seed)
    path = path.encode('utf-8')
    tgen_set_path(path)
    with nogil:
        tgen_init()


def generate(x, y):
    if not validate_chunk_pos(x, y):
        return None
    return Chunk(x, y)


def generate_debug(filename, x, y):
    filename = filename.encode('utf-8')
    return tgen_generate_debug_chunk(filename, x, y)


def dump_mem(filename):
    tgen_dump_mem(filename)


def get_heap_base():
    return tgen_get_heap_base()


# createdef.py helpers

# MSVC std::map
# _Nodeptr _Left; // left subtree, or smallest element if head
# _Nodeptr _Parent;   // parent, or root of tree if head
# _Nodeptr _Right;    // right subtree, or largest element if head
# char _Color;    // _Red or _Black, _Black if head
# char _Isnil;    // true only if head (also nil) node
# char pad[2];
# value_type _Myval;  // the stored value, unused if head


cdef str read_wstr(uint32_t addr):
    cdef string v
    tgen_read_wstr(addr, v)
    return ((&v[0])[:v.size()]).decode('utf_16_le')


cdef bint is_nil(uint32_t ptr):
    return mem.read_byte(ptr + 13) == 1


cdef uint32_t get_right(uint32_t ptr):
    return mem.read_dword(ptr + 8)


cdef uint32_t get_left(uint32_t ptr):
    return mem.read_dword(ptr + 0)


cdef uint32_t get_parent(uint32_t ptr):
    return mem.read_dword(ptr + 4)


cdef uint32_t get_min(uint32_t ptr):
    while not is_nil(get_left(ptr)):
        ptr = get_left(ptr)
    return ptr


cdef dict map_to_dict(uint32_t addr, func):
    cdef dict values = {}
    cdef uint32_t ptr = get_left(mem.read_dword(addr))
    cdef uint32_t test_ptr
    while not is_nil(ptr):
        func(ptr + 16, values)
        if not is_nil(get_right(ptr)):
            ptr = get_min(get_right(ptr))
        else:
            while True:
                test_ptr = get_parent(ptr)
                if is_nil(test_ptr) or ptr != get_right(test_ptr):
                    break
                ptr = test_ptr
            ptr = test_ptr

    return values


def get_single_key_item(uint32_t addr, dict values):
    cdef uint32_t key = mem.read_dword(addr)
    cdef str value = read_wstr(addr+4)
    values[key] = value


def get_double_key_item(uint32_t addr, dict values):
    cdef tuple key = (mem.read_dword(addr), mem.read_dword(addr+4))
    cdef str value = read_wstr(addr+8)
    values[key] = value


def get_static_names():
    return map_to_dict(tgen_get_manager() + 8388876, get_single_key_item)


def get_entity_names():
    return map_to_dict(tgen_get_manager() + 8388868, get_single_key_item)


def get_item_names():
    return map_to_dict(tgen_get_manager() + 8388916, get_double_key_item)


def get_location_names():
    return map_to_dict(tgen_get_manager() + 8388900, get_double_key_item)


def get_quarter_names():
    return map_to_dict(tgen_get_manager() + 8388908, get_double_key_item)


def get_skill_names():
    return map_to_dict(tgen_get_manager() + 8388884, get_single_key_item)


def get_ability_names():
    return map_to_dict(tgen_get_manager() + 8388892, get_single_key_item)


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

    def __init__(self, Chunk proxy, float off_x, float off_y):
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

    cdef void fill(self, Chunk proxy) nogil:
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

    cdef void add_block(self, Chunk proxy, int x, int y, int z,
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


cdef struct ChunkEntry:
    unsigned char r, g, b, a

cdef struct ChunkXY:
    int a, b  # b is not actually used
    unsigned int size
    ChunkEntry * items

cdef struct ChunkData:
    ChunkXY items[256*256]


cdef class ItemWithHeaderList:
    cdef public:
        list items

    def __cinit__(self, uint32_t addr):
        cdef uint32_t vec_start = mem.read_dword(addr)
        cdef uint32_t vec_end = mem.read_dword(addr+4)
        cdef uint32_t vec_capacity = mem.read_dword(addr+8)

        cdef ByteReader reader = create_reader(mem.translate(vec_start),
                                               vec_end - vec_start)
        self.items = []
        cdef uint32_t header
        cdef object item
        for _ in range((vec_end - vec_start) // 4):
            header = reader.read_uint32()
            item = ItemData()
            item.read(reader)
            self.items.append((header, item))


cdef list read_item_with_header_lists(uint32_t start, uint32_t end):
    cdef list items = []
    cdef uint32_t vec_item
    for _ in range((end - start) // 4):
        vec_item = mem.read_dword(start)
        items.append(ItemWithHeaderList(vec_item))
        start += 4
    return items


cdef class StaticEntity:
    cdef public:
        object header
        list items
        object item

    def __cinit__(self, ByteReader reader):
        self.header = StaticEntityHeader()
        self.header.read(reader)
        cdef uint32_t vec_start = reader.read_uint32()
        cdef uint32_t vec_end = reader.read_uint32()
        cdef uint32_t vec_capacity = reader.read_uint32()
        cdef uint32_t something1 = reader.read_uint32()
        self.item = ItemData()
        self.item.read(reader)
        cdef uint32_t something2 = reader.read_uint32()
        cdef uint32_t something3 = reader.read_uint32()
        cdef uint32_t something4 = reader.read_uint32()
        cdef uint32_t something5 = reader.read_uint32()
        cdef uint32_t something6 = reader.read_uint32()
        cdef uint32_t something7 = reader.read_uint32()

        self.items = read_item_with_header_lists(vec_start, vec_end)


cdef class DynamicEntity:
    cdef public:
        object pos
        uint32_t hostile_type
        uint32_t class_type
        uint32_t specialization
        uint32_t entity_type
        uint32_t level
        uint64_t entity_id
        uint32_t flags_bit_3
        float yaw
        uint32_t power_base
        uint32_t not_used19
        object not_used20
        object appearance
        list equipment
        float max_hp_multiplier
        float shoot_speed
        float damage_multiplier
        float armor_multiplier
        float resi_multiplier
        uint32_t unknown_or_not_used4
        str name

    def __cinit__(self, ByteReader reader):
        reader.seek(16)
        self.pos = reader.read_qvec3()
        self.hostile_type = reader.read_uint8()
        reader.skip(3)
        self.entity_type = reader.read_uint32()
        self.class_type = reader.read_uint8()
        self.specialization = reader.read_uint8()
        reader.skip(2)
        self.level = reader.read_uint32()
        reader.skip(4*4)
        self.entity_id = reader.read_uint64()
        self.flags_bit_3 = reader.read_uint8()
        reader.skip(3)
        self.yaw = reader.read_float()
        self.power_base = reader.read_uint8()
        reader.skip(3)
        self.not_used19 = reader.read_uint8()
        reader.skip(3)
        self.not_used20 = reader.read_ivec3()
        reader.skip(4*2)
        self.appearance = AppearanceData()
        self.appearance.read(reader)

        self.equipment = []

        cdef object item
        for _ in range(13):
            item = ItemData()
            item.read(reader)
            self.equipment.append(item)

        reader.skip(304) # ItemWithExtra

        reader.skip(11 * 4)
        self.unknown_or_not_used4 = reader.read_uint32()
        self.name = reader.read_ascii(16)
        reader.skip(4*3 + 1 + 7)

    def set_entity(self, object entity):
        entity.pos = self.pos
        entity.spawn_pos = self.pos.copy()
        entity.hostile_type = self.hostile_type
        entity.entity_type = self.entity_type
        entity.class_type = self.class_type
        entity.specialization = self.specialization
        entity.level = self.level

        if self.flags_bit_3:
            entity.flags |= 1 << 3
        else:
            entity.flags &= ~(1 << 3)

        entity.body_yaw = self.yaw
        entity.power_base = self.power_base
        entity.not_used19 = self.not_used19
        entity.not_used20 = self.not_used20

        entity.appearance = self.appearance
        entity.equipment = self.equipment
        entity.max_hp_multiplier = self.max_hp_multiplier
        entity.shoot_speed = self.shoot_speed
        entity.damage_multiplier = self.damage_multiplier
        entity.armor_multiplier = self.armor_multiplier
        entity.resi_multiplier = self.resi_multiplier
        entity.unknown_or_not_used4

        entity.name = self.name

        if self.appearance.flags & 0x200:
            entity.appearance.scale *= 2.0

        cdef float off_z = entity.appearance.scale.z * 0.5 + 0.1
        entity.pos.z += off_z * BLOCK_SCALE

        # some default values
        entity.consumable = ItemData()
        entity.velocity = Vector3()
        entity.accel = Vector3()
        entity.extra_vel = Vector3()
        entity.ray_hit = Vector3()
        entity.start_chunk = Vector3()
        entity.skills = [0] * 11

    def get_type(self):
        return ENTITY_NAMES[self.entity_type]


cdef class Chunk:
    cdef ChunkData data
    cdef public:
        list items
        list static_entities
        list dynamic_entities
        uint32_t x, y

    def __init__(self, x, y):
        self.x = x
        self.y = y

        cdef uint32_t addr
        with nogil:
            addr = tgen_generate_chunk(self.x, self.y)
            self.read_chunk(addr)

        cdef ByteReader reader = create_reader(NULL, 0)
        cdef uint32_t start, end

        # read dynamic entities
        self.dynamic_entities = []
        start = mem.read_dword(addr + 24)
        end = mem.read_dword(addr + 28)

        cdef DynamicEntity dynamic
        cdef uint32_t new_addr
        for i in range(0, end - start, 4):
            new_addr = mem.read_dword(start + i)
            reader.init(mem.translate(new_addr), 4336)
            dynamic = DynamicEntity.__new__(DynamicEntity, reader)
            self.dynamic_entities.append(dynamic)

        # read static entities
        self.static_entities = []
        start = mem.read_dword(addr + 12)
        end = mem.read_dword(addr + 16)

        reader.init(mem.translate(start), end - start)

        cdef StaticEntity static
        while reader.get_left() > 0:
            static = StaticEntity.__new__(StaticEntity, reader)
            self.static_entities.append(static)

        # read chunk items
        self.items = []

        start = mem.read_dword(addr + 48)
        end = mem.read_dword(addr + 52)

        reader.init(mem.translate(start), end - start)
        while reader.get_left() > 0:
            item = ChunkItemData()
            item.read(reader)
            self.items.append(item)

    cdef void read_chunk(self, uint32_t addr) nogil:
        cdef uint32_t entry = mem.read_dword(addr + 168)

        cdef uint32_t chunk_data, data_size
        cdef char * out_data
        cdef ChunkXY * c

        for i in range(256*256):
            c = &self.data.items[i]
            # cdef uint32_t vtable = mem.read_dword(entry);
            # cdef float something = to_ss(mem.read_dword(entry+4));
            # cdef float something2 = to_ss(mem.read_dword(entry+8));
            # cdef float something3 = to_ss(mem.read_dword(entry+12));
            c.a = mem.read_dword(entry+16)
            c.b = mem.read_dword(entry+20)
            chunk_data = mem.read_dword(entry+24)
            data_size = mem.read_dword(entry+28) # * 4, size
            out_data = <char*>malloc(data_size*4)
            mem.read(chunk_data, out_data, data_size*4)

            # write it out
            c.size = data_size
            c.items = <ChunkEntry*>out_data
            entry += 32

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

    def get_height(self, x, y):
        cdef ChunkXY * data = self.get_xy(x, y)
        return (<int64_t>(data.a) + <int64_t>(data.size))

    def __getitem__(self, index):
        cdef XYProxy proxy = XYProxy()
        proxy.data = &self.data.items[index]
        return proxy

    def __dealloc__(self):
        for i in range(256*256):
            free(self.data.items[i].items)
