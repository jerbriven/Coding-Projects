/** An interface for the ADT undirected, connected graph.
  @file AdjacencyMatrix.h */

#ifndef _ADJACENCY_MATRIX
#define _ADJACENCY_MATRIX

#include "GraphInterface.h"

template<class LabelType>
class AdjacencyMatrix : public GraphInterface<LabelType>
{
private:
    // Define maximum number of nodes
    static const int size = 10;
    int adj[size][size] = {0};
    bool visited[size] = {0};

public:
    AdjacencyMatrix();

   /** Gets the number of vertices in this graph.
    @pre   None.
    @return  The number of vertices in the graph. */
   int getNumVertices() const;
   
   /** Gets the number of edges in this graph.
    @pre   None.
    @return  The number of edges in the graph. */
   int getNumEdges() const;
   
   /** Creates an undirected edge in this graph between two vertices
       that have the given labels. If such vertices do not exist, creates
       them and adds them to the graph before creating the edge.
    @param start  A label for the first vertex. 
    @param end  A label for the second vertex.
    @param edgeWeight  The integer weight of the edge.
    @return  True if the edge is created, or false otherwise. */
   bool add(LabelType start, LabelType end, int edgeWeight);
   
   /** Removes an edge from this graph. If a vertex has no other edges, 
       it is removed from the graph since this is a connected graph. 
    @pre  None.
    @param start  A label for the first vertex.
    @param end  A label for the second vertex.
    @return  True if the edge is removed, or false otherwise. */
   bool remove(LabelType start, LabelType end);
   
   /** Gets the weight of an edge in this graph.
    @return  The weight of the specified edge. 
       If no such edge exists, returns a negative integer. */
   int getEdgeWeight(LabelType start, LabelType end) const;
   
   /** Performs a depth-first search of this graph beginning at the given
       vertex and calls a given function once for each vertex visited.
    @param start  A label for the first vertex.
    @param visit  A client-defined function that performs an operation on
       or with each visited vertex. */
   void depthFirstTraversal(LabelType start, void visit(LabelType&));

   /** Performs a breadth-first search of this graph beginning at the given
       vertex and calls a given function once for each vertex visited.
    @param start  A label for the first vertex.
    @param visit  A client-defined function that performs an operation on
       or with each visited vertex. */
   void breadthFirstTraversal(LabelType start, void visit(LabelType&));
}; // end Adjacency Matrix
#include "AdjacencyMatrix.cpp"
#endif