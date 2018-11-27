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

struct HitPacket
{
  uint64_t entity_id;
  uint64_t target_id;
  float damage;
  uint8_t critical;
  char pad[3];
  uint32_t stun_duration;
  uint32_t something8; // padding maybe?
  qvec3 pos;
  vec3 hit_dir;
  uint8_t skill_hit; // used skill
  uint8_t hit_type;
  uint8_t show_light;
  char pad[1];
};

struct ParticleData
{
  qvec3 pos;
  vec3 accel;
  float color[4];
  float scale;
  uint32_t count;
  uint32_t particle_type;
  float spreading;
  uint32_t something18;
};

struct SoundAction
{
  vec3 pos; // in block coordinates
  uint32_t sound_index;
  float pitch;
  float volume;
};

struct BlockAction
{
  ivec3 block_pos;
  uint8_t color_red;
  uint8_t color_green;
  uint8_t color_blue;
  // v  0 = Invisible, 1 = Solid, 2 = Water, 3 = Flat water, ...
  uint8_t block_type;
  uint32_t something8;
};

struct ShootPacket
{
  uint64_t entity_id;
  int32_t chunk_x;
  int32_t chunk_y;
  uint32_t something5;
  char pad[4];
  qvec3 pos;
  uint32_t something13;
  uint32_t something14;
  uint32_t something15;
  vec3 velocity;
  // rand() something, probably damage multiplier
  // these are not confirmed
  float legacy_damage; // from ext
  // ext: 2-4 depending on mana for boomerangs, otherwise 0.5
  float something20;
  float scale; // from ext
  // old: used stamina? amount of stun?
  float mana; // from ext
  uint32_t particles; // from ext, for crossbow m2
  uint8_t skill; // skill? is 2 for rmb shoot
  char pad[3];
  // from ext: projectile
  // 0: arrow, 1: boomerang, 2: magic, 3: ?, 4: rock
  uint32_t projectile;
  uint8_t something26;
  char pad[3];
  uint32_t something27;
  uint32_t something28;
};

struct PickupAction
{
  uint64_t entity_id; // player who picked up
  ItemData item_data;
};

struct KillAction
{
  uint64_t entity_id; // killer
  uint64_t target_id; // killed
  // is this actually padding? copied as part of MOVQ, but may just be
  // optimization. not used in client, it seems.
  // could also be related to DamageAction, seems to use same list
  // copy implementation
  char pad[4];
  int32_t xp_gained;
};

struct DamageAction
{
  uint64_t target_id;
  uint64_t entity_id;
  float damage;
  char skip[4];
};

struct PassivePacket
{
  uint64_t entity_id;
  uint64_t target_id;
  uint8_t passive_type;
  char pad[3];
  // below not confirmed
  float modifier;
  uint32_t duration;
  char pad[4];
  // equal to source for poison, otherwise 0
  uint64_t target_id2;
};

struct MissionInfo
{
  uint32_t something3;
  uint32_t mission_id;
  uint32_t something5;
  uint32_t monster_id;
  uint32_t quest_level;
  uint8_t something8;
  // 0: ready, 1: progressing, 2: finished
  uint8_t state;
  char pad[2];
  float something10;
  float something11;
  uint32_t chunk_x;
  uint32_t chunk_y;
};

struct MissionPacket
{
  int32_t x; // divide by 8.0 to get region x
  int32_t y; // divide by 8.0 to get region y
  uint32_t something1; // padding?
  uint32_t something2; // also padding???
  MissionInfo info;
};

struct MissionData
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
  MissionInfo info;
  _DWORD dword54;
  _DWORD dword58;
  _BYTE byte5C;
  char pad[3];
};

struct RegionSomething
{
  int field_0;
  int field_4;
  int field_8;
  char field_C;
  char pad[3];
};

struct RegionSeed
{
  _DWORD dword0;
  _DWORD dword4;
  _BYTE byte8;
  char pad[3];
  float floatC;
  float float10;
  _DWORD dword14;
  _DWORD dword18;
};

