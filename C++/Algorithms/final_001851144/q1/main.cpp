#include "infix_check.h"
#include <iostream>
#include "string"

using namespace std;

int main() {
    string string1 = "(((c/d)*a)-(a+b))";
    string string2 = "(a+b-c)";
    char char1[50];
    char char2[50];
    for (int i = 0; i < 50; ++i) {
        char1[i] = string1[i];
        char2[i] = string2[i];
    }

    infix_check test1(char1);
    cout << "Is (((c/d)*a)-(a+b)) a valid infix?: " << test1.isValid() << endl;
    infix_check test2(char2);
    cout << "Is (a+b-c) a valid infix?: " << test2.isValid() << endl;
}