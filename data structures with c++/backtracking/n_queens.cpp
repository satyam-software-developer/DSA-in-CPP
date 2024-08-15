
/* Problem statement
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :

1<=N<=10 For Example:
For a chessboard of size 4*4
The configurations are 
alt text

Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0  */

#include <iostream>
#include <vector>

using namespace std;

// Method to print the board configuration
void printBoard(vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << board[i][j] << " ";
        }
    }
    cout << endl;
}

// Recursive method to place queens on the board
void placeQueens(vector<vector<int>> &board, int row, int n)
{
    // Base case: if all queens are placed, print the board configuration
    if (row == n)
    {
        printBoard(board, n);
        return;
    }

    // Try placing a queen in each column of the current row
    for (int j = 0; j < n; ++j)
    {
        // Check if it's safe to place the queen at board[row][j]
        bool isSafe = true;
        for (int i = 0; i < row; ++i)
        {
            if (board[i][j] == 1 || (j - (row - i) >= 0 && board[i][j - (row - i)] == 1) || (j + (row - i) < n && board[i][j + (row - i)] == 1))
            {
                isSafe = false;
                break;
            }
        }
        if (isSafe)
        {
            board[row][j] = 1;              // Place the queen
            placeQueens(board, row + 1, n); // Recur to place the queen in the next row
            board[row][j] = 0;              // Backtrack: remove the queen and try next column
        }
    }
}

// Method to initiate the process of placing N Queens on an NxN board
void placeNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize an NxN board with all cells set to 0
    placeQueens(board, 0, n);                        // Start placing queens from the first row
}

// Main method to read input and start the N-Queens solution
int main()
{
    int n;
    cin >> n;        // Read the size of the board (N)
    placeNQueens(n); // Start placing N Queens on the board
    return 0;
}
