#include "xGrid.h"

void xGridBoundInit(xGridBound* gridb, void* data) STUB_VOID
void xGridInit(xGrid* grid, const xBox* bounds, uint16 nx, uint16 nz, uint8 ingrid_id) STUB_VOID
void xGridKill(xGrid* grid) STUB_VOID
void xGridEmpty(xGrid* grid) STUB_VOID
bool32 xGridAddToCell(xGridBound**, xGridBound*) STUB
static bool32 xGridAdd(xGrid*, xGridBound*, int32, int32) STUB
bool32 xGridAdd(xGrid* grid, xEnt* ent) STUB
bool32 xGridRemove(xGridBound* gridb) STUB
void xGridUpdate(xGrid* grid, xEnt* ent) STUB_VOID
static xGridBound** xGridGetCell(xGrid* grid, const xEnt* ent, int32& grx, int32& grz) STUB
void xGridGetCell(xGrid* grid, float32 posx, float32, float32 posz, int32& grx, int32& grz) STUB_VOID
xGridBound* xGridIterFirstCell(xGrid* grid, float32 posx, float32, float32 posz, int32& grx, int32& grz, xGridIterator& it) STUB
bool32 xGridEntIsTooBig(xGrid* grid, const xEnt* ent) STUB
void xGridCheckPosition(xGrid* grid, xVec3* pos, xQCData* qcd, xGridCheckPositionCallback hitCB, void* cbdata) STUB_VOID