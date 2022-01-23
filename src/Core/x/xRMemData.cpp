#include "xRMemData.h"

void* RyzMemData::operator new(size_t amt, int32, RyzMemGrow* growCtxt) STUB
void RyzMemData::operator delete(void*) {}

RyzMemGrow* RyzMemGrow::Init(xBase* growuser) STUB
RyzMemGrow* RyzMemGrow::Resume(xBase*) STUB
void RyzMemGrow::Done() STUB_VOID