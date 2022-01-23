#pragma once

#include "xRMemData.h"
#include "xordarray.h"

class xFactoryInst : public RyzMemData
{
private:
	int32 itemType;
	xFactoryInst* nextprod;
	xFactoryInst* prevprod;

public:
	xFactoryInst() WIP : itemType(0), prevprod(NULL), nextprod(NULL) {}
	~xFactoryInst() WIP {}
};

typedef xFactoryInst* (*xFactoryInstCreator)(int32, RyzMemGrow*, void*);
typedef void(*xFactoryInstDestroyer)(xFactoryInst*);

struct XGOFTypeInfo
{
	int32 tid;
	xFactoryInstCreator creator;
	xFactoryInstDestroyer destroyer;
};

class xFactory : public RyzMemData
{
private:
	XGOFTypeInfo* infopool;
	st_XORDEREDARRAY infolist;
	xFactoryInst* products;
	RyzMemGrow growContextData;

public:
	xFactory(int32 maxTypes);
	~xFactory();

	int32 RegItemType(XGOFTypeInfo* info);
	int32 RegItemType(int32 tid, xFactoryInstCreator create, xFactoryInstDestroyer destroy);
	void GrowDataEnable(xBase* user, bool32 isResume);
	void GrowDataDisable();
	xFactoryInst* CreateItem(int32 typeID, void* userdata, RyzMemGrow* callerzgrow);
	void DestroyAll();
	void DestroyItem(xFactoryInst* item);
};