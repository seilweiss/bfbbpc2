#include "xModel.h"

uint32 xModelGetPipeFlags(RpAtomic* model) STUB
void xModelInit() STUB_VOID
void xModelPoolInit(uint32 count, uint32 numMatrices) STUB_VOID
xModelInstance* xModelInstanceAlloc(RpAtomic* data, void* object, uint16 flags, uint8 boneIndex, uint8* boneRemap) STUB
static xModelInstance* FindChild(xModelInstance*) STUB
void xModelInstanceFree(xModelInstance* modelInst) STUB_VOID
void xModelInstanceAttach(xModelInstance* inst, xModelInstance* parent) STUB_VOID
void xModelInstanceUpgradeBrotherShared(xModelInstance* inst, uint32 flags) STUB_VOID
void xModelUpdate(xModelInstance* modelInst, float32 timeDelta) STUB_VOID
void xModelEvalSingle(xModelInstance* modelInst) STUB_VOID
void xModelEval(xModelInstance* modelInst) STUB_VOID
void xModelRenderSingle(xModelInstance* modelInst) STUB_VOID
void xModelRender(xModelInstance* modelInst) STUB_VOID
void xModelRender2D(const xModelInstance& model, const basic_rect<float32>& r, const xVec3& from, const xVec3& to) STUB_VOID
static RwCamera* CameraCreate(int32, int32, int32) STUB
static void CameraDestroy(RwCamera* camera) STUB_VOID
void xModelSetMaterialAlpha(xModelInstance* modelInst, uint8 alpha) STUB_VOID
void xModelMaterialMul(xModelInstance*, float32, float32, float32) STUB_VOID
void xModelResetMaterial(xModelInstance*) STUB_VOID
void xModel_SceneEnter(RpWorld* world) STUB_VOID
void xModel_SceneExit(RpWorld* world) STUB_VOID
void xModelAnimCollStart(xModelInstance& m) STUB_VOID
void xModelAnimCollRefresh(const xModelInstance& cm) STUB_VOID
xVec3 xModelGetBoneLocation(const xModelInstance& model, ulong32 index) STUB
void xModelGetBoneMat(xMat4x3& mat, const xModelInstance& model, ulong32 index) STUB_VOID