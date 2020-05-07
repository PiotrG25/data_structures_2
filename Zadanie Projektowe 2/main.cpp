

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


void printShortestPath(int** dist, int vertices);

using namespace std;

int main() {
	cout << "Hello, World!" << endl;


	int vertices, edges;
	cin >> vertices >> edges;

	Edge** arr = new Edge * [edges];
	int start, end, weight;
	for (int i = 0; i < edges; i++) {
		cin >> start >> end >> weight;
		arr[i] = new Edge(start, end, weight);
	}
	
	NeighbourList** dilists = NeighbourList::makeDirectionalNeighbourLists(arr, edges, vertices);
	printNeighbourLists(dilists, vertices);
	NeighbourMatrix* dimatrix = NeighbourMatrix::makeDirectionalNeighbourMatrix(arr, edges, vertices);
	printNeighbourMatrix(dimatrix, vertices);
	
	NeighbourList** bilists = NeighbourList::makeBidirectionalNeighbourLists(arr, edges, vertices);
	printNeighbourLists(bilists, vertices);
	NeighbourMatrix* bimatrix = NeighbourMatrix::makeBidirectionalNeighbourMatrix(arr, edges, vertices);
	printNeighbourMatrix(bimatrix, vertices);

	for (int i = 0; i < vertices; i++) {
		int** result = dijkstra(bimatrix, edges, vertices, i);
		printShortestPath(result, vertices);
		for (int j = 0; j < vertices; j++) if (result[j] != nullptr) delete result[j];
		delete[] result;
	}

	




	for (int i = 0; i < vertices; i++) {
		delete dilists[i];
		delete bilists[i];
	}
	delete[] dilists;
	delete[] bilists;
	delete dimatrix;
	delete bimatrix;
	

	return 0;
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

