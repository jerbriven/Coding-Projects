#include "ArrayList.h"
#include "ListInterface.h"
#include <iostream>
#include <string>

int count = 0;

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  theArray is sorted into ascending order; n is unchanged.
 @param theArray  The given array.
 @param n  The size of theArray. */
void insertionSort(ListInterface<string>* array, int n)
{
   // unsorted = first index of the unsorted region,
   // loc = index of insertion in the sorted region,
   // nextItem = next item in the unsorted region.
   // Initially, sorted region is theArray[0],
   // unsorted region is theArray[1..n-1].
   // In general, sorted region is theArray[0..unsorted-1],
   // unsorted region theArray[unsorted..n-1]
   for (int unsorted = 1; unsorted < n; unsorted++)
   {
      // At this point, theArray[0..unsorted-1] is sorted.
      // Find the right position (loc) in theArray[0..unsorted]
      // for theArray[unsorted], which is the first entry in the
      // unsorted region; shift, if necessary, to make room
      string nextItem = array->getEntry(unsorted+1);
      int loc = unsorted;
      while ((loc > 0) && (array->getEntry(loc) > nextItem))
      {
         ++count;
         // Shift theArray[loc - 1] to the right
         array->setEntry(loc + 1, array->getEntry(loc));
         loc--;
      }  // end while
      
      // At this point, theArray[loc] is where nextItem belongs
      array->setEntry(loc + 1, nextItem); // Insert nextItem into sorted region
   }  // end for
}  // end insertionSort


int main()
{
   ListInterface<string>* listPtr = new ArrayList<string>();
   string data[] = {"C", "V", "Z", "A", "P", "L"};
   cout << "isEmpty: returns " << listPtr->isEmpty()
   << "; should be 1 (true)" << endl;
   for (int i = 0; i < 6; i++)
   {
      if (listPtr->insert(i + 1, data[i]))
         cout << "Inserted " << listPtr->getEntry(i + 1)
         << " at position " << (i + 1) << endl;
      else
         cout << "Cannot insert " << data[i] << " at position " << (i + 1)
         << endl;
   }  // end for
   
   cout << listPtr->getLength() << endl;
   for (int i = 1; i <= 5; ++i)
      cout << listPtr->getEntry(i) << " ";
   cout << endl;
   insertionSort(listPtr, 5);

   for (int i = 1; i <= 5; ++i)
      cout << listPtr->getEntry(i) << " ";
   return 0;
}  // end main

/*
 isEmpty: returns 1; should be 1 (true)
 Inserted one at position 1
 Inserted two at position 2
 Inserted three at position 3
 Inserted four at position 4
 Inserted five at position 5
 Cannot insert six at position 6
 */