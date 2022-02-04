#include "xCamera.h"

#include "xstransvc.h"
#include "xEnt.h"
#include "xCollideFast.h"
#include "xScrFx.h"
#include "xScene.h"
#include "xEnv.h"

#include <rwcore.h>
#include <rpworld.h>

#include <string.h>

static bool32 sCamCollis = FALSE;

int32 xcam_collis_owner_disable = 0;
bool32 xcam_do_collis = TRUE;
float32 xcam_collis_radius = 0.4f;
float32 xcam_collis_stiffness = 0.3f;

static RpAtomic* sInvisWallHack = NULL;

float32 gCameraLastFov = 0.0f;

static xMat4x3 sCameraFXMatOld;

cameraFXTableEntry sCameraFXTable[CAMERAFX_TYPE_COUNT] =
{
    { CAMERAFX_TYPE_UNK0, NULL, NULL },
    { CAMERAFX_TYPE_ZOOM, xCameraFXZoomUpdate, NULL },
    { CAMERAFX_TYPE_SHAKE, xCameraFXShakeUpdate, NULL }
};

cameraFX sCameraFX[CAMERAFX_COUNT];

static void xCameraFXInit();

inline void add_camera_tweaks() {}

void xCameraInit(xCamera* cam, uint32 width, uint32 height) WIP
{
    xCameraFXInit();

    cam->lo_cam = iCameraCreate(width, height, TRUE);

    xCameraSetFOV(cam, 75.0f);

    cam->bound.sph.center.x = 0.0f;
    cam->bound.sph.center.y = 0.0f;
    cam->bound.sph.center.z = 0.0f;
    cam->bound.sph.r = 0.5f;
    cam->tgt_mat = NULL;
    cam->tgt_omat = NULL;
    cam->tgt_bound = NULL;
    cam->sc = NULL;
    cam->tran_accum.x = 0.0f;
    cam->tran_accum.y = 0.0f;
    cam->tran_accum.z = 0.0f;

    add_camera_tweaks();
}

void xCameraExit(xCamera* cam)
{
    if (cam->lo_cam)
    {
        iCameraDestroy(cam->lo_cam);
        cam->lo_cam = NULL;
    }
}

void xCameraReset(xCamera* cam, float32 d, float32 h, float32 pitch) WIP
{
    sInvisWallHack = (RpAtomic*)xSTFindAsset(0xB8895D14);

    xMat4x3Identity(&cam->mat);

    cam->omat = cam->mat;
    cam->focus.x = 0.0f;
    cam->focus.y = 0.0f;
    cam->focus.z = 10.0f;
    cam->tran_accum.x = 0.0f;
    cam->tran_accum.y = 0.0f;
    cam->tran_accum.z = 0.0f;
    cam->flags = 0;

    float32 goal_p = PI;

    if (cam->tgt_mat)
    {
        goal_p += xatan2(cam->tgt_mat->at.x, cam->tgt_mat->at.z);
    }

    xCameraMove(cam, 0x2E, d, h, goal_p, 0.0f, 2.0f / 3.0f, 2.0f / 3.0f);

    cam->pitch_goal = pitch;
    cam->pitch_cur = pitch;
    cam->roll_cur = 0.0f;

    xMat3x3Euler(&cam->mat, cam->yaw_cur, cam->pitch_cur, cam->roll_cur);

    cam->omat = cam->mat;
    cam->yaw_ct = 1.0f;
    cam->yaw_cd = 1.0f;
    cam->yaw_ccv = 0.65f;
    cam->yaw_csv = 1.0f;
    cam->pitch_ct = 1.0f;
    cam->pitch_cd = 1.0f;
    cam->pitch_ccv = 0.7f;
    cam->pitch_csv = 1.0f;
    cam->roll_ct = 1.0f;
    cam->roll_cd = 1.0f;
    cam->roll_ccv = 0.7f;
    cam->roll_csv = 1.0f;
    cam->flags |= XCAMERA_UNK0x80;

    xcam_do_collis = TRUE;
    xcam_collis_owner_disable = 0;
}

