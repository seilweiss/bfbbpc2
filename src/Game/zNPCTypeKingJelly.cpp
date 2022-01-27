#include "zNPCTypeKingJelly.h"

namespace {

	void init_sound() STUB_VOID;
	void play_sound_immediate(int32, const xVec3*) STUB_VOID;
	void play_sound(int32, const xVec3*) STUB_VOID;
	void kill_sound(int32) STUB_VOID;
	void sound_update(float32) STUB_VOID;
	void kill_sounds() STUB_VOID;
	int32 set_ring_segments(const xVec3& center, float32 radius, float32 segment_length) STUB;
	void updown_ring_update(lightning_ring& ring, float32 dt);
	void expand_ring_update(lightning_ring& ring, float32 dt);

	struct unit_type
	{
		float32 radius_offset;
		float32 height_offset;
		uint8 line;
		float32 thickness;
		xColor color;
		float32 rot_radius;
		float32 degrees;
	};

	struct wave_ring_type
	{
		float32 min_radius;
		float32 max_radius;
		float32 height;
		float32 fade_time;
		float32 max_vel;
		float32 accel;
		float32 segment_length;
		float32 particle_height;
		float32 particles;
		float32 damage_height;
		float32 damage_width;
		float32 knock_back;
		unit_type unit[4];
	};

	struct tweak_group
	{
		void* context;
		tweak_callback* cb_fade_obstructions;
		tweak_callback* cb_ambient_ring;
		int32 max_life;
		float32 min_dist;
		float32 move_radius;
		float32 vel_decay;
		float32 repel_radius;
		float32 repel_radius_ground;
		float32 fade_obstructions;
		float32 music_fade;
		float32 music_fade_delay;
		struct
		{
			float32 duration;
			int32 amount;
			float32 drop_off;
			struct
			{
				float32 r;
				float32 g;
				float32 b;
				float32 a;
			} color;
		} blink;
		struct
		{
			float32 variance;
			float32 attack[3];
			float32 warm_up;
			float32 release;
			float32 cool_down;
		} interval;
		struct
		{
			int32 cycles;
			float32 voffset;
			float32 hoffset;
			float32 delay;
			float32 fall_time;
			struct
			{
				float32 speed;
				float32 drop_off;
				float32 delay;
				float32 voffset;
			} spew;
		} spawn;
		wave_ring_type wave_ring;
		struct
		{
			float32 radius;
			float32 min_height;
			float32 max_height;
			float32 speed;
			float32 segment_length;
			float32 thickness;
			xColor color;
			float32 knock_back;
			struct
			{
				float32 radius;
				float32 max_height;
				float32 speed;
				float32 thickness;
				xColor color;
			} charge;
		} ambient_ring;
		struct
		{
			float32 thickness;
			float32 rand_radius;
			float32 rot_radius;
			float32 move_degrees;
			xColor color;
			float32 delay;
			float32 time;
			int32 max;
			float32 particles;
			float32 knock_back;
			float32 damage_width;
			struct
			{
				float32 thickness;
				xColor color;
				float32 move_degrees;
			} charge;
		} tentacle;
		struct
		{
			float32 delay;
			int32 rings;
			float32 voffset;
			float32 particles;
			float32 radius;
			float32 width;
			float32 vel;
			float32 particle_drop_off;
			float32 vel_drop_off;
		} thump;
		struct
		{
			float32 volume;
			float32 delay;
			float32 radius_inner;
			float32 radius_outer;
			int32 priority;
		} sound[11];

		void register_tweaks(bool init, xModelAssetParam* ap, uint32 apsize, const char*) STUB_VOID;
		void load(xModelAssetParam*, uint32) STUB_VOID;
	};
	
}

void lightning_ring::create() STUB_VOID
void lightning_ring::destroy() STUB_VOID
void lightning_ring::refresh() STUB_VOID
void lightning_ring::create_arc(xVec3*, xVec3*, int32, int32) STUB_VOID

xAnimTable* ZNPC_AnimTable_KingJelly() STUB

zNPCKingJelly::zNPCKingJelly(int32 myType) : zNPCSubBoss(myType) STUB_VOID
void zNPCKingJelly::Init(xEntAsset* asset) STUB_VOID
void zNPCKingJelly::Setup() STUB_VOID
void zNPCKingJelly::Reset() STUB_VOID
void zNPCKingJelly::Destroy() STUB_VOID
void zNPCKingJelly::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCKingJelly::BUpdate(xVec3* pos) STUB_VOID
bool32 zNPCKingJelly::SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled) STUB
void zNPCKingJelly::RenderExtra() STUB_VOID
void zNPCKingJelly::ParseINI() STUB_VOID
void zNPCKingJelly::ParseLinks() STUB_VOID
void zNPCKingJelly::SelfSetup() STUB_VOID
void zNPCKingJelly::Damage(en_NPC_DAMAGE_TYPE damtype, xBase*, const xVec3*) STUB_VOID
uint32 zNPCKingJelly::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*) STUB
float32 zNPCKingJelly::get_variance() const STUB
bool zNPCKingJelly::bored() const STUB
int32 zNPCKingJelly::max_strikes() const STUB
void zNPCKingJelly::update_camera(float32) STUB_VOID
void zNPCKingJelly::set_life(int32 life) STUB_VOID
void zNPCKingJelly::update_round() STUB_VOID
void zNPCKingJelly::add_child(xBase& child, int32 wave) STUB_VOID
void zNPCKingJelly::init_child(child_data&, zNPCCommon&, int32) STUB_VOID
void zNPCKingJelly::disable_child(child_data&) STUB_VOID
void zNPCKingJelly::enable_child(child_data&) STUB_VOID
int32 zNPCKingJelly::count_children(int32) STUB
void zNPCKingJelly::spawn_children(int32 wave, int32 count) STUB_VOID
void zNPCKingJelly::move_to_spawn_position(zNPCCommon&, float32) STUB_VOID
void zNPCKingJelly::taunt() STUB_VOID
void zNPCKingJelly::repel_player() STUB_VOID

