#include <assert.h>
#include <iostream>
#include "mem.h"
#include "config.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#include <pthread.h>
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

void * VirtualAllocSmall(SIZE_T dwSize,
                         DWORD flAllocationType,
                         DWORD flProtect)
{
    if (ntavm == NULL) {
        ntavm = (PNTAVM)GetProcAddress(GetModuleHandleA("ntdll.dll"),
                                       "NtAllocateVirtualMemory");
    }
    DWORD olderr = GetLastError();
    void *ptr = NULL;
    long st = ntavm(INVALID_HANDLE_VALUE, &ptr, NTAVM_ZEROBITS, &dwSize,
                    flAllocationType, flProtect);
    assert((uint32_t)ptr <= 0xFFFFFFFF);
    SetLastError(olderr);
    return st == 0 ? ptr : NULL;
}

#elif _WIN32

void * VirtualAllocSmall(SIZE_T dwSize,
                         DWORD flAllocationType,
                         DWORD flProtect)
{
    return VirtualAlloc(0, dwSize, flAllocationType, flProtect);
}

#endif

void * alloc_exec(size_t size)
{
#ifdef _WIN32
    void* ptr = VirtualAllocSmall(size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    assert(ptr != NULL);
#else
    void* ptr = mmap(0, size, PROT_READ | PROT_WRITE | PROT_EXEC,
                     MAP_ANON | MAP_PRIVATE | MAP_32BIT, -1, 0);
    assert((uintptr_t)ptr <= 0xFFFFFFFF);
    assert(ptr != MAP_FAILED);
#endif
    return ptr;
}

void * alloc_mem(size_t size)
{
#ifdef _WIN32
    void* ptr = VirtualAllocSmall(size, MEM_COMMIT, PAGE_READWRITE);
#else
    void * ptr = mmap(0, size, PROT_READ | PROT_WRITE,
                      MAP_ANON | MAP_PRIVATE | MAP_32BIT, -1, 0);
    assert((uintptr_t)ptr <= 0xFFFFFFFF);
    assert(ptr != MAP_FAILED);
#endif
    return ptr;
}

void free_mem(void * ptr, size_t size)
{
#ifdef _WIN32
    if (!VirtualFree(ptr, 0, MEM_RELEASE))
        assert(false);
#else
    int retval = munmap(ptr, size);
    assert(retval == 0);
#endif
}

void read_protect_memory(void * ptr, size_t size)
{
#ifdef _WIN32
    DWORD old;
    if (!VirtualProtect(ptr, size, PAGE_NOACCESS, &old))
        assert(false);
#else
    int retval = mprotect(ptr, size, PROT_NONE);
    assert(retval == 0);
#endif
}

void write_protect_memory(void * ptr, size_t size, bool exec)
{
#ifdef _WIN32
    DWORD old;
    if (!VirtualProtect(ptr, size,
                        exec ? PAGE_EXECUTE_READ : PAGE_READONLY, &old))
        assert(false);
#else
    int retval = mprotect(ptr, size,
                          exec ? (PROT_READ | PROT_EXEC) : PROT_READ);
    assert(retval == 0);
#endif
}

void unwrite_protect_memory(void * ptr, size_t size, bool exec)
{
#ifdef _WIN32
    DWORD old;
    if (!VirtualProtect(ptr, size,
                        exec ?
                        PAGE_EXECUTE_READWRITE : PAGE_READWRITE,
                        &old))
        assert(false);
#else
    int retval = mprotect(ptr, size,
                          exec ? (PROT_READ | PROT_WRITE | PROT_EXEC) :
                                 (PROT_WRITE | PROT_READ));
    assert(retval == 0);
#endif
}

#ifdef IS_X64

#ifdef _WIN32

static void (*wrap_f)();

DWORD CALLBACK thread_wrap(LPVOID)
{
    wrap_f();
	return 0;
}

typedef LONG NTSTATUS;
typedef DWORD KPRIORITY;
typedef WORD UWORD;

typedef struct _CLIENT_ID
{
    PVOID UniqueProcess;
    PVOID UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef struct _THREAD_BASIC_INFORMATION
{
    NTSTATUS                ExitStatus;
    PVOID                   TebBaseAddress;
    CLIENT_ID               ClientId;
    KAFFINITY               AffinityMask;
    KPRIORITY               Priority;
    KPRIORITY               BasePriority;
} THREAD_BASIC_INFORMATION, *PTHREAD_BASIC_INFORMATION;

enum THREADINFOCLASS
{
    ThreadBasicInformation,
};

typedef NTSTATUS WINAPI NtQueryInformationThread_t(
    HANDLE ThreadHandle, THREADINFOCLASS ThreadInformationClass,
    PVOID ThreadInformation, ULONG ThreadInformationLength,
    PULONG ReturnLength);

void run_with_stack(void (*f)())
{
    wrap_f = f;

    HMODULE dll = LoadLibraryW(L"ntdll.dll");
    auto NtQueryInformationThread =
        (NtQueryInformationThread_t*)
        GetProcAddress(dll, "NtQueryInformationThread");


    DWORD thread_id;
    HANDLE thread = CreateThread(0, ThreadBasicInformation, &thread_wrap, 0,
                                 CREATE_SUSPENDED, &thread_id);

    THREAD_BASIC_INFORMATION bi;
    NtQueryInformationThread(thread, (THREADINFOCLASS)0, &bi,
                             sizeof bi, 0);
    NT_TIB * tib = (NT_TIB*)bi.TebBaseAddress;

    CONTEXT ctx = {};
    ctx.ContextFlags = CONTEXT_ALL;
    GetThreadContext(thread, &ctx);

    const DWORD64 stack_size = 1024 * 1024 * 2;
    void * stack = alloc_mem(stack_size);
    ctx.Rsp = (DWORD64)stack + stack_size -
              ((DWORD64)tib->StackBase - (DWORD64)ctx.Rsp);
    tib->StackBase = (PVOID)((DWORD64)stack + stack_size);
    tib->StackLimit = (PVOID)((DWORD64)stack);
    SetThreadContext(thread, &ctx);

    ResumeThread(thread);
    WaitForSingleObject(thread, INFINITE);
    free_mem(stack, stack_size);
}

#else

static void (*wrap_f)();

static void * thread_start(void *arg)
{
    wrap_f();
}

void run_with_stack(void (*f)())
{
    wrap_f = f;

    pthread_t thr;
    pthread_attr_t attr;
    pthread_attr_t *attrp = &attr;

    pthread_attr_init(&attr);
    int stack_size = 1024 * 1024 * 2;
    void * sp = alloc_mem(stack_size);
    pthread_attr_setstack(&attr, sp, stack_size);
    pthread_create(&thr, attrp, &thread_start, NULL);
    pthread_attr_destroy(attrp);
    pthread_join(thr, NULL);
    free_mem(sp, stack_size);
}

#endif

#else

void run_with_stack(void (*f)())
{
    f();
}

#endif

extern "C" {
    #define HAVE_MORECORE 1
    #define HAVE_MMAP 0
    #define FOOTERS 1
    #define USE_DL_PREFIX
    #define MSPACES 1
    #define MORECORE heap_morecore
    void * heap_morecore(int size);
    #include "dlmalloc.c"

    void * heap_morecore(int size)
    {
        std::cout << "Out of tgen memory!" << std::endl;
        assert(false);
		return NULL;
    }
}

// extern "C" {
//     #define HAVE_MMAP 1
//     #define HAVE_MORECORE 0
//     #define USE_DL_PREFIX
//     #define MMAP heap_mmap
//     #define DIRECT_MMAP heap_mmap
//     #define MUNMAP heap_munmap
//     void * heap_mmap(int size);
//     int heap_munmap(void * ptr, int size);
//     #include "dlmalloc.c"

//     void * heap_mmap(int size)
//     {
//         if (size == 0)
//             return NULL;
//         // std::cout << "Alloc: " << size << '\n';
//         void * ret = alloc_mem(size);

//         if (ret == NULL) {
//             std::cout << "Out of memory" << std::endl;
//             exit(0);
//         }
//         return ret;
//     }

//     int heap_munmap(void * ptr, int size)
//     {
//         if (size == 0)
//             return 0;
//         // std::cout << "Free: " << size << '\n';
//         free_mem(ptr, size);
//         return 0;
//     }
// }

void create_heap(Heap * heap, uint32_t size)
{
    heap->first_alloc = NULL;
    heap->size = size;
    heap->saved = NULL;
    heap->buffer = (unsigned char*)alloc_mem(size);
    heap->ms = (void*)create_mspace_with_base(heap->buffer, size, 0);
}

void save_heap(Heap * heap)
{
    if (heap->saved == NULL)
        heap->saved = (unsigned char*)alloc_mem(heap->size);
    memcpy(heap->saved, heap->buffer, heap->size);
}

void restore_heap(Heap * heap)
{
    memcpy(heap->buffer, heap->saved, heap->size);
}

void destroy_heap(Heap * heap)
{
    free_mem(heap->buffer, heap->size);
}

thread_local Heap * current_heap = NULL;

void set_heap(Heap * heap)
{
    current_heap = heap;
}

void * heap_alloc(uint32_t size)
{
    char * ret = (char*)mspace_malloc((mspace)current_heap->ms, size);
    if (current_heap->first_alloc == NULL)
        current_heap->first_alloc = ret;
    return ret;
}

extern Heap main_heap;

void heap_dealloc(void * mem)
{
    if (mem == NULL)
        return;
    mspace msp = (mspace)current_heap->ms;
    mchunkptr p = mem2chunk(mem);
    mspace fm = (mspace)get_mstate_for(p);
    if (fm != msp) {
        if (fm == (mspace)main_heap.ms) {
            std::cout << "Memory dealloc on main heap\n";
    #ifdef _WIN32
            __debugbreak();
    #endif
        }
    }
    mspace_free((mspace)current_heap->ms, mem);
}


