#include "LinkedStack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    LinkedStack<string> testPeek;
    // Push strings onto the stack
    testPeek.push("Toys");
    testPeek.push("Presents");
    testPeek.push("Cookies");
    testPeek.push("Hot Chocolate");

    // Tests peek and peek2, expecting Hot Chocolate and Cookies
    cout << "Testing peek returns: " << testPeek.peek() << endl;
    cout << "Testing peek2 returns: " << testPeek.peek2() << endl;

    // Pop 3 times, only one item remains
    testPeek.pop();
    testPeek.pop();
    testPeek.pop();
    
    // Exception should be thrown here
    cout << "Testing peek2 returns: " << testPeek.peek2() << endl;
}