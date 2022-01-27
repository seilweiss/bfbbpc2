#include "xEntBoulder.h"

void xEntBoulder_FitToModel(xEntBoulder*) STUB_VOID
void xEntBoulder_Render(xEnt* ent) STUB_VOID
void xEntBoulder_Init(void* ent, void* asset) STUB_VOID
void xEntBoulder_Init(xEntBoulder* ent, xEntAsset* asset) STUB_VOID
void xEntBoulder_ApplyForces(xEntCollis* collis) STUB_VOID
void xEntBoulder_AddInstantForce(xEntBoulder*, xVec3*) STUB_VOID
void xEntBoulder_AddForce(xEntBoulder* ent, xVec3* force) STUB_VOID
void xEntBoulder_BUpdate(xEnt*, xVec3*) {}
void xEntBoulder_RealBUpdate(xEnt* ent, xVec3* pos) STUB_VOID
void xEntBoulder_Update(xEntBoulder* ent, xScene* sc, float32 dt) STUB_VOID
bool32 xEntBoulder_KilledBySurface(xEntBoulder* ent, xScene*, float32) STUB
void xEntBoulder_Kill(xEntBoulder* ent) STUB_VOID
void xEntBoulder_BubbleBowl(float32 multiplier) STUB_VOID
void xEntBoulder_Setup(xEntBoulder* ent) STUB_VOID
void xEntBoulder_Reset(xEntBoulder* ent, xScene*) STUB_VOID
bool32 xEntBoulderEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB
static void RecurseLinks(xLinkAsset*, int32, xEntBoulder**) STUB_VOID
static void RecurseChild(xBase* child, xEntBoulder** boulList, int32& currBoul) STUB_VOID
void xBoulderGenerator_Init(xBase& data, xDynAsset& asset, ulong32) STUB_VOID
void xBoulderGenerator_Init(xBoulderGenerator* bg, xBoulderGeneratorAsset* asset) STUB_VOID
void xBoulderGenerator_Reset(xBoulderGenerator*) STUB_VOID
static void BoulderGen_GiveBirth(xBoulderGenerator*, int32) STUB_VOID
static int32 GetBoulderForGenerating(xBoulderGenerator* bg) STUB
void xBoulderGenerator_Launch(xBoulderGenerator* bg, xVec3* pnt, float32 t) STUB_VOID
bool32 xBoulderGenerator_EventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB
void xBoulderGenerator_GenBoulder(xBoulderGenerator* bg) STUB_VOID