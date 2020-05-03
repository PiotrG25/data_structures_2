
#include "PQ.h"


void PQ::bubbleUp(int index) {
	if (index <= 0) return;

	int parent = parentIndexOf(index);
	while (parent >= 0 && arr[parent]->getWeight() > arr[index]->getWeight()) {
		Edge* e = arr[index];
		arr[index] = arr[parent];
		arr[parent] = e;

		index = parent;
		parent = parentIndexOf(index);
	}
}
void PQ::bubbleDown(int index) {
	int left = leftChildIndexOf(index), right = rightChildIndexOf(index);

	while (true) {
		if (left >= size) {
			// node has no children
			break;
		}
		else if (right >= size) {
			// node has only one child

			if (arr[left]->getWeight() < arr[index]->getWeight()) {
				Edge* e = arr[left];
				arr[left] = arr[index];
				arr[index] = e;
			}
			break;
		}
		else {
			// node has two children

			if (arr[left]->getWeight() < arr[right]->getWeight()) {
				if (arr[left]->getWeight() < arr[index]->getWeight()) {
					Edge* e = arr[left];
					arr[left] = arr[index];
					arr[index] = e;

					index = left;
				}
				else break;
			}
			else {
				if (arr[right]->getWeight() < arr[index]->getWeight()) {
					Edge* e = arr[right];
					arr[right] = arr[index];
					arr[index] = e;

					index = right;
				}
				else break;
			}

			left = leftChildIndexOf(index);
			right = rightChildIndexOf(index);
		}
	}
}

int PQ::parentIndexOf(int index) {
	return (index - 1) / 2;
}
int PQ::leftChildIndexOf(int index) {
	return index * 2 + 1;
}
int PQ::rightChildIndexOf(int index) {
	return index * 2 + 2;
}


PQ::PQ(int size) {
	this->length = size;
	this->arr = new Edge*[this->length];
	for (int i = 0; i < length; i++) arr[i] = nullptr;
	this->size = 0;
}
PQ::~PQ() {
	delete[] arr;
}

void PQ::enqueue(Edge* e) {
	if (size >= length) throw std::exception();

	arr[size] = e;
	bubbleUp(size);
	++size;
}
Edge* PQ::dequeue() {
	if (0 >= size) throw std::exception();

 	Edge* e = arr[0];
	arr[0] = arr[--size];
	arr[size] = nullptr;
	bubbleDown(0);

	return e;
}

int PQ::getSize() {
	return size;
}

