#include "xClumpColl.h"

xClumpCollBSPTree* xClumpColl_StaticBufferInit(void* data) STUB
void xClumpColl_InstancePointers(xClumpCollBSPTree* tree, RpClump* clump) STUB_VOID
xClumpCollBSPTree* xClumpColl_ForAllBoxLeafNodeIntersections(xClumpCollBSPTree* tree, RwBBox* box, xClumpCollBSPTreeIntersectionCallback callBack, void* data) STUB
xClumpCollBSPTree* xClumpColl_ForAllLineLeafNodeIntersections(xClumpCollBSPTree* tree, RwLine* line, xClumpCollV3dGradient* grad, xClumpCollBSPTreeIntersectionCallback callBack, void* data) STUB
xClumpCollBSPTree* xClumpColl_ForAllCapsuleLeafNodeIntersections(xClumpCollBSPTree* tree, RwLine* line, float32 radius, xClumpCollV3dGradient* grad, xClumpCollBSPTreeIntersectionCallback callBack, void* data) STUB
static bool32 LeafNodeLinePolyIntersect(xClumpCollBSPTriangle* triangles, void* data) STUB
static bool32 LeafNodeSpherePolyIntersect(xClumpCollBSPTriangle* triangles, void* data) STUB
static bool32 LeafNodeBoxPolyIntersect(xClumpCollBSPTriangle* triangles, void* data) STUB
xClumpCollBSPTree* xClumpColl_ForAllIntersections(xClumpCollBSPTree* tree, RpIntersection* intersection, RpIntersectionCallBackWorldTriangle callBack, void* data) STUB