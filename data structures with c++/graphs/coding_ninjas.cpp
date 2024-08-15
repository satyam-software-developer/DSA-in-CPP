
/* Problem statement
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .

There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix.
Each of the following N lines contain M characters. Please note that characters are not space separated.
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
Sample Input 2:
5 5
DANDO
NNINJ
AXGJC
INJAA
CODDI
Sample Output 2:
0 */

/*
 * Time complexity: O(N * M)
 * Space complexity: O(N * M)
 * where N and M are the rows and columns respectively of the board
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CodingNinjas
{
public:
    // Direction vectors for 8 possible movements
    vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    string pattern = "CODINGNINJA"; // The pattern we need to search
    vector<vector<int>> used;       // To keep track of visited cells

    // Function to check if a cell is within the bounds of the matrix
    bool validPoint(int x, int y, int N, int M)
    {
        return (x >= 0 && x < N && y >= 0 && y < M);
    }

    // DFS function to search for the pattern starting from (x, y)
    bool DFS(vector<string> &G, int x, int y, int index, int N, int M)
    {
        if (index == 11)
        { // If we have matched the entire pattern
            return true;
        }
        used[x][y] = 1; // Mark this cell as visited
        bool found = false;

        // Explore all 8 directions
        for (auto direction : directions)
        {
            int newx = x + direction[0];
            int newy = y + direction[1];

            // Check if the new cell is valid, matches the current character of the pattern, and is not visited
            if (validPoint(newx, newy, N, M) && G[newx][newy] == pattern[index] && used[newx][newy] == 0)
            {
                found = found || DFS(G, newx, newy, index + 1, N, M); // Recursively search the next character
            }
        }

        used[x][y] = 0; // Backtrack by unmarking this cell
        return found;   // Return if the pattern is found or not
    }

    // Function to initiate the search for the pattern in the entire matrix
    bool solve(vector<string> &Graph, int N, int M)
    {
        used.assign(N, vector<int>(M, 0)); // Initialize the used matrix with 0

        // Search for the pattern starting with the character 'C'
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (Graph[i][j] == 'C')
                {
                    if (DFS(Graph, i, j, 1, N, M))
                    {
                        return true; // If the pattern is found, return true
                    }
                }
            }
        }
        return false; // If the pattern is not found, return false
    }
};

vector<string> takeInput()
{
    int N, M;
    cin >> N >> M; // Read the number of rows and columns

    vector<string> Graph(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Graph[i]; // Read each row of the matrix
    }

    return Graph;
}

int main()
{
    vector<string> Graph = takeInput();                                     // Take input
    CodingNinjas codingNinjas;                                              // Create an instance of the CodingNinjas class
    bool result = codingNinjas.solve(Graph, Graph.size(), Graph[0].size()); // Call the solve function
    cout << result << endl;                                                 // Print the result (1 for true, 0 for false)
    return 0;
}
