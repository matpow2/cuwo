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

#define BITS 8
#include "eflags.h"
#undef BITS

#define BITS 16
#include "eflags.h"
#undef BITS

#define BITS 32
#include "eflags.h"
#undef BITS

// CPU

FORCE_INLINE bool CPU::get_df()
{
    return false;
}

FORCE_INLINE bool CPU::get_zf()
{
    return zf;
}

FORCE_INLINE bool CPU::get_cf()
{
    return cf;
}

FORCE_INLINE bool CPU::get_sf()
{
    return sf;
}

FORCE_INLINE bool CPU::get_of()
{
    return of;
}

FORCE_INLINE void CPU::set_of_cf(bool in_of, bool in_cf)
{
    of = in_of;
    cf = in_cf;
}

FORCE_INLINE void CPU::set_flags(bool in_of, bool in_sf, bool in_zf,
                                 bool in_af, bool in_pf, bool in_cf)
{
    of = in_of;
    sf = in_sf;
    zf = in_zf;
    cf = in_cf;
}

FORCE_INLINE void CPU::test_dword(uint32_t a, uint32_t b)
{
    set_eflags_32(a & b);
}

FORCE_INLINE void CPU::test_word(uint16_t a, uint16_t b)
{
    set_eflags_16(a & b);
}

FORCE_INLINE void CPU::test_byte(uint8_t a, uint8_t b)
{
    set_eflags_8(a & b);
}

FORCE_INLINE uint32_t CPU::sub_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a - b;
    set_eflags_sub_32(a, b, res);
    return res;
}

FORCE_INLINE uint8_t CPU::sub_byte(uint8_t a, uint8_t b)
{
    uint8_t res = a - b;
    set_eflags_sub_8(a, b, res);
    return res;
}

FORCE_INLINE uint32_t CPU::add_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a + b;
    set_eflags_add_32(a, b, res);
    return res;
}

FORCE_INLINE uint8_t CPU::add_byte(uint8_t a, uint8_t b)
{
    uint8_t res = a + b;
    set_eflags_add_8(a, b, res);
    return res;
}

FORCE_INLINE uint32_t CPU::adc_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a + b + uint32_t(get_cf());
    set_eflags_adc_32(a, b, res);
    return res;
}

FORCE_INLINE uint32_t CPU::sbb_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a - b - uint32_t(get_cf());
    set_eflags_sbb_32(a, b, res);
    return res;
}

FORCE_INLINE uint8_t CPU::sbb_byte(uint8_t a, uint8_t b)
{
    uint8_t res = a - b - uint8_t(get_cf());
    set_eflags_sbb_8(a, b, res);
    return res;
}

FORCE_INLINE uint32_t CPU::neg_dword(uint32_t value)
{
    uint32_t res = -(int32_t)(value);
    set_eflags_sub_32(0, value, res);
    return res;
}

FORCE_INLINE uint8_t CPU::neg_byte(uint8_t value)
{
    uint8_t res = -(int8_t)(value);
    set_eflags_sub_8(0, value, res);
    return res;
}

FORCE_INLINE uint32_t CPU::shl_dword(uint32_t value, uint32_t count)
{
    count &= 0x1f;

    if (!count)
        return value;
    uint32_t res = value << count;
    uint32_t cf = (value >> (32 - count)) & 0x1;
    uint32_t of = cf ^ (res >> 31);
    set_eflags_32(res);
    set_of_cf(of == 1, cf == 1);
    return res;
}

FORCE_INLINE uint16_t CPU::shl_word(uint16_t value, uint16_t count)
{
    uint16_t res;

    uint32_t of = 0;
    uint32_t cf = 0;

    count &= 0x1f;

    if (!count)
        return value;

    if (count <= 16) {
        res = uint16_t(value << count);
        cf = (value >> (16 - count)) & 0x1;
        of = cf ^ (res >> 15);
    } else {
        res = 0;
    }

    set_eflags_16(res);
    set_of_cf(of==1, cf==1);

    return res;
}

FORCE_INLINE uint8_t CPU::shl_byte(uint8_t value, uint8_t count)
{
    uint8_t res;
    uint32_t of = 0;
    uint32_t cf = 0;

    count &= 0x1f;

    if (!count)
        return value;

    if (count <= 8) {
        res = uint8_t(value << count);
        cf = (value >> (8 - count)) & 0x1;
        of = cf ^ (res >> 7);
    } else {
        res = 0;
    }

    set_eflags_8(res);
    set_of_cf(of==1, cf==1);

    return res;
}

FORCE_INLINE uint32_t CPU::shld_dword(uint32_t value, uint32_t shr,
                                      uint32_t count)
{
    count &= 0x1F;

    if (!count)
        return value;

    uint32_t res = (value << count) | (shr >> (32 - count));
    set_eflags_32(res);
    uint32_t cf = (value >> (32 - count)) & 0x1;
    uint32_t of = cf ^ (res >> 31);
    set_of_cf(of==1, cf==1);

    return res;
}

