
#ifndef PRIM_H
#define PRIM_H

#include "Edge.h"
#include "PQ.h"
#include "UnionFind.h"
#include "NeighbourList.h"
#include "NeighbourMatrix.h"

// Prim's Minimal Spanning Tree Algorithm
// Both work on bidirectional representations of a graph
Edge** prim(NeighbourList** lists, int edges, int vertices, int& resultWeight);
Edge** prim(NeighbourMatrix* matrix, int edges, int vertices, int& resultWeight);

#endif
