
/*
Problem statement
You have been given an array/list(ARR) of size N.
You need to swap every pair of alternate elements in the array/list.

You don't need to print or return anything, just change in the input array itself.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the elements of the resulting array in a single row separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1sec
Sample Input 1:
1
6
9 3 6 12 4 32
Sample Output 1 :
3 9 12 6 32 4
Sample Input 2:
2
9
9 3 6 12 4 32 5 11 19
4
1 2 3 4
Sample Output 2 :
3 9 12 6 32 4 11 5 19
2 1 4 3

*/
#include <iostream>	 // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

// Function to swap alternate elements in an array
// Parameters:
// arr: Pointer to the array of integers
// size: Size of the array
// Swaps alternate elements starting from index 0 and 1, 2 and 3, and so on.
void swapAlternate(int *arr, int size)
{
	// Iterate over the array elements in steps of 2
	for (int i = 0; i < size - 1; i += 2)
	{
		int temp = arr[i];	 // Store the value of the current element
		arr[i] = arr[i + 1]; // Assign the value of the next element to the current element
		arr[i + 1] = temp;	 // Assign the stored value to the next element
	}
}

// Main function
int main()
{
	int t;	  // Declare a variable to store the number of test cases
	cin >> t; // Read the number of test cases from the standard input

	// Loop over each test case
	while (t--)
	{
		int size;				  // Declare a variable to store the size of the array
		cin >> size;			  // Read the size of the array from the standard input
		int *arr = new int[size]; // Dynamically allocate memory for the array

		// Read the elements of the array from the standard input
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		swapAlternate(arr, size); // Call the function to swap alternate elements in the array

		// Print the modified array
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl; // Print a new line after each test case
		delete[] arr; // Free the dynamically allocated memory for the array
	}
	return 0; // Indicate successful completion of the program
}
