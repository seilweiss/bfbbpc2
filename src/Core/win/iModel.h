#pragma once

#include "xMath3.h"

#include <rwcore.h>
#include <rpworld.h>

struct xModelTag;
struct xModelTagWithNormal;

void iModelInit();
RpAtomic* iModelFileNew(void* buffer, uint32 size);
void iModelUnload(RpAtomic* userdata);
RpAtomic* iModelFile_RWMultiAtomic(RpAtomic* model);
uint32 iModelNumBones(RpAtomic* model);
void iModelQuatToMat(xQuat*, xVec3*, RwMatrix*);
void iModelAnimMatrices(RpAtomic* model, xQuat* quat, xVec3* tran, RwMatrix* mat);
void iModelRender(RpAtomic* model, RwMatrix* mat);
bool32 iModelCull(RpAtomic* model, RwMatrix* mat);
bool32 iModelSphereCull(xSphere* sphere);
bool32 iModelCullPlusShadow(RpAtomic* model, RwMatrix* mat, xVec3* shadowVec, bool32* shadowOutside);
uint32 iModelVertCount(RpAtomic* model);
uint32 iModelVertEval(RpAtomic* model, uint32 index, uint32 count, RwMatrix* mat, xVec3* vert, xVec3* dest);
uint32 iModelNormalEval(xVec3* out, const RpAtomic& m, const RwMatrix* mat, ulong32 index, int32 size, const xVec3* in);
uint32 iModelTagSetup(xModelTag* tag, RpAtomic* model, float32 x, float32 y, float32 z);
uint32 iModelTagSetup(xModelTagWithNormal* tag, RpAtomic* model, float32 x, float32 y, float32 z);
void iModelTagEval(RpAtomic* model, const xModelTag* tag, RwMatrix* mat, xVec3* dest);
void iModelTagEval(RpAtomic* model, const xModelTagWithNormal* tag, RwMatrix* mat, xVec3* dest, xVec3* normal);
void iModelSetMaterialAlpha(RpAtomic* model, uint8 alpha);
void iModelResetMaterial(RpAtomic* model);
void iModelSetMaterialTexture(RpAtomic* model, void* texture);
void iModelMaterialMul(RpAtomic* model, float32 rm, float32 gm, float32 bm);