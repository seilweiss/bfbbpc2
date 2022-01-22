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

struct XGOFTypeInfo
{
	int32 tid;
	xFactoryInst* (*creator)(int32, RyzMemGrow*, void*);
	void(*destroyer)(xFactoryInst*);
};

class xFactory : public RyzMemData
{
private:
	XGOFTypeInfo* infopool;
	st_XORDEREDARRAY infolist;
	xFactoryInst* products;
	RyzMemGrow growContextData;
};