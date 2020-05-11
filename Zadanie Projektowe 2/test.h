
#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <cstdlib>

#include "Edge.h"
#include "NeighbourList.h"
#include "NeighbourMatrix.h"
#include "PQ.h"
#include "UnionFind.h"

#include "Prim.h"
#include "Kruskal.h"

#include "Dijkstra.h"
#include "Ford-Bellman.h"


int* makeRandomArray(int size);

Edge** makeRandomGraph(int edges, int vertices);

#endif
