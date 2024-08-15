
/*
Problem statement
You have been given an integer array/list(ARR) of size N.
It has been sorted(in increasing order) and then rotated by some number 'K' (K is greater than 0) in the right hand direction.

Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the value of 'K' or the index from which which the array/list has been rotated.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
2 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1:
1
6
5 6 1 2 3 4
Sample Output 1:
2
Sample Input 2:
2
5
3 6 8 9 10
4
10 20 30 1
Sample Output 2:
0
3

*/

#include <iostream>  // Include the input-output stream header file for standard input and output operations.
using namespace std; // Using the standard namespace to avoid having to prefix standard functions and objects with "std::".

// Function to check if the array is rotated and find the rotation count
int arrayRotateCheck(int *input, int size)
{
    for (int i = 0; i < size - 1; ++i) // Iterate through the array till the second last element
    {
        if (input[i] > input[i + 1]) // If the current element is greater than the next element
        {
            return i + 1; // Return the index of the next element, indicating the rotation count
        }
    }
    return 0; // If no rotation is found, return 0
}

// Main function
int main()
{
    int t;      // Declare a variable to store the number of test cases
    cin >> t;   // Read the number of test cases from the user
    while (t--) // Loop through each test case
    {
        int size;                   // Declare a variable to store the size of the array
        cin >> size;                // Read the size of the array from the user
        int *input = new int[size]; // Declare a dynamic array to store the elements

        for (int i = 0; i < size; i++) // Loop to read elements of the array
        {
            cin >> input[i]; // Read an element from the user and store it in the array
        }

        cout << arrayRotateCheck(input, size) << endl; // Print the rotation count of the array
        delete[] input;                                // Deallocate memory occupied by the dynamic array
    }

    return 0; // Return 0 to indicate successful completion of the program
}
