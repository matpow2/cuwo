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

#if BITS == 8
#define TYPE uint8_t
#define STYPE int8_t
#elif BITS == 16
#define TYPE uint16_t
#define STYPE int16_t
#elif BITS == 32
#define TYPE uint32_t
#define STYPE int32_t
#endif

#define SIGN_MASK (((TYPE)1) << (BITS - 1))

#define glue2(x, y) x ## _ ## y
#define glue1(x, y) glue2(x, y)
#define bitfunc(x) glue1(x, BITS)

FORCE_INLINE void bitfunc(set_eflags)(TYPE res)
{
    cpu.zf = res == 0;
    cpu.sf = (STYPE)res < 0;
    cpu.cf = false;
    cpu.of = false;
}

FORCE_INLINE void bitfunc(set_eflags_add)(TYPE a, TYPE b, TYPE res)
{
    cpu.cf = res < a;
    cpu.zf = res == 0;
    cpu.sf = (STYPE)res < 0;
    cpu.of = (STYPE)((a ^ b ^ -1) & (a ^ res)) < 0;
}

FORCE_INLINE void bitfunc(set_eflags_sub)(TYPE a, TYPE b, TYPE res)
{
    cpu.cf = a < b;
    cpu.zf = res == 0;
    cpu.sf = (STYPE)res < 0;
    cpu.of = (STYPE)((a ^ b) & (a ^ res)) < 0;
}

FORCE_INLINE void bitfunc(set_eflags_inc)(TYPE res)
{
    cpu.zf = res == 0;
    cpu.sf = (STYPE)res < 0;
    cpu.of = res == SIGN_MASK;
}

FORCE_INLINE void bitfunc(set_eflags_dec)(TYPE res)
{
    cpu.zf = res == 0;
    cpu.sf = (STYPE)res < 0;
    cpu.of = res == (SIGN_MASK - 1);
}

FORCE_INLINE void bitfunc(set_eflags_adc)(TYPE a, TYPE b, TYPE res)
{
    if (cpu.cf)
        cpu.cf = res <= a;
    else
        cpu.cf = res < a;
    cpu.zf = res == 0;
    cpu.sf = (STYPE)res < 0;
    cpu.of = (STYPE)((a ^ b ^ -1) & (a ^ res)) < 0;
}

FORCE_INLINE void bitfunc(set_eflags_sbb)(TYPE a, TYPE b, TYPE res)
{
    if (cpu.cf)
        cpu.cf = a <= b;
    else
        cpu.cf = a < b;
    cpu.zf = res == 0;
    cpu.sf = (STYPE)res < 0;
    cpu.of = (STYPE)((a ^ b) & (a ^ res)) < 0;
}

// cmp

FORCE_INLINE void bitfunc(set_eflags_cmp_cf)(TYPE a, TYPE b, TYPE res)
{
    cpu.cf = a < b;
}

FORCE_INLINE void bitfunc(set_eflags_cmp_zf)(TYPE a, TYPE b, TYPE res)
{
    cpu.zf = res == 0;
}

FORCE_INLINE void bitfunc(set_eflags_cmp_sf)(TYPE a, TYPE b, TYPE res)
{
    cpu.sf = (STYPE)res < 0;
}

FORCE_INLINE void bitfunc(set_eflags_cmp_of)(TYPE a, TYPE b, TYPE res)
{
    cpu.of = (STYPE)((a ^ b) & (a ^ res)) < 0;
}

#undef TYPE
#undef STYPE
#undef SIGN_MASK
#undef glue1
#undef glue2
#undef bitfunc
