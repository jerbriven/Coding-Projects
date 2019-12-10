#include <iostream>
#include "Heap_PriorityQueue.h"
#include <string>

using namespace std;


void read(Heap_PriorityQueue <int> &prQueue, int size, string list[]) {
    if (prQueue.isEmpty()) {
        cout << "The priority queue is empty\n\n";
    }
    else {
        // Stores items of queue
        int temp[size];
        for (int i = 0; i < size; ++i) {
            cout << list[prQueue.peek()] << endl;
            temp[i] = prQueue.peek();
            prQueue.remove();
        }
        // Refills queue with original items
        for (int i = 0; i < size; ++i) {
            prQueue.add(temp[i]);
        }
        cout << endl;
    }
}

int main() {
    Heap_PriorityQueue <int> test;
    string listTasks[4];
     
    // Test the isEmpty() function by reading an empty queue
    read(test, 4, listTasks);

    // Set priorities for tasks
    listTasks[2] = "Send a birthday card to Aunt Mabel.";
    listTasks[3] = "Start the research paper for world history.";
    listTasks[0] = "Finish reading Chapter 19 of Walls and Mirrors.";
    listTasks[1] = "Make plans for Saturday night.";

    // Add priorities
    for (int i = 0; i < 4; ++i)
        test.add(i);

    // Read queue for testing
    read(test, 4, listTasks);
    // Remove highest priority item
    test.remove();
    read(test, 3, listTasks);
}