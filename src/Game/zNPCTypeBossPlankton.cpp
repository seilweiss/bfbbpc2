#include "zNPCTypeBossPlankton.h"

#include "xDebug.h"

namespace {

	struct sound_property
	{
		uint32 asset;
		float32 volume;
		float32 range_inner;
		float32 range_outer;
		float32 delay;
		float32 fade_time;
	};

	struct tweak_group
	{
		xVec3 accel;
		xVec3 max_vel;
		float32 turn_accel;
		float32 turn_max_vel;
		float32 ground_y;
		float32 ground_radius;
		float32 hit_vel;
		float32 hit_max_dist;
		float32 idle_time;
		float32 min_arena_dist;
		struct
		{
			float32 min_ang;
			float32 max_ang;
			float32 min_delay;
			float32 max_delay;
		} follow;
		struct
		{
			float32 fuse_dist;
			float32 fuse_delay;
		} help;
		struct
		{
			xVec3 accel;
			xVec3 max_vel;
			float32 stun_duration;
			float32 obstruct_angle;
		} mode_buddy;
		struct
		{
			xVec3 accel;
			xVec3 max_vel;
			float32 stun_duration;
		} mode_harass;
		struct
		{
			float32 height;
			float32 radius;
			float32 beam_interval;
			float32 beam_duration;
			float32 beam_dist;
		} hunt;
		struct
		{
			float32 rate;
			float32 time_warm_up;
			float32 time_fire;
			float32 gun_tilt_min;
			float32 gun_tilt_max;
			float32 max_dist;
			float32 emit_dist;
			xLaserBoltEmitter::config fx;
		} beam;
		struct
		{
			float32 safety_dist;
			float32 safety_height;
			float32 attack_dist;
			float32 attack_height;
			float32 stun_time;
		} harass;
		struct
		{
			float32 duration;
			float32 accel;
			float32 max_vel;
		} flank;
		struct
		{
			float32 accel;
			float32 max_vel;
			float32 dist;
		} fall;
		struct
		{
			float32 duration;
			float32 move_delay_min;
			float32 move_delay_max;
			float32 accel;
			float32 max_vel;
		} evade;
		struct
		{
			xVec3 center;
			struct
			{
				float32 radius;
				float32 height;
			} attack;
			struct
			{
				float32 radius;
				float32 height;
			} safety;
		} arena;
		sound_property sound[6];
		void* context;
		tweak_callback cb_move;
		tweak_callback cb_arena;
		tweak_callback cb_ground;
		tweak_callback cb_beam;
		tweak_callback cb_help;
		tweak_callback cb_sound;
		tweak_callback cb_sound_asset;

		void register_tweaks(bool init, xModelAssetParam* ap, uint32 apsize, const char*) STUB_VOID;
		void load(xModelAssetParam*, uint32) STUB_VOID;
	};

	xVec3& get_player_loc() STUB_REF(xVec3);
	void init_sound() STUB_VOID;
	void reset_sound() STUB_VOID;
	uint32 play_sound(int32, const xVec3*, float32) STUB;
	void kill_sound(int32, uint32) STUB_VOID;
	void kill_sound(int32) STUB_VOID;
	void play_beam_fly_sound(xLaserBoltEmitter::bolt& b, void*) STUB_VOID;
	void kill_beam_fly_sound(xLaserBoltEmitter::bolt& b, void*) STUB_VOID;
	void play_beam_fire_sound(xLaserBoltEmitter::bolt& b, void*) STUB_VOID;
	void play_beam_hit_sound(xLaserBoltEmitter::bolt& b, void*) STUB_VOID;

}

xAnimTable* ZNPC_AnimTable_BossPlankton() STUB

zNPCBPlankton::zNPCBPlankton(int32 myType) : zNPCBoss(myType) STUB_VOID
void zNPCBPlankton::Init(xEntAsset* asset) STUB_VOID
void zNPCBPlankton::Setup() STUB_VOID
void zNPCBPlankton::PostSetup() STUB_VOID
void zNPCBPlankton::Reset() STUB_VOID
void zNPCBPlankton::Destroy() STUB_VOID
void zNPCBPlankton::Process(xScene* xscn, float32 dt) STUB_VOID
bool32 zNPCBPlankton::SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled) STUB
void zNPCBPlankton::Render() STUB_VOID
void zNPCBPlankton::RenderExtraPostParticles() STUB_VOID
void zNPCBPlankton::ParseINI() STUB_VOID
void zNPCBPlankton::ParseLinks() STUB_VOID
void zNPCBPlankton::SelfSetup() STUB_VOID
void zNPCBPlankton::Damage(en_NPC_DAMAGE_TYPE damtype, xBase*, const xVec3* vec_hit) STUB_VOID
uint32 zNPCBPlankton::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*) STUB
int32 zNPCBPlankton::next_goal() STUB
void zNPCBPlankton::refresh_orbit() STUB_VOID
void zNPCBPlankton::scan_cronies() STUB_VOID

namespace {

	void set_yaw_matrix(xMat3x3&, float32) STUB_VOID;
	void update_move_accel(xVec3&, zNPCBPlankton::move_info&, float32) STUB_VOID;
	void update_move_stop(xVec3&, zNPCBPlankton::move_info&, float32) STUB_VOID;
	void update_move_orbit(xVec3& loc, zNPCBPlankton::move_info& move, const xVec3& center, float32 dt, bool xfree) STUB_VOID;

}

void zNPCBPlankton::update_turn(float32 dt) STUB_VOID
void zNPCBPlankton::update_move(float32) STUB_VOID

namespace {

