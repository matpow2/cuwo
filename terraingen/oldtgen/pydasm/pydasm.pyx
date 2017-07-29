# Copyright (c) Mathias Kaerlev 2013-2017.
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

cdef extern from "libdasm.h":
    cdef enum InstructionType "Instruction":
        C_INSTRUCTION_TYPE_ASC "INSTRUCTION_TYPE_ASC"
        C_INSTRUCTION_TYPE_DCL "INSTRUCTION_TYPE_DCL"
        C_INSTRUCTION_TYPE_MOV "INSTRUCTION_TYPE_MOV"
        C_INSTRUCTION_TYPE_MOVSR "INSTRUCTION_TYPE_MOVSR"
        C_INSTRUCTION_TYPE_ADD "INSTRUCTION_TYPE_ADD"
        C_INSTRUCTION_TYPE_XADD "INSTRUCTION_TYPE_XADD"
        C_INSTRUCTION_TYPE_ADC "INSTRUCTION_TYPE_ADC"
        C_INSTRUCTION_TYPE_SUB "INSTRUCTION_TYPE_SUB"
        C_INSTRUCTION_TYPE_SBB "INSTRUCTION_TYPE_SBB"
        C_INSTRUCTION_TYPE_INC "INSTRUCTION_TYPE_INC"
        C_INSTRUCTION_TYPE_DEC "INSTRUCTION_TYPE_DEC"
        C_INSTRUCTION_TYPE_DIV "INSTRUCTION_TYPE_DIV"
        C_INSTRUCTION_TYPE_IDIV "INSTRUCTION_TYPE_IDIV"
        C_INSTRUCTION_TYPE_NOT "INSTRUCTION_TYPE_NOT"
        C_INSTRUCTION_TYPE_NEG "INSTRUCTION_TYPE_NEG"
        C_INSTRUCTION_TYPE_STOS "INSTRUCTION_TYPE_STOS"
        C_INSTRUCTION_TYPE_LODS "INSTRUCTION_TYPE_LODS"
        C_INSTRUCTION_TYPE_SCAS "INSTRUCTION_TYPE_SCAS"
        C_INSTRUCTION_TYPE_MOVS "INSTRUCTION_TYPE_MOVS"
        C_INSTRUCTION_TYPE_MOVSX "INSTRUCTION_TYPE_MOVSX"
        C_INSTRUCTION_TYPE_MOVZX "INSTRUCTION_TYPE_MOVZX"
        C_INSTRUCTION_TYPE_CMPS "INSTRUCTION_TYPE_CMPS"
        C_INSTRUCTION_TYPE_SHX "INSTRUCTION_TYPE_SHX"
        C_INSTRUCTION_TYPE_ROX "INSTRUCTION_TYPE_ROX"
        C_INSTRUCTION_TYPE_MUL "INSTRUCTION_TYPE_MUL"
        C_INSTRUCTION_TYPE_IMUL "INSTRUCTION_TYPE_IMUL"
        C_INSTRUCTION_TYPE_EIMUL "INSTRUCTION_TYPE_EIMUL"
        C_INSTRUCTION_TYPE_XOR "INSTRUCTION_TYPE_XOR"
        C_INSTRUCTION_TYPE_LEA "INSTRUCTION_TYPE_LEA"
        C_INSTRUCTION_TYPE_XCHG "INSTRUCTION_TYPE_XCHG"
        C_INSTRUCTION_TYPE_CMP "INSTRUCTION_TYPE_CMP"
        C_INSTRUCTION_TYPE_TEST "INSTRUCTION_TYPE_TEST"
        C_INSTRUCTION_TYPE_PUSH "INSTRUCTION_TYPE_PUSH"
        C_INSTRUCTION_TYPE_AND "INSTRUCTION_TYPE_AND"
        C_INSTRUCTION_TYPE_OR "INSTRUCTION_TYPE_OR"
        C_INSTRUCTION_TYPE_POP "INSTRUCTION_TYPE_POP"
        C_INSTRUCTION_TYPE_JMP "INSTRUCTION_TYPE_JMP"
        C_INSTRUCTION_TYPE_JMPC "INSTRUCTION_TYPE_JMPC"
        C_INSTRUCTION_TYPE_JECXZ "INSTRUCTION_TYPE_JECXZ"
        C_INSTRUCTION_TYPE_SETC "INSTRUCTION_TYPE_SETC"
        C_INSTRUCTION_TYPE_MOVC "INSTRUCTION_TYPE_MOVC"
        C_INSTRUCTION_TYPE_LOOP "INSTRUCTION_TYPE_LOOP"
        C_INSTRUCTION_TYPE_CALL "INSTRUCTION_TYPE_CALL"
        C_INSTRUCTION_TYPE_RET "INSTRUCTION_TYPE_RET"
        C_INSTRUCTION_TYPE_ENTER "INSTRUCTION_TYPE_ENTER"
        C_INSTRUCTION_TYPE_INT "INSTRUCTION_TYPE_INT"
        C_INSTRUCTION_TYPE_BT "INSTRUCTION_TYPE_BT"
        C_INSTRUCTION_TYPE_BTS "INSTRUCTION_TYPE_BTS"
        C_INSTRUCTION_TYPE_BTR "INSTRUCTION_TYPE_BTR"
        C_INSTRUCTION_TYPE_BTC "INSTRUCTION_TYPE_BTC"
        C_INSTRUCTION_TYPE_BSF "INSTRUCTION_TYPE_BSF"
        C_INSTRUCTION_TYPE_BSR "INSTRUCTION_TYPE_BSR"
        C_INSTRUCTION_TYPE_BSWAP "INSTRUCTION_TYPE_BSWAP"
        C_INSTRUCTION_TYPE_SGDT "INSTRUCTION_TYPE_SGDT"
        C_INSTRUCTION_TYPE_SIDT "INSTRUCTION_TYPE_SIDT"
        C_INSTRUCTION_TYPE_SLDT "INSTRUCTION_TYPE_SLDT"
        C_INSTRUCTION_TYPE_LFP "INSTRUCTION_TYPE_LFP"
        C_INSTRUCTION_TYPE_CLD "INSTRUCTION_TYPE_CLD"
        C_INSTRUCTION_TYPE_STD "INSTRUCTION_TYPE_STD"
        C_INSTRUCTION_TYPE_XLAT "INSTRUCTION_TYPE_XLAT"
        C_INSTRUCTION_TYPE_FCMOVC "INSTRUCTION_TYPE_FCMOVC"
        C_INSTRUCTION_TYPE_FADD "INSTRUCTION_TYPE_FADD"
        C_INSTRUCTION_TYPE_FADDP "INSTRUCTION_TYPE_FADDP"
        C_INSTRUCTION_TYPE_FIADD "INSTRUCTION_TYPE_FIADD"
        C_INSTRUCTION_TYPE_FSUB "INSTRUCTION_TYPE_FSUB"
        C_INSTRUCTION_TYPE_FSUBP "INSTRUCTION_TYPE_FSUBP"
        C_INSTRUCTION_TYPE_FISUB "INSTRUCTION_TYPE_FISUB"
        C_INSTRUCTION_TYPE_FSUBR "INSTRUCTION_TYPE_FSUBR"
        C_INSTRUCTION_TYPE_FSUBRP "INSTRUCTION_TYPE_FSUBRP"
        C_INSTRUCTION_TYPE_FISUBR "INSTRUCTION_TYPE_FISUBR"
        C_INSTRUCTION_TYPE_FMUL "INSTRUCTION_TYPE_FMUL"
        C_INSTRUCTION_TYPE_FMULP "INSTRUCTION_TYPE_FMULP"
        C_INSTRUCTION_TYPE_FIMUL "INSTRUCTION_TYPE_FIMUL"
        C_INSTRUCTION_TYPE_FDIV "INSTRUCTION_TYPE_FDIV"
        C_INSTRUCTION_TYPE_FDIVP "INSTRUCTION_TYPE_FDIVP"
        C_INSTRUCTION_TYPE_FDIVR "INSTRUCTION_TYPE_FDIVR"
        C_INSTRUCTION_TYPE_FDIVRP "INSTRUCTION_TYPE_FDIVRP"
        C_INSTRUCTION_TYPE_FIDIV "INSTRUCTION_TYPE_FIDIV"
        C_INSTRUCTION_TYPE_FIDIVR "INSTRUCTION_TYPE_FIDIVR"
        C_INSTRUCTION_TYPE_FCOM "INSTRUCTION_TYPE_FCOM"
        C_INSTRUCTION_TYPE_FCOMP "INSTRUCTION_TYPE_FCOMP"
        C_INSTRUCTION_TYPE_FCOMPP "INSTRUCTION_TYPE_FCOMPP"
        C_INSTRUCTION_TYPE_FCOMI "INSTRUCTION_TYPE_FCOMI"
        C_INSTRUCTION_TYPE_FCOMIP "INSTRUCTION_TYPE_FCOMIP"
        C_INSTRUCTION_TYPE_FUCOM "INSTRUCTION_TYPE_FUCOM"
        C_INSTRUCTION_TYPE_FUCOMP "INSTRUCTION_TYPE_FUCOMP"
        C_INSTRUCTION_TYPE_FUCOMPP "INSTRUCTION_TYPE_FUCOMPP"
        C_INSTRUCTION_TYPE_FUCOMI "INSTRUCTION_TYPE_FUCOMI"
        C_INSTRUCTION_TYPE_FUCOMIP "INSTRUCTION_TYPE_FUCOMIP"
        C_INSTRUCTION_TYPE_FST "INSTRUCTION_TYPE_FST"
        C_INSTRUCTION_TYPE_FSTP "INSTRUCTION_TYPE_FSTP"
        C_INSTRUCTION_TYPE_FIST "INSTRUCTION_TYPE_FIST"
        C_INSTRUCTION_TYPE_FISTP "INSTRUCTION_TYPE_FISTP"
        C_INSTRUCTION_TYPE_FISTTP "INSTRUCTION_TYPE_FISTTP"
        C_INSTRUCTION_TYPE_FLD "INSTRUCTION_TYPE_FLD"
        C_INSTRUCTION_TYPE_FILD "INSTRUCTION_TYPE_FILD"
        C_INSTRUCTION_TYPE_FICOM "INSTRUCTION_TYPE_FICOM"
        C_INSTRUCTION_TYPE_FICOMP "INSTRUCTION_TYPE_FICOMP"
        C_INSTRUCTION_TYPE_FFREE "INSTRUCTION_TYPE_FFREE"
        C_INSTRUCTION_TYPE_FFREEP "INSTRUCTION_TYPE_FFREEP"
        C_INSTRUCTION_TYPE_FXCH "INSTRUCTION_TYPE_FXCH"
        C_INSTRUCTION_TYPE_SYSENTER "INSTRUCTION_TYPE_SYSENTER"
        C_INSTRUCTION_TYPE_FPU_CTRL "INSTRUCTION_TYPE_FPU_CTRL"
        C_INSTRUCTION_TYPE_FPU "INSTRUCTION_TYPE_FPU"
        C_INSTRUCTION_TYPE_MMX "INSTRUCTION_TYPE_MMX"
        C_INSTRUCTION_TYPE_SSE "INSTRUCTION_TYPE_SSE"
        C_INSTRUCTION_TYPE_OTHER "INSTRUCTION_TYPE_OTHER"
        C_INSTRUCTION_TYPE_PRIV "INSTRUCTION_TYPE_PRIV"

    cdef enum OperandType "Operand":
        C_OPERAND_TYPE_NONE "OPERAND_TYPE_NONE"
        C_OPERAND_TYPE_MEMORY "OPERAND_TYPE_MEMORY"
        C_OPERAND_TYPE_REGISTER "OPERAND_TYPE_REGISTER"
        C_OPERAND_TYPE_IMMEDIATE "OPERAND_TYPE_IMMEDIATE"

    cdef enum:
        C_REGISTER_EAX "REGISTER_EAX"
        C_REGISTER_ECX "REGISTER_ECX"
        C_REGISTER_EDX "REGISTER_EDX"
        C_REGISTER_EBX "REGISTER_EBX"
        C_REGISTER_ESP "REGISTER_ESP"
        C_REGISTER_EBP "REGISTER_EBP"
        C_REGISTER_ESI "REGISTER_ESI"
        C_REGISTER_EDI "REGISTER_EDI"
        C_REGISTER_NOP "REGISTER_NOP"

    cdef enum:
        C_REGISTER_TYPE_GEN "REGISTER_TYPE_GEN"
        C_REGISTER_TYPE_SEGMENT "REGISTER_TYPE_SEGMENT"
        C_REGISTER_TYPE_DEBUG "REGISTER_TYPE_DEBUG"
        C_REGISTER_TYPE_CONTROL "REGISTER_TYPE_CONTROL"
        C_REGISTER_TYPE_TEST "REGISTER_TYPE_TEST"
        C_REGISTER_TYPE_XMM "REGISTER_TYPE_XMM"
        C_REGISTER_TYPE_MMX "REGISTER_TYPE_MMX"
        C_REGISTER_TYPE_FPU "REGISTER_TYPE_FPU"

    cdef enum AddressingMode "Mode":
        C_MODE_32 "MODE_32"
        C_MODE_16 "MODE_16"

    enum DisassemblingFormat "Format":
        C_FORMAT_ATT "FORMAT_ATT"
        C_FORMAT_INTEL "FORMAT_INTEL"

    ctypedef unsigned int DWORD
    ctypedef unsigned char BYTE
    ctypedef unsigned short WORD

    ctypedef struct OPERAND:
        OperandType type
        int reg
        int basereg
        int indexreg
        int scale
        int dispbytes
        int dispoffset
        int immbytes
        int immoffset
        int sectionbytes
        WORD section
        DWORD displacement
        DWORD immediate
        int flags

    ctypedef struct INSTRUCTION:
        int length
        InstructionType type
        AddressingMode mode
        BYTE opcode
        BYTE modrm
        BYTE sib
        int modrm_offset
        int extindex
        int fpuindex
        int dispbytes
        int immbytes
        int sectionbytes
        OPERAND op1
        OPERAND op2
        OPERAND op3
        int flags
        short eflags_affected
        short eflags_used
        int iop_written
        int iop_read

    int get_instruction_c "get_instruction"(INSTRUCTION * inst, BYTE * addr,
                                            AddressingMode mode)

    int get_instruction_string_c "get_instruction_string"(
        INSTRUCTION * inst, DisassemblingFormat format,
        DWORD offset, char * string, int length
    )

    int get_mnemonic_string_c "get_mnemonic_string"(
        INSTRUCTION * inst, DisassemblingFormat format, char * string,
        int length
    )

    int get_operand_string_c "get_operand_string"(
        INSTRUCTION * inst, OPERAND * op, DisassemblingFormat format,
        DWORD offset, char * string, int length
    )

    int get_register_type_c "get_register_type"(OPERAND * op)


