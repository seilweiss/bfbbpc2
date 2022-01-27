#pragma once

#include "xBase.h"
#include "xMath3.h"
#include "xBound.h"
#include "xMath2.h"

#include <rwcore.h>

struct xScene;
struct xEnt;

struct xCamera : xBase
{
	RwCamera* lo_cam;
	xMat4x3 mat;
	xMat4x3 omat;
	xMat3x3 mbasis;
	xBound bound;
	xMat4x3* tgt_mat;
	xMat4x3* tgt_omat;
	xBound* tgt_bound;
	xVec3 focus;
	xScene* sc;
	xVec3 tran_accum;
	float32 fov;
	uint32 flags;
	float32 tmr;
	float32 tm_acc;
	float32 tm_dec;
	float32 ltmr;
	float32 ltm_acc;
	float32 ltm_dec;
	float32 dmin;
	float32 dmax;
	float32 dcur;
	float32 dgoal;
	float32 hmin;
	float32 hmax;
	float32 hcur;
	float32 hgoal;
	float32 pmin;
	float32 pmax;
	float32 pcur;
	float32 pgoal;
	float32 depv;
	float32 hepv;
	float32 pepv;
	float32 orn_epv;
	float32 yaw_epv;
	float32 pitch_epv;
	float32 roll_epv;
	xQuat orn_cur;
	xQuat orn_goal;
	xQuat orn_diff;
	float32 yaw_cur;
	float32 yaw_goal;
	float32 pitch_cur;
	float32 pitch_goal;
	float32 roll_cur;
	float32 roll_goal;
	float32 dct;
	float32 dcd;
	float32 dccv;
	float32 dcsv;
	float32 hct;
	float32 hcd;
	float32 hccv;
	float32 hcsv;
	float32 pct;
	float32 pcd;
	float32 pccv;
	float32 pcsv;
	float32 orn_ct;
	float32 orn_cd;
	float32 orn_ccv;
	float32 orn_csv;
	float32 yaw_ct;
	float32 yaw_cd;
	float32 yaw_ccv;
	float32 yaw_csv;
	float32 pitch_ct;
	float32 pitch_cd;
	float32 pitch_ccv;
	float32 pitch_csv;
	float32 roll_ct;
	float32 roll_cd;
	float32 roll_ccv;
	float32 roll_csv;
	xVec4 frustplane[12];
};

struct cameraFXShake
{
	float32 magnitude;
	xVec3 dir;
	float32 cycleTime;
	float32 cycleMax;
	float32 dampen;
	float32 dampenRate;
	float32 rotate_magnitude;
	float32 radius;
	xVec3* epicenterP;
	xVec3 epicenter;
	xVec3* player;
};

struct cameraFXZoom
{
	float32 holdTime;
	float32 vel;
	float32 accel;
	float32 distance;
	uint32 mode;
	float32 velCur;
	float32 distanceCur;
	float32 holdTimeCur;
};

struct cameraFX
{
	int32 type;
	int32 flags;
	float32 elapsedTime;
	float32 maxTime;
	union
	{
		cameraFXShake shake;
		cameraFXZoom zoom;
	};
};

struct xBinaryCamera
{
	struct zone_data
	{
		float32 distance;
		float32 height;
		float32 height_focus;
	};

	struct config
	{
		zone_data zone_rest;
		zone_data zone_above;
		zone_data zone_below;
		float32 move_speed;
		float32 turn_speed;
		float32 stick_speed;
		float32 stick_yaw_vel;
		float32 max_yaw_vel;
		float32 margin_angle;
	};

	config cfg;
	xCamera* camera;
	xQuat cam_dir;
	xVec3* s1;
	xVec3* s2;
	float32 s2_radius;
	xVec2 stick_offset;

	void init();
	void start(xCamera& camera);
	void stop();
	void update(float32 dt);
	void set_targets(const xVec3&, const xVec3&, float32) STUB_VOID;
	void render_debug() {}
	void add_tweaks(const char*) {}
};

void xCameraInit(xCamera* cam, uint32 width, uint32 height);
void xCameraExit(xCamera* cam);
void xCameraReset(xCamera* cam, float32 d, float32 h, float32 pitch);
void SweptSphereHitsCameraEnt(xScene*, xRay3* ray, xQCData* qcd, xEnt* ent, void* data);
void xCameraUpdate(xCamera* cam, float32 dt);
void xCameraBegin(xCamera* cam, bool32 clear);
void xCameraFXBegin(xCamera* cam);
void xCameraFXAlloc();
void xCameraFXZoomUpdate(cameraFX* f, float32 dt, const xMat4x3*, xMat4x3* m);
void xCameraFXShake(float32 maxTime, float32 magnitude, float32 cycleMax, float32 rotate_magnitude, float32 radius, xVec3* epicenter, xVec3* player);
void xCameraFXShakeUpdate(cameraFX* f, float32 dt, const xMat4x3*, xMat4x3* m);
void xCameraFXUpdate(xCamera* cam, float32 dt);
void xCameraFXEnd(xCamera* cam);
void xCameraEnd(xCamera* cam, float32 seconds, bool32 update_scrn_fx);
void xCameraShowRaster(xCamera* cam);
void xCameraSetScene(xCamera* cam, xScene* sc);
void xCameraSetTargetMatrix(xCamera* cam, xMat4x3* mat);
void xCameraSetTargetOMatrix(xCamera* cam, xMat4x3* mat);
void xCameraDoCollisions(int32 do_collis, int32 owner);
void xCameraMove(xCamera* cam, uint32 flags, float32 dgoal, float32 hgoal, float32 pgoal, float32 tm, float32 tm_acc, float32 tm_dec);
void xCameraMove(xCamera* cam, const xVec3& loc);
void xCameraMove(xCamera* cam, const xVec3& loc, float32 maxSpeed);
void xCameraFOV(xCamera* cam, float32 fov, float32 maxSpeed, float32 dt);
void xCameraLook(xCamera* cam, uint32 flags, const xQuat* orn_goal, float32 tm, float32 tm_acc, float32 tm_dec);
void xCameraLookYPR(xCamera* cam, uint32 flags, float32 yaw, float32 pitch, float32 roll, float32 tm, float32 tm_acc, float32 tm_dec);
void xCameraRotate(xCamera* cam, const xMat3x3& m, float32 time, float32 accel, float32 decl);
void xCameraRotate(xCamera* cam, const xVec3& v, float32 roll, float32 time, float32 accel, float32 decl);

inline void xCameraSetFOV(xCamera*, float32) STUB_VOID
inline float32 xCameraGetFOV(const xCamera*) STUB