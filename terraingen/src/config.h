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

#ifndef TERRAINGEN_CONFIG_H
#define TERRAINGEN_CONFIG_H

// #define IS_BIG_ENDIAN
#define MEMORY_OFFSET 0x558000
#define FS_SEGMENT_OFFSET 0x584698
#define FS_SEGMENT_SIZE 0x4
#define STACK_BASE (FS_SEGMENT_OFFSET+FS_SEGMENT_SIZE)
#define STACK_SIZE 0x100000
#define STACK_END (STACK_BASE + STACK_SIZE)
#define MEMORY_SIZE (STACK_END - MEMORY_OFFSET)

// debug?
#define DEBUG_MEMORY
#define DEBUG_CPU
#define DEBUG_STACK
#define DEBUG_FPU

#endif // TERRAINGEN_CONFIG_H
