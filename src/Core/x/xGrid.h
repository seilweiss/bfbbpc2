#pragma once

#include "xMath.h"
#include "xBound.h"

struct xEnt;

struct xGridBound
{
	void* data;
	uint16 gx;
	uint16 gz;
	uint8 ingrid;
	uint8 oversize;
	uint8 deleted;
	uint8 gpad;
	xGridBound** head;
	xGridBound* next;
};

struct xGrid
{
	uint8 ingrid_id;
	uint8 pad[3];
	uint16 nx;
	uint16 nz;
	float32 minx;
	float32 minz;
	float32 maxx;
	float32 maxz;
	float32 csizex;
	float32 csizez;
	float32 inv_csizex;
	float32 inv_csizez;
	float32 maxr;
	xGridBound** cells;
	xGridBound* other;
};

struct xGridIterator
{
	xGridBound** listhead;
	xGridBound* curcell;
	uint32 delfound;
};

typedef bool32(*xGridCheckPositionCallback)(xEnt* ent, void* cbdata);

inline xGridBound* xGridIterFirstCell(xGridBound**, xGridIterator&) STUB
inline xGridBound* xGridIterFirstCell(xGrid*, int32, int32, xGridIterator&) STUB
inline xGridBound* xGridIterNextCell(xGridIterator&) STUB
inline void xGridIterClose(xGridIterator&) STUB_VOID

struct grid_index
{
	uint16 unk0, unk2;
};

void xGridBoundInit(xGridBound* gridb, void* data);
void xGridInit(xGrid* grid, const xBox* bounds, uint16 nx, uint16 nz, uint8 ingrid_id);
void xGridKill(xGrid* grid);
void xGridEmpty(xGrid* grid);
bool32 xGridAddToCell(xGridBound**, xGridBound*);
bool32 xGridAdd(xGrid* grid, xEnt* ent);
bool32 xGridRemove(xGridBound* gridb);
void xGridUpdate(xGrid* grid, xEnt* ent);
void xGridGetCell(xGrid* grid, float32 posx, float32, float32 posz, int32& grx, int32& grz);
xGridBound* xGridIterFirstCell(xGrid* grid, float32 posx, float32, float32 posz, int32& grx, int32& grz, xGridIterator& it);
bool32 xGridEntIsTooBig(xGrid* grid, const xEnt* ent);
void xGridCheckPosition(xGrid* grid, xVec3* pos, xQCData* qcd, xGridCheckPositionCallback hitCB, void* cbdata);

inline grid_index get_grid_index(const xGrid&, float32, float32) STUB;

template <class T> inline void xGridCheckBound(xGrid& grid, xBound& bound, xQCData& qcd, T cb) STUB_VOID;