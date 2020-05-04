
#include "Dijkstra.h"


int** dijkstra(NeighbourList** lists, int edges, int vertices, int start) {

	// result array holding distance from start to each vertex
	// nullptr if that value is infinity
	int** result = new int* [vertices];
	for (int i = 0; i < vertices; i++) result[i] = nullptr;

	EdgePQ* pq = new EdgePQ(edges);

	// distance to the start
	result[start] = new int(0);

	// copying pointers to edges beginning at start vertex
	while (lists[start]->hasNext()) {
		Edge* e = lists[start]->getNext();
		pq->enqueue(e);
	}



	delete pq;

	return result;
}

int** dijkstra(NeighbourMatrix* matrix, int edges, int vertices, int start) {
	return nullptr;
}


