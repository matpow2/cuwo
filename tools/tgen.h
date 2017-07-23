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

struct StaticEntityHeader
{
  uint32 entity_type;
  char pad[4];
  qvec3 pos;
  uint32 orientation;
  vec3 size;
  uint8 closed;
  char pad[3];
  uint32 time_offset;
  uint32 something8;
  char pad2[4]; // 64bit padding
  uint64 user_id;
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

struct Spawn /* size 4336 */
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
  uint64_t entity_id;
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
  ItemData items[13];
  float max_hp_multiplier;
  float shoot_speed;
  float damage_multiplier;
  float armor_multiplier;
  float resi_multiplier;
  ItemWithExtra extra_item;
  _DWORD some_12b_p;
  _DWORD some_vec_start;
  _DWORD some_vec_end;
  _DWORD some_vec_capacity;
  _DWORD id_vec_1_start;
  _DWORD id_vec_1_end;
  _DWORD id_vec_1_capacity;
  _DWORD id_vec_2_end_old;
  _DWORD id_vec_2_start;
  _DWORD id_vec_2_end;
  _DWORD id_vec_2_capacity;
  _DWORD unknown_or_not_used4;
  char name[16];
  _DWORD something30;
  _DWORD something31;
  _DWORD something32;
  char something37;
  char pad5[7];
};

struct CriticalSection
{
  char * DebugInfo;
  _DWORD LockCount;
  _DWORD RecursionCount;
  _DWORD OwningThread;
  _DWORD LockSemaphore;
  _DWORD SpinCount;
};

struct Color
{
  uint8 r;
  uint8 g;
  uint8 b;
  uint8 a;
};

struct Field
{
  unsigned int vtable;
  float f1;
  float f2;
  float f3;
  unsigned int a;
  unsigned int b;
  Color * data;
  unsigned int size;
};

struct ChunkItemData
{
  ItemData item_data;
  qvec3 pos;
  float rotation;
  float scale;
  uint8 something3;
  char gap[3];
  uint32 drop_time;
  uint32 something5;
  uint32 something6;
};

struct Zone // size 200
{
  int vtable; // pointer
  int b; // pointer
  int c; // value (size?)
  StaticEntity * static_entities_start;
  StaticEntity * static_entities_end;
  _DWORD static_entities_capacity;
  Spawn ** spawns_start;
  Spawn ** spawns_end;
  _DWORD spawns_capacity;
  _DWORD some4_start; // 4bytep
  _DWORD some4_end; // 4bytep
  _DWORD some4_capacity;
  ChunkItemData * items_start;
  ChunkItemData * items_end;
  _DWORD items_capacity;
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
  _DWORD some2_20byte_capacity;
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
  Field * fields;
  _DWORD other_chunk_data;
  CriticalSection crit_sec;
};

struct SomethingCreature
{
  _DWORD dword0;
  _DWORD dword4;
  _DWORD dword8;
  _DWORD dwordC;
  _DWORD dword10;
  _DWORD dword14;
  _DWORD dword18;
  _DWORD dword1C;
  _DWORD dword20;
  _DWORD dword24;
  _DWORD dword28;
  _DWORD dword2C;
  _DWORD dword30;
  _DWORD dword34;
  _DWORD dword38;
  _DWORD dword3C;
  _DWORD dword40;
  _DWORD dword44;
  _DWORD dword48;
  _DWORD dword4C;
  _DWORD dword50;
  _DWORD dword54;
  _DWORD dword58;
  _DWORD dword5C;
  _DWORD dword60;
  _DWORD dword64;
  _DWORD dword68;
  _DWORD dword6C;
  _DWORD dword70;
  _DWORD dword74;
  _DWORD dword78;
  _DWORD dword7C;
  _DWORD dword80;
  _DWORD dword84;
  _DWORD dword88;
  _DWORD dword8C;
  _DWORD dword90;
  _DWORD dword94;
  _DWORD dword98;
  _DWORD dword9C;
  _DWORD dwordA0;
  _DWORD dwordA4;
  _DWORD dwordA8;
  _DWORD dwordAC;
  _DWORD dwordB0;
  _DWORD dwordB4;
  _DWORD dwordB8;
  _DWORD dwordBC;
  _BYTE gapC0[4];
  _DWORD dwordC4;
  _DWORD dwordC8;
  _DWORD dwordCC;
  _DWORD dwordD0;
  _DWORD dwordD4;
  _DWORD dwordD8;
  _DWORD dwordDC;
  _BYTE gapE0[4];
  _DWORD dwordE4;
  _DWORD dwordE8;
  _BYTE gapEC[1920];
  _DWORD dword86C;
  _DWORD dword870;
  _DWORD dword874;
  _BYTE byte878;
  _BYTE gap[7];
  _DWORD dword880;
  _DWORD dword884;
  _DWORD dword888;
  _DWORD dword88C;
};

