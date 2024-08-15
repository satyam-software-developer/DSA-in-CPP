
/*Problem statement
You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).

Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.

Detailed explanation ( Input/output format, Notes, Images )
Input Format
The first line of input contains an integer 'N' representing
the dimension of the maze.
The next N lines of input contain N space-separated
integers representing the type of the cell.
Output Format :
For each test case, print the path from start position to destination position and only cells that are part of the solution path should be 1, rest all cells should be 0.

Output for every test case will be printed in a separate line.
Constraints:
0 < N < 11 0 <= Maze[i][j] <=1

Time Limit: 1sec
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1
Sample Output 1 Explanation :
Only 1 path is possible

1 0 0
1 0 0
1 1 1
Which is printed from left to right and then top to bottom in one line.

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1
1 0 0 1 0 0 1 1 1
1 0 0 1 1 0 0 1 1
1 0 0 1 1 1 0 0 1
Sample Output 2 Explanation :
4 paths are possible which are printed in the required format.*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Method to print the solution matrix
void printSolution(vector<vector<int>> &solution, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solution[i][j] << " ";
        }
    }
    cout << endl;
}

// Recursive method to solve the maze and find all paths
void solveMaze(vector<vector<int>> &maze, vector<vector<int>> &solution, int x, int y, int n)
{
    // Base case: if the rat reaches the destination (bottom-right corner)
    if (x == n - 1 && y == n - 1)
    {
        solution[x][y] = 1;         // Mark the destination cell in the solution path
        printSolution(solution, n); // Print the current solution path
        cout << endl;
        return;
    }

    // Check if the current cell is out of bounds or blocked or already visited
    if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1)
    {
        return;
    }

    // Mark the current cell as part of the solution path
    solution[x][y] = 1;

    // Move in all four possible directions: up, down, left, right
    solveMaze(maze, solution, x - 1, y, n); // Move up
    solveMaze(maze, solution, x + 1, y, n); // Move down
    solveMaze(maze, solution, x, y - 1, n); // Move left
    solveMaze(maze, solution, x, y + 1, n); // Move right

    // Backtrack: unmark the current cell as part of the solution path
    solution[x][y] = 0;
}

// Method to initialize the solution matrix and start the maze solving process
void ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> solution(n, vector<int>(n, 0)); // Initialize the solution matrix
    solveMaze(maze, solution, 0, 0, n);                 // Start solving the maze from the top-left corner
}

// Main method to read input and start the program
int main()
{
    int n;
    cin >> n;                                    // Read the size of the maze
    vector<vector<int>> maze(n, vector<int>(n)); // Initialize the maze matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j]; // Read each cell value of the maze
        }
    }
    ratInAMaze(maze, n); // Start finding all paths in the maze
    return 0;
}
