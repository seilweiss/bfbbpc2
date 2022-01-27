#pragma once

#include "xRMemData.h"
#include "xordarray.h"

class zMovePoint;
class zNPCCommon;
struct xBound;
struct xCollis;

enum en_SM_NOTICES
{
	SM_NOTE_NPCDIED,
	SM_NOTE_NPCSTANDBY,
	SM_NOTE_NPCALIVE,
	SM_NOTE_DUPPAUSE,
	SM_NOTE_DUPRESUME,
	SM_NOTE_DUPSETDELAY,
	SM_NOTE_DUPDEAD,
	SM_NOTE_KILLKIDS,
	SM_NOTE_NOMORE,
	SM_NOTE_FORCE = FORCEENUMSIZEINT
};

enum en_SM_WAVE_MODE
{
	SM_WAVE_CONTINUOUS,
	SM_WAVE_DISCREET,
	SM_WAVE_NOMORE,
	SM_WAVE_FORCE = FORCEENUMSIZEINT
};

enum en_SM_WAVE_STAT
{
	SM_STAT_BEGIN,
	SM_STAT_INPROG,
	SM_STAT_ABORT,
	SM_STAT_MARKTIME,
	SM_STAT_DONE,
	SM_STAT_NOMORE,
	SM_STAT_FORCE = FORCEENUMSIZEINT
};

enum en_SM_NPC_STATUS
{
	SM_NPC_DEAD,
	SM_NPC_READY,
	SM_NPC_PENDING,
	SM_NPC_SPAWNED,
	SM_NPC_ACTIVE,
	SM_NPC_NOMORE,
	SM_NPC_FORCE = FORCEENUMSIZEINT
};

struct SMSPStatus
{
	zMovePoint* sp;
	int32 flg_stat;
	zNPCCommon* npc_prefer;
};

struct SMNPCStatus
{
	zNPCCommon* npc;
	en_SM_NPC_STATUS status;
	zMovePoint* sp_prefer;
};

class zNPCSpawner : public RyzMemData
{
private:
	int32 flg_spawner;
	zNPCCommon* npc_owner;
	float32 tym_delay;
	int32 max_spawn;
	en_SM_WAVE_MODE wavemode;
	en_SM_WAVE_STAT wavestat;
	float32 tmr_wave;
	int32 cnt_spawn;
	SMSPStatus sppool[16];
	SMNPCStatus npcpool[16];
	st_XORDEREDARRAY pendlist;
	st_XORDEREDARRAY actvlist;
	int32 cnt_cleanup;

public:
	void Subscribe(zNPCCommon* owner);
	void SetWaveMode(en_SM_WAVE_MODE mode, float32 delay, int32 lifemax);
	bool32 AddSpawnPoint(zMovePoint* sp);
	bool32 AddSpawnNPC(zNPCCommon* npc);
	void Reset();
	void MapPreferred();
	void Timestep(float32 dt);
	void UpdateDiscreet(float32);
	void UpdateContinuous(float32);
	void Notify(en_SM_NOTICES note, void* data);
	bool Owned(zNPCCommon*) const;
	bool Receivable(en_SM_NOTICES note, void* data) const;
	SMSPStatus* SelectSP(const SMNPCStatus* npcstat);
	SMSPStatus* NextPendingNPC(int32);
	void ClearActive();
	void ClearPending();
	int32 FillPending();
	int32 ReFillPending();
	bool32 IsSPLZClear(zMovePoint* sp);
	int32 IsNearbyMover(xBound* bnd, int32 usecyl, xCollis* caller_colrec);
	void SetNPCStatus(zNPCCommon*, en_SM_NPC_STATUS);
	SMSPStatus* StatForSP(zMovePoint*, int32);
	SMNPCStatus* StatForNPC(zNPCCommon* npc);
	bool32 SpawnBeastie(SMNPCStatus* npcstat, SMSPStatus* spstat);
	SMNPCStatus* ToastedBeastie(zNPCCommon*);
	void ChildHeartbeat(float32);
	void ChildCleanup(float32);
};

void zNPCSpawner_Startup();
void zNPCSpawner_Shutdown();
void zNPCSpawner_ScenePrepare();
void zNPCSpawner_SceneFinish();
zNPCSpawner* zNPCSpawner_GetInstance();