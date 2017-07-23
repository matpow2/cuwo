#include "import/import.h"
static void TGEN_CDECL free_imp_wrapc(uint32_t v0)
{
    free_imp((void *)v0);
#ifdef VERBOSE_WRAP
    std::cout << "free"  << " " << v0 << '\n';
#endif
}

static uint32_t TGEN_CDECL new_imp_wrapc(uint32_t v0)
{
    uint32_t ret_val = (uint32_t)new_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "void * __cdecl operator new(unsigned int)"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL malloc_imp_wrapc(uint32_t v0)
{
    uint32_t ret_val = (uint32_t)malloc_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "malloc"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_CDECL delete_func_imp_wrapc(uint32_t v0)
{
    delete_func_imp((void *)v0);
#ifdef VERBOSE_WRAP
    std::cout << "void __cdecl operator delete(void *)"  << " " << v0 << '\n';
#endif
}

static void TGEN_CDECL delete_arr_func_imp_wrapc(uint32_t v0)
{
    delete_arr_func_imp((void *)v0);
#ifdef VERBOSE_WRAP
    std::cout << "void __cdecl operator delete[](void *)"  << " " << v0 << '\n';
#endif
}

static uint32_t TGEN_CDECL memcpy_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
    uint32_t ret_val = (uint32_t)memcpy_imp((void *)v0, (void *)v1, (uint32_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "memcpy"  << " " << v0  << " " << v1  << " " << v2 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL strcmp_imp_wrapc(uint32_t v0, uint32_t v1)
{
    uint32_t ret_val = (uint32_t)strcmp_imp((const char *)v0, (const char *)v1);
#ifdef VERBOSE_WRAP
    std::cout << "strcmp"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL memcmp_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
    uint32_t ret_val = (uint32_t)memcmp_imp((const char *)v0, (const char *)v1, (uint32_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "memcmp"  << " " << v0  << " " << v1  << " " << v2 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_CDECL abort_imp_wrapc()
{
    abort_imp();
#ifdef VERBOSE_WRAP
    std::cout << "abort" << '\n';
#endif
}

static void TGEN_CDECL terminateYAXXZ_imp_wrapc()
{
    terminateYAXXZ_imp();
#ifdef VERBOSE_WRAP
    std::cout << "void __cdecl terminate(void)" << '\n';
#endif
}

static uint32_t TGEN_STDCALL WSAStartup_imp_wrapc(uint32_t v0, uint32_t v1)
{
    uint32_t ret_val = (uint32_t)WSAStartup_imp((uint32_t)v0, (uint32_t)v1);
#ifdef VERBOSE_WRAP
    std::cout << "ORDINAL_WS2_32.DLL_115"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_STDCALL InitializeCriticalSectionAndSpinCount_imp_wrapc(uint32_t v0, uint32_t v1)
{
    uint32_t ret_val = (uint32_t)InitializeCriticalSectionAndSpinCount_imp((uint32_t)v0, (uint32_t)v1);
#ifdef VERBOSE_WRAP
    std::cout << "InitializeCriticalSectionAndSpinCount"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_STDCALL DeleteCriticalSection_imp_wrapc(uint32_t v0)
{
    DeleteCriticalSection_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "DeleteCriticalSection"  << " " << v0 << '\n';
#endif
}

static uint32_t TGEN_CDECL rand_imp_wrapc()
{
    uint32_t ret_val = (uint32_t)rand_imp();
#ifdef VERBOSE_WRAP
    std::cout << "rand" <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_CDECL srand_imp_wrapc(uint32_t v0)
{
    srand_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "srand"  << " " << v0 << '\n';
#endif
}

static uint32_t TGEN_STDCALL IsProcessorFeaturePresent_imp_wrapc(uint32_t v0)
{
    uint32_t ret_val = (uint32_t)IsProcessorFeaturePresent_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "IsProcessorFeaturePresent"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_CDECL _beginthread_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
    _beginthread_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "_beginthread"  << " " << v0  << " " << v1  << " " << v2 << '\n';
#endif
}

static uint32_t TGEN_STDCALL EncodePointer_imp_wrapc(uint32_t v0)
{
    uint32_t ret_val = (uint32_t)EncodePointer_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "EncodePointer"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL memmove_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
    uint32_t ret_val = (uint32_t)memmove_imp((void *)v0, (const void *)v1, (uint32_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "memmove"  << " " << v0  << " " << v1  << " " << v2 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL memset_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
    uint32_t ret_val = (uint32_t)memset_imp((void *)v0, (int32_t)v1, (uint32_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "memset"  << " " << v0  << " " << v1  << " " << v2 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL fseek_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
    uint32_t ret_val = (uint32_t)fseek_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "fseek"  << " " << v0  << " " << v1  << " " << v2 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL fwrite_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3)
{
    uint32_t ret_val = (uint32_t)fwrite_imp((const void *)v0, (uint32_t)v1, (uint32_t)v2, (uint32_t)v3);
#ifdef VERBOSE_WRAP
    std::cout << "fwrite"  << " " << v0  << " " << v1  << " " << v2  << " " << v3 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL fclose_imp_wrapc(uint32_t v0)
{
    uint32_t ret_val = (uint32_t)fclose_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "fclose"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL _setjmp_imp_wrapc(uint32_t v0)
{
    uint32_t ret_val = (uint32_t)_setjmp_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "_setjmp"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_STDCALL InitializeCriticalSection_imp_wrapc(uint32_t v0)
{
    InitializeCriticalSection_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "InitializeCriticalSection"  << " " << v0 << '\n';
#endif
}

static void TGEN_STDCALL EnterCriticalSection_imp_wrapc(uint32_t v0)
{
    EnterCriticalSection_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "EnterCriticalSection"  << " " << v0 << '\n';
#endif
}

static void TGEN_STDCALL LeaveCriticalSection_imp_wrapc(uint32_t v0)
{
    LeaveCriticalSection_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "LeaveCriticalSection"  << " " << v0 << '\n';
#endif
}

static uint32_t TGEN_STDCALL InterlockedCompareExchange_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
    uint32_t ret_val = (uint32_t)InterlockedCompareExchange_imp((uint32_t *)v0, (uint32_t)v1, (uint32_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "InterlockedCompareExchange"  << " " << v0  << " " << v1  << " " << v2 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_CDECL _setjmp3_imp_wrapc(uint32_t v0, uint32_t v1)
{
    _setjmp3_imp((uint32_t)v0, (uint32_t)v1);
}

static void TGEN_THISCALL orphan_imp_wrapc(uint32_t v0, uint32_t pad)
{
    orphan_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "public: void __thiscall std::_Container_base0::_Orphan_all(void)"  << " " << v0 << '\n';
#endif
}

static double TGEN_VECTORCALL _libm_sse2_cos_precise_imp_wrapc(double v0)
{
    double ret_val = (double)_libm_sse2_cos_precise_imp((double)v0);
#ifdef VERBOSE_WRAP
    std::cout << "_libm_sse2_cos_precise"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static double TGEN_VECTORCALL _libm_sse2_sin_precise_imp_wrapc(double v0)
{
    double ret_val = (double)_libm_sse2_sin_precise_imp((double)v0);
#ifdef VERBOSE_WRAP
    std::cout << "_libm_sse2_sin_precise"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static double TGEN_VECTORCALL _libm_sse2_sqrt_precise_imp_wrapc(double v0)
{
    double ret_val = (double)_libm_sse2_sqrt_precise_imp((double)v0);
#ifdef VERBOSE_WRAP
    std::cout << "_libm_sse2_sqrt_precise"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static double TGEN_VECTORCALL _libm_sse2_pow_precise_imp_wrapc(double v0, double v1)
{
    double ret_val = (double)_libm_sse2_pow_precise_imp((double)v0, (double)v1);
#ifdef VERBOSE_WRAP
    std::cout << "_libm_sse2_pow_precise"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static double TGEN_VECTORCALL _libm_sse2_exp_precise_wrapc(double v0)
{
    double ret_val = (double)_libm_sse2_exp_precise((double)v0);
#ifdef VERBOSE_WRAP
    std::cout << "_libm_sse2_exp_precise"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static double TGEN_VECTORCALL _libm_sse2_acos_precise_wrapc(double v0)
{
    double ret_val = (double)_libm_sse2_acos_precise((double)v0);
#ifdef VERBOSE_WRAP
    std::cout << "_libm_sse2_acos_precise"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static double TGEN_VECTORCALL _libm_sse2_asin_precise_wrapc(double v0)
{
    double ret_val = (double)_libm_sse2_asin_precise((double)v0);
#ifdef VERBOSE_WRAP
    std::cout << "_libm_sse2_asin_precise"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_THISCALL basic_istream_char_ctor_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2, uint32_t v3)
{
    uint32_t ret_val = (uint32_t)basic_istream_char_ctor_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2, (uint32_t)v3);
#ifdef VERBOSE_WRAP
    std::cout << "public: __thiscall std::basic_istream<char,struct std::char_traits<char> >::basic_istream<char,struct std::char_traits<char> >(class std::basic_streambuf<char,struct std::char_traits<char> > *,bool)"  << " " << v0  << " " << v1  << " " << v2  << " " << v3 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_THISCALL basic_streambuf_char_ctor_imp_wrapc(uint32_t v0, uint32_t pad)
{
    uint32_t ret_val = (uint32_t)basic_streambuf_char_ctor_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "protected: __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::basic_streambuf<char,struct std::char_traits<char> >(void)"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_THISCALL basic_streambuf_char__Init_empty_imp_wrapc(uint32_t v0, uint32_t pad)
{
    basic_streambuf_char__Init_empty_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "protected: void __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::_Init(void)"  << " " << v0 << '\n';
#endif
}

static void TGEN_THISCALL basic_ios_char_setstate_reraise_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2)
{
    basic_ios_char_setstate_reraise_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "public: void __thiscall std::basic_ios<char,struct std::char_traits<char> >::setstate(int,bool)"  << " " << v0  << " " << v1  << " " << v2 << '\n';
#endif
}

static void TGEN_THISCALL basic_streambuf_char_dtor_imp_wrapc(uint32_t v0, uint32_t pad)
{
    basic_streambuf_char_dtor_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "public: virtual __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::~basic_streambuf<char,struct std::char_traits<char> >(void)"  << " " << v0 << '\n';
#endif
}

static void TGEN_THISCALL basic_istream_char_dtor_imp_wrapc(uint32_t v0, uint32_t pad)
{
    basic_istream_char_dtor_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "public: virtual __thiscall std::basic_istream<char,struct std::char_traits<char> >::~basic_istream<char,struct std::char_traits<char> >(void)"  << " " << v0 << '\n';
#endif
}

static void TGEN_THISCALL basic_ios_char_dtor_imp_wrapc(uint32_t v0, uint32_t pad)
{
    basic_ios_char_dtor_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "public: virtual __thiscall std::basic_ios<char,struct std::char_traits<char> >::~basic_ios<char,struct std::char_traits<char> >(void)"  << " " << v0 << '\n';
#endif
}

static uint32_t TGEN_CDECL _Fiopen_imp_wrapc(uint32_t v0, uint32_t v1, uint32_t v2)
{
    uint32_t ret_val = (uint32_t)_Fiopen_imp((char *)v0, (uint32_t)v1, (uint32_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "struct _iobuf * __cdecl std::_Fiopen(char const *,int,int)"  << " " << v0  << " " << v1  << " " << v2 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_THISCALL basic_istream_char_read_int_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1)
{
    uint32_t ret_val = (uint32_t)basic_istream_char_read_int_imp((uint32_t)v0, (uint32_t *)v1);
#ifdef VERBOSE_WRAP
    std::cout << "public: class std::basic_istream<char,struct std::char_traits<char> > & __thiscall std::basic_istream<char,struct std::char_traits<char> >::operator>>(int &)"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_THISCALL basic_ios_char_ctor_imp_wrapc(uint32_t v0, uint32_t pad)
{
    uint32_t ret_val = (uint32_t)basic_ios_char_ctor_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "protected: __thiscall std::basic_ios<char,struct std::char_traits<char> >::basic_ios<char,struct std::char_traits<char> >(void)"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_THISCALL basic_iostream_char_ctor_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2)
{
    uint32_t ret_val = (uint32_t)basic_iostream_char_ctor_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "public: __thiscall std::basic_iostream<char,struct std::char_traits<char> >::basic_iostream<char,struct std::char_traits<char> >(class std::basic_streambuf<char,struct std::char_traits<char> > *)"  << " " << v0  << " " << v1  << " " << v2 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_THISCALL basic_iostream_char_dtor_imp_wrapc(uint32_t v0, uint32_t pad)
{
    basic_iostream_char_dtor_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "public: virtual __thiscall std::basic_iostream<char,struct std::char_traits<char> >::~basic_iostream<char,struct std::char_traits<char> >(void)"  << " " << v0 << '\n';
#endif
}

static void TGEN_CDECL ios_base_Ios_base_dtor_imp_wrapc(uint32_t v0)
{
    ios_base_Ios_base_dtor_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "private: static void __cdecl std::ios_base::_Ios_base_dtor(class std::ios_base *)"  << " " << v0 << '\n';
#endif
}

static uint32_t TGEN_THISCALL basic_streambuf_char_sputn_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2)
{
    uint32_t ret_val = (uint32_t)basic_streambuf_char_sputn_imp((uint32_t)v0, (char *)v1, (uint64_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "public: __int64 __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::sputn(char const *,__int64)"  << " " << v0  << " " << v1  << " " << v2 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL __uncaught_exception_imp_wrapc()
{
    uint32_t ret_val = (uint32_t)__uncaught_exception_imp();
#ifdef VERBOSE_WRAP
    std::cout << "__uncaught_exception" <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_THISCALL basic_ostream_char__Osfx_imp_wrapc(uint32_t v0, uint32_t pad)
{
    basic_ostream_char__Osfx_imp((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "public: void __thiscall std::basic_ostream<char,struct std::char_traits<char> >::_Osfx(void)"  << " " << v0 << '\n';
#endif
}

static uint32_t TGEN_THISCALL basic_ostream_char_print_int_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1)
{
    uint32_t ret_val = (uint32_t)basic_ostream_char_print_int_imp((uint32_t)v0, (int32_t)v1);
#ifdef VERBOSE_WRAP
    std::cout << "public: class std::basic_ostream<char,struct std::char_traits<char> > & __thiscall std::basic_ostream<char,struct std::char_traits<char> >::operator<<(int)"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_THISCALL basic_streambuf_char_setg_imp_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2, uint32_t v3)
{
    basic_streambuf_char_setg_imp((uint32_t)v0, (uint32_t)v1, (uint32_t)v2, (uint32_t)v3);
#ifdef VERBOSE_WRAP
    std::cout << "protected: void __thiscall std::basic_streambuf<char,struct std::char_traits<char> >::setg(char *,char *,char *)"  << " " << v0  << " " << v1  << " " << v2  << " " << v3 << '\n';
#endif
}

static void TGEN_THISCALL basic_ios_wchar_ctor_wrapc(uint32_t v0, uint32_t pad)
{
    basic_ios_wchar_ctor((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "protected: __thiscall std::basic_ios<wchar_t,struct std::char_traits<wchar_t> >::basic_ios<wchar_t,struct std::char_traits<wchar_t> >(void)"  << " " << v0 << '\n';
#endif
}

static void TGEN_THISCALL basic_iostream_wchar_ctor_wrapc(uint32_t v0, uint32_t pad, uint32_t v1, uint32_t v2)
{
    basic_iostream_wchar_ctor((uint32_t)v0, (uint32_t)v1, (uint32_t)v2);
#ifdef VERBOSE_WRAP
    std::cout << "public: __thiscall std::basic_iostream<wchar_t,struct std::char_traits<wchar_t> >::basic_iostream<wchar_t,struct std::char_traits<wchar_t> >(class std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> > *)"  << " " << v0  << " " << v1  << " " << v2 << '\n';
#endif
}

static void TGEN_THISCALL basic_streambuf_wchar_ctor_wrapc(uint32_t v0, uint32_t pad)
{
    basic_streambuf_wchar_ctor((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "protected: __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >(void)"  << " " << v0 << '\n';
#endif
}

static void TGEN_THISCALL basic_streambuf_wchar_dtor_wrapc(uint32_t v0, uint32_t pad)
{
    basic_streambuf_wchar_dtor((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "public: virtual __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >::~basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >(void)"  << " " << v0 << '\n';
#endif
}

static void TGEN_THISCALL basic_iostream_wchar_dtor_wrapc(uint32_t v0, uint32_t pad)
{
    basic_iostream_wchar_dtor((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "public: virtual __thiscall std::basic_iostream<wchar_t,struct std::char_traits<wchar_t> >::~basic_iostream<wchar_t,struct std::char_traits<wchar_t> >(void)"  << " " << v0 << '\n';
#endif
}

static void TGEN_THISCALL basic_ios_wchar_dtor_wrapc(uint32_t v0, uint32_t pad)
{
    basic_ios_wchar_dtor((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "public: virtual __thiscall std::basic_ios<wchar_t,struct std::char_traits<wchar_t> >::~basic_ios<wchar_t,struct std::char_traits<wchar_t> >(void)"  << " " << v0 << '\n';
#endif
}

static uint32_t TGEN_CDECL sub_4120D0_wrapc(uint32_t v0, uint32_t v1)
{
    uint32_t ret_val = (uint32_t)sub_4120D0((uint32_t)v0, (char *)v1);
#ifdef VERBOSE_WRAP
    std::cout << "sub_4120D0"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL sub_4C6970_wrapc(uint32_t v0, uint32_t v1)
{
    uint32_t ret_val = (uint32_t)sub_4C6970((uint32_t)v0, (basic_string_char *)v1);
#ifdef VERBOSE_WRAP
    std::cout << "sub_4C6970"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_THISCALL sub_4D8B70_wrapc(uint32_t v0, uint32_t pad, uint32_t v1)
{
    uint32_t ret_val = (uint32_t)sub_4D8B70((uint32_t)v0, (basic_string_char *)v1);
#ifdef VERBOSE_WRAP
    std::cout << "sub_4D8B70"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL sub_469210_wrapc(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3, uint32_t v4)
{
    uint32_t ret_val = (uint32_t)sub_469210((uint32_t)v0, (char *)v1, (uint32_t)v2, (uint32_t *)v3, (uint32_t)v4);
#ifdef VERBOSE_WRAP
    std::cout << "sub_469210"  << " " << v0  << " " << v1  << " " << v2  << " " << v3  << " " << v4 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL sub_4698F0_wrapc(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3, uint32_t v4)
{
    uint32_t ret_val = (uint32_t)sub_4698F0((uint32_t)v0, (uint32_t)v1, (char *)v2, (int32_t)v3, (uint32_t)v4);
#ifdef VERBOSE_WRAP
    std::cout << "sub_4698F0"  << " " << v0  << " " << v1  << " " << v2  << " " << v3  << " " << v4 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL sub_46A090_wrapc(uint32_t v0)
{
    uint32_t ret_val = (uint32_t)sub_46A090((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "sub_46A090"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL sub_46AE00_wrapc(uint32_t v0)
{
    uint32_t ret_val = (uint32_t)sub_46AE00((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "sub_46AE00"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL sub_46A3A0_wrapc(uint32_t v0, uint32_t v1)
{
    uint32_t ret_val = (uint32_t)sub_46A3A0((uint32_t)v0, (int32_t)v1);
#ifdef VERBOSE_WRAP
    std::cout << "sub_46A3A0"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL sub_46A320_wrapc(uint32_t v0, uint32_t v1)
{
    uint32_t ret_val = (uint32_t)sub_46A320((uint32_t)v0, (int32_t)v1);
#ifdef VERBOSE_WRAP
    std::cout << "sub_46A320"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL sub_4633C0_wrapc(uint32_t v0)
{
    uint32_t ret_val = (uint32_t)sub_4633C0((uint32_t)v0);
#ifdef VERBOSE_WRAP
    std::cout << "sub_4633C0"  << " " << v0 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL sub_469530_wrapc(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3, uint32_t v4)
{
    uint32_t ret_val = (uint32_t)sub_469530((uint32_t)v0, (uint32_t)v1, (char *)v2, (uint32_t)v3, (uint32_t)v4);
#ifdef VERBOSE_WRAP
    std::cout << "sub_469530"  << " " << v0  << " " << v1  << " " << v2  << " " << v3  << " " << v4 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL sub_468330_wrapc(uint32_t v0, uint32_t v1)
{
    uint32_t ret_val = (uint32_t)sub_468330((char *)v0, (uint32_t *)v1);
#ifdef VERBOSE_WRAP
    std::cout << "sub_468330"  << " " << v0  << " " << v1 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static uint32_t TGEN_CDECL sub_463500_wrapc(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3, uint32_t v4)
{
    uint32_t ret_val = (uint32_t)sub_463500((uint32_t)v0, (char *)v1, (uint32_t)v2, (uint32_t)v3, (uint32_t)v4);
#ifdef VERBOSE_WRAP
    std::cout << "sub_463500"  << " " << v0  << " " << v1  << " " << v2  << " " << v3  << " " << v4 <<  " -> " << ret_val << '\n';
#endif
    return ret_val;
}

static void TGEN_CDECL sub_46B620_wrapc()
{
    sub_46B620();
#ifdef VERBOSE_WRAP
    std::cout << "sub_46B620" << '\n';
#endif
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
{"_libm_sse2_exp_precise", Import{(void*)&_libm_sse2_exp_precise_wrapc}},
{"_libm_sse2_acos_precise", Import{(void*)&_libm_sse2_acos_precise_wrapc}},
{"_libm_sse2_asin_precise", Import{(void*)&_libm_sse2_asin_precise_wrapc}},
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
Patch{(void*)&sub_4120D0_wrapc, 0x412710, 0},
Patch{(void*)&sub_4C6970_wrapc, 0x4C6580, 0},
Patch{(void*)&sub_4D8B70_wrapc, 0x4D8F70, 0},
Patch{(void*)&sub_469210_wrapc, 0, SQLITE_TABLE+4*72},
Patch{(void*)&sub_4698F0_wrapc, 0, SQLITE_TABLE+4*10},
Patch{(void*)&sub_46A090_wrapc, 0, SQLITE_TABLE+4*94},
Patch{(void*)&sub_46AE00_wrapc, 0, SQLITE_TABLE+4*57},
Patch{(void*)&sub_46A3A0_wrapc, 0, SQLITE_TABLE+4*20},
Patch{(void*)&sub_46A320_wrapc, 0, SQLITE_TABLE+4*19},
Patch{(void*)&sub_4633C0_wrapc, 0, SQLITE_TABLE+4*16},
Patch{(void*)&sub_469530_wrapc, 0, SQLITE_TABLE+4*2},
Patch{(void*)&sub_468330_wrapc, 0, SQLITE_TABLE+4*70},
Patch{(void*)&sub_463500_wrapc, 0, SQLITE_TABLE+4*55},
Patch{(void*)&sub_46B620_wrapc, 0, SQLITE_TABLE+4*96}
}
);