#include "zNPCTypeBossSB2.h"

#include "xDebug.h"
#include "xSurface.h"

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
		float32 accel;
		float32 max_vel;
		float32 turn_accel;
		float32 turn_max_vel;
		float32 arena_radius;
		float32 ground_y;
		float32 ground_radius;
		float32 ground_zone_height;
		float32 move_radius;
		float32 damage_speed;
		float32 player_damage_time;
		float32 intro_time;
		struct
		{
			float32 pulse_rate;
			float32 pulse_min;
			float32 pulse_max;
		} nodes;
		struct
		{
			float32 min_dist;
			float32 vel;
			float32 accel;
			float32 decel;
			float32 collide_vel;
		} spin;
		struct
		{
			float32 delay_vuln;
		} help;
		struct
		{
			float32 delay;
		} chop;
		struct
		{
			float32 hold_time;
		} swipe;
		struct
		{
			xVec3 emit_offset;
			float32 emit_arc;
			float32 aim_dist;
			float32 aim_time;
			float32 aim_accel_time;
			float32 fire_vel;
			float32 fire_accel;
			float32 drop_vel;
			float32 drop_accel;
			float32 target_yoffset;
			float32 fade_dist;
			float32 kill_dist;
			float32 delay_emit[3];
			float32 delay_fire[3];
		} karate;
		struct
		{
			float32 warm_up;
			float32 cool_down;
			float32 height;
			float32 move_time;
		} hunt;
		struct
		{
			bool is_sphere;
			bool damage_player;
			int32 bone;
			xVec3 offset;
			float32 radius;
			xVec3 extent;
			float32 yaw;
			float32 pitch;
			float32 roll;
		} bounds[3];
		sound_property sound[10];
		void* context;
		tweak_callback cb_arena;
		tweak_callback cb_ground;
		tweak_callback cb_move_radius;
		tweak_callback cb_bounds;
		tweak_callback cb_hunt_move;
		tweak_callback cb_sound;
		tweak_callback cb_sound_asset;

		void register_tweaks(bool init, xModelAssetParam* ap, uint32 apsize, const char*) STUB_VOID;
		void load(xModelAssetParam*, uint32) STUB_VOID;
	};

	struct response_curve
	{
		struct node
		{
			float32 t;
		};

		struct inode : node
		{
			float32 value[1];
		};

		ulong32 values;
		inode* curve;
		ulong32 nodes;
		ulong32 active_node;

		void init(ulong32, const void*, ulong32, const char*, const char**, const tweak_callback*, void*) STUB_VOID;
		void find_active_node(float32 t) STUB_VOID;
		void eval_linear(float32 t, float32* value) STUB_VOID;
		void eval_smooth(float32, float32*) STUB_VOID;
		float32 start_t() const STUB;
		float32 end_t() const STUB;
		float32 clamp_t(float32) const STUB;
		inode* get_node(ulong32) const STUB;
	};

	void init_sound() STUB_VOID;
	void reset_sound() STUB_VOID;
	void play_sound(int32, const xVec3*, float32) STUB_VOID;
	void kill_sound(int32, uint32) STUB_VOID;
	void set_yaw_matrix(xMat3x3&, float32) STUB_VOID;
	void set_alpha_blend(xModelInstance*) STUB_VOID;
	void init_bound_entity(xEnt&, uint32, xModelInstance*, xMat4x3*) STUB_VOID;
	void parallelepiped_to_obb(xBound& obb, xVec3* loc) STUB_VOID;
	float32 max(float32, float32) STUB;

}

xAnimTable* ZNPC_AnimTable_BossSB2() STUB

