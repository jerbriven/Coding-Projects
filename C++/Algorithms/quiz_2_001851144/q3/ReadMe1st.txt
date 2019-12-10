To run my code, you can execute stackTest.exe. You can also
compile the main.cpp file. I used the Array Stack implementation
for another solution to the palindrome problem. I have similar
test cases in main. Then I call a palindrome tester function.
This first calls a function that pushes the string onto a 
character stack. Then, the isPalindrome function is called.
It reads through the string, and compares the characters to 
the top item of the stack. If the characters are ever not 
equal, then the word is not a palindrome. If the string has
been completely checked, then it must be a palindrome.

bool pushAll(stack, string, index)
    if (all characters pushed)
        return true

    push(current character)
    return pushAll(next character)

bool isPalindrome(stack, string, index)
    if (all characters checked)
        print(this word is a palindrome)
        return true
    else if (characters are not mirrored)
        print(this word is not a palindrome)
        return false

    popStack()
    return isPalindrome(next index)