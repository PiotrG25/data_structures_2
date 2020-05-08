

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

