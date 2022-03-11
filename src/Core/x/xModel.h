#pragma once

#include "iModel.h"
#include "xMath2.h"

struct xModelPool;
struct xAnimPlay;
struct xSurface;
struct xModelBucket;
struct xLightKit;

struct xModelInstance
{
	xModelInstance* Next;
	xModelInstance* Parent;
	xModelPool* Pool;
	xAnimPlay* Anim;
	RpAtomic* Data;
	uint32 PipeFlags;
	float32 RedMultiplier;
	float32 GreenMultiplier;
	float32 BlueMultiplier;
	float32 Alpha;
	float32 FadeStart;
	float32 FadeEnd;
	xSurface* Surf;
	xModelBucket** Bucket;
	xModelInstance* BucketNext;
	xLightKit* LightKit;
	void* Object;
	uint16 Flags;
	uint8 BoneCount;
	uint8 BoneIndex;
	uint8* BoneRemap;
	RwMatrix* Mat;
	xVec3 Scale;
	uint32 modelID;
	uint32 shadowID;
	RpAtomic* shadowmapAtomic;
	struct
	{
		xVec3* verts;
	} anim_coll;
};

#define XMODELINSTANCE_UNK0x4 0x4
#define XMODELINSTANCE_UNK0x80 0x80
#define XMODELINSTANCE_UNK0x100 0x100
#define XMODELINSTANCE_UNK0x800 0x800
#define XMODELINSTANCE_UNK0x1000 0x1000

struct xModelPool
{
	xModelPool* Next;
	uint32 NumMatrices;
	xModelInstance* List;
};

struct xModelTag
{
	xVec3 v;
	uint32 matidx;
	float32 wt[4];
};

struct xModelTagWithNormal : xModelTag
{
	xVec3 normal;
};

struct xModelAssetParam
{
	uint32 HashID;
	uint8 WordLength;
	uint8 String[3];
};

extern RpMorphTarget anim_coll_old_mt;

uint32 xModelGetPipeFlags(RpAtomic* model);
void xModelInit();
void xModelPoolInit(uint32 count, uint32 numMatrices);
xModelInstance* xModelInstanceAlloc(RpAtomic* data, void* object, uint16 flags, uint8 boneIndex, uint8* boneRemap);
void xModelInstanceFree(xModelInstance* modelInst);
void xModelInstanceAttach(xModelInstance* inst, xModelInstance* parent);
void xModelInstanceUpgradeBrotherShared(xModelInstance* inst, uint32 flags);
void xModelUpdate(xModelInstance* modelInst, float32 timeDelta);
void xModelEvalSingle(xModelInstance* modelInst);
void xModelEval(xModelInstance* modelInst);
void xModelRenderSingle(xModelInstance* modelInst);
void xModelRender(xModelInstance* modelInst);
void xModelRender2D(const xModelInstance& model, const basic_rect<float32>&r, const xVec3& from, const xVec3& to);
void xModelSetMaterialAlpha(xModelInstance* modelInst, uint8 alpha);
void xModelMaterialMul(xModelInstance*, float32, float32, float32);
void xModelResetMaterial(xModelInstance*);
void xModel_SceneEnter(RpWorld* world);
void xModel_SceneExit(RpWorld* world);
void xModelAnimCollStart(xModelInstance& m);
void xModelAnimCollRefresh(const xModelInstance& cm);
xVec3 xModelGetBoneLocation(const xModelInstance& model, ulong32 index);
void xModelGetBoneMat(xMat4x3& mat, const xModelInstance& model, ulong32 index);

inline void xModelSetScale(xModelInstance*, const xVec3&) STUB_VOID
inline xMat4x3* xModelGetFrame(xModelInstance*) STUB
inline void xModelSetFrame(xModelInstance*, const xMat4x3*) STUB_VOID
inline xSphere* xModelGetLocalSBound(xModelInstance*) STUB

inline bool xModelAnimCollDirty(const xModelInstance& m)
{
	return (m.Flags & (XMODELINSTANCE_UNK0x800 | XMODELINSTANCE_UNK0x1000)) == XMODELINSTANCE_UNK0x800;
}

inline void xModelAnimCollApply(const xModelInstance& m)
{
	if (xModelAnimCollDirty(m))
	{
		xModelAnimCollRefresh(m);
	}

	anim_coll_old_mt.verts = m.Data->geometry->morphTarget->verts;
	m.Data->geometry->morphTarget->verts = (RwV3d*)m.anim_coll.verts;
}

inline void xModelAnimCollRestore(const xModelInstance& m)
{
	m.Data->geometry->morphTarget->verts = anim_coll_old_mt.verts;
}

inline void xModelAnimCollStop(xModelInstance& m) STUB_VOID