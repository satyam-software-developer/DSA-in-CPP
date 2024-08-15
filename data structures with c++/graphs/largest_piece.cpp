
/*Problem statement
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains an integer, that denotes the value of N. 
Each of the following N lines contain N space separated integers.
Output Format :
Print the count of '1's in the biggest piece of '1's, according to the description in the task.
Constraints :
1 <= N <= 1000
Time Limit: 1 sec
Sample Input 1:
2
1 1
0 1
Sample Output 1:
3 */
/*
 * Time complexity: O(N*N)
 * Space complexity: O(N*N)
 * 
 * where N is the size of cake 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Direction vectors for moving up, down, right, and left in the grid
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Helper DFS function to explore the grid recursively
int dfs(vector<vector<int>> &cake, vector<vector<bool>> &visited, int x, int y, int n)
{
    visited[x][y] = true; // Mark the current cell as visited
    int count = 1;        // Initialize the count for the current piece

    // Explore all four possible directions
    for (int i = 0; i < 4; i++)
    {
        int nex = x + dir[i][0]; // Calculate the next cell's row index
        int ney = y + dir[i][1]; // Calculate the next cell's column index

        // Check if the next cell is valid, contains '1', and is unvisited
        if (nex >= 0 && nex < n && ney >= 0 && ney < n && cake[nex][ney] == 1 && !visited[nex][ney])
        {
            // Recursively explore the next cell and accumulate the count
            count += dfs(cake, visited, nex, ney, n);
        }
    }
    return count; // Return the total count for the current piece
}

// Main DFS function to find the largest connected piece of '1's in the grid
int findLargestPiece(vector<vector<int>> &cake, int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false)); // Array to keep track of visited cells
    int ans = 0;                                             // Variable to store the size of the largest piece

    // Loop through all cells in the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // If the cell is unvisited and contains '1', initiate DFS
            if (!visited[i][j] && cake[i][j] == 1)
            {
                // Update the answer with the maximum size found so far
                ans = max(ans, dfs(cake, visited, i, j, n));
            }
        }
    }
    return ans; // Return the size of the largest piece found
}

// Function to take input from the user
vector<vector<int>> takeInput(int &n)
{
    cin >> n; // Read the size of the grid
    vector<vector<int>> cake(n, vector<int>(n));

    // Read each row of the grid
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cake[i][j];
        }
    }
    return cake; // Return the grid
}

// Main method
int main()
{
    int n;
    vector<vector<int>> cake = takeInput(n); // Take input for the grid
    int ans = findLargestPiece(cake, n);     // Find the largest piece of '1's in the grid
    cout << ans << endl;                     // Output the size of the largest piece
    return 0;
}
