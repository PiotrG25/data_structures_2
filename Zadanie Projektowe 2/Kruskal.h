
#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "Edge.h"
#include "PQ.h"
#include "UnionFind.h"
#include "NeighbourList.h"
#include "NeighbourMatrix.h"

// Kruskal's Minimal Spanning Tree Algorithm
// Both work on bidirectional representations of a graph
Edge** kruskal(NeighbourList** lists, int edges, int vertices, int& resultWeight);
Edge** kruskal(NeighbourMatrix* matrix, int edges, int vertices, int& resultWeight);

#endif

