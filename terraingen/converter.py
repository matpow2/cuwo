# Copyright (c) Mathias Kaerlev 2013-2014.
#
# This file is part of cuwo.
#
# cuwo is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# cuwo is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with cuwo.  If not, see <http://www.gnu.org/licenses/>.

import pefile
import pydasm
from cStringIO import StringIO
import collections
import struct
import itertools
import os
import math
import config
from config import function_alias, import_alias, function_enders
from ctypes import c_int32

LICENSE_TEXT = '''\
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
'''

class StringWrapper(object):
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return self.value

    def __repr__(self):
        new = ''
        for c in self.value:
            if c == '\\':
                new += '\\\\'
            elif c == '"':
                new += '\\"'
            elif c == '\r':
                new += '\\r'
            elif c == '\n':
                new += '\\n'
            elif ord(c) > 128:
                new += '\\' + oct(ord(c))[1:]
            else:
                new += c
        return '"%s"' % new


def to_c(format_spec, *args):
    new_args = []
    for arg in args:
        if isinstance(arg, str):
            arg = StringWrapper(arg)
        elif isinstance(arg, bool):
            if arg:
                arg = 'true'
            else:
                arg = 'false'
        new_args.append(arg)
    return format_spec % tuple(new_args)

class CodeWriter(object):
    indentation = 0
    comment = None
    line_count = 0

    def __init__(self, filename, license=True):
        self.fp = StringIO()
        self.filename = filename
        if license:
            self.putln(LICENSE_TEXT)
    
    def format_line(self, line):
        return self.get_spaces() + line
    
    def putln(self, *lines):
        for line in lines:
            line = self.format_line(line)
            if self.comment:
                line = '%s // %s' % (line, self.comment)
            self.fp.write(line + '\n')
            self.line_count += 1

    def putlnc(self, line, *arg):
        line = to_c(line, *arg)
        self.putln(line)
    
    def get_data(self):
        fp = self.fp
        pos = fp.tell()
        fp.seek(0)
        data = fp.read()
        fp.seek(pos)
        return data

    def start_brace(self):
        self.putln('{')
        self.indent()

    def end_brace(self, semicolon = False):
        self.dedent()
        text = '}'
        if semicolon:
            text += ';'
        self.putln(text)

    def putmeth(self, name, *arg, **kw):
        fullarg = list(arg)
        self.putln('%s(%s)' % (name, ', '.join(fullarg)))
        self.start_brace()

    def put_label(self, name):
        self.putln('%s: ;' % name)

    def start_guard(self, name):
        self.putln('#ifndef %s' % name)
        self.putln('#define %s' % name)
        self.putln('')

    def close_guard(self, name):
        self.putln('')
        self.putln('#endif // %s' % name)
        self.putln('')
    
    def indent(self):
        self.indentation += 1
        
    def dedent(self):
        self.indentation -= 1
        if self.indentation < 0:
            raise ValueError('indentation cannot be lower than 0')
        
    def get_spaces(self, extra = 0):
        return (self.indentation + extra) * '    '
    
    def close(self):
        data = self.get_data()
        self.fp.close()
        if self.filename is None:
            return
        try:
            fp = open(self.filename, 'rb')
            original_data = fp.read()
            fp.close()
            if original_data == data:
                return
        except IOError:
            pass
        fp = open(self.filename, 'wb')
        fp.write(data)
        fp.close()

MODE_32 = 0
MODE_16 = 1

REG_GEN = pydasm.REGISTER_TYPE_GEN
REG_SEGMENT = pydasm.REGISTER_TYPE_SEGMENT
REG_XMM = pydasm.REGISTER_TYPE_XMM
REG_MMX = pydasm.REGISTER_TYPE_MMX
REG_FPU = pydasm.REGISTER_TYPE_FPU

REG_GEN_DWORD = 'dword'
REG_GEN_WORD = 'word'
REG_GEN_BYTE = 'byte'

reg_table = {
    REG_GEN_DWORD: ["EAX", "ECX", "EDX", "EBX", "ESP", "EBP", "ESI", "EDI"],
    REG_GEN_WORD: ["AX", "CX", "DX", "BX", "SP", "BP", "SI", "DI"],
    REG_GEN_BYTE: ["AL", "CL", "DL", "BL", "AH", "CH", "DH", "BH"],
    REG_SEGMENT: ["ES", "CS", "SS", "DS", "FS", "GS"],
    REG_XMM: ["XMM0", "XMM1", "XMM2", "XMM3", "XMM4", "XMM5", "XMM6", "XMM7"],
    REG_MMX: ["MM0", "MM1", "MM2", "MM3", "MM4", "MM5", "MM6", "MM7"],
    REG_FPU: ["ST0", "ST1", "ST2", "ST3", "ST4", "ST5", "ST6", "ST7"],
}

reg_ref_table = {
    REG_GEN_DWORD: 'cpu.reg[%s]',
    REG_GEN_WORD: 'cpu.get_reg16(%s)',
    REG_GEN_BYTE: 'cpu.get_reg8(%s)',
    REG_SEGMENT: 'mem.segment_table[%s]',
    REG_XMM: 'cpu.xmm[%s]',
    REG_FPU: 'cpu.get_fpu(%s)'
}

OT_a = 0x01000000
OT_b = 0x02000000        # always 1 byte
OT_c = 0x03000000        # byte or word, depending on operand
OT_d = 0x04000000        # double-word
OT_q = 0x05000000        # quad-word
OT_dq = 0x06000000       # double quad-word
OT_v = 0x07000000        # word or double-word, depending on operand
OT_w = 0x08000000        # always word
OT_p = 0x09000000        # 32-bit or 48-bit pointer
OT_pi = 0x0a000000       # quadword MMX register
OT_pd = 0x0b000000       # 128-bit double-precision float
OT_ps = 0x0c000000       # 128-bit single-precision float
OT_s = 0x0d000000        # 6-byte pseudo descriptor
OT_sd = 0x0e000000       # Scalar of 128-bit double-precision float
OT_ss = 0x0f000000       # Scalar of 128-bit single-precision float
OT_si = 0x10000000       # Doubleword integer register
OT_t = 0x11000000        # 80-bit packed FP data

operand_sizes = {
    0: (4, 2),
    OT_a: (4, 2),
    OT_b: (1, 1),
    OT_c: (2, 1),
    OT_d: (4, 4),
    OT_q: (8, 8),
    OT_dq: (16, 16),
    OT_v: (4, 2),
    OT_w: (2, 2),
    OT_p: (6, 4),
    OT_ps: (16, 16),
    OT_ss: (16, 16),
    OT_sd: (16, 16),
    OT_pd: (16, 16),
    OT_t: (8, 8)
}

REG_EAX = REG_AX = REG_AL = REG_ES = REG_ST0 = pydasm.REGISTER_EAX
REG_ECX = REG_CX = REG_CL = REG_CS = REG_ST1 = pydasm.REGISTER_ECX
REG_EDX = REG_DX = REG_DL = REG_SS = REG_ST2 = pydasm.REGISTER_EDX
REG_EBX = REG_BX = REG_BL = REG_DS = REG_ST3 = pydasm.REGISTER_EBX
REG_ESP = REG_SP = REG_AH = REG_FS = REG_ST4 = pydasm.REGISTER_ESP
REG_EBP = REG_BP = REG_CH = REG_GS = REG_ST5 = pydasm.REGISTER_EBP
REG_ESI = REG_SI = REG_DH = REG_ST6 = pydasm.REGISTER_ESI
REG_EDI = REG_DI = REG_BH = REG_ST7 = pydasm.REGISTER_EDI
REG_NOP = pydasm.REGISTER_NOP

AM_A = 0x00010000  # Direct address with segment prefix
AM_I = 0x00060000  # Immediate data follows
AM_J = 0x00070000  # Immediate value is relative to EIP
AM_I1 = 0x00200000 # Immediate byte 1 encoded in instruction


def get_mask_ot(x):
    return x & 0xff000000


def get_mask_am(x):
    return x & 0x00ff0000


def get_register(reg, reg_type):
    reg_name = reg_table[reg_type][reg]
    return reg_ref_table[reg_type] % reg_name


def get_gen_register(reg, size):
    if size == 1:
        reg_type = REG_GEN_BYTE
    elif size == 2:
        reg_type = REG_GEN_WORD
    else:
        reg_type = REG_GEN_DWORD
    return get_register(reg, reg_type)


def uint32_to_int32(v):
    return c_int32(v).value


