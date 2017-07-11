#ifndef TGEN_CALL_H
#define TGEN_CALL_H

#include "config.h"

#ifdef _WIN32
#define TGEN_VECTORCALL __vectorcall
#define TGEN_THISCALL __fastcall
#define TGEN_STDCALL __stdcall
#define TGEN_CDECL
#else
#define TGEN_THISCALL __attribute__((fastcall))
#define TGEN_STDCALL __attribute__((stdcall))
#define TGEN_VECTORCALL __attribute__((fastcall, sseregparm))
#define TGEN_CDECL
#endif

void * get_mem_va(uint32_t addr);

#ifdef _WIN32
#ifdef IS_X64
#include "../tools/wrapper_msvc_x64.h"
#else
#include "../tools/wrapper_msvc.h"
#endif
#else
#ifdef IS_X64
#include "../tools/wrapper_x64.h"
#else
#include "../tools/wrapper.h"
#endif
#endif

#ifndef IS_X64
inline uint32_t call_x86_cdecl_0(void * p)
{
    uint32_t (*fp)() = (uint32_t (*)())p;
    uint32_t ret = fp();
    return ret;
}

inline uint32_t call_x86_thiscall_3(void * p, uint32_t ecx,
                                    uint32_t arg1, uint32_t arg2)
{
    uint32_t (TGEN_THISCALL *fp)(uint32_t, uint32_t, uint32_t, uint32_t) =
        (uint32_t (TGEN_THISCALL *)(uint32_t, uint32_t, uint32_t, uint32_t))p;
    uint32_t ret = fp(ecx, 0, arg1, arg2);
    return ret;
}
#endif

#endif // TGEN_CALL_H
