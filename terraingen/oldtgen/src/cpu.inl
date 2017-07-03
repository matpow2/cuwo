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

#include "cpu.h"
#include "main.h"
#include <iostream>
#include "config.h"

FORCE_INLINE CPU::CPU()
{
    reg[EAX] = 0x00000001;
    reg[ECX] = 0x00000002;
    reg[EBX] = 0x00000003;
    reg[EDX] = 0x00000004;
    reg[ESI] = 0x00000005;
    reg[EDI] = 0x00000006;

    // init fpu
    fpu_top = -1;
    for (int i = 0; i < 8; i++) {
        fpu[i] = 0.0;
#ifdef DEBUG_FPU
        fpu_empty[i] = true;
#endif
    }
    reset_stack();
}

FORCE_INLINE uint16_t & CPU::get_reg16(Register16 i)
{
    union {
        uint32_t* in;
        uint16_t* out;
    };
    in = &reg[i];
#ifdef IS_BIG_ENDIAN
    return *(out + 1);
#else
    return *out;
#endif
}

FORCE_INLINE uint8_t & CPU::get_reg8(Register8 i)
{
    union {
        uint32_t* in;
        uint8_t* out;
    };
#ifdef IS_BIG_ENDIAN
    if (i < 4) {
        in = &reg[i];
        return *(out + 3);
    } else {
        in = &reg[i & 3];
        return *(out + 2);
    }
#else
    if (i < 4) {
        in = &reg[i];
        return *out;
    } else {
        in = &reg[i + 3];
        return *(out + 1);
    }
#endif
}

FORCE_INLINE void CPU::reset_stack()
{
    reg[EBP] = reg[ESP] = mem.translate(mem.stack+STACK_SIZE);
}

FORCE_INLINE void CPU::add_function(uint32_t addr, FuncPointer value)
{
    functions[addr] = value;
}

FORCE_INLINE void CPU::call_dynamic(uint32_t addr)
{
    FunctionMap::const_iterator it = functions.find(addr);

#ifdef DEBUG_FUNC
    if (it == functions.end()) {
        std::cout << "Could not call dynamic address " << addr << std::endl;
        exit(0);
        return;
    }
#endif

    FuncPointer f = it->second;
    f();
}

// CPU

FORCE_INLINE uint32_t CPU::shld_dword(uint32_t value, uint32_t shr,
                                      uint32_t count)
{
    return (value << count) | (shr >> (32 - count));
}

FORCE_INLINE uint32_t CPU::rol_dword(uint32_t v, uint32_t count)
{
    return (v << count) | (v >> (32 - count));
}

FORCE_INLINE uint16_t CPU::rol_word(uint16_t v, uint16_t count)
{
    return (v << count) | (v >> (16 - count));
}

FORCE_INLINE uint32_t CPU::rcr_dword(uint32_t v, uint32_t count, uint32_t cf)
{
    return (v >> count) | (cf << (32 - count)) |
           (v << (33 - count));
}

FORCE_INLINE void CPU::mul_dword(uint32_t v)
{
    uint32_t a = reg[EAX];

    uint64_t product = ((uint64_t)a)*((uint64_t)v);
    uint32_t product_low = GET32L(product);
    uint32_t product_high = GET32H(product);

    reg[EAX] = product_low;
    reg[EDX] = product_high;
}

FORCE_INLINE void CPU::imul_dword(uint32_t v)
{
    int32_t a = (int32_t)reg[EAX];
    int32_t vv = (int32_t)v;

    int64_t product = ((int64_t)a)*((int64_t)vv); 
    uint32_t product_low = GET32L(product);
    uint32_t product_high = GET32H(product);

    reg[EAX] = product_low;
    reg[EDX] = product_high;
}

FORCE_INLINE uint32_t CPU::imul_dword(uint32_t v, uint32_t mul)
{
    int32_t a = (int32_t)v;
    int32_t vv = (int32_t)mul;

    int64_t product = ((int64_t)a)*((int64_t)vv);
    uint32_t product_32 = (uint32_t)(product & 0xFFFFFFFF);
    return product_32;
}

FORCE_INLINE void CPU::div_dword(uint32_t d)
{
    uint64_t v = (((uint64_t)reg[EDX]) << 32) + ((uint64_t)reg[EAX]);
    uint64_t quot_64  = v / d;
    uint32_t rem_32 = (uint32_t)(v % d);
    uint32_t quot_32 = (uint32_t)(quot_64 & 0xFFFFFFFF);

    reg[EAX] = quot_32;
    reg[EDX] = rem_32;
}

