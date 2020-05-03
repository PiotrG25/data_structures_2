

#include "Kruskal.h"


Edge** kruskal(NeighbourList* lists, int edges, int vertices, int& resultWeight) {
	return nullptr;
}

Edge** kruskal(NeighbourMatrix* matrix, int edges, int vertices, int& resultWeight) {
	Edge** result = new Edge * [vertices - 1];
	int resultIndex = 0; // used for placing result edges in result array
	resultWeight = 0; // weight of result spannig tree

	PQ* pq = new PQ(2 * edges);
	UnionFind* uf = new UnionFind(vertices);

	Edge* e; // pointer for current Edge

	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			e = matrix->get(i, j);
			if (e != nullptr) pq->enqueue(e);
		}
	}

	while (!uf->isOneUnion()) {
		e = pq->dequeue();

		if (!uf->areInOneUnion(e->getStart(), e->getEnd())) {
			uf->unify(e->getStart(), e->getEnd());
			result[resultIndex++] = e->copy();
			resultWeight += e->getWeight();
		}
	}

	return result;
}
