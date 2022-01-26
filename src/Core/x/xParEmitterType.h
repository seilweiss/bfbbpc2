#pragma once

#include "xMath3.h"

struct xPar;
struct xParEmitterAsset;
struct xVolume;
struct xEnt;
struct xParEmitter;

void xParEmitterEmitPoint(xPar* p, xParEmitterAsset* a, float32 dt);
void xParEmitterEmitCircleEdge(xPar* p, xParEmitterAsset* a, float32 dt);
void xParEmitterEmitCircle(xPar* p, xParEmitterAsset* a, float32 dt);
void xParEmitterEmitRect(xPar* p, xParEmitterAsset* a, float32 dt);
void xParEmitterEmitRectEdge(xPar* p, xParEmitterAsset* a, float32 dt);
void xParEmitterEmitLine(xPar* p, xParEmitterAsset* a, float32 dt);
void xParEmitterEmitSphere(xPar* p, xParEmitterAsset* a, float32 dt);
void xParEmitterEmitSphereEdge(xPar* p, xParEmitterAsset* a, float32 dt, int32 subtype);
void xParEmitterEmitVolume(xPar* p, xParEmitterAsset* a, float32 dt, xVolume* vol);
void xParEmitterEmitEntity(xPar* p, xParEmitterAsset* a, float32 dt, xEnt* ent);
void xParEmitterEmitOffsetPoint(xParEmitter* pe, xPar* p, xParEmitterAsset* a, float32, xEnt* ent);
void xParEmitterEmitVCylEdge(xPar* p, xParEmitterAsset* a, float32 dt);
void xParEmitterEmitOCircleEdge(xPar* p, xParEmitterAsset* a, float32 dt);
void xParEmitterEmitOCircle(xPar* p, xParEmitterAsset* a, float32 dt);
xMat4x3* xParEmitterTransformEntBone(xVec3& loc, xVec3& vel, const xParEmitterAsset& a, const xEnt& ent);
void xParEmitterTransformEntBone(xVec3& loc, xVec3& vel, const xParEmitterAsset& a, const xMat4x3& mat);
void xParEmitterEmitEntBone(xPar* p, xParEmitterAsset* a, float32 dt, const xMat4x3& mat);
void xParEmitterEmitEntBound(xPar* p, xParEmitterAsset* a, float32 dt, const xEnt* ent);
