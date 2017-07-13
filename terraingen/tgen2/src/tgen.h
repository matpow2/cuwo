#ifndef TERRAINGEN_API
#define TERRAINGEN_API

#include <stddef.h>
#include <stdint.h>
#include <string>

void tgen_init();
void tgen_set_seed(uint32_t seed);
void * tgen_generate_chunk(uint32_t x, uint32_t y);
void * tgen_get_heap_base();
void tgen_dump_mem(const char * filename);
void tgen_set_path(const char * dir);
// uint32_t tgen_generate_debug_chunk(const char * filename,
//                                    uint32_t x, uint32_t y);
void * tgen_get_manager();
void tgen_read_str(void * addr, std::string & str);
void tgen_read_wstr(void * addr, std::string & str);

#endif // TERRAINGEN_API
