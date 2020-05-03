
#ifndef NEIGHBOUR_MATRIX_H
#define NEIGHBOUR_MATRIX_H

#include <iostream>
#include <iomanip>

#include "Edge.h"


class NeighbourMatrix {

	// number of vertices
	int vertices;
	Edge** arr;

	NeighbourMatrix(int vertices);

	// sets pointer in array to point to Edge e
	void set(int i, int j, Edge* e);

public:

	~NeighbourMatrix();

	// Makes Neighbour Matrix with copies of edges from the array
	static NeighbourMatrix* makeNeighbourMatrix(Edge** arr, int edges, int vertices);

	// returns pointer to edge at designated position
	Edge* get(int i, int j);
};

// prints matrix of edges as matrix (vertices + 1) x (vertices + 1)
// where upper row and left column are indexes of from and to vertices
// each cell contains the weight of edge between them
// 'inf' if edge does not exist
void printNeighbourMatrix(NeighbourMatrix* matrix, int vertices);

#endif

