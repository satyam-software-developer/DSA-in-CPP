
/*
Problem statement
You have been given a random integer array/list(ARR) of size N. 
Write a function that rotates the given array/list by D elements(towards the left).

 Note:
Change in the input array/list itself.You don't need to return or print the elements.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains the value of 'D' by which the array/list needs to be rotated.
Output Format :
For each test case, print the rotated array/list in a row separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^4
0 <= N <= 10^6
0 <= D <= N
Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2
Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2
Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2

*/

#include <iostream> // Include the input-output stream header file for standard input and output operations.
using namespace std; // Using the standard namespace to avoid having to prefix standard functions and objects with "std::".

// Function to swap elements at indices i and j in the array.
void swapElements(int *input, int i, int j)
{
    int temp = input[i]; // Store the value of input[i] in a temporary variable.
    input[i] = input[j]; // Assign the value of input[j] to input[i].
    input[j] = temp; // Assign the value of the temporary variable to input[j].
}

// Function to reverse elements in the array between indices start and end.
void reverse(int *input, int start, int end)
{
    int i = start, j = end; // Initialize two pointers, i and j, at start and end indices respectively.

    // Loop until i crosses j.
    while (i < j)
    {
        swapElements(input, i, j); // Swap elements at indices i and j.
        i++; // Move i forward.
        j--; // Move j backward.
    }
}

// Function to rotate the array to the left by d positions.
void rotate(int *input, int d, int n)
{
    if (d >= n && n != 0) // If d is greater than or equal to n and n is not zero.
    {
        d = d % n; // Set d to the remainder when divided by n.
    }
    else if (n == 0) // If n is zero, return without rotation.
    {
        return;
    }

    // Perform array rotation in three steps: reverse the entire array, then reverse the first part, then reverse the second part.
    reverse(input, 0, n - 1); // Reverse the entire array.
    reverse(input, 0, n - d - 1); // Reverse the first part of the array.
    reverse(input, n - d, n - 1); // Reverse the second part of the array.
}

int main()
{
    int t; // Declare a variable to store the number of test cases.
    cin >> t; // Read the number of test cases from the user.

    while (t--) // Loop through each test case.
    {
        int size; // Declare a variable to store the size of the array.
        cin >> size; // Read the size of the array from the user.

        int *input = new int[size]; // Dynamically allocate memory for the array.

        // Read elements of the array from the user.
        for (int i = 0; i < size; ++i)
        {
            cin >> input[i]; // Read an element from the user and store it in the array.
        }

        int d; // Declare a variable to store the number of rotations.
        cin >> d; // Read the number of rotations from the user.

        rotate(input, d, size); // Call the rotate function to rotate the array by d positions to the left.

        // Print the rotated array.
        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " "; // Output each element of the array followed by a space.
        }

        delete[] input; // Free the memory allocated for the array.
        cout << endl; // Output an end-of-line character after printing the array.
    }
    return 0; // Return 0 to indicate successful execution of the program.
}
