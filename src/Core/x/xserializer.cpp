#include "xserializer.h"

int32 xSerialStartup(int32 count, SERIAL_PERCID_SIZE* sizeinfo) STUB
int32 xSerialShutdown() STUB
void xSerialTraverse(xSerialTraverseCallback func) STUB_VOID
xSerial::xSerial() {}
xSerial::~xSerial() STUB_VOID
void xSerial::setClient(uint32 idtag) STUB_VOID
int32 xSerial::Write(char* data, int32 elesize, int32 n) STUB
int32 xSerial::Write_b1(int32 bits) STUB
int32 xSerial::Write_b7(uint32 bits) STUB
int32 xSerial::Write(uint8 data) STUB
int32 xSerial::Write(int16 data) STUB
int32 xSerial::Write(int32 data) STUB
int32 xSerial::Write(uint32 data) STUB
int32 xSerial::Write(float32 data) STUB
int32 xSerial::Read(char* buf, int32 elesize, int32 n) STUB
int32 xSerial::Read_b1(int32* bits) STUB
int32 xSerial::Read_b7(uint32* bits) STUB
int32 xSerial::Read(uint8* buf) STUB
int32 xSerial::Read(int16* buf) STUB
int32 xSerial::Read(int32* buf) STUB
int32 xSerial::Read(uint32* buf) STUB
int32 xSerial::Read(float32* buf) STUB
void xSerial::wrbit(bool32 is_on) STUB_VOID
bool32 xSerial::rdbit() STUB
void xSerial::prepare(uint32) STUB_VOID
void xSerialWipeMainBuffer() STUB_VOID
static void xSER_init_tables() STUB_VOID
static void xSER_init_buffers(int32 count, SERIAL_PERCID_SIZE* sizeinfo) STUB_VOID
static int32 xSER_ord_compare(void* e1, void* e2) STUB
static int32 xSER_ord_test(const void* key, void* elt) STUB
static SERIAL_CLIENTINFO* XSER_get_client(uint32 idtag) STUB
bool32 xSerial_svgame_register(XSAVEGAME_DATA* sgctxt, SAVEGAME_MODE mode) STUB
static bool32 xSER_xsgclt_svinfo_ver(void*, XSAVEGAME_DATA*, int32* cur_space, int32* max_fullgame) STUB
static bool32 xSER_xsgclt_svproc_ver(void*, XSAVEGAME_DATA* xsg, XSAVEGAME_WRITECONTEXT* wctxt) STUB
static bool32 xSER_xsgclt_ldproc_ver(void*, XSAVEGAME_DATA* xsg, XSAVEGAME_READCONTEXT* rctxt, uint32, int32) STUB
static bool32 xSER_xsgclt_svinfo_clt(void* cltdata, XSAVEGAME_DATA*, int32* cur_space, int32* max_fullgame) STUB
static bool32 xSER_xsgclt_svproc_clt(void* cltdata, XSAVEGAME_DATA* xsg, XSAVEGAME_WRITECONTEXT* wctxt) STUB
static bool32 xSER_xsgclt_ldproc_clt(void*, XSAVEGAME_DATA* xsg, XSAVEGAME_READCONTEXT* rctxt, uint32 idtag, int32) STUB
static bool32 xSER_xsgclt_svinfo_fill(void*, XSAVEGAME_DATA*, int32* cur_space, int32* max_fullgame) STUB
static bool32 xSER_xsgclt_svproc_fill(void*, XSAVEGAME_DATA* xsg, XSAVEGAME_WRITECONTEXT* wctxt) STUB
static bool32 xSER_xsgclt_ldproc_fill(void*, XSAVEGAME_DATA* xsg, XSAVEGAME_READCONTEXT* rctxt, uint32, int32) STUB