class Operand(object):
    __slots__ = ['is_memory', 'is_register', 'is_immediate', 'is_reloc',
                 'has_import_alias', 'index_reg', 'scale', 'base_reg',
                 'displacement', 'reg_type', 'reloc_value', 'type', 'size',
                 'value', 'reloc_displacement']

    def __init__(self, inst, op, offset):
        # default init
        self.is_memory = False
        self.is_register = False
        self.is_immediate = False
        self.is_reloc = False
        self.has_import_alias = False
        self.index_reg = None
        self.scale = None
        self.base_reg = None
        self.displacement = None
        self.reg_type = None

        self.type = op.type

        mode = inst.get_operand_mode()
        mask_ot = get_mask_ot(op.flags)
        self.size = operand_sizes[mask_ot][mode]

        if self.type == pydasm.OPERAND_TYPE_REGISTER:
            self.is_register = True
            self.reg_type = pydasm.get_register_type(op)

            if self.reg_type == REG_GEN:
                if mask_ot == OT_b:
                    self.reg_type = REG_GEN_BYTE
                elif mask_ot == OT_v:
                    if mode == MODE_32:
                        self.reg_type = REG_GEN_DWORD
                    else:
                        self.reg_type = REG_GEN_WORD
                elif mask_ot == OT_w:
                    self.reg_type = REG_GEN_WORD
                elif mask_ot == OT_d:
                    self.reg_type = REG_GEN_DWORD
                elif mask_ot == OT_dq:
                    self.reg_type = REG_GEN_DWORD
                else:
                    raise NotImplementedError()

            self.value = get_register(op.reg, self.reg_type)
        elif self.type == pydasm.OPERAND_TYPE_MEMORY:
            self.is_memory = True
            sum_list = []
            mode = inst.get_address_mode()
            group2 = inst.group2()
            if group2:
                sum_list.append(get_register(group2-1, REG_SEGMENT))

            # Base register
            if op.basereg != REG_NOP:
                if mode == MODE_32:
                    reg_type = REG_GEN_DWORD
                else:
                    reg_type = REG_GEN_WORD
                self.base_reg = get_register(op.basereg, reg_type)
                sum_list.append(self.base_reg)

            # Index register
            if op.indexreg != REG_NOP:
                if mode == MODE_32:
                    reg_type = REG_GEN_DWORD
                else:
                    reg_type = REG_GEN_WORD
                index = self.index_reg = get_register(op.indexreg, reg_type)
                if op.scale in (2, 4, 8):
                    self.scale = op.scale
                    index += '*%s' % self.scale
                sum_list.append(index)
            # INTEL displacement
            if inst.dispbytes:
                addr = op.displacement
                if inst.has_reloc and addr in inst.converter.reloc_values:
                    self.reloc_displacement = inst.converter.get_reloc(addr)
                    self.is_reloc = True
                if op.displacement & (1<<(op.dispbytes*8-1)):
                    tmp = op.displacement
                    if op.dispbytes == 1:
                        tmp = ~tmp & 0xff
                    elif op.dispbytes == 2:
                        tmp = ~tmp & 0xffff
                    elif op.dispbytes == 4:
                        tmp = ~tmp & 0xffffffff
                    else:
                        raise NotImplementedError()
                    self.displacement = '(-0x%x)' % (tmp + 1)
                # Positive displacement
                else:
                    self.displacement = '0x%x' % op.displacement
                sum_list.append(self.displacement)

            if len(sum_list) == 1 and inst.dispbytes:
                addr = op.displacement

                if (addr in inst.converter.imports
                    and addr not in inst.converter.import_addresses.values()):
                    self.displacement = str(addr)
                    self.is_memory = False
                    self.is_immediate = True
                    self.is_reloc = False
                    self.value = self.get_import_alias(addr, inst)
                    return

            self.value = '+'.join(sum_list)
            if self.is_reloc:
                self.reloc_value = '+'.join(sum_list[:-1]
                                            + [self.reloc_displacement])

        elif self.type == pydasm.OPERAND_TYPE_IMMEDIATE:
            self.is_immediate = True
            mask = get_mask_am(op.flags)
            if mask == AM_J:
                value = uint32_to_int32(op.immediate) + inst.length + offset
            elif mask in (AM_I1, AM_I):
                value = op.immediate & 0xFFFFFFFF
            # 32-bit or 48-bit address
            elif mask == AM_A:
                raise NotImplementedError()
                string += '0x%x:0x%x' % (op.section, op.displacement)

            if inst.has_reloc and value in inst.converter.reloc_values:
                self.reloc_value = inst.converter.get_reloc(value)
                self.is_reloc = True

            self.value = value

    def get_import_alias(self, addr, inst):
        name = inst.converter.imports[addr][0].name
        try:
            dll_addr = inst.converter.import_addresses[name]
        except KeyError:
            return addr
        try:
            section = inst.converter.get_section(dll_addr)
        except NotImplementedError:
            return addr
        if section.section_name == 'text':
            # function alias
            return addr
        # data alias
        return dll_addr

    def get(self, as_reloc=True):
        as_reloc = self.is_reloc and as_reloc
        if as_reloc:
            value = self.reloc_value
        else:
            value = self.value
        if self.is_memory:
            return get_memory(value, self.size)
        if self.is_immediate and not as_reloc:
            return '%sU' % value
        return value

def get_memory(addr, size):
    func = 'mem.read_%s' % size_names[size]
    return '%s(%s)' % (func, addr)


class Instruction(object):
    __slots__ = ['converter', 'address', 'has_reloc', 'length', 'type', 'mode',
                 'opcode', 'modrm', 'sib', 'extindex', 'fpuindex', 'dispbytes',
                 'immbytes', 'sectionbytes', 'flags', 'op1', 'op2', 'op3',
                 'prefix', 'eflags_affected', 'eflags_used',
                 'eflags_dependency', 'disasm', 'mnemonic',
                 'condition_value']

    def __init__(self, i, offset, converter):
        self.converter = converter
        self.address = offset

        self.has_reloc = False
        self.condition_value = None

        for pos in xrange(offset, offset+i.length):
            if pos in converter.reloc_addresses:
                self.has_reloc = True
                break

        self.length = i.length
        self.type = i.type
        self.mode = i.mode
        self.opcode = i.opcode
        self.modrm = i.modrm
        self.sib = i.sib
        self.extindex = i.extindex
        self.fpuindex = i.fpuindex
        self.dispbytes = i.dispbytes
        self.immbytes = i.immbytes
        self.sectionbytes = i.sectionbytes
        self.flags = i.flags

        if i.op1.type:
            self.op1 = Operand(self, i.op1, offset)
        else:
            self.op1 = None
        if i.op2.type:
            self.op2 = Operand(self, i.op2, offset)
        else:
            self.op2 = None
        if i.op3.type:
            self.op3 = Operand(self, i.op3, offset)
        else:
            self.op3 = None
        
        mnemonic = pydasm.get_mnemonic_string(i, pydasm.FORMAT_INTEL)
        mnemonic = mnemonic.strip()
        if mnemonic == 'rep retn':
            mnemonic = 'retn'
        elif mnemonic == 'rep ret':
            mnemonic = 'ret'
        mnemonic = mnemonic.split()

        if mnemonic[0] in ["rep", "repe", "repne", "lock"]:
            self.prefix = mnemonic[0]
            mnemonic = mnemonic[1:]
        else:
            self.prefix = None

        if len(mnemonic) > 2:
            if mnemonic != ['bts', 'dword']:
                print mnemonic
                raise NotImplementedError()

        self.mnemonic = mnemonic[0]

        affected = eflags_affected.get(self.mnemonic, i.eflags_affected)
        used = eflags_used.get(self.mnemonic, i.eflags_used)
        self.eflags_affected = get_eflags(affected)
        self.eflags_used = get_eflags(used)
        self.eflags_dependency = collections.defaultdict(list)

        self.disasm = pydasm.get_instruction_string(i, pydasm.FORMAT_INTEL,
                                                    0).rstrip(" ")

    def is_end(self):
        if self.mnemonic != 'call':
            return False
        op = self.op1
        if not op.is_immediate:
            return False
        name = self.converter.get_function_name(op.value)
        return name in function_enders

    def get_disasm(self):
        return self.disasm
    
    def group2(self):
        return (self.flags & 0x00ff0000) >> 16

    def operand_so(self):
        return bool(self.flags & 0x00000100)

    def get_operand_mode(self):
        if self.operand_so():
            return MODE_16
        else:
            return MODE_32

    def address_so(self):
        return bool(self.flags & 0x00001000)

    def get_address_mode(self):
        if self.flags & 0x00001000:
            return MODE_16
        else:
            return MODE_32

    def address_size(self):
        if self.address_so():
            return 2
        else:
            return 4

    def get_condition(self):
        if self.mnemonic in ('sbb', 'adc', 'rcr'):
            return 'c'
        elif self.mnemonic.startswith('j'):
            return self.mnemonic[1:]
        elif self.mnemonic.startswith('cmov'):
            return self.mnemonic[4:]
        elif self.mnemonic.startswith('set'):
            return self.mnemonic[3:]
        return None

    def get_dependees(self):
        dependees = set()
        for value in self.eflags_dependency.values():
            dependees.update(value)
        return dependees

    def get_condition_value(self):
        if self.condition_value is None:
            raise NotImplementedError()
        return self.condition_value


def get_label_name(address):
    return 'loc_%X' % address

label_makers = set([
    'jc', # 0x72,
    'jz', # 0x74,
    'jnz',
    'jl',
    'jnl',
    'jna',
    'jns',
    'js',
    'jng',
    'jnc',
    'ja',
    'jb',
    'jg',
    ('jmp', 0xEB),
    ('jmp', 0xE9)
])

