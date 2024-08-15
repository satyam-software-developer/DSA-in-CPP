
/*
Problem statement
You are given an integer array 'arr' of size 'N'.

You must sort this array using 'Insertion Sort' recursively.

 Note:
Change in the input array itself. You don't need to return or print the elements.
Example:
Input: ‘N’ = 7
'arr' = [2, 13, 4, 1, 3, 6, 28]

Output: [1 2 3 4 6 13 28]

Explanation: After applying insertion sort on the input array, the output is [1 2 3 4 6 13 28].
Detailed explanation ( Input/output format, Notes, Images )
 Input format :
The first line contains an integer 'N' representing the size of the array.

The second line contains 'N' single space-separated integers representing the elements of the array.
Output Format :
Print the array elements in sorted order, separated by a single space.
Sample Input 1:
5
9 3 6 2 0
Sample Output 1:
0 2 3 6 9
Sample Input 2:
4
4 3 2 1
Sample Output 2:
1 2 3 4 
Constraints :
0 <= N <= 10^3
0 <= arr[i] <= 10^5
Time Limit: 1 sec

*/

/*
  Time Complexity: O(N^2)
  Space Complexity: O(N)

*/

#include <iostream> // Include the input-output stream header file for standard input and output operations.

using namespace std; // Using the standard namespace to avoid having to prefix standard functions and objects with "std::".

void insertionSort(int arr[], int n)
{
    // Function to perform insertion sort on an array.
    int i, key, j; // Declare variables for loop control and key storage.
    for (i = 1; i < n; i++) // Loop through the array starting from the second element.
    {
        key = arr[i]; // Store the current element in the key variable.
        j = i - 1; // Initialize j to the index of the previous element.
        while (j >= 0 && arr[j] > key) // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position.
        {
            arr[j + 1] = arr[j]; // Shift elements to the right.
            j = j - 1; // Move to the previous element.
        }
        arr[j + 1] = key; // Place the key at its correct position.
    }
}

int main()
{
    // Main function, entry point of the program.
    
    int n; // Declare a variable to store the size of the array.
    cin >> n; // Read the size of the array from the user.
    int arr[n]; // Declare an array of size 'n' to store user input.

    // Read elements of the array from the user.
    for (int i = 0; i < n; i++) // Iterate over each element of the array.
    {
        cin >> arr[i]; // Read an element from the user and store it in the array.
    }

    insertionSort(arr, n); // Call the insertionSort function to sort the array.

    // Print the sorted array.
    for (int i = 0; i < n; i++) // Iterate over each element of the array.
    {
        cout << arr[i] << " "; // Output each element of the array followed by a space.
    }

    return 0; // Return 0 to indicate successful execution of the program.
}
