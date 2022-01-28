#pragma once

#include "zNPCTypeBoss.h"
#include "zNPCGoalCommon.h"
#include "xLightKit.h"

class zNPCBPlankton;
class zNPCNewsFish;
struct zEntDestructObj;

class zNPCB_SB2 : public zNPCBoss
{
private:
	enum move_enum
	{
		MOVE_NONE,
		MOVE_HALT,
		MOVE_FOLLOW,
		MOVE_Y
	};

	enum hand_enum
	{
		LEFT_HAND,
		RIGHT_HAND
	};

	struct node_data
	{
		zEntDestructObj* ent;
		float32 pulse;
		xLightKit* old_light_kit;
		RpAtomic* skin_model;
		RwMatrix* skin_mat;
		union
		{
			struct
			{
				xModelTagWithNormal tag;
				xModelTag uptag;
			} v2n1;
			struct
			{
				xModelTag tag[3];
			} v3;
		};
	};

	struct hand_data
	{
		bool hurt_player;
		bool hit_platforms;
		xModelTag head_tag[4];
		xModelTag tail_tag[4];
		xEnt* ent;
		float32 radius;
	};

	struct platform_data
	{
		bool stopping;
		xEnt* ent;
		float32 radius;
		xMat3x3 mat;
		struct
		{
			xVec3 axis;
			float32 ang;
			float32 end_ang;
			float32 vel;
			float32 max_vel;
			float32 accel;
		} spin;
	};

	struct bound_data
	{
		xEnt ent;
		xMat4x3 mat;
		xMat3x3 rot_mat;
	};

	enum slug_stage
	{
		SLUG_INACTIVE,
		SLUG_AIM,
		SLUG_DELAY,
		SLUG_DYING,
		SLUG_FIRE
	};

	enum slug_enum
	{
		BEGIN_SLUG,
		SLUG_KAH = 0,
		SLUG_RAH,
		SLUG_TAY,
		MAX_SLUG
	};

	struct slug_data
	{
		slug_stage stage;
		bool spun;
		bool abandoned;
		float32 time;
		float32 stage_delay;
		xEnt* ent;
		platform_data* target;
		xMat4x3 mat;
		xMat4x3 dmat;
		xVec3 move_dir;
		float32 dist;
		float32 vel;
		float32 accel;
		float32 end_dist;
		float32 max_vel;
		float32 ydist;
		float32 yvel;
		float32 end_ydist;
		uint32 sound_handle;
	};

	struct move_config
	{
		float32 accel;
		float32 max_vel;
		float32 turn_accel;
		float32 turn_max_vel;
	};

	struct move_data : move_config
	{
		xVec2 dest;
		xVec2 dir;
		float32 vel;
		float32 yaw;
		float32 yaw_vel;
	};

	struct
	{
		bool face_player;
		bool face_follow;
		bool dizzy;
		move_enum move;
	    bool vulnerable;
	    bool cruise_exploding;
	    bool cruise_hit_body;
	    bool cruise_hit_target;
	    bool nodes_taken;
	    bool updated;
	} flag;
	int32 life;
	int32 round;
	int32 stage;
	float32 delay;
	float32 stage_delay;
	float32 player_damage_timer;
	uint32 old_player_health;
	hand_enum active_hand;
	zNPCBPlankton* plankton;
	zNPCNewsFish* newsfish;
	bool said_intro;
	xModelInstance* models[4];
	node_data nodes[9];
	hand_data hands[2];
	platform_data platforms[16];
	bound_data bounds[5];
	slug_data slugs[3];
	struct
	{
		xVec2 dir;
		float32 vel;
		float32 accel;
		float32 max_vel;
	} turn;
	move_data move;
	struct
	{
		float32 begin;
		float32 end;
		float32 time;
		float32 end_time;
	} ymove;
	struct
	{
		xVec3 body;
		xVec3 mouth;
		xVec3 hand[2];
	} sound_loc;
	float32 node_pulse;
	struct
	{
		xLightKit kit;
		xLightKitLight light[8];
	} glow_light;

public:
	zNPCB_SB2(int32 myType) WIP : zNPCBoss(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void ParseINI();
	virtual void Setup();
	virtual void SelfSetup();
	virtual void Reset();
	virtual void Destroy();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*);
	virtual void Process(xScene* xscn, float32 dt);
	virtual void NewTime(xScene* xscn, float32 dt);
	virtual void Render();
	virtual float32 AttackTimeLeft();
	virtual void HoldUpDude();
	virtual void ThanksImDone();

