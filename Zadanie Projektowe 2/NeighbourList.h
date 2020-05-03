
#ifndef NEIGHBOUR_LIST_H
#define NEIGHBOUR_LIST_H

#include <iostream>

#include "Edge.h"

// NeighbourList holds edges of a vertex (from)
// 

class NeighbourList {
	struct Element {
		Edge* e;
		Element* next;

		Element(Edge* e);
		~Element();
	};

	// starting vertex index
	// size of the list
	int from, size;
	// head and tail pointer of the list
	Element* head, * tail;

	NeighbourList();
	NeighbourList(int from);
public:
	// deletes all Elements and Edges within these elements
	~NeighbourList();

	// Makes Neighbour Lists from copies of edges in the array
	static NeighbourList** makeNeighbourLists(Edge** arr, int edges, int vertices);

	// creates new Element with pionter to Edge e
	// !!! does not copy edge !!!
	void add(Edge* e);

	// returns pointer to array of edges copied from the list
	// sets size to size of the array
	Edge** getEdges(int& size);
};


void printNeighbourLists(NeighbourList** lists, int vertices);

#endif
