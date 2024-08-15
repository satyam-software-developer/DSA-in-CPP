
/*
Problem statement
For a given two-dimensional integer array/list of size (N x M),
print it in a spiral form. That is, you need to print in the order followed for every iteration:

a. First row(left to right)
b. Last column(top to bottom)
c. Last row(right to left)
d. First column(bottom to top)
 Mind that every element will be printed only once.

Refer to the Image:
Spiral path of a matrix

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
Then the test cases follow.

First line of each test case or query contains two integer values, 'N' and 'M', separated by a single space.
They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

Second line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith row constitutes 'M' column values separated by a single space.
Output format :
For each test case, print the elements of the two-dimensional array/list in the spiral form in a single line, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= M <= 10^3
Time Limit: 1sec
Sample Input 1:
1
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output 1:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Sample Input 2:
2
3 3
1 2 3
4 5 6
7 8 9
3 1
10
20
30
Sample Output 2:
1 2 3 6 9 8 7 4 5
10 20 30

*/
#include <iostream>  // Including the input/output stream library for standard I/O operations
using namespace std; // Using the standard namespace for easier access to standard library functions

// Function to print the elements of a 2D array in a spiral order
void spiralPrint(int **input, int nRows, int mCols)
{
    if (nRows == 0 || mCols == 0)
    {           // Checking if either the number of rows or columns is zero
        return; // If so, return from the function since there's nothing to print
    }
    int i, rowStart = 0, colStart = 0;          // Declaring variables for iteration and tracking the start indices
    int numElements = nRows * mCols, count = 0; // Calculating the total number of elements in the matrix and initializing a count variable

    while (count < numElements)
    { // Continue iterating until all elements are printed
        // Print the elements of the first row from the remaining rows
        for (i = colStart; i < mCols; ++i)
        {
            cout << input[rowStart][i] << " "; // Print the element at the current row and column index
            count++;                           // Increment the count of printed elements
        }
        rowStart++; // Move to the next row

        // Print the elements of the last column from the remaining columns
        for (i = rowStart; i < nRows; ++i)
        {
            cout << input[i][mCols - 1] << " "; // Print the element at the current row and last column
            count++;                            // Increment the count of printed elements
        }
        mCols--; // Decrement the number of columns

        // Print the elements of the last row from the remaining rows
        if (rowStart < nRows)
        { // Ensure there are remaining rows to print
            for (i = mCols - 1; i >= colStart; --i)
            {
                cout << input[nRows - 1][i] << " "; // Print the element at the last row and current column
                count++;                            // Increment the count of printed elements
            }
            nRows--; // Decrement the number of rows
        }

        // Print the elements of the first column from the remaining columns
        if (colStart < mCols)
        { // Ensure there are remaining columns to print
            for (i = nRows - 1; i >= rowStart; --i)
            {
                cout << input[i][colStart] << " "; // Print the element at the current row and first column
                count++;                           // Increment the count of printed elements
            }
            colStart++; // Move to the next column
        }
    }
}

int main()
{
    int t;    // Variable to store the number of test cases
    cin >> t; // Reading the number of test cases from standard input
    while (t--)
    {                                  // Looping through each test case
        int row, col;                  // Variables to store the number of rows and columns in the 2D array
        cin >> row >> col;             // Reading the number of rows and columns for the current test case
        int **matrix = new int *[row]; // Dynamically allocating memory for 'row' number of pointers to integer arrays

        for (int i = 0; i < row; i++)
        {                             // Looping through each row
            matrix[i] = new int[col]; // Dynamically allocating memory for 'col' number of integers in each row
            for (int j = 0; j < col; j++)
            {                        // Looping through each column
                cin >> matrix[i][j]; // Reading the elements of the 2D array from standard input
            }
        }
        spiralPrint(matrix, row, col); // Calling the spiralPrint function to print the array elements in a spiral order

        for (int i = 0; i < row; ++i)
        { // Freeing memory allocated for each row
            delete[] matrix[i];
        }
        delete[] matrix; // Freeing memory allocated for the array of pointers

        cout << endl; // Printing a newline after printing the elements of each test case
    }

    return 0; // Indicating successful completion of the program
}
