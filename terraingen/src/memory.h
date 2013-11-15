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

#ifndef TERRAINGEN_MEMORY_H
#define TERRAINGEN_MEMORY_H

#include <inttypes.h>
#include <boost/unordered_map.hpp>
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
    char * data;
    size_t data_size;
    uint32_t segment_table[6];

    uint32_t heap_offset;

#ifdef DEBUG_MEMORY
    uint32_t * alloc_table;
#endif

    Memory();
    void write_file(uint32_t address, const char * filename);
    void write_section(uint32_t address, const char * filename);
    void pad_section(uint32_t address, size_t size);
    void write(uint32_t address, const char * s, size_t len);
    void read(uint32_t address, char * s, size_t len);
    char * translate(uint32_t addr);
    void set_size(size_t size);

    // read/write
    void read_byte(uint32_t address, uint8_t * arg);
    uint8_t read_byte(uint32_t address);
    void read_word(uint32_t address, uint16_t * arg);
    uint16_t read_word(uint32_t address);
    void read_dword(uint32_t address, uint32_t * arg);
    uint32_t read_dword(uint32_t address);
    void read_qword(uint32_t address, uint64_t * arg);
    uint64_t read_qword(uint32_t address);
    void read_dqword(uint32_t address, XMMReg * arg);
    XMMReg read_dqword(uint32_t address);
    void write_byte(uint32_t address, uint8_t arg);
    void write_word(uint32_t address, uint16_t arg);
    void write_dword(uint32_t address, uint32_t arg);
    void write_qword(uint32_t address, uint64_t arg);

    // heap
    uint32_t heap_alloc(uint32_t size);
    void heap_dealloc(uint32_t address);

    // helper functions
    void copy_mem(uint32_t dest, uint32_t src, uint32_t size);
    void move_mem(uint32_t dest, uint32_t src, uint32_t size);
    void set_mem(uint32_t ptr, uint32_t value, uint32_t size);

};

#endif // TERRAINGEN_MEMORY_H
