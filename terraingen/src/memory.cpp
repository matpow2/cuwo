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

#include "memory.h"
#include "config.h"

#ifdef NO_INLINE
#include "memory.inl"
#endif

char * Memory::data = NULL;
size_t Memory::data_size = 0;
uint32_t Memory::segment_table[6];
uint32_t Memory::heap_offset = 0;
#ifdef DEBUG_MEMORY
uint32_t * Memory::alloc_table = NULL;
#endif

Memory mem;
