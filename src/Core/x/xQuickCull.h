#pragma once

#include "xMath3.h"

struct xBound;

struct xQCData
{
	int8 xmin;
	int8 ymin;
	int8 zmin;
	int8 zmin_dup;
	int8 xmax;
	int8 ymax;
	int8 zmax;
	int8 zmax_dup;
	xVec3 min;
	xVec3 max;
};

struct xQCControl
{
	float32 world_xmin;
	float32 world_ymin;
	float32 world_zmin;
	float32 world_xmax;
	float32 world_ymax;
	float32 world_zmax;
	float32 world_xsz;
	float32 world_ysz;
	float32 world_zsz;
	float32 scale_x;
	float32 scale_y;
	float32 scale_z;
	float32 center_x;
	float32 center_y;
	float32 center_z;
};

void xQuickCullInit(xQCControl* ctrl, float32 xmin, float32 ymin, float32 zmin, float32 xmax, float32 ymax, float32 zmax);
void xQuickCullInit(xQCControl* ctrl, const xBox* box);
bool32 xQuickCullIsects(const xQCData* a, const xQCData* b);
void xQuickCullForBound(xQCControl* ctrl, xQCData* q, const xBound* b);
void xQuickCullForLine(xQCControl* ctrl, xQCData* q, const xLine3* ln);
void xQuickCullForRay(xQCControl* ctrl, xQCData* q, const xRay3* r);
void xQuickCullForSphere(xQCControl* ctrl, xQCData* q, const xSphere* s);
void xQuickCullForBox(xQCControl* ctrl, xQCData* q, const xBox* box);
void xQuickCullForOBB(xQCControl* ctrl, xQCData* q, const xBox* b, const xMat4x3* m);
void xQuickCullForEverything(xQCData* q);

inline void xQuickCullForBound(xQCData*, const xBound*) STUB_VOID
inline void xQuickCullForRay(xQCData*, const xRay3*) STUB_VOID
inline void xQuickCullForSphere(xQCData*, const xSphere*) STUB_VOID
inline void xQuickCullForBox(xQCData*, const xBox*) STUB_VOID