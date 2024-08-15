

#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

void dijkstra(vector<vector<int>> &adjacencyMatrix)
{
    int v = adjacencyMatrix.size();   // Number of vertices in the graph
    vector<bool> visited(v, false);   // Vector to track which vertices have been visited
    vector<int> distance(v, INT_MAX); // Vector to store the minimum distance from the source vertex to each vertex

    // Initialize the distance to the source vertex (vertex 0) as 0
    distance[0] = 0;

    // Loop to find the shortest path for all vertices
    for (int i = 0; i < v - 1; i++)
    {
        // Find the vertex with the minimum distance that hasn't been visited yet
        int minVertex = -1;
        for (int j = 0; j < v; j++)
        {
            if (!visited[j] && (minVertex == -1 || distance[j] < distance[minVertex]))
            {
                minVertex = j;
            }
        }

        visited[minVertex] = true; // Mark this vertex as visited

        // Explore all the neighbors of the current vertex
        for (int j = 0; j < v; j++)
        {
            if (adjacencyMatrix[minVertex][j] != 0 && !visited[j] && distance[minVertex] != INT_MAX)
            {
                int newDist = distance[minVertex] + adjacencyMatrix[minVertex][j];
                if (newDist < distance[j])
                {
                    distance[j] = newDist; // Update the distance to vertex j
                }
            }
        }
    }

    // Print the shortest distances from the source vertex to all other vertices
    for (int i = 0; i < v; i++)
    {
        cout << i << " " << distance[i] << endl;
    }
}

int main()
{
    int v, e;
    cin >> v >> e; // Read the number of vertices and edges

    vector<vector<int>> adjacencyMatrix(v, vector<int>(v, 0)); // Create an adjacency matrix to represent the graph

    // Read the edges and populate the adjacency matrix
    for (int i = 0; i < e; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;        // Read the vertices and the weight of the edge
        adjacencyMatrix[v1][v2] = weight; // Set the weight in the adjacency matrix
        adjacencyMatrix[v2][v1] = weight; // Since the graph is undirected, set the symmetric value
    }

    // Call Dijkstra's algorithm to find the shortest paths from the source vertex (vertex 0)
    dijkstra(adjacencyMatrix);

    return 0;
}
