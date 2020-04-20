
#ifndef NEIGHBOUR_MATRIX_H
#define NEIGHBOUR_MATRIX_H

#include <iostream>
#include <iomanip>

#include "Edge.h"


class NeighbourMatrix {

	int vertices;
	Edge** arr;

public:

	NeighbourMatrix(int vertices);
	~NeighbourMatrix();

	Edge* get(int i, int j);
	void set(int i, int j, Edge* e);
};


// Makes Neighbour Matrix with copies of edges from the array
NeighbourMatrix* makeNeighbourMatrix(Edge** arr, int edges, int vertices);

void printNeighbourMatrix(NeighbourMatrix* matrix, int vertices);

#endif

