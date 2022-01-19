#pragma once

#include <rwcore.h>
#include <rpcollis.h>

struct RpCollBSPBranchNode
{
	RwUInt16 type;
	RwUInt8 leftType;
	RwUInt8 rightType;
	RwUInt16 leftNode;
	RwUInt16 rightNode;
	RwReal leftValue;
	RwReal rightValue;
};

struct RpCollBSPLeafNode
{
	RwUInt16 numPolygons;
	RwUInt16 firstPolygon;
};

struct RpCollBSPTree
{
	RwUInt32 numLeafNodes;
	RpCollBSPBranchNode* branchNodes;
	RpCollBSPLeafNode* leafNodes;
	RwUInt8 pad[4];
};

struct RpV3dGradient
{
	RwReal dydx;
	RwReal dzdx;
	RwReal dxdy;
	RwReal dzdy;
	RwReal dxdz;
	RwReal dydz;
};

typedef RwBool (*RpCollBSPTreeIntersectionCallBack)(RwInt32 numTriangles, RwInt32 triOffset, void* data);