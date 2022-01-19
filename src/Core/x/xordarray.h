#pragma once

#include <types.h>

typedef struct st_XORDEREDARRAY
{
	void** list;
	int32 cnt;
	int32 max;
	int32 warnlvl;
} XORDEREDARRAY;

typedef int32(*XOrdCompareCallback)(void*, void*);
typedef bool32(*XOrdTestCallback)(const void*, void*);

void XOrdInit(XORDEREDARRAY* array, int32 size, bool32 tempAlloc);
void XOrdReset(XORDEREDARRAY* array);
void XOrdDone(XORDEREDARRAY* array, bool32 wasTempAlloc);
void XOrdAppend(XORDEREDARRAY* array, void* elt);
void XOrdInsert(XORDEREDARRAY* array, void* elt, XOrdCompareCallback compare);
void* XOrdRemove(XORDEREDARRAY* array, void* elt, int32 index);
int32 XOrdLookup(XORDEREDARRAY* array, const void* key, XOrdTestCallback test);
void XOrdSort(XORDEREDARRAY* array, XOrdCompareCallback test);