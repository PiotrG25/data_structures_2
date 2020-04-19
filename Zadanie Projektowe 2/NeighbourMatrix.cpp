
#include "NeighbourMatrix.h"


NeighbourMatrix::NeighbourMatrix(int vertices) {
	this->vertices = vertices;
	this->arr = new Edge*[vertices * vertices];

	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			arr[i * vertices + j] = nullptr;
		}
	}
}


Edge* NeighbourMatrix::get(int i, int j) {
	if (i < 0 || j < 0 || i >= vertices || j >= vertices) return nullptr;
	return arr[vertices * i + j];
}

void NeighbourMatrix::set(int i, int j, Edge* e) {
	if (i < 0 || j < 0 || i >= vertices || j >= vertices) return;
	arr[i * vertices + j] = e;
}


NeighbourMatrix* makeNeighbourMatrix(Edge** arr, int edges, int vertices) {
	NeighbourMatrix* matrix = new NeighbourMatrix(vertices);

	for (int i = 0; i < edges; i++) {
		// duplicating Edges
		// and converting undirected graph into two-directioned
		Edge* e = arr[i];
		Edge* e1 = new Edge(e->getStart(), e->getEnd(), e->getWeight());
		Edge* e2 = new Edge(e->getEnd(), e->getStart(), e->getWeight());

		matrix->set(e1->getStart(), e1->getEnd(), e1);
		matrix->set(e2->getStart(), e2->getEnd(), e2);
	}

	return matrix;
}
