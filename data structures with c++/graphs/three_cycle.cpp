
/*Problem statement
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 
Output Format :
Print the count the number of 3-cycles in the given graph
Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec
Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1 */
/*
 * Time complexity: O(n^3)
 * Space complexity: O(N^2)
 * 
 * where N is the number of vertices in the input graph and 
 * E is the number of edges in the input graph
 */

#include <iostream>
#include <vector>

using namespace std;

// Function to count the number of 3-cycles (triangles) in the graph
int solve(vector<vector<bool>> &graph, int n)
{
    int cycleCount = 0; // Initialize a counter for the number of cycles

    // Loop through all possible triplets of vertices (i, j, k)
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                // Check if the triplet forms a cycle (i.e., i -> j, j -> k, k -> i)
                if (graph[i][j] && graph[j][k] && graph[k][i])
                {
                    ++cycleCount; // Increment the cycle count if a cycle is found
                }
            }
        }
    }
    return cycleCount; // Return the total number of 3-cycles found
}

// Function to take input for the graph
vector<vector<bool>> takeInput(int &n)
{
    int m;
    cin >> n >> m; // Read the number of vertices (n) and the number of edges (m)

    // Initialize the adjacency matrix
    vector<vector<bool>> graph(n, vector<bool>(n, false));

    // Loop through all the edges to fill the adjacency matrix
    for (int i = 0; i < m; i++)
    {
        int firstvertex, secondvertex;
        cin >> firstvertex >> secondvertex;      // Read the vertices connected by an edge
        graph[firstvertex][secondvertex] = true; // Mark the edge in the adjacency matrix
        graph[secondvertex][firstvertex] = true; // Since the graph is undirected, mark the reverse edge as well
    }
    return graph; // Return the adjacency matrix
}

// Main method
int main()
{
    int n;
    vector<vector<bool>> graph = takeInput(n); // Take input for the graph

    int ans = solve(graph, n); // Solve the problem to find the number of 3-cycles
    cout << ans << endl;       // Print the result

    return 0;
}
