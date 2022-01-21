#pragma once

#include "xSurface.h"

struct xCollis;
struct xScene;

void zSurfaceInit();
void zSurfaceRegisterMapper(uint32 assetId);
void zSurfaceExit();
void zSurfaceResetSurface(xSurface*);
xSurface* zSurfaceGetSurface(uint32 mat_id);
xSurface* zSurfaceGetSurface(const xCollis* coll);
uint32 zSurfaceGetSlide(const xSurface* surf);
uint32 zSurfaceGetStep(const xSurface* surf);
bool zSurfaceOutOfBounds(const xSurface& s);
float32 zSurfaceGetSlideStartAngle(const xSurface* surf);
float32 zSurfaceGetSlideStopAngle(const xSurface* surf);
uint32 zSurfaceGetMatchOrient(const xSurface* surf);
int32 zSurfaceGetDamageType(const xSurface* surf);
uint32 zSurfaceGetDamagePassthrough(const xSurface* surf);
uint32 zSurfaceGetSticky(const xSurface* surf);
uint32 zSurfaceGetStandOn(const xSurface* surf);
float32 zSurfaceGetFriction(const xSurface* surf);
float32 zSurfaceGetOutOfBoundsDelay(const xSurface& s);
int32 zSurfaceGetSlickness(const xSurface* surf);
float32 zSurfaceGetDamping(const xSurface* surf, float32 min_vel);
void zSurfaceSave(xSurface* ent, xSerial* s);
void zSurfaceLoad(xSurface* ent, xSerial* s);
void zSurfaceSetup(xSurface* s);
void zSurfaceUpdate(xBase* to, xScene*, float32 dt);
void zSurfaceGetName(int32 type, char* buffer);
xSurface& zSurfaceGetDefault();