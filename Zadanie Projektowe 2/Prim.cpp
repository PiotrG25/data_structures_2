

#include "Prim.h"


Edge** prim(NeighbourList** lists, int edges, int vertices, int& resultWeight) {
	Edge** result = new Edge * [vertices - 1];
	int resultIndex = 0; // used for placing result edges in result array
	resultWeight = 0; // weight of result spannig tree

	PQ* pq = new PQ(2 * edges);
	UnionFind* uf = new UnionFind(vertices);

	for (int i = 0; i < vertices; i++) lists[i]->resetIterator();
	while (lists[0]->hasNext()) pq->enqueue(lists[0]->getNext());

	Edge* e; // pointer for current Edge

	while (!uf->isOneUnion()) {
		e = pq->dequeue();
		int start = e->getStart(), end = e->getEnd(), weight = e->getWeight();

		if (!uf->areInOneUnion(start, end)) {
			uf->unify(start, end);
			result[resultIndex++] = e->copy();
			resultWeight += weight;

			while (lists[end]->hasNext()) pq->enqueue(lists[end]->getNext());
		}
	}

	delete pq;
	delete uf;

	return result;
}

Edge** prim(NeighbourMatrix* matrix, int edges, int vertices, int& resultWeight) {
	Edge** result = new Edge * [vertices - 1];
	int resultIndex = 0; // used for placing result edges in result array
	resultWeight = 0; // weight of result spannig tree

	PQ* pq = new PQ(2 * edges);
	UnionFind* uf = new UnionFind(vertices);

	Edge* e; // pointer for current Edge

	for (int i = 0; i < vertices; i++) {
		e = matrix->get(0, i);
		if (e != nullptr) pq->enqueue(e);
	}

	while (!uf->isOneUnion()) {
		e = pq->dequeue();
		int start = e->getStart(), end = e->getEnd(), weight = e->getWeight();

		if (!uf->areInOneUnion(start, end)) {
			uf->unify(start, end);
			result[resultIndex++] = e->copy();
			resultWeight += weight;

			for (int i = 0; i < vertices; i++) {
				e = matrix->get(end, i);
				if (e != nullptr) pq->enqueue(e);
			}
		}
	}

	delete pq;
	delete uf;

	return result;
}

