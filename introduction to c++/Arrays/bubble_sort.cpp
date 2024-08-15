
/*
Problem statement
You are given an integer array 'arr' of size 'N'.

You must sort this array using 'Bubble Sort'.

Note:
Change in the input array itself. You don't need to return or print the elements.
Example:
Input: ‘N’ = 7
'arr' = [2, 13, 4, 1, 3, 6, 28]

Output: [1 2 3 4 6 13 28]

Explanation: After applying bubble sort on the input array, the output is [1 2 3 4 6 13 28].
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an integer 'N' representing the size of the array.

The second line contains 'N' single space-separated integers representing the elements of the array.
Output format :
The output contains the array elements after the sorting.
Sample Input 1:
7
2 13 4 1 3 6 28
Sample Output 1:
1 2 3 4 6 13 28
Explanation of Sample Output 1:
After applying bubble sort on the input array, the output is [1 2 3 4 6 13 28].
Sample Input 2:
5
9 3 6 2 0
Sample Output 2:
0 2 3 6 9
Explanation of Sample Output 2:
After applying bubble sort on the input array, the output is [0 2 3 6 9].
Constraints :
1 <= N <= 10^3
0 <= arr[i] <= 10^9
Time Limit: 1 sec

*/
#include <iostream> // Include the input-output stream header file for standard input and output operations.

using namespace std; // Using the standard namespace to avoid having to prefix standard functions and objects with "std::".

void printArray(int input[], int n)
{
    // Function to print the elements of an array.
    for (int i = 0; i < n; i++) // Iterate over each element of the array.
    {
        cout << input[i] << " "; // Output the current element followed by a space.
    }
    cout << endl; // Output an end-of-line character after printing all elements.
}

void bubbleSort(int arr[], int n)
{
    // Function to perform bubble sort on an array.
    for (int i = 0; i < n - 1; i++) // Iterate over the array except for the last element.
    {
        for (int j = 0; j < n - 1 - i; j++) // Iterate over the unsorted part of the array.
        {
            if (arr[j] > arr[j + 1]) // Compare adjacent elements.
            {
                // Swap the elements if they are in the wrong order.
                int temp = arr[j];   // Store the current element in a temporary variable.
                arr[j] = arr[j + 1]; // Assign the next element to the current position.
                arr[j + 1] = temp;   // Assign the temporary variable value to the next position.
            }
        }
    }
}

int main()
{
    // Main function, entry point of the program.

    int n;    // Declare a variable to store the size of the array.
    cin >> n; // Read the size of the array from the user.

    int input[100]; // Declare an array of size 100 to store user input.

    // Read elements of the array from the user.
    for (int i = 0; i < n; i++) // Iterate over each element of the array.
    {
        cin >> input[i]; // Read an element from the user and store it in the array.
    }

    bubbleSort(input, n); // Call the bubbleSort function to sort the array.

    printArray(input, n); // Call the printArray function to print the sorted array.

    return 0; // Return 0 to indicate successful execution of the program.
}
