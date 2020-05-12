
#include "test.h"





void testPrimList(int baseVertices, int incrementVertices, double density) {
	std::cout << "Prim test for " << baseVertices << " " << incrementVertices << ' ' << std::fixed << std::setprecision(2) << density << std::endl;
	

	for (int vertices = baseVertices; vertices < baseVertices + 7 * incrementVertices; vertices += incrementVertices) {
		int samples = 100;
		double* sampleResults = new double[samples];
		int edges = vertices * (vertices - 1) / 2 * density;


		for (int i = 0; i < samples; i++) {
			Edge** graph = makeRandomGraph(edges, vertices);
			NeighbourList** lists = NeighbourList::makeBidirectionalNeighbourLists(graph, edges, vertices);
			int resultWeight;

			auto t1 = std::chrono::high_resolution_clock::now();
			Edge** result = prim(lists, edges, vertices, resultWeight);
			auto t2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> t = t2 - t1;
			sampleResults[i] = t.count();

			for (int j = 0; j < vertices - 1; j++) delete result[j];
			for (int j = 0; j < vertices; j++) delete lists[j];
			for (int j = 0; j < edges; j++) delete graph[j];
			delete[] result;
			delete[] lists;
			delete[] graph;
		}

		double result = 0;
		for (int i = 0; i < samples; i++) {
			result += sampleResults[i];
		}
		result /= samples;
		delete[] sampleResults;

		std::string txt = "primList.txt";
		std::cout << txt << ' ' << result << std::endl;

		std::ofstream os;
		os.open(txt, std::ios::out | std::ios::app);
		os << vertices << ' ' << std::fixed << std::setprecision(12) << result << std::endl;
		os.close();
	}
}
void testPrimMatrix(int baseVertices, int incrementVertices, double density) {

}

void testKruskalList(int baseVertices, int incrementVertices, double density) {

}
void testKruskalMatrix(int baseVertices, int incrementVertices, double density) {

}

void testDijkstraList(int baseVertices, int incrementVertices, double density) {

}
void testDijkstraMatrix(int baseVertices, int incrementVertices, double density) {

}

void testFordBellmanList(int baseVertices, int incrementVertices, double density) {

}
void testFordBellmanMatrix(int baseVertices, int incrementVertices, double density) {

}



Edge** makeRandomGraph(int edges, int vertices) {
	
	Edge** randomGraph = new Edge * [edges];
	int resultIndex = 0;

	int nrOfAllEdges = vertices * (vertices - 1) / 2;
	Edge** allEdges = new Edge * [nrOfAllEdges];              // directional or undirected
	for (int i = 0, index = 0; i < vertices; i++) {
		for (int j = i + 1; j < vertices; j++) {
			allEdges[index++] = new Edge(i, j, rand() % vertices);
		}
	}

	// start by creating of a spanning tree
	UnionFind* uf = new UnionFind(vertices);                  // uff
	int* arr = makeRandomArray(nrOfAllEdges);                 // order in which we add edges to the graph
	bool* taken = new bool[nrOfAllEdges];                     // to keep track of which edges has been added
	for (int i = 0; i < nrOfAllEdges; i++) taken[i] = false;

	for (int i = 0; i < nrOfAllEdges; i++) {
		Edge* e = allEdges[arr[i]];
		int start = e->getStart(), end = e->getEnd();

		// if they were in one union, then adding this edge would create a cycle
		if (!uf->areInOneUnion(start, end)) {
			uf->unify(start, end);
			taken[arr[i]] = true;

			randomGraph[resultIndex++] = e;
		}
	}
	delete uf;

	// spanning tree has V - 1 edges, now we take the rest
	int i = 0;
	for (int j = edges - vertices + 1; j > 0; i++) {
		if (!taken[arr[i]]) {
			randomGraph[resultIndex++] = allEdges[arr[i]];
			taken[arr[i]] = true;
			j--;
		}
	}

	// deleting untaken edges
	for (; i < nrOfAllEdges; i++) {
		if (!taken[arr[i]]) delete allEdges[arr[i]];
	}
	delete[] allEdges;
	delete[] taken;
	delete[] arr;
	
	return randomGraph;
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