namespace {

	bool sphere_hits_line(const xSphere& o, const xVec3& v1, const xVec3& v2, float32 width) STUB;
	int32 sphere_hits_sphere_xz(const xSphere&, const xSphere&) STUB;

}

xVec3 zNPCKingJelly::get_away() const STUB
bool zNPCKingJelly::apply_tentacle_damage() STUB
bool zNPCKingJelly::apply_wave_damage() STUB
bool zNPCKingJelly::apply_ambient_damage() STUB
void zNPCKingJelly::check_player_damage() STUB_VOID
void zNPCKingJelly::start_fight() STUB_VOID
void zNPCKingJelly::decompose() STUB_VOID
void zNPCKingJelly::post_decompose() STUB_VOID
void zNPCKingJelly::vanish() STUB_VOID
void zNPCKingJelly::reappear() STUB_VOID
void zNPCKingJelly::create_tentacle_lightning() {}
zLightning* zNPCKingJelly::new_tentacle_lightning(xVec3* points) STUB
void zNPCKingJelly::destroy_tentacle_lightning() STUB_VOID
void zNPCKingJelly::update_tentacle_lightning(float32 dt) STUB_VOID
void zNPCKingJelly::generate_zap_particles(const zLightning& zap, float32 amount, float32 dt) STUB_VOID
void zNPCKingJelly::refresh_tentacle_points(int32 which) STUB_VOID
void zNPCKingJelly::refresh_tentacle_points() STUB_VOID
void zNPCKingJelly::update_rings(float32 dt) STUB_VOID
void zNPCKingJelly::create_ambient_rings() STUB_VOID
void zNPCKingJelly::destroy_ambient_rings() STUB_VOID
void zNPCKingJelly::create_wave_rings() STUB_VOID
void zNPCKingJelly::destroy_wave_rings() STUB_VOID
void zNPCKingJelly::generate_spawn_particles() STUB_VOID
void zNPCKingJelly::update_spawn_particles(float32 dt) STUB_VOID
void zNPCKingJelly::generate_ring_particles(const lightning_ring& ring, float32 dt) STUB_VOID
void zNPCKingJelly::generate_thump_particles() STUB_VOID
void zNPCKingJelly::start_charge() STUB_VOID

namespace {

	inline uint8 lerp(float32, uint8, uint8) STUB;
	inline xColor lerp(float32, xColor, xColor) STUB;
	inline float32 lerp(float32, float32, float32) STUB;

}

void zNPCKingJelly::update_charge(float32 frac) STUB_VOID
void zNPCKingJelly::end_charge() STUB_VOID
void zNPCKingJelly::load_model() STUB_VOID
void zNPCKingJelly::load_curtain_model() STUB_VOID
void zNPCKingJelly::show_shower_model() STUB_VOID
void zNPCKingJelly::show_attack_model() STUB_VOID
void zNPCKingJelly::fade_curtain() STUB_VOID
void zNPCKingJelly::reset_curtain() STUB_VOID

namespace {

	void set_model_color(xModelInstance*, float32, float32, float32, float32) STUB_VOID;
	void reset_model_color(xModelInstance*) STUB_VOID;

}

void zNPCKingJelly::start_blink() STUB_VOID
void zNPCKingJelly::update_blink(float32 dt) STUB_VOID

bool32 zNPCGoalKJIdle::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalKJIdle::Exit(float32, void*) STUB
bool32 zNPCGoalKJIdle::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalKJIdle::rotate(float32) STUB_VOID
void zNPCGoalKJIdle::move(float32 dt) STUB_VOID

bool32 zNPCGoalKJBored::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalKJBored::Exit(float32, void*) STUB
bool32 zNPCGoalKJBored::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalKJSpawnKids::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalKJSpawnKids::Exit(float32, void*) STUB
bool32 zNPCGoalKJSpawnKids::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalKJTaunt::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalKJTaunt::Exit(float32, void*) STUB
bool32 zNPCGoalKJTaunt::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalKJShockGround::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalKJShockGround::Exit(float32, void*) STUB
bool32 zNPCGoalKJShockGround::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
shockstate_enum zNPCGoalKJShockGround::update_start(float32) STUB
shockstate_enum zNPCGoalKJShockGround::update_warm_up(float32 dt) STUB
shockstate_enum zNPCGoalKJShockGround::update_release(float32) STUB
shockstate_enum zNPCGoalKJShockGround::update_cool_down(float32 dt) STUB
shockstate_enum zNPCGoalKJShockGround::update_stop(float32) STUB

bool32 zNPCGoalKJDamage::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalKJDamage::Exit(float32, void*) STUB
bool32 zNPCGoalKJDamage::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalKJDeath::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalKJDeath::Exit(float32, void*) STUB
bool32 zNPCGoalKJDeath::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB