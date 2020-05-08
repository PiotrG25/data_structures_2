
#include "test.h"



Edge** makeRandomGraph(int vertices, int edges) {
	
	
}

Edge** makeSpanningTree(int vertices) {

	Edge** arr = new Edge * [vertices - 1];
	int* nextVertices = makeRandomArray(vertices);

	for (int i = 1; i < vertices; i++) {
		// get random index of vertex from the tree
		int r = rand() % i;
		// connect next random vertex to the tree
		arr[i - 1] = new Edge(nextVertices[r], nextVertices[i], rand() % vertices + 1);
	}

	delete nextVertices;
	return arr;
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
