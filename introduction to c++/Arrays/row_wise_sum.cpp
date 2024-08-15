
/*
Problem statement
For a given two-dimensional integer array/list of size (N x M), 
find and print the sum of each of the row elements in a single line, separated by a single space.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains two integer values, 'N' and 'M', separated by a single space. 
They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

Second line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith row constitutes 'M' column values separated by a single space.
Output Format :
For each test case, print the sum of every ith row elements in a single line separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= M <= 10^3
Time Limit: 1sec
Sample Input 1:
1
4 2 
1 2 
3 4 
5 6 
7 8
Sample Output 1:
3 7 11 15 
Sample Input 2:
2
2 5 
4 5 3 2 6 
7 5 3 8 9
4 4
1 2 3 4
9 8 7 6
3 4 5 6
-1 1 -10 5
Sample Output 2:
20 32 
10 30 18 -5 

*/
#include <iostream> // Include the input/output stream library
using namespace std; // Use the standard namespace for simplification

// Function to compute the row-wise sum of a 2D array
void rowWiseSum(int **input, int nRows, int mCols) {
    // Iterate over each row of the 2D array
    for (int i = 0; i < nRows; i++) {
        int rowSum = 0; // Initialize the sum for the current row
        
        // Iterate over each column of the current row
        for (int j = 0; j < mCols; j++) {
            rowSum += input[i][j]; // Add the current element to the row sum
        }
        
        cout << rowSum << " "; // Print the row sum
    }
}

// Main function
int main() {
    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases from input
    
    // Process each test case
    while (t--) {
        int row, col; // Variables to store the number of rows and columns
        cin >> row >> col; // Read the number of rows and columns
        
        // Allocate memory for a 2D array dynamically
        int **arr = new int *[row];
        
        // Input elements for each row of the 2D array
        for (int i = 0; i < row; i++) {
            arr[i] = new int[col]; // Allocate memory for each row
            for (int j = 0; j < col; j++) {
                cin >> arr[i][j]; // Read each element of the 2D array
            }
        }
        
        // Compute and print the row-wise sum of the 2D array
        rowWiseSum(arr, row, col);
        cout << endl; // Move to the next line for the next test case
        
        // Free the memory allocated for the 2D array
        for (int i = 0; i < row; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
    return 0; // Indicate successful completion of the program
}
