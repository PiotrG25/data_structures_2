
#ifndef PQ_H
#define PQ_H

#include <iostream>

#include "Edge.h"

// Priority Queue
// implemented with MAX-HEAP - element with highest priority ends up on top
// does not copy of delete Elements stored in it

// Each class stored in it must overload operator >
// returning true if operand on the left has bigger priority than operand on the right
// bool C::operator > (C& e) {
template<class C>
class PQ {

	int length; // length of the array
	int size; // number of elements in the array
	C** arr; // the array


	// methods of restoring heap invariant
	void bubbleUp(int index) {
		if (index <= 0) return;

		int parent = parentIndexOf(index);
		// while index node has bigger priority than parent node
		while (parent >= 0 && *arr[index] > *arr[parent]) {
			// swap elements
			C* e = arr[index];
			arr[index] = arr[parent];
			arr[parent] = e;

			// consider parent node in the next iteration
			index = parent;
			parent = parentIndexOf(index);
		}
	}
	void bubbleDown(int index) {
		int left = leftChildIndexOf(index), right = rightChildIndexOf(index);

		while (true) {
			// node has no children
			if (left >= size) {
				break;
			}
			// if node has only one child
			else if (right >= size) {
				// if the left node has higher priority than the index node
				if (*arr[left] > *arr[index]) {
					// swap elements
					C* e = arr[left];
					arr[left] = arr[index];
					arr[index] = e;
				}

				break;
			}
			// if node has two children
			else {
				// if the left element has higher priority than the right one
				if (*arr[left] > *arr[right]) {
					// if the left node has higher priority than the index node
					if (*arr[left] > *arr[index]) {
						// swap elements
						C* e = arr[left];
						arr[left] = arr[index];
						arr[index] = e;

						// consider left node in the next iteration
						index = left;
					}
					else return; // return if index node has bigger priority than its children
				}
				// if the right element has higher or qual priority than the left one
				else {
					// if right node has higher priority than the index node
					if (*arr[right] > *arr[index]) {
						// swap elements
						C* e = arr[right];
						arr[right] = arr[index];
						arr[index] = e;

						// consider right node in the next iteration
						index = right;
					}
					else return; // return if index node has bigger priority than its children
				}

				left = leftChildIndexOf(index);
				right = rightChildIndexOf(index);
			}
		}
	}

	// methods of calculating indexes of relatives
	int parentIndexOf(int index) {
		return (index - 1) / 2;
	}
	int leftChildIndexOf(int index) {
		return index * 2 + 1;
	}
	int rightChildIndexOf(int index) {
		return index * 2 + 2;
	}

public:
	
	// creates PQ of fixed size
	PQ(int size) {
		this->length = size;
		this->arr = new C * [this->length];
		for (int i = 0; i < length; i++) arr[i] = nullptr;
		this->size = 0;
	}
	~PQ() {
		delete[] arr;
	}

	// adds pointer to the edge to the PQ
	void enqueue(C* e) {
		if (size >= length) throw std::exception();

		arr[size] = e;
		bubbleUp(size);
		++size;
	}
	// removes pointer form the PQ and returns it
	C* dequeue() {
		if (0 >= size) throw std::exception();

		C* e = arr[0];
		arr[0] = arr[--size];
		arr[size] = nullptr;
		bubbleDown(0);

		return e;
	}

	// returns number of elements in the PQ
	int getSize() {
		return size;
	}
};


typedef PQ<Edge> EdgePQ;

#endif