static void xCam_buildbasis(xCamera* cam) WIP
{
    if (!cam->tgt_mat)
    {
        return;
    }

    float32 d2d;
    float32 dx__ = cam->mat.pos.x - cam->tgt_mat->pos.x;
    float32 dz__ = cam->mat.pos.z - cam->tgt_mat->pos.z;
    float32 dist2 = xsqr(dx__) + xsqr(dz__);

    if (xapproxeq(dist2, 1.0f))
    {
        cam->mbasis.at.x = dx__;
        cam->mbasis.at.z = dz__;

        d2d = 1.0f;
    }
    else if (xapproxeq(dist2, 0.0f))
    {
        cam->mbasis.at.x = 0.0f;
        cam->mbasis.at.z = 0.0f;

        d2d = 0.0f;
    }
    else
    {
        d2d = xsqrt(dist2);

        float32 dist_inv = 1.0f / d2d;

        cam->mbasis.at.x = dx__ * dist_inv;
        cam->mbasis.at.z = dz__ * dist_inv;
    }

    if (d2d < EPSILON)
    {
        cam->mbasis.at.x = cam->mat.at.x;
        cam->mbasis.at.z = cam->mat.at.z;

        float32 dist = xsqrt(xsqr(cam->mbasis.at.x) + xsqr(cam->mbasis.at.z));

        if (dist > 0.001f)
        {
            cam->mbasis.at.x *= 1.0f / dist;
            cam->mbasis.at.z *= 1.0f / dist;
        }
        else
        {
            cam->mbasis.at.x = isin(cam->pcur);
            cam->mbasis.at.z = icos(cam->pcur);
        }
    }

    cam->mbasis.at.y = 0.0f;
    cam->mbasis.up.x = 0.0f;
    cam->mbasis.up.y = 1.0f;
    cam->mbasis.up.z = 0.0f;
    cam->mbasis.right.x = cam->mbasis.at.z;
    cam->mbasis.right.y = 0.0f;
    cam->mbasis.right.z = -cam->mbasis.at.x;
}

static void xCam_cyltoworld(xVec3* v, const xMat4x3* tgt_mat, float32 d, float32 h, float32 p, uint32 flags)
{
    if (flags & XCAMERA_UNK0x10)
    {
        v->y = h;
    }
    else
    {
        v->y = h + tgt_mat->pos.y;
    }

    if (flags & XCAMERA_UNK0x20)
    {
        v->x = d * isin(p) + tgt_mat->pos.x;
        v->z = d * icos(p) + tgt_mat->pos.z;
    }
    else
    {
        p += xatan2(tgt_mat->at.x, tgt_mat->at.z);

        v->x = d * isin(p) + tgt_mat->pos.x;
        v->z = d * icos(p) + tgt_mat->pos.z;
    }
}

static void xCam_worldtocyl(float32& d, float32& h, float32& p, const xMat4x3* tgt_mat, const xVec3* v, uint32 flags) WIP
{
    float32 lx;
    float32 lz;

    float32 dx__ = v->x - tgt_mat->pos.x;
    float32 dz__ = v->z - tgt_mat->pos.z;
    float32 dist2 = xsqr(dx__) + xsqr(dz__);

    if (xapproxeq(dist2, 1.0f))
    {
        d = 1.0f;
        lx = dx__;
        lz = dz__;
    }
    else if (xapproxeq(dist2, 0.0f))
    {
        d = 0.0f;
        lx = 0.0f;
        lz = 0.0f;
    }
    else
    {
        d = xsqrt(dist2);

        float32 dist_inv = 1.0f / d;

        lx = dx__ * dist_inv;
        lz = dz__ * dist_inv;
    }

    if (flags & XCAMERA_UNK0x10)
    {
        h = v->y;
    }
    else
    {
        h = v->y - tgt_mat->pos.y;
    }

    p = xatan2(lx, lz);

    if (!(flags & XCAMERA_UNK0x20))
    {
        float32 tgt_p = xatan2(tgt_mat->at.x, tgt_mat->at.z);

        p = xDangleClamp(p - tgt_p);
    }
}

