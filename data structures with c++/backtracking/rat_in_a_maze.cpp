/* Problem statement
You are given a N*N maze with a rat placed at maze[0][0]. Find whether any path exist that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).

Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
0 < N < 11 0 <= Maze[i][j] <=1

Time Limit: 1sec
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
true
Sample Input 2 :
3
1 0 1
1 0 1
0 1 1
Sample Output 2 :
 false */

#include <iostream>
#include <vector>

using namespace std;

// Method to check if a path exists for the rat to reach the destination
bool solveMaze(vector<vector<int>> &maze, int i, int j, vector<vector<int>> &path)
{
    int n = maze.size();

    // Check if (i, j) cell is valid or not
    if (i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0 || path[i][j] == 1)
    {
        return false;
    }

    // Include the cell in the current path
    path[i][j] = 1;

    // Destination cell
    if (i == n - 1 && j == n - 1)
    {
        return true;
    }

    // Explore further in all directions

    // Move down
    if (solveMaze(maze, i + 1, j, path))
    {
        return true;
    }

    // Move right
    if (solveMaze(maze, i, j + 1, path))
    {
        return true;
    }

    // Move up
    if (solveMaze(maze, i - 1, j, path))
    {
        return true;
    }

    // Move left
    if (solveMaze(maze, i, j - 1, path))
    {
        return true;
    }

    // If none of the above moves work, backtrack
    path[i][j] = 0;
    return false;
}

// Method to check if a path exists for the rat to reach the destination
bool ratInAMaze(vector<vector<int>> &maze)
{
    int n = maze.size();
    vector<vector<int>> path(n, vector<int>(n, 0));
    return solveMaze(maze, 0, 0, path);
}

// Main method to take input and start the maze-solving process
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));

    // Read the maze input
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> maze[i][j];
        }
    }

    // Check if there is a path and print the result
    if (ratInAMaze(maze))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
