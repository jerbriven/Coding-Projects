/** ADT stack: Link-based implementation.
    @file LinkedStack.h */
 
#ifndef _LINKED_STACK
#define _LINKED_STACK

#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedStack
{
private:
	Node<ItemType>* front;
	

public:
// Constructors and destructor:
	LinkedStack();                                   // Default constructor
	
// Stack operations:
	bool isEmpty() const;
	bool push(const ItemType& newItem);
	bool pop();
	void read();
}; // end LinkedStack

#include "LinkedStack.cpp"
#endif