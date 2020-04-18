
#ifndef PQ_H
#define PQ_H

#include <iostream>

#include "Edge.h"

// Priority Queue for Edges
// implemented with MIN-HEAP
// priority depends on weight, the smaller the weight, the higher the priority
class PQ {

	int length; // length of the array
	int size; // number of elements in the array
	Edge* arr; // the array


	void bubbleUp(int index);

	void bubbleDown(int index);

	int parentIndexOf(int index);
	int leftChildIndexOf(int index);
	int rightChildIndexOf(int index);

public:


	PQ(int size);
	PQ(Edge* edges, int size);
	~PQ();

	void enqueue(Edge e);
	Edge dequeue();

	int getSize();
};

#endif
