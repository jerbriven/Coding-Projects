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

template<class ItemType>
void shellSort(ItemType theArray[], int n)
{
   for (int h = n / 2; h > 0; h = h / 2)
   {
      for (int unsorted = h; unsorted < n; unsorted++)
      {
        ItemType nextItem = theArray[unsorted];
        int loc = unsorted;
        while ( (loc >= h) && (theArray[loc - h] > nextItem) )
        {
            ++count;
            theArray[loc] = theArray[loc - h];
            loc = loc - h;
        } // end while
        theArray[loc] = nextItem;
      }  // end for
   }  // end for
}  // end shellSort

int main()
{
    // Arrays to be sorted
    string a[6] = {"Z", "X", "R", "K", "F", "B"};
    int b[10] = {22, 3, 9, 1, 25, 0, 7, 6, 1, 10};
    string c[6] = {"Z", "X", "R", "K", "F", "B"};
    int d[10] = {22, 3, 9, 1, 25, 0, 7, 6, 1, 10};

    // Insertion sort of first array
    insertionSort(a, 6);
    for (int i = 0; i < 6; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << count << endl;

    // Insertion sort of second array
    count = 0;
    insertionSort(b, 10);
    for (int i = 0; i < 10; i++)
        cout << b[i] << " ";
    cout << endl;
    cout << count << endl;

    // Shell sort of first array
    count = 0;
    shellSort(c, 6);
    for (int i = 0; i < 6; i++)
        cout << c[i] << " ";
    cout << endl;
    cout << count << endl;

    // Shell sort of second array
    count = 0;
    shellSort(d, 10);
    for (int i = 0; i < 10; i++)
        cout << d[i] << " ";
    cout << endl;
    cout << count << endl;
}  // end main