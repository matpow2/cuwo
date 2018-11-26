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

#ifndef TERRAINGEN_BASE_H
#define TERRAINGEN_BASE_H

#include "crossrand.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "mem.h"

// #define IMPL_CRITSEC

// import: free
void free_imp(void * data)
{
    heap_dealloc(data);
}

// import: void * __cdecl operator new(unsigned int)
void * new_imp(uint32_t size)
{
    return heap_alloc(size);
}

// import: malloc
void * malloc_imp(uint32_t size)
{
    return heap_alloc(size);
}

// import: void __cdecl operator delete(void *)
void delete_func_imp(void * p)
{
    heap_dealloc(p);
}

// import: void __cdecl operator delete[](void *)
void delete_arr_func_imp(void * p)
{
    heap_dealloc(p);
}

// import: memcpy
void * memcpy_imp(void * dst, void * src, uint32_t num)
{
    return memcpy(dst, src, num);
}

// import: strcmp
int32_t strcmp_imp(const char * a, const char * b)
{
    return strcmp(a, b);
}

// import: memcmp
int32_t memcmp_imp(const char * a, const char * b, uint32_t size)
{
    return memcmp(a, b, size);
}

// import: abort
void abort_imp()
{
    abort();
}

// import: void __cdecl terminate(void)
void terminateYAXXZ_imp()
{
    abort();
}

// import: ORDINAL_WS2_32.DLL_115
// stdcall
uint32_t WSAStartup_imp(uint32_t version, uint32_t data)
{
    return 1;
}

// import: InitializeCriticalSectionAndSpinCount
// stdcall
bool InitializeCriticalSectionAndSpinCount_imp(uint32_t crit_sec,
                                               uint32_t spincount)
{
    return 1;
}

// import: DeleteCriticalSection
// stdcall
void DeleteCriticalSection_imp(uint32_t critical_section)
{
#ifndef NDEBUG
    std::cout << "DeleteCriticalSection" << std::endl;
#endif
}

// import: rand
uint32_t rand_imp()
{
    return cross_rand();
}

// import: srand
void srand_imp(uint32_t value)
{
    cross_srand(value);
}

// import: IsProcessorFeaturePresent
// stdcall
uint32_t IsProcessorFeaturePresent_imp(uint32_t feature)
{
    return 0;
}

// import: _beginthread
void _beginthread_imp(uint32_t start, uint32_t stack_size,
                      uint32_t list)
{
    std::cout << "beginthread\n";
}

// import: EncodePointer
// stdcall
uint32_t EncodePointer_imp(uint32_t val)
{
    return val;
}

// import: memmove
void * memmove_imp(void * dest, const void * src, uint32_t size)
{
    return memmove(dest, src, size);
}

// import: memset
void * memset_imp(void * ptr, int32_t value, uint32_t num)
{
    return memset(ptr, value, num);
}

// import: fseek
int32_t fseek_imp(uint32_t stream, uint32_t offset, uint32_t origin)
{
    std::cout << "fseek: " << stream << " " << offset << " " << origin <<
        std::endl;
    return 0;
}

// import: fwrite
uint32_t fwrite_imp(const void * ptr, uint32_t size,
                    uint32_t count, uint32_t stream)
{
    std::cout << "fwrite" << std::endl;
    return 0;
}

// import: fclose
int32_t fclose_imp(uint32_t stream)
{
    std::cout << "fclose: " << stream << std::endl;
    return 0;
}

// import: _setjmp
int32_t _setjmp_imp(uint32_t jmp_buf)
{
    std::cout << "setjmp: " << jmp_buf << std::endl;
    return 0;
}

// import: InitializeCriticalSection
// stdcall
void InitializeCriticalSection_imp(uint32_t sect)
{
#ifndef NDEBUG
    std::cout << "Initialize critical section" << std::endl;
#endif
}

// import: EnterCriticalSection
// stdcall
void EnterCriticalSection_imp(uint32_t sect)
{
#ifndef NDEBUG
    std::cout << "Enter critical section" << std::endl;
#endif
}

// import: LeaveCriticalSection
// stdcall
void LeaveCriticalSection_imp(uint32_t sect)
{
#ifndef NDEBUG
    std::cout << "Leave critical section" << std::endl;
#endif
}

// import: InterlockedCompareExchange
// stdcall
uint32_t InterlockedCompareExchange_imp(uint32_t * dest, uint32_t exc,
                                        uint32_t comp)
{
    std::cout << "InterlockedCompareExchange" << std::endl;

    uint32_t val = *dest;
    if (val == comp)
        *dest = exc;
    return val;
}

// import: _setjmp3
void _setjmp3_imp(uint32_t jmp_buf, uint32_t count)
{
}

/* _Container_base0 is used by apps compiled without iterator checking
 * (i.e. with _ITERATOR_DEBUG_LEVEL=0 ).
 * It provides empty versions of methods used by visual c++'s stl's
 * iterator checking.
 * msvcr100 has to provide them in case apps are compiled with /Od
 * or the optimizer fails to those (empty) calls.
 */

// import: public: void __thiscall std::_Container_base0::_Orphan_all(void)
// thiscall
void orphan_imp(uint32_t self)
{
}

// import: _libm_sse2_cos_precise
// vectorcall
double _libm_sse2_cos_precise_imp(double v)
{
    return cos(v);
}

// import: _libm_sse2_sin_precise
// vectorcall
double _libm_sse2_sin_precise_imp(double v)
{
    return sin(v);
}

// import: _libm_sse2_sqrt_precise
// vectorcall
double _libm_sse2_sqrt_precise_imp(double v)
{
    return sqrt(v);
}

// import: _libm_sse2_pow_precise
// vectorcall
double _libm_sse2_pow_precise_imp(double v, double v2)
{
    return pow(v, v2);
}

// import: _libm_sse2_exp_precise
// vectorcall
double _libm_sse2_exp_precise(double v)
{
    return exp(v);
}

// import: _libm_sse2_acos_precise
// vectorcall
double _libm_sse2_acos_precise(double v)
{
    return acos(v);
}

// import: _libm_sse2_asin_precise
// vectorcall
double _libm_sse2_asin_precise(double v)
{
    return asin(v);
}

#endif // TERRAINGEN_BASE_H
