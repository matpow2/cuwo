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

from libc.stdint cimport (uintptr_t, uint32_t, uint8_t, uint64_t, int64_t,
                          int32_t)
from libc.stdlib cimport malloc, free
from libc.string cimport memcpy
from libcpp.string cimport string

from cuwo.tgen_wrap cimport (Zone, WrapZone, Color, Field, Creature,
                             WrapCreature)

cdef extern from "tgen.h" nogil:
    struct Heap:
        void * first_alloc

    struct CZone "Zone":
        pass

    struct CCreature "Creature":
        pass

    void tgen_init()
    void tgen_set_path(const char * dir)
    void tgen_set_seed(uint32_t seed)
    Heap * tgen_generate_chunk(uint32_t, uint32_t)
    void tgen_destroy_chunk(Heap * v)
    void tgen_simulate()
    void tgen_dump_mem(const char * filename)
    void * tgen_get_heap_base()
    # uint32_t tgen_generate_debug_chunk(const char *, uint32_t, uint32_t)
    void * tgen_get_manager()
    void tgen_read_str(void * addr, string&)
    void tgen_read_wstr(void * addr, string&)

    void sim_add_zone(CZone * z, uint32_t x, uint32_t y)
    void sim_remove_zone(uint32_t x, uint32_t y)
    void sim_add_region(char * r, uint32_t x, uint32_t y)
    void sim_remove_region(uint32_t x, uint32_t y)
    void sim_step(uint32_t dt)
    void sim_remove_creature(CCreature * c)
    CCreature * sim_add_creature(uint64_t id)

cdef extern from "tgen.h":
    void sim_get_creatures(void (*f)(CCreature*))

from libcpp.vector cimport vector

cdef uint32_t read_dword(char * v) nogil:
    cdef uint32_t out
    memcpy(&out, v, sizeof(out))
    return out

cdef uint8_t read_byte(char * v) nogil:
    cdef uint8_t out
    memcpy(&out, v, sizeof(out))
    return out

# block types:
# (courtesy of UserXXX, found by static analysis)
#
# Special blocks:
# Constant  | Type             | Solid | Accepts color
# --------- | ---------------- | ----- | -------------
# 0         | Empty            | No    | No
# 2         | Water            | No    | No
# 3         | Flat Water       | Yes   | The sides take the specified color,
#           | (walkable)       |       | top side looks like water 
#
# Solid blocks with color:
# Constant | Description
# -------- | ----------------
# 1        | Unknown
# 4        | Grass
# 5        | Fields near cities and cliffs (the border of the plateaus found
#          | in e.g. "normal" lands) except in lava lands
# 6        | Rocks / Buildings (in cities and for quest buildings e.g.
#          | castles) / Cliffs in lava lands
# 7        | Trunks and limbs (everything that is "wood") of trees
# 8        | Leafs of trees, this includes the snow on the "leafs" of trees in
#          | snowy lands
# 9        | Sand
# 10       | Snow
# 11       | Unknown
# 12       | Floor in lava lands
# 13       | Unknown
# 14       | Roofs of houses in cities, but only on normal houses, special
#          | buildings like the training buildings use 6
# 15       | Unknown

# alpha:
# - 5 bits, block type, see block type table above
# - 1 bit, set if breakable by bombs/bosses (found by static analysis)
# - 1 bit, used in mesh renderer (caves, darkness? should be empty)
# - 1 bit, ?

cpdef enum BlockType:
    EMPTY_TYPE = 0
    SOLID1_TYPE = 1
    WATER_TYPE = 2
    FLATWATER_TYPE = 3
    GRASS_TYPE = 4
    FIELD_TYPE = 5
    MOUNTAIN_TYPE = 6
    WOOD_TYPE = 7
    LEAF_TYPE = 8
    SAND_TYPE = 9
    SNOW_TYPE = 10
    SOLID2_TYPE = 11
    LAVA_TYPE = 12
    SOLID3_TYPE = 13
    ROOF_TYPE = 14
    SOLID4_TYPE = 15


