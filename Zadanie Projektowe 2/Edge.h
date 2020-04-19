
#ifndef EDGE_H
#define EDGE_H

class Edge {
	int start, end, weight;
public:
	Edge();
	Edge(int start, int end, int weight);

	int getStart();
	int getEnd();
	int getWeight();

	Edge* copy(); // creates new object with the same attributes
	void reverse(); // swaps start with end
};

// sorts edges in ascending orber by weights
void qsortEdges(Edge* edges, int left, int right);

#endif
