
/*
Problem statement
Given an array/list(ARR) of length N, you need to find and return the sum of all the elements in the array/list.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5

Time Limit: 1sec
Sample Input 1:
1
3
9 8 9
Sample Output 1:
26
Sample Input 2:
2
5
1 2 3 4 5
3
10 20 30
Sample Output 2:
15
60

*/
#include <iostream>	 // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

// Function to calculate the sum of elements in an array
// Parameters:
// arr: Pointer to the array of integers
// size: Size of the array
// Returns: Sum of elements in the array
int sum(int arr[], int size)
{
	int ans = 0; // Initialize the sum to 0
	// Iterate over each element of the array
	for (int i = 0; i < size; i++)
	{
		ans += arr[i]; // Add the current element to the sum
	}
	return ans; // Return the total sum of elements in the array
}

// Main function
int main()
{
	int t;	  // Declare a variable to store the number of test cases
	cin >> t; // Read the number of test cases from the standard input

	while (t--) // Loop over each test case
	{
		int size;	 // Declare a variable to store the size of the array
		cin >> size; // Read the size of the array from the standard input

		int *arr = new int[size]; // Dynamically allocate memory for the array

		// Read the elements of the array from the standard input
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		int ans = sum(arr, size); // Calculate the sum of elements using the sum function

		cout << ans << endl; // Print the sum of elements
		delete[] arr;		 // Free the dynamically allocated memory to avoid memory leaks
	}
	return 0; // Indicate successful completion of the program
}