static void xCam_CorrectD(xCamera* cam, float32 f1, float32 f2, float32 f3) WIP
{
    float32 f2_0 = (10.0f / 7.0f) * (2.0f * f1 - f2 * f3);

    f2_0 -= f2;
    f2_0 *= f3;

    float32 f0_0 = cam->mbasis.at.x * f2_0;
    float32 f0_1 = cam->mbasis.at.z * f2_0;

    cam->mat.pos.x += f0_0;
    cam->mat.pos.z += f0_1;
}

static void xCam_CorrectH(xCamera* cam, float32 f1, float32 f2, float32 f3)
{
    float32 f2_0 = 0.15f * f2;
    float32 f1_0 = (10.0f / 7.0f) * (f1 - f2_0 * f3);

    f1_0 -= f2_0;
    f1_0 *= f3;

    cam->mat.pos.y += f1_0;
}

static void xCam_CorrectP(xCamera* cam, float32 f1, float32 f2, float32 f3)
{
    float32 f8 = 0.15f * f2;
    float32 f1_0 = 2.5f * (2.0f * f1 - f8 * f3);

    f1_0 -= f8;
    f1_0 *= f3;

    float32 f0_0 = cam->mbasis.right.x * f1_0;
    float32 f1_1 = cam->mbasis.right.z * f1_0;

    cam->mat.pos.x += f0_0;
    cam->mat.pos.z += f1_1;
}

static void xCam_DampP(xCamera* cam, float32 f1, float32 f2)
{
    float32 f2_0 = f2 * (-6.0f * f1 * f2);
    float32 f0_0 = cam->mbasis.right.x * f2_0;
    float32 f2_1 = cam->mbasis.right.z * f2_0;

    cam->mat.pos.x += f0_0;
    cam->mat.pos.z += f2_1;
}

static void xCam_CorrectYaw(xCamera* cam, float32 f1, float32 f2, float32 f3)
{
    float32 f1_0 = 1.0f / cam->yaw_ct * (2.0f * cam->yaw_cd * f1 - f2 * f3);

    f1_0 -= f2;
    f1_0 *= cam->yaw_csv * f3;

    cam->yaw_cur += f1_0;
}

static void xCam_CorrectPitch(xCamera* cam, float32 f1, float32 f2, float32 f3)
{
    float32 f1_0 = 1.0f / cam->pitch_ct * (2.0f * cam->pitch_cd * f1 - f2 * f3);

    f1_0 -= f2;
    f1_0 *= cam->pitch_csv * f3;

    cam->pitch_cur += f1_0;
}

static void xCam_CorrectRoll(xCamera* cam, float32 f1, float32 f2, float32 f3)
{
    float32 f1_0 = 1.0f / cam->roll_ct * (2.0f * cam->roll_cd * f1 - f2 * f3);

    f1_0 -= f2;
    f1_0 *= cam->roll_csv * f3;

    cam->roll_cur += f1_0;
}

