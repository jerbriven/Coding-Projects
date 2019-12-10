#include<iostream>
#include "AdjacencyMatrix.h"

using namespace std;

char key[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

void visited(int &node) {
    cout << key[node] << " ";
}

int main() {
    AdjacencyMatrix<int> simpleGraph;

    simpleGraph.add(0, 1, 1);
    simpleGraph.add(0, 2, 1);
    simpleGraph.add(1, 3, 1);
    simpleGraph.add(1, 7, 1);
    simpleGraph.add(2, 3, 1);
    simpleGraph.add(3, 7, 1);
    simpleGraph.add(2, 4, 1);
    simpleGraph.add(2, 6, 1);
    simpleGraph.add(2, 8, 1);
    simpleGraph.add(4, 6, 1);
    simpleGraph.add(5, 8, 1);
    simpleGraph.add(5, 6, 1);
    simpleGraph.add(6, 7, 1);

    simpleGraph.printMatrix();

    cout << "Number of vertices: " << simpleGraph.getNumVertices() << endl;
    cout << "Number of edges: " << simpleGraph.getNumEdges() << endl;

    cout << "Breadth first search results: ";
    simpleGraph.breadthFirstTraversal(2, visited);
    cout << endl;
    cout << "Depth first search results: ";
    simpleGraph.depthFirstTraversal(2, visited);
    cout << endl;

    cout << "Edge weight of 0-2 is: " << simpleGraph.getEdgeWeight(0, 2) << endl;
    simpleGraph.remove(0, 2);
    cout << "New number of edges is: " << simpleGraph.getNumEdges() << endl;
}