
#include "Ford-Bellman.h"



int** fordBellman(NeighbourList** lists, int edges, int vertices, int start) {

	// result array holding distance from start to each vertex
	int** dist = new int*[vertices];
	for (int i = 0; i < vertices; i++) dist[i] = nullptr; // infinity
	dist[start] = new int(0);

	// relaxing each edge vertices - 1 times
	for (int i = 0; i < vertices - 1; i++) {
		// j-th list in lists and j-th vertex considered as a start
		for (int j = 0; j < vertices; j++) {
			// we cant relax edges with starting cost of infinity
			if (dist[j] == nullptr) continue;

			NeighbourList* list = lists[j];
			list->resetIterator();

			// for all edges starting with j indexed vertex
			while (list->hasNext()) {
				Edge* e = list->getNext();
				int start = e->getStart(), end = e->getEnd(), weight = e->getWeight();

				// create distance smaller than infinity
				if (dist[end] == nullptr) {
					dist[end] = new int(*dist[start] + weight);
					continue;
				}

				// relax edge
				if (*dist[start] + weight < *dist[end]) {
					*dist[end] = *dist[start] + weight;
				}
			}
		}
	}

	// check for negative cycles 
	for (int i = 0; i < vertices - 1; i++) {
		// j-th list in lists and j-th vertex considered as a start
		for (int j = 0; j < vertices; j++) {
			
			NeighbourList* list = lists[j];
			list->resetIterator();

			while (list->hasNext()) {
				Edge* e = list->getNext();
				int start = e->getStart(), end = e->getEnd(), weight = e->getWeight();

				if (dist[j] == nullptr) {
					// end vertex is affected by a negative cycle
					if (dist[end] != nullptr) {
						delete dist[end];
						dist[end] = nullptr;
					}
				}
				else {
					// end vertex if caught in a negative cycle
					if (dist[end] != nullptr && *dist[start] + weight < *dist[end]) {
						delete dist[end];
						dist[end] = nullptr;
					}
				}
			}
		}
	}

	return dist;
}

int** fordBellman(NeighbourMatrix* matrix, int edges, int vertices, int start) {
	// result array holding distance from start to each vertex
	int** dist = new int* [vertices];
	for (int i = 0; i < vertices; i++) dist[i] = nullptr; // infinity
	dist[start] = new int(0);

	// relaxing each edge vertices - 1 times
	for (int i = 0; i < vertices - 1; i++) {
		// j-th list in lists and j-th vertex considered as a start
		for (int j = 0; j < vertices; j++) {
			// we cant relax edges with starting cost of infinity
			if (dist[j] == nullptr) continue;

			// for all edges starting with j indexed vertex
			for (int k = 0; k < vertices; k++) {
				Edge* e = matrix->get(j, k);
				if (e == nullptr) continue;
				int start = e->getStart(), end = e->getEnd(), weight = e->getWeight();

				// create distance smaller than infinity
				if (dist[end] == nullptr) {
					dist[end] = new int(*dist[start] + weight);
					continue;
				}

				// relax edge
				if (*dist[start] + weight < *dist[end]) {
					*dist[end] = *dist[start] + weight;
				}
			}
		}
	}

	// check for negative cycles 
	for (int i = 0; i < vertices - 1; i++) {
		// j-th list in lists and j-th vertex considered as a start
		for (int j = 0; j < vertices; j++) {

			for (int k = 0; k < vertices; k++) {
				Edge* e = matrix->get(j, k);
				if (e == nullptr) continue;
				int start = e->getStart(), end = e->getEnd(), weight = e->getWeight();

				if (dist[j] == nullptr) {
					// end vertex is affected by a negative cycle
					if (dist[end] != nullptr) {
						delete dist[end];
						dist[end] = nullptr;
					}
				}
				else {
					// end vertex if caught in a negative cycle
					if (dist[end] != nullptr && *dist[start] + weight < *dist[end]) {
						delete dist[end];
						dist[end] = nullptr;
					}
				}
			}
		}
	}

	return dist;
}