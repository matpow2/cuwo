/*
some tgen structs for reference
*/

struct ItemWithHeader
{
    uint32_t header;
    ItemData data;
};

struct ItemWithHeaderList
{
    ItemWithHeader * vec_start;
    ItemWithHeader * vec_end;
    ItemWithHeader * vec_capacity;
};

struct ItemWithHeaderLists
{
    ItemWithHeaderList * vec_start;
    ItemWithHeaderList * vec_end;
    ItemWithHeaderList * vec_capacity;
};

struct StaticEntity
{
    StaticEntityHeader header;
    ItemWithHeaderLists item_with_header_lists;
    uint32_t something1;
    ItemData item; // (88)
    uint32_t something2;
    uint32_t something3;
    uint32_t something4;
    uint32_t something5;
    uint32_t something6;
    uint32_t something7;
};

struct ItemWithExtra // size 304
{
    ItemWithHeaderLists lists;
    _DWORD something1;
    ItemData item;
    _DWORD something_added1;
    _DWORD something_added2;
};

struct DynamicEntity /* size 4336 */
{
  _DWORD vtable;
  char pad1[4];
  float something1;
  char something2[4]; // padding?
  __int64 x;
  __int64 y;
  __int64 z;
  char hostile_type;
  char something3[3];
  _DWORD entity_type;
  char class_type;
  char specialization;
  char pad2[2];
  _DWORD level;
  _DWORD something33;
  _DWORD something34;
  _DWORD something35;
  _DWORD something36;
  __int64 entity_id;
  char enable_flag_8_flags_1;
  char pad3[3];
  float body_yaw;
  char power_base;
  char pad4[3];
  char not_used19;
  char something10_or_pad[3];
  _DWORD not_used20;
  _DWORD not_used21;
  _DWORD not_used22;
  _DWORD something14;
  _DWORD something15;
  AppearanceData appearance;
  EquipmentData items[13];
  float max_hp_multiplier;
  float shoot_speed;
  float damage_multiplier;
  float armor_multiplier;
  float resi_multiplier;
  ItemWithExtra extra_item;
  _DWORD some_12b_p;
  _DWORD some_vec_start;
  _DWORD some_vec_end;
  _DWORD some_vec_cap;
  _DWORD id_vec_1_start;
  _DWORD id_vec_1_end;
  _DWORD id_vec_1_cap;
  _DWORD id_vec_2_end_old;
  _DWORD id_vec_2_start;
  _DWORD id_vec_2_end;
  _DWORD id_vec_2_cap;
  _DWORD unknown_or_not_used4;
  char name[16];
  _DWORD something30;
  _DWORD something31;
  _DWORD something32;
  char something37;
  char pad5[7];
};

struct ChunkParent, size 200
{
  int vtable; // pointer
  int b; // pointer
  int c; // value (size?)
  StaticEntity * static_entities_start;
  StaticEntity * static_entities_end;
  _DWORD static_entities_capacity;
  _DWORD some1_4bytep_start; // something with normal entities
  _DWORD some1_4bytep_end; // something with normal entities
  _DWORD some1_capacity;
  _DWORD some4_start; // 4bytep
  _DWORD some4_end; // 4bytep
  _DWORD some4_capacity;
  _DWORD chunkitems_start;
  _DWORD chunkitems_end;
  _DWORD chunkitems_capacity;
  _DWORD some9_start;
  _DWORD some9_end;
  _DWORD some9_capacity;
  _DWORD some8_start;
  _DWORD some8_end;
  _DWORD some8_capacity;
  _DWORD some7_start;
  _DWORD some7_end;
  _DWORD some7_capacity;
  _DWORD chunk_x;
  _DWORD chunk_y;
  _DWORD some2_20byte_start;
  _DWORD some2_20byte_end;
  _DWORD some2_capacity;
  _BYTE word74;
  _BYTE has_chunkitems;
  _BYTE byte76;
  _BYTE pad;
  _DWORD dword78;
  _DWORD dword7C;
  _DWORD dword80;
  _BYTE byte84;
  _BYTE pad2[3];
  _DWORD some5_start;
  _DWORD some5_end;
  _DWORD some5_capacity;
  _DWORD some6_start;
  _DWORD some6_end;
  _DWORD some6_capacity;
  _DWORD start_something_dynamic_entities;
  _DWORD dwordA4;
  ChunkEntry *chunk_data;
  _DWORD other_chunk_data;
  struct _RTL_CRITICAL_SECTION rtl_critical_sectionB0;
};