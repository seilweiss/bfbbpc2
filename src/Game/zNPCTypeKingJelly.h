#pragma once

#include "zNPCTypeSubBoss.h"
#include "zNPCGoalCommon.h"
#include "xColor.h"
#include "xDebug.h"

struct zLightning;
struct zEnt;

struct lightning_ring
{
	bool active;
	xVec3 center;
	float32 segment_length;
	float32 min_height;
	float32 max_height;
	float32 min_radius;
	float32 max_radius;
	float32 delay;
	float32 accel;
	float32 max_vel;
	float32 width;
	struct
	{
		float32 height;
		float32 radius;
		float32 vel;
		float32 accel;
		float32 time;
	} current;
	struct
	{
		uint8 line;
		float32 thickness;
		xColor color;
		float32 rot_radius;
		float32 degrees;
	} property;
	zLightning* arcs[8];
	uint32 arcs_size;
	void(*update_callback)(lightning_ring&, float32);

	void create();
	void destroy();
	void refresh();
	void create_arc(xVec3*, xVec3*, int32, int32);
	void update(float32) STUB_VOID;
};

enum shockstate_enum
{
	SS_START,
	SS_WARM_UP,
	SS_RELEASE,
	SS_COOL_DOWN,
	SS_STOP,
	MAX_SS
};

class zNPCKingJelly : public zNPCSubBoss
{
private:
	struct child_data
	{
		zNPCCommon* npc;
		uint8 wave;
		uint8 active;
		struct
		{
			xBaseEventCallback eventFunc;
			xEntUpdateCallback update;
			xEntBoundUpdateCallback bupdate;
			xEntMoveCallback move;
			xEntRenderCallback render;
			void(*updateTimerFunc)(xEnt*);
			xEntTranslateCallback transl;
		} callback;
		struct
		{
			uint16 model;
			uint8 pflags;
			uint8 moreFlags;
			uint8 flg_colCheck;
			uint8 flg_penCheck;
			uint8 chkby;
			uint8 penby;
		} flags;
	};

	struct
	{
		uint8 moreFlags;
	} old;
	struct
	{
		bool fighting;
		bool died;
		bool charging;
		bool stop_moving;
		bool updated;
	} flag;
	int32 round;
	int32 attack;
	int32 life;
	uint32 player_life;
	int32 show_vertex;
	bool enabled;
	shockstate_enum shockstate;
	float32 spawn_particle_vel;
	xModelInstance* submodel[4];
	struct
	{
		bool active;
		int32 count;
		float32 intensity;
		float32 delay;
	} blink;
	struct
	{
		float32 last_yaw;
		xVec3 last_target;
	} camera;
	child_data children[32];
	uint32 children_size;
	float32 last_tentacle_shock;
	zLightning* tentacle_lightning[7];
	xVec3 tentacle_points[13][7];
	lightning_ring ambient_rings[3];
	lightning_ring wave_rings[4];
	bool disable_tentacle_damage;
	float32 next_pulse;
	float32 last_pulse;
	zEnt* curtain_ent;
	xModelInstance* curtain_model[5];
	bool first_update;

public:
	zNPCKingJelly(int32 myType);

	virtual void Init(xEntAsset* asset);
	virtual void Setup();
	virtual void Reset();
	virtual void Destroy();
	virtual void Process(xScene* xscn, float32 dt);
	virtual void BUpdate(xVec3* pos);
	virtual bool32 SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled);
	virtual void RenderExtra();
	virtual void ParseINI();
	virtual void ParseLinks();
	virtual void SelfSetup();
	virtual void Damage(en_NPC_DAMAGE_TYPE damtype, xBase*, const xVec3*);
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*);

	float32 get_variance() const;
	bool bored() const;
	int32 max_strikes() const;
	void update_camera(float32);
	void set_life(int32 life);
	void update_round();
	void add_child(xBase& child, int32 wave);
	void init_child(child_data&, zNPCCommon&, int32);
	void disable_child(child_data&);
	void enable_child(child_data&);
	int32 count_children(int32);
	void spawn_children(int32 wave, int32 count);
	void move_to_spawn_position(zNPCCommon&, float32);
	void taunt();
	void repel_player();
	xVec3 get_away() const;
	bool apply_tentacle_damage();
	bool apply_wave_damage();
	bool apply_ambient_damage();
	void check_player_damage();
	void start_fight();
	void decompose();
	void post_decompose();
	void vanish();
	void reappear();
	void create_tentacle_lightning();
	zLightning* new_tentacle_lightning(xVec3* points);
	void destroy_tentacle_lightning();
	void update_tentacle_lightning(float32 dt);
	void generate_zap_particles(const zLightning& zap, float32 amount, float32 dt);
	void refresh_tentacle_points(int32 which);
	void refresh_tentacle_points();
	void update_rings(float32 dt);
	void create_ambient_rings();
	void destroy_ambient_rings();
	void create_wave_rings();
	void destroy_wave_rings();
	void generate_spawn_particles();
	void update_spawn_particles(float32 dt);
	void generate_ring_particles(const lightning_ring& ring, float32 dt);
	void generate_thump_particles();
	void start_charge();
	void update_charge(float32 frac);
	void end_charge();
	void load_model();
	void load_curtain_model();
	void show_shower_model();
	void show_attack_model();
	void fade_curtain();
	void reset_curtain();
	void start_blink();
	void update_blink(float32 dt);
	void render_debug() {}
	xVec3 get_center() const STUB;
	xVec3* get_bottom() const STUB;

	static void on_change_ambient_ring(const tweak_info&) {}
	static void on_change_fade_obstructions(const tweak_info&) {}
};

class zNPCGoalKJIdle : public zNPCGoalCommon
{
private:
	float32 attack_delay;

public:
	zNPCGoalKJIdle(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void rotate(float32);
	void move(float32 dt);
};

class zNPCGoalKJBored : public zNPCGoalCommon
{
public:
	zNPCGoalKJBored(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalKJSpawnKids : public zNPCGoalCommon
{
private:
	float32 delay;
	int32 cycle;
	uint8 spawned;
	uint8 spewed;
	int32 child_count;
	int32 spawn_count;

public:
	zNPCGoalKJSpawnKids(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalKJTaunt : public zNPCGoalCommon
{
public:
	zNPCGoalKJTaunt(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalKJShockGround : public zNPCGoalCommon
{
private:
	float32 delay;
	int32 strikes;

public:
	zNPCGoalKJShockGround(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	shockstate_enum update_start(float32);
	shockstate_enum update_warm_up(float32 dt);
	shockstate_enum update_release(float32);
	shockstate_enum update_cool_down(float32 dt);
	shockstate_enum update_stop(float32);
};

class zNPCGoalKJDamage : public zNPCGoalCommon
{
public:
	zNPCGoalKJDamage(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalKJDeath : public zNPCGoalCommon
{
public:
	zNPCGoalKJDeath(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

xAnimTable* ZNPC_AnimTable_KingJelly();