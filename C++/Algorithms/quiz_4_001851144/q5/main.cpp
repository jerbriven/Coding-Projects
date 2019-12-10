#include <iostream>
#include "LinkedQueue.h"

using namespace std;

int main() {
    // Test matrix for the queue
    int a[10] = {9, 2, 1, 5, 10, 21, 3, 54, 100, 11};
    LinkedQueue<int> queue;
    for (int i = 0; i < 10; ++i) {
        queue.enqueue(a[i]);
    }
    queue.read();
    for (int i = 0; i < 10; ++i) {
        queue.dequeue();
        queue.read();
    }
}