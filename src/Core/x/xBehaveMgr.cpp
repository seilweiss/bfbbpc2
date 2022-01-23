#include "xBehaveMgr.h"

void xBehaveMgr_Startup() STUB_VOID
void xBehaveMgr_Shutdown() STUB_VOID
xBehaveMgr* xBehaveMgr_GetSelf() STUB
xFactory* xBehaveMgr_GoalFactory() STUB
void xBehaveMgr_ScenePrepare() STUB_VOID
void xBehaveMgr_SceneFinish() STUB_VOID
void xBehaveMgr_SceneReset() STUB_VOID

void xBehaveMgr::Startup(int32, int32) STUB_VOID
void xBehaveMgr::RegBuiltIn() STUB_VOID
xPsyche* xBehaveMgr::Subscribe(xBase* owner, int32) STUB
void xBehaveMgr::UnSubscribe(xPsyche* psy) STUB_VOID
void xBehaveMgr::ScenePrepare() {}
void xBehaveMgr::SceneFinish() STUB_VOID
void xBehaveMgr::SceneReset() STUB_VOID

void xPsyche::BrainBegin() STUB_VOID
void xPsyche::BrainExtend() STUB_VOID
void xPsyche::BrainEnd() STUB_VOID
xGoal* xPsyche::AddGoal(int32 gid, void* createData) STUB
void xPsyche::FreshWipe() STUB_VOID
void xPsyche::SetOwner(xBase*, void*) STUB_VOID
void xPsyche::KillBrain(xFactory*) STUB_VOID
void xPsyche::Lobotomy(xFactory*) STUB_VOID
void xPsyche::Amnesia(bool32) STUB_VOID
int32 xPsyche::IndexInStack(int32 gid) const STUB
xGoal* xPsyche::GetCurGoal() const STUB
xGoal* xPsyche::GIDInStack(int32 gid) const STUB
int32 xPsyche::GIDOfActive() const STUB
int32 xPsyche::GIDOfPending() const STUB
xGoal* xPsyche::GetPrevRecovery(int32 gid) const STUB
bool32 xPsyche::xGoalSet(int32 gid, int32) STUB
bool32 xPsyche::GoalPush(int32 gid, int32) STUB
bool32 xPsyche::GoalPopToBase(int32 overpend) STUB
bool32 xPsyche::GoalPopRecover(int32 overpend) STUB
bool32 xPsyche::GoalPop(int32 gid_popto, int32) STUB
bool32 xPsyche::GoalSwap(int32 gid, int32) STUB
bool32 xPsyche::GoalNone(int32 denyExplicit, int32) STUB
void xPsyche::SetTopState(en_GOALSTATE) STUB_VOID
xGoal* xPsyche::FindGoal(int32 gid) STUB
void xPsyche::ForceTran(float32, void*) STUB_VOID
bool32 xPsyche::Timestep(float32 dt, void* updCtxt) STUB
bool32 xPsyche::ParseTranRequest(en_trantype trantyp, int32 trangid) STUB
int32 xPsyche::TranGoal(float32 dt, void* updCtxt) STUB
float32 xPsyche::TimerGet(en_xpsytime tymr) STUB
void xPsyche::TimerClear() STUB_VOID
void xPsyche::TimerUpdate(float32) STUB_VOID