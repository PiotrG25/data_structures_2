
#ifndef MST_H
#define MST_H

#include "PQ.h"
#include "NeighbourList.h"
#include "SortedEdges.h"

// Edge* primAlgorithm(Edge* edges, int nrOfEdges, int nrOfVertices, int& resultWeight) {
Edge* primAlgorithm(NeighbourList* neighbourList, int nrOfEdges, int nrOfVertices, int& resultWeight) {
	Edge* resultEdges = new Edge[nrOfVertices - 1];

}

// Edge* kruskalAlgorithm(Edge* edges, int nrOfEdges, int nrOfVertices, int& resultWeight) {
Edge* kruskalAlgorithm(SortedEdges* sortedEdges, int nrOfEdges, int nrOfVertices, int& resultWeight) {
	Edge* resultEdges = new Edge[nrOfVertices - 1];

}

#endif