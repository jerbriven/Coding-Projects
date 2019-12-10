#include "Graph.h"
#include "LinkedStack.h"
using namespace std;
#include <string>
#include <iostream>

// Default constructor, initializes count and adjacency matrix
Graph::Graph()
{
    count = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            adj[i][j] = 0;
        }
    }
}

// Adds cities to the graph
void Graph::addCity(string cityName) {
    City add(count, cityName);
    cityList[count] = add;
    ++count;
}

// Returns the index number of the city within the graph
int Graph::returnIndex(string cityName) {
    int index;
    for (int i = 0; i < 10; ++i) {
        if (cityList[i].getName() == cityName) {
            index = cityList[i].getIndex();
        } 
    }
    return index;
}

// Adds a directed flight path
void Graph::addDest(string city1, string city2) {
    adj[returnIndex(city1)][returnIndex(city2)] = 1;
}

// Prints the adjacency matrix for debugging
void Graph::printArray() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// Clears the visited matrix
void Graph::unvisitAll() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            visited[i][j] = 0;
        }
    }
}

// Finds the next path to a city that hasn't been visited
string Graph::getNextCity(string pathCity) {
    int row = returnIndex(pathCity);
    // Indicator that there is no more paths from the current city
    string nextCity = "No City";
    for (int i = 0; i < 10; ++i) {
        if (adj[row][i] == 1 && visited[row][i] != 1) {
            nextCity = cityList[i].getName();
        }
    }
    return nextCity;
}

// Marks the visited matrix
void Graph::markVisited(string origin, string dest) {
    visited[returnIndex(origin)][returnIndex(dest)] = 1;
}

// Determines whether or not a path exists from one city to another
bool Graph::isPath(string originCity, string destinationCity)
{
   bool success;
   LinkedStack<string> aStack;
   unvisitAll(); // Clear marks on all cities
    // Push origin city onto aStack and mark it as visited
   aStack.push(originCity);
   
   string topCity = aStack.peek();
   while (!aStack.isEmpty() && (topCity != destinationCity))
   {
      // The stack contains a directed path from the origin city
      // at the bottom of the stack to the city at the top of
      // the stack
      
      // Find an unvisited city adjacent to the city on the
      // top of the stack
      string nextCity = getNextCity(topCity);
      
      if (nextCity == "No City")
         aStack.pop(); // No city found; backtrack
      else // Visit city
      {
        
         aStack.push(nextCity);
         markVisited(topCity,nextCity);
      } // end if
      
      if (!aStack.isEmpty())
         topCity = aStack.peek();
   } // end while
   
   return !aStack.isEmpty();
} // end isPath