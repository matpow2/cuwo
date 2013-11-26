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

#ifndef TERRAINGEN_SSE_H
#define TERRAINGEN_SSE_H

#include "config.h"

class XMMReg
{
public:
    union 
    {
        int8_t d_s8[16];
        int16_t d_s16[8];
        int32_t d_s32[4];
        int64_t d_s64[2];
        uint8_t d_u8[16];
        uint16_t d_u16[8];
        uint32_t d_u32[4];
        uint64_t d_u64[2];
    };

#ifdef IS_BIG_ENDIAN
    FORCE_INLINE int8_t & s8(int i)
    {
        return d_s8[15 - i];
    }

    FORCE_INLINE uint8_t & u8(int i)
    {
        return d_u8[15 - i];
    }

    FORCE_INLINE int16_t & s16(int i)
    {
        return d_s16[7 - i];
    }

    FORCE_INLINE uint16_t & u16(int i)
    {
        return d_u16[7 - i];
    }

    FORCE_INLINE int32_t & s32(int i)
    {
        return d_s32[3 - i];
    }

    FORCE_INLINE uint32_t & u32(int i)
    {
        return d_u32[3 - i];
    }

    FORCE_INLINE int64_t & s32(int i)
    {
        return d_s64[1 - i];
    }

    FORCE_INLINE uint64_t & u64(int i)
    {
        return d_u64[1 - i];
    }
#else
    FORCE_INLINE int8_t & s8(int i)
    {
        return d_s8[i];
    }

    FORCE_INLINE uint8_t & u8(int i)
    {
        return d_u8[i];
    }

    FORCE_INLINE int16_t & s16(int i)
    {
        return d_s16[i];
    }

    FORCE_INLINE uint16_t & u16(int i)
    {
        return d_u16[i];
    }

    FORCE_INLINE int32_t & s32(int i)
    {
        return d_s32[i];
    }

    FORCE_INLINE uint32_t & u32(int i)
    {
        return d_u32[i];
    }

    FORCE_INLINE int64_t & s64(int i)
    {
        return d_s64[i];
    }

    FORCE_INLINE uint64_t & u64(int i)
    {
        return d_u64[i];
    }
#endif

    FORCE_INLINE XMMReg & operator=(uint64_t v)
    {
        u64(0) = v;
        u64(1) = 0;
        return *this;
    }

    FORCE_INLINE XMMReg & operator=(float v)
    {
        u32(0) = *((uint32_t*)&v);
        u32(1) = 0;
        u64(1) = 0;
        return *this;
    }

    FORCE_INLINE XMMReg & operator=(double v)
    {
        u64(0) = *((uint64_t*)&v);
        u64(1) = 0;
        return *this;
    }

    FORCE_INLINE XMMReg & operator=(uint32_t v)
    {
        u32(0) = v;
        u32(1) = 0;
        u64(1) = 0;
        return *this;
    }

    FORCE_INLINE XMMReg & operator=(XMMReg & v)
    {
        u64(0) = v.u64(0);
        u64(1) = v.u64(1);
        return *this;
    }

    FORCE_INLINE XMMReg & operator^(const XMMReg & v)
    {
        u64(0) ^= ((XMMReg&)v).u64(0);
        u64(1) ^= ((XMMReg&)v).u64(1);
        return *this;
    }

    FORCE_INLINE operator uint8_t()
    {
        return u8(0);
    }

    FORCE_INLINE operator uint16_t()
    {
        return u16(0);
    }

    FORCE_INLINE operator uint32_t()
    {
        return u32(0);
    }

    FORCE_INLINE operator uint64_t()
    {
        return u64(0);
    }

    FORCE_INLINE operator double()
    {
        return *((double*)&u64(0));
    }

    FORCE_INLINE operator float()
    {
        return *((float*)&u32(0));
    }

    FORCE_INLINE void reset()
    {
        
    }
};

inline float to_ss(uint32_t v)
{
    return *((float*)&v);
}

inline double to_sd(uint64_t v)
{
    return *((double*)&v);
}

inline uint32_t ss_to_si(float v)
{
    int32_t res = int32_t(v);
    return (uint32_t)(res);
}

inline uint64_t ss_to_d(float v)
{
    double vv = double(v);
    return *((uint64_t*)&vv);
}

inline uint32_t d_to_ss(double v)
{
    float vv = float(v);
    return *((uint32_t*)&vv);
}

inline uint64_t si_to_d(uint32_t a)
{
    int32_t aa = (int32_t)a;
    double v = double(aa);
    return *((uint64_t*)&v);
}

inline uint32_t si_to_ss(uint32_t a)
{
    int32_t aa = (int32_t)a;
    float v = float(aa);
    return *((uint32_t*)&v);
}

inline void dq_to_pd(XMMReg & dst, XMMReg src)
{
    uint32_t a = src.u32(0);
    uint32_t b = src.u32(1);
    dst.u64(0) = si_to_d(a);
    dst.u64(1) = si_to_d(b);
}

inline void ps_to_pd(XMMReg & dst, XMMReg src)
{
    float a = to_ss(src.u32(0));
    float b = to_ss(src.u32(1));
    dst.u64(0) = ss_to_d(a);
    dst.u64(1) = ss_to_d(b);
}

inline void pd_to_ps(XMMReg & dst, XMMReg src)
{
    double a = to_sd(src.u64(0));
    double b = to_sd(src.u64(1));
    dst.u32(0) = d_to_ss(a);
    dst.u32(1) = d_to_ss(b);
    dst.u64(1) = 0;
}

inline void dq_to_ps(XMMReg & dst, XMMReg src)
{
    dst.u32(0) = si_to_ss(src.u32(0));
    dst.u32(1) = si_to_ss(src.u32(1));
    dst.u32(2) = si_to_ss(src.u32(2));
    dst.u32(3) = si_to_ss(src.u32(3));
}

inline uint32_t sd_to_si(double v)
{
    int32_t res = int32_t(v);
    return (uint32_t)res;
}

inline float sd_to_ss(double v)
{
    return float(v);
}

inline double ss_to_sd(float v)
{
    return double(v);
}

inline long double to_ld(uint32_t v)
{
    return (long double)(to_ss(v));
}

inline long double to_ld(uint64_t v)
{
    return (long double)(to_sd(v));
}

inline uint32_t to_dword(float v)
{
    return *((uint32_t*)&v);
}

inline uint64_t to_qword(double v)
{
    return *((uint64_t*)&v);
}

inline uint32_t ld_to_dword(long double v)
{
    float vv = float(v);
    return to_dword(vv);
}

inline uint64_t ld_to_qword(long double v)
{
    double vv = double(v);
    return to_qword(vv);
}

inline void and_pd(XMMReg & dst, XMMReg src)
{
    dst.u64(0) &= ((XMMReg&)src).u64(0);
    dst.u64(1) &= ((XMMReg&)src).u64(1);
}

inline long double si_to_ld(uint64_t v)
{
    return (long double)((int64_t)v);
}

inline long double si_to_ld(uint32_t v)
{
    return (long double)((int32_t)v);
}

inline long double si_to_ld(uint16_t v)
{
    return (long double)((int16_t)v);
}

#endif // TERRAINGEN_SSE_H
