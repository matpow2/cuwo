/*
    Copyright (c) Mathias Kaerlev 2013.

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

// VERY specific address - this is the start of the heap, where the game
// manager has been allocated
#define MANAGER_ADDRESS STACK_END

void save_chunk(uint32_t addr, const char * file)
{
    // std::cout << "Save chunk: " << addr << std::endl;
    std::ofstream fp(file, std::ios::out | std::ios::binary);
    uint32_t entry = mem.read_dword(addr + 168);
    for (int i = 0; i < 256*256; i++) {
        uint32_t vtable = mem.read_dword(entry);
        float something = to_ss(mem.read_dword(entry+4));
        float something2 = to_ss(mem.read_dword(entry+8));
        float something3 = to_ss(mem.read_dword(entry+12));
        uint32_t something4 = mem.read_dword(entry+16);
        uint32_t something5 = mem.read_dword(entry+20);
        uint32_t chunk_data = mem.read_dword(entry+24);
        uint32_t data_size = mem.read_dword(entry+28); // * 4, size
        char * out_data = new char[data_size*4];
        mem.read(chunk_data, out_data, data_size*4);

        // write it out
        fp.write((char*)&something, 4);
        fp.write((char*)&something2, 4);
        fp.write((char*)&something3, 4);
        fp.write((char*)&something4, 4);
        fp.write((char*)&something5, 4);
        fp.write((char*)&data_size, 4);
        fp.write(out_data, data_size*4);
        delete[] out_data;
        entry += 32;
    }
    fp.close();
}

void save_chunk(uint32_t addr, ChunkData * data)
{
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

ChunkData * tgen_generate_chunk(unsigned int x, unsigned int y)
{
    uint32_t heap_offset = mem.heap_offset;

    ChunkData * data = new ChunkData;
    data->x = x;
    data->y = y;

    cpu.reset_stack();
    cpu.push_dword(x);
    cpu.push_dword(y);
    get_self() = MANAGER_ADDRESS;
    add_ret();
    generator_func();

    // save_chunk_now();
    // return 0;
    // address 405E30 is
    // void * __thiscall get_sector_chunk_data(__int64 chunk_pos)
    cpu.push_dword(x);
    cpu.push_dword(y);
    get_self() = MANAGER_ADDRESS;
    add_ret();
    sub_405E30();
    save_chunk(cpu.reg[EAX], data);

    // restore heap offset
    mem.heap_offset = heap_offset;

    return data;
}

void tgen_destroy_chunk(ChunkData * data)
{
    for (int i = 0; i < 256*256; i++) {
        delete[] data->items[i].items;
    }
    delete data;
}

static uint32_t global_seed = 626466;
static std::string data_path;

uint32_t get_seed()
{
    return global_seed;
}

const std::string & get_data_path()
{
    return data_path;
}

void tgen_set_seed(unsigned int seed)
{
    global_seed = seed;
}

void tgen_set_path(const char * path)
{
    data_path = path;
}

void tgen_init()
{
    static bool initialized = false;
    if (initialized)
        return;
    initialized = true;
    init_function_map();
    init_emu();
    init_static();
    entry_point();
}
