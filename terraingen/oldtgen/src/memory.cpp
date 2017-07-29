/*
    Copyright (c) Mathias Kaerlev 2013-2017.

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
#include "config.h"

#ifdef NO_INLINE
#include "memory.inl"
#endif

char Memory::heap[HEAP_SIZE];
char Memory::stack[STACK_SIZE];
char Memory::fs_segment[FS_SEGMENT_SIZE];
uint32_t Memory::segment_table[6];
uint32_t Memory::heap_offset = 0;
uint32_t Memory::manager = 0;

Memory mem;

// dlmalloc

extern "C" {
    #define HAVE_MORECORE 1
    #define HAVE_MMAP 0
    #define USE_DL_PREFIX
    #define MORECORE heap_morecore
    void * heap_morecore(int size);
    #include "dlmalloc.c"

    void * heap_morecore(int size)
    {
        void * ret = (void*)(mem.heap + mem.heap_offset);
        mem.heap_offset += size;

        if (mem.heap_offset >= HEAP_SIZE) {
            std::cout << "Heap too small: " << mem.heap_offset << " "
                << HEAP_SIZE << std::endl;
            exit(0);
        }
        return ret;
    }
}

void Memory::save_heap(SavedHeap & data)
{
    data.heap = new char[heap_offset];
    data.heap_size = heap_offset;
    memcpy(data.heap, heap, heap_offset);
    data.state = new malloc_state;
    memcpy(data.state, gm, sizeof(malloc_state));
}

void Memory::restore_heap(const SavedHeap & data)
{
    memcpy(heap, data.heap, data.heap_size);
    heap_offset = data.heap_size;
    memcpy(gm, data.state, sizeof(malloc_state));
}

