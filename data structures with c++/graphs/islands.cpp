
/* Problem statement
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 0 to V-1) and E connections or edges between islands. Can you count the number of connected groups of islands.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 
Output Format :
Print the count the number of connected groups of islands
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1  */

/*
 * Time complexity: O(N^2)
 * Space complexity: O(N^2)
 * where N is the number of vertex in the graph
 */

#include <iostream>
#include <vector>

using namespace std;

// Declare the dfs function before using it in numConnected
void dfs(vector<vector<int>> &edges, int v1, vector<bool> &visited, int n);

// Function to calculate the number of connected components (islands) in the graph
int numConnected(vector<vector<int>> &edges, int n)
{
    vector<bool> visited(n, false); // Array to keep track of visited vertices
    int count = 0;                  // Variable to store the number of connected components (islands)

    // Loop through all vertices
    for (int i = 0; i < n; i++)
    {
        // If the current vertex has not been visited, start a DFS from that vertex
        if (!visited[i])
        {
            dfs(edges, i, visited, n); // Perform DFS to visit all vertices in this component
            count++;                   // Increment the count of connected components (islands)
        }
    }
    return count; // Return the total number of connected components (islands)
}

// Helper function to perform DFS and visit all connected vertices
void dfs(vector<vector<int>> &edges, int v1, vector<bool> &visited, int n)
{
    visited[v1] = true; // Mark the current vertex as visited

    // Loop through all vertices to find adjacent vertices
    for (int i = 0; i < n; i++)
    {
        // If the vertex is not visited and there is an edge between the current vertex and i
        if (!visited[i] && edges[v1][i] == 1)
        {
            dfs(edges, i, visited, n); // Recursively visit the adjacent vertex
        }
    }
}

// Function to take input and build the adjacency matrix representation of the graph
vector<vector<int>> takeInput()
{
    int n, e;
    cin >> n >> e; // Read the number of vertices and edges

    vector<vector<int>> edges(n, vector<int>(n, 0)); // Adjacency matrix to represent the graph

    // Loop to take all edges as input
    for (int i = 0; i < e; i++)
    {
        int firstvertex, secondvertex;
        cin >> firstvertex >> secondvertex;   // Read the two vertices of an edge
        edges[firstvertex][secondvertex] = 1; // Mark the edge as present in the adjacency matrix
        edges[secondvertex][firstvertex] = 1; // Since the graph is undirected, mark the reverse edge as well
    }
    return edges; // Return the constructed adjacency matrix
}

int main()
{
    vector<vector<int>> edges = takeInput(); // Read input and create the adjacency matrix

    int ans = numConnected(edges, edges.size()); // Calculate the number of connected components (islands)
    cout << ans << endl;                         // Print the result

    return 0;
}
