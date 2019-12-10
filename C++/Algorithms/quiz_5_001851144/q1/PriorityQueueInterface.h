/** ADT priority queue.
@file PriorityQueueInterface.h */

#ifndef _PRIORITY_QUEUE_INTERFACE
#define _PRIORITY_QUEUE_INTERFACE

template<class ItemType>
class PriorityQueueInterface
{
public:
	virtual bool isEmpty() const = 0;
	virtual bool add(const ItemType& newEntry) = 0;
	virtual bool remove() = 0;
	virtual ItemType peek() const = 0;
};
#endif

