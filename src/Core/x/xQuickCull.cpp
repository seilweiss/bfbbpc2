#include "xQuickCull.h"

void xQuickCullInit(xQCControl* ctrl, float32 xmin, float32 ymin, float32 zmin, float32 xmax, float32 ymax, float32 zmax) STUB_VOID
void xQuickCullInit(xQCControl* ctrl, const xBox* box) STUB_VOID
bool32 xQuickCullIsects(const xQCData* a, const xQCData* b) STUB
void xQuickCullForBound(xQCControl* ctrl, xQCData* q, const xBound* b) STUB_VOID
static void xQuickCullCellForVec(xQCControl* ctrl, xQCData* c, const xVec3* v) STUB_VOID
static void xQuickCullCellMerge(xQCData*, const xQCData*, const xQCData*) STUB_VOID
void xQuickCullForLine(xQCControl* ctrl, xQCData* q, const xLine3* ln) STUB_VOID
void xQuickCullForRay(xQCControl* ctrl, xQCData* q, const xRay3* r) STUB_VOID
void xQuickCullForSphere(xQCControl* ctrl, xQCData* q, const xSphere* s) STUB_VOID
void xQuickCullForBox(xQCControl* ctrl, xQCData* q, const xBox* box) STUB_VOID
void xQuickCullForOBB(xQCControl* ctrl, xQCData* q, const xBox* b, const xMat4x3* m) STUB_VOID
void xQuickCullForEverything(xQCData* q) STUB_VOID