void SweptSphereHitsCameraEnt(xScene*, xRay3* ray, xQCData* qcd, xEnt* ent, void* data)
{
    xSweptSphere* sws = (xSweptSphere*)data;

    if (!ent->camcollModel)
    {
        return;
    }

    if (!(ent->chkby & XENT_COLLTYPE_PLYR))
    {
        return;
    }

    if (!xQuickCullIsects(qcd, &ent->bound.qcd))
    {
        return;
    }

    if (!xEntIsVisible(ent))
    {
        if (ent->model->Data != sInvisWallHack)
        {
            return;
        }

        if (ent->collLev != 5)
        {
            if (ent->bound.type == XBOUND_BOX)
            {
                xSweptSphereToBox(sws, &ent->bound.box.box, NULL);
                return;
            }
            else if (ent->bound.type == XBOUND_OBB)
            {
                xSweptSphereToBox(sws, &ent->bound.box.box, ent->bound.mat);
                return;
            }
            else
            {
                return;
            }
        }
    }

    uint32 result = FALSE;

    switch (ent->bound.type)
    {
    case XBOUND_SPH:
    {
        float32 oldrad = ent->bound.sph.r;

        ent->bound.sph.r += sws->radius;

        result = xRayHitsSphereFast(ray, &ent->bound.sph);

        ent->bound.sph.r = oldrad;

        break;
    }
    case XBOUND_BOX:
    {
        xBox tmpbox;

        tmpbox.upper.x = ent->bound.box.box.upper.x + sws->radius;
        tmpbox.upper.y = ent->bound.box.box.upper.y + sws->radius;
        tmpbox.upper.z = ent->bound.box.box.upper.z + sws->radius;
        tmpbox.lower.x = ent->bound.box.box.lower.x - sws->radius;
        tmpbox.lower.y = ent->bound.box.box.lower.y - sws->radius;
        tmpbox.lower.z = ent->bound.box.box.lower.z - sws->radius;

        result = xRayHitsBoxFast(ray, &tmpbox);

        break;
    }
    case XBOUND_OBB:
    {
        float32 f31 = xVec3Length(&ent->bound.mat->right);
        xBox tmpbox;
        xRay3 lr;
        xMat3x3 mn;

        xMat3x3Normalize(&mn, ent->bound.mat);
        xMat4x3Tolocal(&lr.origin, ent->bound.mat, &ray->origin);
        xMat3x3Tolocal(&lr.dir, &mn, &ray->dir);

        lr.max_t = ray->max_t / f31;
        lr.min_t = ray->min_t / f31;
        lr.flags = ray->flags;

        tmpbox.upper.x = ent->bound.box.box.upper.x + sws->radius / f31;
        tmpbox.upper.y = ent->bound.box.box.upper.y + sws->radius / f31;
        tmpbox.upper.z = ent->bound.box.box.upper.z + sws->radius / f31;
        tmpbox.lower.x = ent->bound.box.box.lower.x - sws->radius / f31;
        tmpbox.lower.y = ent->bound.box.box.lower.y - sws->radius / f31;
        tmpbox.lower.z = ent->bound.box.box.lower.z - sws->radius / f31;

        result = xRayHitsBoxFast(&lr, &tmpbox);

        break;
    }
    }

    if (result)
    {
        xModelInstance* collmod = ent->camcollModel;

        xSweptSphereToModel(sws, collmod->Data, collmod->Mat);
    }
}

static void _xCameraUpdate(xCamera* cam, float32 dt) STUB_VOID

void xCameraUpdate(xCamera* cam, float32 dt)
{
    int32 i;
    int32 num_updates = (int32)std::ceilf(144.0f * dt);
    float32 sdt = dt / num_updates;

    for (i = 0; i < num_updates; i++)
    {
        sCamCollis = (i == num_updates - 1);

        _xCameraUpdate(cam, sdt);
    }
}

void xCameraBegin(xCamera* cam, bool32 clear)
{
    iCameraBegin(cam->lo_cam, clear);
    iCameraFrustumPlanes(cam->lo_cam, cam->frustplane);
    iCameraUpdateFog(cam->lo_cam, 0);
}

void xCameraFXBegin(xCamera* cam)
{
    xMat4x3Identity(&sCameraFXMatOld);
    xMat4x3Copy(&sCameraFXMatOld, &cam->mat);
}

static void xCameraFXInit()
{
    memset(sCameraFX, 0, sizeof(sCameraFX));

    for (int32 i = 0; i < CAMERAFX_COUNT; i++)
    {
        sCameraFX[i].flags = 0;
    }
}

cameraFX* xCameraFXAlloc() WIP
{
    for (int32 i = 0; i < 10; i++)
    {
        cameraFX* f = &sCameraFX[i];

        if (f->flags == 0)
        {
            f->flags = CAMERAFX_ACTIVE;
            f->elapsedTime = 0.0f;
            f->maxTime = 0.0f;

            return f;
        }
    }

    return NULL;
}

