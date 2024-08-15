
/* Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.

For printing MST follow the steps -

1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note: Order of different edges doesn't matter.
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
Line 1: Two Integers V and E (separated by space)
Next E lines: Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format:
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
1 <= Wi <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Input Graph



Sample Output 1 :
0 1 3
1 2 1
0 3 5
Input Graph */

/*
 * Time complexity: O(E * log(V))
 * Space complexity: O(V^2)
 * 
 * where E is the number of edges in the graph and 
 * V is the number of vertices in the graph
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Class to represent an edge in the graph
class Edge
{
public:
    int vertex; // The vertex connected by this edge
    int weight; // The weight of the edge

    // Constructor to initialize the vertex and weight of the edge
    Edge(int vertex, int weight)
    {
        this->vertex = vertex;
        this->weight = weight;
    }

    // Operator overloading to compare edges based on their weight
    bool operator>(const Edge &other) const
    {
        return this->weight > other.weight;
    }
};

// Function to implement Prim's algorithm for finding the Minimum Spanning Tree (MST)
void prims(vector<vector<int>> &adjacencyMatrix, int V)
{
    vector<bool> visited(V, false); // Array to keep track of visited vertices
    vector<int> parent(V, -1);      // Array to store the parent of each vertex in the MST
    vector<int> weight(V, INT_MAX); // Array to store the minimum weight to reach each vertex

    // Start from vertex 0, setting its weight to 0
    weight[0] = 0;

    // Use a priority queue to always pick the vertex with the smallest edge weight
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push(Edge(0, 0)); // Start with vertex 0 with weight 0

    // Continue until the priority queue is empty
    while (!pq.empty())
    {
        Edge currentEdge = pq.top(); // Get the edge with the minimum weight
        pq.pop();
        int currentVertex = currentEdge.vertex; // Get the vertex associated with this edge

        // If the vertex is already visited, skip it
        if (visited[currentVertex])
            continue;

        // Mark the current vertex as visited
        visited[currentVertex] = true;

        // Explore all neighbors of the current vertex
        for (int i = 0; i < V; i++)
        {
            // Check if there is an edge and the neighbor is not visited
            if (adjacencyMatrix[currentVertex][i] != 0 && !visited[i])
            {
                // If the edge weight is less than the current weight of the neighbor
                if (adjacencyMatrix[currentVertex][i] < weight[i])
                {
                    weight[i] = adjacencyMatrix[currentVertex][i]; // Update the weight
                    parent[i] = currentVertex;                     // Update the parent
                    pq.push(Edge(i, weight[i]));                   // Add the neighbor to the priority queue
                }
            }
        }
    }

    // Print the edges of the MST
    for (int i = 1; i < V; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E; // Read the number of vertices and edges

    vector<vector<int>> adjacencyMatrix(V, vector<int>(V, 0)); // Create an adjacency matrix to represent the graph

    // Read the edges and populate the adjacency matrix
    for (int i = 0; i < E; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;        // Read the first vertex, second vertex, and the weight of the edge
        adjacencyMatrix[v1][v2] = w; // Set the weight in the adjacency matrix
        adjacencyMatrix[v2][v1] = w; // Since the graph is undirected, set the symmetric value
    }

    // Call Prim's algorithm to find and print the MST
    prims(adjacencyMatrix, V);

    return 0;
}
