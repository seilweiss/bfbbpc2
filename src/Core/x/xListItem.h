#pragma once

#include <types.h>

template <class T> class xListItem
{
private:
	int32 flg_travFilter;
	T* next;
	T* prev;

public:
	xListItem() WIP : flg_travFilter(0), prev(NULL), next(NULL) {}

	void Remove() STUB_VOID;
};