	void reset_speed();
	platform_data* player_platform();
	void activate_hand(hand_enum, bool);
	void deactivate_hand(hand_enum);
	bool player_on_ground() const;
	void emit_slug(slug_enum which);
	bool slugs_ready() const;
	bool slugs_inactive() const;
	void fire_slug(slug_enum which, platform_data& target);
	void abandon_slugs();
	int32 next_goal();
	void reset_stage();
	void set_vulnerable(bool);
	void decompose();
	void update_turn(float32 dt);
	void update_halt(float32 dt);
	void update_follow(float32 dt);
	void update_ymove(float32);
	void update_move(float32 dt);
	void update_camera(float32);
	void update_nodes(float32 dt);
	void init_nodes();
	void show_nodes();
	void move_nodes();
	void render_nodes();
	void bind_nodes();
	void rebind_nodes(RpAtomic* skin_model, RwMatrix* skin_mat);
	void setup_node_tags();
	void check_life();
	void ouchie();
	void update_round();
	xSurface& create_surface();
	void init_hands();
	void move_hand(hand_data& hand, float32 dt);
	void spin_platform(platform_data&, const xVec3&, float32, float32);
	void check_platform_smack(hand_data& hand);
	void update_platforms(float32 dt);
	void init_bounds();
	void reset_bounds();
	void update_bounds();
	void init_slugs();
	void update_aim_slug(slug_data& slug, float32 dt);
	void update_delay_slug(slug_data&, float32);
	void update_dying_slug(slug_data&, float32);
	void update_fire_slug(slug_data& slug, float32 dt);
	void slug_interp(float32 time, float32& scale);
	void update_slugs(float32 dt);
	void scan_cronies();
	void check_hit_fail();
	void create_glow_light();
	void destroy_glow_light();
	void set_glow_light_intensity(float32);
	void say(int32);
	void choose_hand() STUB_VOID;
	const xVec3& location() const STUB_REF(xVec3);
	void render_debug() {}
	const xVec3& get_home() const STUB_REF(xVec3);
	void set_location(const xVec2&) STUB_VOID;
	bool player_damaged() const STUB;
	bool turning() const STUB;
	void set_location(const xVec3&) STUB_VOID;
	const xVec3& start_location() const STUB_REF(xVec3);
	const xVec3& facing() const STUB_REF(xVec3);
	int32 platform_index(const platform_data&) const;
};

class zNPCGoalBossSB2Intro : public zNPCGoalCommon
{
private:
	zNPCB_SB2& owner;

public:
	zNPCGoalBossSB2Intro(int32 myType, zNPCB_SB2& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32, void*, xScene*);
};

class zNPCGoalBossSB2Idle : public zNPCGoalCommon
{
private:
	bool transitioning;
	zNPCB_SB2& owner;

public:
	zNPCGoalBossSB2Idle(int32 myType, zNPCB_SB2& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32, void*, xScene*);
};

class zNPCGoalBossSB2Taunt : public zNPCGoalCommon
{
private:
	zNPCB_SB2& owner;

public:
	zNPCGoalBossSB2Taunt(int32 myType, zNPCB_SB2& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void*, xScene*);
};

class zNPCGoalBossSB2Dizzy : public zNPCGoalCommon
{
private:
	bool sicked;
	zNPCB_SB2& owner;

public:
	zNPCGoalBossSB2Dizzy(int32 myType, zNPCB_SB2& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32, void*, xScene*);
};

class zNPCGoalBossSB2Hit : public zNPCGoalCommon
{
private:
	zNPCB_SB2& owner;

public:
	zNPCGoalBossSB2Hit(int32 myType, zNPCB_SB2& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void*, xScene*);
};

class zNPCGoalBossSB2Hunt : public zNPCGoalCommon
{
private:
	bool following;
	zNPCB_SB2& owner;

public:
	zNPCGoalBossSB2Hunt(int32 myType, zNPCB_SB2& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32, void*, xScene*);
};

class zNPCGoalBossSB2Swipe : public zNPCGoalCommon
{
private:
	bool started;
	bool holding;
	bool said;
	uint32 begin_anim;
	uint32 loop_anim;
	uint32 end_anim;
	zNPCB_SB2& owner;

public:
	zNPCGoalBossSB2Swipe(int32 myType, zNPCB_SB2& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);
	
	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void*, xScene*);

	bool can_start() const;
};

class zNPCGoalBossSB2Chop : public zNPCGoalCommon
{
private:
	bool started;
	bool targetted;
	uint32 begin_anim;
	uint32 loop_anim;
	uint32 end_anim;
	zNPCB_SB2& owner;

public:
	zNPCGoalBossSB2Chop(int32 myType, zNPCB_SB2& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void*, xScene*);

	bool can_start() const;
};

class zNPCGoalBossSB2Karate : public zNPCGoalCommon
{
private:
	bool emitted[3];
	bool started;
	zNPCB_SB2& owner;

public:
	zNPCGoalBossSB2Karate(int32 myType, zNPCB_SB2& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype);

	bool can_start() const;
};

class zNPCGoalBossSB2Death : public zNPCGoalCommon
{
private:
	zNPCB_SB2& owner;

public:
	zNPCGoalBossSB2Death(int32 myType, zNPCB_SB2& owner) WIP : zNPCGoalCommon(myType), owner(owner) {}

	static xFactoryInst* create(int32 who, RyzMemGrow* grow, void* info);

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype*, float32, void*, xScene*);
};

xAnimTable* ZNPC_AnimTable_BossSB2();