def initialize(seed, path):
    tgen_set_seed(seed)
    path = path.encode('utf-8')
    tgen_set_path(path)
    with nogil:
        tgen_init()


def generate(x, y):
    if not validate_chunk_pos(x, y):
        return None
    return ZoneData(x, y)


# def generate_debug(filename, x, y):
#     filename = filename.encode('utf-8')
#     return tgen_generate_debug_chunk(filename, x, y)


def dump_mem(filename):
    tgen_dump_mem(filename.encode('utf-8'))
    cdef uint32_t heap_base = <uint32_t>tgen_get_heap_base()
    cdef uint32_t manager_base = <uint32_t>tgen_get_manager()
    return (heap_base, manager_base)


# createdef.py helpers

# MSVC std::map
# _Nodeptr _Left; // left subtree, or smallest element if head
# _Nodeptr _Parent;   // parent, or root of tree if head
# _Nodeptr _Right;    // right subtree, or largest element if head
# char _Color;    // _Red or _Black, _Black if head
# char _Isnil;    // true only if head (also nil) node
# char pad[2];
# value_type _Myval;  // the stored value, unused if head


cdef str read_wstr(char * addr):
    cdef string v
    tgen_read_wstr(addr, v)
    return ((&v[0])[:v.size()]).decode('utf_16_le')


cdef bint is_nil(uint32_t ptr):
    return read_byte(<char*>ptr + 13) == 1


cdef uint32_t get_right(uint32_t ptr):
    return read_dword(<char*>ptr + 8)


cdef uint32_t get_left(uint32_t ptr):
    return read_dword(<char*>ptr + 0)


cdef uint32_t get_parent(uint32_t ptr):
    return read_dword(<char*>ptr + 4)


cdef uint32_t get_min(uint32_t ptr):
    while not is_nil(get_left(ptr)):
        ptr = get_left(ptr)
    return ptr


ctypedef void (*map_func)(char * addr, dict values)


cdef dict map_to_dict(char * addr, map_func func):
    cdef dict values = {}
    cdef uint32_t ptr = get_left(read_dword(addr))
    cdef uint32_t test_ptr
    while not is_nil(ptr):
        func(<char*>(ptr + 16), values)
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


cdef void get_single_key_item(char * addr, dict values):
    cdef uint32_t key = read_dword(addr)
    cdef str value = read_wstr(addr+4)
    values[key] = value


cdef void get_double_key_item(char * addr, dict values):
    cdef tuple key = (read_dword(addr), read_dword(addr+4))
    cdef str value = read_wstr(addr+8)
    values[key] = value


def get_static_names():
    return map_to_dict(<char*>tgen_get_manager() + 8388876,
                       get_single_key_item)


def get_entity_names():
    return map_to_dict(<char*>tgen_get_manager() + 8388868,
                       get_single_key_item)


def get_item_names():
    return map_to_dict(<char*>tgen_get_manager() + 8388916,
                       get_double_key_item)


def get_location_names():
    return map_to_dict(<char*>tgen_get_manager() + 8388900,
                       get_double_key_item)


def get_quarter_names():
    return map_to_dict(<char*>tgen_get_manager() + 8388908,
                       get_double_key_item)


def get_skill_names():
    return map_to_dict(<char*>tgen_get_manager() + 8388884,
                       get_single_key_item)


def get_ability_names():
    return map_to_dict(<char*>tgen_get_manager() + 8388892,
                       get_single_key_item)


cdef int get_block_type(Color * block) nogil:
    return block.a & 0x1F

cdef bint get_block_breakable(Color * block) nogil:
    return (block.a & 0x20) != 0

cdef tuple get_block_tuple(Color * block):
    return (block.r, block.g, block.b)


# cdef class XYProxy:
#     cdef ChunkXY * data

#     property a:
#         def __get__(self):
#             return self.data.a

#     property b:
#         def __get__(self):
#             return self.data.b

#     def __len__(self):
#         return self.data.size

