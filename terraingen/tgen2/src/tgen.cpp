#include <iostream>
#include <algorithm>
#include <string>
#include "mem.h"
#include "call.h"
#include "msvcstring.h"

static uint32_t global_seed = 0;
static std::string translated_path;
static std::string data_path = "../../../data/";

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

static void * tgen_generate_chunk_return;
static uint32_t tgen_generate_chunk_x;
static uint32_t tgen_generate_chunk_y;
static void tgen_generate_chunk_call()
{
    uint32_t x = tgen_generate_chunk_x;
    uint32_t y = tgen_generate_chunk_y;

    call_x86_thiscall_3(
        get_mem_va(VA_GENERATOR), (uint32_t)manager_data, x, y);

    // address 405E30 is
    // void * __thiscall get_sector_chunk_data(__int64 chunk_pos)
    tgen_generate_chunk_return = (void*)call_x86_thiscall_3(
        get_mem_va(VA_GET_SECTOR_CHUNK_DATA), (uint32_t)manager_data, x, y
    );
}

void * tgen_generate_chunk(uint32_t x, uint32_t y)
{
    tgen_generate_chunk_x = x;
    tgen_generate_chunk_y = y;
    run_with_stack(tgen_generate_chunk_call);
    return tgen_generate_chunk_return;
}

#if 0
uint32_t tgen_generate_debug_chunk(const char * filename,
                                   uint32_t x, uint32_t y)
{
    // restore heap
    mem.restore_heap(saved_heap);

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
#endif

void tgen_set_path(const char * dir)
{
    data_path = dir;
}

void tgen_set_seed(uint32_t seed)
{
    global_seed = seed;
}

// void tgen_dump_mem(const char * filename)
// {
//     std::ofstream fp(filename, std::ios::binary);
//     fp.write(mem.heap, mem.heap_offset);
//     fp.close();
// }

// uint32_t tgen_get_heap_base()
// {
//     return mem.translate((char*)mem.heap);
// }

void * tgen_get_manager()
{
    return manager_data;
}

void tgen_read_str(void * addr, std::string & str)
{
    ((basic_string_char*)addr)->str(str);
}

void tgen_read_wstr(void * addr, std::string & str)
{
    ((basic_string_wchar*)addr)->str(str);
}
