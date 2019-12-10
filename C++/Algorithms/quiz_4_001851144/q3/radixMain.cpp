#include <iostream>
#include <string>
#include "OurQueue.h"
#include <bits/stdc++.h>

using namespace std;

// Pushes all the contents of a string onto a queue 
template<class ItemType>
bool pushAll(OurQueue<ItemType>* strQueue, ItemType item[], int itCount, int size) {
    if (itCount >= size) {
        return true;
    }
    strQueue->enqueue(item[itCount]);
    return pushAll(strQueue, item, itCount + 1, size);
}  

// Reads all the current elements in the queue, for debugging
template<class ItemType>
void readAll(OurQueue<ItemType>* strQueue, ItemType temp[]) {
    while (!strQueue->isEmpty()) {
        cout << strQueue->peekFront() << " ";
        strQueue->dequeue();
    }
    cout << endl;
    pushAll(strQueue, temp, 0, 10);
}  

// Find max value within bag
template<class ItemType>
int getMax(OurQueue<ItemType>* array, int n, ItemType temp[]) {
    OurQueue<ItemType> *testQueue = array;
    int max = testQueue->peekFront();
    for (int i = 0; i < n; ++i) {
        testQueue->dequeue();
        if (testQueue->peekFront() > max) {
            max = testQueue->peekFront();
        }
    }
    pushAll(array, temp, 0, 10);
    return max;
}

template<class ItemType>
void digitSort(OurQueue<ItemType>* array, int n, int exp, ItemType temp[]) {
    int out[n];
    int count[n] = {0};

    // Updates temp based on the queue
    for (int i = 0; i < n; ++i) {
        temp[i] = array->peekFront();
        array->dequeue();
    }
    pushAll(array, temp, 0, n);
    
    // Count the number for each digit
    for (int i = 0; i < n; ++i) {
        ++count[(array->peekFront() / exp) % 10];
        array->dequeue();
    }
    pushAll(array, temp, 0, n);

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1]; 
    }

    for (int i = 0; i < n; i++) 
    { 
        // Insert sorted elemnts to out
        out[count[(array->peekFront()/exp)%10 ] - 1] = array->peekFront(); 
        --count[(array->peekFront() / exp) % 10 ]; 
        array->dequeue();
    } 

    // Update array based on out
    for (int i = n - 1; i >= 0; i--) {
        array->enqueue(out[i]);
    }
} 

// Finds max value of bag and sorts based on each digit
template<class ItemType>
void radixSort(OurQueue<ItemType>* array, int n, ItemType temp[]) { 
    int m = getMax(array, n, temp);

    // Sort based on each digit
    for (int i = 1; m / i > 0; i *= 10) {
        digitSort(array, n, i, temp);
    }
} 

int main() {
    // Numbers to be stored in the bags
    int a[10] = {100, 20, 1, 9, 32, 27, 44, 3, 999, 8};

    // Bag pointers instantiation
    OurQueue<int> *listPtr = new OurQueue<int>;

    pushAll(listPtr, a, 0, 10);
    readAll(listPtr, a);

    // Sort contents of both bags
    radixSort(listPtr, 10, a);

    for (int i = 1; i <= 10; ++i) {
        a[i-1] = listPtr->peekFront();
        listPtr->dequeue();
    }

    // Reads the queue in reverse
    for (int i = 9; i >= 0; --i) {
        cout << a[i] << " ";
    }
}