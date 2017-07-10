#include "import/import.h"
static void TGEN_CDECL free_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "free" << '\n';
#endif
    free_imp((void *)v0);
}

static uint32_t TGEN_CDECL new_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "void * __cdecl operator new(unsigned int)" << '\n';
#endif
    return (uint32_t)new_imp((uint32_t)v0);
}

static uint32_t TGEN_CDECL malloc_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "malloc" << '\n';
#endif
    return (uint32_t)malloc_imp((uint32_t)v0);
}

static void TGEN_CDECL delete_func_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "void __cdecl operator delete(void *)" << '\n';
#endif
    delete_func_imp((void *)v0);
}

static void TGEN_CDECL delete_arr_func_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "void __cdecl operator delete[](void *)" << '\n';
#endif
    delete_arr_func_imp((void *)v0);
}

static uint32_t TGEN_CDECL memcpy_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "memcpy" << '\n';
#endif
    return (uint32_t)memcpy_imp((void *)v0, (void *)v1, (uint32_t)v2);
}

static uint32_t TGEN_CDECL strcmp_imp_wrapc(uint32_t v0, uint32_t v1)
{
#ifndef NDEBUG
    std::cout << "strcmp" << '\n';
#endif
    return (uint32_t)strcmp_imp((const char *)v0, (const char *)v1);
}

static uint32_t TGEN_CDECL memcmp_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "memcmp" << '\n';
#endif
    return (uint32_t)memcmp_imp((const char *)v0, (const char *)v1, (uint32_t)v2);
}

static void TGEN_CDECL abort_imp_wrapc()
{
#ifndef NDEBUG
    std::cout << "abort" << '\n';
#endif
    abort_imp();
}

static void TGEN_CDECL terminateYAXXZ_imp_wrapc()
{
#ifndef NDEBUG
    std::cout << "void __cdecl terminate(void)" << '\n';
#endif
    terminateYAXXZ_imp();
}

static uint32_t TGEN_STDCALL WSAStartup_imp_wrapc(uint32_t v0, uint32_t v1)
{
#ifndef NDEBUG
    std::cout << "ORDINAL_WS2_32.DLL_115" << '\n';
#endif
    return (uint32_t)WSAStartup_imp((uint32_t)v0, (uint32_t)v1);
}

static uint32_t TGEN_STDCALL InitializeCriticalSectionAndSpinCount_imp_wrapc(uint32_t v0, uint32_t v1)
{
#ifndef NDEBUG
    std::cout << "InitializeCriticalSectionAndSpinCount" << '\n';
#endif
    return (uint32_t)InitializeCriticalSectionAndSpinCount_imp((uint32_t)v0, (uint32_t)v1);
}

static void TGEN_STDCALL DeleteCriticalSection_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "DeleteCriticalSection" << '\n';
#endif
    DeleteCriticalSection_imp((uint32_t)v0);
}

static uint32_t TGEN_CDECL rand_imp_wrapc()
{
#ifndef NDEBUG
    std::cout << "rand" << '\n';
#endif
    return (uint32_t)rand_imp();
}

static void TGEN_CDECL srand_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "srand" << '\n';
#endif
    srand_imp((uint32_t)v0);
}

static uint32_t TGEN_STDCALL IsProcessorFeaturePresent_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "IsProcessorFeaturePresent" << '\n';
#endif
    return (uint32_t)IsProcessorFeaturePresent_imp((uint32_t)v0);
}

static void TGEN_CDECL _beginthread_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "_beginthread" << '\n';
#endif
    _beginthread_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2);
}

static uint32_t TGEN_STDCALL EncodePointer_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "EncodePointer" << '\n';
#endif
    return (uint32_t)EncodePointer_imp((uint32_t)v0);
}

static uint32_t TGEN_CDECL memmove_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "memmove" << '\n';
#endif
    return (uint32_t)memmove_imp((void *)v0, (const void *)v1, (uint32_t)v2);
}

static uint32_t TGEN_CDECL memset_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "memset" << '\n';
#endif
    return (uint32_t)memset_imp((void *)v0, (int32_t)v1, (uint32_t)v2);
}

