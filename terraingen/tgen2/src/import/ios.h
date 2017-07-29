/*
    Copyright (c) Mathias Kaerlev 2013-2017.

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
#include "msvcstring.h"
#include "config.h"

// structs

static thread_local std::stringstream * current_stream = NULL;

// import: public: __thiscall std::basic_istream<char,struct std::char_traits
// import: <char> >::basic_istream<char,struct std::char_traits<char> >
// import: (class std::basic_streambuf<char,struct std::char_traits<char> > *,
// import: bool)
// thiscall
uint32_t basic_istream_char_ctor_imp(uint32_t self, uint32_t strbuf,
                                     uint32_t isstd, uint32_t virt_init)
{
    // std::cout << "basic_istream_char_ctor_imp\n";
    return self;
}

// import: protected: __thiscall std::basic_streambuf
// import: <char,struct std::char_traits<char> >::basic_streambuf
// import: <char,struct std::char_traits<char> >(void)
// thiscall
uint32_t basic_streambuf_char_ctor_imp(uint32_t self)
{
    // std::cout << "basic_streambuf_char_ctor_imp\n";
    return self;
}

// import: protected: void __thiscall std::basic_streambuf
// import: <char,struct std::char_traits<char> >::_Init(void)
// thiscall
void basic_streambuf_char__Init_empty_imp(uint32_t self)
{
    // std::cout << "basic_streambuf_char__Init_empty" << std::endl;
}

static thread_local bool last_was_cfg = false;

// import: public: void __thiscall std::basic_ios
// import: <char,struct std::char_traits<char> >::setstate(int,bool)
// thiscall
void basic_ios_char_setstate_reraise_imp(uint32_t self, uint32_t state,
                                         uint32_t reraise)
{
    // std::cout << "basic_ios_char_setstate_reraise" << std::endl;
    if (last_was_cfg) {
        last_was_cfg = false;
        *(uint32_t*)(self + 0xC) = 0;
        return;
    }
    *(uint32_t*)(self + 0xC) = state;
}

// import: public: virtual __thiscall std::basic_streambuf
// import: <char,struct std::char_traits<char> >::~basic_streambuf
// import: <char,struct std::char_traits<char> >(void)
// thiscall
void basic_streambuf_char_dtor_imp(uint32_t self)
{
    // std::cout << "basic_streambuf_char_dtor" << std::endl;
}

// import: public: virtual __thiscall std::basic_istream
// import: <char,struct std::char_traits<char> >::~basic_istream
// import: <char,struct std::char_traits<char> >(void)
// thiscall
void basic_istream_char_dtor_imp(uint32_t self)
{
    // std::cout << "basic_istream_char_dtor" << std::endl;
}

// import: public: virtual __thiscall std::basic_ios
// import: <char,struct std::char_traits<char> >::~basic_ios
// import: <char,struct std::char_traits<char> >(void)
// thiscall
void basic_ios_char_dtor_imp(uint32_t self)
{
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

// import: struct _iobuf * __cdecl std::_Fiopen(char const *,int,int)
uint32_t _Fiopen_imp(char * name, uint32_t mode, uint32_t prot)
{
    unsigned int size = strlen(name);
    if (name[size-3] == 'c' && name[size-2] == 'f' && name[size - 1] == 'g') {
        last_was_cfg = true;
        return 0;
    }
    // std::cout << "_Fiopen: " << name << " " << get_open_mode(mode) << " "
    //     << mode << " " << prot << std::endl;
    return 0;
    // returns FILE*
}

extern uint32_t get_seed();

// import: public: class std::basic_istream
// import: <char,struct std::char_traits
// import: <char> > & __thiscall std::basic_istream
// import: <char,struct std::char_traits<char> >::operator>>(int &)
// thiscall
uint32_t basic_istream_char_read_int_imp(uint32_t self, uint32_t * v)
{
    // let's just give it a seed
    // std::cout << "basic_istream_char_read_int" << std::endl;
    *v = get_seed();
    return self;
}

// import: protected: __thiscall std::basic_ios
// import: <char,struct std::char_traits<char> >::basic_ios
// import: <char,struct std::char_traits<char> >(void)
// thiscall
uint32_t basic_ios_char_ctor_imp(uint32_t self)
{
    // std::cout << "basic_ios_char_ctor" << std::endl;
    return self;
}

// import: public: __thiscall std::basic_iostream
// import: <char,struct std::char_traits<char> >::basic_iostream
// import: <char,struct std::char_traits<char> >(class std::basic_streambuf
// import: <char,struct std::char_traits<char> > *)
// thiscall
uint32_t basic_iostream_char_ctor_imp(uint32_t self, uint32_t strbuf,
                                      uint32_t virtinit)
{
    // hack: use vtable space to create a pointer in host space
    // std::cout << "basic_iostream_char_ctor" << std::endl;
    uint32_t base = self;
    delete current_stream;
    current_stream = new std::stringstream;
    // inlined destructors depend on these
    // mem.write_dword(base, base);
    // mem.write_dword(base+4, 4);
    *(uint32_t*)(base+36) = base + 36;
    *(uint32_t*)(base+40) = base + 40;
    *(uint32_t*)(base+52) = base + 52;
    *(uint32_t*)(base+56) = base + 56;
    *(uint32_t*)(base+68) = base + 68;
    *(uint32_t*)(base+72) = base + 72; // returned in 4CE900
    return self;
}

// import: public: virtual __thiscall std::basic_iostream
// import: <char,struct std::char_traits<char> >::~basic_iostream
// import: <char,struct std::char_traits<char> >(void)
// thiscall
void basic_iostream_char_dtor_imp(uint32_t self)
{
    // std::cout << "basic_iostream_char_dtor" << std::endl;
    delete current_stream;
    current_stream = NULL;
}

// import: private: static void __cdecl std::ios_base::_Ios_base_dtor
// import: (class std::ios_base *)
void ios_base_Ios_base_dtor_imp(uint32_t obj)
{
    // std::cout << "ios_base_Ios_base_dtor" << std::endl;
}

// import: public: __int64 __thiscall std::basic_streambuf
// import: <char,struct std::char_traits<char> >::sputn(char const *,__int64)
// thiscall
uint64_t basic_streambuf_char_sputn_imp(uint32_t self, char * ptr,
                                        uint64_t size)
{
    abort();
    std::string value(ptr, int(size));
    // std::cout << "basic_streambuf_char_sputn: " << value << std::endl;
    return size;
}

// import: __uncaught_exception
uint32_t __uncaught_exception_imp()
{
    // probably safe, seems to be called in IDA too
    // wine *always* returns false, so should be fine
    // std::cout << "__uncaught_exception, this is fine" << std::endl;
    return 0;
}

// import: public: void __thiscall std::basic_ostream
// import: <char,struct std::char_traits<char> >::_Osfx(void)
// thiscall
void basic_ostream_char__Osfx_imp(uint32_t self)
{
    // flush ostream?
    std::cout << "basic_ostream_char__Osfx" << std::endl;
}

// import: public: class std::basic_ostream
// import: <char,struct std::char_traits
// import: <char> > & __thiscall std::basic_ostream
// import: <char,struct std::char_traits<char> >::operator<<(int)
// thiscall
uint32_t basic_ostream_char_print_int_imp(uint32_t self, int32_t val)
{
    std::stringstream & str = *current_stream;
    str << val;
    return self;
    // std::cout << "basic_ostream_char_print_int: " << val << std::endl;
}

// import: protected: void __thiscall std::basic_streambuf
// import: <char,struct std::char_traits<char> >::setg(char *,char *,char *)
// thiscall
void basic_streambuf_char_setg_imp(uint32_t self, uint32_t first,
                                   uint32_t next, uint32_t last)
{
    if (first != 0 || next != 0 || last != 0)
        std::cout << "Cannot setg" << std::endl;
    // std::cout << "basic_streambuf_char_setg" << std::endl;
}

// import: protected: __thiscall std::basic_ios
// import: <wchar_t,struct std::char_traits<wchar_t> >::basic_ios
// import: <wchar_t,struct std::char_traits<wchar_t> >(void)
// thiscall
void basic_ios_wchar_ctor(uint32_t self)
{
}

// import: public: __thiscall std::basic_iostream
// import: <wchar_t,struct std::char_traits<wchar_t> >::basic_iostream
// import: <wchar_t,struct std::char_traits<wchar_t> >
// import: (class std::basic_streambuf
// import: <wchar_t,struct std::char_traits<wchar_t> > *)
// thiscall
void basic_iostream_wchar_ctor(uint32_t self, uint32_t ptr, uint32_t v)
{
}

// import: protected: __thiscall std::basic_streambuf
// import: <wchar_t,struct std::char_traits<wchar_t> >::basic_streambuf
// import: <wchar_t,struct std::char_traits<wchar_t> >(void)
// thiscall
void basic_streambuf_wchar_ctor(uint32_t self)
{
    // const vtable_ptr *vtable; 0
    // wchar_t *rbuf; 4 
    // wchar_t *wbuf; 8
    // wchar_t **prbuf; 12
    // wchar_t **pwbuf; 16
    // wchar_t *rpos; 20
    // wchar_t *wpos; 24
    // wchar_t **prpos; 28
    // wchar_t **pwpos; 32
    // int rsize; 36
    // int wsize; 40
    // int *prsize; 44
    // int *pwsize; 48
    // locale loc; 52

    void * p = heap_alloc(4);
    *(uint32_t*)(self+4) = (uint32_t)p;
    *(uint32_t*)(self+8) = 0;
    *(uint32_t*)(self+12) = (uint32_t)self + 4;
    *(uint32_t*)(self+16) = (uint32_t)self + 8;
    *(uint32_t*)(self+20) = 0;
    *(uint32_t*)(self+24) = 0;
    *(uint32_t*)(self+28) = self + 20;
    *(uint32_t*)(self+32) = self + 24;
    *(uint32_t*)(self+36) = 0;
    *(uint32_t*)(self+40) = 0;
    *(uint32_t*)(self+44) = self + 36;
    *(uint32_t*)(self+48) = self + 40;
    *(uint32_t*)(self+60) = 0;
}

// import: public: virtual __thiscall std::basic_streambuf
// import: <wchar_t,struct std::char_traits<wchar_t> >::
// import: ~basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >(void)
// thiscall
void basic_streambuf_wchar_dtor(uint32_t self)
{
}

// import: public: virtual __thiscall std::basic_iostream
// import: <wchar_t,struct std::char_traits<wchar_t> >::~basic_iostream
// import: <wchar_t,struct std::char_traits<wchar_t> >(void)
// thiscall
void basic_iostream_wchar_dtor(uint32_t self)
{
}

// import: public: virtual __thiscall std::basic_ios
// import: <wchar_t,struct std::char_traits<wchar_t> >::
// import: ~basic_ios<wchar_t,struct std::char_traits<wchar_t> >(void)
// thiscall
void basic_ios_wchar_dtor(uint32_t self)
{
}

// ostream_writecstr
// old patch: 0x4120D0
// patch: 0x412710
uint32_t sub_4120D0(uint32_t stream, char * value)
{
    std::stringstream & str = *current_stream;
    str << value;
    return stream;
    // std::cout << "ostream_writecstr: " << value << std::endl;
}

// ostream_writestr
// old patch: 0x4C6970
// patch: 0x4C6580
uint32_t sub_4C6970(uint32_t stream, basic_string_char* v)
{
    std::stringstream & str = *current_stream;
    // std::cout << "ostream_writestr: " << v->str() << std::endl;
    str << v->str();
    return stream;
}

// copy_iostream_to_str
// old patch: 0x4D8B70
// patch: 0x4D8F70
// thiscall
basic_string_char * sub_4D8B70(uint32_t self, basic_string_char* stdstring)
{
    std::stringstream & str = *current_stream;
    // need to initialize str since it hasn't been done already
    stdstring->reset();

    // move string to guest space
    std::string res = str.str();
    void * str_guest = heap_alloc(res.size());
    memcpy(str_guest, &res[0], res.size());

    // use address 401A00, which is create_string_from_cstr
    // signature: string * __thiscall f(char* str, int size)
    call_x86_thiscall_3(get_mem_va(VA_CREATE_STRING_FROM_CSTR),
                        (uint32_t)stdstring, (uint32_t)str_guest, res.size());

    heap_dealloc(str_guest);

    return stdstring;

    // std::cout << "copy_iostream_to_str: " << res << std::endl;
}

#endif // TERRAINGEN_IOS_H
