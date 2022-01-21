#include "iModel.h"

#include "xModel.h"

#include <rphanim.h>

static inline void SkinXform(xVec3*, const xVec3*, RwMatrix*, const RwMatrix*, const float32*, const uint32*, uint32) STUB_VOID
static inline void SkinNormals(xVec3*, const xVec3*, const RwMatrix*, const RwMatrix*, const float32*, const uint32*, uint32) STUB_VOID

namespace {

	inline void U8_COLOR_CLAMP(uint8&, float32) STUB_VOID;

}

static RwFrame* GetChildFrameHierarchy(RwFrame* frame, void* data) STUB
static RpHAnimHierarchy* GetHierarchy(RpAtomic*) STUB
void iModelInit() STUB_VOID
static RpAtomic* FindAndInstanceAtomicCallback(RpAtomic*, void*) STUB
static RpAtomic* iModelStreamRead(RwStream* stream) STUB
RpAtomic* iModelFileNew(void* buffer, uint32 size) STUB
void iModelUnload(RpAtomic* userdata) STUB_VOID
static RpAtomic* NextAtomicCallback(RpAtomic* atomic, void* data) STUB
RpAtomic* iModelFile_RWMultiAtomic(RpAtomic* model) STUB
uint32 iModelNumBones(RpAtomic* model) STUB
void iModelQuatToMat(xQuat*, xVec3*, RwMatrix*) STUB_VOID
void iModelAnimMatrices(RpAtomic* model, xQuat* quat, xVec3* tran, RwMatrix* mat) STUB_VOID
static void iModelCacheAtomic(RpAtomic*) {}
void iModelRender(RpAtomic* model, RwMatrix* mat) STUB_VOID
bool32 iModelCull(RpAtomic* model, RwMatrix* mat) STUB
bool32 iModelSphereCull(xSphere* sphere) STUB
bool32 iModelCullPlusShadow(RpAtomic* model, RwMatrix* mat, xVec3* shadowVec, bool32* shadowOutside) STUB
uint32 iModelVertCount(RpAtomic* model) STUB
uint32 iModelVertEval(RpAtomic* model, uint32 index, uint32 count, RwMatrix* mat, xVec3* vert, xVec3* dest) STUB
uint32 iModelNormalEval(xVec3* out, const RpAtomic& m, const RwMatrix* mat, ulong32 index, int32 size, const xVec3* in) STUB
static uint32 iModelTagUserData(xModelTag* tag, RpAtomic* model, float32 x, float32 y, float32 z, int32 closeV) STUB
static uint32 iModelTagInternal(xModelTag* tag, RpAtomic* model, float32 x, float32 y, float32 z, int32 closeV) STUB
uint32 iModelTagSetup(xModelTag* tag, RpAtomic* model, float32 x, float32 y, float32 z) STUB
uint32 iModelTagSetup(xModelTagWithNormal* tag, RpAtomic* model, float32 x, float32 y, float32 z) STUB
void iModelTagEval(RpAtomic* model, const xModelTag* tag, RwMatrix* mat, xVec3* dest) STUB_VOID
void iModelTagEval(RpAtomic* model, const xModelTagWithNormal* tag, RwMatrix* mat, xVec3* dest, xVec3* normal) STUB_VOID
static RpMaterial* iModelSetMaterialAlphaCB(RpMaterial*, void*) STUB
void iModelSetMaterialAlpha(RpAtomic* model, uint8 alpha) STUB_VOID
static RpMaterial* iModelResetMaterialCB(RpMaterial*, void*) STUB
void iModelResetMaterial(RpAtomic* model) STUB_VOID
static RpMaterial* iModelSetMaterialTextureCB(RpMaterial* material, void* data) STUB
void iModelSetMaterialTexture(RpAtomic* model, void* texture) STUB_VOID
static RpMaterial* iModelMaterialMulCB(RpMaterial* material, void* data) STUB
void iModelMaterialMul(RpAtomic* model, float32 rm, float32 gm, float32 bm) STUB_VOID