
/*
Problem statement
You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). 
Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3 and among these, 
there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.

Note :
Duplicate number is always present in the given array/list.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the duplicate element in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
Time Limit: 1 sec
Sample Input 1:
1
9
0 7 2 5 4 7 1 3 6
Sample Output 1:
7
Sample Input 2:
2
5
0 2 1 3 1
7
0 3 1 5 4 3 2
Sample Output 2:
1
3

*/
#include <iostream> // Include the necessary header file for input and output operations
#include <climits> // Include the necessary header file for using INT_MAX and INT_MIN constants
using namespace std; // Using the standard namespace to simplify code

// Function to find the duplicate number in the array
int duplicateNumber(int *arr, int size)
{
    // Iterate through the array elements
    for (int i = 0; i < size - 1; ++i)
    {
        // Compare each element with the subsequent elements
        for (int j = i + 1; j < size; ++j)
        {
            // If a duplicate element is found, return the duplicate number
            if (arr[i] == arr[j])
            {
                return arr[i];
            }
        }
    }
    // If no duplicate is found, return 0
    return 0;
}

// Main function
int main()
{
    int t; // Declare a variable to store the number of test cases
    cin >> t; // Read the number of test cases from the standard input

    // Iterate over each test case
    while (t--)
    {
        int size; // Declare a variable to store the size of the array for the current test case
        cin >> size; // Read the size of the array from the standard input
        int *input = new int[size]; // Dynamically allocate memory for the array

        // Read the elements of the array from the standard input
        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        // Call the function to find the duplicate number and output the result
        cout << duplicateNumber(input, size) << endl;

        delete[] input; // Deallocate memory for the array to avoid memory leaks
    }

    return 0; // Indicate successful completion of the program
}