	xVec3 world_to_ring_vel(const xVec3&, const xVec3&, const xVec3&) STUB;
	xVec3 ring_to_world_vel(const xVec3&, const xVec3&, const xVec3&) STUB;

}

void zNPCBPlankton::reset_territories() STUB_VOID
void zNPCBPlankton::update_dialog(float32 dt) STUB_VOID
void zNPCBPlankton::update_animation(float32) {}
void zNPCBPlankton::update_follow(float32 dt) STUB_VOID
void zNPCBPlankton::update_follow_player(float32 dt) STUB_VOID
void zNPCBPlankton::update_follow_camera(float32 dt) STUB_VOID
void zNPCBPlankton::update_aim_gun(float32) STUB_VOID
bool zNPCBPlankton::check_player_damage() STUB
float32 zNPCBPlankton::orbit_yaw_offset(const xVec3& p0, const xVec3& p1) const STUB
void zNPCBPlankton::load_territory(int32 index, xBase& child) STUB_VOID
void zNPCBPlankton::init_beam() STUB_VOID
void zNPCBPlankton::setup_beam() STUB_VOID
void zNPCBPlankton::reset_beam() STUB_VOID
void zNPCBPlankton::vanish() STUB_VOID
void zNPCBPlankton::reappear() STUB_VOID
xVec3 zNPCBPlankton::random_orbit(const xVec3& loc, float32 min_ang, float32 max_ang) const STUB
xVec3 zNPCBPlankton::player_orbit() const STUB
bool zNPCBPlankton::crony_attacking() const STUB
void zNPCBPlankton::stun() STUB_VOID
bool zNPCBPlankton::cronies_dead() const STUB
void zNPCBPlankton::impart_velocity(const xVec3& vel) STUB_VOID
void zNPCBPlankton::next_territory() STUB_VOID
bool zNPCBPlankton::have_cronies() const STUB
bool zNPCBPlankton::move_to_player_territory() STUB
bool zNPCBPlankton::player_left_territory() const STUB
void zNPCBPlankton::say(int32, int32, bool) STUB_VOID
void zNPCBPlankton::sickum() STUB_VOID
void zNPCBPlankton::here_boy() STUB_VOID
void zNPCBPlankton::follow_player() STUB_VOID
void zNPCBPlankton::follow_camera() STUB_VOID
void zNPCBPlankton::reset_speed() STUB_VOID
void zNPCBPlankton::halt(float32 accel) STUB_VOID
void zNPCBPlankton::fall(float32 accel, float32 max_vel) STUB_VOID
void zNPCBPlankton::aim_gun(xAnimPlay* play, xQuat* quat, xVec3*, int32) STUB_VOID

xFactoryInst* zNPCGoalBPlanktonIdle::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonIdle::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonIdle::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonIdle::Process(en_trantype* trantype, float32, void*, xScene*) STUB
void zNPCGoalBPlanktonIdle::get_yaw(float32& optimal, float32& dist) const STUB_VOID
void zNPCGoalBPlanktonIdle::apply_yaw(float32) STUB_VOID

xFactoryInst* zNPCGoalBPlanktonAttack::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonAttack::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonAttack::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonAttack::Process(en_trantype* trantype, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBPlanktonAmbush::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonAmbush::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonAmbush::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonAmbush::Process(en_trantype* trantype, float32 dt, void*, xScene*) STUB

xFactoryInst* zNPCGoalBPlanktonFlank::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonFlank::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonFlank::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonFlank::Process(en_trantype* trantype, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBPlanktonEvade::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonEvade::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonEvade::Exit(float32, void*) STUB

namespace {

	inline xVec3 world_to_ring_loc(const xVec3&, const xVec3&) STUB;
	inline xVec3 ring_to_world_loc(const xVec3&, const xVec3&) STUB;

}

bool32 zNPCGoalBPlanktonEvade::Process(en_trantype* trantype, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBPlanktonHunt::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonHunt::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonHunt::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonHunt::Process(en_trantype* trantype, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBPlanktonTaunt::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonTaunt::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonTaunt::Exit(float32 dt, void*) STUB
bool32 zNPCGoalBPlanktonTaunt::Process(en_trantype*, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBPlanktonMove::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonMove::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonMove::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonMove::Process(en_trantype*, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBPlanktonStun::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonStun::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonStun::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonStun::Process(en_trantype* trantype, float32 dt) STUB

xFactoryInst* zNPCGoalBPlanktonFall::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonFall::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonFall::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonFall::Process(en_trantype* trantype, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBPlanktonDizzy::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonDizzy::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonDizzy::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonDizzy::Process(en_trantype* trantype, float32 dt, void*, xScene*) STUB

xFactoryInst* zNPCGoalBPlanktonBeam::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonBeam::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonBeam::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonBeam::Process(en_trantype* trantype, float32 dt, void*, xScene*) STUB
void zNPCGoalBPlanktonBeam::update_warm_up(float32) STUB_VOID
void zNPCGoalBPlanktonBeam::update_fire(float32 dt) STUB_VOID
void zNPCGoalBPlanktonBeam::update_cool_down(float32) STUB_VOID

xFactoryInst* zNPCGoalBPlanktonWall::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonWall::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonWall::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonWall::Process(en_trantype*, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBPlanktonMissle::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonMissle::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonMissle::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonMissle::Process(en_trantype*, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBPlanktonBomb::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBPlanktonBomb::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBPlanktonBomb::Exit(float32, void*) STUB
bool32 zNPCGoalBPlanktonBomb::Process(en_trantype*, float32, void*, xScene*) STUB