void xCameraFXZoomUpdate(cameraFX* f, float32 dt, const xMat4x3*, xMat4x3* m) WIP
{
    switch (f->zoom.mode)
    {
    case CAMERAFX_ZOOM_MODE_0:
    {
        f->zoom.velCur += f->zoom.accel * dt;
        f->zoom.distanceCur += f->zoom.velCur * dt;

        if (f->zoom.distanceCur >= f->zoom.distance)
        {
            f->zoom.distanceCur = f->zoom.distance;
            f->zoom.mode = CAMERAFX_ZOOM_MODE_2;
            f->zoom.holdTimeCur = 0.0f;
        }

        xMat4x3MoveLocalAt(m, f->zoom.distanceCur);

        break;
    }
    case CAMERAFX_ZOOM_MODE_2:
    {
        f->zoom.holdTimeCur += dt;

        if (f->zoom.holdTimeCur > f->zoom.holdTime)
        {
            f->zoom.mode = CAMERAFX_ZOOM_MODE_1;
            f->zoom.distanceCur = f->zoom.distance;
            f->zoom.velCur = f->zoom.vel;
        }

        xMat4x3MoveLocalAt(m, f->zoom.distance);

        break;
    }
    case CAMERAFX_ZOOM_MODE_1:
    {
        f->zoom.velCur += f->zoom.accel * dt;
        f->zoom.distanceCur -= f->zoom.velCur * dt;

        if (f->zoom.distanceCur <= 0.0f)
        {
            f->zoom.distanceCur = 0.0f;
            f->zoom.mode = CAMERAFX_ZOOM_MODE_3;
            f->flags |= CAMERAFX_UNK0x2;
        }

        xMat4x3MoveLocalAt(m, f->zoom.distanceCur);

        break;
    }
    case CAMERAFX_ZOOM_MODE_3:
    {
        break;
    }
    }
}

void xCameraFXShake(float32 maxTime, float32 magnitude, float32 cycleMax, float32 rotate_magnitude, float32 radius, xVec3* epicenter, xVec3* player) WIP
{
    cameraFX* f = xCameraFXAlloc();

    if (!f)
    {
        return;
    }

    f->type = CAMERAFX_TYPE_SHAKE;
    f->maxTime = maxTime;
    f->shake.magnitude = magnitude;
    f->shake.dir.x = 1.0f;
    f->shake.dir.y = 1.0f;
    f->shake.cycleMax = cycleMax;
    f->shake.cycleTime = 0.0f;
    f->shake.dampen = 0.0f;
    f->shake.dampenRate = 1.0f / maxTime;
    f->shake.rotate_magnitude = rotate_magnitude;
    f->shake.radius = radius;
    f->shake.epicenterP = epicenter;

    if (f->shake.epicenterP)
    {
        f->shake.epicenter = *f->shake.epicenterP;
    }

    f->shake.player = player;
}

void xCameraFXShakeUpdate(cameraFX* f, float32 dt, const xMat4x3*, xMat4x3* m)
{
    float32 x;
    float32 y;
    float32 scale;
    float32 noise;

    f->shake.cycleTime += dt;

    while (f->shake.cycleTime > f->shake.cycleMax)
    {
        f->shake.dir.x = -f->shake.dir.x;
        f->shake.dir.y = -f->shake.dir.y;
        f->shake.cycleTime -= f->shake.cycleMax;
    }

    scale = (f->maxTime - f->elapsedTime) * f->shake.dampenRate;
    noise = (xurand() - 0.5f) * 0.1f;

    if (f->shake.radius > 0.0f && f->shake.player)
    {
        xVec3 dpos;
        xVec3Sub(&dpos, f->shake.player, &f->shake.epicenter);

        float32 dist = dpos.length();

        if (dist > f->shake.radius)
        {
            scale = 0.0f;
        }
        else
        {
            scale *= icos(dist / f->shake.radius * PI * 0.5f);
        }
    }

    x = (f->shake.magnitude + noise) * f->shake.dir.x * scale / f->shake.cycleMax * f->shake.cycleTime * isin(f->shake.cycleTime / f->shake.cycleMax * PI);
    noise = (xurand() - 0.5f) * 0.1f;
    y = (f->shake.magnitude + noise) * f->shake.dir.y * scale / f->shake.cycleMax * f->shake.cycleTime * isin(f->shake.cycleTime / f->shake.cycleMax * PI);

    xMat4x3MoveLocalRight(m, x);
    xMat4x3MoveLocalUp(m, y);

    xVec3 e;
    xMat3x3GetEuler(m, &e);

    e.z += f->shake.cycleTime / f->shake.cycleMax * xrad2deg(1.0f / 90.0f) * 0.1f * scale * f->shake.rotate_magnitude;

    xMat3x3Euler(m, &e);
}

