#include "xFactory.h"

xFactory::xFactory(int32 maxTypes) STUB_VOID
xFactory::~xFactory() STUB_VOID
int32 xFactory::RegItemType(XGOFTypeInfo* info) STUB
int32 xFactory::RegItemType(int32 tid, xFactoryInstCreator create, xFactoryInstDestroyer destroy) STUB
void xFactory::GrowDataEnable(xBase* user, bool32 isResume) STUB_VOID
void xFactory::GrowDataDisable() STUB_VOID
xFactoryInst* xFactory::CreateItem(int32 typeID, void* userdata, RyzMemGrow* callerzgrow) STUB
void xFactory::DestroyAll() STUB_VOID
void xFactory::DestroyItem(xFactoryInst* item) STUB_VOID
static int32 OrdTest_infotype(const void* vkey, void* vitem) STUB
static int32 OrdComp_infotype(void* vkey, void* vitem) STUB