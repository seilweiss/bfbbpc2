#pragma once

#include <types.h>

template <class T> class xListItem
{
private:
	int32 flg_travFilter;
	T* next;
	T* prev;

public:
	xListItem() STUB_VOID;
};