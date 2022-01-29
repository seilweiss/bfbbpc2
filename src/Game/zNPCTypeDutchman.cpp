#include "zNPCTypeDutchman.h"

#include "xDebug.h"

namespace {

	struct beam_config
	{
		float32 accel;
		float32 max_vel;
		float32 start_dist;
		float32 end_dist;
		float32 wave_freq;
		float32 wave_min;
		float32 wave_max;
	};

	struct beam_type : beam_config
	{
		float32 knock_back;
		float32 thickness;
		float32 focus_time;
		float32 segment_width;
		float32 light_rate;
		float32 glow_dist;
		int32 shots[3];
		float32 fade_dist;
	};

	struct sound_property
	{
		float32 volume;
		float32 range_inner;
		float32 range_outer;
		float32 delay;
		float32 fade_time;
	};

	struct tweak_group
	{
		float32 orbit_radius;
		xVec3 accel;
		xVec3 max_vel;
		float32 turn_accel;
		float32 turn_max_vel;
		float32 ground_y;
		float32 ground_radius;
		float32 alpha;
		float32 speed_mult[3];
		float32 reticle_y;
		float32 reticle_radius;
		struct
		{
			float32 alpha;
			float32 scale;
			float32 yoffset;
			float32 vel_u;
			float32 vel_v;
		} halo;
		struct
		{
			float32 turn_vel;
			float32 turn_accel;
			float32 up_vel;
		} initiate;
		beam_type beam;
		struct
		{
			xVec3 accel;
			xVec3 max_vel;
			float32 turn_accel;
			float32 turn_max_vel;
			float32 fade_time;
			float32 trail_width;
		} teleport;
		struct
		{
			float32 accel;
			float32 max_vel;
			float32 start_delay;
			float32 wave_rate;
			float32 unit_dist;
			float32 start_dist;
			float32 lead_dist;
			float32 emit_rate[3];
			float32 emit_width[3];
			float32 snot_dist;
			float32 snot_vel;
			float32 snot_height;
			float32 splash_width;
			float32 decay;
			float32 blob_pitch;
			float32 spray_width;
			float32 warm_up_time;
			float32 sneeze_mult;
		} flame;
		struct
		{
			int32 dummy;
		} fly;
		struct
		{
			float32 min_dist_enable;
			float32 min_dist_disable;
			float32 max_angle_enable;
			float32 max_angle_disable;
			float32 safety_dist;
			float32 decel;
			float32 escape_delay;
		} lasso;
		struct
		{
			float32 beam_radius;
			float32 beam_blast_radius;
			xVec3 flame_size;
			xVec3 snot_size;
			float32 hand_radius;
			float32 slime_width;
			float32 slime_time;
		} damage;
		struct
		{
			float32 delay;
			float32 duration;
			float32 rate_mult;
			float32 yoffset;
		} wipe;
		struct
		{
			float32 wind_duration;
			float32 wink_duration;
			float32 start_y;
			float32 end_y;
			float32 wind_min;
			float32 wind_kill_dist;
			float32 wind_mag_up;
			float32 wind_mag_right;
		} death;
		sound_property sound[6];
		void* context;
		tweak_callback cb_orbit_radius;
		tweak_callback cb_ground;
		tweak_callback cb_damage;
		tweak_callback cb_flame_rate;
		tweak_callback cb_alpha;
		tweak_callback cb_reticle;
		tweak_callback cb_halo_uv;
		tweak_callback cb_blob_pitch;
		tweak_callback cb_sound;

		void register_tweaks(bool init, xModelAssetParam* ap, uint32 apsize, const char*) STUB_VOID;
		void load(xModelAssetParam*, uint32) STUB_VOID;
	};

	float32 look_at(xMat3x3& mat, const xVec3& at) STUB;
	void init_sound() STUB_VOID;
	uint32 play_sound(int32, const xVec3*, float32) STUB;
	void kill_sound(int32, uint32) STUB_VOID;
	void set_volume(int32, uint32, float32) STUB_VOID;

}

xAnimTable* ZNPC_AnimTable_Dutchman() STUB

