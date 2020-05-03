
#include "NeighbourList.h"


NeighbourList::Element::Element(Edge* e) {
	this->e = e;
	next = nullptr;
}

NeighbourList::Element::~Element() {
	delete e;
}


NeighbourList::NeighbourList() { ; }
NeighbourList::NeighbourList(int from) {
	this->from = from;
	size = 0;
	head = tail = nullptr;
}

NeighbourList::~NeighbourList() {
	Element* next = head;
	while (next != nullptr) {
		next = next->next;
		delete head;
		head = next;
	}
}


void NeighbourList::add(Edge* e) {
	if (tail == nullptr) {
		head = tail = new Element(e);
		return;
	}

	tail->next = new Element(e);
	tail = tail->next;
	++size;
}


NeighbourList** NeighbourList::makeNeighbourLists(Edge** arr, int edges, int vertices) {

	NeighbourList** lists = new NeighbourList*[vertices];
	for (int i = 0; i < vertices; i++) lists[i] = new NeighbourList(i);

	for (int i = 0; i < edges; i++) {
		// Duplicating edges
		// Undirected graph will now be two-directioned

		Edge* e1 = arr[i]->copy();
		Edge* e2 = arr[i]->copy();
		e2->reverse();

		lists[e1->getStart()]->add(e1);
		lists[e2->getStart()]->add(e2);
	}

	return lists;
}

void NeighbourList::printNeighbourLists(NeighbourList** lists, int vertices) {
	for (int i = 0; i < vertices; i++) {
		std::cout << i;

		// iterator of elements
		Element* it = lists[i]->head;

		while(it != nullptr) {
			Edge* e = it->e;
			std::cout << ' ' << '(' << e->getEnd() << ',' << ' ' << e->getWeight() << ')';
			it = it->next;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
