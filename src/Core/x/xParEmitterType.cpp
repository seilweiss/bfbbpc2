#include "xParEmitterType.h"

#include "xParEmitter.h"
#include "xBound.h"

namespace {

	inline void ocircle_emit(xPar&, xParEmitterAsset&, float32, float32) STUB_VOID;
	inline void transform_ent_bone(xVec3&, xVec3&, const xParEmitterAsset&, const xMat4x3&) STUB_VOID;
	inline void get_random_offset(const xPEEntBone&, const xMat4x3&) STUB_VOID;
	inline void get_random_offset(const xBound&, float32, uint32) STUB_VOID;

}

void xParEmitterEmitPoint(xPar* p, xParEmitterAsset* a, float32 dt) STUB_VOID
static void xParEmitterAngleVariation(xPar* p, xParEmitterAsset* a) STUB_VOID
void xParEmitterEmitCircleEdge(xPar* p, xParEmitterAsset* a, float32 dt) STUB_VOID
void xParEmitterEmitCircle(xPar* p, xParEmitterAsset* a, float32 dt) STUB_VOID
void xParEmitterEmitRect(xPar* p, xParEmitterAsset* a, float32 dt) STUB_VOID
void xParEmitterEmitRectEdge(xPar* p, xParEmitterAsset* a, float32 dt) STUB_VOID
void xParEmitterEmitLine(xPar* p, xParEmitterAsset* a, float32 dt) STUB_VOID
void xParEmitterEmitSphere(xPar* p, xParEmitterAsset* a, float32 dt) STUB_VOID
void xParEmitterEmitSphereEdge(xPar* p, xParEmitterAsset* a, float32 dt, int32 subtype) STUB_VOID
void xParEmitterEmitVolume(xPar* p, xParEmitterAsset* a, float32 dt, xVolume* vol) STUB_VOID
void xParEmitterEmitEntity(xPar* p, xParEmitterAsset* a, float32 dt, xEnt* ent) STUB_VOID
void xParEmitterEmitOffsetPoint(xParEmitter* pe, xPar* p, xParEmitterAsset* a, float32, xEnt* ent) STUB_VOID
void xParEmitterEmitVCylEdge(xPar* p, xParEmitterAsset* a, float32 dt) STUB_VOID
void xParEmitterEmitOCircleEdge(xPar* p, xParEmitterAsset* a, float32 dt) STUB_VOID
void xParEmitterEmitOCircle(xPar* p, xParEmitterAsset* a, float32 dt) STUB_VOID
xMat4x3* xParEmitterTransformEntBone(xVec3& loc, xVec3& vel, const xParEmitterAsset& a, const xEnt& ent) STUB
void xParEmitterTransformEntBone(xVec3& loc, xVec3& vel, const xParEmitterAsset& a, const xMat4x3& mat) STUB_VOID
void xParEmitterEmitEntBone(xPar* p, xParEmitterAsset* a, float32 dt, const xMat4x3& mat) STUB_VOID
void xParEmitterEmitEntBound(xPar* p, xParEmitterAsset* a, float32 dt, const xEnt* ent) STUB_VOID