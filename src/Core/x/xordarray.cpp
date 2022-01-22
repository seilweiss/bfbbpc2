#include "xordarray.h"

void XOrdInit(st_XORDEREDARRAY* array, int32 size, bool32 tempAlloc) STUB_VOID
void XOrdReset(st_XORDEREDARRAY* array) STUB_VOID
void XOrdDone(st_XORDEREDARRAY* array, bool32 wasTempAlloc) STUB_VOID
void XOrdAppend(st_XORDEREDARRAY* array, void* elt) STUB_VOID
void XOrdInsert(st_XORDEREDARRAY* array, void* elt, XOrdCompareCallback compare) STUB_VOID
void* XOrdRemove(st_XORDEREDARRAY* array, void* elt, int32 index) STUB
int32 XOrdLookup(st_XORDEREDARRAY* array, const void* key, XOrdTestCallback test) STUB
void XOrdSort(st_XORDEREDARRAY* array, XOrdCompareCallback test) STUB_VOID