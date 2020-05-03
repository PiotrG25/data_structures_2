

#include "Kruskal.h"


Edge** kruskal(NeighbourList** lists, int edges, int vertices, int& resultWeight) {
	Edge** result = new Edge * [vertices - 1];
	int resultIndex = 0; // used for placing result edges in result array
	resultWeight = 0; // weight of result spannig tree

	PQ* pq = new PQ(2 * edges);
	UnionFind* uf = new UnionFind(vertices);

	Edge* e; // pointer for current Edge

	// copying pointers of edges to PQ
	for (int i = 0; i < vertices; i++) {
		lists[i]->resetIterator();
		while (lists[i]->hasNext()) pq->enqueue(lists[i]->getNext());
	}

	// unifying until there is only one union
	while (!uf->isOneUnion()) {
		e = pq->dequeue();
		int start = e->getStart(), end = e->getEnd(), weight = e->getWeight();

		// if vertices indexed by start and end are not connected yet
		// adding edge to the result
		// and increasing value of the weight of the result spanning tree
		if (!uf->areInOneUnion(start, end)) {
			uf->unify(start, end);
			result[resultIndex++] = e->copy();
			resultWeight += e->getWeight();
		}
	}
	
	return result;
}

Edge** kruskal(NeighbourMatrix* matrix, int edges, int vertices, int& resultWeight) {
	Edge** result = new Edge * [vertices - 1];
	int resultIndex = 0; // used for placing result edges in result array
	resultWeight = 0; // weight of result spannig tree

	PQ* pq = new PQ(2 * edges);
	UnionFind* uf = new UnionFind(vertices);

	Edge* e; // pointer for current Edge

	// copying pointers of edges to PQ
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			e = matrix->get(i, j);
			if (e != nullptr) pq->enqueue(e);
		}
	}

	// unifying until there is only one union
	while (!uf->isOneUnion()) {
		e = pq->dequeue();
		int start = e->getStart(), end = e->getEnd(), weight = e->getWeight();

		// if vertices indexed by start and end are not connected yet
		// adding edge to the result
		// and increasing value of the weight of the result spanning tree
		if (!uf->areInOneUnion(start, end)) {
			uf->unify(start, end);
			result[resultIndex++] = e->copy();
			resultWeight += e->getWeight();
		}
	}

	return result;
}
