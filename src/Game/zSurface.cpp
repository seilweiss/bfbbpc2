#include "zSurface.h"

void zSurfaceInit() STUB_VOID
static void zSurfaceInitDefaultSurface() STUB_VOID
void zSurfaceRegisterMapper(uint32 assetId) STUB_VOID
void zSurfaceExit() STUB_VOID
void zSurfaceResetSurface(xSurface*) STUB_VOID
xSurface* zSurfaceGetSurface(uint32 mat_id) STUB
xSurface* zSurfaceGetSurface(const xCollis* coll) STUB
uint32 zSurfaceGetSlide(const xSurface* surf) STUB
uint32 zSurfaceGetStep(const xSurface* surf) STUB
bool zSurfaceOutOfBounds(const xSurface& s) STUB
float32 zSurfaceGetSlideStartAngle(const xSurface* surf) STUB
float32 zSurfaceGetSlideStopAngle(const xSurface* surf) STUB
uint32 zSurfaceGetMatchOrient(const xSurface* surf) STUB
int32 zSurfaceGetDamageType(const xSurface* surf) STUB
uint32 zSurfaceGetDamagePassthrough(const xSurface* surf) STUB
uint32 zSurfaceGetSticky(const xSurface* surf) STUB
uint32 zSurfaceGetStandOn(const xSurface* surf) STUB
float32 zSurfaceGetFriction(const xSurface* surf) STUB
float32 zSurfaceGetOutOfBoundsDelay(const xSurface& s) STUB
int32 zSurfaceGetSlickness(const xSurface* surf) STUB
float32 zSurfaceGetDamping(const xSurface* surf, float32 min_vel) STUB
void zSurfaceSave(xSurface* ent, xSerial* s) STUB_VOID
void zSurfaceLoad(xSurface* ent, xSerial* s) STUB_VOID
void zSurfaceSetup(xSurface* s) STUB_VOID
void zSurfaceUpdate(xBase* to, xScene*, float32 dt) STUB_VOID
static bool32 zSurfaceEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB
void zSurfaceGetName(int32 type, char* buffer) STUB_VOID
xSurface& zSurfaceGetDefault() STUB_REF(xSurface)