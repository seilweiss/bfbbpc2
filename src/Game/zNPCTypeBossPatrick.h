#pragma once

#include "zNPCTypeBoss.h"
#include "zNPCGoalCommon.h"
#include "zPortal.h"
#include "xParEmitter.h"
#include "xCamera.h"

struct zPlatform;
struct zParEmitter;
struct zCutsceneMgr;
class zNPCNewsFish;
struct zEntPickup;
struct zScene;

class zNPCBPatrick : public zNPCBoss
{
private:
	struct bossPatGlob
	{
		xParabola path;
		float32 t;
		xVec3 lastPos;
		xVec3 norm;
		xVec3 convVel;
		zPlatform* conv;
		uint32 flags;
	};

	struct bossPatBox
	{
		xEnt* box;
		float32 velocity;
		float32 pos;
		float32 minY;
		uint32 flags;
	};

	struct bossPatShard
	{
		xVec3 rotVec;
		float32 ang;
		float32 size;
		float32 maxSize;
	};

	uint32 bossFlags;
	int32 hitPoints;
	int32 round;
	float32 gooHeight;
	int32 gooLevel;
	int32 notSwingingLastFrame;
	xEnt* gooObj;
	RpAtomic* spitModel;
	RpAtomic* splatModel;
	xVec3 arenaExtent;
	xVec3 fudgePos;
	xVec3 fudgeFace;
	int32 numTasks;
	int32 currTask;
	int32 task[20];
	bossPatGlob glob[50];
	int32 currGlob;
	float32 splatTimer;
	xEnt** boundList;
	uint32 chuckFlags[3];
	zNPCCommon* chuckList[3];
	zMovePoint* chuckMovePoint[3];
	xParEmitterCustomSettings freezeBreathSetting;
	zParEmitter* freezeBreathEmitter;
	xPar* parList[4];
	xPar* lastEmitted;
	int32 numParticles;
	float32 particleTimer;
	float32 frozenTimer;
	xAnimState* animState;
	xAnimTransitionList* animTranList;
	xEnt* fudgeHandle;
	zParEmitter* fudgeEmitter;
	zParEmitter* steamEmitter;
	bossPatBox box[3][8];
	bossPatBox backBox;
	zShrapnelAsset* boxBreak;
	zShrapnelAsset* boxSplash;
	float32 boxLandSndTimer;
	float32 boxSplashSndTimer;
	xEnt* swinger[8];
	int32 currSwinger;
	float32 origSwingerHeight;
	float32 swingTimer;
	xModelInstance* frozenSB;
	xModelInstance* frozenSBIce;
	RpAtomic* shardModel;
	bossPatShard shard[10];
	float32 iceScale;
	float32 shakeAmp;
	float32 shakePhase;
	zShrapnelAsset* iceBreak;
	RwRaster* iceWaveRaster;
	zCutsceneMgr* round1Csn;
	zCutsceneMgr* round2Csn;
	zCutsceneMgr* round3Csn;
	float32 csnTimer;
	zPortal* safeGroundPortal;
	zNPCNewsFish* newsfish;
	uint32 nfFlags;
	float32 badHitTimer;
	int32 numPCHitsInARow;
	int32 numMissesInARow;
	int32 firstTimeR1Csn;
	int32 firstUpdate;
	zEntPickup* underwear[2];
	zPlatform* conveyorBelt[7];
	xBinaryCamera bossCam;

public:
	zNPCBPatrick(int32 myType) WIP : zNPCBoss(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Setup();
	virtual void SelfSetup();
	virtual void Reset();
	virtual void Destroy();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal* rawgoal);
	virtual void Process(xScene* xscn, float32 dt);
	virtual void DuploNotice(en_SM_NOTICES note, void* data);
	virtual void Damage(en_NPC_DAMAGE_TYPE dmg_type, xBase*, const xVec3* vec_hit);

	void RenderGlobs();
	void RenderFrozenPlayer();

	virtual void RenderExtra();
	virtual void NewTime(xScene* xscn, float32 dt);

	int32 nextGoal();
	bossPatGlob* getNextFreeGlob();
	void playSplat(xVec3* pos);
	uint32 canSpawnChucks();
	void gotoRound(int32 num);
	void hiddenByCutscene();
	float32 ConveyorTimeLeft(zPlatform*, xVec3*);
	void ParabolaHitsConveyors(xParabola* path, xCollis* colls);
	void bossPatBoxCheckCollide(bossPatBox*);
	void bossPatBoxUpdate(bossPatBox* bx, float32 dt);
};

class zNPCGoalBossPatIdle : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;

public:
	zNPCGoalBossPatIdle(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossPatTaunt : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;

public:
	zNPCGoalBossPatTaunt(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossPatHit : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;

public:
	zNPCGoalBossPatHit(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 Exit(float32, void*);
};

class zNPCGoalBossPatSpit : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 timeLeftToSpit;

public:
	zNPCGoalBossPatSpit(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossPatRun : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	uint32 runSndID;

public:
	zNPCGoalBossPatRun(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 Exit(float32, void*);
};

class zNPCGoalBossPatSmack : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 globNum;

public:
	zNPCGoalBossPatSmack(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossPatFreeze : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 freezeSlope;

public:
	zNPCGoalBossPatFreeze(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossPatSpawn : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;

public:
	zNPCGoalBossPatSpawn(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossPatSpin : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 numGlobs;
	xVec3 vel;
	xVec3 pole[4];
	int32 currPole;
	uint32 spinSndID;
	uint32 globSndID;

public:
	zNPCGoalBossPatSpin(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 Exit(float32, void*);
};

class zNPCGoalBossPatFudge : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 lerp;
	float32 globNum;
	uint32 vomitSndID;

public:
	zNPCGoalBossPatFudge(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

xAnimTable* ZNPC_AnimTable_BossPatrick();
void zNPCBPatrick_AddBoundEntsToGrid(zScene*);
void zNPCBPatrick_GameIsPaused(zScene*);