
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
	it = head;
	while (it != nullptr) {
		it = it->next;
		delete head;
		head = it;
	}
}


void NeighbourList::add(Edge* e) {
	if (tail == nullptr) {
		head = tail = it = new Element(e);
		return;
	}

	tail->next = new Element(e);
	tail = tail->next;
	++size;
}


NeighbourList** NeighbourList::makeBidirectionalNeighbourLists(Edge** arr, int edges, int vertices) {

	NeighbourList** lists = new NeighbourList * [vertices];
	for (int i = 0; i < vertices; i++) lists[i] = new NeighbourList(i);

	// Copying edges into lists
	for (int i = 0; i < edges; i++) {
		// Undirected graph will now be bidirectional

		Edge* e1 = arr[i]->copy();
		Edge* e2 = arr[i]->copy();
		e2->reverse();

		lists[e1->getStart()]->add(e1);
		lists[e2->getStart()]->add(e2);
	}

	return lists;
}

NeighbourList** NeighbourList::makeDirectionalNeighbourLists(Edge** arr, int edges, int vertices) {
	
	NeighbourList** lists = new NeighbourList * [vertices];
	for (int i = 0; i < vertices; i++) lists[i] = new NeighbourList(i);

	// Copying edges into lists
	for (int i = 0; i < edges; i++) {
		Edge* e = arr[i]->copy();
		lists[e->getStart()]->add(e);
	}

	return lists;
}


void NeighbourList::resetIterator() {
	it = head;
}
Edge* NeighbourList::getNext() {
	if (it == nullptr) throw std::exception();
	Edge* e = it->e;
	it = it->next;
	return e;
}
bool NeighbourList::hasNext() {
	return it != nullptr;
}

void printNeighbourLists(NeighbourList** lists, int vertices) {
	for (int i = 0; i < vertices; i++) {
		std::cout << i;

		// iterator of elements
		lists[i]->resetIterator();

		while(lists[i]->hasNext()) {
			Edge* e = lists[i]->getNext();
			std::cout << ' ' << '(' << e->getEnd() << ',' << ' ' << e->getWeight() << ')';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
