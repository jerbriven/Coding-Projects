using namespace std;
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <sstream>
#include "Graph.h"

// Seperates a string into two, seperated by a comma
vector <string> twoStr(string split) {
    // Uses stringstream
    vector <string> tokens; 
    stringstream ss(split); 
    string intermediate; 
      
    while(getline(ss, intermediate, ',')) 
    { 
        tokens.push_back(intermediate); 
    } 
    return tokens;
}

// Adds the cities from cityFile.txt to Graph
void addCities(Graph* fileGraph) {
    string word[7];
    ifstream file("cityFile.txt");
    // Reads each line of the text file
    if (file.is_open()) {
        for (int i = 0; i <= 6; ++i) {
            file >> word[i];
        }
    }
    file.close();

    // Adds each city to the Graph
    for (int i = 0; i <= 6; ++i) {
        fileGraph->addCity(word[i]);
    }
}

// Adds the destinations from flightFile.txt to Graph
void addDests(Graph* fileGraph) {
    string word[7];
    ifstream file2("flightFile.txt");
    // Reads each line of the text file
    if (file2.is_open()) {
        for (int i = 0; i <= 6; ++i) {
            file2 >> word[i];
        }
    }
    file2.close();

    // Stores two cities in vector
    vector <string> token1;
    for (int i = 0; i <= 6; ++i) {
        token1 = twoStr(word[i]);
        // Adds each destination to Graph
        fileGraph->addDest(token1[0],token1[1]);
    }
}

// Checks if the requests in requestFile.txt are valid in Graph
void checkReqs(Graph* fileGraph) {
    string word[8];
    ifstream file3("requestFile.txt");
    // Reads each line of the text file
    if (file3.is_open()) {
        for (int i = 0; i <= 7; ++i) {
            file3 >> word[i];
        }
    }
    file3.close();

    // Stores two cities in a vector
    vector <string> token2;
    cout << "\n";
    for (int i = 0; i <= 7; ++i) {
        token2 = twoStr(word[i]);
        // Outputs whether or not there is a flight path
        if (fileGraph->isPath(token2[0],token2[1])) {
            cout << "Flight is present from " << token2[0] 
                 << " to " << token2[1] << endl << endl;
        } else {
            cout << "Sorry, no flight from " << token2[0] 
                 << " to " << token2[1] << endl << endl;
        }
    }
}

int main() {
    // Initializes pointer to Graph and records data
    Graph *testGraph = new Graph();
    addCities(testGraph);
    addDests(testGraph);
    checkReqs(testGraph);
}