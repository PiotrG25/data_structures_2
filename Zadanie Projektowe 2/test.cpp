
#include "test.h"



Edge** makeRandomGraph(int vertices, int edges) {
	
	Edge** allEdges = new Edge * [vertices * (vertices - 1)];
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < i; j++) {
			allEdges[i * vertices + j] = new Edge(i, j, )
		}
	}

	// start by creating of a spanning tree

	
	
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
