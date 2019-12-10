#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
   
#include "PlainBox.h"
 
using namespace std;

int main(int argc, char *argv[]) {
   PlainBox<double> numberBox(2);
   PlainBox<string> nameBox; 
   cout << numberBox.getItem();
}