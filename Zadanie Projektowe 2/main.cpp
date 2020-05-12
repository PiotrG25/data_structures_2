

#include <iostream>

#include "Edge.h"
#include "NeighbourList.h"
#include "NeighbourMatrix.h"
#include "PQ.h"
#include "UnionFind.h"

#include "Prim.h"
#include "Kruskal.h"

#include "Dijkstra.h"
#include "Ford-Bellman.h"

#include "test.h"


void printShortestPath(int** dist, int vertices);


using namespace std;

int main() {
	cout << "Hello, World!" << endl;

	testPrimList(100, 100, 0.2);


	/*
	int vertices = 6;
	int min_edges = vertices - 1;
	int max_edges = vertices * (vertices - 1) / 2;
	for (int edges = min_edges; edges <= max_edges; edges++) {
		cout << edges << endl;
		for (int i = 0; i < 3; i++) {
			Edge** arr = makeRandomGraph(edges, vertices);
			NeighbourList** nl = NeighbourList::makeDirectionalNeighbourLists(arr, edges, vertices);
			printNeighbourLists(nl, vertices);

			for (int j = 0; j < edges; j++) delete arr[j];
			delete[] arr;
			for (int j = 0; j < vertices; j++) delete nl[j];
			delete[] nl;
		}
		cout << endl;
	}*/
	
}

void printShortestPath(int** dist, int vertices) {
	for (int i = 0; i < vertices; i++) {
		if (dist[i] == nullptr) {
			cout << "inf";
		}
		else {
			cout << *dist[i] << ' ';
		}
	}
	cout << endl;
}

