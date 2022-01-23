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

	void Insert(T*) STUB_VOID;
	void Remove() STUB_VOID;
	T* Next() STUB;
	T* RemHead(T** listhead) STUB;
	T* Head() STUB;
};