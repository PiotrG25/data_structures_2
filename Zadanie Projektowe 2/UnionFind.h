
#ifndef UNION_FIND
#define UNION_FIND

class UnionFind {
	int* id, * size;
	int nr_of_subgroups;

public:

	UnionFind(int* arr, int n);

	void unify(int i, int j);
	int find(int i);
};

#endif