class Subroutine(object):
    __slots__ = ['start', 'instructions', 'instruction_list', 'labels',
                 'end', 'jumps', 'child_sub', 'enders', 'name']

    def __init__(self, converter, address):
        self.child_sub = None
        if converter is None:
            return
        self.name = None
        self.start = address
        self.instructions = {}
        self.instruction_list = []
        self.labels = set()
        self.jumps = {}
        self.enders = set()

        label_eflags = {}
        eflags_cache = collections.defaultdict(list)

        i = 0
        while True:
            try:
                data = converter.get_memory(address, 16)
            except NotImplementedError, e:
                print 'Could not get memory for address %X' % address
                raise e
            raw_instruction = pydasm.get_instruction(data, pydasm.MODE_32)
            if not raw_instruction:
                print 'Invalid instruction at %X' % address
                break
            instruction = Instruction(raw_instruction, address, converter)
            add_eflags = label_eflags.get(address, None)
            if add_eflags:
                for k, v in add_eflags.iteritems():
                    eflags_cache[k] += v
            for flag in instruction.eflags_used:
                for inst_dep in eflags_cache[flag]:
                    dependency = inst_dep.eflags_dependency
                    dependency[flag].append(instruction)
            for flag in instruction.eflags_affected:
                eflags_cache[flag] = [instruction]

            opcode = instruction.opcode
            self.instructions[address] = instruction
            self.instruction_list.append(instruction)
            address += instruction.length

            mnemonic = instruction.mnemonic
            keys = set([(mnemonic, opcode), mnemonic])

            if mnemonic in ('jmp', 'call'):
                eflags_cache.clear()

            if self.is_end(instruction, i):
                self.enders.add(instruction.address)
                if self.labels:
                    if max(self.labels) < address:
                        # do we still have labels to process?
                        break
                else:
                    break
            elif not keys.isdisjoint(label_makers):
                self.add_jump(instruction.address, instruction.op1.value)
                eflags_copy = {}
                for k, v in eflags_cache.iteritems():
                    eflags_copy[k] = v[:]
                label_eflags[instruction.op1.value] = eflags_copy

            i += 1

        self.end = address

        # do a second pass, checking for instructions that are never used
        # i = 0
        # check_label = False
        # new_list = []
        # for instruction in self.instruction_list:
        #     if check_label and instruction.address not in self.labels:
        #         del self.instructions[instruction.address]
        #         continue
        #     check_label = False
        #     if self.is_end(instruction, i):
        #         check_label = True
        #     new_list.append(instruction)
        #     i += 1
        # self.instruction_list = new_list

    def can_split_direct(self):
        return len(self.enders) == 1

    def can_split(self, address):
        """
        Can only be called after initial decode
        """
        for src, dst in self.jumps.iteritems():
            minimum = min(src, dst)
            maximum = max(src, dst)
            if address >= minimum and address < maximum:
                return False
        return True

    def set_instruction_list(self, items, jumps, enders):
        self.instructions = {}
        self.instruction_list = items
        for instruction in items:
            self.instructions[instruction.address] = instruction
        self.start = items[0].address
        self.end = items[-1].address + items[-1].length
        self.jumps = {}
        for src, dst in jumps.iteritems():
            if src not in self.instructions:
                continue
            self.jumps[src] = dst
        self.labels = set(self.jumps.values())
        self.enders = set()
        for ender in enders:
            if ender not in self.instructions:
                continue
            self.enders.add(ender)

    def split(self, address):
        other_sub = Subroutine(None, None)
        instruction = self.instructions[address]
        index = self.instruction_list.index(instruction)
        items = self.instruction_list[:index]
        other_items = self.instruction_list[index:]
        jumps = self.jumps
        enders = self.enders
        self.set_instruction_list(items, jumps, enders)
        other_sub.set_instruction_list(other_items, jumps, enders)
        self.child_sub = other_sub
        return other_sub

    def add_jump(self, src, dst):
        self.jumps[src] = dst
        self.labels.add(dst)

    def is_end(self, inst, index):
        mnemonic = inst.mnemonic
        opcode = inst.opcode
        if mnemonic in ('retn', 'ret', 'int3'):
            return True
        if mnemonic == 'jmp' and opcode in (0xFF,):
            # far jumps
            return True
        if mnemonic == "jmp" and index == 0:
            # wrapper functions
            return True
        if inst.is_end():
            # special 'call's, checks config.py for function enders
            return True
        return False


size_names = {
    16: 'dqword',
    8: 'qword',
    4: 'dword',
    2: 'word',
    1: 'byte'
}

size_types = {
    8: 'uint64_t',
    4: 'uint32_t',
    2: 'uint16_t',
    1: 'uint8_t'
}

signed_types = {
    8: 'int64_t',
    4: 'int32_t',
    2: 'int16_t',
    1: 'int8_t'
}

float_types = {
    16: 'pd',
    8: 'sd',
    4: 'ss'
}

def prettify_value(value):
    if isinstance(value, (long, int)):
        value = '%#x' % value
    return value

def get_flag(value):
    if value == 'DF':
        return 'false'
    return 'cpu.get_%s()' % value.lower()

def get_fpu():
    return get_register(REG_ST0, REG_FPU)


EFL_CF = 1 << 0
EFL_ZF = 1 << 6
EFL_SF = 1 << 7
EFL_OF = 1 << 11


def get_eflags(value):
    l = set()
    if value & EFL_CF:
        l.add('CF')
    if value & EFL_ZF:
        l.add('ZF')
    if value & EFL_SF:
        l.add('SF')
    if value & EFL_OF:
        l.add('OF')
    return l


def format_cond(v):
    for flag in ('OF', 'ZF', 'SF', 'CF'):
        v = v.replace(flag, get_flag(flag))
    return v

COND_NZ = COND_NE = format_cond('!ZF')
COND_L = format_cond('SF != OF')
COND_NLE = format_cond('!ZF && SF == OF')
COND_NBE = format_cond('!CF && !ZF')
COND_BE = COND_NA = format_cond('CF || ZF')
COND_O = format_cond('OF')
COND_Z = COND_E = format_cond('ZF')
COND_AE = COND_NC = format_cond('!CF')
COND_A = format_cond('!CF && !ZF')
COND_B = COND_C = format_cond('CF')
COND_G = format_cond('!ZF && SF == OF')
COND_GE = COND_NL = format_cond('SF == OF')
COND_LE = COND_NG = format_cond('ZF || SF != OF')
COND_S = format_cond('SF')
COND_NS = format_cond('!SF')


NAME_TO_EFL = {
    'OF': EFL_OF,
    'CF': EFL_CF,
    'ZF': EFL_ZF,
    'SF': EFL_SF
}


def get_cond_eflags(v):
    flags = 0
    for flag in ('OF', 'ZF', 'SF', 'CF'):
        if get_flag(flag) not in v:
            continue
        flags |= NAME_TO_EFL[flag]
    return flags


eflags_affected = {
    'comiss': EFL_CF | EFL_ZF | EFL_SF | EFL_OF,
    'comisd': EFL_CF | EFL_ZF | EFL_SF | EFL_OF
}


eflags_used = {
    'adc': EFL_CF,
    'sbb': EFL_CF,
    'rcr': EFL_CF,
    'cmovae': get_cond_eflags(COND_AE),
    'cmova': get_cond_eflags(COND_A),
    'cmovbe': get_cond_eflags(COND_BE),
    'cmovb': get_cond_eflags(COND_B),
    'cmovg': get_cond_eflags(COND_G),
    'cmovge': get_cond_eflags(COND_GE),
    'cmovl': get_cond_eflags(COND_L),
    'cmovle': get_cond_eflags(COND_LE),
    'cmove': get_cond_eflags(COND_E),
    'cmovne': get_cond_eflags(COND_NE),
    'cmovs': get_cond_eflags(COND_S)
}


