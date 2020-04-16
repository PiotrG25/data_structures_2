
#ifndef EDGES_H
#define EDGES_H

class Edges {
	int nrOfEdges, nrOfVertices;
	Edge* edges;

public:
	Edges(int nrOfEdges, int nrOfVertices, Edge* edges);

	// getMatrixRepresentation();
	// getListRepresentation();
};

class Edge {
	int start, end, weight;
public:
	Edge() {}
	Edge(int start, int end, int weight);

	int getStart();
	int getEnd();
	int getWeight();
};

#endif

