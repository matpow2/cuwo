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
#include "config.h"

#ifdef NO_INLINE
#include "cpu.inl"
#endif

uint32_t CPU::reg[8];
XMMReg CPU::xmm[8];
int CPU::fpu_top;
long double CPU::fpu[8];
#ifdef DEBUG_FPU
bool CPU::fpu_empty[8];
#endif
bool CPU::zf, CPU::cf, CPU::sf, CPU::of;
FunctionMap CPU::functions;

CPU cpu;
