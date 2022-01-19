#include "xString.h"

namespace {

	inline int32 tolower(int32) STUB;
	inline int32 tolower(char) STUB;

}

uint32 xStrHash(const char* str) STUB
uint32 xStrHash(const char* s, ulong32 size) STUB
uint32 xStrHashCat(uint32 prefix, const char* str) STUB
const char* xStrTok(char* string, const char* control, char** nextoken) STUB
const char* xStrTokBuffer(const char* string, const char* control, void* buffer) STUB
int32 xStricmp(const char* string1, const char* string2) STUB
char* xStrupr(char* string) STUB
int32 xStrParseFloatList(float32* dest, const char* strbuf, int32 max) STUB
int32 imemcmp(const void* d1, const void* d2, ulong32 size) STUB
int32 icompare(const substr& s1, const substr& s2) STUB
uint32 atox(const substr& s, const ulong32& read_size) STUB
const char* find_char(const substr& s, const substr& cs) STUB