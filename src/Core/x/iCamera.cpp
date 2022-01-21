#include "iCamera.h"

RwCamera* iCameraCreate(int32 width, int32 height, bool32 mainGameCamera) STUB
void iCameraDestroy(RwCamera* camera) STUB_VOID
void iCameraBegin(RwCamera* cam, bool32 clear) STUB_VOID
void iCameraEnd(RwCamera* cam) STUB_VOID
void iCameraShowRaster(RwCamera* cam) STUB_VOID
void iCameraFrustumPlanes(RwCamera* cam, xVec4* frustplane) STUB_VOID
void iCameraUpdatePos(RwCamera* cam, xMat4x3* pos) STUB_VOID
void iCameraSetFOV(RwCamera* cam, float32 fov) STUB_VOID
void iCameraAssignEnv(RwCamera* camera, iEnv* env_geom) STUB_VOID
void iCamGetViewMatrix(RwCamera* camera, xMat4x3* view_matrix) STUB_VOID
void iCameraSetNearFarClip(float32 nearPlane, float32 farPlane) STUB_VOID
void iCameraSetFogParams(iFogParams* fp, float32 time) STUB_VOID
void iCameraUpdateFog(RwCamera*, iTime t) STUB_VOID
void iCameraSetFogRenderStates() STUB_VOID