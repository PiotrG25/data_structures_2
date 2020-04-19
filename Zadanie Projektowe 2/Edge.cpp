
#include "Edge.h"

Edge::Edge() { ; }

Edge::Edge(int start, int end, int weight) {
	this->start = start;
	this->end = end;
	this->weight = weight;
}

int Edge::getStart() {
	return start;
}
int Edge::getEnd() {
	return end;
}
int Edge::getWeight() {
	return weight;
}

void qsortEdges(Edge* edges, int left, int right) {
	int i = left, j = right, v = edges[(i + j) / 2].getWeight();

	do {
		while (edges[i].getWeight() < v) ++i;
		while (edges[j].getWeight() > v) --j;
		if (i <= j) {
			Edge e = edges[i];
			edges[i] = edges[j];
			edges[j] = e;
			++i;
			--j;
		}
	} while (i <= j);

	if (i < right) qsortEdges(edges, i, right);
	if (left < j) qsortEdges(edges, left, j);
}


Edge* Edge::copy() {
	return new Edge(start, end, weight);
}

void Edge::reverse() {
	int t = start;
	start = end;
	end = t;
}

