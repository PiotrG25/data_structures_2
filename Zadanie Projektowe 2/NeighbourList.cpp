
#include "NeighbourList.h"


NeighbourList::Element::Element(Edge* e) {
	this->e = e;
	next = nullptr;
}

NeighbourList::NeighbourList() { ; }
NeighbourList::NeighbourList(int from) {
	this->from = from;
	head = tail = it = nullptr;
}

void NeighbourList::add(Edge* e) {
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

Edge* NeighbourList::getNext() {
	it = it->next;
	return it->e;
}



NeighbourList** makeNeighbourLists(Edge** arr, int edges, int vertices) {

	NeighbourList** lists = new NeighbourList*[vertices];
	for (int i = 0; i < vertices; i++) lists[i] = new NeighbourList(i);

	for (int i = 0; i < edges; i++) {
		// Duplicating edges
		// Undirected graph will be now two-directioned

		Edge* e = arr[i];
		Edge* e1 = new Edge(e->getStart(), e->getEnd(), e->getWeight());
		Edge* e2 = new Edge(e->getEnd(), e->getStart(), e->getWeight());

		lists[e1->getStart()]->add(e1);
		lists[e2->getStart()]->add(e2);
	}

	return lists;
}