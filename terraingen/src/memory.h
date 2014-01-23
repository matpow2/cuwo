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

#ifndef TERRAINGEN_MEMORY_H
#define TERRAINGEN_MEMORY_H

#include <inttypes.h>
#include <stdlib.h>
#include "sse.h"

enum SegmentRegister
{
    CS = 0,
    SS,
    DS,
    ES,
    FS,
    GS
};

#define HEAP_BASE STACK_END
#define ALLOC_TABLE_SUB (HEAP_BASE - MEMORY_OFFSET)

class Memory
{
public:
    static char * data;
    static size_t data_size;
    static uint32_t segment_table[6];
    static uint32_t heap_offset;

#ifdef DEBUG_MEMORY
    static uint32_t * alloc_table;
#endif

    Memory();
    static void pad_section(uint32_t address, size_t size);
    static void write(uint32_t address, const char * s, size_t len);
    static void read(uint32_t address, char * s, size_t len);
    static char * translate(uint32_t addr);
    static void set_size(size_t size);

    // read/write
    static void read_byte(uint32_t address, uint8_t * arg);
    static uint8_t read_byte(uint32_t address);
    static void read_word(uint32_t address, uint16_t * arg);
    static uint16_t read_word(uint32_t address);
    static void read_dword(uint32_t address, uint32_t * arg);
    static uint32_t read_dword(uint32_t address);
    static void read_qword(uint32_t address, uint64_t * arg);
    static uint64_t read_qword(uint32_t address);
    static void read_dqword(uint32_t address, XMMReg * arg);
    static XMMReg read_dqword(uint32_t address);
    static void write_byte(uint32_t address, uint8_t arg);
    static void write_word(uint32_t address, uint16_t arg);
    static void write_dword(uint32_t address, uint32_t arg);
    static void write_qword(uint32_t address, uint64_t arg);

    // heap
    static uint32_t heap_alloc(uint32_t size);
    static void heap_dealloc(uint32_t address);

    // helper functions
    static void copy_mem(uint32_t dest, uint32_t src, uint32_t size);
    static void move_mem(uint32_t dest, uint32_t src, uint32_t size);
    static void set_mem(uint32_t ptr, uint32_t value, uint32_t size);
};

extern Memory mem;

#ifndef NO_INLINE
#include "memory.inl"
#endif

#endif // TERRAINGEN_MEMORY_H
