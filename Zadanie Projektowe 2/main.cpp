

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

	

	return 0;
}

