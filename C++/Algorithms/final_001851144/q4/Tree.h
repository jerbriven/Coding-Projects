#ifndef _TREE_H
#define _TREE_H

#include <iostream>
using namespace std;

// Define a structure to be used as the tree node
struct TreeNode
{
    int      Key;
    float    fValue;
    int      iValue;
    char     cArray[7];
    TreeNode *left;
    TreeNode *right;
};

class Tree
{
    private:
        TreeNode *root;

    public:
        Tree();
        ~Tree();
        bool isEmpty();
        TreeNode *SearchTree(int Key);
        TreeNode *SearchByValue(float f, int i, char *c, TreeNode *temp);
        bool Insert(TreeNode *newNode);
        bool Insert(int Key, float f, int i, char *cA);
        bool Delete(int Key);
        bool replace(float f, int i, char *c, float f2, int i2, char *c2);
        void PrintOne(TreeNode *T);
        void PrintTree();
    private:
        void ClearTree(TreeNode *T);
        TreeNode *DupNode(TreeNode * T);
        void PrintAll(TreeNode *T);
};
#include "Tree.cpp"

#endif