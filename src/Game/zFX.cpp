#include "zFX.h"

#include "xDebug.h"
#include "xModel.h"
#include "zScene.h"

static void on_spawn_bubble_wall(const tweak_info&) STUB_VOID
void zFX_SceneEnter(RpWorld* world) STUB_VOID
void zFX_SceneExit(RpWorld* world) STUB_VOID
void zFX_SceneReset() STUB_VOID
void zFXPatrickStun(const xVec3* pos) STUB_VOID
void zFXHammer(const xVec3* pos) STUB_VOID
void zFXPorterWave(const xVec3* pos) STUB_VOID
void zFXGooEnable(RpAtomic* atomic, int32 freezeGroup) STUB_VOID
void zFXGoo_SceneEnter() STUB_VOID
static void zFXGoo_SceneReset() STUB_VOID
void zFXGoo_SceneExit() STUB_VOID
void zFXGooUpdateInstance(zFXGooInstance* goo, float32 dt) STUB_VOID
void zFXGooUpdate(float32) STUB_VOID
RpAtomic* zFXGooRenderAtomic(RpAtomic* atomic) STUB
void zFXUpdate(float32 dt) STUB_VOID
void zFXGooFreeze(RpAtomic* atomic, const xVec3* center, xVec3* ref_parPosVec) STUB_VOID
bool32 zFXGooIs(xEnt* obj, float32& depth, uint32 playerCheck) STUB
void zFXGooEventSetWarb(xEnt* ent, const float32* warb) STUB_VOID
void zFXGooEventSetFreezeDuration(xEnt* ent, float32 duration) STUB_VOID
void zFXGooEventMelt(xEnt* ent) STUB_VOID
float32 zFXGooFreezeTimeLeft() STUB
void zFX_SpawnBubbleHit(const xVec3* pos, uint32 num) STUB_VOID
void zFX_SpawnBubbleHit(const xVec3* pos, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd, float32 vel_scale) STUB_VOID
void zFX_SpawnBubbleTrail(const xVec3* pos, uint32 num) STUB_VOID
void zFX_SpawnBubbleTrail(const xVec3* pos, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd) STUB_VOID
void zFX_SpawnBubbleTrailNoNegRandVel(const xVec3* pos, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd) STUB_VOID
void zFX_SpawnBubbleTrail(const xVec3* p1, const xVec3* p2, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd) STUB_VOID
void zFX_SpawnBubbleTrail(const xVec3* p1, const xVec3* p2, const xVec3* vel1, const xVec3* vel2, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd, float32 scale) STUB_VOID
void zFX_SpawnBubbleMenuTrail(const xVec3* pos, uint32 num, const xVec3* pos_rnd, const xVec3* vel_rnd) STUB_VOID
void zFX_SpawnBubbleWall() STUB_VOID
void zFX_SpawnBubbleSlam(const xVec3* pos, uint32 num, float32 rang, float32 bvel, float32 rvel) STUB_VOID
void zFX_SpawnBubbleBlast(const xVec3* pos, uint32 num, float32 radius, float32 blast_vel, float32 rand_vel) STUB_VOID

namespace {

	enum state_enum
	{
		STATE_NONE,
		STATE_OFF,
		STATE_ON
	};

	struct popper_data
	{
		state_enum state;
		xEnt* ent;
		RpAtomic* atomic[4];
		uint32 atomic_size;
		float32 time;
		float32 end_time;
		union
		{
			xVec3 model_scale;
			uint32 pipe_flags;
		};
		float32 rate;
		float32 vel;
		float32 rloc;
		float32 rvel;
		float32 emitted;
		int32 faces;
		float32 radius;
		float32 area;
		float32 weight[768];

		int32 find_weight(float32) const STUB;
	};

	bool model_is_preinstanced(RpAtomic*) STUB;
	bool setup_popper_emitter(popper_data& popper);
	float32 get_triangle_area(const xVec3&, const xVec3&, const xVec3&) STUB;
	int32 count_faces(xModelInstance*) STUB;
	void eval_tri(xVec3* vert, xVec3* norm, const xMat4x3* mat, const RpGeometry* geom, const RpTriangle* tri) STUB_VOID;
	void SkinXformVertAndNormal(xVec3*, xVec3*, const xVec3*, const xVec3*, const xMat4x3*, const xMat4x3*, const float32*, const uint32*, const uint16*, uint32) STUB_VOID;
	void random_point_on_triangle(xVec3& loc, xVec3& norm, const xVec3* v, const xVec3* n) STUB_VOID;
	void random_surface_point(xVec3& loc, xVec3& norm, const popper_data& popper) STUB_VOID;
	popper_data* find_popper(xEnt*) STUB;
	popper_data* find_free_popper() STUB;
	void emit_popper_bubbles(popper_data& popper, int32 emit, float32 scale, float32 vel_add) STUB_VOID;
	void emit_popper_bubbles_immediate(popper_data&) STUB_VOID;
	void update_popper(popper_data& popper, float32 dt) STUB_VOID;
	void set_popper_alpha(popper_data&, float32) STUB_VOID;
	void destroy_popper(popper_data&) STUB_VOID;
	popper_data* grab_popper(xEnt&) STUB;
	void add_popper_tweaks() WIP {}
	bool validate_popper(const xEnt&) STUB;

}

static void init_poppers() STUB_VOID
static void reset_poppers() STUB_VOID
static void update_poppers(float32) STUB_VOID
void zFXPopOn(xEnt& ent, float32 rate, float32 time) STUB_VOID
void zFXPopOff(xEnt& ent, float32 rate, float32 time) STUB_VOID

namespace {

	struct entrail_data
	{
		uint16 flags;
		uint16 type;
		xEnt* ent;
		xVec3 loc;
		xVec3 vel;
		float32 emitted;

		void reset() STUB_VOID;
		void update(float32) STUB_VOID;
	};

	void add_entrail_tweaks() STUB_VOID;

}

static void reset_entrails() STUB_VOID
static void update_entrails(float32 dt) STUB_VOID
static void setup_entrails(zScene& s) STUB_VOID