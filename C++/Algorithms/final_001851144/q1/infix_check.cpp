#include "infix_check.h"
#include <string>

// Constructor
infix_check::infix_check(char init_infix[])
{
    exp = new char[100];
    exp = init_infix;
}

// Determines if valid expression
bool infix_check::findExpression(int* index)
{
    if(!findTerm(index))
			return false;
    if(exp[*index] == '+' || exp[*index] == '-')
    {
        (*index)++;
        return findTerm(index);
    }
    return true;
}

// Determines if valid term
bool infix_check::findTerm(int* index)
{
    if(!findFactor(index))
        return false;
    if(exp[*index] == '*' || exp[*index] == '/')
    {
        (*index)++;
        return findFactor(index);
    }
    return true;
}

// Determines if valid factor
bool infix_check::findFactor(int* index)
{
    if(isLetter(index))
        return true;
    if(exp[*index] == '(')
    {
        (*index)++;
        if(!findExpression(index))
            return false;
        if(exp[*index] == ')')
        {
            (*index)++;
            return true;
        }
    }
    return false;
}

// Base case, checks for a letter
bool infix_check::isLetter(int* index)
{
    for(int i = 0; i < 26; i++)
    {
        if(exp[*index] == letterAlphabet[i])
        {
            (*index)++;
            return true;
        }
    }
    return false;
}

// Calls findExpression to see if its a valid infix
bool infix_check::isValid()
{
    int* index = new int;
    *index = 0;
    if(!findExpression(index))
        return false;
    if(exp[*index] != '\0')
        return false;
    return true;
}