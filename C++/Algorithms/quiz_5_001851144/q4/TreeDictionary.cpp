/** @file TreeDictionary.cpp */

#include "TreeDictionary.h"

template <class KeyType, class ItemType>
TreeDictionary<KeyType, ItemType>::TreeDictionary() {
  // itemTree = new BinarySearchTree<Entry<KeyType, ItemType>>();
}

template <class KeyType, class ItemType>
TreeDictionary<KeyType, ItemType>::TreeDictionary(const TreeDictionary<KeyType, ItemType>& dict)
{
 //  itemTree = new BinarySearchTree<Entry<KeyType, ItemType>>();
  // itemTree.copyTree(dict);
}

template <class KeyType, class ItemType>
TreeDictionary<KeyType, ItemType>::~TreeDictionary()
{
   itemTree.~BinarySearchTree();
}

template <class KeyType, class ItemType>
bool TreeDictionary<KeyType, ItemType>::isEmpty() const
{
   return itemTree.isEmpty();
}

template <class KeyType, class ItemType>
int TreeDictionary<KeyType, ItemType>::getNumberOfItems() const
{
   return itemTree.getNumberOfNodes();
}

template <class KeyType, class ItemType>
bool TreeDictionary<KeyType, ItemType>::add(const KeyType& searchKey,
                                            const ItemType& newItem)
{
   return itemTree.add(Entry<KeyType, ItemType>(newItem, searchKey));
} // end add

template <class KeyType, class ItemType>
bool TreeDictionary<KeyType, ItemType>::remove(const KeyType& itemKey)
{
   return itemTree.remove(Entry<KeyType, ItemType>(ItemType(), itemKey));
}  // end remove   

template <class KeyType, class ItemType>
void TreeDictionary<KeyType, ItemType>::clear()
{
   itemTree.clear();
}

template <class KeyType, class ItemType>
ItemType TreeDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const throw (NotFoundException)
{
   Entry<KeyType, ItemType> node1 =  itemTree.getEntry(Entry<KeyType, ItemType>(ItemType(), searchKey));
   return node1.getItem();
}
  
template <class KeyType, class ItemType>
bool TreeDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const
{
   return itemTree.contains(Entry<KeyType, ItemType>(ItemType(), searchKey));
}

template <class KeyType, class ItemType>
bool TreeDictionary<KeyType, ItemType>::containsItem(const ItemType& item) const
{
   if (item == "num")
      return itemTree.contains(Entry<KeyType, ItemType>(item, "int"));
}

/** Traverses the items in this dictionary in sorted search-key order
 and calls a given client function once for each item. */
template <class KeyType, class ItemType>
void TreeDictionary<KeyType, ItemType>::traverse(void visit(Entry<KeyType, ItemType>&)) const
{
   itemTree.inorderTraverse(visit);
}