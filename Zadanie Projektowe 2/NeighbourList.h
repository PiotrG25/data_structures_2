
#ifndef NEIGHBOUR_LIST_H
#define NEIGHBOUR_LIST_H

#include <iostream>

#include "Edge.h"

// NeighbourList holds edges of a vertex (from)
// can be created only with static method

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

	// creates new Element with pionter to Edge e
	// !!! does not copy edge !!!
	// PS: used only in static lists constructor
	void add(Edge* e);
public:
	// deletes all Elements and Edges within these elements
	~NeighbourList();

	// Makes Neighbour Lists from copies of edges in the array
	static NeighbourList** makeNeighbourLists(Edge** arr, int edges, int vertices);

	// returns pointer to array of edges copied from the list
	// sets size to size of the array
	Edge** getEdges(int& size);
};

// prints for each list 
// list of edges in format:
// i (v1, w1), (v2, w2), ...
// where i is index of from vertex
// vj and wj are index of neighbouring vertex and weight of egdge between
void printNeighbourLists(NeighbourList** lists, int vertices);

#endif
