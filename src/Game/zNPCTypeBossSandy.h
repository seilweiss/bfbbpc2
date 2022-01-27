#pragma once

#include "zNPCTypeBoss.h"
#include "xParEmitter.h"
#include "zLightning.h"
#include "xFX.h"
#include "xCamera.h"

struct zParEmitter;
struct xEntBoulder;
struct zCutsceneMgr;
class zNPCNewsFish;
struct zEntPickup;
struct zScene;

class zNPCBSandy : public zNPCBoss
{
private:
	xEnt** boundList;
	uint32* boundFlags;
	float32* boundEmitTimer;
	uint32 bossFlags;
	xVec3 currDir;
	float32 currVel;
	int32 hitPoints;
	int32 round;
	xVec3 ringCorner[8];
	xVec3 ringEdgeCenter[8];
	xVec3 ropeNormal[8];
	xVec3 bouncePoint[8];
	xEnt* ropeObject[4][8];
	xEnt* ropeObjectLo[8];
	xEnt* ropeSb;
	xEnt* ropeSbDamaged;
	xEnt* turnbuckle[8];
	float32 edgeAlpha[8];
	float32 scoreboardAlpha;
	int32 fromRope;
	int32 toRope;
	float32 limbLength;
	RwRaster* helmetRaster;
	RwRaster* feetRaster;
	RwRaster* targetRaster;
	RwIm3DVertex iconVert[4];
	xVec3 targetPos;
	xQuat qHead;
	xQuat qBoulder;
	xVec3 pHead;
	xVec3 pBoulder;
	float32 magnetizeTime;
	xVec3 shockPos;
	xParEmitterCustomSettings dustEddieSetting;
	zParEmitter* dustEddieEmitter;
	zParEmitter* shockwaveEmitter;
	xEnt* hangingScoreboard;
	xEnt* bustedScoreboard;
	xEnt* crashedScoreboard;
	xEntBoulder* headBoulder;
	zShrapnelAsset* scoreboardShrap;
	zShrapnelAsset* sboardSecondShrap;
	zShrapnelAsset* sboardThirdShrap;
	zShrapnelAsset* lightRigShrap;
	xEnt* lightRig[4];
	zCutsceneMgr* round1Csn;
	zCutsceneMgr* round2Csn;
	zCutsceneMgr* round3Csn;
	float32 csnTimer;
	LightningAdd sparks[6];
	zLightning* wireLight[2];
	xVec3 endPoints[2][4];
	xMat4x3 sparkTransform[2][2];
	float32 timeToNextBolt[2];
	float32 maxLightningWait[2];
	uint32 springSndID;
	uint32 ambientSndID;
	float32 jawTime;
	float32 jawLevel;
	float32 jawThreshold;
	void* jawData;
	int32 isBeat;
	xVec3 laserPoint[16];
	xFXRibbon laserShow;
	xFXRibbon::curve_node curveNode[2];
	float32 curveNodeAlpha;
	float32 curveNodeR;
	float32 curveNodeG;
	float32 curveNodeB;
	zNPCNewsFish* newsfish;
	uint32 nfFlags;
	float32 shockRadius;
	float32 shockwaveGrowthRate;
	float32 shockwaveMaxRadius;
	float32 edropTurnMinTime;
	float32 edropShockwaveTime;
	int32 firstTimeR1Csn;
	int32 firstUpdate;
	zEntPickup* underwear[3];
	xBinaryCamera bossCam;
	xBinaryCamera specialBossCam;

public:
	zNPCBSandy(int32 myType) WIP : zNPCBoss(myType) {}

	virtual void Init(xEntAsset* asset);
	virtual void Setup();
	virtual void SelfSetup();
	virtual void Reset();
	virtual void ParseINI();
	virtual uint32 AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal* rawgoal);
	virtual void Render();

	void CalcMagnetizeInfo();
	void InitFX();
	void UpdateFX(float32 dt);
	
	virtual void Process(xScene* xscn, float32 dt);

	void hiddenByCutscene();

	virtual void Damage(en_NPC_DAMAGE_TYPE damtype, xBase*, const xVec3*);
	virtual void NewTime(xScene* xscn, float32 dt);
};

class zNPCGoalBossSandyIdle : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSandyIdle(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 Exit(float32, void*);
};

class zNPCGoalBossSandyTaunt : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSandyTaunt(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossSandyChase : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSandyChase(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 Exit(float32, void*);
};

class zNPCGoalBossSandyMelee : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSandyMelee(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Exit(float32, void*);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossSandyNoHead : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 secsSincePatWasCarryingHead;

public:
	zNPCGoalBossSandyNoHead(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossSandyElbowDrop : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 elbowFlags;

public:
	zNPCGoalBossSandyElbowDrop(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 Exit(float32, void*);
};

class zNPCGoalBossSandyLeap : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	float32 startX;
	float32 startZ;
	float32 endX;
	float32 endZ;

public:
	zNPCGoalBossSandyLeap(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 Exit(float32, void*);

	const char* Name() WIP { return NULL; }
};

class zNPCGoalBossSandySit : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	float32 totalTime;
	uint32 sitFlags;

public:
	zNPCGoalBossSandySit(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 Exit(float32, void*);
};

class zNPCGoalBossSandyGetUp : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSandyGetUp(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

class zNPCGoalBossSandyRunToRope : public zNPCGoalCommon
{
private:
	float32 timeInGoal;

public:
	zNPCGoalBossSandyRunToRope(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
	virtual bool32 Exit(float32, void*);
};

class zNPCGoalBossSandyClothesline : public zNPCGoalCommon
{
private:
	float32 timeInGoal;
	uint32 stage;
	uint32 playedAnimEarly;
	float32 totalHoverTime;
	xVec3 bounceStartPoint;

public:
	zNPCGoalBossSandyClothesline(int32 myType) WIP : zNPCGoalCommon(myType) {}

	virtual bool32 Enter(float32 dt, void* updCtxt);
	virtual bool32 Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn);
};

xAnimTable* ZNPC_AnimTable_BossSandy();
xAnimTable* ZNPC_AnimTable_BossSandyHead();
xAnimTable* ZNPC_AnimTable_BossSandyScoreboard();
void zNPCBSandy_AddBoundEntsToGrid(zScene*);
void zNPCBSandy_GameIsPaused(zScene*);