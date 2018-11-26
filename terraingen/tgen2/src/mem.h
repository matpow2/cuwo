#ifndef TGEN_MEM_H
#define TGEN_MEM_H

void * alloc_exec(size_t size);
void * alloc_mem(size_t size);
void free_mem(void * ptr, size_t size);
void read_protect_memory(void * ptr, size_t size);
void write_protect_memory(void * ptr, size_t size, bool exec);
void unwrite_protect_memory(void * ptr, size_t size, bool exec);
void run_with_stack(void (*f)());

struct Heap
{
    uint32_t init_size;
    void * first_alloc;
};

void create_heap(Heap * heap, uint32_t size);
void destroy_heap(Heap * heap);
void * heap_alloc(uint32_t size);
void heap_dealloc(void * p);

#endif // TGEN_MEM_H
