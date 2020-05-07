
#include "Dijkstra.h"

VertexDistance::VertexDistance(int vertex, int distance) {
	this->vertex = vertex;
	this->distance = distance;
}

bool VertexDistance::operator > (VertexDistance& vd) {
	return this->distance < vd.distance;
}


int** dijkstra(NeighbourList** lists, int edges, int vertices, int start) {
	
	// result array holding distance from start to each vertex
	int** dist = new int* [vertices];
	for (int i = 0; i < vertices; i++) dist[i] = nullptr; // infinity
	dist[start] = new int(0);

	// vertex is visited, when all of edges beginning with it, have been considered
	bool* visited = new bool[vertices];
	for (int i = 0; i < vertices; i++) visited[i] = false;
	

	// PQ of pairs of vertices and distances
	// Dijkstra's algorithm uses the next most promising vertex
	VertexDistancePQ* pq = new VertexDistancePQ(edges);
	VertexDistance* vd = new VertexDistance(start, 0);
	pq->enqueue(vd);


	while (pq->getSize() > 0) {
		vd = pq->dequeue();
		int current = vd->vertex;

		if (visited[current]) {
			delete vd;
			continue;
		}

		lists[current]->resetIterator();
		while (lists[current]->hasNext()) {
			Edge* e = lists[current]->getNext();
			int start = e->getStart(), end = e->getEnd(), weight = e->getWeight();

			if (dist[end] == nullptr) {
				dist[end] = new int(*dist[start] + weight);
				pq->enqueue(new VertexDistance(end, *dist[end]));
			}
			else if (*dist[start] + weight < *dist[end]) {
				*dist[end] = *dist[start] + weight;
				pq->enqueue(new VertexDistance(end, *dist[end]));
			}
		}
		
		visited[current] = true;
		delete vd;
	}

	delete[]visited;
	delete pq;

	return dist;
}

int** dijkstra(NeighbourMatrix* matrix, int edges, int vertices, int start) {

	// result array holding distance from start to each vertex
	int** dist = new int* [vertices];
	for (int i = 0; i < vertices; i++) dist[i] = nullptr; // infinity
	dist[start] = new int(0);

	// vertex is visited, when all of edges beginning with it, have been considered
	bool* visited = new bool[vertices];
	for (int i = 0; i < vertices; i++) visited[i] = false;


	// PQ of pairs of vertices and distances
	// Dijkstra's algorithm uses the next most promising vertex
	VertexDistancePQ* pq = new VertexDistancePQ(edges);
	VertexDistance* vd = new VertexDistance(start, 0);
	pq->enqueue(vd);


	while (pq->getSize() > 0) {
		vd = pq->dequeue();
		int current = vd->vertex;

		if (visited[current]) {
			delete vd;
			continue;
		}

		for (int i = 0; i < vertices; i++) {
			Edge* e = matrix->get(current, i);
			if (e == nullptr) continue;
			int start = e->getStart(), end = e->getEnd(), weight = e->getWeight();

			if (dist[end] == nullptr) {
				dist[end] = new int(*dist[start] + weight);
				pq->enqueue(new VertexDistance(end, *dist[end]));
			}
			else if (*dist[start] + weight < *dist[end]) {
				*dist[end] = *dist[start] + weight;
				pq->enqueue(new VertexDistance(end, *dist[end]));
			}
		}

		visited[current] = true;
		delete vd;
	}

	delete[]visited;
	delete pq;

	return dist;
}


