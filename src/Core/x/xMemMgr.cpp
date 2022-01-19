#include "xMemMgr.h"

typedef struct xMemBlkInfo_tag
{
	xMemBlock* header;
	uint32 pre;
	uint32 block;
	uint32 post;
	uint32 curr;
	uint32 waste;
	uint32 total;
} xMemBlkInfo;

uint32 gActiveHeap = 0;

void xMemDebug_SoakLog(const char*) STUB_VOID
void xMemInit() STUB_VOID
void xMemExit() STUB_VOID
void xMemInitHeap(xMemHeap* heap, uint32 base, uint32 size, uint32 flags) STUB_VOID
static uint32 xMemGetBlockInfo(xMemHeap* heap, uint32 size, int32 align, xMemBlkInfo* info) STUB
void* xMemGrowAlloc(uint32 heapID, uint32 size) STUB
void* xMemAlloc(uint32 heapID, uint32 size, int32 align) STUB
void* xMemPushTemp(uint32 size) STUB
void xMemPopTemp(void* addr) STUB_VOID
int32 xMemPushBase(uint32) STUB
int32 xMemPushBase() STUB
int32 xMemPopBase(uint32, int32 depth) STUB
int32 xMemPopBase(int32 depth) STUB
int32 xMemGetBase(uint32) STUB
void xMemRegisterBaseNotifyFunc(xMemBaseNotifyCallback func) STUB_VOID
int32 xMemGetBase() STUB
void xMemPoolAddElements(xMemPool* pool, void* buffer, uint32 count) STUB_VOID
void xMemPoolSetup(xMemPool* pool, void* buffer, uint32 nextOffset, uint32 flags, xMemPoolInitCallback initCB, uint32 size, uint32 count, uint32 numRealloc) STUB_VOID
void* xMemPoolAlloc(xMemPool* pool) STUB
void xMemPoolFree(xMemPool* pool, void* data) STUB_VOID