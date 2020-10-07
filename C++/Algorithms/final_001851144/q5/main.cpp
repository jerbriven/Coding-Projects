#include<iostream>
#include "AdjacencyMatrix.h"

using namespace std;

int main() {
    AdjacencyMatrix<int> simpleGraph;

    // Create graph
    simpleGraph.add(0, 1, 2);
    simpleGraph.add(0, 2, 4);
    simpleGraph.add(0, 3, 6);
    simpleGraph.add(1, 2, 5);
    simpleGraph.add(1, 4, 3);
    simpleGraph.add(2, 3, 2);
    simpleGraph.add(2, 4, 2);
    simpleGraph.add(3, 2, 1);
    simpleGraph.add(3, 5, 3);
    simpleGraph.add(3, 4, 5);
    simpleGraph.add(4, 2, 3);
    simpleGraph.add(4, 5, 5);
    simpleGraph.add(4, 6, 1);
    simpleGraph.add(5, 4, 1);
    simpleGraph.add(6, 5, 2);

    // Print matrix
    simpleGraph.printMatrix();

    // Find shortest path between 0 and 6
    cout << "Shortest path between 0 and 6 is: " << simpleGraph.shortestPath(0, 6);
}