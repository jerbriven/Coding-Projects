#include <iostream>
#include "OurQueue.h"
#include <string>
#include <queue>

using namespace std;

template <class ItemType>
void checkEmpty(OurQueue<ItemType> Queue) {
    if (Queue.isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue is not empty\n";
    }
}

int main() {
    OurQueue<string> testQueue;
    // Checking if the queue is empty
    checkEmpty(testQueue);

    // Testing the enqueue member function
    if(testQueue.enqueue("Cat")) {
        cout << "Cat was added to the back of Queue\n";
    } else {
        cout << "Cat failed to be added to the back Queue\n";
    }

    // The queue should be no longer empty
    checkEmpty(testQueue);

    // Adding extra items to the queue
    testQueue.enqueue("Dog");
    testQueue.enqueue("Lizard");

    // Testing the peekFront member function
    cout << testQueue.peekFront()
        << " is at the front of the Queue\n";
    
    // Testing the dequeque member function
    if(testQueue.dequeue()) {
        cout << "The item at the front of the queue was removed\n";
    } else {
        cout << "Removing the first item failed\n";
    }
}