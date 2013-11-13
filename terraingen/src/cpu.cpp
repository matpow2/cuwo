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

#include "cpu.h"
#include "main.h"
#include <limits>
#include <functional>
#include <boost/type_traits/make_signed.hpp>
#include <iostream>
#include "config.h"

inline CPU::CPU()
{
    int i = 1;

    if (*((uint8_t *)&i) == 1) {
        // little endian
        for (i = 0; i < 8; i++) {
            reg16[i] = (uint16_t *)&reg[i];

            if (i < 4) {
                reg8[i] = (uint8_t *)&reg[i];
            } else {
                reg8[i] = (uint8_t *)&reg[i & 3] + 1;
            }
        }
    } else {
        // big_endian
        for (i = 0; i < 8; i++) {
            reg16[i] = (uint16_t *)&reg[i] + 1;

            if (i < 4)
                reg8[i] = (uint8_t *)&reg[i] + 3;
            else
                reg8[i] = (uint8_t *)&reg[i & 3] + 2;
        }
    }

    reg[EAX] = 0x00000001;
    reg[ECX] = 0x00000002;
    reg[EBX] = 0x00000003;
    reg[EDX] = 0x00000004;
    reg[ESI] = 0x00000005;
    reg[EDI] = 0x00000006;

    // init fpu
    fpu_top = 0;
    for (int i = 0; i < 8; i++) {
        fpu[i] = 0.0;
#ifdef DEBUG_FPU
        fpu_empty[i] = true;
#endif
    }

    reset_stack();
}

inline void CPU::reset_stack()
{
    reg[EBP] = reg[ESP] = STACK_END;
}

inline void CPU::add_function(uint32_t addr, FuncPointer value)
{
    functions[addr] = value;
}

inline void CPU::call_dynamic(uint32_t addr)
{
    FunctionMap::const_iterator it = functions.find(addr);

    if (it == functions.end()) {
        std::cout << "Could not call dynamic address " << addr << std::endl;
        exit(0);
        return;
    }

    FuncPointer f = it->second;
    f();
}

inline uint32_t add_vec(uint32_t a, uint32_t b, uint32_t res)
{
    return (a & b) | ((a | b) & (~res));
}

inline uint32_t sub_vec(uint32_t a, uint32_t b, uint32_t res)
{
    return ((~a) & b) | (((~a) ^ b) & res);
}

template <class T>
inline void set_lazy(uint32_t res)
{
    cpu.res = (uint32_t)((T)(typename boost::make_signed<T>::type(res)));
    cpu.aux = 0;
}

#define LF_BIT_SD      (0)          /* lazy Sign Flag Delta            */
#define LF_BIT_AF      (3)          /* lazy Adjust flag                */
#define LF_BIT_PDB     (8)          /* lazy Parity Delta Byte (8 bits) */
#define LF_BIT_CF      (31)         /* lazy Carry Flag                 */
#define LF_BIT_PO      (30)         /* lazy Partial Overflow = CF ^ OF */

#define LF_MASK_SD     (0x01 << LF_BIT_SD)
#define LF_MASK_AF     (0x01 << LF_BIT_AF)
#define LF_MASK_PDB    (0xFF << LF_BIT_PDB)
#define LF_MASK_CF     (0x01 << LF_BIT_CF)
#define LF_MASK_PO     (0x01 << LF_BIT_PO)

#define LF_SIGN_BIT  31

template <typename T>
inline void set_lazy(uint32_t aux, uint32_t res)
{
    cpu.res = (uint32_t)(typename boost::make_signed<T>::type(res));
    const uint32_t size = sizeof(T)*8;
    uint32_t temp = (aux & (LF_MASK_AF)) | ((aux >> (size - 2)) << LF_BIT_PO);
    if (size == 32)
        temp = aux & ~(LF_MASK_PDB | LF_MASK_SD);
    else if (size == 16)
        temp = (aux & (LF_MASK_AF)) | (aux << 16);
    else if (size == 8)
        temp = (aux & (LF_MASK_AF)) | (aux << 24);
    cpu.aux = temp;
}

