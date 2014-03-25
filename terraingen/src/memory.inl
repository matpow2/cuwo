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

#include <string.h>
#include <fstream>
#include <iostream>
#include "config.h"
#include "main.h"
#include "../gensrc/sections.h"

FORCE_INLINE Memory::Memory()
{
    for (int i = 0; i < 6; i++)
        segment_table[i] = 0;
    segment_table[FS] = translate(fs_segment);

    set_heap_size(96 * 1024 * 1024); // allocate 96 mb
}

FORCE_INLINE void Memory::pad_section(uint32_t address, size_t size)
{
    char * data = new char[size]();
    write(address, data, size);
    delete[] data;
}

#ifdef DEBUG_MEMORY
inline void log_access(uint32_t addr)
{
    std::cout << "Could not translate address " << addr << std::endl;
    exit(0);
}
#endif

inline bool test_range(char * res, char * start, int size)
{
    return res >= start || res < (start+size);
}

inline bool test_address(char * res, uint32_t addr, size_t size)
{
#ifdef DEBUG_MEMORY
    if (res == NULL) {
        log_access(addr);
        return false;
    }
    if (test_range(res, data_section, sizeof(data_section)))
        return true;
    if (test_range(res, rdata_section, sizeof(rdata_section)))
        return true;
    if (test_range(res, mem.stack, sizeof(mem.stack)))
        return true;
    if (test_range(res, mem.heap, mem.heap_size))
        return true;
    log_access(addr);
    return false;
#else
    return true;
#endif
}

#define MEMORY_BASE_POINTER (&data_section[0])

FORCE_INLINE char * Memory::translate(uint32_t val)
{
#ifdef IS_64_BIT
    return MEMORY_BASE_POINTER + int32_t(val);
#else
    return (char*)val;
#endif
}

inline void print_fail(uint64_t v)
{
    std::cout << "Translation failing on " << v << std::endl;
}

FORCE_INLINE uint32_t Memory::translate(char * address)
{
#ifdef IS_64_BIT
    int64_t v = (int64_t)(address - MEMORY_BASE_POINTER);
    if ((uint64_t)v > 0xFFFFFFFF) {
        print_fail(v);
    }
    return uint32_t(int32_t(v));
#else
    return (uint32_t)address;
#endif
}

template <class T>
FORCE_INLINE T * test_alloc(T * out)
{
    if (out == NULL) {
        std::cout << "Could not allocate enough memory" << std::endl;
        exit(0);
        return NULL;
    }
    return out;
}

#ifndef IS_32_BIT
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#endif // _WIN32
#endif // IS_32_BIT

FORCE_INLINE void Memory::set_heap_size(size_t size)
{
#ifdef IS_32_BIT
    heap = test_alloc((char*)malloc(size));
#else
#ifdef _WIN32
    heap = VirtualAlloc(MEMORY_BASE_POINTER, size, MEM_COMMIT | MEM_RESERVE,
                        PAGE_READWRITE);
#else
    heap = (char*)mmap((void*)MEMORY_BASE_POINTER, size,
                       PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,
                       -1, 0);
    if (uint64_t(heap) > 0xFFFFFFFF) {
        std::cout << "Heap alloc out of range" << std::endl;
    }
    if ((void*)heap == MAP_FAILED) {
        std::cout << "mmap failed!" << std::endl;
    }

#endif // _WIN32
#endif // IS_32_BIT
    heap_size = size;
}

FORCE_INLINE void Memory::write(uint32_t addr, const char * src, size_t len)
{
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, len))
        return;
#endif
    memcpy(ptr, src, len);
}

FORCE_INLINE void Memory::read(char * addr, char *dest, size_t len)
{
    memcpy(dest, addr, len);
}

FORCE_INLINE void Memory::read(uint32_t addr, char *dest, size_t len)
{
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, len))
        return;
#endif
    memcpy(dest, ptr, len);
}

FORCE_INLINE void Memory::read_byte(uint32_t addr, uint8_t * byte)
{
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 1))
        return;
#endif
    *byte = *((uint8_t*)ptr);
}

FORCE_INLINE uint8_t Memory::read_byte(uint32_t addr)
{
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 1))
        return 0;
#endif
    return *((uint8_t*)ptr);
}