struct Creature
{
  _DWORD vtable;
  _BYTE f4[4];
  uint64_t entity_id;
  EntityData entity_data;
  _DWORD ptr32_1178;
  _DWORD dword117C;
  _DWORD dword1180;
  _DWORD dword1184;
  _DWORD dword1188;
  _DWORD dword118C;
  _DWORD dword1190;
  float float1194;
  float float1198;
  _DWORD dword119C;
  _BYTE f11A0[12];
  _DWORD mapptr24_11AC;
  _DWORD dword11B0;
  _DWORD mapptr24_11B4;
  _DWORD dword11B8;
  _BYTE f11BC[4];
  _DWORD dword11C0;
  _DWORD dword11C4;
  _DWORD dword11C8;
  _DWORD dword11CC;
  _DWORD dword11D0;
  _DWORD dword11D4;
  _DWORD dword11D8;
  ItemWithExtra item_with_extra;
  _DWORD ptr308_130C;
  _DWORD dword1310;
  _DWORD dword1314;
  _DWORD dword1318;
  _BYTE f131C[52];
  _DWORD dword1350;
  _DWORD dword1354;
  _DWORD dword1358;
  _DWORD dword135C;
  _DWORD dword1360;
  _DWORD dword1364;
  _BYTE f1368[12];
  _DWORD dword1374;
  _DWORD dword1378;
  _DWORD dword137C;
  _BYTE f1380[24];
  _DWORD dword1398;
  _DWORD mapptr24_139C;
  _DWORD dword13A0;
  _DWORD creature_map;
  _DWORD dword13A8;
  _DWORD creature_map2;
  _DWORD dword13B0;
  _DWORD dword13B4;
  _BYTE byte13B8;
  _BYTE f13B9[3];
  _DWORD dword13BC;
  _BYTE byte13C0;
  _BYTE f13C1[3];
  _DWORD dword13C4;
  _DWORD dword13C8;
  _DWORD dword13CC;
  _DWORD dword13D0;
  _DWORD dword13D4;
  float dword13D8;
  _DWORD dword13DC;
  _DWORD dword13E0;
  _DWORD behaviour;
  _DWORD dword13E8;
  _DWORD dword13EC;
  _DWORD dword13F0;
  _DWORD dword13F4;
  _DWORD dword13F8;
  _DWORD dword13FC;
  _DWORD dword1400;
  _DWORD dword1404;
  _DWORD dword1408;
  _DWORD mapptr52_140C;
  _DWORD dword1410;
  _DWORD mapptr28_1414;
  _DWORD dword1418;
  _DWORD dword141C;
  _DWORD dword1420;
  _DWORD dword1424;
  _BYTE f1428[48];
  _DWORD dword1458;
  _DWORD dword145C;
  _DWORD ptr20_1460;
  _DWORD dword1464;
  _DWORD mapptr20_1468;
  _DWORD dword146C;
  _DWORD ptr20_1470;
  _DWORD dword1474;
  _DWORD dword1478;
  _DWORD dword147C;
  _DWORD dword1480;
  _DWORD dword1484;
  _DWORD dword1488;
  _DWORD dword148C;
  _DWORD dword1490;
  _DWORD dword1494;
  SomethingCreature som_c;
  _DWORD dword1D28;
  _DWORD float1D2C;
  _BYTE f1D30[8];
  _BYTE byte1D38;
  _BYTE f1D39[3];
  _DWORD dword1D3C;
  _DWORD dword1D40;
  _DWORD dword1D44;
  _WORD word1D48;
  _BYTE f1D4A[2];
  _DWORD dword1D4C;
  _DWORD dword1D50;
  _WORD word1D54;
  _BYTE byte1D56;
  _BYTE f1D57[1];
  _WORD word1D58;
  _BYTE f1D5A[2];
  char char1D5C[256];
  _DWORD dword1E5C;
};
