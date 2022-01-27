#pragma once

#include "zEnt.h"
#include "xDynAsset.h"
#include "zTalkBox.h"

struct taxi_asset : xDynAsset
{
	uint32 marker;
	uint32 cameraID;
	uint32 portalID;
	uint32 talkBoxID;
	uint32 textID;
	uint32 taxiID;
	float32 invDelay;
	float32 portalDelay;
};

struct zTaxi : xBase
{
	taxi_asset* basset;
	zEnt* taxi;
	xVec3 pos;
	uint32 currState;
	uint32 prevState;
	float32 portalTimer;
	float32 invTimer;
	float32 radius;
};

class taxiCB : public ztalkbox::callback
{
private:
	zTaxi* taxi;
	ztalkbox::answer_enum answer;

public:
	taxiCB() WIP : ztalkbox::callback() {}

	virtual void on_signal(uint32) {}
	virtual void on_start() {}
	virtual void on_stop() {}
	virtual void on_answer(ztalkbox::answer_enum answer) STUB_VOID;
};

void zTaxi_Init(xBase& data, xDynAsset& asset, ulong32);
void zTaxi_Init(zTaxi* taxi, taxi_asset* asset);
void zTaxi_Setup(zTaxi* taxi);
void zTaxi_Update(xBase* to, xScene*, float32 dt);
void zTaxi_tb_answer(uint32);
void zTaxi_Save(zTaxi* taxi, xSerial* s);
void zTaxi_Load(zTaxi* taxi, xSerial* s);
bool32 zTaxiEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*);