static uint32_t TGEN_CDECL fseek_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "fseek" << '\n';
#endif
    return (uint32_t)fseek_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2);
}

static uint32_t TGEN_CDECL fwrite_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3)
{
#ifndef NDEBUG
    std::cout << "fwrite" << '\n';
#endif
    return (uint32_t)fwrite_imp((const void *)v0, (uint32_t)v1, (uint32_t)v2, (uint32_t)v3);
}

static uint32_t TGEN_CDECL fclose_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "fclose" << '\n';
#endif
    return (uint32_t)fclose_imp((uint32_t)v0);
}

static uint32_t TGEN_CDECL _setjmp_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "_setjmp" << '\n';
#endif
    return (uint32_t)_setjmp_imp((uint32_t)v0);
}

static void TGEN_STDCALL InitializeCriticalSection_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "InitializeCriticalSection" << '\n';
#endif
    InitializeCriticalSection_imp((uint32_t)v0);
}

static void TGEN_STDCALL EnterCriticalSection_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "EnterCriticalSection" << '\n';
#endif
    EnterCriticalSection_imp((uint32_t)v0);
}

static void TGEN_STDCALL LeaveCriticalSection_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "LeaveCriticalSection" << '\n';
#endif
    LeaveCriticalSection_imp((uint32_t)v0);
}

static uint32_t TGEN_STDCALL InterlockedCompareExchange_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "InterlockedCompareExchange" << '\n';
#endif
    return (uint32_t)InterlockedCompareExchange_imp((uint32_t *)v0, (uint32_t)v1, (uint32_t)v2);
}

static void TGEN_CDECL _setjmp3_imp_wrapc(uint32_t v0, uint32_t v1)
{
    _setjmp3_imp((uint32_t)v0, (uint32_t)v1);
}

static void TGEN_THISCALL orphan_imp_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "public: void __thiscall std::_Container_base0::_Orphan_all(void)" << '\n';
#endif
    orphan_imp((uint32_t)v0);
}

static double TGEN_CDECL _libm_sse2_cos_precise_imp_wrapc(double v0)
{
#ifndef NDEBUG
    std::cout << "_libm_sse2_cos_precise" << '\n';
#endif
    return (double)_libm_sse2_cos_precise_imp((double)v0);
}

static double TGEN_CDECL _libm_sse2_sin_precise_imp_wrapc(double v0)
{
#ifndef NDEBUG
    std::cout << "_libm_sse2_sin_precise" << '\n';
#endif
    return (double)_libm_sse2_sin_precise_imp((double)v0);
}

static double TGEN_CDECL _libm_sse2_sqrt_precise_imp_wrapc(double v0)
{
#ifndef NDEBUG
    std::cout << "_libm_sse2_sqrt_precise" << '\n';
#endif
    return (double)_libm_sse2_sqrt_precise_imp((double)v0);
}

static double TGEN_CDECL _libm_sse2_pow_precise_imp_wrapc(double v0, double v1)
{
#ifndef NDEBUG
    std::cout << "_libm_sse2_pow_precise" << '\n';
#endif
    return (double)_libm_sse2_pow_precise_imp((double)v0, (double)v1);
}

static uint32_t TGEN_THISCALL basic_istream_char_ctor_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2, uint32_t v3)
{
#ifndef NDEBUG
    std::cout << "public: __thiscall std::basic_istream<char,struct std::char_traits<char> >::basic_istream<char,struct std::char_traits<char> >(class std::basic_streambuf<char,struct std::char_traits<char> > *,bool)" << '\n';
#endif
    return (uint32_t)basic_istream_char_ctor_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2, (uint32_t)v3);
}

static uint32_t TGEN_THISCALL basic_streambuf_char_ctor_imp_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "protected: __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::basic_streambuf<char,struct std::char_traits<char> >(void)" << '\n';
#endif
    return (uint32_t)basic_streambuf_char_ctor_imp((uint32_t)v0);
}

static void TGEN_THISCALL basic_streambuf_char__Init_empty_imp_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "protected: void __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::_Init(void)" << '\n';
#endif
    basic_streambuf_char__Init_empty_imp((uint32_t)v0);
}

static void TGEN_THISCALL basic_ios_char_setstate_reraise_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "public: void __thiscall std::basic_ios<char,struct std::char_traits<char> >::setstate(int,bool)" << '\n';
#endif
    basic_ios_char_setstate_reraise_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2);
}

static void TGEN_THISCALL basic_streambuf_char_dtor_imp_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "public: virtual __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::~basic_streambuf<char,struct std::char_traits<char> >(void)" << '\n';
#endif
    basic_streambuf_char_dtor_imp((uint32_t)v0);
}

static void TGEN_THISCALL basic_istream_char_dtor_imp_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "public: virtual __thiscall std::basic_istream<char,struct std::char_traits<char> >::~basic_istream<char,struct std::char_traits<char> >(void)" << '\n';
#endif
    basic_istream_char_dtor_imp((uint32_t)v0);
}

static void TGEN_THISCALL basic_ios_char_dtor_imp_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "public: virtual __thiscall std::basic_ios<char,struct std::char_traits<char> >::~basic_ios<char,struct std::char_traits<char> >(void)" << '\n';
#endif
    basic_ios_char_dtor_imp((uint32_t)v0);
}

static uint32_t TGEN_CDECL _Fiopen_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "struct _iobuf * __cdecl std::_Fiopen(char const *,int,int)" << '\n';
#endif
    return (uint32_t)_Fiopen_imp((char *)v0, (uint32_t)v1, (uint32_t)v2);
}

static uint32_t TGEN_THISCALL basic_istream_char_read_int_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1)
{
#ifndef NDEBUG
    std::cout << "public: class std::basic_istream<char,struct std::char_traits<char> > & __thiscall std::basic_istream<char,struct std::char_traits<char> >::operator>>(int &)" << '\n';
#endif
    return (uint32_t)basic_istream_char_read_int_imp((uint32_t)v0, (uint32_t *)v1);
}

static uint32_t TGEN_THISCALL basic_ios_char_ctor_imp_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "protected: __thiscall std::basic_ios<char,struct std::char_traits<char> >::basic_ios<char,struct std::char_traits<char> >(void)" << '\n';
#endif
    return (uint32_t)basic_ios_char_ctor_imp((uint32_t)v0);
}

static uint32_t TGEN_THISCALL basic_iostream_char_ctor_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "public: __thiscall std::basic_iostream<char,struct std::char_traits<char> >::basic_iostream<char,struct std::char_traits<char> >(class std::basic_streambuf<char,struct std::char_traits<char> > *)" << '\n';
#endif
    return (uint32_t)basic_iostream_char_ctor_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2);
}

static void TGEN_THISCALL basic_iostream_char_dtor_imp_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "public: virtual __thiscall std::basic_iostream<char,struct std::char_traits<char> >::~basic_iostream<char,struct std::char_traits<char> >(void)" << '\n';
#endif
    basic_iostream_char_dtor_imp((uint32_t)v0);
}

static void TGEN_CDECL ios_base_Ios_base_dtor_imp_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "private: static void __cdecl std::ios_base::_Ios_base_dtor(class std::ios_base *)" << '\n';
#endif
    ios_base_Ios_base_dtor_imp((uint32_t)v0);
}

static uint32_t TGEN_THISCALL basic_streambuf_char_sputn_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "public: __int64 __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::sputn(char const *,__int64)" << '\n';
#endif
    return (uint32_t)basic_streambuf_char_sputn_imp((uint32_t)v0, (char *)v1, (uint64_t)v2);
}

static uint32_t TGEN_CDECL __uncaught_exception_imp_wrapc()
{
#ifndef NDEBUG
    std::cout << "__uncaught_exception" << '\n';
#endif
    return (uint32_t)__uncaught_exception_imp();
}

