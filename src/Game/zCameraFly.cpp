#include "zCameraFly.h"

void zCameraFly_Init(xBase& data, xDynAsset& asset, ulong32) STUB_VOID
void zCameraFly_Init(zCameraFly*, CameraFly_asset*) STUB_VOID
void zCameraFly_Setup(zCameraFly* fly) STUB_VOID
void zCameraFly_Update(xBase*, xScene*, float32) {}
void zCameraFly_Save(zCameraFly* fly, xSerial* s) STUB_VOID
void zCameraFly_Load(zCameraFly* fly, xSerial* s) STUB_VOID
uint32 zCameraFlyProcessStopEvent() STUB
bool32 zCameraFlyEventCB(xBase*, xBase* to, uint32 toEvent, const float32*, xBase*) STUB