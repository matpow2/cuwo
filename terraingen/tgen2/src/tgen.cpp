#include <iostream>
#include <algorithm>
#include <string>
#include "mem.h"
#include "call.h"
#include "msvcstring.h"
#include <fstream>
#include "tgen.h"

static uint32_t global_seed = 0;
static std::string translated_path;
static std::string data_path = "../../../data/";

uint32_t get_seed()
{
    return global_seed;
}

const char * translate_path(char * path)
{
    translated_path = path;
    std::replace(translated_path.begin(), translated_path.end(), '\\', '/');
    size_t pos = translated_path.find_last_of("/");
    if (pos != std::string::npos) {
        translated_path = translated_path.substr(pos + 1);
    }
    translated_path = data_path + translated_path;
    return translated_path.c_str();
}

Heap main_heap;
Heap sim_heap;
Heap * gen_heap;
static uint32_t tgen_generate_chunk_x;
static uint32_t tgen_generate_chunk_y;
static void tgen_generate_chunk_call()
{
    uint32_t x = tgen_generate_chunk_x;
    uint32_t y = tgen_generate_chunk_y;

    restore_heap(&main_heap);
    set_heap(gen_heap);

    call_x86_thiscall_3(
        get_mem_va(VA_GENERATOR), (uint32_t)main_heap.first_alloc, x, y);
}

bool sim_add_region(char * region, uint32_t x, uint32_t y)
{
    uint32_t * r = tgen_get_region_ptr(sim_heap.first_alloc, x, y);
    if (*r != 0) {
        std::cout << "sim_add_region: Region already exists\n";
        return false;
    }
    *r = (uint32_t)region;
    return true;
}

bool sim_remove_region(uint32_t x, uint32_t y)
{
    uint32_t * r = tgen_get_region_ptr(sim_heap.first_alloc, x, y);
    if (*r == 0) {
        std::cout << "sim_remove_region: Could not find region\n";
        return false;
    }
    *r = 0;
    return true;
}

bool sim_add_zone(Zone * z, uint32_t x, uint32_t y)
{
    uint32_t * r = tgen_get_region_ptr(sim_heap.first_alloc, x / 64, y / 64);
    if (*r == 0) {
        std::cout << "sim_add_zone: Could not find region\n";
        return false;
    }
    uint32_t * zz = tgen_get_zone_ptr((char*)*r, x, y);
    if (*zz != 0) {
        std::cout << "sim_add_zone: Zone already exists\n";
        return false;
    }
    *zz = (uint32_t)z;
    return true;
}

bool sim_remove_zone(uint32_t x, uint32_t y)
{
    uint32_t * r = tgen_get_region_ptr(sim_heap.first_alloc, x / 64, y / 64);
    if (*r == 0) {
        std::cout << "sim_remove_zone: Could not find region\n";
        return false;
    }
    uint32_t * zz = tgen_get_zone_ptr((char*)*r, x, y);
    if (*zz == 0) {
        std::cout << "sim_remove_zone: Could not find zone\n";
        return false;
    }
    *zz = 0;
    return true;
}

bool is_nil(uint32_t ptr)
{
    return *((char*)ptr + 13) == 1;
}

uint32_t get_right(uint32_t ptr)
{
    return *(uint32_t*)((char*)ptr + 8);
}


uint32_t get_left(uint32_t ptr)
{
    return *(uint32_t*)((char*)ptr + 0);
}


uint32_t get_parent(uint32_t ptr)
{
    return *(uint32_t*)((char*)ptr + 4);
}

uint32_t get_min(uint32_t ptr)
{    
    while (!is_nil(get_left(ptr)))
        ptr = get_left(ptr);
    return ptr;
}


typedef void (*map_func)(char * addr);


void walk_map(char * addr, map_func func)
{
    uint32_t ptr = get_left(*(uint32_t*)addr);
    uint32_t test_ptr;
    while (!is_nil(ptr)) {
        func((char*)(ptr + 16));
        if (!is_nil(get_right(ptr))) {
            ptr = get_min(get_right(ptr));
        } else {
            while (true) {
                test_ptr = get_parent(ptr);
                if (is_nil(test_ptr) || ptr != get_right(test_ptr))
                    break;
                ptr = test_ptr;
            }
            ptr = test_ptr;
        }
    }
}

