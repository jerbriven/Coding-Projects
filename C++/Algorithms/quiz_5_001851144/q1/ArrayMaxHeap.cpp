/** Array-based implementation of the ADT heap.
 @file ArrayMaxHeap.cpp */

#include "ArrayMaxHeap.h"
#include "PrecondViolatedExcep.h"
#include <cmath>

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const
{
   return (2 * nodeIndex) + 2;
}  // end getRightChildIndex

// Returns parent index given some node index
template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int nodeIndex) const
{
   return (nodeIndex - 1)/2;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const
{
    // A node is a leaf if both its children are outside the current array bounds
    if (!(getLeftChildIndex(nodeIndex) < itemCount) && !(getRightChildIndex(nodeIndex) < itemCount)) {
        return true;
    }
    else {
        return false;
    }
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subRootIndex) {
    // Rebuilds heap so that it is semi ordered
    // Swaps parent with child if child is larger
    if (!isLeaf(subRootIndex)) {
        // Index of left child is assumed to be largest child
        int largestChildIndex = 2 * subRootIndex + 1;

        if (getRightChildIndex(subRootIndex) != 0) {
            int rightChildIndex = largestChildIndex + 2;
            if (items[rightChildIndex] > items[largestChildIndex]) {
                // Right child must be larger
                largestChildIndex = rightChildIndex;
            }
        }

        if (items[subRootIndex] <= items[largestChildIndex]) {
            // Make larger child new parent, swap the two values
            swap(items[largestChildIndex], items[subRootIndex]);
            // Recursively call function on the larger child index
            heapRebuild(largestChildIndex);
        }
    }
    // If we arrive at a root, the fucntion is completed
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate() 
{
   for (int index = itemCount / 2; index >= 0; index--)
   {
      heapRebuild(index);  
   }  // end for
}  // end heapCreate

// Default constructor, initialize itemcount to 0, and use default capacity
template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(): itemCount(0), maxItems(DEFAULT_CAPACITY) {
    // allocates memory based on default capacity for items
    items = new ItemType[maxItems];
}

template<class ItemType>
ArrayMaxHeap<ItemType>::
ArrayMaxHeap(const ItemType someArray[], const int arraySize):
             itemCount(arraySize), maxItems(2 * arraySize)
{
   // Allocate the array
   items = new ItemType[2 * arraySize];
   
   // Copy given values into the array
   for (int i = 0; i < itemCount; i++)
      items[i] = someArray[i];
   
   // Reorganize the array into a heap
   heapCreate();
} // end constructor

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{
    // Destructor removes the array memory
    delete[] items;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
    // Returns false if itemCount is 0, otherwise return 1
    if (itemCount == 0)
        return true;
    else
    {
        return false;
    }
    
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
    // Add 1 to itemCount to get number of nodes
    return itemCount + 1;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
    // Compute height
    return ceil(log2(itemCount + 1));
}

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw(PrecondViolatedExcep)
{
   if (isEmpty())
      throw PrecondViolatedExcep("Attempted peek into an empty heap.");
   
   return items[0];
} // end peekTop

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData)
{
    // Reached maximum, can't add items
    if (itemCount == maxItems) {
        return false;
    }

    // Add new item to array
    items[itemCount] = newData;

    // Initialize index for new item
    int newDataIndex = itemCount;
    bool check = false;

    // Reorder until item is placed correctly or its index is less than or equal to 0
    while (newDataIndex > 0 && !check) {
        // Find parent index
        int parentIndex = (newDataIndex - 1) / 2;

        // If parent is greater than child, we are done
        if (items[newDataIndex] <= items[parentIndex]) 
        {
            check = true;
        }
        else
        {
            // We must swap parent with child
            swap(items[parentIndex], items[newDataIndex]);
            newDataIndex = parentIndex;
        }
    }

    // New item must be ordered in heap correctly
    ++ itemCount;
    return true;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
    // Can't remove if heap is empty
    if (isEmpty())
        return false;

    // Move last node to root
    items[0] = items[itemCount - 1];

    // Remove last node
    --itemCount;

    // Fix heap structure with removal
    heapRebuild(0);

    // Success
    return true;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
	// Changes itemCount to 0
	itemCount = 0;
} 