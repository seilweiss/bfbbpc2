#include "xCamera.h"

inline void add_camera_tweaks() {}

void xCameraInit(xCamera* cam, uint32 width, uint32 height) STUB_VOID
void xCameraExit(xCamera* cam) STUB_VOID
void xCameraReset(xCamera* cam, float32 d, float32 h, float32 pitch) STUB_VOID
static void xCam_buildbasis(xCamera* cam) STUB_VOID
static void xCam_cyltoworld(xVec3*, const xMat4x3*, float32, float32, float32, uint32) STUB_VOID
static void xCam_worldtocyl(float32& d, float32& h, float32& p, const xMat4x3* tgt_mat, const xVec3* v, uint32 flags) STUB_VOID
static void xCam_CorrectD(xCamera*, float32, float32, float32) STUB_VOID
static void xCam_CorrectH(xCamera*, float32, float32, float32) STUB_VOID
static void xCam_CorrectP(xCamera*, float32, float32, float32) STUB_VOID
static void xCam_DampP(xCamera*, float32, float32) STUB_VOID
static void xCam_CorrectYaw(xCamera*, float32, float32, float32) STUB_VOID
static void xCam_CorrectPitch(xCamera*, float32, float32, float32) STUB_VOID
static void xCam_CorrectRoll(xCamera*, float32, float32, float32) STUB_VOID
void SweptSphereHitsCameraEnt(xScene*, xRay3* ray, xQCData* qcd, xEnt* ent, void* data) STUB_VOID
static void _xCameraUpdate(xCamera* cam, float32 dt) STUB_VOID
void xCameraUpdate(xCamera* cam, float32 dt) STUB_VOID
void xCameraBegin(xCamera* cam, bool32 clear) STUB_VOID
void xCameraFXBegin(xCamera* cam) STUB_VOID
static void xCameraFXInit() STUB_VOID
void xCameraFXAlloc() STUB_VOID
void xCameraFXZoomUpdate(cameraFX* f, float32 dt, const xMat4x3*, xMat4x3* m) STUB_VOID
void xCameraFXShake(float32 maxTime, float32 magnitude, float32 cycleMax, float32 rotate_magnitude, float32 radius, xVec3* epicenter, xVec3* player) STUB_VOID
void xCameraFXShakeUpdate(cameraFX* f, float32 dt, const xMat4x3*, xMat4x3* m) STUB_VOID
void xCameraFXUpdate(xCamera* cam, float32 dt) STUB_VOID
void xCameraEnd(xCamera* cam, float32 seconds, bool32 update_scrn_fx) STUB_VOID
void xCameraShowRaster(xCamera* cam) STUB_VOID
void xCameraSetScene(xCamera* cam, xScene* sc) STUB_VOID
void xCameraSetTargetMatrix(xCamera* cam, xMat4x3* mat) STUB_VOID
void xCameraSetTargetOMatrix(xCamera* cam, xMat4x3* mat) STUB_VOID
void xCameraDoCollisions(int32 do_collis, int32 owner) STUB_VOID
void xCameraMove(xCamera* cam, uint32 flags, float32 dgoal, float32 hgoal, float32 pgoal, float32 tm, float32 tm_acc, float32 tm_dec) STUB_VOID
void xCameraMove(xCamera* cam, const xVec3& loc) STUB_VOID
void xCameraMove(xCamera* cam, const xVec3& loc, float32 maxSpeed) STUB_VOID
void xCameraFOV(xCamera* cam, float32 fov, float32 maxSpeed, float32 dt) STUB_VOID
void xCameraLook(xCamera* cam, uint32 flags, const xQuat* orn_goal, float32 tm, float32 tm_acc, float32 tm_dec) STUB_VOID
void xCameraLookYPR(xCamera* cam, uint32 flags, float32 yaw, float32 pitch, float32 roll, float32 tm, float32 tm_acc, float32 tm_dec) STUB_VOID
void xCameraRotate(xCamera* cam, const xMat3x3& m, float32 time, float32 accel, float32 decl) STUB_VOID
void xCameraRotate(xCamera* cam, const xVec3& v, float32 roll, float32 time, float32 accel, float32 decl) STUB_VOID
static void bound_sphere_xz(xVec3&, xVec3&, const xVec3&, float32, const xVec3&, float32) STUB_VOID
void xBinaryCamera::init() STUB_VOID
void xBinaryCamera::start(xCamera& camera) STUB_VOID
void xBinaryCamera::stop() STUB_VOID
void xBinaryCamera::update(float32 dt) STUB_VOID