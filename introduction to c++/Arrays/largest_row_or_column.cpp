
/*
Problem statement
For a given two-dimensional integer array/list of size (N x M), you need to find out which row or column has the largest sum(sum of all the elements in a row or column) amongst all the rows/columns.

Note :
If there are more than one rows/columns with maximum sum, consider the row/column that comes first.
And if ith row and jth column has the same largest sum, consider the ith row as answer.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains two integer values, 'N' and 'M', separated by a single space.
They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

Second line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith row constitutes 'M' column values separated by a single space.
Output Format :
For each test case, If row sum is maximum, then print: "row" <row_index> <row_sum>
OR
If column sum is maximum, then print: "column" <col_index> <col_sum>
It will be printed in a single line separated by a single space between each piece of information.

Output for every test case will be printed in a seperate line.
 Consider :
If there doesn't exist a sum at all then print "row 0 -2147483648", where -2147483648 or -2^31 is the smallest value for the range of Integer.
Constraints:
1 <= t <= 10^2
1 <= N <= 10^3
1 <= M <= 10^3
Time Limit: 1sec
Sample Input 1:
1
3 2
6 9
8 5
9 2
Sample Output 1:
column 0 23
Sample Input 2:
1
4 4
6 9 8 5
9 2 4 1
8 3 9 3
8 7 8 6
Sample Output 2:
column 0 31

*/

// #include <iostream>
// #include <climits> // Include for INT_MIN
// using namespace std;

// // Function to find the row or column with the largest sum
// void findLargest(int arr[][100], int m, int n) {
//     // Initialize variables to store the maximum sum, index, and a flag to indicate if it's a row
//     int maxSum = INT_MIN, index = -1;
//     bool isRow = true;

//     // Calculate the sum of each row and find the row with the maximum sum
//     for (int i = 0; i < m; i++) {
//         int rowSum = 0;
//         // Iterate through each element in the current row and calculate its sum
//         for (int j = 0; j < n; j++) {
//             rowSum += arr[i][j];
//         }
//         // Check if the current row's sum is greater than the current maximum sum
//         if (rowSum > maxSum) {
//             // Update the maximum sum and the index of the row with the maximum sum
//             maxSum = rowSum;
//             index = i;
//         }
//     }

//     // Calculate the sum of each column and find the column with the maximum sum
//     for (int j = 0; j < n; j++) {
//         int colSum = 0;
//         // Iterate through each element in the current column and calculate its sum
//         for (int i = 0; i < m; i++) {
//             colSum += arr[i][j];
//         }
//         // Check if the current column's sum is greater than the current maximum sum
//         if (colSum > maxSum) {
//             // Update the flag to indicate it's not a row, update the maximum sum, and the index of the column with the maximum sum
//             isRow = false;
//             maxSum = colSum;
//             index = j; // Fix the typo: changed "intdex" to "index"
//         }
//     }

//     // Print whether the maximum sum belongs to a row or column, along with the index and the sum
//     if (isRow) {
//         cout << "row ";
//     } else {
//         cout << "column ";
//     }
//     cout << index << " " << maxSum << endl;
// }

// // Main function
// int main() {
//     int arr[100][100]; // Declare a 2D array with maximum dimensions
//     int m, n;
//     cin >> m >> n; // Input the number of rows and columns

//     // Taking input for the array
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> arr[i][j]; // Input the elements of the array
//         }
//     }

//     // Call the function to find the row or column with the largest sum
//     findLargest(arr, m, n);

//     return 0;
// }

#include <iostream>
#include <climits>
using namespace std;

// Function to find the row or column with the largest sum
void findLargest(int **input, int nRows, int mCols)
{
    // Initialize variables to store the state of whether the largest sum is in a row, the largest sum, and the index of the row or column
    bool isRow = true;
    int largestSum = INT_MIN;
    int num = 0;

    // Iterate through each row to calculate the sum of elements in that row and find the row with the largest sum
    for (int i = 0; i < nRows; i++)
    {
        int rowSum = 0;
        // Calculate the sum of elements in the current row
        for (int j = 0; j < mCols; j++)
        {
            rowSum += input[i][j];
        }
        // Update the largest sum and the index if the current row's sum is greater than the current largest sum
        if (rowSum > largestSum)
        {
            largestSum = rowSum;
            num = i; // Store the index of the row
        }
    }

    // Iterate through each column to calculate the sum of elements in that column and find the column with the largest sum
    for (int j = 0; j < mCols; j++)
    {
        int colSum = 0;
        // Calculate the sum of elements in the current column
        for (int i = 0; i < nRows; i++)
        {
            colSum += input[i][j];
        }
        // Update the largest sum, the index, and the flag indicating whether it's a row or column if the current column's sum is greater than the current largest sum
        if (colSum > largestSum)
        {
            largestSum = colSum;
            num = j;       // Store the index of the column
            isRow = false; // Update the flag to indicate it's not a row
        }
    }

    // Print whether the maximum sum belongs to a row or column, along with the index and the sum
    if (isRow)
    {
        cout << "row " << num << " " << largestSum;
    }
    else
    {
        cout << "column " << num << " " << largestSum;
    }
}

// Main function
int main()
{
    int t;
    cin >> t; // Input the number of test cases
    while (t--)
    {
        int row, col;
        cin >> row >> col; // Input the number of rows and columns for the current test case

        // Dynamically allocate memory for the 2D array
        int **input = new int *[row];
        for (int i = 0; i < row; i++)
        {
            input[i] = new int[col];
            // Input the elements of the array
            for (int j = 0; j < col; j++)
            {
                cin >> input[i][j];
            }
        }

        // Call the function to find the row or column with the largest sum for the current test case
        findLargest(input, row, col);
        cout << endl;
    }

    return 0;
}
