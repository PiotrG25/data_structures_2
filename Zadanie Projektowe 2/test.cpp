
#include "test.h"




void test(int baseVertices, int incrementVertices, double density) {
	testPrimList(baseVertices, incrementVertices, density);
	testPrimMatrix(baseVertices, incrementVertices, density);

	testKruskalList(baseVertices, incrementVertices, density);
	testKruskalMatrix(baseVertices, incrementVertices, density);

	testDijkstraList(baseVertices, incrementVertices, density);
	testDijkstraMatrix(baseVertices, incrementVertices, density);

	testFordBellmanList(baseVertices, incrementVertices, density);
	testFordBellmanMatrix(baseVertices, incrementVertices, density);
}

void testPrimList(int baseVertices, int incrementVertices, double density) {
	std::cout << "Prim list test for " << baseVertices << " " << incrementVertices << ' ' << std::fixed << std::setprecision(2) << density << std::endl;
	

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

		std::string txt = "Prim list.txt";
		std::cout << "Prim list " << vertices << ' ' << std::fixed << std::setprecision(2) << density << ' ' << std::fixed << std::setprecision(12) << result << std::endl;

		std::ofstream os;
		os.open(txt, std::ios::out | std::ios::app);
		os << "Prim list\t" << vertices << '\t' << std::fixed << std::setprecision(2) << density << '\t' << std::fixed << std::setprecision(12) << result << std::endl;
		os.close();
	}
}
void testPrimMatrix(int baseVertices, int incrementVertices, double density) {
	std::cout << "Prim matrix test for " << baseVertices << " " << incrementVertices << ' ' << std::fixed << std::setprecision(2) << density << std::endl;


	for (int vertices = baseVertices; vertices < baseVertices + 7 * incrementVertices; vertices += incrementVertices) {
		int samples = 100;
		double* sampleResults = new double[samples];
		int edges = vertices * (vertices - 1) / 2 * density;


		for (int i = 0; i < samples; i++) {
			Edge** graph = makeRandomGraph(edges, vertices);
			NeighbourMatrix* matrix = NeighbourMatrix::makeBidirectionalNeighbourMatrix(graph, edges, vertices);
			int resultWeight;

			auto t1 = std::chrono::high_resolution_clock::now();
			Edge** result = prim(matrix, edges, vertices, resultWeight);
			auto t2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> t = t2 - t1;
			sampleResults[i] = t.count();

			for (int j = 0; j < vertices - 1; j++) delete result[j];
			for (int j = 0; j < edges; j++) delete graph[j];
			delete[] result;
			delete matrix;
			delete[] graph;
		}

		double result = 0;
		for (int i = 0; i < samples; i++) {
			result += sampleResults[i];
		}
		result /= samples;
		delete[] sampleResults;

		std::string txt = "Prim matrix.txt";
		std::cout << "Prim matrix " << vertices << ' ' << std::fixed << std::setprecision(2) << density << ' ' << std::fixed << std::setprecision(12) << result << std::endl;

		std::ofstream os;
		os.open(txt, std::ios::out | std::ios::app);
		os << "Prim matrix\t" << vertices << '\t' << std::fixed << std::setprecision(2) << density << '\t' << std::fixed << std::setprecision(12) << result << std::endl;
		os.close();
	}
}

