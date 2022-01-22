#pragma once

#include <types.h>

struct st_XORDEREDARRAY
{
	void** list;
	int32 cnt;
	int32 max;
	int32 warnlvl;
};

typedef int32(*XOrdCompareCallback)(void*, void*);
typedef bool32(*XOrdTestCallback)(const void*, void*);

void XOrdInit(st_XORDEREDARRAY* array, int32 size, bool32 tempAlloc);
void XOrdReset(st_XORDEREDARRAY* array);
void XOrdDone(st_XORDEREDARRAY* array, bool32 wasTempAlloc);
void XOrdAppend(st_XORDEREDARRAY* array, void* elt);
void XOrdInsert(st_XORDEREDARRAY* array, void* elt, XOrdCompareCallback compare);
void* XOrdRemove(st_XORDEREDARRAY* array, void* elt, int32 index);
int32 XOrdLookup(st_XORDEREDARRAY* array, const void* key, XOrdTestCallback test);
void XOrdSort(st_XORDEREDARRAY* array, XOrdCompareCallback test);