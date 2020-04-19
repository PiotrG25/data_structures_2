
#include "NeighbourList.h"


NeighbourList::Element::Element(Edge e) {
	this->e = e;
	next = nullptr;
}


NeighbourList::NeighbourList(int from) {
	this->from = from;
	head = tail = it = nullptr;
}

void NeighbourList::add(Edge e) {
	if (tail == nullptr) {
		head = tail = it = new Element(e);
		return;
	}

	tail->next = new Element(e);
	tail = tail->next;
}


void NeighbourList::resetIterator() {
	it = head;
}

bool NeighbourList::hasNext() {
	return it != nullptr && it->next != nullptr;
}

Edge NeighbourList::getNext() {
	it = it->next;
	return it->e;
}