template <typename T>
inline void set_lazy_incdec(uint32_t aux, uint32_t res)
{
    cpu.res = (uint32_t)(typename boost::make_signed<T>::type(res));
    const uint32_t size = sizeof(T)*8;
    uint32_t temp = (aux & (LF_MASK_AF)) | ((aux >> (size - 2)) << LF_BIT_PO);
    if (size == 32)
        temp = aux & ~(LF_MASK_PDB | LF_MASK_SD);
    else if (size == 16)
        temp = (aux & (LF_MASK_AF)) | (aux << 16);
    else if (size == 8)
        temp = (aux & (LF_MASK_AF)) | (aux << 24);
    uint32_t delta_c = (cpu.aux ^ temp) & LF_MASK_CF;
    delta_c ^= delta_c >> 1;
    cpu.aux = temp ^ delta_c;
}

template <class T>
inline void set_lazy_add(uint32_t a, uint32_t b, uint32_t res)
{
    set_lazy<T>(add_vec(a, b, res), res);
}

template <class T>
inline void set_lazy_inc(uint32_t a, uint32_t b, uint32_t res)
{
    set_lazy_incdec<T>(add_vec(a, b, res), res);
}

template <class T>
inline void set_lazy_sub(uint32_t a, uint32_t b, uint32_t res)
{
    set_lazy<T>(sub_vec(a, b, res), res);
}

template <class T>
inline void set_lazy_dec(uint32_t a, uint32_t b, uint32_t res)
{
    set_lazy_incdec<T>(sub_vec(a, b, res), res);
}

inline bool CPU::get_df()
{
    return false;
}

inline bool CPU::get_zf()
{
    return res == 0;
}

inline bool CPU::get_cf()
{
    return (aux >> LF_BIT_CF) & 1;
}

inline bool CPU::get_sf()
{
    return ((res >> LF_SIGN_BIT) ^ (aux >> LF_BIT_SD)) & 1;
}

inline bool CPU::get_of()
{
    return ((aux + (1U << LF_BIT_PO)) >> LF_BIT_CF)  & 1;
}

inline void CPU::set_of_cf(bool of, bool cf)
{
    uint32_t temp_po = int(of) ^ int(cf);
    aux &= ~(LF_MASK_PO | LF_MASK_CF);
    aux |= (temp_po << LF_BIT_PO) | (int(cf) << LF_BIT_CF);
}

inline void CPU::set_flags(bool of, bool sf, bool zf, bool af, bool pf,
                           bool cf)
{
    // set of
    set_of_cf(of, get_cf());

    // set sf
    int old_sf = int(get_sf());
    aux ^= (old_sf ^ int(sf)) << LF_BIT_SD;

    // set zf
    if (zf) {
        aux ^= ((res >> LF_SIGN_BIT) & 1) << LF_BIT_SD;
        uint32_t pdb = 255 & res;
        aux ^= pdb << LF_BIT_PDB;
        res = 0;
    } else {
        res |= 1 << 8;
    }

    // set af
    aux &= ~(LF_MASK_AF);
    aux |= int(af) << LF_BIT_AF;

    // set pf
    {
        uint32_t pdb = (255 & res) ^ int(!pf);
        aux &= ~(LF_MASK_PDB);
        aux |= pdb << LF_BIT_PDB;
    }

    // set cf
    set_of_cf(get_of(), cf);

#ifdef DEBUG_CPU
    if (get_of() != of || get_sf() != sf || get_cf() != cf || get_zf() != zf) {
        std::cout << "CPU::set_flags failed" << std::endl;
        exit(0);
    }
#endif
}

inline void CPU::test_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a & b;
    set_lazy<uint32_t>(res);
}

inline void CPU::test_word(uint16_t a, uint16_t b)
{
    uint16_t res = a & b;
    set_lazy<uint16_t>(res);
}

inline void CPU::test_byte(uint8_t a, uint8_t b)
{
    uint8_t res = a & b;
    set_lazy<uint8_t>(res);
}

inline uint32_t CPU::sub_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a - b;
    set_lazy_sub<uint32_t>(a, b, res);
    return res;
}

