#include <string>
#ifndef CITY
#define CITY

// Class definition for City
// Contains the index number that corresponds
// to the adjacency matrix
class City
{
private:
	int index;
	string name;
public:
	City();
	City(int num, string cityName);
	void setNum(int num);
	int getIndex();
	string getName();
};

#include "City.cpp"
#endif