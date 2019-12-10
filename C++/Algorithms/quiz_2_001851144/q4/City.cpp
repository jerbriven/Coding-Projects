#include "City.h"
#include <string>
using namespace std;

// Default constructor
City::City() {}

// Passes values for index and name
City::City(int num, string cityName) {
    index = num;
    name = cityName;
}

// Sets value for index number in graph
void City::setNum(int num) {
    index = num;
}

// Returns value for index number in graph
int City::getIndex() {
    return index;
}

// Returns name of city
string City::getName() {
    return name;
}