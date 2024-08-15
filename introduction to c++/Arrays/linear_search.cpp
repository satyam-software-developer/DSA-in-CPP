
/*
Problem statement
You have been given a random integer array/list(ARR) of size N, and an integer X. 
You need to search for the integer X in the given array/list using 'Linear Search'.

 You have been required to return the index at which X is present in the array/list. 
 If X has multiple occurrences in the array/list, then you need to return the index at which the first occurrence of X would be encountered. 
 In case X is not present in the array/list, then return -1.

'Linear search' is a method for finding an element within an array/list. 
It sequentially checks each element of the array/list until a match is found or the whole array/list has been searched.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
-2 ^ 31 <= X <= (2 ^ 31) - 1
Time Limit: 1 sec
Sample Input 1:
1
7
2 13 4 1 3 6 28
3
Sample Output 1:
4
Sample Input 2:
2
7
2 13 4 1 3 6 28
9
5
7 8 5 9 5      
5
Sample Output 2:
-1
2

*/

#include<iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

// Function to perform linear search in an array
// Parameters:
// arr: Pointer to the array
// n: Size of the array
// val: Value to search for in the array
// Returns: Index of the first occurrence of val if found, otherwise -1
int linearSearch(int *arr, int n, int val) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == val) {
            return i; // Return the index of the first occurrence of val
        }
    }
    return -1; // Return -1 if val is not found in the array
}

// Main function
int main() {
    int t; // Declare a variable to store the number of test cases
	cin >> t; // Read the number of test cases from the standard input

	// Iterate over each test case
	while (t--) {
		int n; // Declare a variable to store the size of the array for the current test case
		cin >> n; // Read the size of the array from the standard input
		int *arr = new int[n]; // Dynamically allocate memory for the array

		// Read the elements of the array from the standard input
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		int val; // Declare a variable to store the value to search for
		cin >> val; // Read the value to search for from the standard input

		// Call the linearSearch function to find the index of val in the array
		cout << linearSearch(arr, n, val) << endl;

		delete[] arr; // Free the dynamically allocated memory to avoid memory leaks
	}
    
    return 0; // Indicate successful completion of the program
}
