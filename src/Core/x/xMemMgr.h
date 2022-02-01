#pragma once

#include <types.h>

struct xMemPool;

typedef void(*xMemPoolInitCallback)(xMemPool*, void*);

struct xMemPool
{
	void* FreeList;
	uint16 NextOffset;
	uint16 Flags;
	void* UsedList;
	xMemPoolInitCallback InitCB;
	void* Buffer;
	uint16 Size;
	uint16 NumRealloc;
	uint32 Total;
};

#define XMEMPOOL_UNK0x1 0x1

typedef struct xHeapState_tag
{
	uint32 curr;
	uint16 blk_ct;
	uint16 pad;
	uint32 used;
	uint32 wasted;
} xHeapState;

typedef struct xMemBlock_tag
{
	uint32 addr;
	uint32 size;
	int32 align;
} xMemBlock;

typedef struct xMemHeap_tag
{
	uint32 flags;
	uint32 hard_base;
	uint32 size;
	int16 opp_heap[2];
	xHeapState state[12];
	uint16 state_idx;
	uint16 max_blks;
	xMemBlock* blk;
	xMemBlock* lastblk;
} xMemHeap;

typedef void(*xMemBaseNotifyCallback)();

extern uint32 gActiveHeap;

void xMemDebug_SoakLog(const char*);
void xMemInit();
void xMemExit();
void xMemInitHeap(xMemHeap* heap, uint32 base, uint32 size, uint32 flags);
void* xMemGrowAlloc(uint32 heapID, uint32 size);
void* xMemAlloc(uint32 heapID, uint32 size, int32 align);
void* xMemPushTemp(uint32 size);
void xMemPopTemp(void* addr);
int32 xMemPushBase(uint32);
int32 xMemPushBase();
int32 xMemPopBase(uint32, int32 depth);
int32 xMemPopBase(int32 depth);
int32 xMemGetBase(uint32);
void xMemRegisterBaseNotifyFunc(xMemBaseNotifyCallback func);
int32 xMemGetBase();
void xMemPoolAddElements(xMemPool* pool, void* buffer, uint32 count);
void xMemPoolSetup(xMemPool* pool, void* buffer, uint32 nextOffset, uint32 flags, xMemPoolInitCallback initCB, uint32 size, uint32 count, uint32 numRealloc);
void* xMemPoolAlloc(xMemPool* pool);
void xMemPoolFree(xMemPool* pool, void* data);

#define xMEMALLOC(size) xMemAlloc(gActiveHeap, (size), 0)
#define xMEMGROWALLOC(size) xMemGrowAlloc(gActiveHeap, (size))