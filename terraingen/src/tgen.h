#ifndef TERRAINGEN_API
#define TERRAINGEN_API

#include <stddef.h>
#include <stdint.h>
#include "memory.h"

void tgen_init();
void tgen_set_seed(uint32_t seed);
uint32_t tgen_generate_chunk(uint32_t x, uint32_t y);
void tgen_dump_mem(const char * filename);
void tgen_set_path(const char * dir);
unsigned int tgen_generate_debug_chunk(const char * filename,
                                       unsigned int x, unsigned int y);
unsigned int tgen_get_heap_base();


#endif // TERRAINGEN_API