class CPU(object):
    eip = None
    sub = None

    def __init__(self, converter):
        self.converter = converter
        self.log = converter.log
        self.get_function_name = converter.get_function_name
        self.eflags_id = itertools.count()
        self.result_id = itertools.count()
        self.mnemonic_stats = collections.Counter()

    def set_sub(self, sub):
        self.index = 0
        self.sub = sub
        self.eip = sub.start
        self.remaining_labels = sub.labels.copy()
        self.unimplemented = None
        self.writer = self.converter.writer

    def find_instruction(self, mnemonic, steps):
        keys = sorted(self.sub.instructions.keys())
        index = keys.index(self.eip)
        direction = int(math.copysign(1, steps))
        while steps != 0:
            index += direction
            steps -= direction
            address = keys[index]
            instruction = self.sub.instructions[address]
            if instruction.mnemonic == mnemonic:
                return instruction
        return None

    def on_fail(self, message, i):
        self.writer.comment = None
        if self.unimplemented is None:
            self.unimplemented = True
        print 'Conversion skipped %X:' % (self.sub.start)
        print "%s: [%#x][%x] %s" % (message, self.eip, i.opcode,
                                    i.get_disasm())

    def next(self):
        instruction = self.sub.instruction_list[self.index]
        self.eip = instruction.address

        if self.eip in self.sub.labels:
            self.writer.put_label(get_label_name(self.eip))
            self.remaining_labels.discard(self.eip)

        name = 'on_%s' % instruction.mnemonic
        self.mnemonic_stats[instruction.mnemonic] += 1
        handler = getattr(self, name, None)

        if handler is None:
            self.on_fail('Not implemented', instruction)
            return False

        rep_reg = None
        if instruction.prefix == 'rep':
            if instruction.get_address_mode() != MODE_32:
                raise NotImplementedError()
            rep_reg = get_register(REG_ECX, REG_GEN_DWORD)
        elif instruction.prefix is not None:
            raise NotImplementedError()

        if rep_reg:
            self.writer.putln('while (%s > 0) {' % rep_reg)
            self.writer.indent()

        self.writer.comment = '[%X] %s' % (self.eip, instruction.get_disasm())

        if handler(instruction) is False:
            self.on_fail('Handler skipped', instruction)
            if rep_reg:
                self.writer.end_brace()
            return False

        self.writer.comment = None

        if rep_reg:
            self.writer.putln('%s -= 1;' % rep_reg)
            self.writer.end_brace()

        self.index += 1

        if self.index == len(self.sub.instruction_list):
            self.remaining_labels = set()
            return False

        return True

    def set_memory(self, dest, src, size):
        func = 'mem.write_%s' % size_names[size]
        typ = size_types[size]
        self.writer.putlnc('%s(%s, %s);', func, dest, src)

    def set_register(self, dest, src):
        self.writer.putlnc('%s = %s;', dest, src)

    def push_dword(self, value):
        value = prettify_value(value)
        self.writer.putlnc('cpu.push_dword(%s);' % value)

    def pop_dword(self, value):
        value = prettify_value(value)
        self.writer.putlnc('cpu.pop_dword(&%s);' % value)

    def set_op(self, op, value):
        if op.is_memory:
            if op.is_reloc:
                self.set_memory(op.reloc_value, value, op.size)
            else:
                self.set_memory(op.value, value, op.size)
        else:
            self.set_register(op.get(), value)

    def set_op_eflags(self, i, op, value, *args):
        if not i.eflags_dependency:
            if args:
                value %= args
            self.set_op(op, value)
            return None
        size_type = size_types[op.size]
        if args:
            names = []
            for arg in args:
                name = 'temp_%s' % self.result_id.next()
                self.writer.putlnc('%s %s;', size_type, name)
                self.writer.putlnc('%s = %s;', name, arg)
                names.append(name)
            value %= tuple(names)
        name = 'temp_%s' % self.result_id.next()
        self.writer.putlnc('%s %s;', size_type, name)
        self.writer.putlnc('%s = %s;', name, value)
        self.set_op(op, name)
        if args:
            names.insert(0, name)
            return names
        return name

    def goto(self, test, address):
        if address < self.sub.start or address >= self.sub.end:
            is_call = True
            call = '%s()' % self.get_function_name(address)
        else:
            is_call = False
            call = 'goto %s' % get_label_name(address)
        self.writer.putlnc('if (%s) {', test)
        self.writer.indent()
        self.writer.putlnc('%s;' % call)
        if is_call:
            self.writer.putln('return;')
        self.writer.end_brace()

    def call_dynamic(self, value):
        self.writer.putln('cpu.call_dynamic(%s);' % value)

    def on_push(self, i):
        self.push_dword(i.op1.get())

    def on_pop(self, i):
        if not i.op1.is_register:
            return False
        self.pop_dword(i.op1.value)

    def on_mov(self, i):
        i.op2.size = i.op1.size
        self.set_op(i.op1, i.op2.get())

    def on_movsx(self, i):
        signed1 = signed_types[i.op1.size]
        unsigned1 = size_types[i.op1.size]
        signed2 = signed_types[i.op2.size]
        self.set_op(i.op1, '(%s)((%s)((%s)(%s)))' % (unsigned1, signed1,
                                                     signed2, i.op2.get()))

    def on_movd(self, i):
        i.op1.size = i.op2.size = 4
        self.set_op(i.op1, i.op2.get())

    def on_mulsd(self, i):
        i.op1.size = i.op2.size = 8
        value = 'to_sd(%s) * to_sd(%s)' % (i.op1.get(), i.op2.get())
        self.set_op(i.op1, value)

    def on_mulss(self, i):
        i.op1.size = i.op2.size = 4
        value = 'to_ss(%s) * to_ss(%s)' % (i.op1.get(), i.op2.get())
        self.set_op(i.op1, value)

    def on_addss(self, i):
        i.op1.size = i.op2.size = 4
        value = 'to_ss(%s) + to_ss(%s)' % (i.op1.get(), i.op2.get())
        self.set_op(i.op1, value)

    def on_subss(self, i):
        i.op1.size = i.op2.size = 4
        value = 'to_ss(%s) - to_ss(%s)' % (i.op1.get(), i.op2.get())
        self.set_op(i.op1, value)

    def on_divss(self, i):
        i.op1.size = i.op2.size = 4
        value = 'to_ss(%s) / to_ss(%s)' % (i.op1.get(), i.op2.get())
        self.set_op(i.op1, value)

    def on_addsd(self, i):
        i.op1.size = i.op2.size = 8
        value = 'to_sd(%s) + to_sd(%s)' % (i.op1.get(), i.op2.get())
        self.set_op(i.op1, value)   

    def on_divsd(self, i):
        i.op1.size = i.op2.size = 8
        value = 'to_sd(%s) / to_sd(%s)' % (i.op1.get(), i.op2.get())
        self.set_op(i.op1, value)   

    def on_subsd(self, i):
        i.op1.size = i.op2.size = 8
        value = 'to_sd(%s) - to_sd(%s)' % (i.op1.get(), i.op2.get())
        self.set_op(i.op1, value)

    def on_andpd(self, i):
        self.writer.putlnc('and_pd(%s, %s);', i.op1.get(), i.op2.get())

    def on_cvttsd2si(self, i):
        i.op1.size = 4
        i.op2.size = 8
        self.set_op(i.op1, 'sd_to_si(to_sd(%s))' % i.op2.get())

    def on_cvtsd2sd(self, i):
        # actually cvtss2sd, probably libdasm messing up
        i.op1.size = 8
        i.op2.size = 4
        self.set_op(i.op1, 'ss_to_sd(to_ss(%s))' % i.op2.get())

    def on_cvtsd2ss(self, i):
        i.op1.size = 4
        i.op2.size = 8
        self.set_op(i.op1, 'sd_to_ss(to_sd(%s))' % i.op2.get())

    def on_cvttss2si(self, i):
        i.op1.size = i.op2.size = 4
        self.set_op(i.op1, 'ss_to_si(to_ss(%s))' % i.op2.get())

    def on_cvtdq2pd(self, i):
        self.writer.putlnc('dq_to_pd(%s, %s);', i.op1.get(), i.op2.get())

    def on_cvtps2pd(self, i):
        self.writer.putlnc('ps_to_pd(%s, %s);', i.op1.get(), i.op2.get())

    def on_cvtpd2ps(self, i):
        self.writer.putlnc('pd_to_ps(%s, %s);', i.op1.get(), i.op2.get())

    def on_cvtdq2ps(self, i):
        self.writer.putlnc('dq_to_ps(%s, %s);', i.op1.get(), i.op2.get())

    def on_fst(self, i):
        if i.op1.reg_type == REG_FPU:
            return False
        st0 = get_register(REG_ST0, REG_FPU)
        self.set_op(i.op1, 'to_dword(float(%s))' % st0)

    def on_fistp(self, i):
        if i.fpuindex != 7:
            return False
        i.op1.size = 8
        self.set_op(i.op1, 'int64_t(%s)' % get_fpu())
        self.pop_float()

    def push_float(self, value):
        self.writer.putlnc('cpu.push_fpu(%s);', value)

    def pop_float(self):
        self.writer.putln('cpu.pop_fpu();')

    def on_fsubp(self, i):
        if not i.op2:
            return False
        self.set_op(i.op1, '%s - %s' % (i.op1.get(), i.op2.get()))
        self.pop_float()

    def on_fld1(self, i):
        self.push_float('1.0')

    def on_fldz(self, i):
        self.push_float('0.0')

    def on_fld(self, i):
        self.push_float(i.op1.get())

    def on_fldl(self, i):
        size_type = size_types[i.op1.size]
        self.push_float('to_ld(%s(%s))' % (size_type, i.op1.get()))

    def on_fild(self, i):
        if i.fpuindex != 7:
            return False
        self.push_float('si_to_ld(%s)' % (i.op1.get()))

    def on_flds(self, i):
        size_type = size_types[i.op1.size]
        self.push_float('to_ld(%s(%s))' % (size_type, i.op1.get()))

    def on_fstp(self, i):
        if i.op1.reg_type == REG_FPU:
            value = get_fpu()
        else:
            func = 'ld_to_%s' % size_names[i.op1.size]
            value = '%s(%s)' % (func, get_fpu())
        self.set_op(i.op1, value)
        self.pop_float()

    def on_fstpl(self, i):
        if i.op1.reg_type == REG_FPU:
            import code
            code.interact(local=locals())
        func = 'ld_to_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s)' % (func, get_fpu()))
        self.pop_float()

    def on_comiss(self, i):
        i.op1.size = i.op2.size = 4
        a = 'to_ss(%s)' % i.op1.get()
        b = 'to_ss(%s)' % i.op2.get()
        self.set_eflags(i, a=a, b=b, res=(None, i.op1.size))

    def on_comisd(self, i):
        i.op1.size = i.op2.size = 8
        a = 'to_sd(%s)' % i.op1.get()
        b = 'to_sd(%s)' % i.op2.get()
        self.set_eflags(i, a=a, b=b, res=(None, i.op1.size))

    def on_movapd(self, i):
        i.op1.size = i.op2.size = 16
        self.set_op(i.op1, i.op2.get())

    def on_movaps(self, i):
        i.op1.size = i.op2.size = 16
        self.set_op(i.op1, i.op2.get())

    def on_movlpd(self, i):
        i.op1.size = i.op2.size = 8
        self.set_op(i.op1, i.op2.get())

    def on_movq(self, i):
        i.op1.size = i.op2.size = 8
        self.set_op(i.op1, i.op2.get())

    def on_movss(self, i):
        i.op1.size = i.op2.size = 4
        self.set_op(i.op1, i.op2.get())

    def on_movsd_sse(self, i):
        i.op1.size = i.op2.size = 8
        self.set_op(i.op1, i.op2.get())

    def on_movsd(self, i):
        if i.opcode in (16, 17):
            return self.on_movsd_sse(i)
        mode = i.get_address_mode()
        if mode == MODE_32:
            reg_type = REG_GEN_DWORD
            size = 4
        else:
            reg_type = REG_GEN_WORD
            size = 2
        ds = get_register(REG_DS, REG_SEGMENT)
        esi = get_register(REG_ESI, reg_type)
        es = get_register(REG_DS, REG_SEGMENT)
        edi = get_register(REG_EDI, reg_type)
        self.set_memory('%s+%s' % (es, edi),
                        get_memory('%s+%s' % (ds, esi), size), size)
        df = '(int(!%s)*2-1)*%s' % (get_flag('DF'), size)
        self.set_register(esi, '%s + %s' % (esi, df))
        self.set_register(edi, '%s + %s' % (edi, df))

    def on_stosd(self, i):
        mode = i.get_address_mode()
        if mode == MODE_32:
            reg_type = REG_GEN_DWORD
            size = 4
        else:
            reg_type = REG_GEN_WORD
            size = 2
        eax = get_register(REG_EAX, reg_type)
        es = get_register(REG_ES, REG_SEGMENT)
        edi = get_register(REG_EDI, reg_type)
        self.set_memory('%s+%s' % (es, edi), eax, size)
        df = '(int(!%s)*2-1)*%s' % (get_flag('DF'), size)
        self.set_register(edi, '%s + %s' % (edi, df))

    def on_sbb(self, i):
        a = i.op1.get()
        b = i.op2.get()
        v = '%%s - %%s - int(%s)' % i.get_condition_value()
        ret = self.set_op_eflags(i, i.op1, v, a, b)
        if not ret:
            return
        res, a, b = ret
        self.set_eflags(i, a=a, b=b, res=(res, i.op1.size))

    def on_sub(self, i):
        a = i.op1.get()
        b = i.op2.get()
        ret = self.set_op_eflags(i, i.op1, '%s - %s', a, b)
        if not ret:
            return
        res, a, b = ret
        self.set_eflags(i, a=a, b=b, res=(res, i.op1.size))

    def on_adc(self, i):
        a = i.op1.get()
        b = i.op2.get()
        v = '%%s + %%s + int(%s)' % i.get_condition_value()
        ret = self.set_op_eflags(i, i.op1, v, a, b)
        if not ret:
            return
        res, a, b = ret
        self.set_eflags(i, a=a, b=b, res=(res, i.op1.size))

    def set_eflags(self, i, a=None, b=None, res=None):
        name = i.mnemonic
        dependees = i.get_dependees()
        res, size = res
        signed_type = signed_types[size]
        signed_res = '(%s)%s' % (signed_type, res)

        for instruction in dependees:
            create_bool = False
            if instruction.condition_value:
                cond_name = instruction.condition_value
            else:
                cond_name = 'cond_%s' % self.eflags_id.next()
                instruction.condition_value = cond_name
                create_bool = True
            c = instruction.get_condition()
            if c is None:
                print instruction.mnemonic
                raise NotImplementedError()
            if c in ('nz', 'ne') and name == 'cmp':
                value = '%s != %s' % (a, b)
            elif c in ('nz', 'ne'):
                value = '%s != 0' % res
            elif c in ('z', 'e') and name == 'cmp':
                value = '%s == %s' % (a, b)
            elif c in ('z', 'e'):
                value = '%s == 0' % res
            elif c == 's':
                value = '%s < 0' % signed_res
            elif c == 'ns':
                value = '%s >= 0' % signed_res
            elif c in ('g', 'nle') and name in ('and', 'or', 'xor', 'test'):
                value = '%s > 0' % signed_res
            elif c in ('g', 'nle') and name == 'cmp':
                value = '(%s)%s > (%s)%s' % (signed_type, a, signed_type, b)
            elif c == 'l' and name in ('and', 'or', 'xor', 'test'):
                value = '%s < 0' % signed_res
            elif c in ('ng', 'le') and name == 'inc':
                value = '%s <= -1' % signed_res
            elif c in ('ng', 'le') and name == 'dec':
                value = '%s <= 1' % signed_res
            elif c in ('ng', 'le') and name in ('and', 'or', 'xor', 'test'):
                value = '%s <= 0' % signed_res
            elif c in ('ng', 'le') and name == 'cmp':
                value = '(%s)%s <= (%s)%s' % (signed_type, a, signed_type, b)
            elif c in ('ge', 'nl') and name in ('and', 'or', 'xor', 'test'):
                value = '%s >= 0' % signed_res
            elif c in ('ge', 'nl') and name == 'cmp':
                value = '(%s)%s >= (%s)%s' % (signed_type, a, signed_type, b)
            elif c in ('c', 'b') and name == 'xor':
                value = 'false'
            elif c in ('c', 'b') and name == 'shr':
                value = '(%s >> (%s - 1)) & 1' % (a, b)
            elif c in ('c', 'b') and name == 'add':
                value = '%s < %s' % (res, a)
            elif c in ('c', 'b') and name in ('neg', 'sub', 'cmp', 'comiss',
                                              'comisd'):
                value = '%s < %s' % (a, b)
            elif c in ('c', 'b') and name == 'adc':
                value = '%s ? %s <= %s : %s < %s' % (i.get_condition_value(),
                                                     res, a, res, a)
            elif c in ('c', 'b') and name == 'sbb':
                value = '%s ? %s <= %s : %s < %s' % (i.get_condition_value(),
                                                     a, b, a, b)
            elif c in ('nc', 'ae') and name == 'add':
                value = '%s >= %s' % (res, a)
            elif c in ('nc', 'ae') and name in ('neg', 'sub', 'cmp', 'comiss',
                                                'comisd'):
                value = '%s >= %s' % (a, b)
            elif c in ('nc', 'ae') and name in ('and', 'or', 'xor', 'test'):
                value = 'true'
            elif c == 'o' and name == 'mul':
                value = '%s != 0' % res
            elif c in ('na', 'be') and name in ('neg', 'sub'):
                value = '%s == 0 || %s < %s' % (res, a, b)
            elif c in ('na', 'be') and name in ('cmp', 'comiss', 'comisd'):
                value = '%s <= %s' % (a, b)
            elif c in ('a', 'nbe') and name in ('neg', 'sub'):
                value = '%s != 0 && %s >= %s' % (res, a, b)
            elif c in ('a', 'nbe') and name in ('cmp', 'comiss', 'comisd'):
                value = '%s > %s' % (a, b)
            elif c == 'l' and name == 'cmp':
                value = '(%s)%s < (%s)%s' % (signed_type, a, signed_type, b)
            elif c == 'nl' and name == 'cmp':
                value = '(%s)%s >= (%s)%s' % (signed_type, a, signed_type, b)
            else:
                print name, c
                raise NotImplementedError()
            if create_bool:
                self.writer.putlnc('bool %s;', cond_name)
            self.writer.putlnc('%s = %s;', cond_name, value)

    def on_dec(self, i):
        res = self.set_op_eflags(i, i.op1, '%s - 1' % i.op1.get())
        if not res:
            return
        self.set_eflags(i, res=(res, i.op1.size))

    def on_inc(self, i):
        res = self.set_op_eflags(i, i.op1, '%s + 1' % i.op1.get())
        if not res:
            return
        self.set_eflags(i, res=(res, i.op1.size))

    def on_and(self, i):
        res = self.set_op_eflags(i, i.op1,
                                 '%s & %s' % (i.op1.get(), i.op2.get()))
        if not res:
            return
        self.set_eflags(i, res=(res, i.op1.size))

    def on_or(self, i):
        res = self.set_op_eflags(i, i.op1,
                                 '%s | %s' % (i.op1.get(), i.op2.get()))
        if not res:
            return
        self.set_eflags(i, res=(res, i.op1.size))

    def on_xor(self, i):
        res = self.set_op_eflags(i, i.op1,
                                 '%s ^ %s' % (i.op1.get(), i.op2.get()))
        if not res:
            return
        self.set_eflags(i, res=(res, i.op1.size))

    def on_not(self, i):
        # eflags not affected
        size_type = size_types[i.op1.size]
        self.set_op(i.op1, '%s(~%s)' % (size_type, i.op1.get()))

    def on_xorps(self, i):
        # eflags not affected
        self.set_op(i.op1, '%s ^ %s' % (i.op1.get(), i.op2.get()))
 
    def on_lea(self, i):
        if i.get_operand_mode() != MODE_32 or i.get_address_mode() != MODE_32:
            import code
            code.interact(local=locals())
        self.set_op(i.op1, i.op2.value)

    def call_memory(self, op):
        try:
            addr = eval(op.value)
        except NameError:
            self.call_dynamic(op.get())
            return

        value = self.converter.get_memory(addr, 4)
        value, = struct.unpack('<I', value)

        can_deref = False

        try:
            self.converter.get_memory(value, 0)
            can_deref = True
        except NotImplementedError:
            can_deref = False

        if not can_deref:
            if addr in self.converter.imports:
                value = addr
            else:
                self.call_dynamic(op.get())
                return

        self.converter.add_function(value)

        v = '%s();' % self.get_function_name(value)
        self.writer.putln(v)

    def on_call(self, i):
        test_ebp = False
        # if self.eip in (0x54ABD5, 0x54AC12):
        #     test_ebp = False

        op = i.op1

        esp = get_register(REG_ESP, REG_GEN_DWORD)
        ebp = get_register(REG_EBP, REG_GEN_DWORD)

        if test_ebp:
            test_name = 'test_ebp_%s' % self.eip
            self.writer.putln('uint32_t %s = %s;' % (test_name, ebp))

        self.set_register(esp, '%s-4' % esp)

        if op.is_register:
            self.call_dynamic(op.get())
        elif op.is_immediate:
            self.converter.add_function(op.value)
            self.writer.putln('%s();' % self.get_function_name(op.value))
            if op.value == 0x412FE0:
                # startthread(), lets stop here
                # print 'Found startthread'
                self.unimplemented = False
                return False
        else:
            self.call_memory(op)

        if test_ebp:
            self.writer.putln('if (%s != %s) {' % (ebp, test_name))
            self.writer.indent()
            self.log('EBP not preserved at %X' % self.eip)
            self.writer.end_brace()

    def on_xchg(self, i):
        self.writer.start_brace()
        size = size_types[i.op1.size]
        self.writer.putln('%s swap_value = %s;' % (size, i.op1.get()))
        self.set_op(i.op1, i.op2.get())
        self.set_op(i.op2, 'swap_value')
        self.writer.end_brace()

    def on_cbw(self, i):
        if i.get_operand_mode() != MODE_32:
            ax = get_register(REG_AX, REG_GEN_WORD)
            al = get_register(REG_AL, REG_GEN_BYTE)
            self.set_register(ax, '(uint16_t)int16_t(int8_t(%s))' % al)
            return
        eax = get_register(REG_EAX, REG_GEN_DWORD)
        ax = get_register(REG_AX, REG_GEN_WORD)
        self.set_register(eax, 'uint32_t(int32_t(int16_t(%s)))' % ax)

    def on_setcc(self, i):
        self.set_op(i.op1, 'int(%s)' % i.get_condition_value())

    on_setnz = on_setcc
    on_sets = on_setcc
    on_setl = on_setcc
    on_setnle = on_setcc
    on_setnbe = on_setcc
    on_setbe = on_setcc
    on_seto = on_setcc
    on_setns = on_setcc
    on_setz = on_setcc

    def on_movzx(self, i):
        src = i.op2
        if src.is_memory and src.displacement:
            # test for jumptable in text segment
            # let on_jmp handle this
            try:
                displacement = eval(src.displacement)
                section = self.converter.get_section(displacement)
                if section.section_name == 'text':
                    self.writer.putln('// movzx ignored here')
                    return
            except (NotImplementedError, NameError):
                pass
        self.set_register(i.op1.value, i.op2.get())

    def on_cmovcc(self, i):
        self.writer.putlnc('if (%s)', i.get_condition_value())
        self.writer.indent()
        self.set_op(i.op1, i.op2.get())
        self.writer.dedent()

    on_cmovae = on_cmovcc
    on_cmova = on_cmovcc
    on_cmovbe = on_cmovcc
    on_cmovb = on_cmovcc
    on_cmovg = on_cmovcc
    on_cmovge = on_cmovcc
    on_cmovl = on_cmovcc
    on_cmovle = on_cmovcc
    on_cmove = on_cmovcc
    on_cmovne = on_cmovcc
    on_cmovs = on_cmovcc

    def on_int3(self, i):
        pass
        # self.log('int3 at %s' % self.eip)

    def on_nop(self, i):
        pass

    def on_fstcw(self, i):
        self.log('fstcw nop')

    def on_jmp(self, i):
        op = i.op1

        if op.is_register:
            self.call_dynamic(op.get())
            self.writer.putln('return;')
            return

        if (i.opcode in (0xEB, 0xE9) and op.value >= self.sub.start
                and op.value < self.sub.end):
            # jump short
            self.writer.putln('goto %s;' % get_label_name(op.value))
            return

        if op.is_immediate:
            self.converter.add_function(op.value)
            self.writer.putln('%s();' % self.get_function_name(op.value))
            self.writer.putln('return;')
        else:
            # detect jumptable
            reg = op.index_reg

            if op.scale:
                comp = self.find_instruction('cmp', -4)
                indirect = self.find_instruction('movzx', -2)
                if comp is None:
                    print i.get_disasm()
                    raise NotImplementedError()
                table_size = comp.op2.value+1
                if indirect:
                    if indirect.op1.value != reg:
                        raise NotImplementedError()
                    ind_op = indirect.op2
                    ind_addr = eval(ind_op.displacement)
                    ind_reg = op.index_reg
                    if ind_op.size != 1:
                        raise NotImplementedError()
                    indexes = collections.defaultdict(list)
                    # find the max value
                    for ii in xrange(table_size):
                        data = self.converter.get_memory(ind_addr + ii, 1)
                        index, = struct.unpack('<B', data)
                        indexes[index].append(ii)

                    self.writer.putln('switch (%s) {' % ind_reg)
                    self.writer.indent()
                    for to_index, from_list in indexes.iteritems():
                        for table_index in from_list:
                            self.writer.putln('case %s:' % table_index)
                        self.writer.indent()
                        self.set_register(reg, '%s' % to_index)
                        self.writer.putln('break;')
                        self.writer.dedent()
                    self.writer.end_brace()
                    table_size = max(indexes)+1
                table_addr = eval(op.displacement)
                scale = op.scale

                self.writer.putln('switch (%s) {' % reg)
                self.writer.indent()
                for ii in xrange(table_size):
                    data = self.converter.get_memory(table_addr + ii*scale, 4)
                    addr, = struct.unpack('<I', data)
                    if addr > self.sub.end or addr < self.sub.start:
                        raise NotImplementedError()
                    loc = get_label_name(addr)
                    self.writer.putln('case %s: goto %s;' % (ii, loc))
                    self.sub.add_jump(i.address, addr)
                    self.remaining_labels.add(addr)
                self.writer.end_brace()
                return
            self.call_memory(op)
            self.writer.putln('return;')

    def on_jcc(self, i):
        self.goto(i.get_condition_value(), i.op1.value)

    on_jz = on_jcc
    on_jc = on_jcc
    on_js = on_jcc
    on_jns = on_jcc
    on_jnl = on_jcc
    on_jl = on_jcc
    on_jng = on_jcc
    on_jnc = on_jcc
    on_ja = on_jcc
    on_jg = on_jcc
    on_jna = on_jcc
    on_jnz = on_jcc

    def on_shl(self, i):
        if i.eflags_dependency:
            raise NotImplementedError()
        self.set_op(i.op1, '%s << %s' % (i.op1.get(), i.op2.get()))

    def on_shld(self, i):
        if i.eflags_dependency:
            raise NotImplementedError()
        func = 'cpu.shld_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s, %s)' % (func, i.op1.get(),
                                               i.op2.get(), i.op3.get()))

    def on_shr(self, i):
        a = i.op1.get()
        b = i.op2.get()
        ret = self.set_op_eflags(i, i.op1, '%s >> %s', a, b)
        if not ret:
            return
        res, a, b = ret
        self.set_eflags(i, a=a, b=b, res=(res, i.op1.size))

    def on_rcr(self, i):
        if i.eflags_dependency:
            raise NotImplementedError()
        func = 'cpu.rcr_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s, %s)' % (func, i.op1.get(), i.op2.get(),
                                               i.get_condition_value()))

    def on_rol(self, i):
        if i.eflags_dependency:
            raise NotImplementedError()
        func = 'cpu.rol_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_sar(self, i):
        if i.eflags_dependency:
            raise NotImplementedError()
        signed_type = signed_types[i.op1.size]
        op1 = i.op1.get()
        op2 = i.op2.get()
        self.set_op(i.op1, '((%s)%s) >> %s' % (signed_type, op1, op2))

    def on_add(self, i):
        a = i.op1.get()
        b = i.op2.get()
        ret = self.set_op_eflags(i, i.op1, '%s + %s', a, b)
        if not ret:
            return
        res, a, b = ret
        self.set_eflags(i, a=a, b=b, res=(res, i.op1.size))

    def on_xadd(self, i):
        if i.eflags_dependency:
            raise NotImplementedError()
        func = 'cpu.xadd_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_neg(self, i):
        signed_type = signed_types[i.op1.size]
        b = i.op1.get()
        ret = self.set_op_eflags(i, i.op1,
                                 '-(%s)(%%s)' % (signed_type), b)
        if not ret:
            return
        res, b = ret
        self.set_eflags(i, a=0, b=b, res=(res, i.op1.size))

    def on_test(self, i):
        op1 = i.op1.get()
        op2 = i.op2.get()
        if op1 == op2:
            res = op1
        else:
            res = '(%s & %s)' % (i.op1.get(), i.op2.get())
        self.set_eflags(i, res=(res, i.op1.size))

    def on_cwd(self, i):
        if i.get_operand_mode() != MODE_32:
            import code
            code.interact(local=locals())
        eax = get_register(REG_EAX, REG_GEN_DWORD)
        edx = get_register(REG_EDX, REG_GEN_DWORD)
        self.set_register(edx, 'cdq_x86(%s)' % eax)

    def on_div(self, i):
        if i.op2 or i.op3:
            return False
        func = 'cpu.div_%s' % size_names[i.op1.size]
        self.writer.putlnc('%s(%s);', func, i.op1.get())

    def on_idiv(self, i):
        if i.op2 or i.op3:
            return False
        func = 'cpu.idiv_%s' % size_names[i.op1.size]
        self.writer.putlnc('%s(%s);', func, i.op1.get())

    def on_imul(self, i):
        if i.eflags_dependency:
            raise NotImplementedError()
        if i.op3:
            func = 'cpu.imul_%s' % size_names[i.op1.size]
            call = '%s(%s, %s)' % (func, i.op2.get(), i.op3.get())
            self.set_op(i.op1, call)
        elif i.op2:
            func = 'cpu.imul_%s' % size_names[i.op1.size]
            call = '%s(%s, %s)' % (func, i.op1.get(), i.op2.get())
            self.set_op(i.op1, call)
        else:
            func = 'cpu.imul_%s' % size_names[i.op1.size]
            self.writer.putlnc('%s(%s);', func, i.op1.get())

    def on_mul(self, i):
        func = 'cpu.mul_%s' % size_names[i.op1.size]
        self.writer.putlnc('%s(%s);', func, i.op1.get())
        if not i.eflags_dependency:
            return
        eax = get_register(REG_EAX, REG_GEN_DWORD)
        edx = get_register(REG_EDX, REG_GEN_DWORD)
        self.set_eflags(i, a=eax, res=(edx, i.op1.size))

    def on_retn(self, i):
        value = i.op1.value
        reg = get_register(REG_ESP, REG_GEN_DWORD)
        self.set_register(reg, '%s+%s' % (reg, value+4))
        self.writer.putln('return;')

    def on_ret(self, i):
        reg = get_register(REG_ESP, REG_GEN_DWORD)
        self.set_register(reg, '%s+4' % reg)
        self.writer.putln('return;')

    def on_leave(self, i):
        esp = get_register(REG_ESP, REG_GEN_DWORD)
        ebp = get_register(REG_EBP, REG_GEN_DWORD)
        self.set_register(esp, ebp)
        self.set_register(ebp, 'cpu.pop_dword();')

    def on_cmp(self, i):
        a = i.op1.get()
        b = i.op2.get()
        self.set_eflags(i, a=a, b=b, res=(None, i.op1.size))

