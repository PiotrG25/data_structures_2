
#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <fstream>

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


void testPrimList(int baseVertices, int incrementVertices, double density);
void testPrimMatrix(int baseVertices, int incrementVertices, double density);

void testKruskalList(int baseVertices, int incrementVertices, double density);
void testKruskalMatrix(int baseVertices, int incrementVertices, double density);

void testDijkstraList(int baseVertices, int incrementVertices, double density);
void testDijkstraMatrix(int baseVertices, int incrementVertices, double density);

void testFordBellmanList(int baseVertices, int incrementVertices, double density);
void testFordBellmanMatrix(int baseVertices, int incrementVertices, double density);

#endif
