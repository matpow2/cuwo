struct ItemUpgrade
{
  char x;
  char y;
  char z;
  char material;
  _DWORD level;
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
  signed short level;
  _BYTE pad3[2];
  ItemUpgrade items[32];
  _DWORD upgrade_count;
};

struct AppearanceData
{
  _BYTE not_used_1;
  _BYTE not_used_2;
  _BYTE hair_red;
  _BYTE hair_green;
  _BYTE hair_blue;
  _BYTE pad[1];
  _BYTE movement_flags;
  _BYTE entity_flags;
  float scale;
  float bounding_radius;
  float bounding_height;
  signed short head_model;
  signed short hair_model;
  signed short hand_model;
  signed short foot_model;
  signed short body_model;
  signed short back_model;
  signed short shoulder_model;
  signed short wing_model;
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

#define FLAGS_1_HOSTILE 0x20

#define POS_BIT 0
#define ORIENT_BIT 1
#define VEL_BIT 2
#define ACCEL_BIT 3
#define EXTRA_VEL_BIT 4
#define LOOK_PITCH_BIT 5
#define MODE_BIT 9
#define APPEARANCE_BIT 13
#define FLAGS_BIT 14
#define CLASS_BIT 21
#define CHARGED_MP_BIT 23
#define MULTIPLIER_BIT 30
#define LEVEL_BIT 33
#define CONSUMABLE_BIT 43
#define EQUIPMENT_BIT 44
#define NAME_BIT 45
#define SKILL_BIT 46

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
  _BYTE hostile_type;
  char gap_51[3];
  _DWORD entity_type; /* needs to be changed */
  _BYTE current_mode;
  char gap_59[3];
  _DWORD mode_start_time;
  _DWORD hit_counter;
  _DWORD last_hit_time;
  AppearanceData appearance;
  _BYTE flags_1; /* has hostile flags */
  _BYTE flags_2;
  char gap_116[2];
  _DWORD roll_time;
  signed int stun_time;
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
  float hp;
  float mp;
  float block_power;
  float max_hp_multiplier;
  float shoot_speed;
  float damage_multiplier;
  float armor_multiplier;
  float resi_multiplier;
  _BYTE not_used7;
  _BYTE not_used8;
  char gap_17E[2];
  _DWORD level;
  _DWORD current_xp;
  uint64_t parent_owner; /* used for pets, guess by Somer, originally 2 DWORDs*/
  _DWORD unknown_or_not_used1; // probably a uint64
  _DWORD unknown_or_not_used2;
  _BYTE power_base;
  char gap_199[3];
  _DWORD unknown_or_not_used4;
  _DWORD unknown_or_not_used5;
  _DWORD not_used11;
  _DWORD not_used12;
  _DWORD super_weird;
  qvec3 spawn_pos;
  _BYTE not_used19;
  char gap_1C9[3];
  _DWORD not_used20;
  _DWORD not_used21;
  _DWORD not_used22;
  ItemData consumable;
  ItemData equipment[13];
  _DWORD skills[11];
  _DWORD mana_cubes;
  char name[16];
};
