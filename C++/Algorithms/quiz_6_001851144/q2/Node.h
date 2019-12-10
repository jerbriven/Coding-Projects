#ifndef _NODE
#define _NODE

class Node
{
private:
	bool IS_LEAF;
	int *key, size;
	Node** ptr;
	friend class BPTree;
public:
	Node();
};
#include "Node.cpp"
#endif