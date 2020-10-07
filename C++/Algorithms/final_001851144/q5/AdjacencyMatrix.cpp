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
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j)
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
    return true;
}

template<class LabelType>
bool AdjacencyMatrix<LabelType>::remove(LabelType start, LabelType end)
{
    adj[start][end] = 0;
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

template<class LabelType>
int AdjacencyMatrix<LabelType>::minDistance(int dist[], bool final[])
{
    // Set min value
    int min = INT_MAX, min_index;

    for (int x = 0; x < size; x++)
        if (final[x] == false && dist[x] <= min)
            min = dist[x], min_index = x;

    return min_index;
}

template<class LabelType>
int AdjacencyMatrix<LabelType>::shortestPath(LabelType start, LabelType end)
{
    // Contains shortest distances
    int dist[size];
    // Set to 1 when shortest distance is finalized
    bool final[size];

    // Set all distances as infinite and final values as false
    for (int i = 0; i < size; i++) {
        dist[i] = INT_MAX, final[i] = false;
    }

    // Distance to itself is always 0
    dist[start] = 0;

    // Shortest path for each vertex
    for (int count = 0; count < size - 1; count++) {
        int u = minDistance(dist, final);
        final[u] = true;

        // Change distance value
        for (int x = 0; x < size; x++)
            if (!final[x] && adj[u][x] && dist[u] != INT_MAX 
                && dist[u] + adj[u][x] < dist[x])
                dist[x] = dist[u] + adj[u][x];

    }

    return dist[6];
}