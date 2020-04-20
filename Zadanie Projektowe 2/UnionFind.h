
#ifndef UNION_FIND
#define UNION_FIND

class UnionFind {
	int* id, * size;
	int nr_of_subgroups;

public:

	UnionFind(int n);

	// unifies two subgroups into one group
	// connects smaller group to bigger group
	void unify(int i, int j);
	// finds root index of subgroup
	// sets every node on the way from i to root to root
	int find(int i);

	// returns true if i and j belong to one subgroup
	bool areInOneUnion(int i, int j);

	int getNumberOfSubgroups();
	bool isOneUnion();
};

#endif