FORCE_INLINE void Memory::read_word(uint32_t addr, uint16_t * arg)
{
#ifdef IS_BIG_ENDIAN
    uint16_t val;
    read(addr, (char*)&val, 2);
    val = ((val & 0xff00) >> 8) | 
          ((val & 0x00ff) << 8);
    *arg = val;
#else
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 2))
        return;
#endif
    *arg = *((uint16_t*)ptr);
#endif
}

FORCE_INLINE uint16_t Memory::read_word(uint32_t addr)
{
#ifdef IS_BIG_ENDIAN
    uint16_t val;
    read(addr, (char*)&val, 2);
    val =  ((val & 0xff00) >> 8) | 
           ((val & 0x00ff) << 8);
    return val;
#else
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 2))
        return 0;
#endif
    return *((uint16_t*)ptr);
#endif
}

FORCE_INLINE void Memory::read_dword(char * addr, uint32_t * dword)
{
#ifdef IS_BIG_ENDIAN
    uint32_t val;
    read(addr, (char*)&val, 4);
    val =  ((val & 0xff000000) >> 24) | 
           ((val & 0x00ff0000) >> 8)  | 
           ((val & 0x0000ff00) << 8) | 
           ((val & 0x000000ff) << 24);
    *dword = val;
#else
    *dword = *((uint32_t*)addr);
#endif
}

FORCE_INLINE void Memory::read_dword(uint32_t addr, uint32_t * dword)
{
#ifdef IS_BIG_ENDIAN
    uint32_t val;
    read(addr, (char*)&val, 4);
    val =  ((val & 0xff000000) >> 24) | 
           ((val & 0x00ff0000) >> 8)  | 
           ((val & 0x0000ff00) << 8) | 
           ((val & 0x000000ff) << 24);
    *dword = val;
#else
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 4))
        return;
#endif
    *dword = *((uint32_t*)ptr);
#endif
}

FORCE_INLINE uint32_t Memory::read_dword(uint32_t addr)
{
#ifdef IS_BIG_ENDIAN
    uint32_t val;
    read(addr, (char*)&val, 4);
    val =  ((val & 0xff000000) >> 24) | 
           ((val & 0x00ff0000) >> 8)  | 
           ((val & 0x0000ff00) << 8) | 
           ((val & 0x000000ff) << 24);
    *dword = val;
#else
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 4))
        return 0;
#endif
    return *((uint32_t*)ptr);
#endif
}

FORCE_INLINE uint32_t Memory::read_dword(char * addr)
{
#ifdef IS_BIG_ENDIAN
    uint32_t val;
    read(addr, (char*)&val, 4);
    val =  ((val & 0xff000000) >> 24) | 
           ((val & 0x00ff0000) >> 8)  | 
           ((val & 0x0000ff00) << 8) | 
           ((val & 0x000000ff) << 24);
    *dword = val;
#else
    return *((uint32_t*)addr);
#endif
}

FORCE_INLINE void Memory::read_qword(uint32_t addr, uint64_t * qword)
{
#ifdef IS_BIG_ENDIAN
    uint64_t val;
    read(addr, (char*)&val, 8);
    val = ((val & 0xff00000000000000) >> 56) |
          ((val & 0x00ff000000000000) >> 40) |
          ((val & 0x0000ff0000000000) >> 24) |
          ((val & 0x000000ff00000000) >> 8) |
          ((val & 0x00000000ff000000) << 8) |
          ((val & 0x0000000000ff0000) << 24) |
          ((val & 0x000000000000ff00) << 40) |
          ((val & 0x00000000000000ff) << 56);
    *qword = val;
#else
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 8))
        return;
#endif
    *qword = *((uint64_t*)ptr);
#endif
}

FORCE_INLINE uint64_t Memory::read_qword(uint32_t addr)
{
#ifdef IS_BIG_ENDIAN
    uint64_t val;
    read(addr, (char*)&val, 8);
    val = ((val & 0xff00000000000000) >> 56) |
          ((val & 0x00ff000000000000) >> 40) |
          ((val & 0x0000ff0000000000) >> 24) |
          ((val & 0x000000ff00000000) >> 8) |
          ((val & 0x00000000ff000000) << 8) |
          ((val & 0x0000000000ff0000) << 24) |
          ((val & 0x000000000000ff00) << 40) |
          ((val & 0x00000000000000ff) << 56);
    *qword = val;
#else
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 8))
        return 0;
#endif
    return *((uint64_t*)ptr);
#endif
}