#     def __getitem__(self, int index):
#         cdef ChunkEntry * data = &self.data.items[index]
#         return get_block_tuple(data)

#     cpdef int get_type(self, int index):
#         return get_block_type(&self.data.items[index])

#     cpdef bint get_breakable(self, int index):
#         return get_block_breakable(&self.data.items[index])


cdef struct Vertex:
    float x, y, z
    float nx, ny, nz
    unsigned char r, g, b, a


cdef struct Quad:
    Vertex v1, v2, v3, v4


cdef class RenderBuffer:
    cdef vector[Quad] data
    cdef float off_x, off_y

    def __init__(self, ZoneData zone, float off_x, float off_y):
        self.off_x = off_x
        self.off_y = off_y
        with nogil:
            self.fill(zone)

    def get_data(self):
        cdef char * v = <char*>(&self.data[0])
        return v[:self.data.size()*sizeof(Quad)]

    def get_data_pointer(self):
        cdef uintptr_t v = <uintptr_t>(&self.data[0])
        return (v, self.data.size())

    cdef void fill(self, ZoneData proxy) nogil:
        cdef int x, y, i, n, z
        cdef Field * xy
        cdef Color * block
        for i in range(256*256):
            x = i % 256
            y = i / 256
            xy = &(<Field*>proxy.data[0].fields)[i]
            for z in range(min(xy.b, 0), <int>(xy.a + xy.size)):
                if proxy.get_neighbor_solid_c(x, y, z):
                    continue
                if z < xy.a:
                    self.add_block(proxy, x, y, z, &(<Color*>xy.data)[0])
                    continue
                block = &(<Color*>xy.data)[z - xy.a]
                if get_block_type(block) == EMPTY_TYPE:
                    continue
                self.add_block(proxy, x, y, z, block)

    cdef void add_block(self, ZoneData proxy, int x, int y, int z,
                        Color * block) nogil:
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



# cdef class ItemWithHeaderList:
#     cdef public:
#         list items

#     def __cinit__(self, char * addr):
#         cdef char * vec_start = <char*>read_dword(addr)
#         cdef char * vec_end = <char*>read_dword(addr+4)
#         cdef uint32_t vec_capacity = read_dword(addr+8)

#         cdef ByteReader reader = create_reader(vec_start,
#                                                vec_end - vec_start)
#         self.items = []
#         cdef uint32_t header
#         cdef object item
#         for _ in range((vec_end - vec_start) // 4):
#             header = reader.read_uint32()
#             item = ItemData()
#             item.read(reader)
#             self.items.append((header, item))


# cdef list read_item_with_header_lists(char * start, char * end):
#     cdef list items = []
#     cdef char * vec_item
#     for _ in range((end - start) // 4):
#         vec_item = <char*>read_dword(start)
#         items.append(ItemWithHeaderList(vec_item))
#         start += 4
#     return items


# cdef class StaticEntity:
#     cdef public:
#         object header
#         list items
#         object item

#     def __cinit__(self, ByteReader reader):
#         self.header = StaticEntityHeader()
#         self.header.read(reader)
#         cdef uint32_t vec_start = reader.read_uint32()
#         cdef uint32_t vec_end = reader.read_uint32()
#         cdef uint32_t vec_capacity = reader.read_uint32()
#         cdef uint32_t something1 = reader.read_uint32()
#         self.item = ItemData()
#         self.item.read(reader)
#         cdef uint32_t something2 = reader.read_uint32()
#         cdef uint32_t something3 = reader.read_uint32()
#         cdef uint32_t something4 = reader.read_uint32()
#         cdef uint32_t something5 = reader.read_uint32()
#         cdef uint32_t something6 = reader.read_uint32()
#         cdef uint32_t something7 = reader.read_uint32()

#         ## disabled for now
#         # self.items = read_item_with_header_lists(vec_start, vec_end)


# cdef class DynamicEntity:
#     # cube::Spawn