INSTRUCTION_TYPE_ASC = C_INSTRUCTION_TYPE_ASC
INSTRUCTION_TYPE_DCL = C_INSTRUCTION_TYPE_DCL
INSTRUCTION_TYPE_MOV = C_INSTRUCTION_TYPE_MOV
INSTRUCTION_TYPE_MOVSR = C_INSTRUCTION_TYPE_MOVSR
INSTRUCTION_TYPE_ADD = C_INSTRUCTION_TYPE_ADD
INSTRUCTION_TYPE_XADD = C_INSTRUCTION_TYPE_XADD
INSTRUCTION_TYPE_ADC = C_INSTRUCTION_TYPE_ADC
INSTRUCTION_TYPE_SUB = C_INSTRUCTION_TYPE_SUB
INSTRUCTION_TYPE_SBB = C_INSTRUCTION_TYPE_SBB
INSTRUCTION_TYPE_INC = C_INSTRUCTION_TYPE_INC
INSTRUCTION_TYPE_DEC = C_INSTRUCTION_TYPE_DEC
INSTRUCTION_TYPE_DIV = C_INSTRUCTION_TYPE_DIV
INSTRUCTION_TYPE_IDIV = C_INSTRUCTION_TYPE_IDIV
INSTRUCTION_TYPE_NOT = C_INSTRUCTION_TYPE_NOT
INSTRUCTION_TYPE_NEG = C_INSTRUCTION_TYPE_NEG
INSTRUCTION_TYPE_STOS = C_INSTRUCTION_TYPE_STOS
INSTRUCTION_TYPE_LODS = C_INSTRUCTION_TYPE_LODS
INSTRUCTION_TYPE_SCAS = C_INSTRUCTION_TYPE_SCAS
INSTRUCTION_TYPE_MOVS = C_INSTRUCTION_TYPE_MOVS
INSTRUCTION_TYPE_MOVSX = C_INSTRUCTION_TYPE_MOVSX
INSTRUCTION_TYPE_MOVZX = C_INSTRUCTION_TYPE_MOVZX
INSTRUCTION_TYPE_CMPS = C_INSTRUCTION_TYPE_CMPS
INSTRUCTION_TYPE_SHX = C_INSTRUCTION_TYPE_SHX
INSTRUCTION_TYPE_ROX = C_INSTRUCTION_TYPE_ROX
INSTRUCTION_TYPE_MUL = C_INSTRUCTION_TYPE_MUL
INSTRUCTION_TYPE_IMUL = C_INSTRUCTION_TYPE_IMUL
INSTRUCTION_TYPE_EIMUL = C_INSTRUCTION_TYPE_EIMUL
INSTRUCTION_TYPE_XOR = C_INSTRUCTION_TYPE_XOR
INSTRUCTION_TYPE_LEA = C_INSTRUCTION_TYPE_LEA
INSTRUCTION_TYPE_XCHG = C_INSTRUCTION_TYPE_XCHG
INSTRUCTION_TYPE_CMP = C_INSTRUCTION_TYPE_CMP
INSTRUCTION_TYPE_TEST = C_INSTRUCTION_TYPE_TEST
INSTRUCTION_TYPE_PUSH = C_INSTRUCTION_TYPE_PUSH
INSTRUCTION_TYPE_AND = C_INSTRUCTION_TYPE_AND
INSTRUCTION_TYPE_OR = C_INSTRUCTION_TYPE_OR
INSTRUCTION_TYPE_POP = C_INSTRUCTION_TYPE_POP
INSTRUCTION_TYPE_JMP = C_INSTRUCTION_TYPE_JMP
INSTRUCTION_TYPE_JMPC = C_INSTRUCTION_TYPE_JMPC
INSTRUCTION_TYPE_JECXZ = C_INSTRUCTION_TYPE_JECXZ
INSTRUCTION_TYPE_SETC = C_INSTRUCTION_TYPE_SETC
INSTRUCTION_TYPE_MOVC = C_INSTRUCTION_TYPE_MOVC
INSTRUCTION_TYPE_LOOP = C_INSTRUCTION_TYPE_LOOP
INSTRUCTION_TYPE_CALL = C_INSTRUCTION_TYPE_CALL
INSTRUCTION_TYPE_RET = C_INSTRUCTION_TYPE_RET
INSTRUCTION_TYPE_ENTER = C_INSTRUCTION_TYPE_ENTER
INSTRUCTION_TYPE_INT = C_INSTRUCTION_TYPE_INT
INSTRUCTION_TYPE_BT = C_INSTRUCTION_TYPE_BT
INSTRUCTION_TYPE_BTS = C_INSTRUCTION_TYPE_BTS
INSTRUCTION_TYPE_BTR = C_INSTRUCTION_TYPE_BTR
INSTRUCTION_TYPE_BTC = C_INSTRUCTION_TYPE_BTC
INSTRUCTION_TYPE_BSF = C_INSTRUCTION_TYPE_BSF
INSTRUCTION_TYPE_BSR = C_INSTRUCTION_TYPE_BSR
INSTRUCTION_TYPE_BSWAP = C_INSTRUCTION_TYPE_BSWAP
INSTRUCTION_TYPE_SGDT = C_INSTRUCTION_TYPE_SGDT
INSTRUCTION_TYPE_SIDT = C_INSTRUCTION_TYPE_SIDT
INSTRUCTION_TYPE_SLDT = C_INSTRUCTION_TYPE_SLDT
INSTRUCTION_TYPE_LFP = C_INSTRUCTION_TYPE_LFP
INSTRUCTION_TYPE_CLD = C_INSTRUCTION_TYPE_CLD
INSTRUCTION_TYPE_STD = C_INSTRUCTION_TYPE_STD
INSTRUCTION_TYPE_XLAT = C_INSTRUCTION_TYPE_XLAT
INSTRUCTION_TYPE_FCMOVC = C_INSTRUCTION_TYPE_FCMOVC
INSTRUCTION_TYPE_FADD = C_INSTRUCTION_TYPE_FADD
INSTRUCTION_TYPE_FADDP = C_INSTRUCTION_TYPE_FADDP
INSTRUCTION_TYPE_FIADD = C_INSTRUCTION_TYPE_FIADD
INSTRUCTION_TYPE_FSUB = C_INSTRUCTION_TYPE_FSUB
INSTRUCTION_TYPE_FSUBP = C_INSTRUCTION_TYPE_FSUBP
INSTRUCTION_TYPE_FISUB = C_INSTRUCTION_TYPE_FISUB
INSTRUCTION_TYPE_FSUBR = C_INSTRUCTION_TYPE_FSUBR
INSTRUCTION_TYPE_FSUBRP = C_INSTRUCTION_TYPE_FSUBRP
INSTRUCTION_TYPE_FISUBR = C_INSTRUCTION_TYPE_FISUBR
INSTRUCTION_TYPE_FMUL = C_INSTRUCTION_TYPE_FMUL
INSTRUCTION_TYPE_FMULP = C_INSTRUCTION_TYPE_FMULP
INSTRUCTION_TYPE_FIMUL = C_INSTRUCTION_TYPE_FIMUL
INSTRUCTION_TYPE_FDIV = C_INSTRUCTION_TYPE_FDIV
INSTRUCTION_TYPE_FDIVP = C_INSTRUCTION_TYPE_FDIVP
INSTRUCTION_TYPE_FDIVR = C_INSTRUCTION_TYPE_FDIVR
INSTRUCTION_TYPE_FDIVRP = C_INSTRUCTION_TYPE_FDIVRP
INSTRUCTION_TYPE_FIDIV = C_INSTRUCTION_TYPE_FIDIV
INSTRUCTION_TYPE_FIDIVR = C_INSTRUCTION_TYPE_FIDIVR
INSTRUCTION_TYPE_FCOM = C_INSTRUCTION_TYPE_FCOM
INSTRUCTION_TYPE_FCOMP = C_INSTRUCTION_TYPE_FCOMP
INSTRUCTION_TYPE_FCOMPP = C_INSTRUCTION_TYPE_FCOMPP
INSTRUCTION_TYPE_FCOMI = C_INSTRUCTION_TYPE_FCOMI
INSTRUCTION_TYPE_FCOMIP = C_INSTRUCTION_TYPE_FCOMIP
INSTRUCTION_TYPE_FUCOM = C_INSTRUCTION_TYPE_FUCOM
INSTRUCTION_TYPE_FUCOMP = C_INSTRUCTION_TYPE_FUCOMP
INSTRUCTION_TYPE_FUCOMPP = C_INSTRUCTION_TYPE_FUCOMPP
INSTRUCTION_TYPE_FUCOMI = C_INSTRUCTION_TYPE_FUCOMI
INSTRUCTION_TYPE_FUCOMIP = C_INSTRUCTION_TYPE_FUCOMIP
INSTRUCTION_TYPE_FST = C_INSTRUCTION_TYPE_FST
INSTRUCTION_TYPE_FSTP = C_INSTRUCTION_TYPE_FSTP
INSTRUCTION_TYPE_FIST = C_INSTRUCTION_TYPE_FIST
INSTRUCTION_TYPE_FISTP = C_INSTRUCTION_TYPE_FISTP
INSTRUCTION_TYPE_FISTTP = C_INSTRUCTION_TYPE_FISTTP
INSTRUCTION_TYPE_FLD = C_INSTRUCTION_TYPE_FLD
INSTRUCTION_TYPE_FILD = C_INSTRUCTION_TYPE_FILD
INSTRUCTION_TYPE_FICOM = C_INSTRUCTION_TYPE_FICOM
INSTRUCTION_TYPE_FICOMP = C_INSTRUCTION_TYPE_FICOMP
INSTRUCTION_TYPE_FFREE = C_INSTRUCTION_TYPE_FFREE
INSTRUCTION_TYPE_FFREEP = C_INSTRUCTION_TYPE_FFREEP
INSTRUCTION_TYPE_FXCH = C_INSTRUCTION_TYPE_FXCH
INSTRUCTION_TYPE_SYSENTER = C_INSTRUCTION_TYPE_SYSENTER
INSTRUCTION_TYPE_FPU_CTRL = C_INSTRUCTION_TYPE_FPU_CTRL
INSTRUCTION_TYPE_FPU = C_INSTRUCTION_TYPE_FPU
INSTRUCTION_TYPE_MMX = C_INSTRUCTION_TYPE_MMX
INSTRUCTION_TYPE_SSE = C_INSTRUCTION_TYPE_SSE
INSTRUCTION_TYPE_OTHER = C_INSTRUCTION_TYPE_OTHER
INSTRUCTION_TYPE_PRIV = C_INSTRUCTION_TYPE_PRIV

