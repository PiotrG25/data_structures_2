
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
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			if (arr[i * vertices + j] != nullptr) delete arr[i * vertices + j];
		}
	}
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


NeighbourMatrix* NeighbourMatrix::makeBidirectionalNeighbourMatrix(Edge** arr, int edges, int vertices) {
	NeighbourMatrix* matrix = new NeighbourMatrix(vertices);

	// Copying edges into matrix
	for (int i = 0; i < edges; i++) {
		// Undirected graph will be now bidirectional

		Edge* e1 = arr[i]->copy();
		Edge* e2 = arr[i]->copy();
		e2->reverse();

		matrix->set(e1->getStart(), e1->getEnd(), e1);
		matrix->set(e2->getStart(), e2->getEnd(), e2);
	}

	return matrix;
}

NeighbourMatrix* NeighbourMatrix::makeDirectionalNeighbourMatrix(Edge** arr, int edges, int vertices) {
	NeighbourMatrix* matrix = new NeighbourMatrix(vertices);

	// Copying edges into matrix
	for (int i = 0; i < edges; i++) {
		Edge* e = arr[i]->copy();
		matrix->set(e->getStart(), e->getEnd(), e);
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

