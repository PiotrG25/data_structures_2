
#ifndef NEIGHBOUR_LIST_H
#define NEIGHBOUR_LIST_H

#include "Edge.h"

class NeighbourList {
	struct Element {
		Edge e;
		Element* next;

		Element(Edge e);
	};

	int from;
	Element* head, * tail, * it;

	NeighbourList();
	NeighbourList(int from);

	void add(Edge e);
	void resetIterator();
	bool hasNext();
	Edge getNext();
};

#endif
