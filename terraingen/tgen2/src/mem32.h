#ifndef TGEN_MEM32_H
#define TGEN_MEM32_H

#include "config.h"
#include <assert.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#endif


#ifdef _WIN64
// from LuaJIT
/* Undocumented, but hey, that's what we all love so much about Windows. */
typedef long (*PNTAVM)(HANDLE handle, PVOID *addr, ULONG_PTR zbits,
                       PSIZE_T size, ULONG alloctype, ULONG prot);
static PNTAVM ntavm;

/* Number of top bits of the lower 32 bits of an address that must be zero.
** Apparently 0 gives us full 64 bit addresses and 1 gives us the lower 2GB.
*/
#define NTAVM_ZEROBITS      1

static void * VirtualAllocSmall(void * ptr,
                                SIZE_T dwSize,
                                DWORD flAllocationType,
                                DWORD flProtect)
{
    if (ntavm == NULL) {
        ntavm = (PNTAVM)GetProcAddress(GetModuleHandleA("ntdll.dll"),
                                       "NtAllocateVirtualMemory");
    }
    LPVOID ret = ptr;
    long st = ntavm(INVALID_HANDLE_VALUE, &ret, NTAVM_ZEROBITS, &dwSize,
                    flAllocationType, flProtect);
    if (st != 0) {
        // SetLastError(RtlNtStatusToDosError(st));
        ret = NULL;
    }
    assert((uint64_t)ret <= 0xFFFFFFFF);
    return ret;
}
#elif defined(_WIN32)
#define VirtualAllocSmall VirtualAlloc
#endif

#ifdef IS_X64
#define EXTRA_MMAP_FLAG MAP_32BIT
#else
#define EXTRA_MMAP_FLAG (0)
#endif

#define mmap_small(addr, len, prot, flags, fd, offset) \
        mmap(addr, len, prot, (flags) | EXTRA_MMAP_FLAG, fd, offset)

#endif // TGEN_MEM32_H
