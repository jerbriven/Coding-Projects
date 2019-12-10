/** ADT list: Array-based implementation. @file ArrayList.h */

#ifndef _ARRAY_LIST
#define _ARRAY_LIST

#include "ListInterface.h"
#include "PrecondViolated.h"

template<class ItemType>
class ArrayList : public ListInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 10; // Small capacity to test for a full list 
	ItemType items[DEFAULT_CAPACITY];      // Array of list items
   int itemCount;                         // Current count of list items 
   int maxItems;                          // Maximum capacity of the list
   
public:
   ArrayList();
   // Copy constructor and destructor are supplied by compiler
   
   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool remove(int position);
   void clear();
   
   /** @throw PrecondViolated if position < 1 or position > getLength(). */
   ItemType getEntry(int position) const throw(PrecondViolated);

   /** @throw PrecondViolated if position < 1 or position > getLength(). */
   void setEntry(int position, const ItemType& newEntry) throw(PrecondViolated);
}; // end ArrayList

#include "ArrayList.cpp"
#endif 