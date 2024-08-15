
/* Problem statement
Given an undirected graph G(V,E), check if the graph G is connected graph or not.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2.  */

/*
 * Time complexity: O(V + E)
 * Space complexity: (V^2)
 * 
 * where V is the number of vertices in the input graph and 
 * E is the number of edges in the input graph
 */

#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS and mark visited vertices
void DFS(vector<vector<int>> &edges, int sv, vector<bool> &visited)
{
    visited[sv] = true; // Mark the current vertex as visited
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            DFS(edges, i, visited); // Recursively visit all adjacent vertices
        }
    }
}

// Function to check if the graph is connected
bool isConnected(vector<vector<int>> &edges)
{
    vector<bool> visited(edges.size(), false); // Vector to keep track of visited vertices

    DFS(edges, 0, visited); // Start DFS from vertex 0

    // Check if all vertices were visited
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            return false; // If any vertex was not visited, the graph is not connected
        }
    }
    return true; // All vertices were visited, so the graph is connected
}

int main()
{
    int n, e;
    cin >> n >> e; // Read the number of vertices and edges

    if (n == 0)
    {
        cout << "true" << endl; // If there are no vertices, the graph is trivially connected
        return 0;
    }

    vector<vector<int>> edges(n, vector<int>(n, 0)); // Adjacency matrix to represent the graph

    // Loop to take all edges as input
    for (int i = 0; i < e; i++)
    {
        int fv, sv;
        cin >> fv >> sv;   // Read the endpoints of an edge
        edges[fv][sv] = 1; // Mark the edge as present in the adjacency matrix
        edges[sv][fv] = 1; // Since the graph is undirected, mark the reverse edge as well
    }

    // Check if the graph is connected and output the result
    if (isConnected(edges))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
