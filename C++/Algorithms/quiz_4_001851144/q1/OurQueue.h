/** @file OurQueue.h */
#ifndef _OUR_QUEUE
#define _OUR_QUEUE
#include <queue>
#include "QueueInterface.h"
using namespace std;


template<class ItemType>
class OurQueue : public QueueInterface<ItemType>
{
private:
    queue<ItemType> objectQueue;
public:
   bool isEmpty() const;
   bool enqueue(const ItemType& newEntry);
   bool dequeue();
   ItemType peekFront() const;
}; // end QueueInterface
#include "OurQueue.cpp"
#endif