void xCameraFXUpdate(xCamera* cam, float32 dt) WIP
{
    for (int32 i = 0; i < CAMERAFX_COUNT; i++)
    {
        cameraFX* f = &sCameraFX[i];

        if (f->flags & CAMERAFX_ACTIVE)
        {
            f->elapsedTime += dt;

            if (f->maxTime > 0.0f && (f->elapsedTime > 0.0f || f->flags & CAMERAFX_UNK0x2))
            {
                f->flags = 0;

                if (sCameraFXTable[f->type].funcKill)
                {
                    sCameraFXTable[f->type].funcKill(f);
                }
            }
            else if (sCameraFXTable[f->type].func)
            {
                sCameraFXTable[f->type].func(f, dt, &sCameraFXMatOld, &cam->mat);
            }
        }
    }

    iCameraUpdatePos(cam->lo_cam, &cam->mat);
}

void xCameraFXEnd(xCamera* cam)
{
    xMat4x3Copy(&cam->mat, &sCameraFXMatOld);
    iCameraUpdatePos(cam->lo_cam, &sCameraFXMatOld);
}

void xCameraEnd(xCamera* cam, float32 seconds, bool32 update_scrn_fx)
{
    if (update_scrn_fx)
    {
        xScrFxUpdate(cam->lo_cam, seconds);
    }

    iCameraEnd(cam->lo_cam);
}

void xCameraShowRaster(xCamera* cam)
{
    iCameraShowRaster(cam->lo_cam);
}

void xCameraSetScene(xCamera* cam, xScene* sc)
{
    cam->sc = sc;

    iCameraAssignEnv(cam->lo_cam, sc->env->geom);
}

void xCameraSetTargetMatrix(xCamera* cam, xMat4x3* mat)
{
    cam->tgt_mat = mat;
}

void xCameraSetTargetOMatrix(xCamera* cam, xMat4x3* mat)
{
    cam->tgt_omat = mat;
}

void xCameraDoCollisions(bool32 do_collis, int32 owner)
{
    xcam_collis_owner_disable &= ~(1 << owner);
    xcam_collis_owner_disable |= (int32)!do_collis << owner;
    xcam_do_collis = (xcam_collis_owner_disable == 0);
}

void xCameraMove(xCamera* cam, uint32 flags, float32 dgoal, float32 hgoal, float32 pgoal, float32 tm, float32 tm_acc, float32 tm_dec) WIP
{
    cam->flags = (cam->flags & ~XCAMERA_UNKMASK0x3E) | (flags & XCAMERA_UNKMASK0x3E);
    cam->dgoal = dgoal;
    cam->hgoal = hgoal;
    cam->pgoal = pgoal;

    if (tm <= 0.0f)
    {
        if (!cam->tgt_mat)
        {
            return;
        }

        cam->dcur = dgoal;
        cam->hcur = hgoal;
        cam->pcur = pgoal;

        xCam_cyltoworld(&cam->mat.pos, cam->tgt_mat, dgoal, hgoal, pgoal, cam->flags);

        cam->omat.pos = cam->mat.pos;
        cam->yaw_cur = cam->yaw_goal = cam->pcur + (cam->pcur >= PI ? -PI : PI);
    }
    else
    {
        cam->flags |= XCAMERA_UNK0x1;
        cam->tm_acc = tm - tm_acc;
        cam->tm_dec = tm_dec;
        cam->tmr = tm;

        float32 s = 1.0f / (tm - 0.5f * (tm_acc - tm_dec));

        cam->depv = (dgoal - cam->dcur) * s;
        cam->hepv = (hgoal - cam->hcur) * s;
        cam->pepv = xDangleClamp(pgoal - cam->pcur) * s * 0.5f * (dgoal + cam->dcur);
    }
}

