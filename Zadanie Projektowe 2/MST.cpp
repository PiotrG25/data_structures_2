
#include "MST.h"

void qsort(Edge* edges, int left, int right) {
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

	if (i < right) qsort(edges, i, right);
	if (left < j) qsort(edges, left, j);
}

