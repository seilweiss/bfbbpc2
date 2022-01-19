#pragma once

#include "xsavegame.h"

typedef struct st_SERIAL_CLIENTINFO SERIAL_CLIENTINFO;

class xSerial
{
private:
	uint32 idtag;
	int32 baseoff;
	SERIAL_CLIENTINFO* ctxtdata;
	int32 warned;
	int32 curele;
	int32 bitidx;
	int32 bittally;

public:
	xSerial();
	~xSerial();
	void setClient(uint32 idtag);
	int32 Write(char* data, int32 elesize, int32 n);
	int32 Write_b1(int32 bits);
	int32 Write_b7(uint32 bits);
	int32 Write(uint8 data);
	int32 Write(int16 data);
	int32 Write(int32 data);
	int32 Write(uint32 data);
	int32 Write(float32 data);
	int32 Read(char* buf, int32 elesize, int32 n);
	int32 Read_b1(int32* bits);
	int32 Read_b7(uint32* bits);
	int32 Read(uint8* buf);
	int32 Read(int16* buf);
	int32 Read(int32* buf);
	int32 Read(uint32* buf);
	int32 Read(float32* buf);
	void wrbit(bool32 is_on);
	bool32 rdbit();
	void prepare(uint32);
};

typedef struct st_SERIAL_PERCID_SIZE
{
	uint32 idtag;
	int32 needsize;
} SERIAL_PERCID_SIZE;

typedef bool32(*xSerialTraverseCallback)(uint32, xSerial*);

int32 xSerialStartup(int32 count, SERIAL_PERCID_SIZE* sizeinfo);
int32 xSerialShutdown();
void xSerialTraverse(xSerialTraverseCallback func);
void xSerialWipeMainBuffer();
bool32 xSerial_svgame_register(XSAVEGAME_DATA* sgctxt, SAVEGAME_MODE mode);