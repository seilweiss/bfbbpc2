#pragma once

#include "zNPCTypeSubBoss.h"
#include "zParEmitter.h"
#include "containers.h"

class zNPCDutchman : public zNPCSubBoss
{
public:
	enum move_enum
	{
		MOVE_NONE,
		MOVE_FOLLOW,
		MOVE_ACCEL,
		MOVE_VEL,
		MOVE_STOP
	};

	enum fade_enum
	{
		FADE_NONE,
		FADE_DISSOLVE,
		FADE_TELEPORT,
		FADE_COALESCE
	};

	struct move_info
	{
		xVec3 dest;
		xVec3 vel;
		xVec3 accel;
		xVec3 max_vel;
	};

	struct beam_end
	{
		bool extend;
		xVec3 loc;
	};

	struct beam_info
	{
		bool extend;
		xVec3 start_loc;
		beam_end end[16];
		uint32 segments;
		float32 alpha;
		float32 thickness;
	};

	struct wave_data
	{
		bool clipped;
		xVec3 loc;
		xVec3 dir;
		float32 dist;
		float32 clip_dist;
		float32 vel;
		xVec3 sound_loc;
		uint32 sound_handle;
		int32 emitted[3];
	};

	struct slime_slice
	{
		float32 age;
		float32 dist;
	};

private:
	struct
	{
		bool face_player;
		bool fighting;
		bool beaming;
		bool was_beaming;
		bool hurting;
		bool flaming;
		bool eye_glow;
		bool hand_trail;
		move_enum move;
		fade_enum fade;
	} flag;
	int32 life;
	int32 round;
	int32 stage;
	float32 delay;
	float32 alpha;
	struct
	{
		xVec2 dir;
		float32 vel;
		float32 accel;
		float32 max_vel;
	} turn;
	move_info move;
	struct
	{
		uint8 moreFlags;
	} old;
	beam_info beam[2];
	static_queue<wave_data> waves;
	struct
	{
		float32 size;
		float32 time;
		int32 emitted;
		bool splash_break;
		xVec3 splash_loc;
		bool blob_break;
		xVec3 blob_loc;
		float32 imax_dist;
		xMat3x3 blob_mat;
	} flames;
	struct
	{
		xVec3 loc[2];
	} hand_trail;
	struct
	{
		float32 time;
		float32 duration;
		float32 iduration;
		xVec3 sound_loc;
		uint32 sound_handle;
	} fade;
	struct
	{
		static_queue<slime_slice> slices;
		xVec3 origin;
		xVec3 dir;
	} slime;
	struct
	{
		float32 size;
	} eye_glow;
	zNPCLassoInfo lasso_info;
	RwRaster* laser_raster;

public:
	zNPCDutchman(int32 myType);

	virtual void Init(xEntAsset* asset);
	virtual void Setup();
	virtual void Reset();
	virtual void Destroy();
	virtual void Process(xScene* xscn, float32 dt);
	virtual bool32 SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled);
	virtual void Render();
	virtual void RenderExtra();
	virtual void ParseINI();
	virtual void SelfSetup();
	virtual void Damage(en_NPC_DAMAGE_TYPE, xBase*, const xVec3*);
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*);
	virtual void LassoNotify(en_LASSO_EVENT event);
	virtual bool32 LassoSetup();
	virtual uint8 ColChkFlags() const WIP { return 0; }
	virtual uint8 ColPenFlags() const WIP { return 0; }
	virtual uint8 ColChkByFlags() const WIP { return 0x10; }
	virtual uint8 ColPenByFlags() const WIP { return 0x10; }
	virtual uint8 PhysicsFlags() const WIP { return 0x3; }
	virtual bool32 IsAlive() STUB;
	virtual zNPCLassoInfo* PRIV_GetLassoData() STUB;

	void update_round();
	int32 next_goal();
	float32 goal_delay();
	void decompose();
	void update_turn(float32 dt);
	void update_move(float32 dt);
	void update_animation(float32);
	void update_camera(float32);
	void update_wave(wave_data& wave, float32 dt);
	void init_wave(wave_data& wave, const xVec3& loc, const xVec3& dir);
	void kill_wave(wave_data&);
	void start_eye_glow();
	void stop_eye_glow();
	void update_eye_glow(float32 dt);
	void start_hand_trail();
	void stop_hand_trail();
	void update_hand_trail(float32);
	void dissolve(float32 delay);
	void coalesce(float32 delay);
	void reset_blob_mat();
	void refresh_reticle();
	void reset_lasso_anim();
	void update_fade(float32 dt);
	void update_slime(float32 dt);
	void add_slime(const xVec3& loc, float32 dt);
	void add_spray(const xVec3& loc, float32 dt);
	void add_splash(const xVec3&, float32);
	void update_flames(float32 dt);
	void start_fight();
	void set_life(int32);
	void start_beam();
	void stop_beam();
	void set_alpha(float32);
	void start_flames();
	void stop_flames();
	bool check_player_damage();
	xVec3 get_eye_loc(int32) const;
	xVec3 get_hand_loc(int32) const;
	xVec3 get_splash_loc() const;
	void vanish();
	void reappear();
	xVec3 random_orbit(const xVec3& loc, float32 min_ang, float32 max_ang) const;
	void turn_to_face(const xVec3&);
	void reset_speed();
	void halt(float32);
	void render_beam();
	void render_halo();
	const xVec3& get_center() const STUB_REF(xVec3);
	void face_player() STUB_VOID;
	void render_debug() {}
	void disable_emitter(zParEmitter&) const STUB_VOID;
	bool turning() const STUB;
	void emit_particles(zParEmitter&, float32, xParEmitterCustomSettings&) const STUB_VOID;
	const xVec3& get_orbit() const STUB_REF(xVec3);
	void emit_particles(zParEmitter&, float32) const STUB_VOID;
	const xVec3& get_facing() const STUB_REF(xVec3);
	void enable_emitter(zParEmitter&) const STUB_VOID;
	xVec3 get_nose_loc() const STUB;
	xVec3 get_chest_loc() const STUB;
	bool turning(float32) const STUB;
};

