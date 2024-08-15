
/*
Problem statement
You have been given a random integer array/list(ARR) of size N.
You have been required to push all the zeros that are present in the array/list to the end of it.
Also, make sure to maintain the relative order of the non-zero elements.

Note:
Change in the input array/list itself. You don't need to return or print the elements.

You need to do this in one scan of array only. Don't use extra space.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the elements of the array/list in the desired order separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1:
1
7
2 0 0 1 3 0 0
Sample Output 1:
2 1 3 0 0 0 0
 Explanation for the Sample Input 1 :
All the zeros have been pushed towards the end of the array/list.
Another important fact is that the order of the non-zero elements have been maintained as they appear in the input array/list.
Sample Input 2:
2
5
0 3 0 2 0
5
9 0 0 8 2
Sample Output 2:
3 2 0 0 0
9 8 2 0 0

*/
#include <iostream>  // Include the input-output stream header file for standard input and output operations.
using namespace std; // Using the standard namespace to avoid having to prefix standard functions and objects with "std::".

void pushZeroesEnd(int *input, int size)
{
    // Function to push all the zeroes in the array to the end while maintaining the order of non-zero elements.
    int nonZero = 0; // Initialize a variable to keep track of the index where non-zero elements will be placed.

    // Iterate through the array.
    for (int i = 0; i < size; i++)
    {
        if (input[i] != 0) // If the current element is non-zero.
        {
            int temp = input[i];       // Swap the current non-zero element with the first zero element encountered.
            input[i] = input[nonZero]; // Move the non-zero element to the nonZero position.
            input[nonZero] = temp;     // Place the zero element in the current position.
            nonZero++;                 // Increment the non-zero index for the next iteration.
        }
    }
}

int main()
{
    int t;    // Declare a variable to store the number of test cases.
    cin >> t; // Read the number of test cases from the user.

    while (t--) // Loop through each test case.
    {
        int size;                   // Declare a variable to store the size of the array.
        cin >> size;                // Read the size of the array from the user.
        int *input = new int[size]; // Declare a dynamic array to store the elements.

        // Read elements of the array from the user.
        for (int i = 0; i < size; i++) // Iterate over each element of the array.
        {
            cin >> input[i]; // Read an element from the user and store it in the array.
        }

        pushZeroesEnd(input, size); // Call the function to push all zeroes to the end of the array.

        // Print the modified array.
        for (int i = 0; i < size; i++) // Iterate over each element of the array.
        {
            cout << input[i] << " "; // Output each element of the array followed by a space.
        }

        cout << endl;   // Output an end-of-line character after printing the array.
        delete[] input; // Free the memory allocated for the array.
    }
    return 0; // Return 0 to indicate successful execution of the program.
}
