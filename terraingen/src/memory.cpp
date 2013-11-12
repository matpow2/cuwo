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

#include "memory.h"
#include <string.h>
#include <fstream>
#include <iostream>
#include "config.h"
#include "main.h"

inline Memory::Memory()
: data_size(0), data(NULL), alloc_table(NULL)
{
    for (int i = 0; i < 6; i++)
        segment_table[i] = 0;
    segment_table[FS] = FS_SEGMENT_OFFSET;

    heap_offset = 0; // from stack end

    set_size(MEMORY_SIZE);
}

inline void Memory::write_section(uint32_t address, const char * filename)
{
    std::ifstream fp(filename, std::ios::binary | std::ios::ate);
    if(!fp) {
        std::cout << "Could not read " << filename << std::endl;
        return;
    }
    std::ifstream::pos_type size = fp.tellg();
    char * data = new char[size];
    fp.seekg(0, std::ios::beg);
    fp.read(data, size);
    fp.close();
    write(address, data, size);
    delete[] data;
}

inline void Memory::write_file(uint32_t address, const char * filename)
{
    std::ifstream fp(filename, std::ios::binary | std::ios::ate);
    if(!fp) {
        std::cout << "Could not read " << filename << std::endl;
        return;
    }
    std::ifstream::pos_type size = fp.tellg();
    char * data = new char[size];
    fp.seekg(0, std::ios::beg);
    fp.read(data, size);
    fp.close();
    write(address, data, size);
    delete[] data;
}

inline void Memory::pad_section(uint32_t address, size_t size)
{
    char * data = new char[size]();
    write(address, data, size);
    delete[] data;
}

inline void log_access(uint32_t addr)
{
    std::cout << "Could not translate address " << addr << std::endl;
    exit(0);
}

inline bool test_alloc_table(uint32_t v, uint32_t addr, uint32_t size)
{
    if (v == 0) {
        log_access(addr);
        return false;
    }

    uint32_t test_addr = addr - HEAP_BASE;

    for (uint32_t i = test_addr; i < test_addr+size; i++) {
        if (v != mem.alloc_table[i]) {
            log_access(addr);
            return false;
        }
    }

    return true;
}

inline bool test_address(char * res, uint32_t addr, size_t size)
{
#ifdef DEBUG_MEMORY
    bool ret = res != NULL;
    if (!ret) {
        log_access(addr);
        return false;
    }
    if (addr < HEAP_BASE)
        return true;

    // search allocation table
    return test_alloc_table(mem.alloc_table[addr-HEAP_BASE], addr, size);
#else
    return true;
#endif
}

inline char * Memory::translate(uint32_t addr)
{
#ifdef DEBUG_MEMORY
    if (addr < MEMORY_OFFSET || addr >= HEAP_BASE+heap_offset)
        return NULL;
#endif
    return &data[addr-MEMORY_OFFSET];
}

template <class T>
inline T * test_alloc(T * out)
{
    if (out == NULL) {
        std::cout << "Could not allocate enough memory" << std::endl;
        exit(0);
        return NULL;
    }
    return out;
}

inline void Memory::set_size(size_t size)
{
    if (size <= data_size)
        return;
    size_t new_size = (size*3)/2; // * 1.5
    if (data == NULL) {
        data = test_alloc((char*)malloc(new_size));
        memset(data, 0, new_size);
    } else {
        data = test_alloc((char*)realloc(data, new_size));
    }

#ifdef DEBUG_MEMORY
    size_t table_size = (new_size - ALLOC_TABLE_SUB) * sizeof(uint32_t);

    if (alloc_table == NULL) {
        alloc_table = test_alloc((uint32_t*)malloc(table_size));
        memset(alloc_table, 0, table_size);
    } else {
        alloc_table = test_alloc((uint32_t*)realloc(alloc_table, table_size));
        size_t old_size = (data_size - ALLOC_TABLE_SUB) * sizeof(uint32_t);
        memset((char*)alloc_table+old_size, 0, table_size-old_size);
    }
#endif

    data_size = new_size;
}

inline void Memory::write(uint32_t addr, const char * src, size_t len)
{
    char * mem = translate(addr);
    if (!test_address(mem, addr, len))
        return;
    memcpy(mem, src, len);
}

inline void Memory::read(uint32_t addr, char *dest, size_t len)
{
    char * mem = translate(addr);
    if (!test_address(mem, addr, len))
        return;
    memcpy(dest, mem, len);
}

inline void Memory::read_byte(uint32_t addr, uint8_t * byte)
{
    char * mem = translate(addr);
    if (!test_address(mem, addr, 1))
        return;
    *byte = *((uint8_t*)mem);
}

inline uint8_t Memory::read_byte(uint32_t addr)
{
    uint8_t ret;
    read_byte(addr, &ret);
    return ret;
}

inline void Memory::read_word(uint32_t addr, uint16_t * arg)
{
#ifdef IS_BIG_ENDIAN
    uint16_t val;
    read(addr, (char*)&val, 2);
    val =  ((val & 0xff00) >> 8) | 
           ((val & 0x00ff) << 8);
    *arg = val;
#else
    read(addr, (char*)arg, 2);
#endif
}

inline uint16_t Memory::read_word(uint32_t addr)
{
    uint16_t ret;
    read_word(addr, &ret);
    return ret;
}