OPERAND_TYPE_NONE = C_OPERAND_TYPE_NONE
OPERAND_TYPE_MEMORY = C_OPERAND_TYPE_MEMORY
OPERAND_TYPE_REGISTER = C_OPERAND_TYPE_REGISTER
OPERAND_TYPE_IMMEDIATE = C_OPERAND_TYPE_IMMEDIATE

REGISTER_EAX = C_REGISTER_EAX
REGISTER_ECX = C_REGISTER_ECX
REGISTER_EDX = C_REGISTER_EDX
REGISTER_EBX = C_REGISTER_EBX
REGISTER_ESP = C_REGISTER_ESP
REGISTER_EBP = C_REGISTER_EBP
REGISTER_ESI = C_REGISTER_ESI
REGISTER_EDI = C_REGISTER_EDI
REGISTER_NOP = C_REGISTER_NOP

REGISTER_TYPE_GEN = C_REGISTER_TYPE_GEN
REGISTER_TYPE_SEGMENT = C_REGISTER_TYPE_SEGMENT
REGISTER_TYPE_DEBUG = C_REGISTER_TYPE_DEBUG
REGISTER_TYPE_CONTROL = C_REGISTER_TYPE_CONTROL
REGISTER_TYPE_TEST = C_REGISTER_TYPE_TEST
REGISTER_TYPE_XMM = C_REGISTER_TYPE_XMM
REGISTER_TYPE_MMX = C_REGISTER_TYPE_MMX
REGISTER_TYPE_FPU = C_REGISTER_TYPE_FPU

