#include "xPartition.h"

void xPartitionReset() STUB_VOID
static PartLink* PartitionGetFreeLink() STUB
static void PartitionSpaceReset(PartSpace*) STUB_VOID
static void PartitionSpaceInsert(PartSpace*, void*) STUB_VOID
int32 xPartitionGetTrueIdx(Partition*, int32, int32, int32) STUB
void xPartitionVolume(Partition* part, xVolume* volume, int32 x_spaces, int32 y_spaces, int32 z_spaces) STUB_VOID
void xPartitionWorld(Partition* part, xEnv* env, int32 x_spaces, int32 y_spaces, int32 z_spaces) STUB_VOID
int32 xPartitionInsert(Partition* part, void* insert_data, xVec3* insert_pos) STUB
int32 xPartitionUpdate(Partition* part, void* data, int32 old_idx, xVec3* current_pos) STUB
void xPartitionSpaceMove(PartSpace* src, PartSpace* dest, uint32 data) STUB_VOID
void xPartitionDump(Partition*, char*) STUB_VOID