class zNPCGoalDutchmanNil : public zNPCGoalCommon
{
public:
	zNPCGoalDutchmanNil(int32 myType, zNPCDutchman&) WIP : zNPCGoalCommon(myType) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void*);
};

class zNPCGoalDutchmanInitiate : public zNPCGoalCommon
{
private:
	zNPCDutchman& owner;

public:
	zNPCGoalDutchmanInitiate(int32 myType, zNPCDutchman& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalDutchmanIdle : public zNPCGoalCommon
{
private:
	zNPCDutchman& owner;

public:
	zNPCGoalDutchmanIdle(int32 myType, zNPCDutchman& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalDutchmanDisappear : public zNPCGoalCommon
{
private:
	zNPCDutchman& owner;

public:
	zNPCGoalDutchmanDisappear(int32 myType, zNPCDutchman& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalDutchmanTeleport : public zNPCGoalCommon
{
private:
	zNPCDutchman& owner;

public:
	zNPCGoalDutchmanTeleport(int32 myType, zNPCDutchman& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalDutchmanReappear : public zNPCGoalCommon
{
private:
	zNPCDutchman& owner;

public:
	zNPCGoalDutchmanReappear(int32 myType, zNPCDutchman& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalDutchmanBeam : public zNPCGoalCommon
{
public:
	enum substate_enum
	{
		SS_STOP,
		SS_FOCUS,
		SS_FIRE,
		SS_UNFOCUS,
		SS_DONE
	};

	struct beam_data
	{
		xVec2 origin;
		xVec2 dir;
		float32 dist;
		float32 vel;
		float32 wave_offset;
		uint32 ribbon_flags;
		xVec3 loc;
		uint32 impact_sound;
		uint32 glow_sound;
	};

private:
	substate_enum substate;
	int32 shots;
	beam_data beam[2];
	zNPCDutchman& owner;

public:
	zNPCGoalDutchmanBeam(int32 myType, zNPCDutchman& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void update_stop(float32);
	void update_focus(float32);
	void update_fire(float32 dt);
	void update_unfocus(float32);
	void aim_beam(beam_data&, const xVec3&, float32) const;
	void calc_beam_loc(xVec2& loc, float32 dist, const beam_data& data) const;
	void update_beam(float32 dt, beam_data& beam, int32 which);
	void refresh_beam(int32 which);
	void start_effects(int32, float32);
	void add_miss_effects(int32, float32);
	void add_blast_effects(int32 which, float32 dt);
	void add_effects(int32 which, float32 dt);
	void predict_target(xVec3& target) const;
};

class zNPCGoalDutchmanFlame : public zNPCGoalCommon
{
public:
	enum substate_enum
	{
		SS_WAIT,
		SS_MOVE,
		SS_STOP,
		SS_DONE
	};

private:
	substate_enum substate;
	xVec2 move_dir;
	bool stopped;
	zNPCDutchman& owner;

public:
	zNPCGoalDutchmanFlame(int32 myType, zNPCDutchman& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);

	void update_wait(float32);
	void update_move(float32);
	void update_stop(float32 dt);
	void refresh_vulnerability();
};

class zNPCGoalDutchmanPostFlame : public zNPCGoalCommon
{
private:
	zNPCDutchman& owner;

public:
	zNPCGoalDutchmanPostFlame(int32 myType, zNPCDutchman& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalDutchmanCaught : public zNPCGoalCommon
{
private:
	bool grabbed;
	zNPCDutchman& owner;

public:
	zNPCGoalDutchmanCaught(int32 myType, zNPCDutchman& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalDutchmanDamage : public zNPCGoalCommon
{
private:
	bool moving;
	zNPCDutchman& owner;

public:
	zNPCGoalDutchmanDamage(int32 myType, zNPCDutchman& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalDutchmanDeath : public zNPCGoalCommon
{
public:
	enum substate_enum
	{
		SS_DISSOLVE,
		SS_DISPERSE,
		SS_WINK,
		SS_DONE
	};

private:
	substate_enum substate;
	float32 emit_frac;
	float32 min_y;
	float32 max_y;
	zNPCDutchman& owner;

public:
	zNPCGoalDutchmanDeath(int32 myType, zNPCDutchman& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

xAnimTable* ZNPC_AnimTable_Dutchman();