
#ifndef PRIM_H
#define PRIM_H

#include "Edge.h"
#include "PQ.h"
#include "UnionFind.h"
#include "NeighbourList.h"
#include "NeighbourMatrix.h"

Edge* prim(NeighbourList* list, int edges, int vertices, int& resultWeight);
Edge* prim(NeighbourList* list, int edges, int vertices, int& resultWeight);

#endif