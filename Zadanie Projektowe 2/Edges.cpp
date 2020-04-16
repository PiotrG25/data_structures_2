
#include "Edges.h"

Edges::Edges(int nrOfEdges, int nrOfVertices, Edge* edges) {
	this->nrOfEdges = nrOfEdges;
	this->nrOfVertices = nrOfVertices;
	this->edges = new Edge[nrOfEdges];
	for (int i = 0; i < nrOfEdges; i++) this->edges[i] = edges[i];
}

// Edges::getMatrixRepresentation();
// Edges::getListRepresentation();



Edge::Edge(int start, int end, int weight) {
	this->start = start;
	this->end = end;
	this->weight = weight;
}

int Edge::getStart() { return start; }
int Edge::getEnd() { return end; }
int Edge::getWeight() { return weight; }