
#ifndef FORD_BELLMAN_H
#define FORD_BELLMAN_H

#include "Edge.h"
#include "PQ.h"
#include "UnionFind.h"
#include "NeighbourList.h"
#include "NeighbourMatrix.h"


int** fordBellman(NeighbourList** lists, int edges, int vertices, int start);
int** fordBellman(NeighbourMatrix* matrix, int edges, int vertices, int start);


#endif
