#include <iostream>
#include <string>
#include <fstream>
#include "ArrayBag.h"

using namespace std;

void displayBag(ArrayBag<string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize()
        << " items:" << endl;
   vector<string> bagItems = bag.toVector();
   
   int numberOfEntries = (int) bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      cout << bagItems[i] << " ";
   }  // end for
	cout << endl << endl;
}  // end displayBag

void bagTester(ArrayBag<string>& bag)
{
   cout << "isEmpty: returns " << bag.isEmpty() 
        << "; should be 1 (true)" << endl;
   displayBag(bag);

	string items[] = {"The", "dog", "walked", "to", "the", "store"};
   cout << "Add 6 items to the bag: " << endl;
	for (int i = 0; i < 6; i++)
   {
		bag.add(items[i]);
	}  // end for
   
   displayBag(bag);
   
   cout << "isEmpty: returns " << bag.isEmpty() 
        << "; should be 0 (false)" << endl;
	
   cout << "getCurrentSize: returns " << bag.getCurrentSize() 
        << "; should be 6" << endl;
   
   cout << "Try to add another entry: add(\"extra\") returns " 
        << bag.add("extra") << endl;      
   
   cout << "contains(\"three\"): returns " << bag.contains("three")
        << "; should be 1 (true)" << endl;
   cout << "contains(\"ten\"): returns " << bag.contains("ten")
        << "; should be 0 (false)" << endl;
   cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one") << " should be 2" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 1 (true)" << endl;
   cout << "getFrequencyOf(\"one\"): returns "
        << bag.getFrequencyOf("one") << " should be 1" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 1 (true)" << endl;
   cout << "remove(\"one\"): returns " << bag.remove("one")
        << "; should be 0 (false)" << endl;
   cout << endl;
   
   displayBag(bag);
   
   cout << "After clearing the bag, ";
   
   cout << "isEmpty: returns " << bag.isEmpty()
        << "; should be 1 (true)" << endl;
}  // end bagTester

int main()
{
	ArrayBag<string> bag;
	cout << "Testing the Array-Based Bag:" << endl;
   cout << "The initial bag is empty." << endl;
	bagTester(bag);
   cout << "All done!" << endl << endl 
        << "Beginning Dictionary Check" << endl << endl;
   
    string word[6]; 
    fstream myfile;
    ifstream file("spellCheck.txt");
    if (file.is_open()) {
        for (int i = 0; i <= 5; ++i) {
            file >> word[i];
        }
    }

    for (int i = 0; i <= 5; ++i) {
        if (bag.contains(word[i])) {
            cout << "(" << word[i] << ")" 
                 << " is spelled correctly" << endl;
        } else {
            cout << "("<< word[i] <<  ")" 
                 << " is mispelled" << endl;
        }
    }

    myfile.close();

    return 0;
}  // end main

/*
 Testing the Array-Based Bag:
 The initial bag is empty.
 isEmpty: returns 1; should be 1 (true)
 The bag contains 0 items:
 
 
 Add 6 items to the bag:
 The bag contains 6 items:
 one two three four five one
 
 isEmpty: returns 0; should be 0 (false)
 getCurrentSize: returns 6; should be 6
 Try to add another entry: add("extra") returns 0
 contains("three"): returns 1; should be 1 (true)
 contains("ten"): returns 0; should be 0 (false)
 getFrequencyOf("one"): returns 2 should be 2
 remove("one"): returns 1; should be 1 (true)
 getFrequencyOf("one"): returns 1 should be 1
 remove("one"): returns 1; should be 1 (true)
 remove("one"): returns 0; should be 0 (false)
 
 The bag contains 4 items:
 five two three four
 
 After clearing the bag, isEmpty: returns 1; should be 1 (true)
 All done!
 */