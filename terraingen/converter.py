# Copyright (c) Mathias Kaerlev 2013.
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
import os
import math
from alias import function_alias, import_alias, function_enders
from ctypes import c_int32

LICENSE_TEXT = '''\
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

    def __init__(self, filename=None):
        self.fp = StringIO()
        self.filename = filename
        self.putln(LICENSE_TEXT)
    
    def format_line(self, line):
        return self.get_spaces() + line
    
    def putln(self, *lines, **kw):
        wrap = kw.get('wrap', False)
        indent = kw.get('indent', True)
        if wrap:
            indent = self.get_spaces(1)
        for line in lines:
            if wrap:
                line = ('\n' + indent).join(textwrap.wrap(line))
            if indent:
                line = self.format_line(line)
            if self.comment:
                line = '%s // %s' % (line, self.comment)
            self.fp.write(line + '\n')

    def putlnc(self, line, *arg):
        line = to_c(line, *arg)
        self.putln(line)

    def putraw(self, *arg, **kw):
        indentation = self.indentation
        self.indentation = 0
        self.putln(*arg, **kw)
        self.indentation = indentation

    def putdefine(self, name, value):
        if value is None:
            return
        if isinstance(value, str):
            value = '"%s"' % value
        self.putln('#define %s %s' % (name, value))
    
    def putindent(self, extra = 0):
        self.fp.write(self.get_spaces(extra))
    
    def put(self, value, indent = False):
        if indent:
            self.putindent()
        self.fp.write(value)
    
    def get_data(self):
        fp = self.fp
        pos = fp.tell()
        fp.seek(0)
        data = fp.read()
        fp.seek(pos)
        return data

    def putcode(self, writer):
        data = writer.get_data().splitlines()
        for line in data:
            self.putln(line)
    
    def putclass(self, name, subclass = None):
        text = 'class %s' % name
        if subclass is not None:
            text += ' : public %s' % subclass
        self.putln(text)
        self.start_brace()

    def start_brace(self):
        self.putln('{')
        self.indent()

    def end_brace(self, semicolon = False):
        self.dedent()
        text = '}'
        if semicolon:
            text += ';'
        self.putln(text)
    
    def putdef(self, name, value, wrap = False):
        new_value = '%r' % (value,)
        self.putln('%s = %s' % (name, new_value), wrap = wrap)

    def putmeth(self, name, *arg, **kw):
        fullarg = list(arg)
        self.putln('%s(%s)' % (name, ', '.join(fullarg)))
        self.start_brace()

    def put_label(self, name):
        self.putln('%s: ;' % name)

    def put_access(self, name):
        self.dedent()
        self.putln('%s:' % name)
        self.indent()

    def start_guard(self, name):
        self.putln('#ifndef %s' % name)
        self.putln('#define %s' % name)
        self.putln('')

    def close_guard(self, name):
        self.putln('')
        self.putln('#endif # %s' % name)
    
    def putend(self):
        self.putln('pass')
        self.dedent()
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
        # try:
        #     fp = open(self.filename, 'rb')
        #     original_data = fp.read()
        #     fp.close()
        #     if original_data == data:
        #         return
        # except IOError:
        #     pass
        fp = open(self.filename, 'wb')
        fp.write(data)
        fp.close()

    def get_line_count(self):
        return self.get_data().count('\n')

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
    REG_GEN_WORD: '*cpu.reg16[%s]',
    REG_GEN_BYTE: '*cpu.reg8[%s]',
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
    is_memory = False
    is_register = False
    is_immediate = False
    has_import_alias = False

    index_reg = None
    scale = None
    base_reg = None
    displacement = None

    def __init__(self, inst, op, offset):
        self.op = op
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
                if op.displacement & (1<<(op.dispbytes*8-1)):
                    tmp = op.displacement
                    if op.dispbytes == 1:
                        tmp = ~tmp & 0xff
                    elif op.dispbytes == 2:
                        tmp = ~tmp & 0xffff
                    elif op.dispbytes == 4:
                        tmp = ~tmp & 0xffffffff
                    self.displacement = '(-0x%x)' % (tmp + 1)
                # Positive displacement
                else:
                    self.displacement = '0x%x' % op.displacement
                sum_list.append(self.displacement)

            # check for import alias
            if len(sum_list) == 1 and inst.dispbytes:
                addr = op.displacement
                if (addr in inst.converter.imports
                    and addr not in inst.converter.import_addresses.values()):
                    self.is_memory = False
                    self.is_immediate = True
                    self.value = self.get_import_alias(addr, inst)
                    return

            self.value = '+'.join(sum_list)

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

    def get(self):
        if self.is_memory:
            return get_memory(self.value, self.size)
        return self.value

def get_memory(addr, size):
    func = 'mem.read_%s' % size_names[size]
    return '%s(%s)' % (func, addr)

class Instruction(object):
    def __init__(self, instruction, offset, converter):
        self.instruction = instruction
        self.converter = converter
        self.address = offset

        self.length = instruction.length
        self.type = instruction.type
        self.mode = instruction.mode
        self.opcode = instruction.opcode
        self.modrm = instruction.modrm
        self.sib = instruction.sib
        self.extindex = instruction.extindex
        self.fpuindex = instruction.fpuindex
        self.dispbytes = instruction.dispbytes
        self.immbytes = instruction.immbytes
        self.sectionbytes = instruction.sectionbytes
        self.flags = instruction.flags

        if instruction.op1.type:
            self.op1 = Operand(self, instruction.op1, offset)
        else:
            self.op1 = None
        if instruction.op2.type:
            self.op2 = Operand(self, instruction.op2, offset)
        else:
            self.op2 = None
        if instruction.op3.type:
            self.op3 = Operand(self, instruction.op3, offset)
        else:
            self.op3 = None
        
        mnemonic = pydasm.get_mnemonic_string(instruction, pydasm.FORMAT_INTEL)
        mnemonic = mnemonic.strip()
        if mnemonic == 'rep retn':
            mnemonic = 'retn'
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

    def is_end(self):
        if self.mnemonic != 'call':
            return False
        op = self.op1
        if not op.is_immediate:
            return False
        name = self.converter.get_function_name(op.value)
        return name in function_enders

    def get_disasm(self):
        return pydasm.get_instruction_string(self.instruction,
                                             pydasm.FORMAT_INTEL,
                                             0).rstrip(" ")

    def group1(self):
        return bool(self.flags & 0xff000000)
    
    def group2(self):
        return (self.flags & 0x00ff0000) >> 16
    
    def group3(self):
        return bool(self.flags & 0x0000ff00)

    def lock(self):
        return bool(self.flags & 0x01000000)
    
    def repne(self):
        return bool(self.flags & 0x02000000)
    
    def rep(self):
        return bool(self.flags & 0x03000000)
        
    def repe(self):
        return bool(self.flags & 0x03000000)
    
    def es_override(self):
        return bool(self.flags & 0x00010000)
    
    def cs_override(self):
        return bool(self.flags & 0x00020000)
    
    def ss_override(self):
        return bool(self.flags & 0x00030000)
    
    def ds_override(self):
        return bool(self.flags & 0x00040000)
    
    def fs_override(self):
        return bool(self.flags & 0x00050000)
    
    def gs_override(self):
        return bool(self.flags & 0x00060000)

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
        
    def get_rm(self):
        if self.modrm:
            return self.modrm & 0x7
        else:
            return False
        
        return False
    
    def get_reg_opcode(self):
        if self.modrm:
            return (self.modrm >> 3) & 0x7
        else:
            return False    
        
        return False
    
    def get_mod(self):
        if self.modrm:
            return (self.modrm >> 6) & 0x7
        else:
            return False
        
        return False

    def get_base(self):
        if self.sib:
            return self.sib & 0x7
        else:
            return False
        
        return False
        
    def get_index(self):
        if self.sib:
            return (self.sib >> 3) & 0x7
        else:
            return False
        
        return False
    
    def get_scale(self):
        if self.sib:
            return (self.sib >> 6) & 0x7
        else:
            return False
        
        return False

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
    def __init__(self, converter, address):
        self.start = address
        self.instructions = {}
        self.instruction_list = []
        self.labels = set()

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
            opcode = instruction.opcode
            self.instructions[address] = instruction
            self.instruction_list.append(instruction)
            address += instruction.length

            mnemonic = instruction.mnemonic
            keys = set([(mnemonic, opcode), mnemonic])

            if self.is_end(instruction, i):
                if self.labels:
                    if max(self.labels) < address:
                        break
                else:
                    break
            elif not keys.isdisjoint(label_makers):
                result = instruction.op1.value
                self.labels.add(result)

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

    def is_end(self, inst, index):
        mnemonic = inst.mnemonic
        opcode = inst.opcode
        return ((mnemonic in ('retn', 'ret', 'int3')) or
                (mnemonic == 'jmp' and opcode in (0xFF,)) or
                (mnemonic == "jmp" and index == 0) or
                inst.is_end())


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
    2: 'uint16_t',
    1: 'uint8_t'
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
    return 'cpu.get_%s()' % value.lower()

class CPU(object):
    eip = None
    sub = None

    def __init__(self, converter):
        self.converter = converter
        self.log = converter.log
        self.get_function_name = converter.get_function_name

    def set_sub(self, sub):
        self.index = 0
        self.sub = sub
        self.eip = sub.start
        self.remaining_labels = sub.labels.copy()
        self.unimplemented = False
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
        self.unimplemented = True
        print 'Conversion failed %X:' % (self.sub.start)
        print "%s: [%#x][%x] %s" % (message, self.eip, i.opcode,
                                    i.get_disasm())

    def next(self):
        instruction = self.sub.instruction_list[self.index]
        self.eip = instruction.address

        if self.eip in self.sub.labels:
            self.writer.put_label(get_label_name(self.eip))
            self.remaining_labels.discard(self.eip)

        name = 'on_%s' % instruction.mnemonic

        handler = getattr(self, name, None)

        if handler is None:
            self.on_fail('Not implemented', instruction)
            return False

        rep_reg = None
        if instruction.prefix == 'rep':
            rep_reg = get_register(REG_CX, REG_GEN_WORD)
        elif instruction.prefix is not None:
            raise NotImplementedError()

        if rep_reg:
            self.writer.putln('while (%s > 0) {' % rep_reg)
            self.writer.indent()

        self.writer.comment = '[%X] %s' % (self.eip, instruction.get_disasm())

        if handler(instruction) is False:
            self.on_fail('Handler failed', instruction)
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

    def push_size(self, value, size):
        getattr(self, 'push_%s' % size_names[size])(value)

    def push_byte(self, value):
        value = prettify_value(value)
        self.writer.putlnc('cpu.push_byte(%s);', value)

    def push_word(self, value):
        value = prettify_value(value)
        self.writer.putlnc('cpu.push_word(%s);', value)

    def push_dword(self, value):
        value = prettify_value(value)
        self.writer.putlnc('cpu.push_dword(%s);' % value)

    def pop_dword(self, value):
        value = prettify_value(value)
        self.writer.putlnc('cpu.pop_dword(&%s);' % value)

    def set_op(self, op, value):
        if op.is_memory:
            self.set_memory(op.value, value, op.size)
        else:
            self.set_register(op.value, value)

    def goto(self, test, address):
        if address < self.sub.start or address >= self.sub.end:
            call = '%s()' % self.get_function_name(address)
        else:
            call = 'goto %s' % get_label_name(address)
        self.writer.putln('if (%s) %s;' % (test, call))

    def test_flag(self, flag, value, goto):
        test = get_flag(flag)
        if not value:
            test = '!%s' % test
        self.goto(test, goto)

    def test_eq_flag(self, flag1, flag2, value, goto):
        if value:
            comp = '=='
        else:
            comp = '!='
        test1 = get_flag(flag1)
        test2 = get_flag(flag2)
        self.goto('%s %s %s' % (test1, comp, test2), goto)

    def test_and_flag(self, flag1, flag2, value, goto):
        test1 = get_flag(flag1)
        test2 = get_flag(flag2)
        if value:
            test = '%s && %s' % (test1, test2)
        else:
            test = '!%s && !%s' % (test1, test2)
        self.goto(test, goto)

    def call_dynamic(self, value):
        self.writer.putln('cpu.call_dynamic(%s);' % value)

    def on_push(self, i):
        self.push_dword(i.op1.get())

    def on_pop(self, i):
        if not i.op1.is_register:
            return False
        self.pop_dword(i.op1.value)

    def on_mov(self, i):
        # since we don't want to bother with setting up import table, just
        # set function pointers directly
        self.set_op(i.op1, i.op2.get())

    def on_movsx(self, i):
        signed1 = signed_types[i.op2.size]
        unsigned1 = size_types[i.op2.size]
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
        i.op1.size = 4
        i.op2.size = 8
        self.set_op(i.op1, 'ss_to_sd(to_ss(%s))' % i.op2.get())

    def on_cvtsd2ss(self, i):
        i.op1.size = 4
        i.op2.size = 8
        self.set_op(i.op1, 'sd_to_ss(to_sd(%s))' % i.op2.get())

    def on_cvttss2si(self, i):
        i.op1.size = i.op2.size = 4
        self.set_op(i.op1, 'ss_to_si(%s)' % i.op2.get())

    def on_cvtdq2pd(self, i):
        self.writer.putlnc('dq_to_pd(%s, %s);', i.op1.get(), i.op2.get())

    def on_cvtps2pd(self, i):
        self.writer.putlnc('ps_to_pd(%s, %s);', i.op1.get(), i.op2.get())

    def on_cvtpd2ps(self, i):
        self.writer.putlnc('pd_to_ps(%s, %s);', i.op1.get(), i.op2.get())

    def on_cvtdq2ps(self, i):
        self.writer.putlnc('dq_to_ps(%s, %s);', i.op1.get(), i.op2.get())

    def on_fst(self, i):
        st0 = get_register(REG_ST0, REG_FPU)
        self.set_op(i.op1, 'to_dword(float(%s))' % st0)

    def on_fistp(self, i):
        if i.fpuindex != 7:
            return False
        i.op1.size = 8
        self.set_op(i.op1, 'int64_t(%s)' % self.pop_float())

    def push_float(self, value):
        self.writer.putlnc('cpu.push_fpu(%s);', value)

    def pop_float(self, write=False):
        if write:
            self.writer.putln('cpu.pop_fpu();')
            return
        return 'cpu.pop_fpu()'

    def on_fsubp(self, i):
        if not i.op2:
            return False
        self.set_op(i.op1, '%s - %s' % (i.op1.get(), i.op2.get()))
        self.pop_float(True)

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
        if i.op1.size == 10:
            i.op1.size = 8
        self.push_float('si_to_ld(%s)' % (i.op1.get()))

    def on_flds(self, i):
        size_type = size_types[i.op1.size]
        self.push_float('to_ld(%s(%s))' % (size_type, i.op1.get()))

    def on_fstp(self, i):
        func = 'ld_to_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s)' % (func, self.pop_float()))

    def on_fstpl(self, i):
        func = 'ld_to_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s)' % (func, self.pop_float()))

    def on_comiss(self, i):
        i.op1.size = i.op2.size = 4
        self.writer.putlnc('cpu.compare_ss(to_ss(%s), to_ss(%s));' % (
            i.op1.get(), i.op2.get()))

    def on_comisd(self, i):
        i.op1.size = i.op2.size = 8
        self.writer.putlnc('cpu.compare_sd(to_sd(%s), to_sd(%s));' % (
            i.op1.get(), i.op2.get()))

    def on_movapd(self, i):
        self.set_op(i.op1, i.op2.get())

    def on_movaps(self, i):
        self.set_op(i.op1, i.op2.get())

    def on_movlpd(self, i):
        self.set_op(i.op1, i.op2.get())

    def on_movq(self, i):
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
        es = get_register(REG_DS, REG_SEGMENT)
        edi = get_register(REG_EDI, reg_type)
        self.set_memory('%s+%s' % (es, edi), eax, size)
        df = '(int(!%s)*2-1)*%s' % (get_flag('DF'), size)
        self.set_register(edi, '%s + %s' % (edi, df))

    def on_sbb(self, i):
        func = 'cpu.sbb_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_sub(self, i):
        func = 'cpu.sub_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_adc(self, i):
        func = 'cpu.adc_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_dec(self, i):
        func = 'cpu.dec_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s)' % (func, i.op1.get()))

    def on_inc(self, i):
        func = 'cpu.inc_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s)' % (func, i.op1.get()))

    def on_and(self, i):
        func = 'cpu.and_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_or(self, i):
        func = 'cpu.or_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_xor(self, i):
        func = 'cpu.xor_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_not(self, i):
        # eflags not affected
        self.set_op(i.op1, '~%s' % i.op1.get())

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
                print 'Found startthread'
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
        self.set_register(eax, 'uint32_t(int16_t(%s))' % ax)

    def on_setnz(self, i):
        test = get_flag('ZF')
        self.set_register(i.op1.value, 'int(!%s)' % test)

    def on_sets(self, i):
        test = get_flag('SF')
        self.set_register(i.op1.value, 'int(%s)' % test)

    def on_setl(self, i):
        sf = get_flag('SF')
        of = get_flag('OF')
        self.set_register(i.op1.value, 'int(%s != %s)' % (sf, of))

    def on_setnle(self, i):
        zf = get_flag('ZF')
        sf = get_flag('SF')
        of = get_flag('OF')
        self.set_register(i.op1.value, 'int(!%s && %s == %s)' % (zf, sf, of))

    def on_setnbe(self, i):
        cf = get_flag('CF')
        zf = get_flag('ZF')
        self.set_register(i.op1.value, 'int(!%s && !%s)' % (cf, zf))

    def on_setbe(self, i):
        cf = get_flag('CF')
        zf = get_flag('ZF')
        self.set_register(i.op1.value, 'int(%s || %s)' % (cf, zf))

    def on_seto(self, i):
        test = get_flag('OF')
        self.set_register(i.op1.value, 'int(%s)' % test)

    def on_setns(self, i):
        test = get_flag('SF')
        self.set_register(i.op1.value, 'int(!%s)' % test)

    def on_setz(self, i):
        self.set_op(i.op1, 'int(%s)' % get_flag('ZF'))

    def on_movzx(self, i):
        src = i.op2
        if src.is_memory and src.displacement:
            # test for jumptable in text segment
            # let on_jmp handle this
            displacement = eval(src.displacement)
            try:
                section = self.converter.get_section(displacement)
                if section.section_name == 'text':
                    return
            except NotImplementedError:
                pass
        self.set_register(i.op1.value, i.op2.get())

    def on_cmovae(self, i):
        self.writer.putlnc('if (!%s)', get_flag('CF'))
        self.writer.indent()
        self.set_op(i.op1, i.op2.get())
        self.writer.dedent()

    def on_cmova(self, i):
        cf = get_flag('CF')
        zf = get_flag('ZF')
        self.writer.putlnc('if (!%s && !%s)', cf, zf)
        self.writer.indent()
        self.set_op(i.op1, i.op2.get())
        self.writer.dedent()

    def on_cmovbe(self, i):
        cf = get_flag('CF')
        zf = get_flag('ZF')
        self.writer.putlnc('if (%s || %s)', cf, zf)
        self.writer.indent()
        self.set_op(i.op1, i.op2.get())
        self.writer.dedent()

    def on_cmovb(self, i):
        cf = get_flag('CF')
        self.writer.putlnc('if (%s)', cf)
        self.writer.indent()
        self.set_op(i.op1, i.op2.get())
        self.writer.dedent()

    def on_cmovg(self, i):
        zf = get_flag('ZF')
        sf = get_flag('SF')
        of = get_flag('OF')
        self.writer.putlnc('if (!%s && %s == %s)', zf, sf, of)
        self.writer.indent()
        self.set_op(i.op1, i.op2.get())
        self.writer.dedent()

    def on_cmovge(self, i):
        zf = get_flag('ZF')
        cf = get_flag('CF')
        self.writer.putlnc('if (%s || %s)', zf, cf)
        self.writer.indent()
        self.set_op(i.op1, i.op2.get())
        self.writer.dedent()

    def on_cmovl(self, i):
        self.writer.putln('if (%s == %s)' % (get_flag('SF'), get_flag('OF')))
        self.writer.indent()
        self.set_op(i.op1, i.op2.get())
        self.writer.dedent()

    def on_cmovle(self, i):
        sf = get_flag('SF')
        of = get_flag('OF')
        zf = get_flag('ZF')
        self.writer.putln('if (%s || %s != %s)' % (zf, sf, of))
        self.writer.indent()
        self.set_op(i.op1, i.op2.get())
        self.writer.dedent()

    def on_cmove(self, i):
        test = get_flag('ZF')
        self.writer.putln('if (%s)' % test)
        self.writer.indent()
        self.set_op(i.op1, i.op2.get())
        self.writer.dedent()

    def on_cmovne(self, i):
        test = get_flag('ZF')
        self.writer.putln('if (!%s)' % test)
        self.writer.indent()
        self.set_op(i.op1, i.op2.get())
        self.writer.dedent()

    def on_int3(self, i):
        # self.log('int3 at %s' % self.eip)
        pass

    def on_nop(self, i):
        pass

    def on_fstcw(self, i):
        print 'fstcw nop at %X' % self.eip

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
                    if indirect.op1.get() != reg:
                        raise NotImplementedError()
                    ind_op = indirect.op2
                    ind_addr = eval(ind_op.displacement)
                    ind_reg = op.index_reg
                    if ind_op.size != 1:
                        raise NotImplementedError()
                    indexes = collections.defaultdict(list)
                    # find the max value
                    for i in xrange(table_size):
                        data = self.converter.get_memory(ind_addr + i, 1)
                        index, = struct.unpack('<B', data)
                        indexes[index].append(i)

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
                for i in xrange(table_size):
                    data = self.converter.get_memory(table_addr + i*scale, 4)
                    addr, = struct.unpack('<I', data)
                    loc = get_label_name(addr)
                    self.writer.putln('case %s: goto %s;' % (i, loc))
                    self.sub.labels.add(addr)
                    self.remaining_labels.add(addr)
                self.writer.end_brace()
                return
            self.call_memory(op)
            self.writer.putln('return;')

    def on_jz(self, i):
        self.test_flag('ZF', True, i.op1.value)

    def on_jc(self, i):
        self.test_flag('CF', True, i.op1.value)

    def on_js(self, i):
        self.test_flag('SF', True, i.op1.value)

    def on_jns(self, i):
        self.test_flag('SF', False, i.op1.value)

    def on_jnl(self, i):
        self.test_eq_flag('SF', 'OF', True, i.op1.value)

    def on_jl(self, i):
        self.test_eq_flag('SF', 'OF', False, i.op1.value)

    def on_jng(self, i):
        self.test_flag('ZF', True, i.op1.value)
        self.test_eq_flag('SF', 'OF', False, i.op1.value)

    def on_jnc(self, i):
        self.test_flag('CF', False, i.op1.value)

    def on_ja(self, i):
        self.test_and_flag('CF', 'ZF', False, i.op1.value)

    def on_jg(self, i):
        zf = get_flag('ZF')
        sf = get_flag('SF')
        of = get_flag('OF')
        self.goto('!%s && %s == %s' % (zf, sf, of), i.op1.value)

    def on_jna(self, i):
        for name in ('CF', 'ZF'):
            self.test_flag(name, True, i.op1.value)

    def on_shl(self, i):
        func = 'cpu.shl_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_shld(self, i):
        func = 'cpu.shld_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s, %s)' % (func, i.op1.get(), i.op2.get(),
                                               i.op3.get()))

    def on_shr(self, i):
        func = 'cpu.shr_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_rcr(self, i):
        func = 'cpu.rcr_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_rol(self, i):
        func = 'cpu.rol_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_sar(self, i):
        func = 'cpu.sar_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_add(self, i):
        func = 'cpu.add_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_xadd(self, i):
        func = 'cpu.xadd_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s, %s)' % (func, i.op1.get(), i.op2.get()))

    def on_neg(self, i):
        func = 'cpu.neg_%s' % size_names[i.op1.size]
        self.set_op(i.op1, '%s(%s)' % (func, i.op1.get()))

    def on_test(self, i):
        name = 'cpu.test_%s' % size_names[i.op1.size]
        self.writer.putln('%s(%s, %s);' % (name, i.op1.get(), i.op2.get()))

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
        if i.op3:
            func = 'cpu.imul_%s' % size_names[i.op1.size]
            call = '%s(%s, %s);' % (func, i.op2.get(), i.op3.get())
            self.set_op(i.op1, call)
        elif i.op2:
            func = 'cpu.imul_%s' % size_names[i.op1.size]
            call = '%s(%s, %s);' % (func, i.op1.get(), i.op2.get())
            self.set_op(i.op1, call)
        else:
            func = 'cpu.imul_%s' % size_names[i.op1.size]
            self.writer.putlnc('%s(%s);', func, i.op1.get())

    def on_mul(self, i):
        if i.op2 or i.op3:
            return False
        func = 'cpu.mul_%s' % size_names[i.op1.size]
        self.writer.putlnc('%s(%s);', func, i.op1.get())

    def on_retn(self, i):
        value = i.op1.value
        reg = get_register(REG_ESP, REG_GEN_DWORD)
        self.set_register(reg, '%s+%s' % (reg, value+4))
        self.writer.putln('return;')

    def on_ret(self, i):
        reg = get_register(REG_ESP, REG_GEN_DWORD)
        self.set_register(reg, '%s+%s' % (reg, 4))
        self.writer.putln('return;')

    def on_leave(self, i):
        esp = get_register(REG_ESP, REG_GEN_DWORD)
        ebp = get_register(REG_EBP, REG_GEN_DWORD)
        self.set_register(esp, ebp)
        self.set_register(ebp, 'cpu.pop_dword();')

    def on_cmp(self, i):
        name = 'cpu.cmp_%s' % size_names[i.op1.size]
        self.writer.putln('%s(%s, %s);' % (name, i.op1.get(), i.op2.get()))

    def on_jnz(self, i):
        self.test_flag('ZF', False, i.op1.value)

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

class Converter(object):
    def __init__(self, path):
        # setup
        self.custom_code = ''
        for f in os.listdir('src/import'):
            code_path = os.path.join('src/import', f)
            self.custom_code += open(code_path, 'rb').read()

        self.mem_writes = {}
        self.sections = []
        self.imports = {}
        self.used_imports = set()
        self.custom_subs = set()
        self.cached_names = {}
        self.subs = {}
        self.cpu = CPU(self)
        self.load_sections = []
        self.load_images = []

        self.base_dir = os.path.dirname(path)
        pe = pefile.PE(path)

        optional = pe.OPTIONAL_HEADER

        self.image_base = optional.ImageBase
        self.code_base = optional.ImageBase + optional.BaseOfCode
        self.data_base = optional.ImageBase + optional.BaseOfData
        self.entry_point = optional.ImageBase + optional.AddressOfEntryPoint

        print "Image Base Addr:  0x%08x" % (self.image_base)
        print "Code Base Addr:   0x%08x" % (self.code_base)
        print "Data Base Addr:   0x%08x" % (self.data_base)
        print "Entry Point Addr: 0x%08x\n" % (self.entry_point)

        print 'image header:', len(pe.header)

        writer = CodeWriter('gensrc/out.cpp')
        writer.putln('#include "main.h"')
        writer.putln('#include "memory.h"')
        writer.putln('#include "functions.h"')
        writer.putln('')

        writer.putmeth('inline void start')

        for index, section in enumerate(pe.sections):
            self.sections.append(section)
            section.image_base = self.image_base
            name = section.Name.strip('\x00')[1:]
            section.section_name = name
            if name in ('rsrc', 'text', 'reloc'):
                continue
            self.load_sections.append(section)

        self.import_addresses = {}
        for entry in pe.DIRECTORY_ENTRY_IMPORT:
            # should_load = entry.dll in ('MSVCP110.dll',)
            should_load = False

            if should_load:
                path = os.path.abspath(os.path.join(self.base_dir, entry.dll))
                dll_pe = self.load_dll(path, entry)

            for imp in entry.imports:
                if should_load:
                    self.setup_import(dll_pe, imp)
                else:
                    self.imports[imp.address] = (imp, entry)
                # print '[*]  0x%08x [%20s]' % (imp.address, imp.name)

        for section in self.load_sections:
            name = section.Name.strip('\x00')[1:]
            section_base = section.image_base + section.VirtualAddress
            virtualsize = section.Misc_VirtualSize
            data = section.get_data()
            data_len = len(data)

            print "[*] Base Addr: 0x%08x (vsize: %08x  dsize: %08x)" % (
                section_base, virtualsize, data_len)

            # for x in range(sectiondatalen):
            #     c = section.data[x]
            #     self.set_memory(sectionbase + x, int(ord(c)), size=1)
            filename = 'gensrc/%s_section_%X.dat' % (name, section_base)
            with open(filename, 'wb') as fp:
                fp.write(data)
            writer.putlnc('mem.write_section(%#x, %r);', section_base,
                          filename)
            
            # if we have a section without data lets fill nulls
            extra = virtualsize - data_len
            if extra > 0:
                off = section_base + data_len
                writer.putlnc('mem.pad_section(%#x, %s);', off, extra)

        writer.putln('entry_point();')
        writer.end_brace()

        # ensure custom sqlite3 is used
        sqlite_table = self.image_base + 0x16A290
        for _ in xrange(712 / 4):
            value = self.get_memory(sqlite_table, 4)
            value, = struct.unpack('<I', value)
            if value != 0:
                func = self.get_function_name(value)
                # XXX hack
                self.custom_code += func
                # print '%s -> %X' % (func, self.get_ida_address(sqlite_table))
            sqlite_table += 4

        # get current dynamic addresses
        import dynamic
        self.dynamic_addresses = dynamic.dynamic_addresses

        # write functions, starting from entry point
        # start at main()
        self.entry_point = self.image_base + 0x149AD0
        self.function_stack = [self.entry_point]
        for address in self.dynamic_addresses:
            if (address in self.imports and
                address not in self.import_addresses.values()):
                self.used_imports.add(address)
            else:
                self.function_stack.insert(0, address)

        while self.function_stack:
            address = self.function_stack.pop()
            ida = self.get_ida_address(address)
            sub = Subroutine(self, address)
            self.subs[address] = sub
            self.iterate_tree(sub)

        addresses = set()
        addresses.update(self.subs.keys())
        addresses.update(self.used_imports)
        addresses.update(self.custom_subs)

        writer.putmeth('void init_function_map')
        for address in addresses:
            name = self.get_function_name(address)
            writer.putln('cpu.add_function(0x%X, %s);' % (address, name))
        writer.end_brace()

        writer.close()

        writer = CodeWriter('gensrc/functions.h')
        for address in addresses:
            name = self.get_function_name(address)
            writer.putln('inline void %s();' % name)
        for address in self.subs.keys():
            name = self.get_function_name(address)
            writer.putln('#include "gensrc/%s.h"' % name)
        writer.putln('')
        writer.close()

        writer = CodeWriter('gensrc/stubs.h')
        writer.putln('#include <iostream>')
        writer.putln('')
        stubs = self.used_imports
        stubs -= set(self.import_addresses.values())
        stubs -= set(self.subs.keys())
        stub_names = set()
        for imp in stubs:
            name = self.get_function_name(imp)
            if self.is_custom(name) or name in stub_names:
                continue
            stub_names.add(name)
            writer.putmeth('inline void %s' % name)
            import_name = self.get_import_name(imp)
            writer.putln('std::cout << "Stub: %s" << std::endl;' % import_name)
            writer.end_brace()
            writer.putln('')
        writer.close()

        # write import names
        # open('importnames.txt', 'wb').write(repr(import_mappings))

    def is_custom(self, name):
        data = self.custom_code.replace('%s();' % name, '')
        return name in data

    def get_ida_address(self, address):
        ida_image_base = 0x200000
        ida_address = address - self.image_base + ida_image_base
        return ida_address

    def setup_import(self, pe, imp):
        addr = self.import_addresses[imp.name]
        self.mem_writes[(imp.address, 4)] = DWORD(addr)

    def load_dll(self, path, entry):
        pe = pefile.PE(path)
        print 'pe header size:', len(pe.header)
        optional = pe.OPTIONAL_HEADER

        image_base = optional.ImageBase

        for exp in pe.DIRECTORY_ENTRY_EXPORT.symbols:
            addr = image_base + exp.address
            self.import_addresses[exp.name] = addr
            self.imports[addr] = (exp, entry)

        for section in pe.sections:
            name = section.Name.strip('\x00')[1:]
            section.image_base = image_base
            section.section_name = name
            self.sections.append(section)
            if name in ('rsrc', 'reloc'):
                continue
            self.load_sections.append(section)

        for entry in pe.DIRECTORY_ENTRY_IMPORT:
            for imp in entry.imports:
                self.imports[imp.address] = (imp, entry)

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

    def iterate_tree(self, sub):
        name = self.get_function_name(sub.start)
        writer = self.writer = CodeWriter('gensrc/%s.h' % name)
        self.cpu.set_sub(sub)

        writer.putmeth('void %s' % name)
        is_aliased = sub.start in function_alias
        if is_aliased:
            writer.putlnc('std::cout << %r << std::endl;',
                          '%s() start' % name)
        while True:
            if not self.cpu.next():
                break
        for label in self.cpu.remaining_labels:
            writer.put_label(get_label_name(label))
        if self.cpu.unimplemented:
            self.log('Not implemented, stack may be corrupted (%X)' % (
                sub.start))
        if is_aliased:
            writer.putlnc('std::cout << %r << std::endl;',
                               '%s() end' % name)
        writer.end_brace()
        writer.close()

    def get_section(self, address):
        for section in self.sections:
            section_base = section.image_base + section.VirtualAddress
            section_end = section_base + section.SizeOfRawData
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

    def log(self, value):
        self.writer.putlnc('std::cout << %r << std::endl;', value)


SERVER_HASH = 'A6FC5AA34068B5B80C53B2439C65BE3B'


def main():
    import hashlib
    import argparse

    parser = argparse.ArgumentParser(
        description='Translates Server.exe into a terrain generator')
    parser.add_argument('file', help='path to Server.exe')
    args = parser.parse_args()

    file_hash = hashlib.md5(open(args.file, 'rb').read()).hexdigest()

    if file_hash != SERVER_HASH.lower():
        print 'Invalid Server.exe hash, should be %s' % SERVER_HASH
        return

    converter = Converter(args.file)

if __name__ == '__main__':
    main()