inline uint8_t CPU::sub_byte(uint8_t a, uint8_t b)
{
    uint32_t res = uint32_t(a) - uint32_t(b);
    set_lazy_sub<uint8_t>(a, b, res);
    return res;
}

inline uint32_t CPU::add_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a + b;
    set_lazy_add<uint32_t>(a, b, res);
    return res;
}

inline uint8_t CPU::add_byte(uint8_t a, uint8_t b)
{
    uint32_t res = uint32_t(a) + uint32_t(b);
    set_lazy_add<uint8_t>(a, b, res);
    return uint8_t(res);
}

inline uint32_t CPU::adc_dword(uint32_t a, uint32_t b)
{
    bool cf = get_cf();
    uint32_t res = a + b + int(cf);
    set_lazy_add<uint32_t>(a, b, res);
    return res;
}

inline uint32_t CPU::sbb_dword(uint32_t a, uint32_t b)
{
    bool cf = get_cf();
    uint32_t res = a - (b + int(cf));
    set_lazy_sub<uint32_t>(a, b, res);
    return res;
}

inline uint8_t CPU::sbb_byte(uint8_t a, uint8_t b)
{
    bool cf = get_cf();
    uint32_t res = uint32_t(a) - (uint32_t(b) + uint32_t(cf));
    set_lazy_sub<uint8_t>(a, b, res);
    return res;
}

inline uint32_t CPU::neg_dword(uint32_t value)
{
    uint32_t res = -(int32_t)(value);
    set_lazy_sub<uint32_t>(0, value, res);
    return res;
}

inline uint8_t CPU::neg_byte(uint8_t value)
{
    uint32_t res = -(int8_t)(value);
    set_lazy_sub<uint8_t>(0, value, res);
    return res;
}

inline uint32_t CPU::shl_dword(uint32_t value, uint32_t count)
{
    count &= 0x1f;

    if (!count)
        return value;
    uint32_t res = value << count;
    uint32_t cf = (value >> (32 - count)) & 0x1;
    uint32_t of = cf ^ (res >> 31);
    set_lazy<uint32_t>(res);
    set_of_cf(of == 1, cf == 1);
    return res;
}

inline uint16_t CPU::shl_word(uint16_t value, uint16_t count)
{
    uint16_t res;

    uint32_t of = 0;
    uint32_t cf = 0;

    count &= 0x1f; /* use only 5 LSB's */

    if (!count)
        return value;

    if (count <= 16) {
        res = (value << count);
        cf = (value >> (16 - count)) & 0x1;
        of = cf ^ (res >> 15);
    } else {
        res = 0;
    }

    set_lazy<uint16_t>(res);
    set_of_cf(of==1, cf==1);

    return res;
}

inline uint8_t CPU::shl_byte(uint8_t value, uint8_t count)
{
    uint8_t res;
    uint32_t of = 0;
    uint32_t cf = 0;

    count &= 0x1f;

    if (!count)
        return value;

    if (count <= 8) {
        res = (value << count);
        cf = (value >> (8 - count)) & 0x1;
        of = cf ^ (res >> 7);
    } else {
        res = 0;
    }

    set_lazy<uint8_t>(res);
    set_of_cf(of==1, cf==1);

    return res;
}

inline uint32_t CPU::shld_dword(uint32_t value, uint32_t shr, uint32_t count)
{
    count &= 0x1F;

    if (!count)
        return value;

    uint32_t res = (value << count) | (shr >> (32 - count));
    set_lazy<uint32_t>(res);
    uint32_t cf = (value >> (32 - count)) & 0x1;
    uint32_t of = cf ^ (res >> 31);
    set_of_cf(of==1, cf==1);

    return res;
}

inline uint32_t CPU::sar_dword(uint32_t v, uint32_t count)
{
    count &= 0x1f;

    if (!count)
        return v;

    uint32_t res = ((int32_t)v) >> count;
    set_lazy<uint32_t>(res);
    uint32_t cf = (v >> (count - 1)) & 1;
    set_of_cf(false, cf==1);
    return res;
}

inline uint32_t CPU::rol_dword(uint32_t v, uint32_t count)
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

