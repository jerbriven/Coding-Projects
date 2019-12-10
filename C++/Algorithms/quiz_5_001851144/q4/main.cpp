#include <iostream>
#include "TreeDictionary.h"
#include <string>

using namespace std;

template <class KeyType, class ItemType>
void visit(Entry<KeyType, ItemType>& test) {
    cout << test.getItem() << " ";
}

void addCheck(TreeDictionary<string, string>& currentDict, string key, string item) {
    if (currentDict.containsItem(item)) {
        cout << "Tree already has identifier " << item << endl << endl;
    } else {
        currentDict.add(key, item);
        cout << "Added " << key << " "<< item << endl << endl;
    }
}

int main() {
    // Test that tries to add variable declarations to dictionary
    TreeDictionary<string, string> testTree;
    addCheck(testTree,"int", "num");
    addCheck(testTree,"double", "num2");
    addCheck(testTree,"float", "num3");
    addCheck(testTree,"float", "num");
    testTree.traverse(visit);
}