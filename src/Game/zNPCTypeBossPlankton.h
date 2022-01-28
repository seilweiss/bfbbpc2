#pragma once

#include "zNPCTypeBoss.h"
#include "xDecal.h"
#include "xLaserBolt.h"

struct zEntDestructObj;
struct xTimer;
class zNPCNewsFish;

class zNPCBPlankton : public zNPCBoss
{
public:
	enum move_enum
	{
		MOVE_NONE,
		MOVE_ACCEL,
		MOVE_STOP,
		MOVE_ORBIT
	};

	enum follow_enum
	{
		FOLLOW_NONE,
		FOLLOW_PLAYER,
		FOLLOW_CAMERA
	};

	enum mode_enum
	{
		MODE_BUDDY,
		MODE_HARASS
	};

	struct move_info
	{
		xVec3 dest;
		xVec3 vel;
		xVec3 accel;
		xVec3 max_vel;
	};

	struct territory_data
	{
		zMovePoint* origin;
		xEnt* platform;
		zEntDestructObj* fuse;
		xTimer* timer;
		zNPCCommon* crony[8];
		int32 crony_size;
		bool fuse_detected;
		bool fuse_destroyed;
		float32 fuse_detect_time;
	};

private:
	struct
	{
		bool updated;
		bool face_player;
		bool attacking;
		bool hunt;
		bool aim_gun;
		move_enum move;
		follow_enum follow;
	} flag;
	mode_enum mode;
	float32 delay;
	xQuat gun_tilt;
	float32 ambush_delay;
	float32 beam_duration;
	float32 stun_duration;
	xDecalEmitter beam_ring;
	xDecalEmitter beam_glow;
	xLaserBoltEmitter beam;
	xParEmitter* beam_charge;
	struct
	{
		xVec3 center;
		float32 radius;
	} orbit;
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
		float32 delay;
		float32 max_delay;
	} follow;
	struct
	{
		uint8 moreFlags;
	} old;
	zNPCBoss* crony;
	territory_data territory[8];
	int32 territory_size;
	int32 active_territory;
	zNPCNewsFish* newsfish;
	uint32 old_player_health;
	bool played_intro;

public:
	zNPCBPlankton(int32 myType);

	virtual void Init(xEntAsset* asset);
	virtual void Setup();
	virtual void PostSetup();
	virtual void Reset();
	virtual void Destroy();
	virtual void Process(xScene* xscn, float32 dt);
	virtual bool32 SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled);
	virtual void Render();
	virtual void RenderExtraPostParticles();
	virtual void ParseINI();
	virtual void ParseLinks();
	virtual void SelfSetup();
	virtual void Damage(en_NPC_DAMAGE_TYPE damtype, xBase*, const xVec3* vec_hit);
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*);
	virtual uint8 ColChkFlags() const WIP { return 0; }
	virtual uint8 ColPenFlags() const WIP { return 0; }
	virtual uint8 ColChkByFlags() const WIP { return 0x10; }
	virtual uint8 ColPenByFlags() const WIP { return 0x10; }
	virtual uint8 PhysicsFlags() const WIP { return 0x3; }
	virtual bool32 IsAlive() WIP { return TRUE; }

	int32 next_goal();
	void refresh_orbit();
	void scan_cronies();
	void update_turn(float32 dt);
	void update_move(float32);
	void reset_territories();
	void update_dialog(float32 dt);
	void update_animation(float32);
	void update_follow(float32 dt);
	void update_follow_player(float32 dt);
	void update_follow_camera(float32 dt);
	void update_aim_gun(float32);
	bool check_player_damage();
	float32 orbit_yaw_offset(const xVec3& p0, const xVec3& p1) const;
	void load_territory(int32 index, xBase& child);
	void init_beam();
	void setup_beam();
	void reset_beam();
	void vanish();
	void reappear();
	xVec3 random_orbit(const xVec3& loc, float32 min_ang, float32 max_ang) const;
	xVec3 player_orbit() const;
	bool crony_attacking() const;
	void stun();
	bool cronies_dead() const;
	void impart_velocity(const xVec3& vel);
	void next_territory();
	bool have_cronies() const;
	bool move_to_player_territory();
	bool player_left_territory() const;
	void say(int32, int32, bool);
	void sickum();
	void here_boy();
	void follow_player();
	void follow_camera();
	void reset_speed();
	void halt(float32 accel);
	void fall(float32 accel, float32 max_vel);

	static void aim_gun(xAnimPlay* play, xQuat* quat, xVec3*, int32);

	const xVec3& location() const STUB_REF(xVec3);
	void face_player() STUB_VOID;
	void render_debug() {}
	bool turning() const STUB;
	void take_control() STUB_VOID;
	float32 get_orbit_yaw(const xVec3&) const STUB;
	void set_location(const xVec3&) STUB_VOID;
	void give_control() STUB_VOID;
	void enable_emitter(xParEmitter&) const STUB_VOID;
	void disable_emitter(xParEmitter&) const STUB_VOID;
};