inline uint16_t CPU::rol_word(uint16_t v, uint16_t count)
{
    if ((count & 0x0f) == 0) {
        if (count & 0x10) {
            uint32_t bit0  = v & 0x1;
            uint32_t bit15 = v >> 15;
            set_of_cf((bit0 ^ bit15)==1, bit0==1);
        }
    } else {
        count &= 0x0f;
        uint16_t res = (v << count) | (v >> (16 - count));
        uint32_t bit0  = res & 0x1;
        uint32_t bit15 = res >> 15;
        set_of_cf((bit0 ^ bit15)==1, bit0==1);
        return res;
    }
    return v;
}

inline uint32_t CPU::rcr_dword(uint32_t v, uint32_t count)
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

inline uint32_t CPU::shr_dword(uint32_t v, uint32_t count)
{
    count &= 0x1f;

    if (!count)
        return v;
    uint32_t res = v >> count;
    unsigned cf = (v >> (count - 1)) & 0x1;
    unsigned of = ((res << 1) ^ res) >> 31;
    set_lazy<uint32_t>(res);
    set_of_cf(of==1, cf==1);
    return res;
}

inline uint16_t CPU::shr_word(uint16_t v, uint16_t count)
{
    count &= 0x1f;

    if (!count)
        return v;
    uint16_t res = v >> count;
    uint32_t cf = (v >> (count - 1)) & 0x1;
    uint32_t of = ((uint16_t)((res << 1) ^ res) >> 15) & 0x1;
    set_lazy<uint16_t>(res);
    set_of_cf(of==1, cf==1);
    return res;
}

inline uint8_t CPU::shr_byte(uint8_t v, uint8_t count)
{
    count &= 0x1f;

    if (!count)
        return v;

    uint8_t res = v >> count;
    unsigned cf = (v >> (count - 1)) & 0x1;
    unsigned of = (((res << 1) ^ res) >> 7) & 0x1;
    set_lazy<uint8_t>(res);
    set_of_cf(of==1, cf==1);
    return res;
}

inline void CPU::mul_dword(uint32_t v)
{
    uint32_t a = reg[EAX];

    uint64_t product = ((uint64_t)a)*((uint64_t)v);
    uint32_t product_low = GET32L(product);
    uint32_t product_high = GET32H(product);

    reg[EAX] = product_low;
    reg[EDX] = product_high;

    set_lazy<uint32_t>(product_low);
    if (product_high != 0)
        set_of_cf(true, true);
}

inline void CPU::imul_dword(uint32_t v)
{
    int32_t a = (int32_t)reg[EAX];
    int32_t vv = (int32_t)v;

    int64_t product = ((int64_t)a)*((int64_t)vv); 
    uint32_t product_low = GET32L(product);
    uint32_t product_high = GET32H(product);

    reg[EAX] = product_low;
    reg[EDX] = product_high;

    set_lazy<uint32_t>(product_low);
    if (product != (int32_t)product)
        set_of_cf(true, true);
}

inline uint32_t CPU::imul_dword(uint32_t v, uint32_t mul)
{
    int32_t a = (int32_t)v;
    int32_t vv = (int32_t)mul;

    int64_t product = ((int64_t)a)*((int64_t)vv);
    uint32_t product_32 = (uint32_t)(product & 0xFFFFFFFF);

    set_lazy<uint32_t>(product_32);
    if (product != (int32_t)product)
        set_of_cf(true, true);

    return product_32;
}

inline void CPU::div_dword(uint32_t d)
{
    uint64_t v = (((uint64_t)reg[EDX]) << 32) + ((uint64_t)reg[EAX]);
    uint64_t quot_64  = v / d;
    uint32_t rem_32 = (uint32_t)(v % d);
    uint32_t quot_32 = (uint32_t)(quot_64 & 0xFFFFFFFF);

    reg[EAX] = quot_32;
    reg[EDX] = rem_32;
}

