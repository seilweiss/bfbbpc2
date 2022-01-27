#include "zTaxi.h"

enum answer_enum
{
	ANSWER_CONTINUE,
	ANSWER_YES,
	ANSWER_NO,
	ANSWER_NONE
};

void zTaxi_Init(xBase& data, xDynAsset& asset, ulong32) STUB_VOID
void zTaxi_Init(zTaxi* taxi, taxi_asset* asset) STUB_VOID
void zTaxi_Setup(zTaxi* taxi) STUB_VOID
void zTaxi_Update(xBase* to, xScene*, float32 dt) STUB_VOID
void zTaxi_tb_answer(uint32) STUB_VOID
void zTaxi_Save(zTaxi* taxi, xSerial* s) STUB_VOID
void zTaxi_Load(zTaxi* taxi, xSerial* s) STUB_VOID
bool32 zTaxiEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB