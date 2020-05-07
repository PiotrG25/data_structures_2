

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
	/*
	NeighbourList** lists = NeighbourList::makeDirectionalNeighbourLists(arr, edges, vertices);
	printNeighbourLists(lists, vertices);
	NeighbourMatrix* matrix = NeighbourMatrix::makeDirectionalNeighbourMatrix(arr, edges, vertices);
	printNeighbourMatrix(matrix, vertices);
	*/
	
	NeighbourList** lists = NeighbourList::makeBidirectionalNeighbourLists(arr, edges, vertices);
	printNeighbourLists(lists, vertices);
	NeighbourMatrix* matrix = NeighbourMatrix::makeBidirectionalNeighbourMatrix(arr, edges, vertices);
	printNeighbourMatrix(matrix, vertices);

	for (int i = 0; i < vertices; i++) {
		int** result = fordBellman(matrix, edges, vertices, i);

		for (int j = 0; j < vertices; j++) {
			cout << *result[j] << ' ';
		}
		cout << endl;

		for (int j = 0; j < vertices; j++) delete result[j];
		delete[] result;
	}

	


	for (int i = 0; i < vertices; i++) delete lists[i];
	delete[] lists;
	delete matrix;
	

	return 0;
}

