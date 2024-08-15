
/*
Problem statement
For a given two-dimensional square matrix of size (N x N).
Find the total sum of elements on both the diagonals and at all the four boundaries.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
Then the test cases follow.

First line of each test case or query contains a single integer value, 'N' representing the 'rows' and 'columns' for the two-dimensional square matrix.

Second line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format:
For each test case, print the single integer denoting the sum.

Output for every test case will be printed in a seperate line.
Constraints:
1 <= t <= 10^2
0 <= N <= 10^3
Time Limit: 1sec
Sample input 1:
1
3
1 2 3
4 5 6
7 8 9
Sample Output 1:
45
Explanation for Sample Output 1:
The boundary elements are 1, 2, 3, 6, 9, 8, 7 and 4.

The first-diagonal elements are 1, 5 and 9.

The second-diagonal elements are 3, 5 and 7.

We just need to add all these numbers making sure that no number is added twice.
For example, '1' is both a boundary element and a first-diagonal element similarly, '5' contributes to both the diagonals but they won't be added twice.

Hence, we add up, [1 + 2 + 3 + 6 + 9 + 8 + 7 + 4 + 5] to give 45 as the output.
Sample input 2:
2
5
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
4
1 2 3 10
4 5 6 11
7 8 9 12
13 14 15 16
Sample Output 2:
273
136

*/

#include <iostream>
using namespace std;

// Function to calculate the sum of elements in the first diagonal of a square matrix
int getFirstDiagonalSum(int **input, int n)
{
    int sum = 0;

    // Traverse through the diagonal elements
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        sum += input[i][j]; // Add the element to the sum
    }
    return sum;
}

// Function to calculate the sum of elements in the second diagonal of a square matrix
int getSecondDiagonalSum(int **input, int n)
{
    int sum = 0;

    // Traverse through the diagonal elements
    for (int i = 0, j = n - 1; i < n; i++, j--)
    {
        sum += input[i][j]; // Add the element to the sum
    }

    return sum;
}

// Function to calculate the sum of boundary elements of a square matrix
int getBoundarySum(int **input, int n)
{
    int sum = 0;

    // Traverse through the boundary elements excluding the corners
    for (int i = 1; i < n - 1; i++)
    {
        sum += input[0][i];     // Top row
        sum += input[n - 1][i]; // Bottom row
        sum += input[i][0];     // Left column
        sum += input[i][n - 1]; // Right column
    }
    return sum;
}

// Function to calculate the total sum of the matrix
int totalSum(int **input, int n)
{

    int sum = getFirstDiagonalSum(input, n); // Sum of first diagonal
    sum += getSecondDiagonalSum(input, n);   // Sum of second diagonal
    sum += getBoundarySum(input, n);         // Sum of boundary elements

    // Adjust the sum if the matrix size is odd by subtracting the center element
    if (n % 2 != 0)
    {
        sum -= input[n / 2][n / 2];
    }
    return sum;
}

// Main function
int main()
{
    int t;
    cin >> t; // Input number of test cases
    while (t--)
    {
        int n;
        cin >> n;                 // Input size of the square matrix
        int **arr = new int *[n]; // Dynamically allocate memory for the matrix

        // Input elements of the matrix
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        // Output the total sum of the matrix
        cout << totalSum(arr, n) << endl;

        // Free memory allocated for the matrix
        for (int i = 0; i < n; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
    return 0;
}
