#pragma once

#include "xGrid.h"

struct zScene;

extern xGrid colls_grid;
extern xGrid colls_oso_grid;

void zGridReset(zScene* s);
void zGridInit(zScene* s);
void zGridExit(zScene*);
void zGridUpdateEnt(xEnt* ent);