#include "iFile.h"

#include "xFile.h"

void iFileInit() STUB_VOID
void iFileExit() {}
uint32* iFileLoad(char* name, uint32* buffer, uint32* size) STUB
uint32 iFileOpen(const char* name, int32 flags, tag_xFile* file) STUB
int32 iFileSeek(xFile* file, int32 offset, int32 whence) STUB
static void ifilereadCB(xFile*) STUB_VOID
uint32 iFileRead(tag_xFile* file, void* buf, uint32 size) STUB
// GameCube only
//static void async_cb(long32, DVDFileInfo*) STUB_VOID
int32 iFileReadAsync(xFile*, void*, uint32, iFileReadAsyncCallback, int32) STUB
IFILE_READSECTOR_STATUS iFileReadAsyncStatus(int32 key, int32* amtToFar) STUB
uint32 iFileClose(xFile* file) STUB
uint32 iFileGetSize(xFile* file) STUB
void iFileReadStop() STUB_VOID
void iFileFullPath(const char* relname, char* fullname) STUB_VOID
void iFileSetPath(char* path) STUB_VOID
uint32 iFileFind(const char*, tag_xFile*) STUB
void iFileGetInfo(tag_xFile*, uint32*, uint32*) STUB_VOID