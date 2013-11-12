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

#ifndef TERRAINGEN_CPU_H
#define TERRAINGEN_CPU_H

#include <inttypes.h>
#include <limits>
#include <string.h>
#include <stdlib.h>
#include <boost/unordered_map.hpp>
#include "sse.h"

enum Register32
{
    EAX = 0,
    ECX,
    EDX,
    EBX,
    ESP,
    EBP,
    ESI,
    EDI
};


enum Register16
{
    AX = 0,
    CX,
    DX,
    BX,
    SP,
    BP,
    SI,
    DI
};

enum Register8
{
    AL = 0,
    CL,
    DL,
    BL,
    AH,
    CH,
    DH,
    BH
};

enum CPUFlag
{
    CF = 0,
    PF = 2,
    AF = 4,
    ZF = 6,
    SF = 7,
    TF = 8,
    IF = 9,
    DF = 10,
    OF = 11
};

enum RegisterXMM
{
    XMM0 = 0,
    XMM1,
    XMM2,
    XMM3,
    XMM4,
    XMM5,
    XMM6,
    XMM7
};

enum RegisterST
{
    ST0 = 0,
    ST1,
    ST2,
    ST3,
    ST4,
    ST5,
    ST6,
    ST7
};

class Memory;

typedef void (*FuncPointer)();

typedef boost::unordered_map<uint32_t, FuncPointer> FunctionMap;

class CPU
{
public:
    uint32_t reg[8];
    uint16_t *reg16[8];
    uint8_t *reg8[8];
    XMMReg xmm[8];
    size_t fpu_top;
    long double fpu[8];

    // saved for lazy eflags
    uint32_t res;
    uint32_t aux;

    FunctionMap functions;

    CPU();
    void reset_stack();

    bool get_zf();
    bool get_cf();
    bool get_sf();
    bool get_of();
    bool get_df();
    void set_of_cf(bool of, bool cf);
    void set_flags(bool of, bool sf, bool zf, bool af, bool pf, bool cf);

    uint32_t neg_dword(uint32_t v);
    uint8_t neg_byte(uint8_t v);
    uint32_t sub_dword(uint32_t a, uint32_t b);
    uint8_t sub_byte(uint8_t a, uint8_t b);
    uint32_t adc_dword(uint32_t a, uint32_t b);
    uint32_t sbb_dword(uint32_t a, uint32_t b);
    uint8_t sbb_byte(uint8_t a, uint8_t b);
    uint32_t dec_dword(uint32_t v);
    uint16_t dec_word(uint16_t v);
    uint8_t dec_byte(uint8_t v);
    uint32_t inc_dword(uint32_t v);
    uint16_t inc_word(uint16_t v);
    uint8_t inc_byte(uint8_t v);
    uint32_t or_dword(uint32_t a, uint32_t b);
    uint16_t or_word(uint16_t a, uint16_t b);
    uint8_t or_byte(uint8_t a, uint8_t b);
    uint32_t and_dword(uint32_t a, uint32_t b);
    uint16_t and_word(uint16_t a, uint16_t b);
    uint8_t and_byte(uint8_t a, uint8_t b);
    uint32_t shl_dword(uint32_t v, uint32_t count);
    uint16_t shl_word(uint16_t v, uint16_t count);
    uint32_t shld_dword(uint32_t v, uint32_t op2, uint32_t count);
    uint8_t shl_byte(uint8_t v, uint8_t count);
    uint32_t shr_dword(uint32_t v, uint32_t count);
    uint16_t shr_word(uint16_t v, uint16_t count);
    uint8_t shr_byte(uint8_t v, uint8_t count);
    uint32_t sar_dword(uint32_t v, uint32_t count);
    uint32_t rol_dword(uint32_t v, uint32_t count);
    uint16_t rol_word(uint16_t v, uint16_t count);
    uint32_t rcr_dword(uint32_t v, uint32_t count);
    void mul_dword(uint32_t v);
    void imul_dword(uint32_t v);
    uint32_t imul_dword(uint32_t v, uint32_t mul);
    void idiv_dword(uint32_t v);
    void div_dword(uint32_t v);
    uint32_t xadd_dword(uint32_t a, uint32_t & b);

    // sse
    void compare_ss(float a, float b);
    void compare_sd(double a, double b);

    void test_dword(uint32_t a, uint32_t b);
    void test_word(uint16_t a, uint16_t b);
    void test_byte(uint8_t a, uint8_t b);
    void cmp_dword(uint32_t a, uint32_t b);
    void cmp_word(uint16_t a, uint16_t b);
    void cmp_byte(uint8_t a, uint8_t b);

    void add_function(uint32_t addr, FuncPointer value);
    void call_dynamic(uint32_t addr);

    void push_byte(uint8_t arg);
    void push_word(uint16_t arg);
    void push_dword(uint32_t arg);
    void pop_byte(uint8_t * arg);
    uint8_t pop_byte();
    void pop_word(uint16_t * arg);
    uint16_t pop_word();
    void pop_dword(uint32_t * arg);
    uint32_t pop_dword();
    void pop_qword(uint64_t * arg);
    uint64_t pop_qword();

    long double & get_fpu(RegisterST index);
    void push_fpu(long double value);
    long double pop_fpu();

    // for stack
    uint64_t get_qword(uint32_t off);
    uint32_t get_dword(uint32_t off);
    uint16_t get_word(uint32_t off);
    uint8_t get_byte(uint32_t off);
};

// helper functions

#define WORD_UPPER_TO_BYTE(to,from) \
memcpy(&(to),((uint8_t *)&(from))+1,1);

#define WORD_LOWER_TO_BYTE(to,from) \
memcpy(&(to),&(from),1);

#define DWORD_UPPER_TO_WORD(to,from) \
memcpy(&(to),((uint8_t *)&(from))+2,2);

#define DWORD_LOWER_TO_WORD(to,from) \
memcpy(&(to),&(from),2);

#define QWORD_UPPER_TO_DWORD(to,from) \
memcpy(&(to),((uint8_t *)&(from))+4,4);

#define QWORD_LOWER_TO_DWORD(to,from) \
memcpy(&(to),&(from),4);

#define DWORD_FROM_WORDS(to, upper, lower) \
memcpy(&to,&lower,2); \
memcpy(((char *)&to)+2,&upper,2); 

#define QWORD_FROM_DWORDS(to, upper, lower) \
memcpy(&to,&lower,4); \
memcpy(((char *)&to)+4,&upper,4); 

#define GET32L(val) ((uint32_t)(((uint64_t)(val)) & 0xFFFFFFFF))
#define GET32H(val) ((uint32_t)(((uint64_t)(val)) >> 32))

inline uint32_t cdq_x86(uint32_t v)
{
    if (((int32_t)v) < 0)
        return std::numeric_limits<uint32_t>::max();
    return 0;
}

// custom/import helpers

extern CPU cpu;

inline void pop_ret()
{
    cpu.reg[ESP] += 4;
}

inline void add_ret()
{
    cpu.reg[ESP] -= 4;
}

inline uint32_t & get_self()
{
    return cpu.reg[ECX];
}

inline void set_ret(uint32_t v)
{
    cpu.reg[EAX] = v;
}

inline void set_ret(int v)
{
    set_ret(uint32_t(v));
}

inline void set_ret(uint64_t v)
{
    cpu.reg[EAX] = v & 0xFFFFFFFF;
    cpu.reg[EDX] = v >> 32;
}

inline void ret_self()
{
    set_ret(get_self());
}

#endif // TERRAINGEN_CPU_H
