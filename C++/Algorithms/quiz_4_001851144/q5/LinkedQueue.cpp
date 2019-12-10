/** @file LinkedQueue.cpp */

#include "LinkedQueue.h"  // Header file
#include <iostream>
using namespace std;

template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue() : front(nullptr), rear(nullptr)
{
}  // end default constructor

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	// Pop until Queue is empty
	while (!isEmpty())
		dequeue();
}  // end destructor

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
	return front == nullptr && rear == nullptr;
}  // end isEmpty

// Adds items to the end of the queue
template<class ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newItem)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem);	

   // Instantiates circular list
   if (isEmpty()) {
      front = newNodePtr;
      rear = newNodePtr;
      newNodePtr->setNext(rear);
   // Adds item to end, updates rear
   } else {
      rear->setNext(newNodePtr);
      newNodePtr->setNext(front);
      rear = newNodePtr;
   }	     
   newNodePtr = nullptr;
	return true;
}  // end push

// Removes an item from the front of the queue
template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;
   Node<ItemType>* nodeToDeletePtr = front;
   // Removes last item in queue, resets queue to empty state
   if (front == rear) {
      nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
      result = true;
      front = nullptr;
      rear = nullptr;
   }
	else if (!isEmpty())
	{
      // Queue is not empty; delete front
		front = front->getNext();
      rear->setNext(front);
		
		// Return deleted node to system
      nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
            
      result = true;
	}  // end if
   
	return result;	
}  // end pop

template<class ItemType>	
void LinkedQueue<ItemType>::read()
{
   // Displays all items of the queue
   if (!isEmpty()) {
	   Node<ItemType>* currentPtr = front;
      cout << currentPtr->getItem() << " ";
      currentPtr = currentPtr->getNext();
      while (currentPtr != front) {
         cout << currentPtr->getItem() << " ";
         currentPtr = currentPtr->getNext();
      }
      cout << endl;
   // The queue contains no items
   } else {
      cout << "The Queue is empty" << endl;
   }
} 
