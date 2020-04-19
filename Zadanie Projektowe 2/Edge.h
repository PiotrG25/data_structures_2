
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
};

void qsortEdges(Edge* edges, int left, int right);

#endif
