
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
	Edge** arr; // the array


	// methods of restoring heap invariant
	void bubbleUp(int index);
	void bubbleDown(int index);

	// methods of calculating indexes of relatives
	int parentIndexOf(int index);
	int leftChildIndexOf(int index);
	int rightChildIndexOf(int index);

public:
	
	// creates PQ of fixed size
	PQ(int size);
	~PQ();

	// adds pointer to the edge to the PQ
	void enqueue(Edge* e);
	// removes pointer form the PQ and returns it
	Edge* dequeue();

	// returns number of elements in the PQ
	int getSize();
};

#endif
