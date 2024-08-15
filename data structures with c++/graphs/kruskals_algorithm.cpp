
/* Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.

Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

For printing MST follow the steps -

1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Input Graph

Sample Output 1 :
1 2 1
0 1 3
0 3 5
Input Graph */

/*
 * Time complexity: O(E * log(E))
 * Space complexity: O(V + E)
 * 
 * where E is the number of edges in the graph and
 * V is the number of vertices in the graph
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a class to represent an edge in the graph
class Edge
{
public:
    int source; // The source vertex of the edge
    int dest;   // The destination vertex of the edge
    int weight; // The weight of the edge

    // Method to print the edge in the required format
    void printEdge()
    {
        cout << min(source, dest) << " " << max(source, dest) << " " << weight << endl;
    }

    // Operator to compare edges based on their weight
    bool operator<(const Edge &e) const
    {
        return weight < e.weight;
    }
};

// Function to find the parent of a vertex in the disjoint set
int findParent(int v, vector<int> &parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    // Recursively find the top-most parent (root) of the vertex
    return findParent(parent[v], parent);
}

// Function to implement Kruskal's algorithm
void kruskal(vector<Edge> &edges, int v, int e)
{
    // Sort all the edges in ascending order of their weight
    sort(edges.begin(), edges.end());

    // Vector to store the edges of the Minimum Spanning Tree (MST)
    vector<Edge> output(v - 1);

    // Vector to keep track of the parent of each vertex (for the disjoint set)
    vector<int> parent(v);
    for (int i = 0; i < v; i++)
    {
        parent[i] = i; // Initially, each vertex is its own parent
    }

    int count = 0; // Number of edges included in the MST
    int i = 0;     // Index to iterate through sorted edges

    // Keep adding edges to the MST until we have v-1 edges
    while (count != v - 1)
    {
        Edge currentEdge = edges[i];

        // Find the parent of the source and destination vertices
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        // If they have different parents, adding this edge won't form a cycle
        if (sourceParent != destParent)
        {
            output[count] = currentEdge; // Add the edge to the MST
            count++;
            parent[sourceParent] = destParent; // Union the sets
        }
        i++;
    }

    // Print all the edges in the MST
    for (int j = 0; j < v - 1; j++)
    {
        output[j].printEdge();
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    // Vector to store all edges
    vector<Edge> edges(e);

    // Read all edges from the user
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].source >> edges[i].dest >> edges[i].weight;
    }

    // Call the Kruskal's algorithm function
    kruskal(edges, v, e);

    return 0;
}
