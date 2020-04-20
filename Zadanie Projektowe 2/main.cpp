

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

	NeighbourList** lists = makeNeighbourLists(arr, edges, vertices);
	printNeighbourLists(lists, vertices);
	NeighbourMatrix* matrix = makeNeighbourMatrix(arr, edges, vertices);
	printNeighbourMatrix(matrix, vertices);


	int resultWeight = 0;
	Edge** result = prim(lists, edges, vertices, resultWeight);

	cout << "result:" << endl;

	delete lists;
	delete matrix;

	cout << "result:" << endl;

	lists = makeNeighbourLists(result, edges, vertices);
	printNeighbourLists(lists, vertices);
	matrix = makeNeighbourMatrix(result, edges, vertices);
	printNeighbourMatrix(matrix, vertices);

	return 0;
}

