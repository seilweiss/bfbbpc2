#pragma once

#include <types.h>

struct xBase;
class RyzMemGrow;

class RyzMemData
{
public:
	void* operator new(size_t amt, int32, RyzMemGrow* growCtxt);
	void operator delete(void*);
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

public:
	RyzMemGrow* Init(xBase* growuser);
	RyzMemGrow* Resume(xBase*);
	void Done();
	bool32 IsEnabled() STUB;
};