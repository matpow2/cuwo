import os
import subprocess

spill = ['r12', 'r13', 'r14', 'r15']
arg_order = ['rdi', 'rsi', 'rdx', 'rcx', 'r8', 'r9']
arg_order_msvc = ['rcx', 'rdx', 'r8', 'r9']
arg_order_double = ['xmm0', 'xmm1', 'xmm2', 'xmm3']

preserve_call = ['rbp', 'rbx']
preserve_call_msvc = ['rdi', 'rsi'] + preserve_call

# volatile x64 msvc: RAX, RCX, RDX, R8-R11
# non-volatile x64 msvc: RDI, RSI, RBX, RBP, RSP, R12-R15

# non-volatile x64: RSP, RBP, RBX, R12-R15

# volatile: EAX, ECX, EDX, ST0 - ST7, ES and GS
# non-volatile: EBX, EBP, ESP, EDI, ESI, CS and DS
# save on non-msvc: EDI, ESI

# all x64 registers are cut to their 32bit parts when going from
# 64bit -> 32bit, so need to preserve all non-volatiles
# msvc: rdi, rsi, rbx
# non-msvc: rbx

arg_map = {}
arg_map_msvc = {}

for i in range(6):
    for (m, o) in ((arg_map, arg_order), (arg_map_msvc, arg_order_msvc)):
        try:
            m['arg' + str(i)] = o[i]
        except IndexError:
            pass

x86_call_base = '''

macro X86_Start
{
use64
    call   $+5
    a:
    mov    dword [rsp + 4], 0x23
    add    dword [rsp], b - a
use32
    retf
    b:
}

Macro X86_End
{
use32
    push 0x33
    call $+5
    add dword [esp], 5
    retf
use64
}
'''

asm_template = '''

macro X64_Start
{
    LOCAL a, b
use32
    push 0x33
    call $+5
    a:
    add dword [esp], b - a
    retf
    b:
use64
}

Macro X64_End
{
    local c, d
use64
    call $+5
    c:
    mov dword [rsp+4], 0x23
    add dword [rsp], d - c
use32
    retf
    d:
}

'''

class state:
    is_msvc = False
    output_c = ''

temp_bin_path = os.path.join(os.path.dirname(__file__), 'temp.bin')
temp_asm_path = os.path.join(os.path.dirname(__file__), 'temp.asm')

for path in ('fasm/FASM.exe', 'fasm/fasm.x64', 'fasm/fasm'):
    fasm_path = os.path.join(os.path.dirname(__file__), path)
    if not os.path.isfile(fasm_path):
        continue

def get_asm(asm):
    with open(temp_asm_path, 'w', encoding='utf-8') as fp:
        fp.write(asm)
    subprocess.run([fasm_path, temp_asm_path, temp_bin_path], check=True)
    with open(temp_bin_path, 'rb') as fp:
        data = fp.read()
    return data

import textwrap
def encode_c(data):
    out = ''
    out += f'{{\n'
    vals = []
    for c in data:
        vals.append(hex(c))
    vals = ', '.join(vals)
    vals = '\n'.join(textwrap.wrap(vals))
    out += vals + '\n};'
    return out

def get_c_type(typ):
    if typ == 'double':
        return 'double'
    return 'uint32_t'

