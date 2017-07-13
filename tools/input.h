struct ItemUpgrade
{
  char x;
  char y;
  char z;
  char material;
  int level;
};

struct ItemData
{
  _BYTE type;
  _BYTE sub_type;
  _BYTE pad1[2];
  _DWORD modifier;
  _DWORD minus_modifier;
  _BYTE rarity;
  _BYTE material;
  _BYTE flags;
  _BYTE pad2[1];
  /* signed? probably not: https://bpaste.net/show/cbab9c88524a */
  signed short level = 1;
  _BYTE pad3[2];
  ItemUpgrade items[32];
  _DWORD upgrade_count;
};

struct AppearanceData
{
  _BYTE not_used_1;
  _BYTE not_used_2;
  _BYTE hair_red = 255;
  _BYTE hair_green = 255;
  _BYTE hair_blue = 255;
  _BYTE pad[1];
  _WORD flags;

  vec3 scale; /* old: scale, bounding_radius, bounding_height */

  signed short head_model = -1;
  signed short hair_model = -1;
  signed short hand_model = -1;
  signed short foot_model = -1;
  signed short body_model = -1;
  signed short back_model = -1;
  signed short shoulder_model = -1;
  signed short wing_model = -1;
  float head_scale;
  float body_scale;
  float hand_scale;
  float foot_scale;
  float shoulder_scale;
  float weapon_scale;
  float back_scale;
  float unknown;
  float wing_scale;
  float body_pitch;
  float arm_pitch;
  float arm_roll;
  float arm_yaw;
  float feet_pitch;
  float wing_pitch;
  float back_pitch;
  vec3 body_offset;
  vec3 head_offset;
  vec3 hand_offset;
  vec3 foot_offset;
  vec3 back_offset;
  vec3 wing_offset;
};

/* mask bits */
#define POS_BIT 0
#define ORIENT_BIT 1
#define VEL_BIT 2
#define ACCEL_BIT 3
#define EXTRA_VEL_BIT 4
#define LOOK_PITCH_BIT 5
#define PHYSICS_BIT 6
#define HOSTILE_BIT 7
#define TYPE_BIT 8
#define MODE_BIT 9
#define MODE_TIME_BIT 10
#define HIT_COUNTER_BIT 11
#define LAST_HIT_BIT 12
#define APPEARANCE_BIT 13
#define FLAGS_BIT 14
#define ROLL_BIT 15
#define STUN_BIT 16
#define SLOWED_BIT 17
#define MAKE_BLUE_BIT 18
#define SPEED_UP_BIT 19
#define SHOW_PATCH_BIT 20
#define CLASS_BIT 21
#define SPECIALIZATION_BIT 22
#define CHARGED_MP_BIT 23
/* #define NOT_USED1_BIT 24 */
/* #define NOT_USED2_BIT 25 */
#define RAY_BIT 26
#define HP_BIT 27
#define MP_BIT 28
#define BLOCK_POWER_BIT 29
#define MULTIPLIER_BIT 30
/* #define NOT_USED3_BIT 31 */
/* #define NOT_USED4_BIT 32 */
#define LEVEL_BIT 33
#define XP_BIT 34
#define OWNER_BIT 35
/* #define UNKNOWN1_BIT 36 */
#define POWER_BASE_BIT 37
/* #define UNKNOWN2_BIT 38 */
#define START_CHUNK_BIT 39
#define SPAWN_BIT 40
/* #define NOT_USED5_BIT 41 */
/* #define NOT_USED6_BIT 42 */
#define CONSUMABLE_BIT 43
#define EQUIPMENT_BIT 44
#define NAME_BIT 45
#define SKILL_BIT 46
#define MANA_CUBES_BIT 47

struct EntityData
{
  qvec3 pos;
  float body_roll;
  float body_pitch;
  float body_yaw;
  vec3 velocity;
  vec3 accel;
  vec3 extra_vel;
  float look_pitch;
  _DWORD physics_flags;
  _BYTE hostile_type = 3;
  char gap_51[3];
  _DWORD entity_type; /* needs to be changed */
  _BYTE current_mode;
  char gap_59[3];
  _DWORD mode_start_time;
  _DWORD hit_counter;
  _DWORD last_hit_time;
  AppearanceData appearance;
  _WORD flags; /* has hostile flags */
  char gap_116[2];
  _DWORD roll_time;
  signed int stun_time = -3000;
  _DWORD slowed_time;
  _DWORD make_blue_time;
  _DWORD speed_up_time;
  float show_patch_time;
  _BYTE class_type;
  _BYTE specialization;
  char gap_132[2];
  float charged_mp;

  _DWORD not_used_1;
  _DWORD not_used_2;
  _DWORD not_used_3;

  _DWORD not_used_4;
  _DWORD not_used_5;
  _DWORD not_used_6;

  vec3 ray_hit;
  float hp = 500;
  float mp;
  float block_power;
  float max_hp_multiplier = 100;
  float shoot_speed;
  float damage_multiplier = 1;
  float armor_multiplier = 1;
  float resi_multiplier = 1;
  _BYTE not_used7;
  _BYTE not_used8;
  char gap_17E[2];
  signed int level;
  signed int current_xp;

  uint64_t parent_owner; /* used for pets, guess by Somer, originally 2 DWORDs*/

  _DWORD unknown_or_not_used1; // probably a uint64
  _DWORD unknown_or_not_used2;

  _BYTE power_base;
  char gap_199[3];
  int unknown_or_not_used4 = -1;

  ivec3 start_chunk = Vector3(-1, -1, 0);

  _DWORD super_weird;
  qvec3 spawn_pos;
  _BYTE not_used19;
  char gap_1C9[3];

  ivec3 not_used20 = Vector3(-1, -1, 0);

  ItemData consumable;
  ItemData equipment[13];
  _DWORD skills[11];
  _DWORD mana_cubes;
  char name[16];
};
