
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

NeighbourMatrix::~NeighbourMatrix() {
	delete[] arr;
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
		// Undirected graph will be now two-directioned

		Edge* e1 = arr[i]->copy();
		Edge* e2 = arr[i]->copy();
		e2->reverse();

		matrix->set(e1->getStart(), e1->getEnd(), e1);
		matrix->set(e2->getStart(), e2->getEnd(), e2);
	}

	return matrix;
}

void printNeighbourMatrix(NeighbourMatrix* matrix, int vertices) {
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			Edge* e = matrix->get(i, j);
			if (e == nullptr) {
				std::cout << std::setw(3) << "inf" << ' ';
			}
			else {
				std::cout << std::setw(3) << e->getWeight() << ' ';
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

