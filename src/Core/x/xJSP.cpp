#include "xJSP.h"

static RpAtomic* CountAtomicCB(RpAtomic*, void*) STUB
static RpMesh* AddMeshCB(RpMesh*, RpMeshHeader*, void*) STUB
static RpAtomic* AddAtomicCB(RpAtomic*, void*) STUB
static RpAtomic* AddAtomicPrecalcedVertCB(RpAtomic*, void*) STUB
static RpAtomic* ListAtomicCB(RpAtomic* atomic, void* data) STUB
void xJSP_MultiStreamRead(void* data, uint32 size, xJSPHeader** jsp) STUB_VOID
void xJSP_Destroy(xJSPHeader* jsp) STUB_VOID