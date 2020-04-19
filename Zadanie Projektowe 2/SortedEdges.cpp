
#include "SortedEdges.h"


SortedEdges::SortedEdges(Edge* edges, int n) {
	this->edges = new Edge[n];
	this->size = n;
	for (int i = 0; i < n; i++) this->edges[i] = edges[i];
	qsort(0, n - 1);
}

void SortedEdges::qsort(int left, int right) {
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

	if (i < right) qsort(i, right);
	if (left < j) qsort(left, j);
}

Edge SortedEdges::getEdge(int i) {
	return edges[i];
}

int SortedEdges::getSize() {
	return size;
}