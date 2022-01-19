#include "xIni.h"

static char* TrimWhitespace(char*) STUB
xIniFile* xIniParse(char* buf, int32 len) STUB
void xIniDestroy(xIniFile* ini) STUB_VOID
int32 xIniGetIndex(xIniFile*, char*) STUB
int32 xIniGetInt(xIniFile* ini, char* tok, int32 def) STUB
float32 xIniGetFloat(xIniFile* ini, char* tok, float32 def) STUB
char* xIniGetString(xIniFile* ini, char* tok, char* def) STUB