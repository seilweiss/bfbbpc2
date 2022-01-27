#pragma once

#include <types.h>
#include <rwcore.h>
#include <rpworld.h>
#include <rpcollis.h>

struct xClumpCollBSPBranchNode
{
	uint32 leftInfo;
	uint32 rightInfo;
	float32 leftValue;
	float32 rightValue;
};

struct xClumpCollBSPVertInfo
{
	uint16 atomIndex;
	uint16 meshVertIndex;
};

struct xClumpCollBSPTriangle
{
	union
	{
		xClumpCollBSPVertInfo i;
		RwV3d* p;
	} v;
	uint8 flags;
	uint8 platData;
	uint16 matIndex;
};

struct xClumpCollBSPTree
{
	uint32 numBranchNodes;
	xClumpCollBSPBranchNode* branchNodes;
	uint32 numTriangles;
	xClumpCollBSPTriangle* triangles;
};

struct xClumpCollV3dGradient
{
	float32 dydx;
	float32 dzdx;
	float32 dxdy;
	float32 dzdy;
	float32 dxdz;
	float32 dydz;
};

typedef bool32(*xClumpCollBSPTreeIntersectionCallback)(xClumpCollBSPTriangle* triangles, void* data);

xClumpCollBSPTree* xClumpColl_StaticBufferInit(void* data);
void xClumpColl_InstancePointers(xClumpCollBSPTree* tree, RpClump* clump);
xClumpCollBSPTree* xClumpColl_ForAllBoxLeafNodeIntersections(xClumpCollBSPTree* tree, RwBBox* box, xClumpCollBSPTreeIntersectionCallback callBack, void* data);
xClumpCollBSPTree* xClumpColl_ForAllLineLeafNodeIntersections(xClumpCollBSPTree* tree, RwLine* line, xClumpCollV3dGradient* grad, xClumpCollBSPTreeIntersectionCallback callBack, void* data);
xClumpCollBSPTree* xClumpColl_ForAllCapsuleLeafNodeIntersections(xClumpCollBSPTree* tree, RwLine* line, float32 radius, xClumpCollV3dGradient* grad, xClumpCollBSPTreeIntersectionCallback callBack, void* data);
xClumpCollBSPTree* xClumpColl_ForAllIntersections(xClumpCollBSPTree* tree, RpIntersection* intersection, RpIntersectionCallBackWorldTriangle callBack, void* data);