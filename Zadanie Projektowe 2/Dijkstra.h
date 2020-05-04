
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Edge.h"
#include "PQ.h"
#include "UnionFind.h"
#include "NeighbourList.h"
#include "NeighbourMatrix.h"

int** dijkstra(NeighbourList** lists, int edges, int vertices, int start);
int** dijkstra(NeighbourMatrix* matrix, int edges, int vertices, int start);

#endif
