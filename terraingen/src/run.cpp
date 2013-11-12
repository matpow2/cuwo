void save_chunk_now();

#include "main.h"
#include "gensrc/stubs.h"
#include "gensrc/out.cpp"
#include "imports.h"
#include <iostream>
#include <fstream>
#include <string>
#include <boost/lexical_cast.hpp>

// inline includes
#include "cpu.cpp"
#include "memory.cpp"

CPU cpu;
Memory mem;

// VERY specific address - this is the start of the heap, where the game
// manager has been allocated
#define MANAGER_ADDRESS STACK_END

void save_chunk(uint32_t addr)
{
    static int index = -1;
    index++;
    std::string filename = "genout" + boost::lexical_cast<std::string>(index)
                           + ".bin";
    std::cout << "Save chunk: " << addr << std::endl;
    std::ofstream fp(filename.c_str(), std::ios::out | std::ios::binary);
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

void save_chunk_now()
{
    // static bool should_save = true;
    // if (!should_save)
    //     return;
    // should_save = false;

    // hardcoded, for debug
    save_chunk(101495531);
}

int main(int argc, const char ** argv)
{
    init_function_map();
    start();
    std::cout << "Generator setup!" << std::endl;

    cpu.reset_stack();
    cpu.push_dword(0x8020);
    cpu.push_dword(0x8020);
    get_self() = MANAGER_ADDRESS;
    add_ret();
    generator_func();

    save_chunk_now();
    return 0;
    // address 405E30 is
    // void * __thiscall get_sector_chunk_data(__int64 chunk_pos)
    cpu.push_dword(0x8020);
    cpu.push_dword(0x8020);
    get_self() = MANAGER_ADDRESS;
    add_ret();
    sub_405E30();
    save_chunk(cpu.reg[EAX]);
    return 0;
}