static void show_creatures(char * addr)
{
    uint64_t id = *(uint64_t*)addr;

    uint32_t p = *(uint32_t*)(addr + 8);
    Creature * c = (Creature*)p;
    std::cout << "creature: " << id << " " << c->entity_data.velocity[0] << '\n';
}

static uint64_t add_id;
static Creature * add_creature_return;

static uint32_t get_creature_map()
{
    return (uint32_t)sim_heap.first_alloc + 4;
}

static void sim_add_creature_call()
{
    set_heap(&sim_heap);
    uint64_t id = add_id;
    Creature * creature = (Creature*)alloc_mem(sizeof(Creature));
    // init_creature
    call_x86_thiscall_2(get_mem_va(0x406400), (uint32_t)creature,
                        (uint32_t)&id);

    // get_creature_ptr
    uint32_t p = call_x86_thiscall_2(get_mem_va(0x402B10),
                                     get_creature_map(),
                                     (uint32_t)&id);
    *(uint32_t*)p = (uint32_t)creature;
    add_creature_return = creature;
}

Creature * sim_add_creature(uint64_t id)
{
    add_id = id;
    run_with_stack(sim_add_creature_call);
    return add_creature_return;
}

static Creature * remove_creature;

static void sim_remove_creature_call()
{
    set_heap(&sim_heap);

    Creature * c = remove_creature;

    // del_creature_in_map
    call_x86_thiscall_2(get_mem_va(0x530560),
                        get_creature_map(),
                        (uint32_t)&c->entity_id);

    uint32_t dtor = ((uint32_t*)c->vtable)[0];
    // dtor(this, delete_this)
    call_x86_thiscall_2((void*)dtor, (uint32_t)c, 0);

    free_mem(c, sizeof(Creature));
}

void sim_remove_creature(Creature * c)
{
    remove_creature = c;
    run_with_stack(sim_remove_creature_call);
}

static void (*get_callback)(Creature*);

static void sim_get_creatures_cb(char * addr)
{
    uint32_t p = *(uint32_t*)(addr + 8);
    Creature * c = (Creature*)p;
    get_callback(c);
}

void sim_get_creatures(void (*f)(Creature*))
{
    get_callback = f;
    walk_map((char*)get_creature_map(), sim_get_creatures_cb);
}

static uint32_t step_dt;
static PacketQueue * in_queue;
static bool in_queue_init = false;
static PacketQueue * out_queue;

static void sim_init_in_queue()
{
    set_heap(&sim_heap);
    call_x86_thiscall_1(get_mem_va(INIT_PACKET_QUEUE), (uint32_t)in_queue);
}

static void sim_step_call()
{
    // *(uint8_t*)get_mem_va(0x4CF01B) = 0xCC;
    // *(uint8_t*)get_mem_va(0x4CEEF2) = 0xCC;

    set_heap(&sim_heap);

    if (!in_queue_init)
        sim_init_in_queue();
    in_queue_init = false;

    static bool reset_out_queue = false;
    if (reset_out_queue)
        call_x86_thiscall_1(get_mem_va(0x4239F0), (uint32_t)out_queue);
    reset_out_queue = true;

    call_x86_thiscall_1(get_mem_va(INIT_PACKET_QUEUE), (uint32_t)out_queue);
    call_x86_thiscall_4(get_mem_va(WORLD_SIM),
                        (uint32_t)sim_heap.first_alloc,
                        step_dt, (uint32_t)out_queue, (uint32_t)in_queue);
    call_x86_thiscall_1(get_mem_va(0x4239F0), (uint32_t)in_queue);
    // walk_map((char*)sim_heap.first_alloc + 4, show_creatures);
}

PacketQueue * sim_get_in_packets()
{
    if (in_queue == NULL)
        in_queue = (PacketQueue*)alloc_mem(sizeof(PacketQueue));
    return in_queue;
}