def add_func(name, patch, table, callconv, func_prot):
    if name == 'ignore':
        print('skipping', func_prot)
    func_prot = func_prot.replace('*', ' * ')
    decl, args = func_prot.split('(')
    split = decl.rsplit()
    func_name = split[-1]
    ret = ' '.join(split[:-1])
    args = args.split(')')[0].split(',')
    args = [' '.join(arg.rsplit()[:-1]) for arg in args]
    if len(args) == 1 and not args[0]:
        args = []

    arg_off = 0
    if callconv == 'thiscall':
        arg_off = 1

    if is_x64:
        asm = asm_template
        asm += f'{func_name}_wrap:\n'
        asm += f'    X64_Start\n'
        asm += f'    use64\n'
        push_off = 12
        if state.is_msvc:
            cur_arg_order = arg_order_msvc
        else:
            cur_arg_order = arg_order

        asm += f'    push r12\n'
        if not state.is_msvc:
            asm += f'    push rdi\n'
            asm += f'    push rsi\n'
            push_off += 8*2
        asm += f'    mov r12, rsp\n'

        if callconv == 'thiscall':
            dest = cur_arg_order[0]
            if dest != 'rcx':
                asm += f'    mov {dest}, rcx\n'
        asm += f'    and esp, 0xFFFFFFF0\n'
        pushes = 0
        asm_arg = ''
        for i in range(len(args)-arg_off):
            if args[i+arg_off] == 'double':
                continue
            try:
                reg = cur_arg_order[i+arg_off]
                asm_arg += f'    mov {reg}, [r12+{push_off+i*4}]\n'
            except IndexError:
                pushes += 1
                asm_arg += f'    push qword [r12+{push_off+i*4}]\n'

        rsp_sub = 128 # red zone
        if pushes % 2 == 1:
            rsp_sub += 8
        asm += f'    sub rsp, {rsp_sub}\n' # red zone
        asm += asm_arg
        asm += f'    mov rax, 0x1122334455667788\n'
        asm += f'    call rax\n'
        asm += f'    mov rsp, r12\n'

        if not state.is_msvc:
            asm += f'    pop rsi\n'
            asm += f'    pop rdi\n'

        asm += f'    pop r12\n'
        asm += f'    X64_End\n'
        asm += f'    use32\n'
        if callconv in ('stdcall', 'thiscall'):
            asm += f'    ret {(len(args)-arg_off)*4}\n'
        else:
            asm += f'    ret\n'

        # if not state.is_msvc and state.is_x64:
        #     print(asm)
        #     input()
        asm = get_asm(asm)
        asm = encode_c(asm)
        asm_c = f'static unsigned char {func_name}_asm[] = \n' + asm + '\n\n'
        state.output_c += asm_c

    if patch is not None or table is not None:
        patch = patch or 0
        table = table or 0
        state.patches.append((patch, table, func_name))
    else:
        state.asm.append((name, func_name))

    extract_this = (callconv == 'thiscall' and not state.is_x64)
    c_args = [f'{get_c_type(args[i])} v{i}' for i in range(len(args))]
    if extract_this:
        c_args.insert(1, 'uint32_t pad')
    c_args = ', '.join(c_args)
    if ret == 'void':
        c_ret = 'void'
    else:
        c_ret = get_c_type(ret)

    c_ret_final = c_ret
    if not state.is_x64:
        c_ret_final = c_ret_final + ' ' + 'TGEN_' + callconv.upper()
    state.output_c += f'static {c_ret_final} {func_name}_wrapc({c_args})\n'
    state.output_c += f'{{\n'
    print_name = name
    if not print_name:
        print_name = func_name
    c_args_call = [f'({args[i]})v{i}' for i in range(len(args))]
    c_args_call = ', '.join(c_args_call)
    call = f'{func_name}({c_args_call})'
    ret_code = None
    if c_ret == 'void':
        state.output_c += f'    {call};\n'
    else:
        ret_code = '    return ret_val;\n'
        state.output_c += f'    {c_ret} ret_val = ({c_ret}){call};\n'
    
    if name != '_setjmp3':
        # state.output_c += f'#ifndef NDEBUG\n'
        state.output_c += f'#ifdef VERBOSE_WRAP\n'

        print_args = [f' << " " << v{i} ' for i in range(len(args))]
        print_args = ''.join(print_args)
        state.output_c += f"    std::cout << \"{print_name}\" "
        state.output_c += f"{print_args}<< "
        if ret_code is not None:
            state.output_c += f' " -> " << ret_val << '
        state.output_c += "'\\n';\n"
        state.output_c += f'#endif\n'
    if ret_code is not None:
        state.output_c += ret_code
    state.output_c += f'}}\n\n'

    print(name, patch, ret, args)

def do_lines(lines):
    name = ''
    callconv = 'cdecl'
    func_prot = ''
    patch = None
    table = None
    has_func = False
    for line in lines:
        line = line.strip()
        if line.startswith('// stdcall'):
            callconv = 'stdcall'
        elif line.startswith('// vectorcall'):
            callconv = 'vectorcall'
        elif line.startswith('// thiscall'):
            callconv = 'thiscall'
        elif line.startswith('// import:'):
            name += line.split(':', 1)[1].strip()
            has_func = True
        elif line.startswith('// patch:'):
            patch = line.split(':', 1)[1].strip()
            has_func = True
        elif line.startswith('// table:'):
            table = line.split(':', 1)[1].strip()
            has_func = True
        elif has_func and not line.startswith('//'):
            func_prot += line

        if has_func and ')' in func_prot:
            add_func(name, patch, table, callconv, func_prot)
            name = ''
            callconv = 'cdecl'
            func_prot = ''
            patch = None
            table = None
            has_func = False

