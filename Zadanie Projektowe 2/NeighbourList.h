
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
	// head tail and iterator pointers of the list
	Element* head, * tail, * it;

	NeighbourList();
	NeighbourList(int from);

	// creates new Element with pionter to Edge e
	// !!! does not copy edge !!!
	// PS: used only in static lists constructor
	void add(Edge* e);

public:

	// deletes all Elements and Edges within these elements
	~NeighbourList();

	// Make Neighbour Lists from copies of edges in the array
	// Bidirectional
	static NeighbourList** makeBidirectionalNeighbourLists(Edge** arr, int edges, int vertices);
	// Directional
	static NeighbourList** makeDirectionalNeighbourLists(Edge** arr, int edges, int vertices);

	// iterator methods
	// sets iterator to point to head of the list
	void resetIterator();
	// returns pointer to edge at which iterator is pointing
	// and moves iterator to next
	Edge* getNext();
	// checks if iterator doesnt point to nullptr
	bool hasNext();
};

// prints for each list list of edges in format:
// j (v1, w1), (v2, w2), ...
// where j is index of from vertex
// vi and wi are index of neighbouring vertex and weight of egdge between
void printNeighbourLists(NeighbourList** lists, int vertices);


#endif
