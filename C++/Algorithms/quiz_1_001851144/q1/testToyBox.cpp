#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
   
#include "ToyBox.h"
 
using namespace std;

int main(int argc, char *argv[]) {
   ToyBox<string> toyChest("Race Car", BLUE);
   //ToyBox<string> nameBox; 
   cout << toyChest.getColor() << endl;
   cout << toyChest.getItem() << endl;
   toyChest.setItem("Action Figure");
   cout << toyChest.getItem() << endl;
   cout << toyChest.getColor();
}