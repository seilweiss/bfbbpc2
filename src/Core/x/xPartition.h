#pragma once

#include "xMath3.h"

struct xVolume;
struct xEnv;

typedef struct _tagPartLink
{
	void* data;
	_tagPartLink* next;
} PartLink;

typedef struct _tagPartSpace
{
	int32 total;
	PartLink head;
} PartSpace;

typedef struct _tagPartition
{
	xVec3 min;
	xVec3 max;
	xVec3 space_dim;
	int32 total_x;
	int32 total_y;
	int32 total_z;
	PartSpace* space;
	PartSpace global;
} Partition;

void xPartitionReset();
int32 xPartitionGetTrueIdx(Partition*, int32, int32, int32);
void xPartitionVolume(Partition* part, xVolume* volume, int32 x_spaces, int32 y_spaces, int32 z_spaces);
void xPartitionWorld(Partition* part, xEnv* env, int32 x_spaces, int32 y_spaces, int32 z_spaces);
int32 xPartitionInsert(Partition* part, void* insert_data, xVec3* insert_pos);
int32 xPartitionUpdate(Partition* part, void* data, int32 old_idx, xVec3* current_pos);
void xPartitionSpaceMove(PartSpace* src, PartSpace* dest, uint32 data);
void xPartitionDump(Partition*, char*);
