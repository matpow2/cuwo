#include <assert.h>
#include <iostream>
#include "mem.h"
#include "tgen.h"
#include "call.h"
#include "config.h"
#include <stdio.h>

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

static thread_local void * stack;
static const uint32_t stack_size = 1024 * 1024 * 2;

struct StackAllocator
{
    static void alloc()
    {
        if (stack == NULL)
            stack = alloc_mem(stack_size);
    }

    ~StackAllocator()
    {
        if (stack != NULL)
            free_mem(stack, stack_size);
    }
};

static thread_local StackAllocator stack_alloc;

static thread_local void (*wrap_f)();

static void run_callback()
{
    tgen_set_thread_breakpoint();
    wrap_f();
}

void run_with_stack(void (*f)())
{
    wrap_f = f;
    stack_alloc.alloc();
    void * end = stack;
    void * base = (char*)end + stack_size;
    _run_with_stack(base, end, run_callback);
}

#else

void run_with_stack(void (*f)())
{
    tgen_set_thread_breakpoint();
    f();
}

#endif

thread_local Heap * current_heap = NULL;
extern Heap main_heap;
extern Heap sim_heap;

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
        if (current_heap == &sim_heap)
            std::cout << "Sim heap\n";
        else if (current_heap == &main_heap)
            std::cout << "Main heap\n";
        else
            std::cout << "Gen heap\n";
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