#     cdef public:
#         object pos
#         uint32_t hostile_type
#         uint32_t class_type
#         uint32_t specialization
#         uint32_t entity_type
#         int32_t level
#         uint64_t entity_id
#         uint32_t flags_bit_3
#         float yaw
#         uint32_t power_base
#         uint32_t not_used19
#         object not_used20
#         object appearance
#         list equipment
#         float max_hp_multiplier
#         float shoot_speed
#         float damage_multiplier
#         float armor_multiplier
#         float resi_multiplier
#         uint32_t unknown_or_not_used4
#         str name

#     def __cinit__(self, ByteReader reader):
#         reader.seek(16)
#         self.pos = reader.read_qvec3()
#         self.hostile_type = reader.read_uint8()
#         reader.skip(3)
#         self.entity_type = reader.read_uint32()
#         self.class_type = reader.read_uint8()
#         self.specialization = reader.read_uint8()
#         reader.skip(2)
#         self.level = reader.read_uint32()
#         reader.skip(4*4)
#         self.entity_id = reader.read_uint64()
#         self.flags_bit_3 = reader.read_uint8()
#         reader.skip(3)
#         self.yaw = reader.read_float()
#         self.power_base = reader.read_uint8()
#         reader.skip(3)
#         self.not_used19 = reader.read_uint8()
#         reader.skip(3)
#         self.not_used20 = reader.read_ivec3()
#         reader.skip(4*2)
#         self.appearance = AppearanceData()
#         self.appearance.read(reader)

#         self.equipment = []

#         cdef object item
#         for _ in range(13):
#             item = ItemData()
#             item.read(reader)
#             self.equipment.append(item)

#         reader.skip(304) # ItemWithExtra

#         reader.skip(11 * 4)
#         self.unknown_or_not_used4 = reader.read_uint32()
#         self.name = reader.read_ascii(16)
#         reader.skip(4*3 + 1 + 7)

#     def set_entity(self, object entity):
#         entity.pos = self.pos
#         entity.spawn_pos = self.pos.copy()
#         entity.hostile_type = self.hostile_type
#         entity.entity_type = self.entity_type
#         entity.class_type = self.class_type
#         entity.specialization = self.specialization
#         entity.level = self.level

#         if self.flags_bit_3:
#             entity.flags |= 1 << 3
#         else:
#             entity.flags &= ~(1 << 3)

#         entity.body_yaw = self.yaw
#         entity.power_base = self.power_base
#         entity.not_used19 = self.not_used19
#         entity.not_used20 = self.not_used20

#         entity.appearance = self.appearance
#         entity.equipment = self.equipment
#         entity.max_hp_multiplier = self.max_hp_multiplier
#         entity.shoot_speed = self.shoot_speed
#         entity.damage_multiplier = self.damage_multiplier
#         entity.armor_multiplier = self.armor_multiplier
#         entity.resi_multiplier = self.resi_multiplier
#         entity.unknown_or_not_used4

#         entity.name = self.name

#         if self.appearance.flags & 0x200:
#             entity.appearance.scale *= 2.0

#         cdef float off_z = entity.appearance.scale.z * 0.5 + 0.1
#         entity.pos.z += off_z * BLOCK_SCALE

#         # some default values
#         entity.consumable = ItemData()
#         entity.velocity = Vector3()
#         entity.accel = Vector3()
#         entity.extra_vel = Vector3()
#         entity.ray_hit = Vector3()
#         entity.start_chunk = Vector3()
#         entity.skills = [0] * 11

#     def get_type(self):
#         return ENTITY_NAMES[self.entity_type]

cdef char * get_region(void * manager, uint32_t reg_x, uint32_t reg_y) nogil:
    cdef char * p = <char*>manager + 188
    cdef uint32_t v = (<uint32_t*>p)[reg_y + reg_x * 1024]
    return <char*>v

