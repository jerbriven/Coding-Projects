#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <climits>
#include "bTreePlus.h"
using namespace std;

int main()
{
    BPTree testTree;
    testTree.insert(5);
    testTree.insert(6);
    testTree.insert(7);
    testTree.insert(9);
    testTree.insert(1);
    testTree.display(testTree.getRoot());
    cout << "The key 5 was ";
    testTree.search(5);
    testTree.remove(5);
    cout << "After removing 5, the tree contains: ";
    testTree.display(testTree.getRoot());
}