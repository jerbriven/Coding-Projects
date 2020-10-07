#ifndef INFIX_CHECK
#define INFIX_CHECK

#include <iostream>
using namespace std;

class infix_check
{
    private:
        char *exp;
        bool findExpression(int* index);
        bool findTerm(int* index);
        bool findFactor(int* index);
        bool isLetter(int* index);
        char letterAlphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    public:
        infix_check(char init_infix[]);
        bool isValid();
};

#include "infix_check.cpp"

#endif