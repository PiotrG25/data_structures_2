
#include "UnionFind.h"

UnionFind::UnionFind(int n) {
	id = new int[n];
	size = new int[n];
	nr_of_subgroups = n;

	for (int i = 0; i < n; ++i) {
		id[i] = i;
		size[i] = 1;
	}
}

UnionFind::~UnionFind() {
	delete[] id;
	delete[] size;
}


void UnionFind::unify(int i, int j) {

	int iroot = find(i);
	int jroot = find(j);

	if (iroot == jroot) return;

	if (size[iroot] > size[jroot]) {
		id[jroot] = iroot;
		size[iroot] += size[jroot];
	}
	else {
		id[iroot] = jroot;
		size[jroot] += size[iroot];
	}

	--nr_of_subgroups;
}

int UnionFind::find(int i) {
	int root = i;

	while (root != id[root]) root = id[root];

	while (i != root) {
		int next = id[i];
		id[i] = root;
		i = next;
	}

	return root;
}


bool UnionFind::areInOneUnion(int i, int j) {
	return find(i) == find(j);
}

int UnionFind::getNumberOfSubgroups() {
	return nr_of_subgroups;
}

bool UnionFind::isOneUnion() {
	return nr_of_subgroups == 1;
}
