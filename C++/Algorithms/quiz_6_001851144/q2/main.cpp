#include <iostream>
#include "bTree.h"

using namespace std;

template <typename T>
bool lessThan(T a, T b) {
    if (a < b)
        return true;
    else
        return false;
}

template <typename T>
void printKey(T key) {
    cout << key << " ";
}

int main() {
    BTree<int> testTree(3, lessThan, printKey);
    testTree.insert(5);
    testTree.insert(6);
    testTree.insert(7);
    testTree.insert(9);
    testTree.insert(1);
    testTree.print();
    cout << "Searching for key 5 returns: " << testTree.searchKey(5) << endl;
    testTree.remove(5);
    cout << "After removing 5, the tree contains: ";
    testTree.print();
}