void xCameraMove(xCamera* cam, const xVec3& loc)
{
    cam->omat.pos = cam->mat.pos = loc;
    cam->flags &= ~XCAMERA_UNKMASK0x3E;
    cam->tm_acc = cam->tm_dec = cam->tmr = 0.0f;
}

void xCameraMove(xCamera* cam, const xVec3& loc, float32 maxSpeed) WIP
{
    xVec3 dpos;
    xVec3Sub(&dpos, &loc, &cam->mat.pos);

    float32 dist = xVec3Length(&dpos);

    if (dist > maxSpeed)
    {
        xVec3SMul(&dpos, &dpos, maxSpeed / dist);
        xVec3Add(&cam->mat.pos, &cam->mat.pos, &dpos);
    }
    else
    {
        cam->mat.pos = loc;
    }

    cam->omat.pos = cam->mat.pos;
    cam->flags &= ~XCAMERA_UNKMASK0x3E;
    cam->tm_acc = cam->tm_dec = cam->tmr = 0.0f;
}

void xCameraFOV(xCamera* cam, float32 fov, float32 maxSpeed, float32 dt) WIP
{
    float32 speed = maxSpeed * dt;
    float32 currentFOV = xCameraGetFOV(cam);

    if (currentFOV == fov)
    {
        return;
    }

    if (speed != 0.0f)
    {
        float32 len = fov - currentFOV;

        if (xabs(len) > speed)
        {
            len *= speed / len;

            xCameraSetFOV(cam, currentFOV + len);
        }
        else
        {
            xCameraSetFOV(cam, fov);
        }
    }
    else
    {
        xCameraSetFOV(cam, fov);
    }
}

void xCameraLook(xCamera* cam, uint32 flags, const xQuat* orn_goal, float32 tm, float32 tm_acc, float32 tm_dec)
{
    cam->flags = (cam->flags & ~XCAMERA_UNKMASK0xF80) | (flags & XCAMERA_UNKMASK0xF80);
    cam->orn_goal = *orn_goal;

    if (tm <= 0.0f)
    {
        if (!cam->tgt_mat)
        {
            return;
        }

        xQuatToMat(orn_goal, &cam->mat);

        *(xMat3x3*)&cam->omat = *(xMat3x3*)&cam->mat;
    }
    else
    {
        cam->flags |= XCAMERA_UNK0x40;
        cam->ltm_acc = tm - tm_acc;
        cam->ltm_dec = tm_dec;
        cam->ltmr = tm;

        xQuatDiff(&cam->orn_diff, &cam->orn_cur, orn_goal);

        float32 s = 1.0f / (tm - (tm_acc - tm_dec) * 0.5f);

        cam->orn_epv = s * xQuatGetAngle(&cam->orn_diff);
    }
}

void xCameraLookYPR(xCamera* cam, uint32 flags, float32 yaw, float32 pitch, float32 roll, float32 tm, float32 tm_acc, float32 tm_dec) WIP
{
    cam->flags = (cam->flags & ~XCAMERA_UNKMASK0xF80) | (flags & XCAMERA_UNKMASK0xF80) | XCAMERA_UNK0x80;
    cam->yaw_goal = yaw;
    cam->pitch_goal = pitch;
    cam->roll_goal = roll;

    if (tm <= 0.0f)
    {
        if (!cam->tgt_mat)
        {
            return;
        }

        cam->yaw_cur = yaw;
        cam->pitch_cur = pitch;
        cam->roll_cur = roll;

        xMat3x3Euler(&cam->mat, yaw, pitch, roll);

        *(xMat3x3*)&cam->omat = *(xMat3x3*)&cam->mat;
    }
    else
    {
        cam->flags |= XCAMERA_UNK0x40;
        cam->ltm_acc = tm - tm_acc;
        cam->ltm_dec = tm_dec;
        cam->ltmr = tm;

        float32 s = 1.0f / (tm - (0.5f * (tm_acc - tm_dec)));

        cam->yaw_epv = s * xDangleClamp(yaw - cam->yaw_cur);
        cam->pitch_epv = s * xDangleClamp(pitch - cam->pitch_cur);
        cam->roll_epv = s * xDangleClamp(roll - cam->roll_cur);
    }
}