FORCE_INLINE uint32_t CPU::sar_dword(uint32_t v, uint32_t count)
{
    count &= 0x1f;

    if (!count)
        return v;

    uint32_t res = ((int32_t)v) >> count;
    set_eflags_32(res);
    uint32_t cf = (v >> (count - 1)) & 1;
    set_of_cf(false, cf==1);
    return res;
}

FORCE_INLINE uint32_t CPU::rol_dword(uint32_t v, uint32_t count)
{
    count &= 0x1f;

    if (!count)
        return v;

    uint32_t res = (v << count) | (v >> (32 - count));
    uint32_t bit0 = res & 0x1;
    uint32_t bit31 = res >> 31;
    set_of_cf((bit0 ^ bit31)==1, bit0==1);
    return res;
}

FORCE_INLINE uint16_t CPU::rol_word(uint16_t v, uint16_t count)
{
    if ((count & 0x0f) == 0) {
        if (count & 0x10) {
            uint32_t bit0  = v & 0x1;
            uint32_t bit15 = v >> 15;
            set_of_cf((bit0 ^ bit15)==1, bit0==1);
        }
    } else {
        count &= 0x0f;
        uint16_t res = uint16_t((v << count) | (v >> (16 - count)));
        uint32_t bit0  = res & 0x1;
        uint32_t bit15 = res >> 15;
        set_of_cf((bit0 ^ bit15)==1, bit0==1);
        return res;
    }
    return v;
}

FORCE_INLINE uint32_t CPU::rcr_dword(uint32_t v, uint32_t count)
{
    count &= 0x1f;

    if (!count)
        return v;

    uint32_t res;

    if (count == 1) {
        res = (v >> 1) | (uint32_t(get_cf()) << 31);
    } else {
        res = (v >> count) | (uint32_t(get_cf()) << (32 - count)) |
              (v << (33 - count));
    }

    uint32_t cf = (v >> (count - 1)) & 0x1;
    uint32_t of = ((res << 1) ^ res) >> 31;
    set_of_cf(of==1, cf==1);
    return res;
}

FORCE_INLINE uint32_t CPU::shr_dword(uint32_t v, uint32_t count)
{
    count &= 0x1f;

    if (!count)
        return v;
    uint32_t res = v >> count;
    unsigned cf = (v >> (count - 1)) & 0x1;
    unsigned of = ((res << 1) ^ res) >> 31;
    set_eflags_32(res);
    set_of_cf(of==1, cf==1);
    return res;
}

FORCE_INLINE uint16_t CPU::shr_word(uint16_t v, uint16_t count)
{
    count &= 0x1f;

    if (!count)
        return v;
    uint16_t res = uint16_t(v >> count);
    uint32_t cf = (v >> (count - 1)) & 0x1;
    uint32_t of = ((uint16_t)((res << 1) ^ res) >> 15) & 0x1;
    set_eflags_16(res);
    set_of_cf(of==1, cf==1);
    return res;
}

FORCE_INLINE uint8_t CPU::shr_byte(uint8_t v, uint8_t count)
{
    count &= 0x1f;

    if (!count)
        return v;

    uint8_t res = uint8_t(v >> count);
    unsigned cf = (v >> (count - 1)) & 0x1;
    unsigned of = (((res << 1) ^ res) >> 7) & 0x1;
    set_eflags_8(res);
    set_of_cf(of==1, cf==1);
    return res;
}

FORCE_INLINE void CPU::mul_dword(uint32_t v)
{
    uint32_t a = reg[EAX];

    uint64_t product = ((uint64_t)a)*((uint64_t)v);
    uint32_t product_low = GET32L(product);
    uint32_t product_high = GET32H(product);

    reg[EAX] = product_low;
    reg[EDX] = product_high;

    set_eflags_32(product_low);
    if (product_high != 0)
        set_of_cf(true, true);
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

    set_eflags_32(product_low);
    if (product != (int32_t)product)
        set_of_cf(true, true);
}

FORCE_INLINE uint32_t CPU::imul_dword(uint32_t v, uint32_t mul)
{
    int32_t a = (int32_t)v;
    int32_t vv = (int32_t)mul;

    int64_t product = ((int64_t)a)*((int64_t)vv);
    uint32_t product_32 = (uint32_t)(product & 0xFFFFFFFF);

    set_eflags_32(product_32);
    if (product != (int32_t)product)
        set_of_cf(true, true);

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
    set_eflags_add_32(a, b, res);
    b = a;
    return res;
}

FORCE_INLINE uint32_t CPU::xor_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a ^ b;
    set_eflags_32(res);
    return res;
}

FORCE_INLINE uint8_t CPU::xor_byte(uint8_t a, uint8_t b)
{
    uint8_t res = a ^ b;
    set_eflags_8(res);
    return res;
}

FORCE_INLINE uint32_t CPU::dec_dword(uint32_t a)
{
    uint32_t res = a - 1;
    set_eflags_dec_32(res);
    return res;
}

