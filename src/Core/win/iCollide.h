#pragma once

#include "xCollide.h"

void iCollideInit(xScene*);
bool32 PointWithinTriangle(xVec3* _pt, xVec3** _tri, xVec3* _normal);
void FindNearestPointOnLine(xVec3* _result, xVec3* _point, xVec3* _start, xVec3* _end);
RpCollisionTriangle* sphereHitsEnvCB(RpIntersection* isx, RpWorldSector*, RpCollisionTriangle* tri, RwReal dist, void* data);
uint32 iSphereHitsEnv(const xSphere* b, const xEnv* env, xCollis* coll);
int32 iSphereHitsEnv3(const xSphere* b, const xEnv* env, xCollis* colls, uint8 ncolls, float32 sth);
int32 iSphereHitsEnv4(const xSphere* b, const xEnv* env, const xMat3x3* mat, xCollis* colls);
int32 iSphereHitsModel3(const xSphere* b, const xModelInstance* m, xCollis* colls, uint8 ncolls, float32 sth);
uint32 iRayHitsEnv(const xRay3* r, const xEnv* env, xCollis* coll);
uint32 iRayHitsModel(const xRay3* r, const xModelInstance* m, xCollis* coll);
void iSphereForModel(xSphere* o, const xModelInstance* m);
void iBoxForModel(xBox* o, const xModelInstance* m);
void iBoxForModelLocal(xBox* o, const xModelInstance* m);