zNPCDutchman::zNPCDutchman(int32 myType) : zNPCSubBoss(myType) STUB_VOID
void zNPCDutchman::Init(xEntAsset* asset) STUB_VOID
void zNPCDutchman::Setup() STUB_VOID
void zNPCDutchman::Reset() STUB_VOID
void zNPCDutchman::Destroy() STUB_VOID
void zNPCDutchman::Process(xScene* xscn, float32 dt) STUB_VOID
bool32 zNPCDutchman::SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled) STUB
void zNPCDutchman::Render() STUB_VOID
void zNPCDutchman::RenderExtra() STUB_VOID
void zNPCDutchman::ParseINI() STUB_VOID
void zNPCDutchman::SelfSetup() STUB_VOID
void zNPCDutchman::Damage(en_NPC_DAMAGE_TYPE, xBase*, const xVec3*) STUB_VOID
uint32 zNPCDutchman::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*) STUB
void zNPCDutchman::LassoNotify(en_LASSO_EVENT event) STUB_VOID
bool32 zNPCDutchman::LassoSetup() STUB
void zNPCDutchman::update_round() STUB_VOID
int32 zNPCDutchman::next_goal() STUB
float32 zNPCDutchman::goal_delay() STUB
void zNPCDutchman::decompose() STUB_VOID

namespace {

	void set_yaw_matrix(xMat3x3&, float32) STUB_VOID;
	void update_move_follow(xVec3& loc, zNPCDutchman::move_info& move, const xMat3x3& mat, float32 dt) STUB_VOID;
	void update_move_accel(xVec3& loc, zNPCDutchman::move_info& move, float32 dt) STUB_VOID;
	void update_move_vel(xVec3&, zNPCDutchman::move_info&, float32) STUB_VOID;
	void update_move_stop(xVec3&, zNPCDutchman::move_info&, float32) STUB_VOID;

}

void zNPCDutchman::update_turn(float32 dt) STUB_VOID
void zNPCDutchman::update_move(float32 dt) STUB_VOID
void zNPCDutchman::update_animation(float32) {}
void zNPCDutchman::update_camera(float32) STUB_VOID

namespace {

	bool clip_outside_circle(float32& out, const xVec2& origin, const xVec2& dir, float32 d1, float32 d2, const xVec2& center, float32 r) STUB;
	bool clip_outside_circle(float32&, const xVec3&, const xVec3&, float32, float32, const xVec3&, float32) STUB;

}

void zNPCDutchman::update_wave(wave_data& wave, float32 dt) STUB_VOID
void zNPCDutchman::init_wave(wave_data& wave, const xVec3& loc, const xVec3& dir) STUB_VOID
void zNPCDutchman::kill_wave(wave_data&) STUB_VOID
void zNPCDutchman::start_eye_glow() STUB_VOID
void zNPCDutchman::stop_eye_glow() STUB_VOID
void zNPCDutchman::update_eye_glow(float32 dt) STUB_VOID
void zNPCDutchman::start_hand_trail() STUB_VOID
void zNPCDutchman::stop_hand_trail() STUB_VOID
void zNPCDutchman::update_hand_trail(float32) STUB_VOID
void zNPCDutchman::dissolve(float32 delay) STUB_VOID
void zNPCDutchman::coalesce(float32 delay) STUB_VOID
void zNPCDutchman::reset_blob_mat() STUB_VOID
void zNPCDutchman::refresh_reticle() STUB_VOID
void zNPCDutchman::reset_lasso_anim() STUB_VOID
void zNPCDutchman::update_fade(float32 dt) STUB_VOID
void zNPCDutchman::update_slime(float32 dt) STUB_VOID
void zNPCDutchman::add_slime(const xVec3& loc, float32 dt) STUB_VOID
void zNPCDutchman::add_spray(const xVec3& loc, float32 dt) STUB_VOID
void zNPCDutchman::add_splash(const xVec3&, float32) {}
void zNPCDutchman::update_flames(float32 dt) STUB_VOID
void zNPCDutchman::start_fight() STUB_VOID
void zNPCDutchman::set_life(int32) STUB_VOID
void zNPCDutchman::start_beam() STUB_VOID
void zNPCDutchman::stop_beam() STUB_VOID
void zNPCDutchman::set_alpha(float32) STUB_VOID
void zNPCDutchman::start_flames() STUB_VOID
void zNPCDutchman::stop_flames() STUB_VOID
bool zNPCDutchman::check_player_damage() STUB
xVec3 zNPCDutchman::get_eye_loc(int32) const STUB
xVec3 zNPCDutchman::get_hand_loc(int32) const STUB
xVec3 zNPCDutchman::get_splash_loc() const STUB
void zNPCDutchman::vanish() STUB_VOID
void zNPCDutchman::reappear() STUB_VOID
xVec3 zNPCDutchman::random_orbit(const xVec3& loc, float32 min_ang, float32 max_ang) const STUB
void zNPCDutchman::turn_to_face(const xVec3&) STUB_VOID
void zNPCDutchman::reset_speed() STUB_VOID
void zNPCDutchman::halt(float32) STUB_VOID

namespace {

