
#include "test.h"


int* makeRandomArray(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) arr[i] = i;
	
	int len = size;
	for (int i = 0; i < size; i++) {
		int r = rand() % len + i;

		int t = arr[r];
		arr[r] = arr[i];
		arr[i] = t;

		len--;
	}

	return arr;
}

Edge** makeRandomGraph(int vertices, double edges) {

	Edge** arr = new Edge * [edges];
	int arrIndex = 0;

	// create spanning tree
	UnionFind* uf = new UnionFind(vertices);
	int* nextVertices = makeRandomArray(vertices);
	while (!uf->isOneUnion()) {
		// index of next vertex
		int mod = vertices - uf->getNumberOfSubgroups() + 1;
		// get random vertex from the tree
		int r = rand() % mod;
		// connect next random vertex to the tree
		uf->unify(r, nextVertices[mod]);
		arr[arrIndex++] = new Edge(r, nextVertices[mod], rand() % vertices + 1);
	}


	return arr;
}
