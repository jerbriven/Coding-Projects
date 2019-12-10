#include "AdjacencyMatrix.h"
#include <vector>
#include <iostream>

using namespace std;

template<class LabelType>
AdjacencyMatrix<LabelType>::AdjacencyMatrix()
{}

template<class LabelType>
void AdjacencyMatrix<LabelType>::printMatrix()
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
            cout << adj[i][j] << " ";
        cout << endl;
    }
        
}

template<class LabelType>
int AdjacencyMatrix<LabelType>::getNumVertices() const
{
    return size;
}

template<class LabelType>
int AdjacencyMatrix<LabelType>::getNumEdges() const
{
    int edgeCount = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (adj[i][j] != 0)
                ++edgeCount;

    return edgeCount / 2;
}

template<class LabelType>
bool AdjacencyMatrix<LabelType>::add(LabelType start, LabelType end, int edgeWeight)
{
    adj[start][end] = edgeWeight;
    adj[end][start] = edgeWeight;
    return true;
}

template<class LabelType>
bool AdjacencyMatrix<LabelType>::remove(LabelType start, LabelType end)
{
    adj[start][end] = 0;
    adj[end][start] = 0;
    return true;
}

template<class LabelType>
int AdjacencyMatrix<LabelType>::getEdgeWeight(LabelType start, LabelType end) const
{
    return adj[start][end];
}

template<class LabelType>
void AdjacencyMatrix<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&))
{
    // Visit the current node
    visit(start);

    // Mark the current node as visited
    visited[start] = true;

    // For all other nodes
    for (int i = 0; i < size; ++i) {
        if (adj[start][i] != 0 && (!visited[i]))
            depthFirstTraversal(i,visit);
    }
}

template<class LabelType>
void AdjacencyMatrix<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&))
{
    // Vector that contains the adjacent nodes
    vector<LabelType> alist;
    alist.push_back(start);

    // Mark current node as visited
    visited[start] = true;

    int check;
    while (!alist.empty()) {
        check = alist[0];

        // Print node
        visit(check);
        alist.erase(alist.begin());

        // Every vertex adjacent
        for (int i = 0; i < size; ++i) {
            if (adj[check][i] != 0 && (!visited[i])) {
                // Add node to the queue
                alist.push_back(i);

                // Mark next node as visited
                visited[i] = true;
            }
        }
    }
    // Reset visited as all false
    for (int i = 0; i < size; ++i)
        visited[i] = false;
}