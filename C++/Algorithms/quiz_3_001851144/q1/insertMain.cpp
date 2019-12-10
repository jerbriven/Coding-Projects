#include <iostream>
#include <string>

using namespace std;

int count = 0;

template<class ItemType>

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  theArray is sorted into ascending order; n is unchanged.
 @param theArray  The given array.
 @param n  The size of theArray. */
void insertionSort(ItemType theArray[], int n)
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
      ItemType nextItem = theArray[unsorted];
      int loc = unsorted;
      while ((loc > 0) && (theArray[loc - 1] > nextItem))
      {
         ++count;
         // Shift theArray[loc - 1] to the right
         theArray[loc] = theArray[loc - 1];
         loc--;
      }  // end while
      
      // At this point, theArray[loc] is where nextItem belongs
      theArray[loc] = nextItem; // Insert nextItem into sorted region
   }  // end for
}  // end insertionSort



int main()
{
   string a[6] = {"Z", "X", "R", "K", "F", "B"};
   int b[10] = {22, 3, 9, 1, 25, 0, 7, 6, 1, 10};
   insertionSort(a, 6);
   for (int i = 0; i < 6; i++)
      cout << a[i] << " ";
   cout << endl;
   cout << count << endl;

   count = 0;
   insertionSort(b, 10);
   for (int i = 0; i < 10; i++)
      cout << b[i] << " ";
   cout << endl;
   cout << count << endl;
}  // end main