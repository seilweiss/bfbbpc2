#pragma once

#include "xMath3.h"
#include "iTime.h"

#include <rwcore.h>

struct iEnv;
struct iFogParams;

RwCamera* iCameraCreate(int32 width, int32 height, bool32 mainGameCamera);
void iCameraDestroy(RwCamera* camera);
void iCameraBegin(RwCamera* cam, bool32 clear);
void iCameraEnd(RwCamera* cam);
void iCameraShowRaster(RwCamera* cam);
void iCameraFrustumPlanes(RwCamera* cam, xVec4* frustplane);
void iCameraUpdatePos(RwCamera* cam, xMat4x3* pos);
void iCameraSetFOV(RwCamera* cam, float32 fov);
void iCameraAssignEnv(RwCamera* camera, iEnv* env_geom);
void iCamGetViewMatrix(RwCamera* camera, xMat4x3* view_matrix);
void iCameraSetNearFarClip(float32 nearPlane, float32 farPlane);
void iCameraSetFogParams(iFogParams* fp, float32 time);
void iCameraUpdateFog(RwCamera*, iTime t);
void iCameraSetFogRenderStates();