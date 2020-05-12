
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Edge.h"
#include "PQ.h"
#include "UnionFind.h"
#include "NeighbourList.h"
#include "NeighbourMatrix.h"

// structure used only in Dijkstra's Algorithm
struct VertexDistance {
	int vertex, distance;

	VertexDistance(int vertex, int distance);

	bool operator > (VertexDistance& vd);
};

typedef PQ<VertexDistance> VertexDistancePQ;


// Dijkstra's Shortest Path Finding Algorithm
// Both work on directional representations of a graph
int** dijkstra(NeighbourList** lists, int edges, int vertices, int start);
int** dijkstra(NeighbourMatrix* matrix, int edges, int vertices, int start);

#endif