FORMAT_ATT = C_FORMAT_ATT
FORMAT_INTEL = C_FORMAT_INTEL

MODE_16 = C_MODE_16
MODE_32 = C_MODE_32

cdef class Operand:
    cdef OPERAND * raw

    property type:
        def __get__(self):
            return self.raw.type

    property reg:
        def __get__(self):
            return self.raw.reg

    property basereg:
        def __get__(self):
            return self.raw.basereg

    property indexreg:
        def __get__(self):
            return self.raw.indexreg

    property scale:
        def __get__(self):
            return self.raw.scale

    property dispbytes:
        def __get__(self):
            return self.raw.dispbytes

    property dispoffset:
        def __get__(self):
            return self.raw.dispoffset

    property immbytes:
        def __get__(self):
            return self.raw.immbytes

    property immoffset:
        def __get__(self):
            return self.raw.immoffset

    property sectionbytes:
        def __get__(self):
            return self.raw.sectionbytes

    property section:
        def __get__(self):
            return self.raw.section

    property displacement:
        def __get__(self):
            return self.raw.displacement

    property immediate:
        def __get__(self):
            return self.raw.immediate

    property flags:
        def __get__(self):
            return self.raw.flags


cdef class Instruction:
    cdef INSTRUCTION raw

    property length:
        def __get__(self):
            return self.raw.length

    property type:
        def __get__(self):
            return self.raw.type

    property mode:
        def __get__(self):
            return self.raw.mode

    property opcode:
        def __get__(self):
            return self.raw.opcode

    property modrm:
        def __get__(self):
            return self.raw.modrm

    property sib:
        def __get__(self):
            return self.raw.sib

    property modrm_offset:
        def __get__(self):
            return self.raw.modrm_offset

    property extindex:
        def __get__(self):
            return self.raw.extindex

    property fpuindex:
        def __get__(self):
            return self.raw.fpuindex

    property dispbytes:
        def __get__(self):
            return self.raw.dispbytes

    property immbytes:
        def __get__(self):
            return self.raw.immbytes

    property sectionbytes:
        def __get__(self):
            return self.raw.sectionbytes

    property flags:
        def __get__(self):
            return self.raw.flags

    property eflags_affected:
        def __get__(self):
            return self.raw.eflags_affected

    property eflags_used:
        def __get__(self):
            return self.raw.eflags_used

    property iop_written:
        def __get__(self):
            return self.raw.iop_written

    property iop_read:
        def __get__(self):
            return self.raw.iop_read

    cdef public:
        Operand op1
        Operand op2
        Operand op3

    def __init__(self):
        self.op1 = Operand()
        self.op1.raw = &self.raw.op1
        self.op2 = Operand()
        self.op2.raw = &self.raw.op2
        self.op3 = Operand()
        self.op3.raw = &self.raw.op3


