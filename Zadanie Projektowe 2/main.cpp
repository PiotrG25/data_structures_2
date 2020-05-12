

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

using namespace std;

void printShortestPath(int** dist, int vertices);

Edge** readMSTFromFile(int& edges, int& vertices);
Edge** readShortestPathFromFile(int& edges, int& vertices, int& start);
Edge** readMSTMaxFlowFile(int& edges, int& vertices, int& start, int& end);

void doMST();
void doShortestPath();
void doMaxFlow();

int main() {
	cout << "Hello, World!" << endl;

	string menu = "\
		\r[0] - zakoncz program\n\
		\r[1] - wyznaczanie minimalnego drzewa rozpinajacego\n\
		\r[2] - wyznaczanie najkrotszej sciezki w grafie\n\
		\r\
		";
	int choice;
	do {
		cout << menu << endl;
		cin >> choice;
		if (choice == 1) {
			doMST();
		}
		else if (choice == 2) {
			doShortestPath();
		}
		else if (choice == 3) {
			doMaxFlow();
		}
	} while (choice != 0);
}


void doMST() {
	string menu = "\
		\r[0] - zakoncz\n\
		\r[1] - wczytaj z pliku\n\
		\r[2] - wygeneruj graf losowo\n\
		\r[3] - wyswietl listowo i macierzowo na ekranie\n\
		\r[4] - Algorytm Prima\n\
		\r[5] - Algorytm Kruskala\n\
		";
	Edge** arr = nullptr;
	NeighbourList** lists = nullptr;
	NeighbourMatrix* matrix = nullptr;
	int edges = 0, vertices = 0;

	Edge** result;
	int resultWeight;

	int choice;
	do {
		cout << menu << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			if (arr != nullptr) {
				for (int i = 0; i < edges; i++) delete arr[i];
				delete[] arr;
			}

			arr = readMSTFromFile(edges, vertices);
			lists = NeighbourList::makeBidirectionalNeighbourLists(arr, edges, vertices);
			matrix = NeighbourMatrix::makeBidirectionalNeighbourMatrix(arr, edges, vertices);
			break;
		case 2:
			if (arr != nullptr) {
				for (int i = 0; i < edges; i++) delete arr[i];
				delete[] arr;
			}

			double density;
			cout << "Podaj ilosc wierzcholkow i gestosc" << endl;
			cin >> vertices >> density;
			edges = vertices * (vertices - 1) / 2 * density;
			arr = makeRandomGraph(edges, vertices);
			lists = NeighbourList::makeBidirectionalNeighbourLists(arr, edges, vertices);
			matrix = NeighbourMatrix::makeBidirectionalNeighbourMatrix(arr, edges, vertices);
			break;
		case 3:
			if (arr == nullptr) {
				cout << "BRAK GRAFU!!!" << endl;
				break;
			}
			printNeighbourLists(lists, vertices);
			printNeighbourMatrix(matrix, vertices);
			break;
		case 4:
			if (arr == nullptr) {
				cout << "BRAK GRAFU!!!" << endl;
				break;
			}

			result = prim(lists, edges, vertices, resultWeight);
			cout << "Wynik algorytmu Prima dla reprezentacji listowej: " << resultWeight << endl;
			for (int i = 0; i < edges; i++) {
				cout << result[i]->getStart() << ' ' << result[i]->getEnd() << ' ' << result[i]->getWeight() << endl;
				delete result[i];
			}
			cout << endl;
			delete[] result;

			result = prim(matrix, edges, vertices, resultWeight);
			cout << "Wynik algorytmu Prima dla reprezentacji macierzowej: " << resultWeight << endl;
			for (int i = 0; i < edges; i++) {
				cout << result[i]->getStart() << ' ' << result[i]->getEnd() << ' ' << result[i]->getWeight() << endl;
				delete result[i];
			}
			cout << endl;
			delete[] result;
			break;
		case 5:
			if (arr == nullptr) {
				cout << "BRAK GRAFU!!!" << endl;
				break;
			}

			result = kruskal(lists, edges, vertices, resultWeight);
			cout << "Wynik algorytmu Kruskala dla reprezentacji listowej: " << resultWeight << endl;
			for (int i = 0; i < edges; i++) {
				cout << result[i]->getStart() << ' ' << result[i]->getEnd() << ' ' << result[i]->getWeight() << endl;
				delete result[i];
			}
			cout << endl;
			delete[] result;

			result = kruskal(matrix, edges, vertices, resultWeight);
			cout << "Wynik algorytmu Kruskala dla reprezentacji macierzowej: " << resultWeight << endl;
			for (int i = 0; i < edges; i++) {
				cout << result[i]->getStart() << ' ' << result[i]->getEnd() << ' ' << result[i]->getWeight() << endl;
				delete result[i];
			}
			cout << endl;
			delete[] result;
			break;
		}
	} while (choice != 0);

	if (arr != nullptr) {
		for (int i = 0; i < edges; i++) delete arr[i];
		delete[] arr;
		for (int i = 0; i < vertices; i++) delete lists[i];
		delete[] lists;
		delete matrix;
	}
}
void doShortestPath() {
	string menu = "\
		\r[0] - zakoncz\n\
		\r[1] - wczytaj z pliku\n\
		\r[2] - wygeneruj graf losowo\n\
		\r[3] - wyswietl listowo i macierzowo na ekranie\n\
		\r[4] - Algorytm Dijkstry\n\
		\r[5] - Algorytm Forda-Bellmana\n\
		";
	Edge** arr = nullptr;
	NeighbourList** lists = nullptr;
	NeighbourMatrix* matrix = nullptr;
	int edges = 0, vertices = 0, start;

	int** result;

	int choice;
	do {
		cout << menu << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			if (arr != nullptr) {
				for (int i = 0; i < edges; i++) delete arr[i];
				delete[] arr;
			}

			arr = readShortestPathFromFile(edges, vertices, start);
			lists = NeighbourList::makeDirectionalNeighbourLists(arr, edges, vertices);
			matrix = NeighbourMatrix::makeDirectionalNeighbourMatrix(arr, edges, vertices);
			break;
		case 2:
			if (arr != nullptr) {
				for (int i = 0; i < edges; i++) delete arr[i];
				delete[] arr;
			}

			double density;
			cout << "Podaj ilosc wierzcholkow i gestosc" << endl;
			cin >> vertices >> density;
			edges = vertices * (vertices - 1) / 2 * density;
			arr = makeRandomGraph(edges, vertices);
			lists = NeighbourList::makeDirectionalNeighbourLists(arr, edges, vertices);
			matrix = NeighbourMatrix::makeDirectionalNeighbourMatrix(arr, edges, vertices);
			start = rand() % vertices;
			break;
		case 3:
			if (arr == nullptr) {
				cout << "BRAK GRAFU!!!" << endl;
				break;
			}
			printNeighbourLists(lists, vertices);
			printNeighbourMatrix(matrix, vertices);
			break;
		case 4:
			if (arr == nullptr) {
				cout << "BRAK GRAFU!!!" << endl;
				break;
			}

			result = dijkstra(lists, edges, vertices, start);
			cout << "Wynik algorytmu Dijkstry dla reprezentacji listowej dla startu: " << start << endl;
			printShortestPath(result, vertices);
			cout << endl;

			for (int i = 0; i < vertices; i++) {
				if(result[i] != nullptr) delete result[i];
			}
			delete[] result;

			result = dijkstra(matrix, edges, vertices, start);
			cout << "Wynik algorytmu Dijkstry dla reprezentacji macierzowej dla startu: " << start << endl;
			printShortestPath(result, vertices);
			cout << endl;

			for (int i = 0; i < vertices; i++) {
				if (result[i] != nullptr) delete result[i];
			}
			delete[] result;
			break;
		case 5:
			if (arr == nullptr) {
				cout << "BRAK GRAFU!!!" << endl;
				break;
			}

			result = fordBellman(lists, edges, vertices, start);
			cout << "Wynik algorytmu Forda-Bellmana dla reprezentacji listowej dla startu: " << start << endl;
			printShortestPath(result, vertices);
			cout << endl;

			for (int i = 0; i < vertices; i++) {
				if (result[i] != nullptr) delete result[i];
			}
			delete[] result;

			result = fordBellman(matrix, edges, vertices, start);
			cout << "Wynik algorytmu Forda-Bellmana dla reprezentacji macierzowej dla startu: " << start << endl;
			printShortestPath(result, vertices);
			cout << endl;

			for (int i = 0; i < vertices; i++) {
				if (result[i] != nullptr) delete result[i];
			}
			delete[] result;
			break;
		}
	} while (choice != 0);

	if (arr != nullptr) {
		for (int i = 0; i < edges; i++) delete arr[i];
		delete[] arr;
		for (int i = 0; i < vertices; i++) delete lists[i];
		delete[] lists;
		delete matrix;
	}
}
void doMaxFlow() {
	string menu = "\
		\r[0] - zakoncz\n\
		\r[1] - wczytaj z pliku\n\
		\r[2] - wygeneruj graf losowo\n\
		\r[3] - wyswietl listowo i macierzowo na ekranie\n\
		\r[4] - \n\
		\r[5] - \n\
		";
}

void printShortestPath(int** dist, int vertices) {
	for (int i = 0; i < vertices; i++) {
		if (dist[i] == nullptr) {
			cout << "inf ";
		}
		else {
			cout << *dist[i] << ' ';
		}
	}
	cout << endl;
}


Edge** readMSTFromFile(int& edges, int& vertices) {
	return nullptr;
}
Edge** readShortestPathFromFile(int& edges, int& vertices, int& start) {
	return nullptr;
}
Edge** readMSTMaxFlowFile(int& edges, int& vertices, int& start, int& end) {
	return nullptr;
}
