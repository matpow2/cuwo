#ifndef TGEN_MEM_H
#define TGEN_MEM_H

#include <functional>

extern void * manager_data;

void * alloc_exec(size_t size);
void * alloc_mem(size_t size);
void free_mem(void * ptr, size_t size);
void read_protect_memory(void * ptr, size_t size);
void write_protect_memory(void * ptr, size_t size, bool exec);
void unwrite_protect_memory(void * ptr, size_t size, bool exec);
void run_with_stack(void (*f)());

struct SavedHeap
{
    char * heap;
    uint32_t heap_size;
    void * state;
};

void save_heap(SavedHeap * data);
void restore_heap(const SavedHeap * data);
void * heap_alloc(uint32_t size);
void heap_dealloc(void * p);

#endif // TGEN_MEM_H
