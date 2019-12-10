#include "BinaryNodeTree.h"
#include <iostream>

using namespace std;

void isTreeEmpty(BinaryNodeTree<int> tree) 
{
    if (tree.isEmpty())
        cout << "Tree is empty\n";
    else
        cout << "Tree is not empty\n";
}

void treeContain(BinaryNodeTree<int> tree, int check)
{
    if (tree.contains(check)) {
        cout << "The tree does contain " << check << endl;
    }
    else {
        cout << "The tree does not contain " << check << endl;
    }
}

void display(int& item) {
    cout << item << " ";
}

int main()
{
    int a[3] = {1, 2, 3};
    int b[7] = {1, 4, 99, 3, 11, 25, 16};
    BinaryNodeTree<int> test;

    isTreeEmpty(test);
    for (int i = 0; i < 3; ++i)
    {
       test.add(a[i]);
    } 
    isTreeEmpty(test);

    test.checkTree();

    cout << "Pre Order Display: ";
    test.preorderTraverse(display);
    cout << endl;
    cout << "In Order Display: ";
    test.inorderTraverse(display);
    cout << endl;
    cout << "Post Order Display: ";
    test.postorderTraverse(display);
    cout << endl;

    for (int i = 0; i < 7; ++i)
    {
       test.add(b[i]);
    } 

    cout << "Height of tree is " << test.getHeight() << endl;
    cout << "Number of nodes is " << test.getNumberOfNodes() << endl;
    cout << "Root is " << test.getRootData() << endl;
    test.setRootData(20);
    cout << "Root was changed to " << test.getRootData() << endl;
    cout << test.remove(20) << endl;
    cout << "20 was removed from the tree" << endl;
    cout << "Number of nodes is now " << test.getNumberOfNodes() << endl;

    treeContain(test, 3);
    cout << test.getEntry(3) << endl;


    cout << "Clearing the tree" << endl;
    test.clear();
    cout << "Number of nodes is now " << test.getNumberOfNodes() << endl;
}