
/* Problem statement
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).

From a cell (i, j), you can move in three directions:

1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.

Detailed explanation ( Input/output format, Notes, Images )
 Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format :
Print the minimum cost to reach the destination.
Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76
Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18 */

/*
 * Time Complexity : O(3^P) where P = (M*N)
 * Space Complexity: O(max(M,N))
 * 
 * Where M and N are the rows and columns of the matrix.
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MinCostPath
{
public:
    // Helper method to recursively find the minimum cost path
    static int minCostPathHelper(const vector<vector<int>> &input, int mRows, int nCols, int currRow, int currCol)
    {
        // If the current position is out of bounds, return a large value (infinity)
        if (currRow >= mRows || currCol >= nCols)
        {
            return INT_MAX;
        }
        // If the current position is the bottom-right corner, return the value at that position
        if (currRow == (mRows - 1) && currCol == (nCols - 1))
        {
            return input[currRow][currCol];
        }
        // Calculate the cost of moving downwards
        int downCost = minCostPathHelper(input, mRows, nCols, (currRow + 1), currCol);
        // Calculate the cost of moving diagonally
        int diagonalCost = minCostPathHelper(input, mRows, nCols, (currRow + 1), (currCol + 1));
        // Calculate the cost of moving right
        int leftCost = minCostPathHelper(input, mRows, nCols, currRow, (currCol + 1));

        // Return the value at the current position plus the minimum cost of the three possible moves
        return input[currRow][currCol] + min(diagonalCost, min(downCost, leftCost));
    }

    // Main method to find the minimum cost path
    static int minCostPath(const vector<vector<int>> &input)
    {
        int mRows = input.size(); // Number of rows in the input matrix
        if (mRows == 0)
        {
            return INT_MAX; // If the matrix is empty, return a large value (infinity)
        }
        int nCols = input[0].size(); // Number of columns in the input matrix

        // Start the helper method from the top-left corner (0, 0)
        return minCostPathHelper(input, mRows, nCols, 0, 0);
    }

    // Method to take 2D matrix input from the user
    static vector<vector<int>> take2DInput()
    {
        int mRows, nCols;
        cin >> mRows >> nCols;

        // If there are no rows, return an empty matrix
        if (mRows == 0)
        {
            return vector<vector<int>>(0, vector<int>(0));
        }

        // Initialize the matrix
        vector<vector<int>> mat(mRows, vector<int>(nCols));

        // Read each row
        for (int row = 0; row < mRows; ++row)
        {
            for (int col = 0; col < nCols; ++col)
            {
                cin >> mat[row][col];
            }
        }

        // Return the filled matrix
        return mat;
    }
};

int main()
{
    // Take the 2D matrix input from the user
    vector<vector<int>> mat = MinCostPath::take2DInput();
    // Print the minimum cost path
    cout << MinCostPath::minCostPath(mat) << endl;
    return 0;
}
