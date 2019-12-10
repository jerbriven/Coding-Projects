#include "BinarySearchTree.h"

// Default constructor
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() {
	rootPtr = nullptr;
}

// Destructor
template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
	clear();
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) {
	rootPtr = new BinaryNode<ItemType>(rootItem);
}

template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& bst) {
	rootPtr=preOrderDeepCopy(bst.rootPtr);
}

template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
	return (rootPtr == nullptr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
	return heightCount(rootPtr);
}

template<class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
	int count = 0;

	if (rootPtr != nullptr)
	{
		preOrderCountNodes(rootPtr, count);
	}

	return count;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& item) {
	bool added = false;

	if (!contains(item))
	{
		int befSize = this->getNumberOfNodes();

		BinaryNode<ItemType> * temp = new BinaryNode<ItemType>(item);
		rootPtr = placeNode(rootPtr, temp);

		if (befSize < this->getNumberOfNodes())
		{
			added = true;
		}
	}

	return added;
}

template<class ItemType>
void BinarySearchTree<ItemType>::clear() {
	clearPostOrder(rootPtr);
	rootPtr = nullptr;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& item) const {
	BinaryNode<ItemType>* found = findNode(rootPtr, item);

	if (found == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// Places item in 
template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::placeNode(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr) {
	if (subTreePtr == nullptr)
	{
		return newNodePtr;
	}
	else
	{ 
		BinaryNode<ItemType>*lptr = subTreePtr->getLeftChildPtr();
		BinaryNode<ItemType>*rptr = subTreePtr->getRightChildPtr();

		if (subTreePtr->getItem() > newNodePtr->getItem())
		{
			lptr = placeNode(lptr, newNodePtr);
			subTreePtr->setLeftChildPtr(lptr);
		}
		else
		{

			rptr = placeNode(rptr, newNodePtr);
			subTreePtr->setRightChildPtr(rptr);
		}
		return subTreePtr;
	}
} 

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target) const {
	BinaryNode<ItemType>* tempPtr = subTreePtr;

	if (subTreePtr == nullptr)
	{
		return nullptr;
	}
	else if (subTreePtr->getItem() == target)
	{
		return subTreePtr;
	}
	else if (subTreePtr->getItem() > target)
	{
		tempPtr = findNode(subTreePtr->getLeftChildPtr(), target);
	}
	else
	{
		tempPtr = findNode(subTreePtr->getRightChildPtr(), target);
	}
	
	return tempPtr;
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
	inOrderTrav(rootPtr, visit);
}

template<class ItemType>
void BinarySearchTree<ItemType>::rebalance() {
	int numOfNodes = this->getNumberOfNodes();

	ItemType * ar = new ItemType[numOfNodes];

	int count = 0;
	fillArInOrder(rootPtr, ar, count);

	readTree(ar, numOfNodes);

	delete[]ar;
	ar = nullptr;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::readTree(ItemType arr[], int n) {
	clear();

	bool built = false;

	rootPtr = buildTree(arr, 0, n);

	if (this->getNumberOfNodes() == n)
	{
		built = true;
	}
	return built;
}

template<class ItemType>
void BinarySearchTree<ItemType>::displaySideways() const {
	sideways(rootPtr, 0);
}

template<class ItemType>
void BinarySearchTree<ItemType>::sideways(BinaryNode<ItemType>* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->getRightChildPtr(), level);

		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << current->getItem() << endl; 
		sideways(current->getLeftChildPtr(), level);
	}
}

template<class ItemType>
void BinarySearchTree<ItemType>::preOrderCountNodes(BinaryNode<ItemType>* current, int & count) const {
	if (current == nullptr)
	{
		return;
	}

	count += 1;

	preOrderCountNodes(current->getLeftChildPtr(), count);

	preOrderCountNodes(current->getRightChildPtr(), count);
}

template<class ItemType>
void BinarySearchTree<ItemType>::clearPostOrder(BinaryNode<ItemType>* current) {
	if (current == nullptr)
	{
		return;
	}

	clearPostOrder(current->getLeftChildPtr());

	clearPostOrder(current->getRightChildPtr());

	delete current;
	current = nullptr;
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::preOrderDeepCopy( BinaryNode<ItemType>* toCopy) {
	if (toCopy == nullptr)
	{
		return nullptr;

	}
	
	ItemType item = toCopy->getItem();
	BinaryNode<ItemType>* root= new BinaryNode<ItemType>(item);

	root->setLeftChildPtr(preOrderDeepCopy(toCopy->getLeftChildPtr()));

	root->setRightChildPtr(preOrderDeepCopy(toCopy->getRightChildPtr()));

	return root;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::preOrderComparsion(const BinaryNode<ItemType>* root,const BinaryNode<ItemType>* rhs) const {
	bool retVal;

	if (root == nullptr && rhs == nullptr)
	{
		retVal = true;
	}
	else if (root->getItem() != rhs->getItem())
	{
		retVal = false;
	}
	else
	{
		retVal= preOrderComparsion(root->getLeftChildPtr(), rhs->getLeftChildPtr());

		retVal= preOrderComparsion(root->getRightChildPtr(), rhs->getRightChildPtr());
	}

	return retVal;
}

template<class ItemType>
void BinarySearchTree<ItemType>::fillArInOrder(const BinaryNode<ItemType>* root, ItemType ar[], int & index) {
	if (root == nullptr)
	{
		return;
	}

	fillArInOrder(root->getLeftChildPtr(), ar, index);

	ItemType item = root->getItem();
	ar[index] = item;
	index++;

	fillArInOrder(root->getRightChildPtr(), ar, index);
}

template<class ItemType>
void BinarySearchTree<ItemType>::inOrderTrav(const BinaryNode<ItemType>* root, void visit(ItemType&)) const {
	if (root == nullptr)
	{
		return;
	}

	inOrderTrav(root->getLeftChildPtr(), visit);

	ItemType item = root->getItem();
	visit(item);

	inOrderTrav(root->getRightChildPtr(), visit);
}

template<class ItemType>
int BinarySearchTree<ItemType>::heightCount(BinaryNode<ItemType>* root)const {
	if (root == nullptr)
	{
		return 0;
	}
	else
	{
		int lh = heightCount(root->getLeftChildPtr());

		int rh = heightCount(root->getRightChildPtr());

		if (lh > rh)
			return(lh + 1);
		else 
			return(rh + 1);
	}
}

template<class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::buildTree(ItemType ar[], int lbound, int ubound) {
	if (lbound >= ubound) return nullptr;

	// Calculate the middle of array
	int m = lbound + (ubound - lbound) / 2;

	// Set root equal to item in middle of array
	BinaryNode<ItemType>*root = new BinaryNode<ItemType>(ar[m]);

	// Set left child to left part of array
	root->setLeftChildPtr(buildTree(ar, lbound, m));

	// Set right child to right part of array
	root->setRightChildPtr(buildTree(ar, m+1, ubound));

	return root;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::operator==(const BinarySearchTree<ItemType>& other) const {
	if (this->getNumberOfNodes() != other.getNumberOfNodes())
	{
		return false;
	}
	else
	{
		return preOrderComparsion(this->rootPtr, other.rootPtr);
	}
}

// Checks it two trees are not the same
template<class ItemType>
bool BinarySearchTree<ItemType>::operator!=(const BinarySearchTree<ItemType>& other) const {
	return !(*this == other);
}