FORCE_INLINE uint16_t CPU::dec_word(uint16_t a)
{
    uint16_t res = a - 1;
    set_eflags_dec_16(res);
    return res;
}

FORCE_INLINE uint8_t CPU::dec_byte(uint8_t a)
{
    uint8_t res = a - 1;
    set_eflags_dec_8(res);
    return res;
}

FORCE_INLINE uint32_t CPU::inc_dword(uint32_t a)
{
    uint32_t res = a + 1;
    set_eflags_inc_32(res);
    return res;
}

FORCE_INLINE uint16_t CPU::inc_word(uint16_t a)
{
    uint16_t res = a + 1;
    set_eflags_inc_16(res);
    return res;
}

FORCE_INLINE uint8_t CPU::inc_byte(uint8_t a)
{
    uint8_t res = a + 1;
    set_eflags_inc_8(res);
    return res;
}

FORCE_INLINE uint32_t CPU::or_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a | b;
    set_eflags_32(res);
    return res;
}

FORCE_INLINE uint16_t CPU::or_word(uint16_t a, uint16_t b)
{
    uint16_t res = a | b;
    set_eflags_16(a | b);
    return res;
}

FORCE_INLINE uint8_t CPU::or_byte(uint8_t a, uint8_t b)
{
    uint8_t res = a | b;
    set_eflags_8(res);
    return res;
}

FORCE_INLINE uint32_t CPU::and_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a & b;
    set_eflags_32(res);
    return res;
}

FORCE_INLINE uint16_t CPU::and_word(uint16_t a, uint16_t b)
{
    uint16_t res = a & b;
    set_eflags_16(res);
    return res;
}

FORCE_INLINE uint8_t CPU::and_byte(uint8_t a, uint8_t b)
{
    uint8_t res = a & b;
    set_eflags_8(res);
    return res;
}

FORCE_INLINE void CPU::cmp_dword(uint32_t a, uint32_t b)
{
    set_eflags_sub_32(a, b, a - b);
}

FORCE_INLINE void CPU::cmp_word(uint16_t a, uint16_t b)
{
    set_eflags_sub_16(a, b, a - b);
}

FORCE_INLINE void CPU::cmp_byte(uint8_t a, uint8_t b)
{
    set_eflags_sub_8(a, b, a - b);
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

FORCE_INLINE void CPU::push_byte(uint8_t arg)
{
    reg[ESP] -= 1;
    mem.write_byte(reg[ESP], arg);
#ifdef DEBUG_STACK
    test_stack();
#endif
}

FORCE_INLINE void CPU::push_word(uint16_t arg)
{
    reg[ESP] -= 2;
    mem.write_word(reg[ESP], arg);
#ifdef DEBUG_STACK
    test_stack();
#endif
}

FORCE_INLINE void CPU::push_dword(uint32_t arg)
{
    reg[ESP] -= 4;
    mem.write_dword(reg[ESP], arg);
#ifdef DEBUG_STACK
    test_stack();
#endif
}

FORCE_INLINE void CPU::pop_byte(uint8_t * arg)
{
    mem.read_byte(reg[ESP], arg);
    reg[ESP] += 1;
#ifdef DEBUG_STACK
    test_stack();
#endif
}

FORCE_INLINE uint8_t CPU::pop_byte()
{
    uint8_t v;
    pop_byte(&v);
    return v;
}

FORCE_INLINE void CPU::pop_word(uint16_t * arg)
{
    mem.read_word(reg[ESP], arg);
    reg[ESP] += 2;
#ifdef DEBUG_STACK
    test_stack();
#endif
}

FORCE_INLINE uint16_t CPU::pop_word()
{
    uint16_t v;
    pop_word(&v);
    return v;
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

FORCE_INLINE void CPU::compare_ss(float a, float b)
{
    bool zf, pf, cf;
    if (a != a || b != b) {
        // nan
        zf = pf = cf = true;
    } else if (a > b) {
        zf = pf = cf = false;
    } else if (a < b) {
        zf = pf = false;
        cf = true;
    } else if (a == b) {
        // equal
        zf = true;
        pf = cf = false;
    } else {
#ifdef DEBUG_CPU
        std::cout << "Unknown float relation!" << std::endl;
#endif
        zf = pf = cf = false;
    }
    set_flags(false, false, zf, false, pf, cf);
}

FORCE_INLINE void CPU::compare_sd(double a, double b)
{
    bool zf, pf, cf;
    if (a != a || b != b)
        // nan
        zf = pf = cf = true;
    else if (a > b)
        zf = pf = cf = false;
    else if (a < b) {
        zf = pf = false;
        cf = true;
    } else if (a == b) {
        // equal
        zf = true;
        pf = cf = false;
    } else {
#ifdef DEBUG_CPU
        std::cout << "Unknown float relation!" << std::endl;  
#endif
        zf = pf = cf = false;
    }
    set_flags(false, false, zf, false, pf, cf);
}

FORCE_INLINE uint32_t cdq_x86(uint32_t v)
{
    if (v & 0x80000000)
        return 0xFFFFFFFF;
    return 0x00000000;
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
