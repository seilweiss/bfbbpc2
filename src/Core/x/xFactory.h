#pragma once

#include "xRMemData.h"

class xFactoryInst : public RyzMemData
{
private:
	int32 itemType;
	xFactoryInst* nextprod;
	xFactoryInst* prevprod;

public:
	xFactoryInst() STUB_VOID;
};