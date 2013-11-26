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

#ifndef TERRAINGEN_IOS_H
#define TERRAINGEN_IOS_H

#include <sstream>

// structs

#define BUF_SIZE_CHAR 16

// XXX fix for big-endian

struct basic_string_char
{
    union {
        uint8_t buf[BUF_SIZE_CHAR];
        uint32_t ptr;
    };
    uint32_t size;
    uint32_t res; // capacity

    void reset()
    {
        size = 0;
        res = 15;
    }

    char * get()
    {
        if (size < BUF_SIZE_CHAR)
            return (char*)&buf;
        return mem.translate(ptr);
    }

    std::string str()
    {
        return std::string(get(), size);
    }
};

std::stringstream * current_stream = NULL;

void basic_istream_char_ctor_imp()
{
    pop_ret();
    uint32_t self = get_self();
    uint32_t strbuf = cpu.pop_dword();
    uint32_t isstd = cpu.pop_dword();
    uint32_t virt_init = cpu.pop_dword();
    ret_self();
    // std::cout << "basic_istream_char_ctor" << std::endl;
}

void basic_streambuf_char_ctor_imp()
{
    pop_ret();
    uint32_t self = get_self();
    // std::cout << "basic_streambuf_char_ctor" << std::endl;
    ret_self();
}

void basic_streambuf_char__Init_empty_imp()
{
    pop_ret();
    uint32_t self = get_self();
    // std::cout << "basic_streambuf_char__Init_empty" << std::endl;
}

void basic_ios_char_setstate_reraise_imp()
{
    pop_ret();
    uint32_t self = get_self();
    uint32_t state = cpu.pop_dword();
    uint32_t reraise = cpu.pop_dword();
    // std::cout << "basic_ios_char_setstate_reraise" << std::endl;
}

void basic_streambuf_char_dtor_imp()
{
    pop_ret();
    uint32_t self = get_self();
    // std::cout << "basic_streambuf_char_dtor" << std::endl;
}

void basic_istream_char_dtor_imp()
{
    pop_ret();
    uint32_t self = get_self();
    // std::cout << "basic_istream_char_dtor" << std::endl;
}

void basic_ios_char_dtor_imp()
{
    pop_ret();
    uint32_t self = get_self();
    // std::cout << "basic_ios_char_dtor" << std::endl;
}

enum ShareFlags
{
    SHARE_COMPAT = 0x00,
    SHARE_DENYRW = 0x10,
    SHARE_DENYWR = 0x20,
    SHARE_DENYRD = 0x30,
    SHARE_DENYNO = 0x40
};

enum OpenModes
{
    OPEN_IN = 0x01,
    OPEN_OUT = 0x02,
    OPEN_ATE = 0x04,
    OPEN_APPEND = 0x08,
    OPEN_TRUNCATE = 0x10,
    OPEN_NOCREATE = 0x40,
    OPEN_NOREPLACE = 0x80,
    OPEN_BINARY = 0x20,
    OPEN_MASK = 0xff
};

inline std::string get_open_mode(int mode)
{
    std::string val;
    if (mode & OPEN_IN)
        val += "r";
    if (mode & OPEN_OUT)
        val += "w";
    if (mode & OPEN_BINARY)
        val += "b";
    if (mode & OPEN_APPEND)
        val += "a";
    return val;
}

void _Fiopen_imp()
{
    pop_ret();
    char * name = mem.translate(cpu.get_dword(0));
    uint32_t mode = cpu.get_dword(4);
    uint32_t prot = cpu.get_dword(8);
    set_ret(0);
    // std::cout << "_Fiopen: " << name << " " << get_open_mode(mode) << " " 
    //     << mode << " " << prot << std::endl;
    // returns FILE*
}

extern uint32_t get_seed();

void basic_istream_char_read_int_imp()
{
    pop_ret();
    uint32_t * v = (uint32_t*)mem.translate(cpu.pop_dword());
    // let's just give it a seed
    *v = get_seed();
    ret_self();
    // std::cout << "basic_istream_char_read_int" << std::endl;
}

void basic_ios_char_ctor_imp()
{
    pop_ret();
    ret_self();
    // std::cout << "basic_ios_char_ctor" << std::endl;
}

