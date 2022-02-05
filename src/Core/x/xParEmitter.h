#pragma once

#include "xBase.h"
#include "xMath3.h"
#include "xModel.h"

struct xParGroup;
struct xParSys;
struct xPar;
struct xScene;

struct xParInterp
{
	float32 val[2];
	uint32 interp;
	float32 freq;
	float32 oofreq;

	void set(float32, float32, float32, uint32) STUB_VOID;
	void order() STUB_VOID;
};

struct xParEmitterPropsAsset : xBaseAsset
{
	uint32 parSysID;
	union
	{
		xParInterp rate;
		xParInterp value[1];
	};
	xParInterp life;
	xParInterp size_birth;
	xParInterp size_death;
	xParInterp color_birth[4];
	xParInterp color_death[4];
	xParInterp vel_scale;
	xParInterp vel_angle;
	xVec3 vel;
	uint32 emit_limit;
	float32 emit_limit_reset_time;
};

struct xParEmitterCustomSettings : xParEmitterPropsAsset
{
	uint32 custom_flags;
	uint32 attachToID;
	xVec3 pos;
	xVec3 vel;
	float32 vel_angle_variation;
	uint8 rot[3];
	uint8 padding;
	float32 radius;
	float32 emit_interval_current;
	void* emit_volume;
};

#define XPAREMITTER_CUSTOM_UNK0x2 0x2
#define XPAREMITTER_CUSTOM_UNK0x100 0x100
#define XPAREMITTER_CUSTOM_UNK0x200 0x200

struct xPECircle
{
	float32 radius;
	float32 deflection;
	xVec3 dir;
};

typedef struct _tagEmitSphere
{
	float32 radius;
} EmitSphere;

typedef struct _tagEmitRect
{
	float32 x_len;
	float32 z_len;
} EmitRect;

typedef struct _tagEmitLine
{
	xVec3 pos1;
	xVec3 pos2;
	float32 radius;
} EmitLine;

typedef struct _tagEmitVolume
{
	uint32 emit_volumeID;
} EmitVolume;

typedef struct _tagEmitOffsetPoint
{
	xVec3 offset;
} EmitOffsetPoint;

struct xPEVCyl
{
	float32 height;
	float32 radius;
	float32 deflection;
};

struct xPEEntBone
{
	uint8 flags;
	uint8 type;
	uint8 bone;
	uint8 pad1;
	xVec3 offset;
	float32 radius;
	float32 deflection;
};

struct xPEEntBound
{
	uint8 flags;
	uint8 type;
	uint8 pad1;
	uint8 pad2;
	float32 expand;
	float32 deflection;
};

struct xParEmitterAsset : xBaseAsset
{
	uint8 emit_flags;
	uint8 emit_type;
	uint16 pad;
	uint32 propID;
	union
	{
		xPECircle e_circle;
		EmitSphere e_sphere;
		EmitRect e_rect;
		EmitLine e_line;
		EmitVolume e_volume;
		EmitOffsetPoint e_offsetp;
		xPEVCyl e_vcyl;
		xPEEntBone e_entbone;
		xPEEntBound e_entbound;
	};
	uint32 attachToID;
	xVec3 pos;
	xVec3 vel;
	float32 vel_angle_variation;
	uint32 cull_mode;
	float32 cull_dist_sqr;
};

struct xParEmitter : xBase
{
	xParEmitterAsset* tasset;
	xParGroup* group;
	xParEmitterPropsAsset* prop;
	uint8 rate_mode;
	float32 rate;
	float32 rate_time;
	float32 rate_fraction;
	float32 rate_fraction_cull;
	uint8 emit_flags;
	uint8 emit_pad[3];
	uint8 rot[3];
	xModelTag tag;
	float32 oocull_distance_sqr;
	float32 distance_to_cull_sqr;
	void* attachTo;
	xParSys* parSys;
	void* emit_volume;
	xVec3 last_attach_loc;
};

#define XPAREMITTER_UNK0x1 0x1

int32 xParInterpConvertInterpMode(xParInterp* p);
void xParEmitterInit(void* b, void* tasset);
void xParEmitterInit(xBase* b, xParEmitterAsset* pea);
void xParEmitterSetup(xParEmitter* t);
void xParEmitterReset(xParEmitter*);
bool32 xParEmitterEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);
xPar* xParEmitterEmitCustom(xParEmitter* p, float32 dt, xParEmitterCustomSettings* info);
float32 xParInterpCompute(int32 interp_mode, xParInterp* r, float32 time, int32 time_has_elapsed, float32 lastVal);
xPar* xParEmitterEmitSetTexIdxs(xPar* p, const xParSys* ps);
xPar* xParEmitterEmit(xParEmitter* pe, float32 emit_dt, float32 par_dt);
void xParEmitterUpdate(xBase* to, xScene*, float32 dt);
void xParEmitterDestroy();

inline xPar* xParEmitterEmit(xParEmitter*, float32) STUB