#include "BagInterface.h"
#include "LinkedBag.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    LinkedBag<string> bagPtr;
    bagPtr.readForward();
    bagPtr.addFirst("Test");
    bagPtr.addFirst("Car");
    bagPtr.readForward();
    bagPtr.removeFirst();
    bagPtr.readForward();

    bagPtr.addLast("Truck");
    bagPtr.readForward();
    bagPtr.removeLast();
    bagPtr.addLast("Giraffe");
    bagPtr.readForward();
    bagPtr.readFirst();
    bagPtr.readLast();
    bagPtr.removeLast();
    bagPtr.readForward();

    cout << "All done!" << endl;
   
    return 0;
} 

