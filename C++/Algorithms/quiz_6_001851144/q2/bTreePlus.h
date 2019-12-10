#ifndef _BPLUS_TREE
#define _BPLUS_TREE

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<climits>
#include "Node.h"
using namespace std;


class BPTree
{
	Node *root;
	void insertInternal(int,Node*,Node*);
	void removeInternal(int,Node*,Node*);
	Node* findParent(Node*,Node*);
public:
	BPTree();
	void search(int);
	void insert(int);
	void remove(int);
	void display(Node*);
	Node* getRoot();
	void cleanUp(Node*);
	~BPTree();
};
#include "bTreePlus.cpp"
#endif