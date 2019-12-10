#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryNode.h"

using namespace std;

template<class ItemType>
class BinarySearchTree {
public:
	BinarySearchTree<ItemType>();
	explicit BinarySearchTree<ItemType>(const ItemType& rootItem);
	BinarySearchTree<ItemType>(const BinarySearchTree<ItemType>& bst);
	virtual ~BinarySearchTree<ItemType>();
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	bool add(const ItemType& item);
	bool contains(const ItemType& item) const;
	void displaySideways() const;
	void inorderTraverse(void visit(ItemType&)) const;
	void rebalance();
	void clear();
	bool readTree(ItemType arr[], int n);
	bool operator==(const BinarySearchTree<ItemType> &) const;
	bool operator!=(const BinarySearchTree<ItemType> &) const;
private:
	BinaryNode<ItemType>* rootPtr{ nullptr };
	BinaryNode<ItemType>* placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr);
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target) const;
	void sideways(BinaryNode<ItemType>* current, int level) const;
	void preOrderCountNodes(BinaryNode<ItemType>* current, int & count) const;
	void clearPostOrder(BinaryNode<ItemType>* current);
	BinaryNode<ItemType>* preOrderDeepCopy(BinaryNode<ItemType>* toCopy);
	bool preOrderComparsion(const BinaryNode<ItemType>* root, const BinaryNode<ItemType>* rhs)const;
	void fillArInOrder(const BinaryNode<ItemType>* root, ItemType ar[], int & index);
	void inOrderTrav(const BinaryNode<ItemType>* root, void visit(ItemType&)) const;
	int heightCount(BinaryNode<ItemType>* root)const;
	BinaryNode<ItemType>* buildTree(ItemType ar[], int lbound, int ubound);

};

#include "BinarySearchTree.cpp"

#endif