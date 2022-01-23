#pragma once

#include "zNPCTypeCommon.h"
#include "zTaskBox.h"
#include "zNPCSupport.h"
#include "xEntDrive.h"
#include "zNPCMessenger.h"

struct zPlatform;
struct xShadowCache;

class HiThere : public ztaskbox::callback
{
private:
	zNPCCommon* npc;

public:
	HiThere() WIP : ztaskbox::callback() {}

	virtual void on_talk_start() STUB_VOID;
	virtual void on_talk_stop() STUB_VOID;
};

class zNPCVillager : public zNPCCommon
{
private:
	HiThere hithere;
	ztaskbox* converse;
	int32 current_talk_anim;

public:
	zNPCVillager(int32 myType) WIP : zNPCCommon(myType) {}

	virtual uint8 ColChkFlags() const;
	virtual uint8 ColPenFlags() const;
	virtual uint8 PhysicsFlags() const;
	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void ParseINI();

	void ParseNonRandTalk();

	virtual void Process(xScene* xscn, float32 dt);

	void ChkCheatSize();

	virtual void CollideReview();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal*);
	virtual bool32 NPCMessage(NPCMsg* mail);
	virtual bool32 FolkHandleMail(NPCMsg* mail);
	virtual void SpeakBegin();
	virtual void SpeakEnd();
	virtual void SpeakStart(uint32 sndid, uint32, int32 anim);
	virtual void SpeakStop();
	virtual float32 GenShadCacheRad() WIP { return 1.5f; }
	virtual uint8 ColChkByFlags() const WIP { return 0x18; }
	virtual uint8 ColPenByFlags() const WIP { return 0x18; }
	
	bool32 PlayerIsStaring();
	void AddTalking(xPsyche* psy, xGoalProcessCallback eval_plyrnear, xGoalProcessCallback eval_talking, xGoalProcessCallback eval_chatter, xGoalProcessCallback eval_speak);
	void FindMyConverse();
	void TossMyConverse();
};

class zNPCFish : public zNPCVillager
{
private:
	NPCTarget tgt_robonear;
	float32 tmr_robonear;
	float32 tmr_checkagain;
	xEntDrive raw_drvdata;

public:
	zNPCFish(int32 myType) WIP : zNPCVillager(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void ParseINI();

	void FishSoundTables();

	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void Process(xScene* xscn, float32 dt);
	virtual bool32 FolkHandleMail(NPCMsg* msg);
	virtual xEntDrive* PRIV_GetDriverData() STUB;

	void MonitorCowering(xScene*, float32);
	void CheckDoChat();
};

class zNPCMerManChair : public zNPCVillager
{
private:
	int32 flg_mermanchair;

public:
	zNPCMerManChair(int32 myType) WIP : zNPCVillager(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void SelfSetup();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual void Process(xScene*, float32 dt);
	virtual uint8 ColChkFlags() const WIP { return 0; }
	virtual uint8 ColPenFlags() const WIP { return 0; }
	virtual uint8 PhysicsFlags() const WIP { return 0; }
};

class zNPCNewsFish : public zNPCVillager
{
private:
	struct say_data
	{
		int32 total;
		int32 prev_total;
	};

	enum say_enum
	{
		INVALID_SAY = -1,
		SAY_B101_01 = 0,
		SAY_B101_02,
		SAY_B101_03,
		SAY_B101_04,
		SAY_B101_05,
		SAY_B101_06,
		SAY_B101_07,
		SAY_B101_08,
		SAY_B101_09,
		SAY_B101_10,
		SAY_B101_11,
		SAY_B101_12,
		SAY_B101_13,
		SAY_B101_14,
		SAY_B101_15,
		SAY_B101_16,
		SAY_B201_01,
		SAY_B201_02,
		SAY_B201_03,
		SAY_B201_04,
		SAY_B201_05,
		SAY_B201_06,
		SAY_B201_07,
		SAY_B303_INTRO_1,
		SAY_B303_INTRO_2,
		SAY_B303_FUSE_NEAR,
		SAY_B303_FUSE_HIT,
		SAY_B303_BRAIN_HELP_1,
		SAY_B303_BRAIN_HELP_2,
		SAY_B303_BRAIN_HELP_3,
		SAY_HIT_PLAYER_1,
		SAY_HIT_PLAYER_2,
		SAY_HIT_PLAYER_3,
		SAY_HIT_PLAYER_4,
		SAY_HIT_PLAYER_5,
		SAY_HIT_PLAYER_6,
		SAY_BOWL_HIT_1,
		SAY_BOWL_HIT_2,
		SAY_BOWL_HIT_3,
		SAY_BOWL_HIT_4,
		SAY_BOWL_HIT_5,
		SAY_BOWL_HELP,
		SAY_HIT_BOSS_1,
		SAY_HIT_BOSS_2,
		SAY_SANDY_SPLIT,
		SAY_SANDY_FLY,
		SAY_SB_VICTORY,
		SAY_SB_ROUGH_RIDE,
		SAY_SB_BACK,
		SAY_SB_HIT_FAIL_1,
		SAY_SB_HIT_FAIL_2,
		SAY_SB_HIT_BOSS_1,
		SAY_SB_HIT_BOSS_2,
		SAY_SB_HIT_BOSS_3,
		SAY_SB_VULN_1,
		SAY_SB_VULN_2,
		SAY_SB_VULN_3,
		SAY_SB_VULN_4,
		SAY_SB_VULN_5,
		SAY_ROBOT_TACTICS,
		SAY_ROBOT_HIT_FAIL,
		SAY_ROBOT_DIZZY,
		SAY_ROBOT_STUN_1,
		SAY_ROBOT_STUN_2,
		SAY_ROBOT_STUN_3,
		SAY_ROBOT_HIT,
		SAY_ROBOT_VULN_1,
		SAY_ROBOT_VULN_2,
		SAY_SPIN,
		SAY_B302_INTRO,
		SAY_HIT_LAST,
		MAX_SAY
	};

