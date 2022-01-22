#pragma once

#include <types.h>

struct xBase;

struct RyzMemData
{
};

class RyzMemGrow
{
private:
	int32 flg_grow;
	int32 amt;
	char* ptr;
	xBase* user;
	int32 amt_last;
	char* ptr_last;
	xBase* user_last;
};