cdef Zone * get_zone(void * manager, uint32_t zone_x, uint32_t zone_y) nogil:
    cdef uint32_t reg_x = zone_x / 64
    cdef uint32_t reg_y = zone_y / 64
    cdef char * reg = get_region(manager, reg_x, reg_y)
    cdef char * p = <char*>reg + 65560
    zone_x %= 64
    zone_y %= 64
    cdef uint32_t v = (<uint32_t*>p)[zone_y + zone_x * 64]
    return <Zone*>v

cdef class ZoneData(WrapZone):
    # chunk::Zone

    cdef Heap * heap
    cdef char * region

    cdef public:
        uint32_t x, y

    def __init__(self, x, y):
        self.x = x
        self.y = y

        with nogil:
            self.heap = tgen_generate_chunk(self.x, self.y)
            self.data = get_zone(tgen_get_manager(), self.x, self.y)
            self.region = get_region(tgen_get_manager(),
                                     self.x / 64, self.y / 64)

        if self.data == NULL:
            print('Invalid zone')
        if self.region == NULL:
            print('Invalid region')

    def get_region(self):
        return <uint32_t>self.region

    cdef _destroy(self):
        if self.heap == NULL:
            return
        tgen_destroy_chunk(self.heap)
        self.heap = NULL
        self.data = NULL
        self.region = NULL

    def destroy(self):
        self._destroy()

    def __dealloc__(self):
        self._destroy()

    cdef bint get_solid_c(self, int x, int y, int z) nogil:
        if x < 0 or x >= 256 or y < 0 or y >= 256:
            return False
        cdef Field * data = self.get_xy(x, y)
        if z < data.a:
            return True
        z -= data.a
        if z >= <int>data.size:
            return False
        return get_block_type(&(<Color*>data.data)[z]) != EMPTY_TYPE

    def get_solid(self, x, y, z):
        return self.get_solid_c(x, y, z)

    cdef Field * get_xy(self, int x, int y) nogil:
        return &(<Field*>self.data.fields)[x + y * 256]

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
        cdef Field * xy
        cdef Color * block
        for i in range(256*256):
            x = i % 256
            y = i / 256
            xy = &(<Field*>self.data.fields)[x + y * 256]
            for z in range(xy.b, <int>(xy.a + xy.size)):
                if self.get_neighbor_solid_c(x, y, z):
                    continue
                if z < xy.a:
                    blocks[(x, y, z)] = get_block_tuple(&(<Color*>xy.data)[0])
                    continue
                block = &(<Color*>xy.data)[z - xy.a]
                if get_block_type(block) == EMPTY_TYPE:
                    continue
                blocks[(x, y, z)] = get_block_tuple(block)
        return blocks

    def get_render(self, off_x=0.0, off_y=0.0):
        return RenderBuffer(self, off_x, off_y)

    def get_height(self, x, y):
        cdef Field * data = self.get_xy(x, y)
        return (<int64_t>(data.a) + <int64_t>(data.size))

def add_region(ZoneData zone):
    sim_add_region(zone.region, zone.x / 64, zone.y / 64)

def remove_region(ZoneData zone):
    sim_remove_region(zone.x / 64, zone.y / 64)

def add_zone(ZoneData zone):
    sim_add_zone(<CZone*>zone.data, zone.x, zone.y)

def remove_zone(ZoneData zone):
    sim_remove_zone(zone.x, zone.y)

def step(uint32_t dt):
    sim_step(dt)

def remove_creature(WrapCreature creature):
    sim_remove_creature(<CCreature*>creature.data)
    # bound to mess up some people, let's free on __dealloc__ in the future
    creature.data = NULL

def add_creature(uint64_t id):
    cdef CCreature * c = sim_add_creature(id)
    cdef WrapCreature wrap = WrapCreature.__new__(WrapCreature)
    wrap.data = <Creature*>c
    return wrap

cdef dict creature_map = {}

cdef void get_creature_map(CCreature * c):
    cdef WrapCreature wrap = WrapCreature.__new__(WrapCreature)
    wrap.data = <Creature*>c
    creature_map[wrap.data[0].entity_id] = wrap

def get_creatures():
    creature_map.clear()
    sim_get_creatures(get_creature_map)
    return creature_map
