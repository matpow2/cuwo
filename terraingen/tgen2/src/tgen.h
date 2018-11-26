#ifndef TERRAINGEN_API
#define TERRAINGEN_API

#include <stddef.h>
#include <stdint.h>
#include <string>
#include "mem.h"
#include "tgendef.h"

void tgen_init();
void tgen_set_seed(uint32_t seed);
void tgen_generate_chunk(uint32_t x, uint32_t y);
void tgen_destroy_chunk(uint32_t x, uint32_t y);
void tgen_destroy_reg_seed(uint32_t x, uint32_t y);
void tgen_destroy_reg_data(uint32_t x, uint32_t y);
Heap * tgen_get_heap();
void tgen_dump_mem(const char * filename);
void tgen_set_path(const char * dir);
// uint32_t tgen_generate_debug_chunk(const char * filename,
//                                    uint32_t x, uint32_t y);
void * tgen_get_manager();
void tgen_read_str(void * addr, std::string & str);
void tgen_read_wstr(void * addr, std::string & str);
void tgen_set_breakpoint(uint32_t addr);
void tgen_set_thread_breakpoint();

// sim
bool sim_add_region(char * reg, uint32_t x, uint32_t y);
bool sim_remove_region(uint32_t x, uint32_t y);
bool sim_add_zone(Zone * zone, uint32_t x, uint32_t y);
bool sim_remove_zone(uint32_t x, uint32_t y);
void sim_step(uint32_t dt);
void sim_remove_creature(Creature * c);
Creature * sim_add_creature(uint64_t id);
void sim_get_creatures(void (*f)(Creature*));
void sim_add_in_hit(HitPacket * p);
void sim_add_in_passive(PassivePacket * p);
PacketQueue * sim_get_in_packets();
PacketQueue * sim_get_out_packets();

inline uint32_t * tgen_get_region_ptr(void * manager,
                                      uint32_t reg_x, uint32_t reg_y)
{
    char * p = (char*)manager + 188;
    return ((uint32_t*)p) + reg_y + reg_x * 1024;
}

inline char * tgen_get_region(void * manager,
                              uint32_t reg_x, uint32_t reg_y)
{
    return (char*)*tgen_get_region_ptr(manager, reg_x, reg_y);
}

inline uint32_t * tgen_get_zone_ptr(char * reg,
                                    uint32_t zone_x, uint32_t zone_y)
{
    char * p = reg + 65560;
    zone_x %= 64;
    zone_y %= 64;
    return ((uint32_t*)p) + zone_y + zone_x * 64;
}

inline Zone * tgen_get_zone(char * reg, uint32_t zone_x, uint32_t zone_y)
{
    uint32_t * p = tgen_get_zone_ptr(reg, zone_x, zone_y);
    return (Zone*)*p;
}

#endif // TERRAINGEN_API
