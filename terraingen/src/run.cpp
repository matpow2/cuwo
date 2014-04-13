/*
    Copyright (c) Mathias Kaerlev 2013-2014.

    This file is part of cuwo.

    cuwo is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    cuwo is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with cuwo.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "main.h"
#include "gensrc/out.cpp"
#include "imports.h"
#include "terraingen.h"
#include <fstream>

#define MANAGER_ADDRESS mem.manager

/*
Some3Data:
    88: ItemData

struct ChunkParent, size 200
{
  int vtable; - pointer
  int b; - pointer
  int c; - value (size?)
  Some3Data * some3_start;
  Some3Data * some3_end;
  _DWORD some3_capacity;
  _DWORD some1_4bytep_start;
  _DWORD some1_4bytep_end;
  _DWORD some1_capacity;
  _DWORD some4_start;
  _DWORD some4_end;
  _DWORD some4_capacity;
  _DWORD chunkitems_start;
  _DWORD chunkitems_end;
  _DWORD chunkitems_capacity;
  _DWORD some9_start;
  _DWORD some9_end;
  _DWORD some9_capacity;
  _DWORD some8_start;
  _DWORD some8_end;
  _DWORD some8_capacity;
  _DWORD some7_start;
  _DWORD some7_end;
  _DWORD some7_capacity;
  _DWORD chunk_x;
  _DWORD chunk_y;
  _DWORD some2_20byte_start;
  _DWORD some2_20byte_end;
  _DWORD some2_capacity;
  _BYTE word74;
  _BYTE has_chunkitems;
  _BYTE byte76;
  _BYTE pad;
  _DWORD dword78;
  _DWORD dword7C;
  _DWORD dword80;
  _BYTE byte84;
  _BYTE pad2[3];
  _DWORD some5_start;
  _DWORD some5_end;
  _DWORD some5_capacity;
  _DWORD some6_start;
  _DWORD some6_end;
  _DWORD some6_capacity;
  _DWORD dwordA0;
  _DWORD dwordA4;
  ChunkEntry *chunk_data;
  _DWORD other_chunk_data;
  struct _RTL_CRITICAL_SECTION rtl_critical_sectionB0;
};

*/

void save_chunk(uint32_t addr, ChunkData * data)
{
    // read items
    uint32_t start_items = mem.read_dword(addr + 48);
    uint32_t end_items = mem.read_dword(addr + 52);
    data->item_size = end_items - start_items;
    data->item_data = new char[data->item_size];
    mem.read(start_items, data->item_data, data->item_size);

    uint32_t entry = mem.read_dword(addr + 168);
    for (int i = 0; i < 256*256; i++) {
        ChunkXY & c = data->items[i];
        // uint32_t vtable = mem.read_dword(entry);
        // float something = to_ss(mem.read_dword(entry+4));
        // float something2 = to_ss(mem.read_dword(entry+8));
        // float something3 = to_ss(mem.read_dword(entry+12));
        uint32_t something4 = mem.read_dword(entry+16);
        uint32_t something5 = mem.read_dword(entry+20);
        uint32_t chunk_data = mem.read_dword(entry+24);
        uint32_t data_size = mem.read_dword(entry+28); // * 4, size
        char * out_data = new char[data_size*4];
        mem.read(chunk_data, out_data, data_size*4);

        // write it out
        c.a = something4;
        c.b = something5;
        c.size = data_size;
        c.items = (ChunkEntry*)out_data;
        entry += 32;
    }
}

static SavedHeap saved_heap;
static char saved_stack[STACK_SIZE];

ChunkData * tgen_generate_chunk(unsigned int x, unsigned int y)
{
    ChunkData * data = new ChunkData;
    data->x = x;
    data->y = y;

    cpu.reset_stack();
    cpu.push_dword(y);
    cpu.push_dword(x);
    get_self() = MANAGER_ADDRESS;
    add_ret();
    generator_func();

    // save_chunk_now();
    // return 0;
    // address 405E30 is
    // void * __thiscall get_sector_chunk_data(__int64 chunk_pos)
    cpu.push_dword(y);
    cpu.push_dword(x);
    get_self() = MANAGER_ADDRESS;
    add_ret();
    sub_405E30();
    save_chunk(cpu.reg[EAX], data);

    // restore heap
    mem.restore_heap(saved_heap);
    // memcpy(mem.stack, saved_stack, STACK_SIZE);

    return data;
}

unsigned int tgen_generate_debug_chunk(const char * filename,
                                       unsigned int x, unsigned int y)
{
    ChunkData * data = new ChunkData;
    data->x = x;
    data->y = y;

    cpu.reset_stack();
    cpu.push_dword(y);
    cpu.push_dword(x);
    get_self() = MANAGER_ADDRESS;
    add_ret();
    generator_func();

    // save_chunk_now();
    // return 0;
    // address 405E30 is
    // void * __thiscall get_sector_chunk_data(__int64 chunk_pos)
    cpu.push_dword(y);
    cpu.push_dword(x);
    get_self() = MANAGER_ADDRESS;
    add_ret();
    sub_405E30();
    uint32_t chunk_offset = cpu.reg[EAX];
    tgen_dump_mem(filename);

    // restore heap
    mem.restore_heap(saved_heap);
    // memcpy(mem.stack, saved_stack, STACK_SIZE);

    return chunk_offset;
}

void tgen_destroy_chunk(ChunkData * data)
{
    for (int i = 0; i < 256*256; i++) {
        delete[] data->items[i].items;
    }
    delete data;
}

static uint32_t global_seed = 626466;
static std::string translated_path;
static std::string data_path;

uint32_t get_seed()
{
    return global_seed;
}

const char * translate_path(char * path)
{
    translated_path = path;
    std::replace(translated_path.begin(), translated_path.end(), '\\', '/');
    size_t pos = translated_path.find_last_of("/");
    if (pos != std::string::npos) {
        translated_path = translated_path.substr(pos + 1);
    }
    translated_path = data_path + translated_path;
    return translated_path.c_str();
}

void tgen_set_path(const char * dir)
{
    data_path = dir;
}

void tgen_set_seed(unsigned int seed)
{
    global_seed = seed;
}

void tgen_init()
{
    static bool initialized = false;
    if (initialized)
        return;
    initialized = true;
    rebase_data();
    init_function_map();
    init_static();
    entry_point();

    // save memory state
    mem.save_heap(saved_heap);
    // memcpy(saved_stack, mem.stack, STACK_SIZE);
}

void tgen_dump_mem(const char * filename)
{
    std::ofstream fp(filename, std::ios::binary);
    fp.write(mem.heap, mem.heap_offset);
    fp.close();
}
