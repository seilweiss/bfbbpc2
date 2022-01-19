#include "xordarray.h"

void XOrdInit(XORDEREDARRAY* array, int32 size, bool32 tempAlloc) STUB_VOID
void XOrdReset(XORDEREDARRAY* array) STUB_VOID
void XOrdDone(XORDEREDARRAY* array, bool32 wasTempAlloc) STUB_VOID
void XOrdAppend(XORDEREDARRAY* array, void* elt) STUB_VOID
void XOrdInsert(XORDEREDARRAY* array, void* elt, XOrdCompareCallback compare) STUB_VOID
void* XOrdRemove(XORDEREDARRAY* array, void* elt, int32 index) STUB
int32 XOrdLookup(XORDEREDARRAY* array, const void* key, XOrdTestCallback test) STUB
void XOrdSort(XORDEREDARRAY* array, XOrdCompareCallback test) STUB_VOID