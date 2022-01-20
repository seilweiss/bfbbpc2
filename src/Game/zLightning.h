#pragma once

#include "xMath3.h"
#include "xColor.h"

typedef struct _tagLightningAdd
{
	uint32 type;
	float32 setup_degrees;
	float32 move_degrees;
	float32 rot_radius;
	xVec3* start;
	xVec3* end;
	int16 total_points;
	int16 end_points;
	float32 time;
	float32 arc_height;
	float32 thickness;
	xColor color;
	float32 rand_radius;
	uint32 flags;
	float32 zeus_normal_offset;
	float32 zeus_back_offset;
	float32 zeus_side_offset;
} LightningAdd;

typedef struct _tagLightningLine
{
	float32 unused;
} LightningLine;

typedef struct _tagLightningRot
{
	float32 deg[16];
	float32 degrees;
	float32 height;
} LightningRot;

typedef struct _tagLightningZeus
{
	float32 normal_offset;
	float32 back_offset;
	float32 side_offset;
} LightningZeus;

struct zLightning
{
	uint32 type;
	uint32 flags;
	union
	{
		struct
		{
			xVec3 base_point[16];
			xVec3 point[16];
			int16 total_points;
			int16 end_points;
			float32 arc_height;
			xVec3 arc_normal;
			float32 thickness[16];
			union
			{
				LightningLine line;
				LightningRot rot;
				LightningZeus zeus;
			};
			float32 rand_radius;
		} legacy;
		struct
		{
			xVec3 endPoint[2];
			xVec3 direction;
			float32 length;
			float32 scale;
			float32 width;
			float32 endParam[2];
			float32 endVel[2];
			float32 paramSpan[2];
			float32 arc_height;
			xVec3 arc_normal;
		} func;
	};
	xColor color;
	float32 time_left;
	float32 time_total;
};

void zLightningInit();
zLightning* zLightningAdd(LightningAdd* add);
void zLightningUpdate(float32 seconds);
void zLightningRender();
void zLightningShow(zLightning* l, bool32 show);
void zLightningKill(zLightning* l);
void zLightningModifyEndpoints(zLightning* l, xVec3* start, xVec3* end);