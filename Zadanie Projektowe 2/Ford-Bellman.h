
#ifndef FORD_BELLMAN_H
#define FORD_BELLMAN_H

#define PLUS_INF 2147483647
#define MINUS_INF -2147483648

#include "Edge.h"
#include "PQ.h"
#include "UnionFind.h"
#include "NeighbourList.h"
#include "NeighbourMatrix.h"


// Ford-Bellman's Shortest Path Finding Algorithm
// Both work on directional representations of a graph
int* fordBellman(NeighbourList** lists, int edges, int vertices, int start);
int* fordBellman(NeighbourMatrix* matrix, int edges, int vertices, int start);


#endif
