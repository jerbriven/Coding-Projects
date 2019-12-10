#include "StackInterface.h"
#include "ArrayStack.h"
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// Pushes all the contents of a string onto a stack 
bool pushAll(ArrayStack<char>* strStack, string item, int itCount) {
    if (itCount < 0) {
        return true;
    }

    strStack->push(item.at(itCount));
    return pushAll(strStack, item, itCount - 1);
}  

// Checks if a string is a palindrome using a stack
bool isPalindrome(ArrayStack<char>* strStack, string item, int itCount) {
    // All characters have been checked
    if (itCount < 0) {
        cout << "\"" << item << "\" is a palindrome" << endl;
        return true;
    // Word is not a palindrome if opposite characters are not the same
    } else if (strStack->peek() != item.at(itCount)) {
        cout << "\"" << item << "\" is not a palindrome" << endl;
        return false;
    }

    // Pop and recursively call function
    strStack->pop();
    return isPalindrome(strStack, item, itCount - 1);
}

// Function that creates a pointer to a stack, and does necessary functions
// to test if its a palindrome
void testString(string stringIn) {
    ArrayStack<char> *palinTest = new ArrayStack<char>;
    pushAll(palinTest, stringIn, stringIn.size() - 1);
    isPalindrome(palinTest, stringIn, stringIn.size() - 1);
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