

#include "Prim.h"


Edge** prim(NeighbourList** lists, int edges, int vertices, int& resultWeight) {
	Edge** result = new Edge * [vertices - 1];
	int resultIndex = 0;
	resultWeight = 0;
	PQ* pq = new PQ(2 * edges);
	UnionFind* uf = new UnionFind(vertices);

	for (int i = 0; i < vertices; i++) lists[i]->resetIterator();
	while (lists[0]->hasNext()) pq->enqueue(lists[0]->getNext());


	while (!uf->isOneUnion()) {
		Edge* e = pq->dequeue();
		int start = e->getStart(), end = e->getEnd(), weight = e->getWeight();

		if (!uf->areInOneUnion(start, end)) {
			uf->unify(start, end);
			result[resultIndex++] = e;
			resultWeight += weight;

			while (lists[end]->hasNext()) pq->enqueue(lists[end]->getNext());
		}
	}

	delete pq;
	delete uf;

	return result;
}

Edge** prim(NeighbourMatrix* matrix, int edges, int vertices, int& resultWeight) {
	return nullptr;
}