void zNPCB_SB2::Init(xEntAsset* asset) STUB_VOID
void zNPCB_SB2::ParseINI() STUB_VOID
void zNPCB_SB2::Setup() STUB_VOID
void zNPCB_SB2::SelfSetup() STUB_VOID
void zNPCB_SB2::Reset() STUB_VOID
void zNPCB_SB2::Destroy() STUB_VOID
uint32 zNPCB_SB2::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*) STUB
void zNPCB_SB2::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCB_SB2::NewTime(xScene* xscn, float32 dt) STUB_VOID
void zNPCB_SB2::Render() STUB_VOID
float32 zNPCB_SB2::AttackTimeLeft() STUB
void zNPCB_SB2::HoldUpDude() {}
void zNPCB_SB2::ThanksImDone() STUB_VOID
void zNPCB_SB2::reset_speed() STUB_VOID
zNPCB_SB2::platform_data* zNPCB_SB2::player_platform() STUB
void zNPCB_SB2::activate_hand(hand_enum, bool) STUB_VOID
void zNPCB_SB2::deactivate_hand(hand_enum) STUB_VOID
bool zNPCB_SB2::player_on_ground() const STUB
void zNPCB_SB2::emit_slug(slug_enum which) STUB_VOID
bool zNPCB_SB2::slugs_ready() const STUB
bool zNPCB_SB2::slugs_inactive() const STUB
void zNPCB_SB2::fire_slug(slug_enum which, platform_data& target) STUB_VOID
void zNPCB_SB2::abandon_slugs() STUB_VOID
int32 zNPCB_SB2::next_goal() STUB
void zNPCB_SB2::reset_stage() STUB_VOID
void zNPCB_SB2::set_vulnerable(bool) STUB_VOID
void zNPCB_SB2::decompose() {}
void zNPCB_SB2::update_turn(float32 dt) STUB_VOID
void zNPCB_SB2::update_halt(float32 dt) STUB_VOID
void zNPCB_SB2::update_follow(float32 dt) STUB_VOID
void zNPCB_SB2::update_ymove(float32) STUB_VOID
void zNPCB_SB2::update_move(float32 dt) STUB_VOID
void zNPCB_SB2::update_camera(float32) STUB_VOID
void zNPCB_SB2::update_nodes(float32 dt) STUB_VOID
void zNPCB_SB2::init_nodes() STUB_VOID
void zNPCB_SB2::show_nodes() STUB_VOID
void zNPCB_SB2::move_nodes() STUB_VOID
void zNPCB_SB2::render_nodes() STUB_VOID
void zNPCB_SB2::bind_nodes() STUB_VOID
void zNPCB_SB2::rebind_nodes(RpAtomic* skin_model, RwMatrix* skin_mat) STUB_VOID
void zNPCB_SB2::setup_node_tags() STUB_VOID
void zNPCB_SB2::check_life() STUB_VOID
void zNPCB_SB2::ouchie() STUB_VOID
void zNPCB_SB2::update_round() STUB_VOID
xSurface& zNPCB_SB2::create_surface() STUB_REF(xSurface)
void zNPCB_SB2::init_hands() STUB_VOID
void zNPCB_SB2::move_hand(hand_data& hand, float32 dt) STUB_VOID
void zNPCB_SB2::spin_platform(platform_data&, const xVec3&, float32, float32) STUB_VOID
void zNPCB_SB2::check_platform_smack(hand_data& hand) STUB_VOID
void zNPCB_SB2::update_platforms(float32 dt) STUB_VOID
void zNPCB_SB2::init_bounds() STUB_VOID
void zNPCB_SB2::reset_bounds() STUB_VOID
void zNPCB_SB2::update_bounds() STUB_VOID
void zNPCB_SB2::init_slugs() STUB_VOID
void zNPCB_SB2::update_aim_slug(slug_data& slug, float32 dt) STUB_VOID
void zNPCB_SB2::update_delay_slug(slug_data&, float32) STUB_VOID
void zNPCB_SB2::update_dying_slug(slug_data&, float32) STUB_VOID
void zNPCB_SB2::update_fire_slug(slug_data& slug, float32 dt) STUB_VOID
void zNPCB_SB2::slug_interp(float32 time, float32& scale) STUB_VOID
void zNPCB_SB2::update_slugs(float32 dt) STUB_VOID
void zNPCB_SB2::scan_cronies() STUB_VOID
void zNPCB_SB2::check_hit_fail() STUB_VOID
void zNPCB_SB2::create_glow_light() STUB_VOID
void zNPCB_SB2::destroy_glow_light() STUB_VOID
void zNPCB_SB2::set_glow_light_intensity(float32) STUB_VOID
void zNPCB_SB2::say(int32) STUB_VOID

xFactoryInst* zNPCGoalBossSB2Intro::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBossSB2Intro::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB2Intro::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB2Intro::Process(en_trantype* trantype, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBossSB2Idle::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBossSB2Idle::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB2Idle::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB2Idle::Process(en_trantype* trantype, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBossSB2Taunt::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBossSB2Taunt::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB2Taunt::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB2Taunt::Process(en_trantype* trantype, float32 dt, void*, xScene*) STUB

xFactoryInst* zNPCGoalBossSB2Dizzy::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBossSB2Dizzy::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB2Dizzy::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB2Dizzy::Process(en_trantype* trantype, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBossSB2Hit::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBossSB2Hit::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB2Hit::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB2Hit::Process(en_trantype* trantype, float32 dt, void*, xScene*) STUB

xFactoryInst* zNPCGoalBossSB2Hunt::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBossSB2Hunt::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB2Hunt::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB2Hunt::Process(en_trantype* trantype, float32, void*, xScene*) STUB

xFactoryInst* zNPCGoalBossSB2Swipe::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBossSB2Swipe::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB2Swipe::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB2Swipe::Process(en_trantype* trantype, float32 dt, void*, xScene*) STUB
bool zNPCGoalBossSB2Swipe::can_start() const STUB

xFactoryInst* zNPCGoalBossSB2Chop::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBossSB2Chop::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB2Chop::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB2Chop::Process(en_trantype* trantype, float32 dt, void*, xScene*) STUB
bool zNPCGoalBossSB2Chop::can_start() const STUB

xFactoryInst* zNPCGoalBossSB2Karate::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBossSB2Karate::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB2Karate::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB2Karate::Process(en_trantype* trantype) STUB
bool zNPCGoalBossSB2Karate::can_start() const STUB

xFactoryInst* zNPCGoalBossSB2Death::create(int32 who, RyzMemGrow* grow, void* info) STUB
bool32 zNPCGoalBossSB2Death::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalBossSB2Death::Exit(float32, void*) STUB
bool32 zNPCGoalBossSB2Death::Process(en_trantype*, float32, void*, xScene*) STUB