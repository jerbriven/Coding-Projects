#include "Node.h"
#include "City.h"
#ifndef GRAPH
#define GRAPH

// Class definition for Graph
// Contains an adjacency matrix
// Contains a list of cities that are represented
// in the adjacency matrix
class Graph
{
private:
	int adj[10][10];
    int visited[10][10];
	int num;
    City cityList[10];
    int count;

public:
    Graph();
    void addCity(string cityName);
    int returnIndex(string cityName);
    void addDest(string city1, string city2);
    void printArray();
    bool isPath(string originCity, string destinationCity);
    void unvisitAll();
    void markVisited(string origin, string dest);
    string getNextCity(string pathCity);
};

#include "Graph.cpp"
#endif