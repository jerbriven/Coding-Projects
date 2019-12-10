/** @file ArrayStack.cpp */
#include <cassert>       // For assert
#include "ArrayStack.h"  // Header file
#include <iostream>
using namespace std;

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
}  // end default constructor

// Copy constructor and destructor are supplied by the compiler

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
	return top < 0;	
}  // end isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
	bool result = false;	
	if (top < MAX_STACK - 1)  // Does stack have room for newEntry?
	{
		++top;
		items[top] = newEntry;
		result = true;
	}  // end if
   
	return result;
}  // end push


template<class ItemType>
ItemType ArrayStack<ItemType>::pop()
{
	if (!isEmpty())
	{
        --top;
		return true;
	}   
	return false;
}  // end pop


template<class ItemType> 
ItemType ArrayStack<ItemType>::peek() const
{
	assert(!isEmpty());  // Enforce precondition
   
	// Stack is not empty; return top
	return items[top];
}  // end peek
// End of implementation file.
