
/*
Problem statement
For a given two-dimensional integer array/list of size (N x M), print the array/list in a sine wave order, i.e, 
print the first column top to bottom, next column bottom to top and so on.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains two integer values, 'N' and 'M', separated by a single space. 
They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

Second line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith row constitutes 'M' column values separated by a single space.
Output format :
For each test case, print the elements of the two-dimensional array/list in the sine wave order in a single line, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= M <= 10^3
Time Limit: 1sec
Sample Input 1:
1
3 4 
1  2  3  4 
5  6  7  8 
9 10 11 12
Sample Output 1:
1 5 9 10 6 2 3 7 11 12 8 4
Sample Input 2:
2
5 3 
1 2 3 
4 5 6 
7 8 9 
10 11 12 
13 14 15
3 3
10 20 30 
40 50 60
70 80 90
Sample Output 2:
1 4 7 10 13 14 11 8 5 2 3 6 9 12 15 
10 40 70 80 50 20 30 60 90 

*/

// #include <iostream>
// using namespace std;

// void wavePrint(int arr[][100], int m, int n){
//     for(int j = 0; j < n; j++){
//         if(j % 2 == 0){
//             for(int i = 0; i < m; i++){
//                 cout << arr[i][j] << " ";
//             }
//         }
//         else{
//             for(int i = m-1; i>=0; i--){
//                 cout << arr[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }
// }

//     int
//     main()
// {
// int  a[100][100];
// int m, n;
// cin >> m >> n;

// //Taking input
// for(int i = 0; i < m; i++){
//     for(int j = 0; j < n; j++){
//         cin >> a[i][j];
//     }
// }

// wavePrint(a, m, n);
//     return 0;
// }

#include<iostream> // Including the input/output stream library for standard I/O operations
using namespace std; // Using the standard namespace for easier access to standard library functions

// Function to print elements of a 2D array in a wave pattern
void wavePrint(int **input, int nRows, int mCols){

    if(nRows == 0 ){ // Checking if the number of rows is 0, if so, there's nothing to print, so return from the function
        return;
    }

    // Iterating through each column of the array
    for(int j = 0; j < mCols; j++){
        if(j % 2 == 0){ // If the column index is even
            // Printing elements of the column from top to bottom
            for(int i = 0; i < nRows; i++){
               cout << input[i][j] << " ";
            }
        }
        else{ // If the column index is odd
            // Printing elements of the column from bottom to top
            for(int i = nRows - 1; i >= 0; i--){
               cout << input[i][j] << " ";
            }
        }
    }
}

int main(){

    int t; // Variable to store the number of test cases
	cin >> t; // Reading the number of test cases from standard input
	while (t--) // Looping through each test case
	{
		int row, col; // Variables to store the number of rows and columns in the 2D array
		cin >> row >> col; // Reading the number of rows and columns for the current test case
		int **input = new int *[row]; // Dynamically allocating memory for 'row' number of pointers to integer arrays
		for (int i = 0; i < row; i++) // Looping through each row
		{
			input[i] = new int[col]; // Dynamically allocating memory for 'col' number of integers in each row
			for (int j = 0; j < col; j++) // Looping through each column
			{
				cin >> input[i][j]; // Reading the elements of the 2D array from standard input
			}
		}
		wavePrint(input, row, col); // Calling the wavePrint function to print the array elements in a wave pattern
		cout << endl; // Printing a newline after each test case
	}
    
    return 0; // Indicating successful completion of the program
}