static void TGEN_THISCALL basic_ostream_char__Osfx_imp_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "public: void __thiscall std::basic_ostream<char,struct std::char_traits<char> >::_Osfx(void)" << '\n';
#endif
    basic_ostream_char__Osfx_imp((uint32_t)v0);
}

static uint32_t TGEN_THISCALL basic_ostream_char_print_int_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1)
{
#ifndef NDEBUG
    std::cout << "public: class std::basic_ostream<char,struct std::char_traits<char> > & __thiscall std::basic_ostream<char,struct std::char_traits<char> >::operator<<(int)" << '\n';
#endif
    return (uint32_t)basic_ostream_char_print_int_imp((uint32_t)v0, (int32_t)v1);
}

static void TGEN_THISCALL basic_streambuf_char_setg_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2, uint32_t v3)
{
#ifndef NDEBUG
    std::cout << "protected: void __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::setg(char *,char *,char *)" << '\n';
#endif
    basic_streambuf_char_setg_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2, (uint32_t)v3);
}

static void TGEN_THISCALL basic_ios_wchar_ctor_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "protected: __thiscall std::basic_ios<wchar_t,struct std::char_traits<wchar_t> >::basic_ios<wchar_t,struct std::char_traits<wchar_t> >(void)" << '\n';
#endif
    basic_ios_wchar_ctor((uint32_t)v0);
}

static void TGEN_THISCALL basic_iostream_wchar_ctor_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2)
{
#ifndef NDEBUG
    std::cout << "public: __thiscall std::basic_iostream<wchar_t,struct std::char_traits<wchar_t> >::basic_iostream<wchar_t,struct std::char_traits<wchar_t> >(class std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> > *)" << '\n';
#endif
    basic_iostream_wchar_ctor((uint32_t)v0, (uint32_t)v1, (uint32_t)v2);
}

static void TGEN_THISCALL basic_streambuf_wchar_ctor_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "protected: __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >(void)" << '\n';
#endif
    basic_streambuf_wchar_ctor((uint32_t)v0);
}

static void TGEN_THISCALL basic_streambuf_wchar_dtor_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "public: virtual __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >::~basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >(void)" << '\n';
#endif
    basic_streambuf_wchar_dtor((uint32_t)v0);
}

static void TGEN_THISCALL basic_iostream_wchar_dtor_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "public: virtual __thiscall std::basic_iostream<wchar_t,struct std::char_traits<wchar_t> >::~basic_iostream<wchar_t,struct std::char_traits<wchar_t> >(void)" << '\n';
#endif
    basic_iostream_wchar_dtor((uint32_t)v0);
}

static void TGEN_THISCALL basic_ios_wchar_dtor_wrapc(uint32_t v0, uint32_t pad)
{
#ifndef NDEBUG
    std::cout << "public: virtual __thiscall std::basic_ios<wchar_t,struct std::char_traits<wchar_t> >::~basic_ios<wchar_t,struct std::char_traits<wchar_t> >(void)" << '\n';
#endif
    basic_ios_wchar_dtor((uint32_t)v0);
}

static uint32_t TGEN_CDECL sub_4120D0_wrapc(uint32_t v0, uint32_t v1)
{
#ifndef NDEBUG
    std::cout << "sub_4120D0" << '\n';
#endif
    return (uint32_t)sub_4120D0((uint32_t)v0, (char *)v1);
}

static uint32_t TGEN_CDECL sub_4C6970_wrapc(uint32_t v0, uint32_t v1)
{
#ifndef NDEBUG
    std::cout << "sub_4C6970" << '\n';
#endif
    return (uint32_t)sub_4C6970((uint32_t)v0, (basic_string_char *)v1);
}

static uint32_t TGEN_THISCALL sub_4D8B70_wrapc(uint32_t v0, uint32_t pad, uint32_t v1)
{
#ifndef NDEBUG
    std::cout << "sub_4D8B70" << '\n';
#endif
    return (uint32_t)sub_4D8B70((uint32_t)v0, (basic_string_char *)v1);
}

