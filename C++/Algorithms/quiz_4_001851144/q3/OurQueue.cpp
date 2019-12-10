/** @file OurQueue.h */ 

#include <queue>
#include <iostream>

using  namespace std;

/** Sees whether this queue is empty.
@return True if the queue is empty, or false if not. */
template < class ItemType>
bool OurQueue<ItemType>::isEmpty() const
{
    return objectQueue.empty();
}

/** Adds a new entry to the back of this queue.
@post If the operation was successful, newEntry is at the 
    back of the queue.
@param newEntry  The object to be added as a new entry.
@return True if the addition is successful or false if not. */
template <class ItemType>
bool OurQueue<ItemType>::enqueue(const ItemType& newEntry)
{
    int prevSize = objectQueue.size();
    objectQueue.push(newEntry);
    if (++prevSize == objectQueue.size()) {
        return true;
    } else {
        return false;
    }  
}

/** Removes the front of this queue.
@post If the operation was successful, the front of the queue 
    has been removed.
@return True if the removal is successful or false if not. */
template <class ItemType>
bool OurQueue<ItemType>::dequeue()
{
    int prevSize = objectQueue.size();
    objectQueue.pop();
    if (--prevSize == objectQueue.size()) {
        return true;
    } else {
        return false;
    }
}

/** Returns the front of this queue.
@pre The queue is not empty.
@post The front of the queue has been returned, and the
    queue is unchanged.
@return The front of the queue. */
template <class ItemType>
ItemType OurQueue<ItemType>::peekFront() const
{
    if (!isEmpty()) {
        return objectQueue.front();
    } else {
        //cout << "The queue is empty, can't peek\n";
        return 0;
    }
}