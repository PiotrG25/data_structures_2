
#ifndef SORTED_EDGES_H
#define SORTED_EDGES_H

#include "Edge.h"

/*
SortedEdges holds edges in ASC order by weight
*/
class SortedEdges {
	Edge* edges;
	int size;

	void qsort(int left, int right);
public:
	SortedEdges(Edge* edges, int n);

	Edge getEdge(int i);
	int getSize();
};

#endif