static uint32_t TGEN_CDECL sub_469210_wrapc(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3, uint32_t v4)
{
#ifndef NDEBUG
    std::cout << "sub_469210" << '\n';
#endif
    return (uint32_t)sub_469210((uint32_t)v0, (char *)v1, (uint32_t)v2, (uint32_t *)v3, (uint32_t)v4);
}

static uint32_t TGEN_CDECL sub_4698F0_wrapc(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3, uint32_t v4)
{
#ifndef NDEBUG
    std::cout << "sub_4698F0" << '\n';
#endif
    return (uint32_t)sub_4698F0((uint32_t)v0, (uint32_t)v1, (char *)v2, (int32_t)v3, (uint32_t)v4);
}

static uint32_t TGEN_CDECL sub_46A090_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "sub_46A090" << '\n';
#endif
    return (uint32_t)sub_46A090((uint32_t)v0);
}

static uint32_t TGEN_CDECL sub_46AE00_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "sub_46AE00" << '\n';
#endif
    return (uint32_t)sub_46AE00((uint32_t)v0);
}

static uint32_t TGEN_CDECL sub_46A3A0_wrapc(uint32_t v0, uint32_t v1)
{
#ifndef NDEBUG
    std::cout << "sub_46A3A0" << '\n';
#endif
    return (uint32_t)sub_46A3A0((uint32_t)v0, (int32_t)v1);
}

static uint32_t TGEN_CDECL sub_46A320_wrapc(uint32_t v0, uint32_t v1)
{
#ifndef NDEBUG
    std::cout << "sub_46A320" << '\n';
#endif
    return (uint32_t)sub_46A320((uint32_t)v0, (int32_t)v1);
}

static uint32_t TGEN_CDECL sub_4633C0_wrapc(uint32_t v0)
{
#ifndef NDEBUG
    std::cout << "sub_4633C0" << '\n';
#endif
    return (uint32_t)sub_4633C0((uint32_t)v0);
}

static uint32_t TGEN_CDECL sub_469530_wrapc(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3, uint32_t v4)
{
#ifndef NDEBUG
    std::cout << "sub_469530" << '\n';
#endif
    return (uint32_t)sub_469530((uint32_t)v0, (uint32_t)v1, (char *)v2, (uint32_t)v3, (uint32_t)v4);
}

static uint32_t TGEN_CDECL sub_468330_wrapc(uint32_t v0, uint32_t v1)
{
#ifndef NDEBUG
    std::cout << "sub_468330" << '\n';
#endif
    return (uint32_t)sub_468330((char *)v0, (uint32_t *)v1);
}

static uint32_t TGEN_CDECL sub_463500_wrapc(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3, uint32_t v4)
{
#ifndef NDEBUG
    std::cout << "sub_463500" << '\n';
#endif
    return (uint32_t)sub_463500((uint32_t)v0, (char *)v1, (uint32_t)v2, (uint32_t)v3, (uint32_t)v4);
}

static void TGEN_CDECL sub_46B620_wrapc()
{
#ifndef NDEBUG
    std::cout << "sub_46B620" << '\n';
#endif
    sub_46B620();
}