struct Region
{
  _DWORD vtable;
  char gap4[4];
  _BYTE set_to_one1;
  char gap9[3];
  _DWORD set_to_one2;
  _DWORD dword10;
  _DWORD dword14;
  RegionSomething regsomething[4096];
  Zone * zones[4096];
  MissionData missions[64];
  char byte15A18;
  char pad[3];
  _DWORD dword15A1C;
  _DWORD dword15A20;
  _DWORD dword15A24;
};

// thanks to Ando for this
struct AirshipData
{
  uint64_t entity_id;
  uint8_t something1;
  char pad[3];
  uint32_t something2;
  qvec3 pos;
  vec3 velocity;
  vec3 rotation;
  qvec3 start_pos;
  float path_rotation;
  uint32_t something3;
  qvec3 dest_pos;
  // 0 = goto start pos, 1 = landing, 2 = departing, 3 = goto dest pos.
  uint8_t stage;
  char pad[3];
  uint8_t something4;
  char pad[3];
};

// lists

struct HitPacketList
{
  HitPacketList * next;
  HitPacketList * prev;
  HitPacket data;
};

struct ParticleDataList
{
  ParticleDataList * next;
  ParticleDataList * prev;
  ParticleData data;
};

struct SoundActionList
{
  SoundActionList * next;
  SoundActionList * prev;
  SoundAction data;
};

struct BlockActionList
{
  BlockActionList * next;
  BlockActionList * prev;
  BlockAction data;
};

struct ShootPacketList
{
  ShootPacketList * next;
  ShootPacketList * prev;
  ShootPacket data;
};

struct ChunkItemList
{
  ChunkItemList * next;
  ChunkItemList * prev;
  ChunkItemData data;
};

struct ChunkItemsList
{
  ChunkItemsList * next;
  ChunkItemsList * prev;
  int32_t chunk_x;
  int32_t chunk_y;
  ChunkItemList * data;
};

struct StaticEntityList
{
  StaticEntityList * next;
  StaticEntityList * prev;
  StaticEntityHeader data;
};

struct Items8List_2
{
  Items8List_2 * next;
  Items8List_2 * prev;
  uint8_t data[16];
};

struct Items8List_1
{
  Items8List_1 * next;
  Items8List_1 * prev;
  uint64_t something;
  Items8List_2 data;
};

struct PickupActionList
{
  PickupActionList * next;
  PickupActionList * prev;
  PickupAction data;
};

struct KillActionList
{
  KillActionList * next;
  KillActionList * prev;
  KillAction data;
};

struct DamageActionList
{
  DamageActionList * next;
  DamageActionList * prev;
  DamageAction data;
};

struct PassivePacketList
{
  PassivePacketList * next;
  PassivePacketList * prev;
  PassivePacket data;
};

struct MissionPacketList
{
  MissionPacketList * next;
  MissionPacketList * prev;
  MissionPacket data;
};

struct PacketQueue
{
  HitPacketList * player_hits;
  uint32_t player_hits_size;
  SoundActionList * sound_actions;
  uint32_t sound_actions_size;
  ParticleDataList * particles;
  uint32_t particles_size;
  BlockActionList * block_actions;
  uint32_t block_actions_size;
  ShootPacketList * shoot_packets;
  uint32_t shoot_packets_size;
  ChunkItemsList * chunk_items;
  uint32_t chunk_items_size;
  StaticEntityList * static_entities;
  uint32_t static_entities_size;
  Items8List_1 * items_8;
  uint32_t items_8_size;
  PickupActionList * pickup_actions;
  uint32_t pickup_actions_size;
  KillActionList * kill_actions;
  uint32_t kill_actions_size;
  DamageActionList * damage_actions;
  uint32_t damage_actions_size;
  PassivePacketList * passive_packets;
  uint32_t passive_packets_size;
  MissionPacketList * missions;
  uint32_t missions_size;
};
