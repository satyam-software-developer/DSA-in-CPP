
/* Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

Find the path using BFS and print the shortest path available.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
 */

/*
 * In a typical BFS search, the time complexity is O(V+E)
 * where V is the number of vertices and 
 * E is the number of edges.
 * 
 * There are n nodes and m edges in this problem.
 * We build adjacent list of all m edges in  graph which takes O(m)
 * Each node is added to the queue and popped from queue once, it takes O(n) to handle all nodes.
 * The time complexity is O(n+m).
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Helper function to perform BFS and find a path from 'sv' (start vertex) to 'ev' (end vertex)
vector<int> getPathBFSHelper(vector<vector<int>> &edges, int sv, int ev, vector<bool> &visited)
{
    int n = edges.size(); // Get the number of vertices in the graph

    unordered_map<int, int> parentMap; // Map to store the parent of each vertex
    queue<int> q;                      // Queue for BFS traversal

    // Check for invalid input of sv or ev
    if (sv > n - 1 || ev > n - 1)
    {
        return {}; // Return an empty vector if either source or end vertex is out of bounds
    }

    // If there's a direct edge and sv is the same as ev
    if (edges[sv][ev] == 1 && sv == ev)
    {
        return {sv}; // Return the path with only one vertex
    }

    q.push(sv);         // Enqueue the starting vertex
    visited[sv] = true; // Mark the starting vertex as visited

    // Loop until there are no more vertices to visit
    while (!q.empty())
    {
        int front = q.front(); // Dequeue a vertex from the front of the queue
        q.pop();

        // Explore all adjacent vertices of the current vertex
        for (int i = 0; i < n; i++)
        {
            if (edges[front][i] == 1 && !visited[i])
            {                         // Check for an unvisited adjacent vertex
                parentMap[i] = front; // Store the parent of the adjacent vertex
                q.push(i);            // Enqueue the adjacent vertex

                visited[i] = true; // Mark the vertex as visited

                // If the adjacent vertex is the end vertex, construct the path
                if (i == ev)
                {
                    vector<int> path;
                    path.push_back(ev);        // Add the end vertex to the path
                    int value = parentMap[ev]; // Get the parent of the end vertex

                    // Backtrack through the parent map to construct the path
                    while (value != sv)
                    {
                        path.push_back(value);    // Add each vertex in the path
                        value = parentMap[value]; // Move to the parent of the current vertex
                    }
                    path.push_back(value); // Add the start vertex to the path

                    return path; // Return the constructed path
                }
            }
        }
    }
    return {}; // If the loop ends, there is no path between sv and ev
}

// Function to initiate BFS and find a path from 'sv' (start vertex) to 'ev' (end vertex)
vector<int> getPathBFS(vector<vector<int>> &edges, int sv, int ev)
{
    vector<bool> visited(edges.size(), false);       // Vector to keep track of visited vertices
    return getPathBFSHelper(edges, sv, ev, visited); // Call the helper function to find the path
}

int main()
{
    int n, e;
    cin >> n >> e; // Read the number of vertices and edges

    vector<vector<int>> edges(n, vector<int>(n, 0)); // Adjacency matrix to represent the graph

    // Loop to take all edges as input
    for (int i = 0; i < e; i++)
    {
        int fv, sv;
        cin >> fv >> sv;   // Read the endpoints of an edge
        edges[fv][sv] = 1; // Mark the edge as present in the adjacency matrix
        edges[sv][fv] = 1; // Since the graph is undirected, mark the reverse edge as well
    }

    int sv, ev;
    cin >> sv >> ev; // Read the source and end vertices to check for a path

    // Get the path from sv to ev using BFS
    vector<int> ans = getPathBFS(edges, sv, ev);
    if (!ans.empty())
    { // If a path exists
        for (int i = ans.size() - 1; i >= 0; i--)
        { // Print all elements in the path in reverse order
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
