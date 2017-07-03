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
#include "tgen.h"
#include <fstream>

#define MANAGER_ADDRESS mem.manager

static SavedHeap saved_heap;

uint32_t tgen_generate_chunk(uint32_t x, uint32_t y)
{
    // restore heap
    mem.restore_heap(saved_heap);

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

    return cpu.reg[EAX];
}

uint32_t tgen_generate_debug_chunk(const char * filename,
                                   uint32_t x, uint32_t y)
{
    // restore heap
    mem.restore_heap(saved_heap);

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

    return chunk_offset;
}

static uint32_t global_seed = 0;
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

uint32_t tgen_get_manager()
{
    return (uint32_t)manager_addr;
}

void tgen_set_path(const char * dir)
{
    data_path = dir;
}

void tgen_set_seed(uint32_t seed)
{
    global_seed = seed;
}

void tgen_init()
{
    static bool initialized = false;
    if (initialized)
        return;
    initialized = true;
    init_noise();
    rebase_data();
    init_function_map();
    init_static();
    entry_point();

    // save memory state
    mem.save_heap(saved_heap);
}

void tgen_dump_mem(const char * filename)
{
    std::ofstream fp(filename, std::ios::binary);
    fp.write(mem.heap, mem.heap_offset);
    fp.close();
}

uint32_t tgen_get_heap_base()
{
    return mem.translate((char*)mem.heap);
}

uint32_t tgen_get_manager()
{
    return MANAGER_ADDRESS;
}

// XXX fix for big-endian

void tgen_read_str(uint32_t addr, std::string & str)
{
    ((basic_string_char*)mem.translate(addr))->str(str);
}

void tgen_read_wstr(uint32_t addr, std::string & str)
{
    ((basic_string_wchar*)mem.translate(addr))->str(str);
}