inline void CPU::idiv_dword(uint32_t d)
{
    int64_t v = (((uint64_t)reg[EDX]) << 32) | ((uint64_t)reg[EAX]);
    int32_t divis = (int32_t)d;

    int64_t quot_64 = v / divis;
    int32_t rem_32 = (int32_t)(v % divis);
    int32_t quot_32 = (int32_t)(quot_64 & 0xFFFFFFFF);

    reg[EAX] = (uint32_t)quot_32;
    reg[EDX] = (uint32_t)rem_32;
}

inline uint32_t CPU::xadd_dword(uint32_t a, uint32_t & b)
{
    uint32_t res = a + b;
    b = a;
    set_lazy_add<uint32_t>(a, b, res);
    return res;
}

inline uint32_t CPU::xor_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a ^ b;
    set_lazy<uint32_t>(res);
    return res;
}

inline uint8_t CPU::xor_byte(uint8_t a, uint8_t b)
{
    uint8_t res = a ^ b;
    set_lazy<uint8_t>(res);
    return res;
}

inline uint32_t CPU::dec_dword(uint32_t a)
{
    uint32_t res = a - 1;
    set_lazy_dec<uint32_t>(res + 1, 0, res);
    return res;
}

inline uint16_t CPU::dec_word(uint16_t a)
{
    uint32_t res = uint32_t(a) - 1;
    set_lazy_dec<uint16_t>(res + 1, 0, res);
    return uint16_t(res);
}

inline uint8_t CPU::dec_byte(uint8_t a)
{
    uint32_t res = uint32_t(a) - 1;
    set_lazy_dec<uint8_t>(res + 1, 0, res);
    return res;
}

inline uint32_t CPU::inc_dword(uint32_t a)
{
    uint32_t res = a + 1;
    set_lazy_inc<uint32_t>(res - 1, 0, res);
    return res;
}

inline uint16_t CPU::inc_word(uint16_t a)
{
    uint32_t res = uint32_t(a) + 1;
    set_lazy_inc<uint16_t>(res - 1, 0, res);
    return uint16_t(res);
}

inline uint8_t CPU::inc_byte(uint8_t a)
{
    uint32_t res = uint32_t(a) + 1;
    set_lazy_inc<uint8_t>(res - 1, 0, res);
    return uint8_t(res);
}

inline uint32_t CPU::or_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a | b;
    set_lazy<uint32_t>(res);
    return res;
}

inline uint16_t CPU::or_word(uint16_t a, uint16_t b)
{
    uint16_t res = a | b;
    set_lazy<uint16_t>(res);
    return res;
}

inline uint8_t CPU::or_byte(uint8_t a, uint8_t b)
{
    uint8_t res = a | b;
    set_lazy<uint8_t>(res);
    return res;
}

inline uint32_t CPU::and_dword(uint32_t a, uint32_t b)
{
    uint32_t res = a & b;
    set_lazy<uint32_t>(res);
    return res;
}

inline uint16_t CPU::and_word(uint16_t a, uint16_t b)
{
    uint16_t res = a & b;
    set_lazy<uint16_t>(res);
    return res;
}

inline uint8_t CPU::and_byte(uint8_t a, uint8_t b)
{
    uint8_t res = a & b;
    set_lazy<uint8_t>(res);
    return res;
}

inline void CPU::cmp_dword(uint32_t a, uint32_t b)
{
    uint32_t res = uint32_t(a) - uint32_t(b);
    set_lazy_sub<uint32_t>(a, b, res);
}

inline void CPU::cmp_word(uint16_t a, uint16_t b)
{
    uint32_t res = uint32_t(a) - uint32_t(b);
    set_lazy_sub<uint16_t>(a, b, res);
}

inline void CPU::cmp_byte(uint8_t a, uint8_t b)
{
    uint32_t res = uint32_t(a) - uint32_t(b);
    set_lazy_sub<uint8_t>(a, b, res);
}

#ifdef DEBUG_STACK
inline void test_stack_pos(uint32_t v)
{
    if (v < STACK_BASE || v > STACK_END)
        std::cout << "Stack registers invalid" << std::endl;
}

inline void test_stack()
{
    test_stack_pos(cpu.reg[ESP]);
    test_stack_pos(cpu.reg[EBP]);
}
#endif

