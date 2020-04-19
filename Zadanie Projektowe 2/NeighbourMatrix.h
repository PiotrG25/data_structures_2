
#ifndef NEIGHBOUR_MATRIX_H
#define NEIGHBOUR_MATRIX_H


#include "Edge.h"


class NeighbourMatrix {

	int vertices;
	Edge** arr;

public:

	NeighbourMatrix(int vertices);

	Edge* get(int i, int j);
	void set(int i, int j, Edge* e);
};


NeighbourMatrix* makeNeighbourMatrix(Edge** arr, int edges, int vertices);

#endif

