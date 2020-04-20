
#ifndef NEIGHBOUR_LIST_H
#define NEIGHBOUR_LIST_H

#include <iostream>

#include "Edge.h"

//NeighbourList holds edges of a vertex

class NeighbourList {
	struct Element {
		Edge* e;
		Element* next;

		Element(Edge* e);
		~Element();
	};

	int from;
	Element* head, * tail, * it;

public:

	NeighbourList();
	NeighbourList(int from);
	~NeighbourList();

	void add(Edge* e); // creates new Element with pionter to Edge e
	void resetIterator(); // sets iterator to head
	bool hasNext(); // returns true if iterator can get next value and isnt nullptr
	Edge* getNext(); // returns next edge and sets it iterator to next Element
};


// Makes Neighbour Lists from copies of edges in the array
NeighbourList** makeNeighbourLists(Edge** arr, int edges, int vertices);

void printNeighbourLists(NeighbourList** lists, int vertices);

#endif
