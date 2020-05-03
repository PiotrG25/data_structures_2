
#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "Edge.h"
#include "PQ.h"
#include "UnionFind.h"
#include "NeighbourList.h"
#include "NeighbourMatrix.h"

Edge** kruskal(NeighbourList* lists, int edges, int vertices, int& resultWeight);
Edge** kruskal(NeighbourMatrix* matrix, int edges, int vertices, int& resultWeight);

#endif

