/** A binary search tree implementation of the ADT dictionary
    that organizes its data items in sorted search-key order.
    Search keys in the dictionary are unique.
 @file TreeDictionary.h */
 
#ifndef _TREE_DICTIONARY
#define _TREE_DICTIONARY

#include "BinarySearchTree.h"
#include "Entry.h"
#include "NotFoundException.h"

template <class KeyType, class ItemType>
class TreeDictionary
{
private:
   // Binary search tree of dictionary entries
   BinarySearchTree<Entry<KeyType, ItemType> > itemTree;
   
   
public:
   TreeDictionary();
   TreeDictionary(const TreeDictionary<KeyType, ItemType>& dict);
   virtual ~TreeDictionary();
   
   // The declarations of the public methods appear here and are the
   // same as given in Listing 18-3 for the class ArrayDictionary.
 
   bool isEmpty() const;
   int getNumberOfItems() const;
   bool add(const KeyType& searchKey, const ItemType& newItem);
   bool remove(const KeyType& searchKey);
   void clear();
   ItemType getItem(const KeyType& searchKey) const throw (NotFoundException);
   bool contains(const KeyType& searchKey) const;
   bool containsItem(const ItemType& item) const;
   
   /** Traverses the items in this dictionary in sorted search-key order
    and calls a given client function once for each item. */
   void traverse(void visit(Entry<KeyType, ItemType>&)) const;
}; // end TreeDictionary

#include "TreeDictionary.cpp"
#endif