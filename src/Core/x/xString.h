#pragma once

#include <types.h>

struct substr
{
	const char* text;
	ulong32 size;

	static substr create(const char* text, ulong32 size) WIP { substr s = { text, size }; return s; }
};

uint32 xStrHash(const char* str);
uint32 xStrHash(const char* s, ulong32 size);
uint32 xStrHashCat(uint32 prefix, const char* str);
const char* xStrTok(char* string, const char* control, char** nextoken);
const char* xStrTokBuffer(const char* string, const char* control, void* buffer);
int32 xStricmp(const char* string1, const char* string2);
char* xStrupr(char* string);
int32 xStrParseFloatList(float32* dest, const char* strbuf, int32 max);
int32 imemcmp(const void* d1, const void* d2, ulong32 size);
int32 icompare(const substr& s1, const substr& s2);
uint32 atox(const substr& s, const ulong32& read_size);
const char* find_char(const substr& s, const substr& cs);

inline const char* find_char(const substr&, char) STUB
inline bool is_ws(char) STUB
inline ulong32 skip_ws(const char*&, ulong32&) STUB
inline ulong32 skip_ws(substr&) STUB
inline ulong32 rskip_ws(const char*&, ulong32&) STUB
inline ulong32 rskip_ws(substr&) STUB
inline void trim_ws(const char*&, ulong32&) STUB_VOID
inline void trim_ws(substr&) STUB_VOID
inline ulong32 atox(const substr&) STUB