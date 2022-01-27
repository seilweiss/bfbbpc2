#pragma once

#include "zNPCGoalCommon.h"
#include "zNPCTypeSubBoss.h"
#include "containers.h"

struct z_disco_floor;

struct aqua_beam
{
	struct ring_segment
	{
		xModelInstance* model;
		xVec3 origin;
		float32 dist;
		float32 vel;
		uint32 sound_handle;
		xMat4x3 mat;
	};

	typedef fixed_queue<ring_segment, 31> ring_segment_queue;

	struct squiggle_segment
	{
		xMat4x3 mat;
		struct
		{
			float32 freq;
			float32 offset;
			float32 move;
		} layer[3];
	};

	struct config
	{
		float32 duration;
		int32 sound_interval;
		struct
		{
			float32 size;
			float32 alpha;
			float32 vel;
			float32 accel;
			float32 emit_delay;
			float32 grow;
			float32 fade_dist;
			float32 kill_dist;
			float32 follow;
			float32 hit_radius;
			xVec3 hit_offset;
		} ring;
	};

	struct fire_type : config
	{
		int32 emit_bone;
		xVec3 offset;
		float32 yaw;
		float32 pitch;
	};

	config cfg;
	bool firing;
	xVec3 loc;
	xVec3 dir;
	xMat4x3 mat;
	float32 time;
	struct
	{
		RpAtomic* model_data;
		float32 emit_time;
		ring_segment_queue queue;
	} ring;
	struct
	{
		squiggle_segment set[8];
		float32 alpha;
		float32 scale;
	} squiggle;
	int32 ring_sounds;

	void load(const config&, uint32);
	void load(const config&, RpAtomic&);
	void reset();
	void start();
	void stop();
	void update(float32);
	void render();
	bool hits_sphere(const xSphere& o) const;
	void update_rings(float32 dt);
	void emit_ring();
	void kill_ring();
	void update_ring(ring_segment_queue::iterator, float32);
	void render_ring(ring_segment& r);
	bool active() const STUB;
	void move(const xVec3&, const xVec3&) STUB_VOID;
};

class zNPCPrawn : public zNPCSubBoss
{
public:
	enum floor_state_enum
	{
		FS_SAFE,
		FS_BEGIN,
		FS_BEAM,
		FS_AIM_LANE,
		FS_LANE,
		FS_DANGER
	};

	struct range_type
	{
		int32 min;
		int32 max;
	};

private:
	struct
	{
	} flag;
	int32 life;
	int32 round;
	bool face_player;
	xVec2 look_dir;
	z_disco_floor* disco;
	zNPCSpawner* spawner[3];
	uint32 danger_mask;
	floor_state_enum floor_state;
	int32 floor_state_index;
	uint32 floor_state_counter;
	float32 floor_time;
	float32 delay;
	bool first_update;
	bool fighting;
	struct
	{
		bool change;
		floor_state_enum floor_state;
		uint32 counter;
		range_type pattern;
		float32 transition_delay;
		float32 state_delay;
	} pending;
	struct
	{
		float32 sin_pitch;
		float32 cos_pitch;
	} precomp;
	struct
	{
		float32 vel;
		float32 accel;
		float32 max_vel;
	} turn;
	aqua_beam beam;
	xVec3 closeup_loc[8][4];
	xModelInstance* closeup_model[8];
	uint32 closeups_used;

public:
	zNPCPrawn(int32 myType);

	virtual void Init(xEntAsset* asset);
	virtual void Setup();
	virtual void Reset();
	virtual void Destroy();
	virtual void Process(xScene* xscn, float32 dt);
	virtual void NewTime(xScene* xscn, float32 dt);
	virtual bool32 SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled);
	virtual void ParseINI();
	virtual void ParseLinks();
	virtual void SelfSetup();
	virtual void Damage(en_NPC_DAMAGE_TYPE damtype, xBase*, const xVec3*);
	virtual void DuploNotice(en_SM_NOTICES note, void* data);
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*);
	virtual void Render();
	virtual uint8 ColChkFlags() const WIP { return 0; }
	virtual uint8 ColPenFlags() const WIP { return 0; }
	virtual uint8 ColChkByFlags() const WIP { return 0x10; }
	virtual uint8 ColPenByFlags() const WIP { return 0x10; }
	virtual uint8 PhysicsFlags() const WIP { return 0x3; }
	virtual bool32 IsAlive() STUB;

	void update_round();
	void decompose();
	zNPCSpawner* make_spawner(int32);
	void add_child(xBase& child, int32 wave);
	void update_turn(float32 dt);
	void update_animation(float32);
	void update_floor(float32);
	void update_beam(float32 dt);
	void update_particles(float32);
	void update_camera(float32);
	void start_fight();
	void get_floor_info(floor_state_enum s, range_type& pattern, float32& transition_delay, float32& state_delay);
	void apply_pending();
	void set_floor_state(floor_state_enum s, bool immediate, bool force);
	void vanish();
	void reappear();
	void render_closeup();
	void set_life(int32 life);
	bool check_player_damage();
	xVec3 get_away() const;
	void repel_player() const;
	void show_model();
	void hide_model();
	xVec3* get_center() const STUB;
	void render_debug() {}
	bool turning() const STUB;
	xVec3* get_facing() const STUB;
};

class zNPCGoalPrawnIdle : public zNPCGoalCommon
{
public:
	zNPCGoalPrawnIdle(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalPrawnBeam : public zNPCGoalCommon
{
private:
	enum substate_enum
	{
		SS_AIM,
		SS_FIRE,
		SS_HOLD,
		SS_SWEEP,
		SS_STOP,
		MAX_SS
	};

	substate_enum substate;
	int32 sweeps;
	float32 sweep_dir;
	float32 delay;

public:
	zNPCGoalPrawnBeam(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	
	substate_enum update_aim(float32);
	substate_enum update_fire(float32);
	substate_enum update_hold(float32);
	substate_enum update_sweep(float32);
	substate_enum update_stop(float32);
	void init_look_dir();
};

class zNPCGoalPrawnBowl : public zNPCGoalCommon
{
private:
	bool aiming;

public:
	zNPCGoalPrawnBowl(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalPrawnDamage : public zNPCGoalCommon
{
public:
	zNPCGoalPrawnDamage(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalPrawnDeath : public zNPCGoalCommon
{
public:
	zNPCGoalPrawnDeath(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

xAnimTable* ZNPC_AnimTable_Prawn();