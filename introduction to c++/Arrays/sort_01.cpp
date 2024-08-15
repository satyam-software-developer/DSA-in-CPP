
/*
Problem statement
You have been given an integer array/list(ARR) of size N that contains only integers, 0 and 1. 
Write a function to sort this array/list. Think of a solution which scans the array/list only once and don't require use of an extra array/list.

Note:
You need to change in the given array/list itself. Hence, no need to return or print anything. 
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers(all 0s and 1s) representing the elements in the array/list.
Output format :
For each test case, print the sorted array/list elements in a row separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1:
1
7
0 1 1 0 1 0 1
Sample Output 1:
0 0 0 1 1 1 1
Sample Input 2:
2
8
1 0 1 1 0 1 0 1
5
0 1 0 1 0
Sample Output 2:
0 0 0 1 1 1 1 1
0 0 0 1 1 

*/

#include<iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

// Function to sort an array of zeroes and ones
// Parameters:
// input: Pointer to the array of integers
// size: Size of the array
// Sorts the array in-place with all zeroes appearing before ones
void sortZeroesAndOne(int input[], int size)
{
    int nextZero = 0; // Initialize the index for the next zero element
    // Iterate over each element of the array
    for(int i = 0; i < size; i++)
    {
        // If the current element is zero, swap it with the next zero element
        if(input[i] == 0)
        {
            int temp = input[nextZero]; // Store the value of the next zero element
            input[nextZero] = input[i]; // Assign the current element to the next zero position
            input[i] = temp; // Assign the value stored in temp to the current position
            nextZero++; // Move the nextZero index forward
        }
    }
}

// Main function
int main()
{
    int t; // Declare a variable to store the number of test cases
	cin >> t; // Read the number of test cases from the standard input

	// Loop over each test case
	while (t--)
	{
		int size; // Declare a variable to store the size of the array
		cin >> size; // Read the size of the array from the standard input
		int input[size]; // Declare an array to store the elements

		// Read the elements of the array from the standard input
		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		sortZeroesAndOne(input, size); // Call the function to sort the array of zeroes and ones

		// Print the sorted array
		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		cout << endl; // Print a new line after each test case
	}
    
    return 0; // Indicate successful completion of the program
}
