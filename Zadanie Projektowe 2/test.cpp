
#include "test.h"



Edge** makeRandomGraph(int edges, int vertices) {
	
	Edge** randomGraph = new Edge * [edges];
	int resultIndex = 0;

	int nrOfAllEdges = vertices * (vertices - 1) / 2;
	Edge** allEdges = new Edge * [nrOfAllEdges];              // directional or undirected
	for (int i = 0, index = 0; i < vertices; i++) {
		for (int j = i + 1; j < vertices; j++) {
			allEdges[index++] = new Edge(i, j, rand() % vertices);
		}
	}

	// start by creating of a spanning tree
	UnionFind* uf = new UnionFind(vertices);                  // uff
	int* arr = makeRandomArray(nrOfAllEdges);                 // order in which we add edges to the graph
	bool* taken = new bool[nrOfAllEdges];                     // to keep track of which edges has been added
	for (int i = 0; i < nrOfAllEdges; i++) taken[i] = false;

	for (int i = 0; i < nrOfAllEdges; i++) {
		Edge* e = allEdges[arr[i]];
		int start = e->getStart(), end = e->getEnd();

		// if they were in one union, then adding this edge would create a cycle
		if (!uf->areInOneUnion(start, end)) {
			uf->unify(start, end);
			taken[arr[i]] = true;

			randomGraph[resultIndex++] = e;
		}
	}
	delete uf;

	// spanning tree has V - 1 edges, now we take the rest
	int i = 0;
	for (int j = edges - vertices + 1; j > 0; i++) {
		if (!taken[arr[i]]) {
			randomGraph[resultIndex++] = allEdges[arr[i]];
			taken[arr[i]] = true;
			j--;
		}
	}

	// deleting untaken edges
	for (; i < nrOfAllEdges; i++) {
		if (!taken[arr[i]]) delete allEdges[arr[i]];
	}
	delete[] allEdges;
	delete[] taken;
	delete[] arr;
	
	return randomGraph;
}

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
