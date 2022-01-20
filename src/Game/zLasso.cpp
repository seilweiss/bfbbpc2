#include "zLasso.h"

struct zLassoGuide
{
	xModelInstance* poly;
	xAnimState* lassoAnim;
	int32 vertMap[16];
};

void zLasso_Init(zLasso* lasso, xModelInstance* model, float32 x, float32 y, float32 z) STUB_VOID
void zLasso_AddGuide(xEnt* ent, xAnimState* lassoAnim, xModelInstance* lassoModel) STUB_VOID
void zLasso_SetGuide(xEnt* ent, xAnimState* lassoAnim) STUB_VOID
void zLasso_InterpToGuide(zLasso* lasso) STUB_VOID
void zLasso_Render(zLasso* lasso) STUB_VOID
void zLasso_Update(zLasso* lasso, xEnt* ent, float32 dt) STUB_VOID
void zLasso_InitTimer(zLasso* lasso, float32 interpTime) STUB_VOID
void zLasso_ResetTimer(zLasso* lasso, float32 interpTime) STUB_VOID
static void fizzicalRadius(zLasso*, float32, xVec3*) STUB_VOID
static void fizzicalCenter(zLasso*, float32, xVec3*) STUB_VOID
static void fizzicalNormal(zLasso*, float32, xVec3*) STUB_VOID
static void fizzicalHonda(zLasso* lasso, float32, xVec3* newPoint) STUB_VOID
static void nonfizzicalHonda(zLasso* lasso, float32, xVec3* newPoint) STUB_VOID
static void fizzicalSlack(zLasso*, float32, xVec3*) STUB_VOID
void zLasso_scenePrepare() STUB_VOID
static void initVertMap(zLassoGuide* guide) STUB_VOID
static void vec2vecMat(xMat4x3*, xVec3*, xVec3*) STUB_VOID
static void bakeMorphAnim(RpGeometry* geom, void* anim) STUB_VOID