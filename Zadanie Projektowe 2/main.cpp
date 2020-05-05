

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

	NeighbourList** lists = NeighbourList::makeBidirectionalNeighbourLists(arr, edges, vertices);
	printNeighbourLists(lists, vertices);
	NeighbourMatrix* matrix = NeighbourMatrix::makeBidirectionalNeighbourMatrix(arr, edges, vertices);
	printNeighbourMatrix(matrix, vertices);

	dijkstra(lists, edges, vertices, 0);

	
	/*
	int resultWeight = 0;
	Edge** result = kruskal(lists, edges, vertices, resultWeight);

	cout << "result: " << resultWeight << endl;
	lists = NeighbourList::makeBidirectionalNeighbourLists(result, vertices - 1, vertices);
	printNeighbourLists(lists, vertices);
	matrix = NeighbourMatrix::makeBidirectionalNeighbourMatrix(result, vertices - 1, vertices);
	printNeighbourMatrix(matrix, vertices);

	for (int i = 0; i < vertices - 1; i++) delete result[i];
	delete result;
	*/
	/*
	for (int i = 0; i < vertices; i++) {
		int* result = dijkstra(lists, edges, vertices, i);
		for (int i = 0; i < vertices; i++) {
			cout << result[i] << ' ';
		}
		cout << endl;
		delete[] result;

		result = dijkstra(matrix, edges, vertices, i);
		for (int i = 0; i < vertices; i++) {
			cout << result[i] << ' ';
		}
		cout << endl;
		delete[] result;

		cout << endl;
	}
	*/


	for (int i = 0; i < vertices; i++) delete lists[i];
	delete[] lists;
	delete matrix;
	

	return 0;
}