class zNPCGoalBPlanktonIdle : public zNPCGoalCommon
{
private:
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonIdle(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32, void*, xScene*);

	void get_yaw(float32& optimal, float32& dist) const;
	void apply_yaw(float32);
};

class zNPCGoalBPlanktonAttack : public zNPCGoalCommon
{
private:
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonAttack(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32, void*, xScene*);
};

class zNPCGoalBPlanktonAmbush : public zNPCGoalCommon
{
private:
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonAmbush(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void*, xScene*);
};

class zNPCGoalBPlanktonFlank : public zNPCGoalCommon
{
private:
	float32 accel;
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonFlank(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);
	
	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32, void*, xScene*);
};

class zNPCGoalBPlanktonEvade : public zNPCGoalCommon
{
private:
	float32 evade_delay;
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonEvade(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32, void*, xScene*);
};

class zNPCGoalBPlanktonHunt : public zNPCGoalCommon
{
private:
	xVec3 player_loc;
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonHunt(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32, void*, xScene*);
};

class zNPCGoalBPlanktonTaunt : public zNPCGoalCommon
{
private:
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonTaunt(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);
	
	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32 dt, void*);
	virtual bool32 Process(en_trantype*, float32, void*, xScene*);
};

class zNPCGoalBPlanktonMove : public zNPCGoalCommon
{
private:
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonMove(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype*, float32, void*, xScene*);
};

class zNPCGoalBPlanktonStun : public zNPCGoalCommon
{
private:
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonStun(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt);
};

class zNPCGoalBPlanktonFall : public zNPCGoalCommon
{
private:
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonFall(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32, void*, xScene*);
};

class zNPCGoalBPlanktonDizzy : public zNPCGoalCommon
{
private:
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonDizzy(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void*, xScene*);
};

class zNPCGoalBPlanktonBeam : public zNPCGoalCommon
{
private:
	enum substate_enum
	{
		SS_WARM_UP,
		SS_FIRE,
		SS_COOL_DOWN,
		SS_DONE
	};

	float32 emitted;
	substate_enum substate;
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonBeam(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void*, xScene*);

	void update_warm_up(float32);
	void update_fire(float32 dt);
	void update_cool_down(float32);
};

class zNPCGoalBPlanktonWall : public zNPCGoalCommon
{
private:
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonWall(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype*, float32, void*, xScene*);
};

class zNPCGoalBPlanktonMissle : public zNPCGoalCommon
{
private:
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonMissle(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype*, float32, void*, xScene*);
};

class zNPCGoalBPlanktonBomb : public zNPCGoalCommon
{
private:
	zNPCBPlankton& owner;

public:
	zNPCGoalBPlanktonBomb(int32 myType, zNPCBPlankton& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype*, float32, void*, xScene*);
};

xAnimTable* ZNPC_AnimTable_BossPlankton();