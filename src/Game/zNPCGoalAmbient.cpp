#include "zNPCGoalAmbient.h"

xFactoryInst* GOALCreate_Ambient(int32 who, RyzMemGrow* grow, void*) STUB

bool32 zNPCGoalJellyBumped::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalJellyBumped::Exit(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalJellyBumped::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalJellyBumped::MoveSwoosh(float32) STUB_VOID
void zNPCGoalJellyBumped::PlayWithAnimSpd() STUB_VOID
void zNPCGoalJellyBumped::StreakPrep() STUB_VOID
void zNPCGoalJellyBumped::StreakDone() STUB_VOID
void zNPCGoalJellyBumped::StreakUpdate() STUB_VOID
void zNPCGoalJellyBumped::ExtractAimDir(xVec3* dir_aim) STUB_VOID
float32 zNPCGoalJellyBumped::CalcEndPoint(xVec3* pos_end, const xVec3* dir_aim) STUB

bool32 zNPCGoalJellyAttack::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalJellyAttack::Exit(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalJellyAttack::Process(en_trantype* trantype, float32 dt, void* updCtxt, xScene* xscn) STUB
void zNPCGoalJellyAttack::ZapperStart() STUB_VOID
void zNPCGoalJellyAttack::ZapperStop() STUB_VOID
void zNPCGoalJellyAttack::ZapperUpdate() STUB_VOID

bool32 zNPCGoalJellyBirth::Enter(float32 dt, void* updCtxt) STUB
bool32 zNPCGoalJellyBirth::Process(en_trantype* trantyp, float32 dt, void* ctxt, xScene* xscn) STUB
void zNPCGoalJellyBirth::BirthInfoSet(const xVec3* pos_birth, float32 tym_fall) STUB_VOID