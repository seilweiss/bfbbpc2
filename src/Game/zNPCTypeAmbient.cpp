#include "zNPCTypeAmbient.h"

void ZNPC_Ambient_Startup() STUB_VOID
void ZNPC_Ambient_Shutdown() STUB_VOID
xFactoryInst* ZNPC_Create_Ambient(int32 who, RyzMemGrow* grow, void*) STUB
void ZNPC_Destroy_Ambient(xFactoryInst* inst) STUB_VOID
xAnimTable* ZNPC_AnimTable_Ambient() STUB
xAnimTable* ZNPC_AnimTable_Jelly() STUB
xAnimTable* ZNPC_AnimTable_Neptune() STUB

void zNPCAmbient::Init(xEntAsset* asset) STUB_VOID
void zNPCAmbient::Reset() STUB_VOID
void zNPCAmbient::Process(xScene* xscn, float32 dt) STUB_VOID
void zNPCAmbient::SelfSetup() STUB_VOID
uint32 zNPCAmbient::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*) STUB
bool32 zNPCAmbient::NPCMessage(NPCMsg* mail) STUB

void zNPCJelly::Init(xEntAsset* asset) STUB_VOID
void zNPCJelly::ParseINI() STUB_VOID
void zNPCJelly::Reset() STUB_VOID
void zNPCJelly::SelfSetup() STUB_VOID
void zNPCJelly::JellySpawn(const xVec3* pos_spawn, float32 tym_fall) STUB_VOID
void zNPCJelly::JellyKill() STUB_VOID
uint32 zNPCJelly::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*) STUB
void zNPCJelly::BUpdate(xVec3*) STUB_VOID
void zNPCJelly::Process(xScene* xscn, float32 dt) STUB_VOID
bool32 zNPCJelly::AmbiHandleMail(NPCMsg* mail) STUB
void zNPCJelly::PlayWithAlpha(float32) STUB_VOID
void zNPCJelly::SetAlpha(float32 alf) STUB_VOID
void zNPCJelly::PlayWithAnimSpd() STUB_VOID
void zNPCJelly::PumpFaster() STUB_VOID
void zNPCJelly::JellyBoneWorldPos(xVec3* pos, int32 idx_request) const STUB_VOID
void zNPCJelly::PlayWithLightnin() STUB_VOID

static bool32 JELY_grul_getAngry(xGoal* rawgoal, void*, en_trantype* trantype, float32, void*) STUB

void zNPCJelly::ActLikeOctopus() STUB_VOID

uint32 zNPCNeptune::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*) STUB
void zNPCNeptune::ParseINI() STUB_VOID
void zNPCNeptune::Reset() STUB_VOID
void zNPCNeptune::Process(xScene* xscn, float32 dt) STUB_VOID

uint32 zNPCMimeFish::AnimPick(int32 gid, en_NPC_GOAL_SPOT, xGoal*) STUB
void zNPCMimeFish::Reset() STUB_VOID
void zNPCMimeFish::Process(xScene*, float32) STUB_VOID