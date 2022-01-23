#include "xBehaveGoalSimple.h"

void xGoalSimple_RegisterTypes(xFactory* fac) STUB_VOID
static xFactoryInst* GOALCreate_Generic(int32 who, RyzMemGrow* growCtxt, void*) STUB
static void GOALDestroy_Generic(xFactoryInst* item) STUB_VOID

bool32 xGoalGeneric::Enter(float32 dt, void* updCtxt) STUB
bool32 xGoalGeneric::Exit(float32 dt, void* updCtxt) STUB
bool32 xGoalGeneric::Suspend(float32 dt, void* updCtxt) STUB
bool32 xGoalGeneric::Resume(float32 dt, void* updCtxt) STUB
bool32 xGoalGeneric::SysEvent(xBase* from, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget, bool32* handled) STUB