def do_callers():
    if state.is_msvc:
        cur_arg_order = arg_order_msvc
        save_regs = preserve_call_msvc
    else:
        cur_arg_order = arg_order
        save_regs = preserve_call

    imports = []
    setup_callers = '#define SETUP_CALLERS()'
    for callconv in ('thiscall', 'cdecl', 'stdcall'):
        for i in range(5):
            asm = x86_call_base
            asm += f'start:\n'
            asm += f'use64\n'
            asm += f'mov rax, {cur_arg_order[0]}\n'

            spill_order = ['r10', 'r11']
            def get_reg(reg):
                is_spill = False
                try:
                    reg = cur_arg_order[reg]
                except IndexError:
                    return ('r10d', True)
                if len(reg) == 2 or is_spill:
                    reg += 'd'
                else:
                    reg = 'e' + reg[1:]
                return (reg, False)

            arg_asm = ''
            pop_args = 0
            thiscall_prolog = None
            if callconv == 'thiscall':
                arg_off = 1
            spilled_args = max(0, (i + 1) - len(cur_arg_order))
            for arg in range(i):
                mov_reg, is_spill = get_reg(arg+1)
                if arg == 0 and callconv == 'thiscall':
                    if mov_reg != 'ecx':
                        thiscall_prolog = f'mov ecx, {mov_reg}\n'
                else:
                    arg_pos = (i - 1 - arg_off) - (arg - arg_off)
                    if is_spill:
                        spill_off = (arg + 1) - len(cur_arg_order)
                        spill_off += len(save_regs)
                        if state.is_msvc:
                            # safe area
                            spill_off += 4
                        spill_off += 1 # return address
                        arg_asm += f'mov r10, [rsp+{spill_off*8}]\n'
                    arg_asm += f'mov dword [rsp-{(arg_pos+1)*4}], {mov_reg}\n'
                    pop_args += 1

            if pop_args > 0:
                arg_asm += f'lea rsp, [rsp-{pop_args*4}]\n'

            save_regs = list(save_regs)
            for reg in save_regs:
                asm += f'push {reg}\n'

            asm += arg_asm
            if thiscall_prolog is not None:
                asm += thiscall_prolog

            asm += f'X86_Start\n'
            if not state.is_msvc:
                for seg in ('ds', 'es'):
                    asm += f'push 0x2b\n'
                    asm += f'pop {seg}\n'
            asm += f'call eax\n'
            asm += f'X86_End\n'

            if callconv == 'cdecl':
                if pop_args > 0:
                    arg_asm += f'lea rsp, [rsp+{pop_args*4}]\n'
            for reg in reversed(save_regs):
                asm += f'pop {reg}\n'
            asm += f'ret\n'

            # if callconv == 'thiscall' and state.is_msvc and state.is_x64 and i == 3:
            #     print(asm)
            #     input()
            # if spilled_args > 0:
            #     print(asm)
            #     input()
            name = f'call_x86_{callconv}_{i}'
            asm = get_asm(asm)
            asm = encode_c(asm)
            c_args = ['void*'] + ['uint32_t'] * i
            c_args = ', '.join(c_args)


            state.output_c += f'uint32_t (*{name})({c_args});\n'
            state.output_h += f'extern uint32_t (*{name})({c_args});\n'
            state.output_c += f'unsigned char {name}_asm[] = {asm}\n\n'
            imports.append(f'{{"{name}", '
                           f'Import{{&{name}_asm[0], sizeof {name}_asm, '
                           f'NULL}}}}')
            setup_callers += '\\\n{\\\n'
            setup_callers += f'Import & imp = imports["{name}"];\\\n'
            setup_callers += (f'void * f = load_x86(imp.asm_data, '
                              f'imp.asm_size);\\\n')
            setup_callers += (f'{name} = (uint32_t (*)({c_args}))f;\\\n')
            setup_callers += '}'

    state.output_c += setup_callers + '\n\n'
    return imports

for (is_msvc, is_x64) in ((True, True), (False, True),
                          (True, False), (False, False)):
    state.is_msvc = is_msvc
    state.is_x64 = is_x64
    state.asm = []
    state.patches = []
    state.output_c = '#include "import/import.h"\n'
    state.output_h = ''

    import_dir = os.path.join(os.path.dirname(__file__), '..', 'src', 'import')
    for f in os.listdir(import_dir):
        if f not in ('base.h', 'sqlite.h', 'ios.h'):
            continue
        code_path = os.path.join(import_dir, f)

        with open(code_path, 'r', encoding='utf-8') as fp:
            lines = fp.readlines()

        do_lines(lines)

    if is_x64:
        imports = [(f'{{"{name}", '
                    f'Import{{&{func}_asm[0], sizeof {func}_asm, '
                            f'(void*)&{func}_wrapc}}}}')
                    for (name, func) in state.asm]

        imports += do_callers()

        patches = [(f'Patch{{&{func}_asm[0], sizeof {func}_asm, '
                             f'(void*)&{func}_wrapc, {patch},'
                             f'{table}}}')
                    for (patch, table, func) in state.patches]
    else:
        imports = [(f'{{"{name}", '
                    f'Import{{(void*)&{func}_wrapc}}}}')
                    for (name, func) in state.asm]

        patches = [(f'Patch{{(void*)&{func}_wrapc, {patch}, {table}}}')
                    for (patch, table, func) in state.patches]

    imports = ',\n'.join(imports)
    patches = ',\n'.join(patches)
    state.output_c += (f'std::unordered_map<std::string, Import> imports(\n'
                       f'{{\n{imports}\n}}\n);')

    state.output_c += (f'std::vector<Patch> patches(\n'
                       f'{{\n{patches}\n}}\n);')

    name = 'wrapper'
    if is_msvc:
        name += '_msvc'
    if is_x64:
        name += '_x64'
    cpp_filename = os.path.join(os.path.dirname(__file__), name + '.cpp')
    h_filename = os.path.join(os.path.dirname(__file__), name + '.h')

    with open(cpp_filename, 'w', encoding='utf-8') as fp:
        fp.write(state.output_c)
    with open(h_filename, 'w', encoding='utf-8') as fp:
        fp.write(state.output_h)
