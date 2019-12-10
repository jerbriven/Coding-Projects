#include "ArrayDictionary.h"
#include <iostream>
#include <string>

using namespace std;

// Defines a cout statement for visit
template <class ItemType>
void visit(ItemType Item) {
    cout << Item << endl;
}

void testContains(ArrayDictionary<int, string> test, int keyTest) {
    // Tests contains
    if (test.contains(keyTest)) {
        // Tests getItem
        cout << "Key " << keyTest << " is in the dictionary, contains: " 
             << test.getItem(keyTest) << endl << endl;
    } else {
        cout << "Key " << keyTest << " is not in the dictionary" << endl << endl;
    }
}

void checkEmpty(ArrayDictionary<int, string> test) {
    if (test.isEmpty()) {
        cout << "Dictionary is empty\n\n";
    } else {
        cout << "Dictionary contains items\n\n";
    }
}

int main()
{
    // Items are names, keys are birthday months
    ArrayDictionary<int, string> testDict;
    testDict.add(6, "Jeremy");
    testDict.add(1, "Tricia");
    testDict.add(10, "Jordan");
    testDict.add(7, "Tim");

    int num = testDict.getNumberOfItems();
    cout << "This dictionary contains: " << num << " key/item pairs\n\n";

    // Test traversal
    testDict.traverse(visit);

    // Testing contains and getItem
    testContains(testDict, 10);
    testContains(testDict, 3);

    // Testing remove
    testDict.remove(1);
    cout << "Removing Key 1......." << endl;
    testDict.traverse(visit);

    // Testing clear
    testDict.clear();
    checkEmpty(testDict);

    testDict.~ArrayDictionary();
}