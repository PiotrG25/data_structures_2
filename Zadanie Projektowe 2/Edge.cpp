
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
