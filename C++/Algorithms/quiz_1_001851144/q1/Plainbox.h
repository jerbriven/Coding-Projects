/** @file PlainBox.h */

#ifndef _PLAIN_BOX
#define _PLAIN_BOX

// Indicates this is a template definition
// Declaration for the class PlainBox

template<class ItemType>
class PlainBox
{
private:
   // Data field
   ItemType item;
public:
   // Default constructor
   PlainBox();
   // Parameterized constructor
   PlainBox(const ItemType& theItem);
   // Mutator method that can change the value of the data field
   void setItem(const ItemType& theItem);
   // Accessor method to get the value of the data field
   ItemType getItem() const;
};
// end PlainBox

#include "PlainBox.cpp" 

// Include the implementation file

#endif