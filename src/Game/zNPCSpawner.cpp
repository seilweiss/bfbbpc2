#include "zNPCSpawner.h"

void zNPCSpawner_Startup() {}
void zNPCSpawner_Shutdown() {}
void zNPCSpawner_ScenePrepare() STUB_VOID
void zNPCSpawner_SceneFinish() STUB_VOID
zNPCSpawner* zNPCSpawner_GetInstance() STUB

void zNPCSpawner::Subscribe(zNPCCommon* owner) STUB_VOID
void zNPCSpawner::SetWaveMode(en_SM_WAVE_MODE mode, float32 delay, int32 lifemax) STUB_VOID
bool32 zNPCSpawner::AddSpawnPoint(zMovePoint* sp) STUB
bool32 zNPCSpawner::AddSpawnNPC(zNPCCommon* npc) STUB
void zNPCSpawner::Reset() STUB_VOID
void zNPCSpawner::MapPreferred() STUB_VOID
void zNPCSpawner::Timestep(float32 dt) STUB_VOID
void zNPCSpawner::UpdateDiscreet(float32) STUB_VOID
void zNPCSpawner::UpdateContinuous(float32) STUB_VOID
void zNPCSpawner::Notify(en_SM_NOTICES note, void* data) STUB_VOID
bool zNPCSpawner::Owned(zNPCCommon*) const STUB
bool zNPCSpawner::Receivable(en_SM_NOTICES note, void* data) const STUB
SMSPStatus* zNPCSpawner::SelectSP(const SMNPCStatus* npcstat) STUB
SMSPStatus* zNPCSpawner::NextPendingNPC(int32) STUB
void zNPCSpawner::ClearActive() STUB_VOID
void zNPCSpawner::ClearPending() STUB_VOID
int32 zNPCSpawner::FillPending() STUB
int32 zNPCSpawner::ReFillPending() STUB
bool32 zNPCSpawner::IsSPLZClear(zMovePoint* sp) STUB
int32 zNPCSpawner::IsNearbyMover(xBound* bnd, int32 usecyl, xCollis* caller_colrec) STUB
void zNPCSpawner::SetNPCStatus(zNPCCommon*, en_SM_NPC_STATUS) STUB_VOID
SMSPStatus* zNPCSpawner::StatForSP(zMovePoint*, int32) STUB
SMNPCStatus* zNPCSpawner::StatForNPC(zNPCCommon* npc) STUB
bool32 zNPCSpawner::SpawnBeastie(SMNPCStatus* npcstat, SMSPStatus* spstat) STUB
SMNPCStatus* zNPCSpawner::ToastedBeastie(zNPCCommon*) STUB
void zNPCSpawner::ChildHeartbeat(float32) {}
void zNPCSpawner::ChildCleanup(float32) STUB_VOID