FORCE_INLINE void Memory::read_dqword(uint32_t addr, XMMReg * dqword)
{
    read_qword(addr, &dqword->u64(0));
    read_qword(addr+8, &dqword->u64(1));
}

FORCE_INLINE XMMReg Memory::read_dqword(uint32_t addr)
{
    XMMReg reg;
    read_dqword(addr, &reg);
    return reg;
}

FORCE_INLINE void Memory::write_byte(uint32_t addr, uint8_t byte)
{
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 1))
        return;
#endif
    *((uint8_t*)ptr) = byte;
}

FORCE_INLINE void Memory::write_word(uint32_t addr, uint16_t word)
{
#ifdef IS_BIG_ENDIAN
    word = ((word & 0xff00) >> 8) | 
           ((word & 0x00ff) << 8);
#endif
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 2))
        return;
#endif
    *((uint16_t*)ptr) = word;
}

FORCE_INLINE void Memory::write_dword(char * address, uint32_t dword)
{
#ifdef IS_BIG_ENDIAN
    dword = ((dword & 0xff000000) >> 24) |
            ((dword & 0x00ff0000) >> 8) |
            ((dword & 0x0000ff00) << 8) |
            ((dword & 0x000000ff) << 24);
#endif
    *((uint32_t*)address) = dword;
}

FORCE_INLINE void Memory::write_dword(uint32_t addr, uint32_t dword)
{
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 4))
        return;
#endif
    write_dword(ptr, dword);
}

FORCE_INLINE void Memory::write_qword(uint32_t addr, uint64_t qword)
{
#ifdef IS_BIG_ENDIAN
    qword = ((qword & 0xff00000000000000) >> 56) |
            ((qword & 0x00ff000000000000) >> 40) |
            ((qword & 0x0000ff0000000000) >> 24) |
            ((qword & 0x000000ff00000000) >> 8) |
            ((qword & 0x00000000ff000000) << 8) |
            ((qword & 0x0000000000ff0000) << 24) |
            ((qword & 0x000000000000ff00) << 40) |
            ((qword & 0x00000000000000ff) << 56);
#endif
    char * ptr = translate(addr);
#ifdef DEBUG_MEMORY
    if (!test_address(ptr, addr, 8))
        return;
#endif
    *((uint64_t*)ptr) = qword;
}

FORCE_INLINE uint32_t Memory::heap_alloc(uint32_t size)
{
    uint32_t ret = translate(heap + heap_offset);
    // add size to heap offset and align to 8-byte boundary
#ifdef IS_32_BIT
    heap_offset = (heap_offset + size + 8 - 1) & ~(8 - 1);
#else
    heap_offset = (heap_offset + size + 16 - 1) & ~(16 - 1);
#endif
    // heap_size = heap_size+size;
    if (heap_offset > heap_size) {
        std::cout << "Heap too small: " << heap_offset << " " << heap_size
            << std::endl;
        exit(0);
    }
    // set_heap_size(heap_offset);
    return ret;
}

FORCE_INLINE void Memory::heap_dealloc(uint32_t address)
{
    // do nothing right now
}

FORCE_INLINE void Memory::copy_mem(uint32_t dest, uint32_t src, uint32_t size)
{
    if (size == 0)
        return;

    char * addr1 = translate(dest);
#ifdef DEBUG_MEMORY
    if (!test_address(addr1, dest, size))
        return;
#endif

    char * addr2 = translate(src);
#ifdef DEBUG_MEMORY
    if (!test_address(addr2, src, size))
        return;
#endif

    memcpy(addr1, addr2, size);
}

FORCE_INLINE void Memory::move_mem(uint32_t dest, uint32_t src, uint32_t size)
{
    if (size == 0)
        return;

    char * addr1 = translate(dest);
#ifdef DEBUG_MEMORY
    if (!test_address(addr1, dest, size))
        return;
#endif

    char * addr2 = translate(src);
#ifdef DEBUG_MEMORY
    if (!test_address(addr2, src, size))
        return;
#endif

    memmove(addr1, addr2, size);
}

FORCE_INLINE void Memory::set_mem(uint32_t ptr, uint32_t value, uint32_t size)
{
    if (size == 0)
        return;

    char * addr = translate(ptr);
#ifdef DEBUG_MEMORY
    if (!test_address(addr, ptr, size))
        return;
#endif

    memset(addr, value, size);
}
