
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

	// used to compare priority between edges
	// priority depends on weight, the smaller the weight, the higher the priority
	// returns true if operand on the left has higher priority
	bool operator > (Edge& e);
};

// sorts edges in ascending orber by weights
void qsortEdges(Edge* edges, int left, int right);

#endif
