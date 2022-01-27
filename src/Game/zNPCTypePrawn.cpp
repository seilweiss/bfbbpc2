#include "zNPCTypePrawn.h"

#include "xColor.h"
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
		float32 turn_accel;
		float32 spawn_delay;
		float32 repel_radius;
		struct
		{
			zNPCPrawn::range_type pattern;
		} safe;
		struct
		{
			zNPCPrawn::range_type pattern;
			float32 state_delay;
			float32 transition_delay;
		} begin;
		struct
		{
			float32 delay[3];
			zNPCPrawn::range_type pattern;
			float32 state_delay;
			float32 transition_delay;
			float32 exhaust_vel;
			float32 knock_back;
			struct
			{
				int32 amount[3];
				float32 arc;
				float32 delay;
				float32 accel;
				float32 max_vel;
			} sweep;
			aqua_beam::fire_type fire;
		} beam;
		struct
		{
			float32 duration;
			float32 state_delay;
			float32 transition_delay;
			struct
			{
				int32 first;
				int32 range;
				int32 offset;
				int32 size;
			} pattern;
		} aim_lane;
		struct
		{
			float32 duration[3];
			float32 state_delay;
			float32 transition_delay;
			struct
			{
				int32 first;
				int32 range;
				int32 offset;
				int32 size;
			} pattern;
		} lane;
		struct
		{
			float32 state_delay;
			float32 transition_delay;
			float32 cycle_delay;
			int32 pattern_offset;
			int32 pattern_size;
			zNPCPrawn::range_type pattern[20];
		} danger;
		sound_property sound[4];
		void* context;
		tweak_callback cb_sound;
		tweak_callback cb_sound_asset;

		void register_tweaks(bool init, xModelAssetParam* ap, uint32 apsize, const char*) STUB_VOID
		void load(xModelAssetParam*, uint32) STUB_VOID;
	};

	void init_sound() STUB_VOID;
	void reset_sound() STUB_VOID;
	void play_sound(int32, const xVec3*, float32) STUB_VOID;
	void kill_sound(int32, uint32) STUB_VOID;
	void kill_sound(int32) STUB_VOID;

}

void aqua_beam::load(const config&, uint32) STUB_VOID
void aqua_beam::load(const config&, RpAtomic&) STUB_VOID
void aqua_beam::reset() STUB_VOID
void aqua_beam::start() STUB_VOID
void aqua_beam::stop() STUB_VOID
void aqua_beam::update(float32) STUB_VOID
void aqua_beam::render() STUB_VOID
bool aqua_beam::hits_sphere(const xSphere& o) const STUB
void aqua_beam::update_rings(float32 dt) STUB_VOID
void aqua_beam::emit_ring() STUB_VOID
void aqua_beam::kill_ring() STUB_VOID
void aqua_beam::update_ring(ring_segment_queue::iterator, float32) STUB_VOID
void aqua_beam::render_ring(ring_segment& r) STUB_VOID

namespace {

	struct television
	{
		RwCamera* cam;
		RwRaster* raster;
		RwRaster* bgraster;
		RpWorld* world;
		RwTexture* texture;
		uint32 vert_buffer_used;
		RwRGBA bgcolor;
		float32 rcz;
		float32 w;
		float32 h;

		void create(int32, int32) STUB_VOID;
		void destroy() STUB_VOID;
		void set_background(xColor) STUB_VOID;
		void set_model_texture(xModelInstance&) STUB_VOID;
		void update(xModelInstance&, xLightKit*) STUB_VOID;
		void render_static() {}
		void render_background() STUB_VOID;
		void set_vert(RwIm2DVertex&, float32, float32, float32, float32) STUB_VOID;
		void move(const xVec3&, const xVec3&) STUB_VOID;
	};

}

xAnimTable* ZNPC_AnimTable_Prawn() STUB

zNPCPrawn::zNPCPrawn(int32 myType) : zNPCSubBoss(myType) STUB_VOID
void zNPCPrawn::Init(xEntAsset* asset) STUB_VOID
void zNPCPrawn::Setup() STUB_VOID
void zNPCPrawn::Reset() STUB_VOID
void zNPCPrawn::Destroy() STUB_VOID
void zNPCPrawn::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCPrawn::NewTime(xScene* xscn, float32 dt) STUB_VOID
bool32 zNPCPrawn::SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled) STUB