inline void CPU::push_byte(uint8_t arg)
{
    reg[ESP] -= 1;
    mem.write_byte(reg[ESP], arg);
#ifdef DEBUG_STACK
    test_stack();
#endif
}

inline void CPU::push_word(uint16_t arg)
{
    reg[ESP] -= 2;
    mem.write_word(reg[ESP], arg);
#ifdef DEBUG_STACK
    test_stack();
#endif
}

inline void CPU::push_dword(uint32_t arg)
{
    reg[ESP] -= 4;
    mem.write_dword(reg[ESP], arg);
#ifdef DEBUG_STACK
    test_stack();
#endif
}

inline void CPU::pop_byte(uint8_t * arg)
{
    mem.read_byte(reg[ESP], arg);
    reg[ESP] += 1;
#ifdef DEBUG_STACK
    test_stack();
#endif
}

inline uint8_t CPU::pop_byte()
{
    uint8_t v;
    pop_byte(&v);
    return v;
}

inline void CPU::pop_word(uint16_t * arg)
{
    mem.read_word(reg[ESP], arg);
    reg[ESP] += 2;
#ifdef DEBUG_STACK
    test_stack();
#endif
}

inline uint16_t CPU::pop_word()
{
    uint16_t v;
    pop_word(&v);
    return v;
}

inline void CPU::pop_dword(uint32_t * arg)
{
    mem.read_dword(reg[ESP], arg);
    reg[ESP] += 4;
#ifdef DEBUG_STACK
    test_stack();
#endif
}

inline uint32_t CPU::pop_dword()
{
    uint32_t v;
    pop_dword(&v);
    return v;
}

inline void CPU::pop_qword(uint64_t * arg)
{
    mem.read_qword(reg[ESP], arg);
    reg[ESP] += 8;
#ifdef DEBUG_STACK
    test_stack();
#endif
}

inline uint64_t CPU::pop_qword()
{
    uint64_t v;
    pop_qword(&v);
    return v;
}

inline uint64_t CPU::get_qword(uint32_t off)
{
    uint64_t arg;
    mem.read_qword(reg[ESP]+off, &arg);
    return arg;
}

inline uint32_t CPU::get_dword(uint32_t off)
{
    uint32_t arg;
    mem.read_dword(reg[ESP]+off, &arg);
    return arg;
}

inline uint16_t CPU::get_word(uint32_t off)
{
    uint16_t arg;
    mem.read_word(reg[ESP]+off, &arg);
    return arg;
}

inline uint8_t CPU::get_byte(uint32_t off)
{
    uint8_t arg;
    mem.read_byte(reg[ESP]+off, &arg);
    return arg;
}

inline long double & CPU::get_fpu(RegisterST index)
{
#ifdef DEBUG_FPU
    if (fpu_empty[(fpu_top+index) & 7]) {
        std::cout << "FPU index empty" << std::endl;
        exit(0);
    }
#endif
    return fpu[(fpu_top+index) & 7];
}

inline void CPU::push_fpu(long double value)
{
    fpu_top = (fpu_top-1) & 7;
#ifdef DEBUG_FPU
    if (!fpu_empty[fpu_top]) {
        std::cout << "FPU index not empty" << std::endl;
        exit(0);
    }
    fpu_empty[fpu_top] = false;
#endif
    fpu[fpu_top] = value;
}

inline long double CPU::pop_fpu()
{
    long double ret = fpu[fpu_top];
#ifdef DEBUG_FPU
    if (fpu_empty[fpu_top]) {
        std::cout << "FPU index empty" << std::endl;
        exit(0);
    }
    fpu_empty[fpu_top] = true;
#endif
    fpu_top = (fpu_top+1) & 7;
    return ret;
}

inline void CPU::compare_ss(float a, float b)
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
        std::cout << "Unknown float relation!" << std::endl;
    }
    set_flags(false, false, zf, false, pf, cf);
}

inline void CPU::compare_sd(double a, double b)
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
        std::cout << "Unknown float relation!" << std::endl;
    }
    set_flags(false, false, zf, false, pf, cf);
}