import struct

class DWORD(object):
    def __init__(self, value):
        self.data = struct.pack('<I', value)

import_filter = '@?$'
import_mappings = {}

def filter_import_name(name):
    try:
        return import_mappings[name]
    except KeyError:
        pass
    v = name
    for c in import_filter:
        v = v.replace(c, '')
    if v[0] in '0123456789':
        v = '_' + v
    import_mappings[name] = v
    return v


def makedirs(path):
    try:
        os.makedirs(path)
    except OSError:
        return


class Section(object):
    def __init__(self, pe, pe_section):
        self.VirtualAddress = pe_section.VirtualAddress
        self.SizeOfRawData = pe_section.SizeOfRawData
        self.Misc_VirtualSize = pe_section.Misc_VirtualSize
        self.PointerToRawData = pe_section.PointerToRawData
        self.Name = pe_section.Name
        self.data_adj = pe.adjust_FileAlignment(
            pe_section.PointerToRawData, pe.OPTIONAL_HEADER.FileAlignment)
        self.virtual_adj = pe.adjust_SectionAlignment(
            pe_section.VirtualAddress,
            pe.OPTIONAL_HEADER.SectionAlignment,
            pe.OPTIONAL_HEADER.FileAlignment)
        self.data = pe.__data__

    def get_data(self, start=None, length=None):
        if start is None:
            offset = self.data_adj
        else:
            offset = (start - self.virtual_adj) + self.data_adj

        if length is not None:
            end = offset + length
        else:
            end = offset + self.SizeOfRawData

        # PointerToRawData is not adjusted here as we might want to read any
        # possible extra bytes that might get cut off by aligning the start
        # (and hence cutting something off the end)
        if end > self.PointerToRawData + self.SizeOfRawData:
            end = self.PointerToRawData + self.SizeOfRawData
        return self.data[offset:end]


