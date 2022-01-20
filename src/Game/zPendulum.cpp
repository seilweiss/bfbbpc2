#include "zPendulum.h"

void zPendulum_Init(void* pend, void* asset) STUB_VOID
void zPendulum_Init(zPendulum* pend, xEntAsset* asset) STUB_VOID
void zPendulum_Save(zPendulum* pend, xSerial* s) STUB_VOID
void zPendulum_Load(zPendulum* pend, xSerial* s) STUB_VOID
void zPendulum_Setup(zPendulum* pend, xScene*) STUB_VOID
void zPendulum_Reset(zPendulum* pend, xScene* sc) STUB_VOID
void zPendulum_Update(zPendulum* pend, xScene* sc, float32 dt) STUB_VOID
void zPendulum_Move(zPendulum* pend, xScene* s, float32 dt, xEntFrame* frame) STUB_VOID
static void zPendulumTranslate(xEnt* xent, xVec3* dpos, xMat4x3* dmat) STUB_VOID
bool32 zPendulumEventCB(xBase*, xBase* to, uint32 toEvent, const float32* toParam, xBase* toParamWidget) STUB