std::unordered_map<std::string, Import> imports(
{
{"free", Import{(void*)&free_imp_wrapc}},
{"void * __cdecl operator new(unsigned int)", Import{(void*)&new_imp_wrapc}},
{"malloc", Import{(void*)&malloc_imp_wrapc}},
{"void __cdecl operator delete(void *)", Import{(void*)&delete_func_imp_wrapc}},
{"void __cdecl operator delete[](void *)", Import{(void*)&delete_arr_func_imp_wrapc}},
{"memcpy", Import{(void*)&memcpy_imp_wrapc}},
{"strcmp", Import{(void*)&strcmp_imp_wrapc}},
{"memcmp", Import{(void*)&memcmp_imp_wrapc}},
{"abort", Import{(void*)&abort_imp_wrapc}},
{"void __cdecl terminate(void)", Import{(void*)&terminateYAXXZ_imp_wrapc}},
{"ORDINAL_WS2_32.DLL_115", Import{(void*)&WSAStartup_imp_wrapc}},
{"InitializeCriticalSectionAndSpinCount", Import{(void*)&InitializeCriticalSectionAndSpinCount_imp_wrapc}},
{"DeleteCriticalSection", Import{(void*)&DeleteCriticalSection_imp_wrapc}},
{"rand", Import{(void*)&rand_imp_wrapc}},
{"srand", Import{(void*)&srand_imp_wrapc}},
{"IsProcessorFeaturePresent", Import{(void*)&IsProcessorFeaturePresent_imp_wrapc}},
{"_beginthread", Import{(void*)&_beginthread_imp_wrapc}},
{"EncodePointer", Import{(void*)&EncodePointer_imp_wrapc}},
{"memmove", Import{(void*)&memmove_imp_wrapc}},
{"memset", Import{(void*)&memset_imp_wrapc}},
{"fseek", Import{(void*)&fseek_imp_wrapc}},
{"fwrite", Import{(void*)&fwrite_imp_wrapc}},
{"fclose", Import{(void*)&fclose_imp_wrapc}},
{"_setjmp", Import{(void*)&_setjmp_imp_wrapc}},
{"InitializeCriticalSection", Import{(void*)&InitializeCriticalSection_imp_wrapc}},
{"EnterCriticalSection", Import{(void*)&EnterCriticalSection_imp_wrapc}},
{"LeaveCriticalSection", Import{(void*)&LeaveCriticalSection_imp_wrapc}},
{"InterlockedCompareExchange", Import{(void*)&InterlockedCompareExchange_imp_wrapc}},
{"_setjmp3", Import{(void*)&_setjmp3_imp_wrapc}},
{"public: void __thiscall std::_Container_base0::_Orphan_all(void)", Import{(void*)&orphan_imp_wrapc}},
{"_libm_sse2_cos_precise", Import{(void*)&_libm_sse2_cos_precise_imp_wrapc}},
{"_libm_sse2_sin_precise", Import{(void*)&_libm_sse2_sin_precise_imp_wrapc}},
{"_libm_sse2_sqrt_precise", Import{(void*)&_libm_sse2_sqrt_precise_imp_wrapc}},
{"_libm_sse2_pow_precise", Import{(void*)&_libm_sse2_pow_precise_imp_wrapc}},
{"public: __thiscall std::basic_istream<char,struct std::char_traits<char> >::basic_istream<char,struct std::char_traits<char> >(class std::basic_streambuf<char,struct std::char_traits<char> > *,bool)", Import{(void*)&basic_istream_char_ctor_imp_wrapc}},
{"protected: __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::basic_streambuf<char,struct std::char_traits<char> >(void)", Import{(void*)&basic_streambuf_char_ctor_imp_wrapc}},
{"protected: void __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::_Init(void)", Import{(void*)&basic_streambuf_char__Init_empty_imp_wrapc}},
{"public: void __thiscall std::basic_ios<char,struct std::char_traits<char> >::setstate(int,bool)", Import{(void*)&basic_ios_char_setstate_reraise_imp_wrapc}},
{"public: virtual __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::~basic_streambuf<char,struct std::char_traits<char> >(void)", Import{(void*)&basic_streambuf_char_dtor_imp_wrapc}},
{"public: virtual __thiscall std::basic_istream<char,struct std::char_traits<char> >::~basic_istream<char,struct std::char_traits<char> >(void)", Import{(void*)&basic_istream_char_dtor_imp_wrapc}},
{"public: virtual __thiscall std::basic_ios<char,struct std::char_traits<char> >::~basic_ios<char,struct std::char_traits<char> >(void)", Import{(void*)&basic_ios_char_dtor_imp_wrapc}},
{"struct _iobuf * __cdecl std::_Fiopen(char const *,int,int)", Import{(void*)&_Fiopen_imp_wrapc}},
{"public: class std::basic_istream<char,struct std::char_traits<char> > & __thiscall std::basic_istream<char,struct std::char_traits<char> >::operator>>(int &)", Import{(void*)&basic_istream_char_read_int_imp_wrapc}},
{"protected: __thiscall std::basic_ios<char,struct std::char_traits<char> >::basic_ios<char,struct std::char_traits<char> >(void)", Import{(void*)&basic_ios_char_ctor_imp_wrapc}},
{"public: __thiscall std::basic_iostream<char,struct std::char_traits<char> >::basic_iostream<char,struct std::char_traits<char> >(class std::basic_streambuf<char,struct std::char_traits<char> > *)", Import{(void*)&basic_iostream_char_ctor_imp_wrapc}},
{"public: virtual __thiscall std::basic_iostream<char,struct std::char_traits<char> >::~basic_iostream<char,struct std::char_traits<char> >(void)", Import{(void*)&basic_iostream_char_dtor_imp_wrapc}},
{"private: static void __cdecl std::ios_base::_Ios_base_dtor(class std::ios_base *)", Import{(void*)&ios_base_Ios_base_dtor_imp_wrapc}},
{"public: __int64 __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::sputn(char const *,__int64)", Import{(void*)&basic_streambuf_char_sputn_imp_wrapc}},
{"__uncaught_exception", Import{(void*)&__uncaught_exception_imp_wrapc}},
{"public: void __thiscall std::basic_ostream<char,struct std::char_traits<char> >::_Osfx(void)", Import{(void*)&basic_ostream_char__Osfx_imp_wrapc}},
{"public: class std::basic_ostream<char,struct std::char_traits<char> > & __thiscall std::basic_ostream<char,struct std::char_traits<char> >::operator<<(int)", Import{(void*)&basic_ostream_char_print_int_imp_wrapc}},
{"protected: void __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::setg(char *,char *,char *)", Import{(void*)&basic_streambuf_char_setg_imp_wrapc}},
{"protected: __thiscall std::basic_ios<wchar_t,struct std::char_traits<wchar_t> >::basic_ios<wchar_t,struct std::char_traits<wchar_t> >(void)", Import{(void*)&basic_ios_wchar_ctor_wrapc}},
{"public: __thiscall std::basic_iostream<wchar_t,struct std::char_traits<wchar_t> >::basic_iostream<wchar_t,struct std::char_traits<wchar_t> >(class std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> > *)", Import{(void*)&basic_iostream_wchar_ctor_wrapc}},
{"protected: __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >(void)", Import{(void*)&basic_streambuf_wchar_ctor_wrapc}},
{"public: virtual __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >::~basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >(void)", Import{(void*)&basic_streambuf_wchar_dtor_wrapc}},
{"public: virtual __thiscall std::basic_iostream<wchar_t,struct std::char_traits<wchar_t> >::~basic_iostream<wchar_t,struct std::char_traits<wchar_t> >(void)", Import{(void*)&basic_iostream_wchar_dtor_wrapc}},
{"public: virtual __thiscall std::basic_ios<wchar_t,struct std::char_traits<wchar_t> >::~basic_ios<wchar_t,struct std::char_traits<wchar_t> >(void)", Import{(void*)&basic_ios_wchar_dtor_wrapc}}
}
);std::vector<Patch> patches(
{
Patch{(void*)&sub_4120D0_wrapc, 4268240},
Patch{(void*)&sub_4C6970_wrapc, 5007728},
Patch{(void*)&sub_4D8B70_wrapc, 5081968},
Patch{(void*)&sub_469210_wrapc, 4624912},
Patch{(void*)&sub_4698F0_wrapc, 4626672},
Patch{(void*)&sub_46A090_wrapc, 4628624},
Patch{(void*)&sub_46AE00_wrapc, 4632064},
Patch{(void*)&sub_46A3A0_wrapc, 4629408},
Patch{(void*)&sub_46A320_wrapc, 4629280},
Patch{(void*)&sub_4633C0_wrapc, 4600768},
Patch{(void*)&sub_469530_wrapc, 4625712},
Patch{(void*)&sub_468330_wrapc, 4621104},
Patch{(void*)&sub_463500_wrapc, 4601088},
Patch{(void*)&sub_46B620_wrapc, 4634144}
}
);