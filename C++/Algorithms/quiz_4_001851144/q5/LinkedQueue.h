/** ADT Queue: Link-based implementation.
    @file LinkedQueue.h */
 
#ifndef _LINKED_QUEUE
#define _LINKED_QUEUE

#include "Node.h"

template<class ItemType>
class LinkedQueue
{
private:
	Node<ItemType>* front; // Pointer to first node in the chain;
    Node<ItemType>* rear; // Pointer to last node in the chain

public:
// Constructors and destructor:
	LinkedQueue();                                   // Default constructor
	virtual ~LinkedQueue();                          // Destructor
	
// Queue operations:
	bool isEmpty() const;
	bool enqueue(const ItemType& newItem);
	bool dequeue();
	void read();
}; // end LinkedQueue

#include "LinkedQueue.cpp"
#endif