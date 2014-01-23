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

inline double cos_interpolate(double a, double b, double t)
{
    double ft = t * CW_PI;
    double f = (1.0 - cos(ft)) * 0.5;
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

#endif // TERRAINGEN_NOISE_H
