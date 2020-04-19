
#ifndef NEIGHBOUR_LIST_H
#define NEIGHBOUR_LIST_H


#include "Edge.h"

//NeighbourList holds edges of a vertex

class NeighbourList {
	struct Element {
		Edge e;
		Element* next;

		Element(Edge e);
	};

	int from;
	Element* head, * tail, * it;

public:

	NeighbourList();
	NeighbourList(int from);

	void add(Edge e);
	void resetIterator();
	bool hasNext();
	Edge getNext();
};


NeighbourList* makeNeighbourLists(Edge* arr, int edges, int vertices);

#endif
