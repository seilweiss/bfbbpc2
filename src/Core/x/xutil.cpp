#include "xutil.h"

int32 xUtilStartup() STUB
int32 xUtilShutdown() STUB
const char* xUtil_idtag2string(uint32 srctag, int32 bufidx) STUB
uint32 xUtil_crc_init() STUB
uint32 xUtil_crc_update(uint32 crc_accum, char* data, int32 datasize) STUB
bool32 xUtil_yesno(float32 wt_yes) STUB
void xUtil_wtadjust(float32* wts, int32 cnt, float32 arbref) STUB_VOID