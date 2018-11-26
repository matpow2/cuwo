#include <assert.h>
#include <iostream>
#include "mem.h"
#include "tgen.h"
#include "call.h"
#include "config.h"
#include <stdio.h>

#include "mem32.h"

void * alloc_exec(size_t size)
{
#ifdef _WIN32
    void* ptr = VirtualAllocSmall(0, size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    assert(ptr != NULL);
#else
    void* ptr = mmap_small(0, size, PROT_READ | PROT_WRITE | PROT_EXEC,
                           MAP_ANON | MAP_PRIVATE, -1, 0);
    assert((uintptr_t)ptr <= 0xFFFFFFFF);
    assert(ptr != MAP_FAILED);
#endif
    return ptr;
}

void * alloc_mem(size_t size)
{
#ifdef _WIN32
    void* ptr = VirtualAllocSmall(0, size, MEM_COMMIT, PAGE_READWRITE);
#else
    void * ptr = mmap_small(0, size, PROT_READ | PROT_WRITE,
                            MAP_ANON | MAP_PRIVATE, -1, 0);
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
        if (stack == NULL) {
            stack = alloc_mem(stack_size);
        }
    }

    ~StackAllocator()
    {
        if (stack != NULL) {
            free_mem(stack, stack_size);
        }
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
#ifdef _WIN32
    NT_TIB* tib = (NT_TIB*)__readgsqword(0x30);
    void * old_base = tib->StackBase;
    void * old_limit = tib->StackLimit;
    // void * old_dealloc_stack = tib->DeallocationStack;
    tib->StackBase = base;
    tib->StackLimit = end;
    // tib->DeallocationStack = NULL;
#endif

    _run_with_stack(base, run_callback);

#ifdef _WIN32
    tib->StackBase = old_base;
    tib->StackLimit = old_limit;
    // tib->DeallocationStack = old_dealloc_stack;
#endif
}

#else

void run_with_stack(void (*f)())
{
    tgen_set_thread_breakpoint();
    f();
}

#endif

extern Heap main_heap;
#define CUR_HEAP main_heap
#include "rpmalloc.h"

struct ThreadAlloc
{
    bool has_init;

    ThreadAlloc()
    : has_init(false)
    {
    }

    void init()
    {
        if (has_init)
            return;
        has_init = true;
        rpmalloc_thread_initialize();
    }

    ~ThreadAlloc()
    {
        rpmalloc_thread_finalize();
    }
};

static thread_local ThreadAlloc thread_alloc;

void create_heap(Heap * heap, uint32_t init_size)
{
    heap->init_size = init_size;
    heap->first_alloc = NULL;
    rpmalloc_initialize();
}

void destroy_heap(Heap * heap)
{
    rpmalloc_finalize();
}

void * heap_alloc(uint32_t size)
{
    thread_alloc.init();
    void * ret = rpmalloc(size);
    if (CUR_HEAP.first_alloc == NULL)
        CUR_HEAP.first_alloc = ret;
    return ret;
}

void heap_dealloc(void * mem)
{
    thread_alloc.init();
    rpfree(mem);
}