class Converter(object):
    def __init__(self, path):
        # setup
        self.base_dir = os.path.dirname(__file__)
        self.gen_dir = os.path.join(self.base_dir, 'gensrc')

        self.custom_code = ''
        import_dir = os.path.join(self.base_dir, 'src', 'import')
        for f in os.listdir(import_dir):
            code_path = os.path.join(import_dir, f)
            self.custom_code += open(code_path, 'rb').read()

        self.mem_writes = {}
        self.sections = []
        self.imports = {}
        self.used_imports = set()
        self.custom_subs = set()
        self.cached_names = {}
        self.subs = set()
        self.cpu = CPU(self)
        self.load_sections = []
        self.load_images = []
        self.sources = []
        self.big_sources = set()
        pe = pefile.PE(path)

        optional = pe.OPTIONAL_HEADER

        self.image_base = optional.ImageBase
        self.code_base = optional.ImageBase + optional.BaseOfCode
        self.data_base = optional.ImageBase + optional.BaseOfData
        self.entry_point = optional.ImageBase + optional.AddressOfEntryPoint

        print "Image base: %X" % self.image_base

        makedirs(self.gen_dir)
        writer = self.open_code('out.cpp')
        writer.putln('#include "main.h"')
        writer.putln('#include "memory.h"')
        writer.putln('#include "functions.h"')

        for index, section in enumerate(pe.sections):
            section = Section(pe, section)
            self.sections.append(section)
            section.image_base = self.image_base
            name = section.Name.strip('\x00')[1:]
            section.section_name = name
            if name in ('rsrc', 'text', 'reloc'):
                continue
            self.load_sections.append(section)

        self.import_addresses = {}
        for entry in pe.DIRECTORY_ENTRY_IMPORT:
            for imp in entry.imports:
                self.imports[imp.address] = (imp, entry)

        for section in self.load_sections:
            name = section.section_name
            writer.putln('#include "%s_section.h"' % name)

        writer.putln('')

        # writer.putmeth('void init_emu')

        sections_header = self.open_code('sections.h')
        sections_header.start_guard('TERRAINGEN_SECTIONS_H')

        for section in self.load_sections:
            name = section.section_name
            section_base = section.image_base + section.VirtualAddress
            data = section.get_data()
            extra = section.Misc_VirtualSize - len(data)
            data += '\x00' * extra
            name = '%s_section' % name
            self.write_data_header(data, name, '%s.h' % name)
            sections_header.putlnc('extern char %s[%s];', name, len(data))

        sections_header.close_guard('TERRAINGEN_SECTIONS_H')
        sections_header.close()

        # ensure custom sqlite3 is used
        sqlite_table = config.sqlite_table
        for _ in xrange(712 / 4):
            value = self.get_dword(sqlite_table)
            if value != 0:
                func = self.get_function_name(value)
                # XXX hack
                self.custom_code += func
                # print '%s -> %X' % (func, self.get_ida_address(sqlite_table))
            sqlite_table += 4

        # get current dynamic addresses
        self.dynamic_addresses = config.dynamic_addresses

        # write functions, starting from entry point
        # start at main()
        self.entry_point = config.entry_point
        self.function_stack = [self.entry_point]
        for address in self.dynamic_addresses:
            if (address in self.imports and
                address not in self.import_addresses.values()):
                self.used_imports.add(address)
            else:
                self.function_stack.insert(0, address)

        # add initterm initializers to function stack
        writer.putmeth('void init_static')
        for addr in xrange(config.static_start, config.static_end, 4):
            value = self.get_dword(addr)
            if value in config.static_ignore:
                continue
            self.add_function(value)
            writer.putln('add_ret();')
            writer.putlnc('%s();', self.get_function_name(value))
        writer.end_brace()

        # get reloc ready
        self.reloc_addresses = set()
        self.reloc_values = set()

        writer.putmeth('void rebase_data')
        # iterate reloc section
        for data in pe.DIRECTORY_ENTRY_BASERELOC:
            for entry in data.entries:
                t = entry.type
                if t == 0:
                    continue
                if t != 3:
                    print 'has unsupported reloctype', t
                    continue
                addr = entry.rva + self.image_base
                dword = self.get_dword(addr)
                is_text = False
                if self.get_section(addr).section_name == 'text':
                    is_text = True
                if dword in (self.image_base, 
                             self.image_base+0x3c,
                             self.image_base+0x18,
                             self.image_base+0x74,
                             self.image_base+0xe8): 
                    # dos headers
                    continue
                if self.get_section(dword).section_name == 'text':
                    continue
                self.reloc_values.add(dword)
                self.reloc_addresses.add(addr)
                if is_text:
                    continue
                src = self.get_reloc(dword, True)
                dst = self.get_reloc(addr, False)
                writer.putlnc('mem.write_dword(%s, %s);', dst, src)
        writer.end_brace()

        del pe # garbage collect

        # iterate function stack

        while self.function_stack:
            address = self.function_stack.pop()
            ida = self.get_ida_address(address)
            subs = self.get_subs(address)
            self.subs.add(subs[0].start)
            for sub in subs:
                self.iterate_tree(sub)

        addresses = set()
        addresses.update(self.subs)
        addresses.update(self.used_imports)
        addresses.update(self.custom_subs)

        writer.putmeth('void init_function_map')
        for address in addresses:
            name = self.get_function_name(address)
            writer.putln('cpu.add_function(0x%X, %s);' % (address, name))
        writer.end_brace()

        writer.close()

        writer = self.open_code('functions.h')
        writer.start_guard('TERRAINGEN_FUNCTIONS_H')
        for address in addresses:
            name = self.get_function_name(address)
            writer.putln('extern void %s();' % name)
        writer.close_guard('TERRAINGEN_FUNCTIONS_H')
        writer.close()

        writer = self.open_code('stubs.cpp')
        writer.putln('#include <iostream>')
        writer.putln('')
        stubs = self.used_imports
        stubs -= set(self.import_addresses.values())
        stubs -= self.subs
        stub_names = set()
        for imp in stubs:
            name = self.get_function_name(imp)
            if self.is_custom(name) or name in stub_names:
                continue
            stub_names.add(name)
            writer.putmeth('void %s' % name)
            import_name = self.get_import_name(imp)
            writer.putln('std::cout << "Stub: %s" << std::endl;' % import_name)
            writer.end_brace()
            writer.putln('')
        writer.close()

        writer = self.open_code('Routines.cmake', license=False)
        writer.putln('set(GEN_SRCS')
        writer.indent()
        for f in self.sources:
            name = os.path.basename(f)
            name = '${GEN_DIR}/%s' % name
            writer.putln(name)
        writer.dedent()
        writer.putln(')')
        writer.putln('')

        writer.putln('set(GEN_BIG_SRCS')
        writer.indent()
        for f in self.big_sources:
            name = os.path.basename(f)
            name = '${GEN_DIR}/%s' % name
            writer.putln(name)
        writer.dedent()
        writer.putln(')')
        writer.close()

        print 'Instruction stats:', self.cpu.mnemonic_stats.most_common(10)

    def write_data_header(self, data, name, filename):
        if os.path.isfile(self.get_path(filename)):
            print 'Not writing data header for', filename
            return
        section_writer = self.open_code(filename)
        section_writer.putlnc('char %s[%s] = {', name, len(data))
        section_writer.indent()

        i = 0
        data_len = len(data)
        while i < data_len:
            items = []
            for ii in xrange(i, min(i+10, len(data))):
                v = struct.unpack('b', data[ii])[0]
                if v < 0:
                    v = '-0x%02X,' % -v
                else:
                    v = ' 0x%02X,' % v
                items.append(v)
            items = ' '.join(items)
            i += 10
            if i >= data_len:
                items = items[:-1]
            section_writer.putln(items)

        section_writer.end_brace(True)
        section_writer.putln('')
        section_writer.close()

    def get_reloc(self, addr, as_guest=True):
        section = self.get_section(addr)
        if section.section_name == 'text':
            raise NotImplementedError()
        data_name = '%s_section' % section.section_name
        offset = addr - (section.image_base + section.VirtualAddress)
        ret = '%s+%s' % (data_name, offset)
        if as_guest:
            ret = 'mem.translate(%s)' % ret
        return ret

    def is_custom(self, name):
        data = self.custom_code.replace('%s();' % name, '')
        return name in data

    def get_ida_address(self, address):
        ida_image_base = 0x200000
        ida_address = address - self.image_base + ida_image_base
        return ida_address

    def add_function(self, address):
        if address in self.subs or address in self.function_stack:
            return
        if (address in self.imports and
            address not in self.import_addresses.values() and
            address not in self.dynamic_addresses):
            return
        if address in self.custom_subs:
            return
        name = self.get_function_name(address)
        if self.is_custom(name):
            self.custom_subs.add(address)
            return
        self.function_stack.append(address)

    def get_import_name(self, address):
        try:
            imp = self.imports[address]
        except KeyError:
            return None
        imp, entry = imp
        key = imp.name
        if imp.name is None:
            name = entry.dll.split('.')[0].lower()
            key = (name, imp.ordinal)
            default = '%s_%s' % key
        else:
            default = key
        return import_alias.get(key, default)

    def get_function_name(self, address):
        try:
            self.cached_names[address]
        except KeyError:
            pass
        imp = self.get_import_name(address)
        if imp is not None:
            self.used_imports.add(address)
            return filter_import_name(imp) + '_imp'
        elif address == self.entry_point:
            func_name = 'entry_point'
        else:
            func_name = function_alias.get(address, 'sub_%X' % address)
        self.cached_names[address] = func_name
        return func_name

    def get_subs(self, address):
        """
        Since some routines can get massive, we need to split some of them
        so MSVC/GCC won't choke on them.
        """
        sub = Subroutine(self, address)
        size = len(sub.instruction_list)
        # init func is 51048
        if size <= 50000 or not sub.can_split_direct():
            return [sub]

        name = self.get_function_name(sub.start)
        start_sub = sub
        subs = [start_sub]
        split_dist = 4000
        jumps = start_sub.jumps

        next_offset = split_dist

        split_points = sorted(sub.instructions.keys())
        for pos in split_points:
            offset = pos - start_sub.start
            if offset < next_offset:
                continue
            if not sub.can_split(pos):
                continue
            sub = sub.split(pos)
            subs.append(sub)
            next_offset += split_dist

        for index, sub in enumerate(subs):
            sub.name = '%s_%s' % (name, index+1)

        # generate wrapper code
        source_name = '%s.cpp' % name
        self.sources.append(source_name)
        writer = self.open_code(source_name)
        for sub in subs:
            writer.putln('extern void %s();' % sub.name)
        writer.putln('')
        writer.putmeth('void %s' % name)
        for sub in subs:
            writer.putln('%s();' % sub.name)
        writer.end_brace()
        writer.close()
        return subs

    def iterate_tree(self, sub):
        if sub.name:
            name = sub.name
        else:
            name = self.get_function_name(sub.start)
        source_name = '%s.cpp' % name
        self.sources.append(source_name)
        writer = self.writer = self.open_code(source_name)
        writer.putln('#include "main.h"')
        writer.putln('#include "functions.h"')
        writer.putln('#include "sections.h"')
        writer.putln('#include <iostream>')
        writer.putln('')
        self.cpu.set_sub(sub)

        writer.putmeth('void %s' % name)
        while True:
            if not self.cpu.next():
                break
        if sub.child_sub:
            writer.putln('return;')
        for label in self.cpu.remaining_labels:
            writer.put_label(get_label_name(label))
        if self.cpu.unimplemented:
            self.log('Not implemented, stack may be corrupted (%X)' % (
                sub.start))
        writer.end_brace()
        writer.close()

    def get_section(self, address):
        for section in self.sections:
            section_base = section.image_base + section.VirtualAddress
            section_end = section_base + section.Misc_VirtualSize 
            if address < section_base or address >= section_end:
                continue
            return section
        raise NotImplementedError()

    def get_memory(self, address, size):
        try:
            return self.mem_writes[(address, size)].data
        except KeyError:
            pass
        section = self.get_section(address)
        if section is None:
            raise NotImplementedError()
        address -= section.image_base
        return section.get_data(address, size)

    def get_dword(self, addr):
        value = self.get_memory(addr, 4)
        value, = struct.unpack('<I', value)
        return value

    def log(self, value):
        self.writer.putlnc('std::cout << %r << std::endl;', value)

    def get_path(self, filename):
        return os.path.join(self.gen_dir, filename)

    def open_code(self, filename, *arg, **kw):
        return CodeWriter(self.get_path(filename), *arg, **kw)

    def get_sources(self):
        srcs = [self.get_path(src) for src in self.sources]
        srcs += [self.get_path('stubs.cpp')]
        srcs += [os.path.join(self.base_dir, 'src', item) for item in
                 ('run.cpp', 'memory.cpp', 'cpu.cpp', 'sqlite3.c')]
        return srcs

    def get_includes(self, msvc=False):
        includes = [self.base_dir,
                    os.path.join(self.base_dir, 'include'),
                    os.path.join(self.base_dir, 'src')]
        if msvc:
            includes += [os.path.join(self.base_dir, 'include', 'win32')]
        return includes


SERVER_HASH = 'A6FC5AA34068B5B80C53B2439C65BE3B'


def convert(filename):
    import hashlib

    file_hash = hashlib.md5(open(filename, 'rb').read()).hexdigest()
    if file_hash != SERVER_HASH.lower():
        print 'Invalid Server.exe hash, should be %s' % SERVER_HASH
        return

    converter = Converter(filename)
    return converter

def main():
    import argparse

    parser = argparse.ArgumentParser(
        description='Translates Server.exe into a terrain generator')
    parser.add_argument('file', help='path to Server.exe')
    args = parser.parse_args()

    convert(args.file)

if __name__ == '__main__':
    main()