DEF STR_BUFFER_SIZE = 256


def get_instruction(bytes buf, AddressingMode mode):
    """
    Decode an instruction from the given buffer.

    Takes in a string containing the data to disassemble and the mode,
    either MODE_16 or MODE_32. Returns an Instruction object or None if
    the instruction can't be disassembled.
    """

    cdef Instruction inst = Instruction()
    cdef char * data = buf
    size = get_instruction_c(&inst.raw, <unsigned char*>(data), mode)
    if not size:
        return None
    return inst


def get_instruction_string(Instruction inst, DisassemblingFormat format,
                           unsigned long int offset):
    """
    Transform an instruction object into its string representation.

    The function takes an Instruction object; its format, either
    FORMAT_INTEL or FORMAT_ATT and finally an offset (refer to
    libdasm for meaning). Returns a string representation of the
    disassembled instruction.
    """
    cdef char data[STR_BUFFER_SIZE]
    
    if not get_instruction_string_c(&inst.raw, format, offset, <char*>(&data),
                                    STR_BUFFER_SIZE):
        return None
    cdef str value = data.decode('utf-8')
    return value


def get_mnemonic_string(Instruction inst, DisassemblingFormat format):
    """
    Transform an instruction object's mnemonic into its string representation.

    The function takes an Instruction object and its format, either
    FORMAT_INTEL or FORMAT_ATT. Returns a string representation of the
    mnemonic.
    """
    cdef char data[STR_BUFFER_SIZE]
    get_mnemonic_string_c(&inst.raw, format, <char*>(&data),
                          STR_BUFFER_SIZE)
    cdef str value = data.decode('utf-8')
    return value


def get_operand_string(Instruction inst, int op_idx,
                       DisassemblingFormat format, unsigned int offset):
    """
    Transform an instruction object's operand into its string representation.

    The function takes an Instruction object; the operand index (0,1,2);
    its format, either FORMAT_INTEL or FORMAT_ATT and finally an offset
    (refer to libdasm for meaning). Returns a string representation of
    the disassembled operand.
    """
    cdef char data[STR_BUFFER_SIZE]
    
    if not get_operand_string_c(&inst.raw, &(inst.raw.op1)+op_idx,
                                format, offset, <char*>(&data),
                                STR_BUFFER_SIZE):
        return None
    
    cdef str value = data.decode('utf-8')
    return value

def get_register_type(Operand op):
    """
    Get the type of the register used by the operand.

    The function takes an Operand object and returns a Long representing
    the type of the register.
    """
    return get_register_type_c(op.raw)