void basic_iostream_char_ctor_imp()
{
    pop_ret();
    uint32_t strbuf = cpu.pop_dword();
    uint32_t virtinit = cpu.pop_dword();
    // hack: use vtable space to create a pointer in host space
    uint32_t base = get_self();
    delete current_stream;
    current_stream = new std::stringstream;
    // inlined destructors depend on these
    // mem.write_dword(base, base);
    // mem.write_dword(base+4, 4);
    mem.write_dword(base+36, base+36);
    mem.write_dword(base+40, base+40);
    mem.write_dword(base+52, base+52);
    mem.write_dword(base+56, base+56);
    mem.write_dword(base+68, base+68);
    mem.write_dword(base+72, base+72); // returned in 4CE900
    ret_self();
    // std::cout << "basic_iostream_char_ctor" << std::endl;
}

void basic_iostream_char_dtor_imp()
{
    pop_ret();
    delete current_stream;
    current_stream = NULL;
    // std::cout << "basic_iostream_char_ctor" << std::endl;
}

void ios_base_Ios_base_dtor_imp()
{
    pop_ret();
    uint32_t obj = cpu.get_dword(0);
    // std::cout << "ios_base_Ios_base_dtor" << std::endl;
}

void basic_streambuf_char_sputn_imp()
{
    pop_ret();
    char * ptr = mem.translate(cpu.pop_dword());
    uint64_t size = cpu.pop_qword();
    std::string value(ptr, int(size));
    set_ret(size);
    std::cout << "basic_streambuf_char_sputn: " << value << std::endl;
}

void __uncaught_exception_imp()
{
    // probably safe, seems to be called in IDA too
    // wine *always* returns false, so should be fine
    pop_ret();
    set_ret(0);
    std::cout << "__uncaught_exception, this is fine" << std::endl;
}

void basic_ostream_char__Osfx_imp()
{
    // flush ostream?
    pop_ret();
    std::cout << "basic_ostream_char__Osfx" << std::endl;
}

void basic_ostream_char_print_int_imp()
{
    pop_ret();
    int32_t val = (int32_t)cpu.pop_dword();
    std::stringstream & str = *current_stream;
    str << val;
    ret_self();
    // std::cout << "basic_ostream_char_print_int: " << val << std::endl;
}

void basic_streambuf_char_setg_imp()
{
    pop_ret();
    uint32_t self = get_self();
    uint32_t first = cpu.pop_dword();
    uint32_t next = cpu.pop_dword();
    uint32_t last = cpu.pop_dword();
    if (first != 0 || next != 0 || last != 0)
        std::cout << "Cannot setg" << std::endl;
    // std::cout << "basic_streambuf_char_setg" << std::endl;
}

// ostream_writecstr
void sub_4120D0()
{
    pop_ret();
    uint32_t stream = cpu.get_dword(0);
    std::stringstream & str = *current_stream;
    char * value = mem.translate(cpu.get_dword(4));
    str << value;
    set_ret(stream);
    // std::cout << "ostream_writecstr: " << value << std::endl;
}

// ostream_writestr
void sub_4C6970()
{
    pop_ret();
    uint32_t stream = cpu.get_dword(0);
    std::stringstream & str = *current_stream;
    uint32_t val = cpu.get_dword(4);
    basic_string_char * v = (basic_string_char*)mem.translate(val);
    // std::cout << "ostream_writestr: " << v->str() << std::endl;
    str << v->str();
    set_ret(stream);
}

// copy_iostream_to_str
void sub_4D8B70()
{
    pop_ret();
    uint32_t stream = get_self();
    std::stringstream & str = *current_stream;
    uint32_t stdstring = cpu.pop_dword();
    // need to initialize str since it hasn't been done already
    ((basic_string_char*)mem.translate(stdstring))->reset();

    // move string to guest space
    std::string res = str.str();
    uint32_t str_guest = mem.heap_alloc(res.size());
    memcpy(mem.translate(str_guest), &res[0], res.size());

    // use address 401A00, which is create_string_from_cstr
    // signature: string * __thiscall f(char* str, int size)
    get_self() = stdstring;
    cpu.push_dword(res.size());
    cpu.push_dword(str_guest);
    add_ret();
    sub_401A00();

    mem.heap_dealloc(str_guest);

    set_ret(stdstring);

    // std::cout << "copy_iostream_to_str: " << res << std::endl;
}

#endif // TERRAINGEN_IOS_H