	inline void set_vert(RwIm3DVertex&, const xVec3&, float32, float32, uint8) STUB_VOID;
	void set_beam_verts(RwIm3DVertex* vert, const xVec3& loc0, const xVec3& loc1, uint8 a0, uint8 a1, const xVec3& half_right) STUB_VOID;
	xVec3 world_to_screen(const xVec3& loc) STUB;
	RwIm3DVertex* render_beam(RwIm3DVertex* vert, const zNPCDutchman::beam_info& beam, ulong32 which, uint8 alpha) STUB;
	RwIm3DVertex* render_beam(RwIm3DVertex*, const zNPCDutchman::beam_info&) STUB;

}

void zNPCDutchman::render_beam() STUB_VOID
void zNPCDutchman::render_halo() STUB_VOID

xFactoryInst* zNPCGoalDutchmanNil::create(int32 who, RyzMemGrow* grow, void*) STUB

xFactoryInst* zNPCGoalDutchmanInitiate::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalDutchmanInitiate::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDutchmanInitiate::Exit(float32, void*) STUB
bool32 zNPCGoalDutchmanInitiate::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

xFactoryInst* zNPCGoalDutchmanIdle::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalDutchmanIdle::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDutchmanIdle::Exit(float32, void*) STUB
bool32 zNPCGoalDutchmanIdle::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

xFactoryInst* zNPCGoalDutchmanDisappear::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalDutchmanDisappear::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDutchmanDisappear::Exit(float32, void*) STUB
bool32 zNPCGoalDutchmanDisappear::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

xFactoryInst* zNPCGoalDutchmanTeleport::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalDutchmanTeleport::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDutchmanTeleport::Exit(float32, void*) STUB
bool32 zNPCGoalDutchmanTeleport::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

xFactoryInst* zNPCGoalDutchmanReappear::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalDutchmanReappear::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDutchmanReappear::Exit(float32, void*) STUB
bool32 zNPCGoalDutchmanReappear::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

xFactoryInst* zNPCGoalDutchmanBeam::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalDutchmanBeam::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDutchmanBeam::Exit(float32, void*) STUB
bool32 zNPCGoalDutchmanBeam::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalDutchmanBeam::update_stop(float32) STUB_VOID
void zNPCGoalDutchmanBeam::update_focus(float32) STUB_VOID
void zNPCGoalDutchmanBeam::update_fire(float32 dt) STUB_VOID
void zNPCGoalDutchmanBeam::update_unfocus(float32) STUB_VOID
void zNPCGoalDutchmanBeam::aim_beam(beam_data&, const xVec3&, float32) const STUB_VOID
void zNPCGoalDutchmanBeam::calc_beam_loc(xVec2& loc, float32 dist, const beam_data& data) const STUB_VOID
void zNPCGoalDutchmanBeam::update_beam(float32 dt, beam_data& beam, int32 which) STUB_VOID
void zNPCGoalDutchmanBeam::refresh_beam(int32 which) STUB_VOID
void zNPCGoalDutchmanBeam::start_effects(int32, float32) STUB_VOID
void zNPCGoalDutchmanBeam::add_miss_effects(int32, float32) STUB_VOID
void zNPCGoalDutchmanBeam::add_blast_effects(int32 which, float32 dt) STUB_VOID
void zNPCGoalDutchmanBeam::add_effects(int32 which, float32 dt) STUB_VOID
void zNPCGoalDutchmanBeam::predict_target(xVec3& target) const STUB_VOID

xFactoryInst* zNPCGoalDutchmanFlame::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalDutchmanFlame::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDutchmanFlame::Exit(float32, void*) STUB
bool32 zNPCGoalDutchmanFlame::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalDutchmanFlame::update_wait(float32) STUB_VOID
void zNPCGoalDutchmanFlame::update_move(float32) STUB_VOID
void zNPCGoalDutchmanFlame::update_stop(float32 dt) STUB_VOID

namespace {

	inline float32 angle_difference(const xVec2&, const xVec2&) STUB;

}

void zNPCGoalDutchmanFlame::refresh_vulnerability() STUB_VOID

xFactoryInst* zNPCGoalDutchmanPostFlame::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalDutchmanPostFlame::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDutchmanPostFlame::Exit(float32, void*) STUB
bool32 zNPCGoalDutchmanPostFlame::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

xFactoryInst* zNPCGoalDutchmanCaught::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalDutchmanCaught::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDutchmanCaught::Exit(float32, void*) STUB
bool32 zNPCGoalDutchmanCaught::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

xFactoryInst* zNPCGoalDutchmanDamage::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalDutchmanDamage::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDutchmanDamage::Exit(float32, void*) STUB
bool32 zNPCGoalDutchmanDamage::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

xFactoryInst* zNPCGoalDutchmanDeath::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalDutchmanDeath::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalDutchmanDeath::Exit(float32, void*) STUB
bool32 zNPCGoalDutchmanDeath::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB