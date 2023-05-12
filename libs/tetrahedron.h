#pragma once
#include <bullet/LinearMath/btVector3.h>
#include <set>

struct TriangleFacet {
    std::vector<btVector3> vertices;
};

struct Tetrahedron {
    unsigned int VAO;
    std::set<btVector3> allSingularVertices;
    std::vector<TriangleFacet> facets;
    std::vector<float> verticesAsSingleArr;
};
