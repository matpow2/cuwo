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

#ifndef TERRAINGEN_BASE_H
#define TERRAINGEN_BASE_H

#include "main.h"
#include "crossrand.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

inline void free_imp()
{
    // cdecl
    pop_ret();
    uint32_t data = cpu.get_dword(0);
    mem.heap_dealloc(data);
}

inline void new_func_imp()
{
    // cdecl
    pop_ret();
    uint32_t size = cpu.get_dword(0);
    uint32_t ret = mem.heap_alloc(size);
    set_ret(ret);
}

inline void malloc_imp()
{
    // cdecl
    pop_ret();
    uint32_t size = cpu.get_dword(0);
    uint32_t ret = mem.heap_alloc(size);
    set_ret(ret);
}

inline void _malloc_crt_imp()
{
    malloc_imp();
}

inline void _calloc_crt_imp()
{
    // cdecl
    pop_ret();
    uint32_t num = cpu.get_dword(0);
    uint32_t size = cpu.get_dword(4);
    size *= num;
    uint32_t ret = mem.heap_alloc(size);
    mem.set_mem(ret, 0, size);
    set_ret(ret);
}

inline void delete_func_imp()
{
    // cdecl
    pop_ret();
    uint32_t data = cpu.get_dword(0);
    mem.heap_dealloc(data);
    set_ret(0);
}

inline void delete_arr_func_imp()
{
    // cdecl
    pop_ret();
    uint32_t data = cpu.get_dword(0);
    mem.heap_dealloc(data);
    set_ret(0);
}

inline void memcpy_imp()
{
    pop_ret();
    uint32_t dest = cpu.get_dword(0);
    uint32_t src = cpu.get_dword(4);
    uint32_t num = cpu.get_dword(8);
    // std::cout << "memcpy: " << dest << " " << src << " " << num << std::endl;
    mem.copy_mem(dest, src, num);
    set_ret(dest);
}

inline void strcmp_imp()
{
    pop_ret();
    uint32_t str1 = cpu.get_dword(0);
    uint32_t str2 = cpu.get_dword(4);
    std::cout << "strcmp" << str1 << " " << str2 << std::endl;
    set_ret(0);
}

inline void memcmp_imp()
{
    pop_ret();
    uint32_t str1 = cpu.get_dword(0);
    uint32_t str2 = cpu.get_dword(4);
    uint32_t num = cpu.get_dword(8);
    // std::cout << "memcmp" << str1 << " " << str2 << std::endl;
    set_ret(0);
}

inline void abort_imp()
{
    pop_ret();
    std::cout << "Abort process" << std::endl;
}

inline void terminateYAXXZ_imp()
{
    pop_ret();
    std::cout << "Terminate process" << std::endl;
}

inline void WSAStartup_imp()
{
    // stdcall
    pop_ret();
    uint32_t version = cpu.pop_dword();
    uint32_t data = cpu.pop_dword();
    // std::cout << "WSAStartup: " << data << " " << version << std::endl;
    set_ret(1);
}

inline void InitializeCriticalSectionAndSpinCount_imp()
{
    // std::cout << "InitializeCriticalSectionAndSpinCount" << std::endl;
    pop_ret();
    uint32_t critical_section = cpu.pop_dword();
    uint32_t spincount = cpu.pop_dword();
}

inline void DeleteCriticalSection_imp()
{
    std::cout << "DeleteCriticalSection" << std::endl;
    pop_ret();
    uint32_t critical_section = cpu.pop_dword();
}

inline void rand_imp()
{
    // cdecl
    pop_ret();
    unsigned int r = cross_rand();
    set_ret(r);
}

inline void srand_imp()
{
    // cdecl
    pop_ret();
    uint32_t value = cpu.get_dword(0);
    cross_srand(value);
}

inline void IsProcessorFeaturePresent_imp()
{
    pop_ret();
    uint32_t feature = cpu.pop_dword();
    set_ret(0);
}

inline void bad_cast_ctor_charptr_imp()
{
    pop_ret();
    uint32_t name = cpu.pop_dword();
    std::cout << "Bad cast exception" << std::endl;
}

inline void exception_ctor_imp()
{
    pop_ret();
    uint32_t name = cpu.pop_dword();
    std::cout << "Exception constructor" << std::endl;
}

inline void exception_ctor_noalloc_imp()
{
    // thiscall
    pop_ret();
    uint32_t name = cpu.pop_dword();
    uint32_t noalloc = cpu.pop_dword();
    std::cout << "Exception constructor noalloc" << std::endl;
}

