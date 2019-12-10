#include<iostream>
#include "AdjacencyMatrix.h"

using namespace std;

void visited(int &node) {
    cout << node << " ";
}

int main() {
    AdjacencyMatrix<int> simpleGraph;
    simpleGraph.add(0, 3, 1);
    simpleGraph.add(0, 2, 1);
    simpleGraph.add(2, 7, 1);
    simpleGraph.add(3, 4, 1);
    simpleGraph.add(0, 7, 1);
    cout << "Number of vertices: " << simpleGraph.getNumVertices() << endl;
    cout << "Number of edges: " << simpleGraph.getNumEdges() << endl;

    cout << "Breadth first search results: ";
    simpleGraph.breadthFirstTraversal(0, visited);
    cout << endl;
    cout << "Depth first search results: ";
    simpleGraph.depthFirstTraversal(0, visited);
    cout << endl;

    cout << "Edge weight of 0-2 is: " << simpleGraph.getEdgeWeight(0, 2) << endl;
    simpleGraph.remove(0, 2);
    cout << "New number of edges is: " << simpleGraph.getNumEdges() << endl;
}