/** @file LinkedStack.cpp */

#include <cassert>        // For assert
#include "LinkedStack.h"  // Header file
#include "PrecondViolated.h"
#include <iostream>

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : front(nullptr), count(0)
{
}  // end default constructor

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
   // Point to nodes in original chain
   Node<ItemType>* origChainPtr = aStack->front;  
   
   if (origChainPtr == nullptr)
      front = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      front = new Node<ItemType>();
      front->setItem(origChainPtr->getItem());
      
      // Point to last node in new chain
      Node<ItemType>* newChainPtr = front;     
      
      // Copy remaining nodes
      while (origChainPtr != nullptr)
      {
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext(); 
         
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item 
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);  
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr); 
         
         // Advance pointer to new last node      
         newChainPtr = newChainPtr->getNext();   
      }  // end while
      
      newChainPtr->setNext(nullptr);           // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
	// Pop until stack is empty
	while (!isEmpty())
		pop();
}  // end destructor

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return front == nullptr;
}  // end isEmpty

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, front);				
	front = newNodePtr;
   newNodePtr = nullptr;
      
   ++count;
	return true;
}  // end push

template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
      // Stack is not empty; delete top
		Node<ItemType>* nodeToDeletePtr = front;
		front = front->getNext();
		
		// Return deleted node to system
      nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
            
      result = true;
	}  // end if
   
   --count;
	return result;	
}  // end pop

template<class ItemType>	
ItemType LinkedStack<ItemType>::peek() const
{
	assert(!isEmpty());  // Enforce precondition
   
	// Stack is not empty; return top
	return front->getItem();
}  // end getTop
// End of implementation file.

template<class ItemType> 
ItemType LinkedStack<ItemType>::peek2() const throw(PrecondViolated)
{
	if (count <= 1) {
		string message = "Cannot peek2, stack contains less than 2 items"; 
      	throw(PrecondViolated(message)); 
	}
	else {
		Node<ItemType>* nodeToReturn;
      nodeToReturn = front->getNext();
      return nodeToReturn->getItem();
	}
}