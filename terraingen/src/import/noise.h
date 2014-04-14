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

#ifndef TERRAINGEN_NOISE_H
#define TERRAINGEN_NOISE_H

#define CW_PI 3.1415927

inline double noise1(int x, int y)
{
    int n = x + y * 57;
    n = (n << 13) ^ n;
    int nn = (n * (n * n * 60493 + 19990303) - 771171059) & 0x7FFFFFFF;
    return 1.0 - (double(nn) / 1073741824.0);
}

static double cos_table[5000];

void init_noise()
{
    for (int i = 0; i < 5000; i++) {
        cos_table[i] = cos(i * 0.0002 * CW_PI);
    }
}

inline double fast_cos(double t)
{
    return cos_table[int(t * 5000.01)];
}

inline double cos_interpolate(double a, double b, double t)
{
    double f = (1.0 - fast_cos(t)) * 0.5;
    return a*(1.0-f) + b*f;
}

inline double interpolated_noise(double x, double y)
{
    int x_int = int(x);
    int y_int = int(y);
    double x_frac = x - double(x_int);
    double y_frac = y - double(y_int);

    double v1 = noise1(x_int, y_int);
    double v2 = noise1(x_int+1, y_int);
    double v3 = noise1(x_int, y_int+1);
    double v4 = noise1(x_int+1, y_int+1);

    double i1 = cos_interpolate(v1, v2, x_frac);
    double i2 = cos_interpolate(v3, v4, x_frac);
    return cos_interpolate(i1, i2, y_frac);
}

inline void sub_4D59F0()
{
    pop_ret();
    double x = to_sd(cpu.get_qword(0));
    double y = to_sd(cpu.get_qword(8));
    double r = interpolated_noise(x, y);
    cpu.push_fpu((long double)(r));
}

inline uint64_t make_pair(uint32_t a, uint32_t b)
{
    return (uint64_t(a) << 32) | b;
}

void sub_4FE970()
{
    pop_ret();
    uint32_t self = get_self();

    uint32_t a2 = cpu.pop_dword();
    uint32_t a3 = cpu.pop_dword();
    uint32_t a4 = cpu.pop_dword();

    int32_t v6_hi_max = int32_t(a3 + 128*128) / (128*128);
    int32_t v6_hi = int32_t(a3 - 128*128) / (128*128);
    mem.write_qword(a2, uint64_t(-1));
    double v4 = interpolated_noise(double(a4) * 0.0005, 3423.0);
    double v7 = interpolated_noise(double(a3) * 0.0005, 23421.0);
    int v29 = 0;
    int v22 = int(a3 + v4 * 3.0 * 256.0);
    int v21 = int(a4 + v7 * 3.0 * 256.0);
    int32_t v30 = 0;
    int32_t v6_lo_max = int32_t(a4 + 128*128) / (128*128);
    int32_t v6_lo_start = int32_t(a4 - 128*128) / (128*128);

    while (v6_hi < v6_hi_max) {
        int32_t v6_lo = v6_lo_start;
        while (v6_lo < v6_lo_max) {
            if (v6_hi < 0 || v6_hi >= 1024 || v6_lo >= 1024) {
                v6_lo++;
                continue;
            }
            int32_t i = (v6_hi << 10) + 1048623;
            int v26 = mem.read_dword(self + (v6_lo + i)*4);
            if (!v26) {
                v6_lo++;
                continue;
            }
            uint64_t v34 = int64_t(mem.read_dword(v26)) << 16;
            uint32_t v34_lo = v34 & 0xFFFFFFFF;
            uint32_t v34_hi = v34 >> 32;
            v34_lo -= (v22 << 16);
            v34_hi -= v34_lo < (v22 << 16);
            v34_hi -= v22 >> 16;

            const float v10 = 1 / 65536.0f;
            v34 = make_pair(v34_hi, v34_lo);
            float v17 = double(v34) * v10;

            int64_t v35 = uint64_t(mem.read_dword(v26+4)) << 16;
            v35 -= int64_t(v21) << 16;
            float v18 = double(v35);

            int32_t v19 = int32_t(v18 * v10 * v18 * v10 + v17 * v17);
            if (!v29 || v19 < v30) {
                v29 = v26;
                v30 = v19;
                mem.write_qword(a2, make_pair(v6_lo, v6_hi));
            }
            v6_lo++;
        }
        v6_hi++;
    }
    set_ret(a2);
    return;
}

#endif // TERRAINGEN_NOISE_H
