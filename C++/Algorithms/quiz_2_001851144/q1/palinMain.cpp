#include<iostream>
#include<string>

using namespace std;

// Recursive function that determines whether a word is a palindrome
string isPalindrome(string palin) {
    if (palin.length() == 1 || palin.length() == 0)
        return "String is a palindrome.";
    else if (palin.back() == palin.front()) {
       palin.erase(0,1);
       palin.erase(palin.length() - 1);
       return isPalindrome(palin);
    } else
        return "String is not a palindrome.";
}

int main() {
    // Tests for various palindromes and not plaindrome strings
    string test = "abcdpdcba";
    string test2 = "money";
    string test3 = "rats star";
    string test4 = "algorithms";
    string test5 = "racecar";
    string test6 = "a";
    string test7 = "bb";
    string test8 = "";
    cout << isPalindrome(test) << endl;
    cout << isPalindrome(test2) << endl;
    cout << isPalindrome(test3) << endl;
    cout << isPalindrome(test4) << endl;
    cout << isPalindrome(test5) << endl;
    cout << isPalindrome(test6) << endl;
    cout << isPalindrome(test7) << endl;
    cout << isPalindrome(test8) << endl;
}