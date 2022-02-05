#pragma once

#include "zGlobals.h"

extern zGlobals globals;
extern xGlobals* xglobals;

void zMainShowProgressBar();
void zMainFirstScreen(int32 mode);
void zMainMemCardSpaceQuery();
void zMainMemCardRenderText(const char*, bool);