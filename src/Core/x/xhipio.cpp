#include "xhipio.h"

st_HIPLOADFUNCS* get_HIPLFuncs() STUB
static st_HIPLOADDATA* HIPLCreate(const char* filename, char* dblbuf, int32 bufsize) STUB
static void HIPLDestroy(st_HIPLOADDATA* lddata) STUB_VOID
static uint32 HIPLBaseSector(st_HIPLOADDATA* lddata) STUB
static bool32 HIPLSetBypass(st_HIPLOADDATA* lddata, bool32 enable, bool32 use_async) STUB
static void HIPLSetSpot(st_HIPLOADDATA* lddata, int32 spot) STUB_VOID
static uint32 HIPLBlockEnter(st_HIPLOADDATA* lddata) STUB
static void HIPLBlockExit(st_HIPLOADDATA* lddata) STUB_VOID
static int32 HIPLBlockRead(st_HIPLOADDATA* lddata, void* data, int32 cnt, int32 size) STUB
static int32 HIPLBypassRead(st_HIPLOADDATA* lddata, void* data, int32 cnt, int32 size) STUB
static int32 HIPLReadAsync(st_HIPLOADDATA*, int32, char*, int32, int32) STUB
static en_READ_ASYNC_STATUS HIPLPollRead(st_HIPLOADDATA* lddata) STUB
static int32 HIPLReadBytes(st_HIPLOADDATA* lddata, char* data, int32 cnt) STUB
static int32 HIPLReadShorts(st_HIPLOADDATA* lddata, int16* data, int32 cnt) STUB
static int32 HIPLReadLongs(st_HIPLOADDATA* lddata, int32* data, int32 cnt) STUB
static int32 HIPLReadFloats(st_HIPLOADDATA* lddata, float32* data, int32 cnt) STUB
static int32 HIPLReadString(st_HIPLOADDATA* lddata, char* buf) STUB