FORCE_INLINE void CPU::idiv_dword(uint32_t d)
{
    int64_t v = (((uint64_t)reg[EDX]) << 32) | ((uint64_t)reg[EAX]);
    int32_t divis = (int32_t)d;

    int64_t quot_64 = v / divis;
    int32_t rem_32 = (int32_t)(v % divis);
    int32_t quot_32 = (int32_t)(quot_64 & 0xFFFFFFFF);

    reg[EAX] = (uint32_t)quot_32;
    reg[EDX] = (uint32_t)rem_32;
}

FORCE_INLINE uint32_t CPU::xadd_dword(uint32_t a, uint32_t & b)
{
    uint32_t res = a + b;
    b = a;
    return res;
}

#ifdef DEBUG_STACK
FORCE_INLINE void test_stack_pos(uint32_t v)
{
    if (v < STACK_BASE || v > STACK_END)
        std::cout << "Stack registers invalid" << std::endl;
}

FORCE_INLINE void test_stack()
{
    test_stack_pos(cpu.reg[ESP]);
    test_stack_pos(cpu.reg[EBP]);
}
#endif

FORCE_INLINE void CPU::push_dword(uint32_t arg)
{
    reg[ESP] -= 4;
    mem.write_dword(reg[ESP], arg);
#ifdef DEBUG_STACK
    test_stack();
#endif
}

FORCE_INLINE void CPU::pop_dword(uint32_t * arg)
{
    mem.read_dword(reg[ESP], arg);
    reg[ESP] += 4;
#ifdef DEBUG_STACK
    test_stack();
#endif
}

FORCE_INLINE uint32_t CPU::pop_dword()
{
    uint32_t v;
    pop_dword(&v);
    return v;
}

FORCE_INLINE void CPU::pop_qword(uint64_t * arg)
{
    mem.read_qword(reg[ESP], arg);
    reg[ESP] += 8;
#ifdef DEBUG_STACK
    test_stack();
#endif
}

FORCE_INLINE uint64_t CPU::pop_qword()
{
    uint64_t v;
    pop_qword(&v);
    return v;
}

FORCE_INLINE uint64_t CPU::get_qword(uint32_t off)
{
    uint64_t arg;
    mem.read_qword(reg[ESP]+off, &arg);
    return arg;
}

FORCE_INLINE uint32_t CPU::get_dword(uint32_t off)
{
    uint32_t arg;
    mem.read_dword(reg[ESP]+off, &arg);
    return arg;
}

FORCE_INLINE uint16_t CPU::get_word(uint32_t off)
{
    uint16_t arg;
    mem.read_word(reg[ESP]+off, &arg);
    return arg;
}

FORCE_INLINE uint8_t CPU::get_byte(uint32_t off)
{
    uint8_t arg;
    mem.read_byte(reg[ESP]+off, &arg);
    return arg;
}

FORCE_INLINE long double & CPU::get_fpu(RegisterST index)
{
#ifdef DEBUG_FPU
    if (fpu_empty[fpu_top-index]) {
        std::cout << "FPU index empty" << std::endl;
        exit(0);
    }
#endif
    return fpu[fpu_top-index];
}

FORCE_INLINE void CPU::push_fpu(long double value)
{
    fpu_top++;
#ifdef DEBUG_FPU
    if (!fpu_empty[fpu_top]) {
        std::cout << "FPU index not empty" << std::endl;
        exit(0);
    }
    fpu_empty[fpu_top] = false;
#endif
    fpu[fpu_top] = value;
}

FORCE_INLINE long double CPU::pop_fpu()
{
    long double ret = fpu[fpu_top];
#ifdef DEBUG_FPU
    if (fpu_empty[fpu_top]) {
        std::cout << "FPU index empty" << std::endl;
        exit(0);
    }
    fpu_empty[fpu_top] = true;
#endif
    fpu_top--;
    return ret;
}

FORCE_INLINE uint32_t cdq_x86(uint32_t v)
{
    if ((int32_t)v < 0)
        return 0xFFFFFFFF;
    return 0;
}

// custom/import helpers

FORCE_INLINE void pop_ret()
{
    cpu.reg[ESP] += 4;
}

FORCE_INLINE void add_ret()
{
    cpu.reg[ESP] -= 4;
}

FORCE_INLINE uint32_t & get_self()
{
    return cpu.reg[ECX];
}

FORCE_INLINE void set_ret(uint32_t v)
{
    cpu.reg[EAX] = v;
}

FORCE_INLINE void set_ret(int v)
{
    set_ret(uint32_t(v));
}

FORCE_INLINE void set_ret(uint64_t v)
{
    cpu.reg[EAX] = uint32_t(v & 0xFFFFFFFF);
    cpu.reg[EDX] = uint32_t(v >> 32);
}

FORCE_INLINE void ret_self()
{
    set_ret(get_self());
}