namespace {

	int32 load_patterns(xModelAssetParam*, uint32, const char*, zNPCPrawn::range_type*, int32) STUB;

}

void zNPCPrawn::ParseINI() STUB_VOID
void zNPCPrawn::ParseLinks() STUB_VOID
void zNPCPrawn::SelfSetup() STUB_VOID
void zNPCPrawn::Damage(en_NPC_DAMAGE_TYPE damtype, xBase*, const xVec3*) STUB_VOID
void zNPCPrawn::DuploNotice(en_SM_NOTICES note, void* data) STUB_VOID
uint32 zNPCPrawn::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*) STUB
void zNPCPrawn::Render() STUB_VOID
void zNPCPrawn::update_round() STUB_VOID
void zNPCPrawn::decompose() STUB_VOID
zNPCSpawner* zNPCPrawn::make_spawner(int32) STUB
void zNPCPrawn::add_child(xBase& child, int32 wave) STUB_VOID

namespace {

	void set_yaw_matrix(xMat3x3&, float32) STUB_VOID;

}

void zNPCPrawn::update_turn(float32 dt) STUB_VOID
void zNPCPrawn::update_animation(float32) STUB_VOID
void zNPCPrawn::update_floor(float32) STUB_VOID

namespace {

	inline void mulat(xVec3&, const xMat3x3&, const xMat3x3&) STUB_VOID;

}

void zNPCPrawn::update_beam(float32 dt) STUB_VOID
void zNPCPrawn::update_particles(float32) {}
void zNPCPrawn::update_camera(float32) STUB_VOID
void zNPCPrawn::start_fight() STUB_VOID
void zNPCPrawn::get_floor_info(floor_state_enum s, range_type& pattern, float32& transition_delay, float32& state_delay) STUB_VOID
void zNPCPrawn::apply_pending() STUB_VOID
void zNPCPrawn::set_floor_state(floor_state_enum s, bool immediate, bool force) STUB_VOID
void zNPCPrawn::vanish() STUB_VOID
void zNPCPrawn::reappear() STUB_VOID
void zNPCPrawn::render_closeup() STUB_VOID
void zNPCPrawn::set_life(int32 life) STUB_VOID
bool zNPCPrawn::check_player_damage() STUB
xVec3 zNPCPrawn::get_away() const STUB
void zNPCPrawn::repel_player() const STUB_VOID
void zNPCPrawn::show_model() STUB_VOID
void zNPCPrawn::hide_model() STUB_VOID

bool32 zNPCGoalPrawnIdle::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPrawnIdle::Exit(float32, void*) STUB
bool32 zNPCGoalPrawnIdle::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalPrawnBeam::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPrawnBeam::Exit(float32, void*) STUB
bool32 zNPCGoalPrawnBeam::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
zNPCGoalPrawnBeam::substate_enum zNPCGoalPrawnBeam::update_aim(float32) STUB
zNPCGoalPrawnBeam::substate_enum zNPCGoalPrawnBeam::update_fire(float32) STUB
zNPCGoalPrawnBeam::substate_enum zNPCGoalPrawnBeam::update_hold(float32) STUB
zNPCGoalPrawnBeam::substate_enum zNPCGoalPrawnBeam::update_sweep(float32) STUB
zNPCGoalPrawnBeam::substate_enum zNPCGoalPrawnBeam::update_stop(float32) STUB
void zNPCGoalPrawnBeam::init_look_dir() STUB_VOID

bool32 zNPCGoalPrawnBowl::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPrawnBowl::Exit(float32, void*) STUB
bool32 zNPCGoalPrawnBowl::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalPrawnDamage::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPrawnDamage::Exit(float32, void*) STUB
bool32 zNPCGoalPrawnDamage::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB

bool32 zNPCGoalPrawnDeath::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalPrawnDeath::Exit(float32, void*) STUB
bool32 zNPCGoalPrawnDeath::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB