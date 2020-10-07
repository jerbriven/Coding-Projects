/** ADT stack: Link-based implementation.
    @file LinkedStack.h */
 
#ifndef _LINKED_STACK
#define _LINKED_STACK

#include "StackInterface.h"
#include "Node.h"
#include "PrecondViolated.h"

template<class ItemType>
class LinkedStack
{
private:
	Node<ItemType>* front;
	int count;
	

public:
// Constructors and destructor:
	LinkedStack();                                   // Default constructor
	LinkedStack(const LinkedStack<ItemType>& aStack);
	~LinkedStack();

// Stack operations:
	bool isEmpty() const;
	bool push(const ItemType& newItem);
	bool pop();
	void read();
	ItemType peek() const;
	ItemType peek2() const throw(PrecondViolated);
}; // end LinkedStack

#include "LinkedStack.cpp"
#endif