/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>
#include <iostream>

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), tailPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag->itemCount;
   Node<ItemType>* origChainPtr = aBag->headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr) {
      headPtr = nullptr;  // Original bag is empty; so is copy
      tailPtr = nullptr;
   }
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr; // Last-node pointer
      while (origChainPtr != nullptr)
      {
         origChainPtr = origChainPtr ->getNext(); // Advance pointer
         
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
         tailPtr = newChainPtr;
      } // end while
      
      newChainPtr->setNext(nullptr); // Flag end of new chain
   } // end if
} // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::addFirst(const ItemType& newEntry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);

   if (headPtr == nullptr) {
       headPtr = nextNodePtr;
       tailPtr = nextNodePtr;
       nextNodePtr = nullptr;
   } else {
        nextNodePtr->setNext(headPtr);  // New node points to chain
        headPtr = nextNodePtr;          // New node is now first node
        nextNodePtr = nullptr;
   }

   itemCount++; 
   return true;
}  // end add

template<class ItemType>
bool LinkedBag<ItemType>::addLast(const ItemType& newEntry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);

   if (tailPtr == nullptr) {
       headPtr = nextNodePtr;
       tailPtr = nextNodePtr;
       nextNodePtr = nullptr;
   } else {
        tailPtr->setNext(nextNodePtr);  // New node points to chain
        tailPtr = nextNodePtr;          // New node is now first node
        nextNodePtr = nullptr;
   }

   itemCount++;
   return true;
}  // end add

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::removeFirst()
{
   bool canRemoveItem = !isEmpty();
   if (canRemoveItem) {      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove

// Needs fix

template<class ItemType>
bool LinkedBag<ItemType>::removeLast()
{
   bool canRemoveItem = !isEmpty();
   if (canRemoveItem) {      
      // Delete Last node

      Node<ItemType>* nodeToDeletePtr = tailPtr;
      Node<ItemType>* newTail = headPtr;
      while (newTail->getNext() != tailPtr) {
         newTail = newTail->getNext();
      }
      tailPtr = newTail;
      tailPtr->setNext(nullptr);
      newTail = nullptr;
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   }
   
	return canRemoveItem;
}  // end remove

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
	itemCount = 0;
}  // end clear


template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo

template<class ItemType>
void LinkedBag<ItemType>::readForward() {
    Node<ItemType>* curPtr = headPtr;
    cout << "The bag contains: " << endl;
    if (!isEmpty()) {
        while(curPtr != nullptr) {
            cout << curPtr->getItem() << " ";
            curPtr = curPtr->getNext();
        }
        cout << "\n\n";
    } else {
        cout << "Nothing...\n\n";
    }
}

template<class ItemType>
void LinkedBag<ItemType>::readFirst() {
    cout << "First item: " << headPtr->getItem() << endl << endl;
}

template<class ItemType>
void LinkedBag<ItemType>::readLast() {
    cout << "First item: " << tailPtr->getItem() << endl << endl;
}