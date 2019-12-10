#include "Node.h"
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<climits>

int MAX = 10; //size of each node

Node::Node()
{
	//dynamic memory allocation
	key = new int[MAX];
	ptr = new Node*[MAX+1];
}