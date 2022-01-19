#include "xCutscene.h"

struct xCutsceneAnimHdr
{
	uint32 RootIndex;
	float32 Translate[3];
};

struct CutsceneShadowModel
{
	RpAtomic* model;
	RwMatrix* animMat;
	uint32 shadowBits;
};

void xCutscene_Init(void* toc) STUB_VOID
xCutscene* xCutscene_Create(uint32 id) STUB
bool32 xCutscene_Destroy(xCutscene* csn) STUB
bool32 xCutscene_LoadStart(xCutscene* csn) STUB
static float32 xCutsceneConvertBreak(float32, xCutsceneBreak*, uint32, int32) STUB
bool32 xCutscene_Update(xCutscene* csn, float32 dt) STUB
void xCutscene_SetSpeed(xCutscene* csn, float32 speed) STUB_VOID
void xCutscene_SetCamera(xCutscene* csn, xCamera* cam) STUB_VOID
static void xcsCalcAnimMatrices(RwMatrix* animMat, RpAtomic* model, xCutsceneAnimHdr* ahdr, float32 time, uint32 tworoot) STUB_VOID
static void JDeltaEval(RpAtomic* model, void* deltaModel, void* deltaAnim, float32 time) STUB_VOID
static void CutsceneShadowRender(CutsceneShadowModel* smod) STUB_VOID
void xCutscene_Render(xCutscene* csn, xEnt**, int32*, float32*) STUB_VOID

inline xCutscene* xCutscene_CurrentCutscene() STUB