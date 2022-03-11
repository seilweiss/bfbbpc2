#include "iSystem.h"

#include <rwcore.h>

void iVSync() STUB_VOID
static void TRCInit() STUB_VOID
void iSystemInit(uint32 options) STUB_VOID
void iSystemExit() STUB_VOID
static uint32 RWAttachPlugins() STUB
static uint32 RenderWareInit() STUB
static void RenderWareExit() STUB_VOID
static RwTexture* TextureRead(const char* name, const char* maskName) STUB
uint8 iGetMinute() STUB
uint8 iGetHour() STUB
uint8 iGetDay() STUB
uint8 iGetMonth() STUB
uint32 iGetCurrFormattedDate(char* str) STUB
uint32 iGetCurrFormattedTime(char* str) STUB