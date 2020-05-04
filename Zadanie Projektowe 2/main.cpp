

#include <iostream>

#include "Edge.h"
#include "NeighbourList.h"
#include "NeighbourMatrix.h"
#include "PQ.h"
#include "UnionFind.h"

#include "Prim.h"
#include "Kruskal.h"


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


	int resultWeight = 0;
	Edge** result = kruskal(lists, edges, vertices, resultWeight);

	for (int i = 0; i < vertices; i++) delete lists[i];
	delete[] lists;
	delete matrix;

	cout << "result: " << resultWeight << endl;

	lists = NeighbourList::makeBidirectionalNeighbourLists(result, vertices - 1, vertices);
	printNeighbourLists(lists, vertices);
	matrix = NeighbourMatrix::makeBidirectionalNeighbourMatrix(result, vertices - 1, vertices);
	printNeighbourMatrix(matrix, vertices);

	for (int i = 0; i < vertices; i++) delete lists[i];
	delete[] lists;
	delete matrix;
	

	return 0;
}

