#include <iostream>
#include <string>
#include "ArrayList.h"
#include "ListInterface.h"

using namespace std;

// Find max value within bag
template<class ItemType>
int getMax(ListInterface<ItemType>* array, int n) {
    int max = array->getEntry(1);
    for (int i = 0; i < n; ++i) {
        if (array->getEntry(i+1) > max) {
            max = array->getEntry(i+1);
        }
    }
    return max;
}

template<class ItemType>
void digitSort(ListInterface<ItemType>* array, int n, int exp) {
    int out[n];
    int count[n] = {0};

    // Count the number for each digit
    for (int i = 0; i < n; ++i) {
        ++count[(array->getEntry(i+1) / exp) % 10];
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1]; 
    }

    for (int i = n - 1; i >= 0; i--) 
    { 
        // Insert sorted elemnts to out
        out[count[(array->getEntry(i+1)/exp)%10 ] - 1] = array->getEntry(i+1); 
        --count[(array->getEntry(i+1) / exp) % 10 ]; 
    } 

    // Update array based on out
    for (int i = 0; i < n; i++) 
        array->setEntry(i+1, out[i]);
}

// Finds max value of bag and sorts based on each digit
template<class ItemType>
void radixSort(ListInterface<ItemType>* array, int n) {
    int m = getMax(array, n);

    // Sort based on each digit
    for (int i = 1; m / i > 0; i *= 10) {
        digitSort(array, n, i);
    }
}

int main() {
    // Numbers to be stored in the bags
    int a[10] = {100, 20, 1, 9, 32, 27, 44, 3, 999, 8};
    int b[10] = {-20, 20, -1, 1, 32, 27, 50, 3, 999, -9};

    // Bag pointers instantiated
    ListInterface<int>* listPtr = new ArrayList<int>();
    ListInterface<int>* listPtr2 = new ArrayList<int>();

    // Bag items inserted
    for (int i = 0; i < 10; i++)
    {
      listPtr->insert(i + 1, a[i]);
      listPtr2->insert(i + 1, b[i]);
    }

    // Display initial array order
    for (int i = 0; i < 9; ++i) {
        cout << listPtr->getEntry(i+1) << " ";
    }
    cout << endl;
    for (int i = 0; i < 9; ++i) {
        cout << listPtr2->getEntry(i+1) << " ";
    }
    cout << endl;

    // Sort contents of both bags
    radixSort(listPtr, 10);
    radixSort(listPtr2, 10);

    for (int i = 1; i <= 10; ++i) {
        cout << listPtr->getEntry(i) << " ";
    }
    cout << endl;
    for (int i = 1; i <= 10; ++i) {
        cout << listPtr2->getEntry(i) << " ";
    }

}