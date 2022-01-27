#pragma once

#include "xGrid.h"

struct zScene;

void zGridReset(zScene* s);
void zGridInit(zScene* s);
void zGridExit(zScene*);
void zGridUpdateEnt(xEnt* ent);