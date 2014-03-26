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

#ifndef TERRAINGEN_CONFIG_H
#define TERRAINGEN_CONFIG_H

// #define IS_BIG_ENDIAN

#if _WIN32 || _WIN64
#if _WIN64
#define IS_64_BIT
#else
#define IS_32_BIT
#endif
#endif

#if __GNUC__
#if __x86_64__ || __ppc64__
#define IS_64_BIT
#else
#define IS_32_BIT
#endif
#endif

#define STACK_SIZE 0x100000
#define FS_SEGMENT_SIZE 0x4

#ifdef IS_32_BIT
#define HEAP_SIZE (128 * 1024 * 1024)
#else
#define HEAP_SIZE (128 * 1024 * 1024)
#endif

// debug?
// #define DEBUG_MEMORY
// #define DEBUG_CPU
// #define DEBUG_STACK
// #define DEBUG_FPU
// #define DEBUG_FUNC

// #define NO_INLINE
#define FAST_INLINE

#if defined(NO_INLINE)
    #define FORCE_INLINE
#elif defined(FAST_INLINE)
    #ifdef _MSC_VER
    #define FORCE_INLINE __forceinline
    #else
    #define FORCE_INLINE __attribute__((always_inline)) inline
    #endif
#else
    #define FORCE_INLINE inline
#endif

#endif // TERRAINGEN_CONFIG_H
