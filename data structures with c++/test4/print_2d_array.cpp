
/* 
Problem statement
Given a 2D integer array with n rows and m columns. 
Print the 0th row from input n times, 1st row n-1 times…..(n-1)th row will be printed 1 time.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : No of rows (n) and no of columns (m) (separated by single space)
Line 2 : Row 1 elements (separated by space)
Line 3 : Row 2 elements (separated by space)
Line 4 : and so on
Sample Input 1:
3 3
1 2 3
4 5 6
7 8 9
Sample Output 1 :
1 2 3
1 2 3
1 2 3
4 5 6
4 5 6
7 8 9
*/

#include <iostream>
using namespace std;

// Function to print the 2D array as per the given pattern
void print2DArray(int input[][1000], int row, int col)
{
    // Initialize a variable 'k' to store the number of rows
    int k = row;
    // Loop through each row of the input array
    for (int i = 0; i < row; i++)
    {
        // Loop 'k' times to print the current row 'k' times
        for (int l = k - 1; l >= 0; l--)
        {
            // Loop through each column of the current row
            for (int j = 0; j < col; j++)
            {
                // Print the element of the current row
                cout << input[i][j] << " ";
            }
            // Move to the next line after printing each row
            cout << "\n";
        }
        // Decrement the value of 'k' to consider fewer rows in each iteration
        k--;
    }
}

// Main function
int main()
{
    // Declare variables to store the number of rows and columns
    int row, col;
    // Read the number of rows and columns from the user
    cin >> row >> col;

    // Declare a 2D array with 'row' rows and 1000 columns
    int input[row][1000];
    // Loop to input elements into the 2D array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> input[i][j];
        }
    }
    // Call the print2DArray function to print the input array
    print2DArray(input, row, col);

    return 0;
}