	say_data said[71];
	bool was_reset;
	uint32 soundHandle;
	uint32 currSoundID;
	uint32 nextSoundID;
	float32 jawTime;
	void* jawData;
	uint32 newsfishFlags;
	xVec2 onScreenCoords;
	xVec2 offScreenCoords;
	xVec2 screenCoords;
	float32 screenSize;
	float32 screenRot;
	float32 appearSpeed;
	float32 disappearSpeed;
	float32 screenLerp;

public:
	zNPCNewsFish(int32 myType) WIP : zNPCVillager(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void PostSetup();
	virtual void Process(xScene*, float32 dt);
	virtual void Reset();
	virtual void SelfSetup() {}
	virtual void SpeakStart(uint32 sndid, uint32 sndhandle);
	virtual void SpeakStop();

	bool32 IsTalking();
	void TalkOnScreen(bool32 talkOnScreen);

	virtual void Render();

	bool say(say_enum s, int32 flags);
	bool32 say(const say_enum* s, ulong32 size, int32 flags, int32 max_say);
	void reset_said();
	say_data* get_said(say_enum) STUB;
};

class zNPCNewsFishTV : public zNPCVillager
{
public:
	zNPCNewsFishTV(int32 myType) WIP : zNPCVillager(myType) {}

	uint8 ColChkFlags() const WIP { return 0; }
	uint8 ColPenFlags() const WIP { return 0; }
	uint8 ColChkByFlags() const WIP { return 0; }
	uint8 ColPenByFlags() const WIP { return 0; }
	uint8 PhysicsFlags() const WIP { return 0; }
};

class zNPCSandyBikini : public zNPCVillager
{
private:
	float32 tmr_leakCycle;

public:
	zNPCSandyBikini(int32 myType) WIP : zNPCVillager(myType) {}

	virtual void Reset();
	virtual void Process(xScene* xscn, float32 dt);

	void VFXLeakyFaucet(float32 dt);
};

enum en_BBOY_PLATANIM
{
	BBOY_PLATANIM_MOVE,
	BBOY_PLATANIM_HIT,
	BBOY_PLATANIM_NOMORE,
	BBOY_PLATANIM_FORCE = FORCEENUMSIZEINT
};

class zNPCBalloonBoy : public zNPCFish
{
private:
	int32 specialBalloon;
	zPlatform* plat_balloons;
	xShadowCache* shadCache;

public:
	zNPCBalloonBoy(int32 myType) WIP : zNPCFish(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Reset();
	virtual void SelfSetup();
	virtual void Render();

	void PlatShadRend();
	void AddBallooning(xPsyche*);

	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT gspot, xGoal* rawgoal);
	virtual bool32 FolkHandleMail(NPCMsg* mail);

	bool32 ParseSysEvent(NPCSysEvent* sed);
	void PlatAnimSet(en_BBOY_PLATANIM platanim);
	void PlatAnimSync();
	bool32 IAmBallooning();
};

class zNPCBubbleBuddy : public zNPCFish
{
public:
	zNPCBubbleBuddy(int32 myType) WIP : zNPCFish(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Setup();
	virtual void Reset();
	virtual void Render() STUB_VOID;
	virtual void RenderExtra();
};

void ZNPC_Villager_Startup();
void ZNPC_Villager_Shutdown();
void zNPCVillager_ScenePrepare();
void zNPCVillager_SceneFinish();
void zNPCVillager_SceneReset();
void zNPCVillager_ScenePostInit();
void zNPCVillager_SceneTimestep(xScene*, float32 dt);
xFactoryInst* ZNPC_Create_Villager(int32 who, RyzMemGrow* growCtxt, void*);
void ZNPC_Destroy_Villager(xFactoryInst* inst);
xAnimTable* ZNPC_AnimTable_Villager();
xAnimTable* ZNPC_AnimTable_Villager(xAnimTable* callerTable);
xAnimTable* ZNPC_AnimTable_BalloonBoy();
xAnimTable* ZNPC_AnimTable_BalloonBoy(xAnimTable* callerTable);
xAnimTable* ZNPC_AnimTable_SuperFriend();
xAnimTable* ZNPC_AnimTable_SuperFriend(xAnimTable* callerTable);
void zNPCBubbleBuddy_AlphaUpdate(float32);
RpAtomic* NPC_BubBud_RenderCB(RpAtomic* atomic);
void FOLK_InitEffects();
void FOLK_KillEffects();