inline void Memory::read_dword(uint32_t addr, uint32_t * dword)
{
#ifdef IS_BIG_ENDIAN
    uint32_t val;
    read(addr, (char*)&val, 4);
    val =  ((val & (0xff000000)) >> 24) | 
           ((val & (0x00ff0000)) >> 8)  | 
           ((val & (0x0000ff00)) << 8) | 
           ((val & (0x000000ff)) << 24);
    *dword = val;
#else
    read(addr, (char*)dword, 4);
#endif
}

inline uint32_t Memory::read_dword(uint32_t addr)
{
    uint32_t ret;
    read_dword(addr, &ret);
    return ret;
}

inline void Memory::read_qword(uint32_t addr, uint64_t * qword)
{
#ifdef IS_BIG_ENDIAN
    uint64_t val;
    read(addr, (char*)&val, 8);
    val = ((val & (0xff00000000000000)) >> 56) |
          ((val & (0x00ff000000000000)) >> 40) |
          ((val & (0x0000ff0000000000)) >> 24) |
          ((val & (0x000000ff00000000)) >> 8) |
          ((val & (0x00000000ff000000)) << 8) |
          ((val & (0x0000000000ff0000)) << 24) |
          ((val & (0x000000000000ff00)) << 40) |
          ((val & (0x00000000000000ff)) << 56);
    *qword = val;
#else
    read(addr, (char*)qword, 8);
#endif
}

inline uint64_t Memory::read_qword(uint32_t addr)
{
    uint64_t ret;
    read_qword(addr, &ret);
    return ret;
}

inline void Memory::read_dqword(uint32_t addr, XMMReg * dqword)
{
    read_qword(addr, &dqword->u64(0));
    read_qword(addr+8, &dqword->u64(1));
}

inline XMMReg Memory::read_dqword(uint32_t addr)
{
    XMMReg reg;
    read_dqword(addr, &reg);
    return reg;
}

inline void Memory::write_byte(uint32_t addr, uint8_t byte)
{
    char *address = translate(addr);
    
    if (!test_address(address, addr, 1))
        return;
    
    *((uint8_t *)address) = byte;
}

inline void Memory::write_word(uint32_t addr, uint16_t word)
{
#ifdef IS_BIG_ENDIAN
    word = ((word & 0xff00) >> 8) | 
          ((word & 0x00ff) << 8);
#endif
    write(addr, (char*)&word, 2);
}

inline void Memory::write_dword(uint32_t addr, uint32_t dword)
{
#ifdef IS_BIG_ENDIAN
    dword = ((dword & (0xff000000)) >> 24) |
            ((dword & (0x00ff0000)) >> 8) |
            ((dword & (0x0000ff00)) << 8) |
            ((dword & (0x000000ff)) << 24);
#endif
    write(addr, (char*)&dword, 4);
}

inline void Memory::write_qword(uint32_t addr, uint64_t qword)
{
#ifdef IS_BIG_ENDIAN
    qword = ((qword & (0xff00000000000000)) >> 56) |
            ((qword & (0x00ff000000000000)) >> 40) |
            ((qword & (0x0000ff0000000000)) >> 24) |
            ((qword & (0x000000ff00000000)) >> 8) |
            ((qword & (0x00000000ff000000)) << 8) |
            ((qword & (0x0000000000ff0000)) << 24) |
            ((qword & (0x000000000000ff00)) << 40) |
            ((qword & (0x00000000000000ff)) << 56);
#endif
    write(addr, (char*)&qword, 8);
}

inline uint32_t Memory::heap_alloc(uint32_t size)
{
    // char * data = new char[size]();
    uint32_t ret = STACK_END+heap_offset;
    // add size to heap offset and align to 8-byte boundary
    // heap_offset = (heap_offset + size + 8 - 1) & ~(8 - 1);
    heap_offset = heap_offset+size;
    set_size(MEMORY_SIZE+heap_offset);

#ifdef DEBUG_MEMORY
    // set allocation table
    uint32_t table_addr = ret - STACK_END;
    for (uint32_t i = table_addr; i < table_addr+size; i++) {
        alloc_table[i] = ret;
    }
#endif

    // write(ret, data, size);
// #ifdef DEBUG_MEMORY
//     std::cout << "Allocated " << size << " at " << ret << std::endl;
// #endif
    return ret;
}

inline void Memory::heap_dealloc(uint32_t address)
{
    // do nothing right now
#ifdef DEBUG_MEMORY
    uint32_t table_addr = address - STACK_END;

    if (alloc_table[table_addr] != address) {
        std::cout << "Invalid dealloc address: " << address << std::endl;
        exit(0);
    }

    while (true) {
        if (alloc_table[table_addr] != address)
            break;
        mem.alloc_table[table_addr] = 0;
        table_addr++;
    }
    // std::cout << "Deleting " << address << std::endl;
#endif
}

inline void Memory::copy_mem(uint32_t dest, uint32_t src, uint32_t size)
{
    if (size == 0)
        return;

    char * addr1 = translate(dest);
    if (!test_address(addr1, dest, size))
        return;

    char * addr2 = translate(src);
    if (!test_address(addr2, src, size))
        return;

    memcpy(addr1, addr2, size);
}

inline void Memory::move_mem(uint32_t dest, uint32_t src, uint32_t size)
{
    if (size == 0)
        return;

    char * addr1 = translate(dest);
    if (!test_address(addr1, dest, size))
        return;

    char * addr2 = translate(src);
    if (!test_address(addr2, src, size))
        return;

    memmove(addr1, addr2, size);
}

inline void Memory::set_mem(uint32_t ptr, uint32_t value, uint32_t size)
{
    if (size == 0)
        return;

    char * addr = translate(ptr);
    if (!test_address(addr, ptr, size))
        return;

    memset(addr, value, size);
}