void testKruskalList(int baseVertices, int incrementVertices, double density) {
	std::cout << "Kruskal list test for " << baseVertices << " " << incrementVertices << ' ' << std::fixed << std::setprecision(2) << density << std::endl;


	for (int vertices = baseVertices; vertices < baseVertices + 7 * incrementVertices; vertices += incrementVertices) {
		int samples = 100;
		double* sampleResults = new double[samples];
		int edges = vertices * (vertices - 1) / 2 * density;


		for (int i = 0; i < samples; i++) {
			Edge** graph = makeRandomGraph(edges, vertices);
			NeighbourList** lists = NeighbourList::makeBidirectionalNeighbourLists(graph, edges, vertices);
			int resultWeight;

			auto t1 = std::chrono::high_resolution_clock::now();
			Edge** result = kruskal(lists, edges, vertices, resultWeight);
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

		std::string txt = "Kruskal list.txt";
		std::cout << "Kruskal list " << vertices << ' ' << std::fixed << std::setprecision(2) << density << ' ' << std::fixed << std::setprecision(12) << result << std::endl;

		std::ofstream os;
		os.open(txt, std::ios::out | std::ios::app);
		os << "Kruskal list\t" << vertices << '\t' << std::fixed << std::setprecision(2) << density << '\t' << std::fixed << std::setprecision(12) << result << std::endl;
		os.close();
	}
}
void testKruskalMatrix(int baseVertices, int incrementVertices, double density) {
	std::cout << "Kruskal matrix test for " << baseVertices << " " << incrementVertices << ' ' << std::fixed << std::setprecision(2) << density << std::endl;


	for (int vertices = baseVertices; vertices < baseVertices + 7 * incrementVertices; vertices += incrementVertices) {
		int samples = 100;
		double* sampleResults = new double[samples];
		int edges = vertices * (vertices - 1) / 2 * density;


		for (int i = 0; i < samples; i++) {
			Edge** graph = makeRandomGraph(edges, vertices);
			NeighbourMatrix* matrix = NeighbourMatrix::makeBidirectionalNeighbourMatrix(graph, edges, vertices);
			int resultWeight;

			auto t1 = std::chrono::high_resolution_clock::now();
			Edge** result = kruskal(matrix, edges, vertices, resultWeight);
			auto t2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> t = t2 - t1;
			sampleResults[i] = t.count();

			for (int j = 0; j < vertices - 1; j++) delete result[j];
			for (int j = 0; j < edges; j++) delete graph[j];
			delete[] result;
			delete matrix;
			delete[] graph;
		}

		double result = 0;
		for (int i = 0; i < samples; i++) {
			result += sampleResults[i];
		}
		result /= samples;
		delete[] sampleResults;

		std::string txt = "Kruskal matrix.txt";
		std::cout << "Kruskal matrix " << vertices << ' ' << std::fixed << std::setprecision(2) << density << ' ' << std::fixed << std::setprecision(12) << result << std::endl;

		std::ofstream os;
		os.open(txt, std::ios::out | std::ios::app);
		os << "Kruskal matrix\t" << vertices << '\t' << std::fixed << std::setprecision(2) << density << '\t' << std::fixed << std::setprecision(12) << result << std::endl;
		os.close();
	}
}

void testDijkstraList(int baseVertices, int incrementVertices, double density) {
	std::cout << "Dijkstra list test for " << baseVertices << " " << incrementVertices << ' ' << std::fixed << std::setprecision(2) << density << std::endl;


	for (int vertices = baseVertices; vertices < baseVertices + 7 * incrementVertices; vertices += incrementVertices) {
		int samples = 100;
		double* sampleResults = new double[samples];
		int edges = vertices * (vertices - 1) / 2 * density;


		for (int i = 0; i < samples; i++) {
			Edge** graph = makeRandomGraph(edges, vertices);
			NeighbourList** lists = NeighbourList::makeDirectionalNeighbourLists(graph, edges, vertices);

			auto t1 = std::chrono::high_resolution_clock::now();
			int* result = dijkstra(lists, edges, vertices, rand() % vertices);
			auto t2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> t = t2 - t1;
			sampleResults[i] = t.count();

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

		std::string txt = "Dijkstra list.txt";
		std::cout << "Dijkstra list " << vertices << ' ' << std::fixed << std::setprecision(2) << density << ' ' << std::fixed << std::setprecision(12) << result << std::endl;

		std::ofstream os;
		os.open(txt, std::ios::out | std::ios::app);
		os << "Dijkstra list\t" << vertices << '\t' << std::fixed << std::setprecision(2) << density << '\t' << std::fixed << std::setprecision(12) << result << std::endl;
		os.close();
	}
}
void testDijkstraMatrix(int baseVertices, int incrementVertices, double density) {
	std::cout << "Dijkstra matrix test for " << baseVertices << " " << incrementVertices << ' ' << std::fixed << std::setprecision(2) << density << std::endl;


	for (int vertices = baseVertices; vertices < baseVertices + 7 * incrementVertices; vertices += incrementVertices) {
		int samples = 100;
		double* sampleResults = new double[samples];
		int edges = vertices * (vertices - 1) / 2 * density;


		for (int i = 0; i < samples; i++) {
			Edge** graph = makeRandomGraph(edges, vertices);
			NeighbourMatrix* matrix = NeighbourMatrix::makeDirectionalNeighbourMatrix(graph, edges, vertices);

			auto t1 = std::chrono::high_resolution_clock::now();
			int* result = dijkstra(matrix, edges, vertices, rand() % vertices);
			auto t2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> t = t2 - t1;
			sampleResults[i] = t.count();

			for (int j = 0; j < edges; j++) delete graph[j];
			delete[] result;
			delete matrix;
			delete[] graph;
		}

		double result = 0;
		for (int i = 0; i < samples; i++) {
			result += sampleResults[i];
		}
		result /= samples;
		delete[] sampleResults;

		std::string txt = "Dijkstra matrix.txt";
		std::cout << "Dijkstra matrix " << vertices << ' ' << std::fixed << std::setprecision(2) << density << ' ' << std::fixed << std::setprecision(12) << result << std::endl;

		std::ofstream os;
		os.open(txt, std::ios::out | std::ios::app);
		os << "Dijkstra matrix\t" << vertices << '\t' << std::fixed << std::setprecision(2) << density << '\t' << std::fixed << std::setprecision(12) << result << std::endl;
		os.close();
	}
}

void testFordBellmanList(int baseVertices, int incrementVertices, double density) {
	std::cout << "Ford-Bellman list test for " << baseVertices << " " << incrementVertices << ' ' << std::fixed << std::setprecision(2) << density << std::endl;


	for (int vertices = baseVertices; vertices < baseVertices + 7 * incrementVertices; vertices += incrementVertices) {
		int samples = 100;
		double* sampleResults = new double[samples];
		int edges = vertices * (vertices - 1) / 2 * density;


		for (int i = 0; i < samples; i++) {
			Edge** graph = makeRandomGraph(edges, vertices);
			NeighbourList** lists = NeighbourList::makeDirectionalNeighbourLists(graph, edges, vertices);

			auto t1 = std::chrono::high_resolution_clock::now();
			int* result = fordBellman(lists, edges, vertices, rand() % vertices);
			auto t2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> t = t2 - t1;
			sampleResults[i] = t.count();

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

		std::string txt = "Ford-Bellman list.txt";
		std::cout << "Ford-Bellman list " << vertices << ' ' << std::fixed << std::setprecision(2) << density << ' ' << std::fixed << std::setprecision(12) << result << std::endl;

		std::ofstream os;
		os.open(txt, std::ios::out | std::ios::app);
		os << "Ford-Bellman list\t" << vertices << '\t' << std::fixed << std::setprecision(2) << density << '\t' << std::fixed << std::setprecision(12) << result << std::endl;
		os.close();
	}
}
void testFordBellmanMatrix(int baseVertices, int incrementVertices, double density) {
	std::cout << "Ford-Bellman matrix test for " << baseVertices << " " << incrementVertices << ' ' << std::fixed << std::setprecision(2) << density << std::endl;


	for (int vertices = baseVertices; vertices < baseVertices + 7 * incrementVertices; vertices += incrementVertices) {
		int samples = 100;
		double* sampleResults = new double[samples];
		int edges = vertices * (vertices - 1) / 2 * density;


		for (int i = 0; i < samples; i++) {
			Edge** graph = makeRandomGraph(edges, vertices);
			NeighbourMatrix* matrix = NeighbourMatrix::makeDirectionalNeighbourMatrix(graph, edges, vertices);

			auto t1 = std::chrono::high_resolution_clock::now();
			int* result = fordBellman(matrix, edges, vertices, rand() % vertices);
			auto t2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> t = t2 - t1;
			sampleResults[i] = t.count();

			for (int j = 0; j < edges; j++) delete graph[j];
			delete[] result;
			delete matrix;
			delete[] graph;
		}

		double result = 0;
		for (int i = 0; i < samples; i++) {
			result += sampleResults[i];
		}
		result /= samples;
		delete[] sampleResults;

		std::string txt = "Ford-Bellman matrix.txt";
		std::cout << "Ford-Bellman matrix " << vertices << ' ' << std::fixed << std::setprecision(2) << density << ' ' << std::fixed << std::setprecision(12) << result << std::endl;

		std::ofstream os;
		os.open(txt, std::ios::out | std::ios::app);
		os << "Ford-Bellman matrix\t" << vertices << '\t' << std::fixed << std::setprecision(2) << density << '\t' << std::fixed << std::setprecision(12) << result << std::endl;
		os.close();
	}
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
