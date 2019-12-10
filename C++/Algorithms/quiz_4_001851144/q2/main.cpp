#include "OurQueue.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Pushes all the contents of a string onto a queue 
bool pushAll(OurQueue<char>* strQueue, string item, int itCount) {
    if (itCount < 0) {
        return true;
    }

    strQueue->enqueue(item.at(itCount));
    return pushAll(strQueue, item, itCount - 1);
}  

// Checks if a string is a palindrome using a queue
bool isPalindrome(OurQueue<char>* strQueue, string item, int itCount, int size) {
    // All characters have been checked
    if (itCount > size) {
        cout << "\"" << item << "\" is a palindrome" << endl;
        return true;
    // Word is not a palindrome if opposite characters are not the same
    } else if (strQueue->peekFront() != item.at(itCount)) {
        cout << "\"" << item << "\" is not a palindrome" << endl;
        return false;
    }

    // Pop and recursively call function
    strQueue->dequeue();
    return isPalindrome(strQueue, item, itCount + 1, size);
}

// Function that creates a pointer to a stack, and does necessary functions
// to test if its a palindrome
void testString(string stringIn) {
    OurQueue<char> *palinTest = new OurQueue<char>;
    pushAll(palinTest, stringIn, stringIn.size() - 1);
    isPalindrome(palinTest, stringIn, 0, stringIn.size() - 1);
}

int main() {
    // Test cases
    testString("racecar");
    testString("null");
    testString("a");
    testString("");
    testString("aa");
    testString("rats star");
}