inline void _beginthread_imp()
{
    pop_ret();
    std::cout << "_beginthread" << std::endl;
}

inline void EncodePointer_imp()
{
    // stdcall
    pop_ret();
    uint32_t val = cpu.pop_dword();
    set_ret(val);
}

inline void memmove_imp()
{
    pop_ret();
    uint32_t dest = cpu.get_dword(0);
    uint32_t src = cpu.get_dword(4);
    uint32_t num = cpu.get_dword(8);
    // std::cout << "memmove: " << dest << " " << src << " " << num << std::endl;
    mem.move_mem(dest, src, num);
    set_ret(dest);
}

inline void memset_imp()
{
    pop_ret();
    uint32_t ptr = cpu.get_dword(0);
    uint32_t value = cpu.get_dword(4);
    uint32_t num = cpu.get_dword(8);
    // std::cout << "memset: " << ptr << " " << value << " " << num << std::endl;
    mem.set_mem(ptr, value, num);
}

inline void fseek_imp()
{
    pop_ret();
    uint32_t stream = cpu.get_dword(0);
    uint32_t offset = cpu.get_dword(4);
    uint32_t origin = cpu.get_dword(8);
    std::cout << "fseek: " << stream << " " << offset << " " << origin <<
        std::endl;
    set_ret(0);
}

inline void fwrite_imp()
{
    pop_ret();
    std::cout << "fclose" << std::endl;
}

inline void fclose_imp()
{
    pop_ret();
    uint32_t stream = cpu.get_dword(0);
    std::cout << "fclose: " << stream << std::endl;
    set_ret(0);
}

inline void _setjmp_imp()
{
    pop_ret();
    uint32_t jmp_buf = cpu.get_dword(0);
    std::cout << "setjmp: " << jmp_buf << std::endl;
}

inline void InitializeCriticalSection_imp()
{
    pop_ret();
    uint32_t critical_section = cpu.pop_dword();
    std::cout << "Initialize critical section" << std::endl;
}

inline void EnterCriticalSection_imp()
{
    pop_ret();
    uint32_t critical_section = cpu.pop_dword();
    std::cout << "Enter critical section" << std::endl;
}

inline void LeaveCriticalSection_imp()
{
    pop_ret();
    uint32_t critical_section = cpu.pop_dword();
    std::cout << "Leave critical section" << std::endl;
}

inline void InterlockedCompareExchange_imp()
{
    std::cout << "InterlockedCompareExchange" << std::endl;
    pop_ret();
    uint32_t dest = cpu.pop_dword();
    uint32_t exchange = cpu.pop_dword();
    uint32_t comparand = cpu.pop_dword();

    uint32_t val = mem.read_dword(dest);
    if (val == comparand)
        mem.write_dword(dest, exchange);

    set_ret(val);
}

inline void _setjmp3_imp()
{
    pop_ret();
    uint32_t jmp_buf = cpu.get_dword(0);
    uint32_t count = cpu.get_dword(4);
    // std::cout << "_setjmp3 " << count << std::endl;
}

/* _Container_base0 is used by apps compiled without iterator checking
 * (i.e. with _ITERATOR_DEBUG_LEVEL=0 ).
 * It provides empty versions of methods used by visual c++'s stl's
 * iterator checking.
 * msvcr100 has to provide them in case apps are compiled with /Od
 * or the optimizer fails to inline those (empty) calls.
 */

inline void _Orphan_all_Container_base0stdQAEXXZ_imp()
{
    pop_ret();
    // std::cout << "_Orphan_all_Container_base0stdQAEXXZ" << std::endl;
}

inline void _libm_sse2_cos_precise_imp()
{
    pop_ret();
    double v = to_sd(cpu.xmm[XMM0]);
    v = cos(v);
    cpu.xmm[XMM0] = v;
}

inline void _libm_sse2_sin_precise_imp()
{
    pop_ret();
    double v = to_sd(cpu.xmm[XMM0]);
    v = sin(v);
    cpu.xmm[XMM0] = v;
}

inline void _libm_sse2_sqrt_precise_imp()
{
    pop_ret();
    double v = to_sd(cpu.xmm[XMM0]);
    v = sqrt(v);
    cpu.xmm[XMM0] = v;
}

inline void _libm_sse2_pow_precise_imp()
{
    pop_ret();
    double v = to_sd(cpu.xmm[XMM0]);
    double vv = to_sd(cpu.xmm[XMM1]);
    v = pow(v, vv);
    cpu.xmm[XMM0] = v;
}

#endif // TERRAINGEN_BASE_H