static PacketQueue * sim_prepare_in_packets()
{
    PacketQueue * q = sim_get_in_packets();
    if (!in_queue_init) {
        run_with_stack(sim_init_in_queue);
        in_queue_init = true;
    }
    return q;
}

void sim_add_in_hit(HitPacket * p)
{
    PacketQueue * q = sim_prepare_in_packets();
    set_heap(&sim_heap);
    HitPacketList * l =
        (HitPacketList*)heap_alloc(sizeof(HitPacketList));

    HitPacketList * head = (HitPacketList*)q->player_hits;
    l->next = (uint32_t)head->next;
    l->prev = 0;
    l->data = *p;
    head->next = (uint32_t)l;
    q->player_hits_size++;
}

void sim_add_in_passive(PassivePacket * p)
{
    PacketQueue * q = sim_prepare_in_packets();
    set_heap(&sim_heap);
    PassivePacketList * l =
        (PassivePacketList*)heap_alloc(sizeof(PassivePacketList));

    PassivePacketList * head = (PassivePacketList*)q->passive_packets;
    l->next = (uint32_t)head->next;
    l->prev = 0;
    l->data = *p;
    head->next = (uint32_t)l;
    q->passive_packets_size++;
}

PacketQueue * sim_get_out_packets()
{
    if (out_queue == NULL)
        out_queue = (PacketQueue*)alloc_mem(sizeof(PacketQueue));
    return out_queue;
}

void sim_step(uint32_t dt)
{
    sim_get_in_packets();
    sim_get_out_packets();

    step_dt = dt;
    run_with_stack(sim_step_call);
}

Heap * tgen_generate_chunk(uint32_t x, uint32_t y)
{
    tgen_generate_chunk_x = x;
    tgen_generate_chunk_y = y;
    gen_heap = new Heap;
    create_heap(gen_heap, GEN_HEAP_SIZE);
    run_with_stack(tgen_generate_chunk_call);
    return gen_heap;
}

void tgen_destroy_chunk(Heap * ret)
{
    destroy_heap(ret);
}

void tgen_set_path(const char * dir)
{
    data_path = dir;
}

void tgen_set_seed(uint32_t seed)
{
    global_seed = seed;
}

void tgen_set_breakpoint(uint32_t addr)
{
    *(uint8_t*)get_mem_va(addr) = 0xCC;
}

#ifdef _WIN32
#include <windows.h>
#endif

void tgen_dump_mem(const char * filename)
{
#ifdef _WIN32
    std::ofstream fp(filename, std::ios::binary | std::ios::out);
    const void * ptr = (const void*)0;
    const void * end = (const void*)0xFFFFFFFF;
    MEMORY_BASIC_INFORMATION info;
    const char * old = (const char*)0;
    while (ptr < end) {
        if (VirtualQuery(ptr, &info, sizeof(info)) != sizeof(info))
            break;
        // std::cout << "reg: " << info.AllocationProtect << " " <<
        //     info.State << ' ' << info.Protect << ' '
        //     << info.Type << '\n';
        const char * base = (const char*)info.BaseAddress;
        if (info.State != MEM_FREE && info.Protect != 0) {
            // std::cout << "seek\n";
            fp.seekp((uint32_t)base);
            // std::cout << "tellp: " << fp.tellp() << ' ' <<
            //     (uint32_t)base << '\n';
            fp.write(base, info.RegionSize);
            // std::cout << "written\n";
            old = base;
        }
        ptr = (const void*)(base + info.RegionSize);
    }
    // std::cout << "done\n";
#endif
}

void * tgen_get_heap_base()
{
    return main_heap.buffer;
}

void * tgen_get_manager()
{
    return main_heap.first_alloc;
}

void tgen_read_str(void * addr, std::string & str)
{
    ((basic_string_char*)addr)->str(str);
}

void tgen_read_wstr(void * addr, std::string & str)
{
    ((basic_string_wchar*)addr)->str(str);
}
