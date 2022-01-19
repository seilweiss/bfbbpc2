#pragma once

#include <types.h>

struct xAnimTable;

void zAnimListInit();
void zAnimListExit();
xAnimTable* zAnimListGetTable(uint32 id);
int32 zAnimListGetNumUsed(uint32 id);