void xCameraRotate(xCamera* cam, const xMat3x3& m, float32 time, float32 accel, float32 decl) WIP
{
    cam->flags = cam->flags & ~XCAMERA_UNKMASK0xF80 | XCAMERA_UNK0x80;

    xVec3 eu;
    xMat3x3GetEuler(&m, &eu);

    cam->yaw_goal = eu.x;
    cam->pitch_goal = eu.y;
    cam->roll_goal = eu.z;

    if (time == 0.0f)
    {
        cam->yaw_cur = eu.x;
        cam->pitch_cur = eu.y;
        cam->roll_cur = eu.z;
    }

    *(xMat3x3*)&cam->mat = m;

    if (time == 0.0f)
    {
        *(xMat3x3*)&cam->omat = m;
    }

    if (time == 0.0f)
    {
        cam->ltm_acc = cam->ltm_dec = cam->ltmr = 0.0f;
    }
    else
    {
        cam->ltm_acc = accel;
        cam->ltm_dec = decl;
        cam->ltmr = time;
    }

    cam->yaw_epv = cam->pitch_epv = cam->roll_epv = 0.0f;
}

void xCameraRotate(xCamera* cam, const xVec3& v, float32 roll, float32 time, float32 accel, float32 decl) WIP
{
    cam->yaw_goal = xatan2(v.x, v.z);
    cam->pitch_goal = -xasin(v.y);
    cam->roll_goal = roll;

    if (time == 0.0f)
    {
        cam->yaw_cur = cam->yaw_goal;
        cam->pitch_cur = cam->pitch_goal;
        cam->roll_cur = cam->roll_goal;
    }

    cam->flags = cam->flags & ~XCAMERA_UNKMASK0xF80 | XCAMERA_UNK0x80;

    xMat3x3Euler(&cam->mat, cam->yaw_goal, cam->pitch_goal, cam->roll_goal);

    if (time == 0.0f)
    {
        *(xMat3x3*)&cam->omat = *(xMat3x3*)&cam->mat;
    }

    if (time == 0.0f)
    {
        cam->ltm_acc = cam->ltm_dec = cam->ltmr = 0.0f;
    }
    else
    {
        cam->ltm_acc = accel;
        cam->ltm_dec = decl;
        cam->ltmr = time;
    }

    cam->yaw_epv = cam->pitch_epv = cam->roll_epv = 0.0f;
}

static void bound_sphere_xz(xVec3& r3, xVec3& r4, const xVec3& r5, float32 f1, const xVec3& r6, float32 f2)
{
    float32 f31 = f1 / f2;
    float32 f3 = f31 * xsqrt(xsqr(f2) - xsqr(f1));
    float32 f5_0 = f1 * f31;
    float32 f6 = f3 * r6.x;
    float32 f4 = f3 * r6.z;
    float32 f8 = f5_0 * r6.x;
    float32 f5_1 = f5_0 * r6.z;

    r3.x = r5.x + f4 + f8;
    r3.y = r5.y;
    r3.z = r5.z - f6 + f5_1;

    r4.x = r5.x - f4 + f8;
    r4.y = r5.y;
    r4.z = r5.z + f6 + f5_1;
}

void xBinaryCamera::init()
{
    camera = NULL;
    s1 = s2 = NULL;
}

void xBinaryCamera::start(xCamera& camera)
{
    this->camera = &camera;

    xQuatFromMat(&cam_dir, &camera.mat);

    stick_offset = 0.0f;
}

void xBinaryCamera::stop()
{
    camera = NULL;
}

void xBinaryCamera::update(float32 dt) STUB_VOID