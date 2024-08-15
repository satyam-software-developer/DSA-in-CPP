
/* 
Problem statement
You have been given an array/list 'ARR' of integers. 
Your task is to find the second largest element present in the 'ARR'.

Note:
a) Duplicate elements may be present.

b) If no such element is present return -1.
Example:
Input: Given a sequence of five numbers 2, 4, 5, 6, 8.

Output:  6

Explanation:
In the given sequence of numbers, number 8 is the largest element, 
followed by number 6 which is the second-largest element. 
Hence we return number 6 which is the second-largest element in the sequence.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 5000
-10 ^ 9 <= 'SIZE' <= 10 ^ 9 

Where ‘T’ is the total number of test cases, ‘N’ denotes the number of elements in the array and ‘SIZE’ denotes the range of the elements in the array.

Time limit: 1 sec.
Sample Input 1:
2
6
12 1 35 10 34 1
5
10 10 10 10 10
Sample Output 1:
34
-1
Explanation of sample input 1:
Test case 1: In the given sequence of numbers, number 35 is the largest element, followed by number 34 which is the second-largest element. 
Hence we return number 34 which is the second-largest element in the sequence.

Test case 2: In the given sequence of numbers, number 10 is the largest element. 
However, since all the elements are the same, the second largest element does not exist. So, we return -1.
Sample Input 2:
1
6
7 8 8 1 4 3 
Sample Output 2:
7
Explanation of sample input 2:
In the given sequence of numbers, 8 exists two times and is the largest element, followed by 7 which is the second-largest element. 
Hence we return the number 7 as the second-largest element.

*/

#include <iostream> // Include the input-output stream header file for standard input and output operations.
using namespace std; // Using the standard namespace to avoid having to prefix standard functions and objects with "std::".

// Function to find the second largest element in the array
int findSecondLargest(int arr[], int n)
{
    int i, j; // Declare variables for loop iteration
    bool swapped; // Declare a boolean variable to track if any swap occurred

    // Bubble sort algorithm to sort the array in ascending order
    for (int i = 0; i < n - 1; i++) // Outer loop for passes
    {
        swapped = false; // Initialize swapped as false for each pass
        for (j = 0; j < n - i - 1; j++) // Inner loop for comparisons
        {
            if (arr[j] > arr[j + 1]) // If current element is greater than the next element
            {
                swap(arr[j], arr[j + 1]); // Swap the elements
                swapped = true; // Set swapped to true indicating a swap occurred
            }
        }
        if (swapped == false) // If no swap occurred in the pass, the array is already sorted
            break; // Break the loop
    }

    // The second largest element is the second last element after sorting in ascending order
    return arr[n - 2]; // Return the second last element
}

// Main function
int main()
{
    int n; // Declare a variable to store the size of the array
    cin >> n; // Read the size of the array from the user
    int arr[n]; // Declare an array to store the elements

    // Read elements of the array from the user
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read an element from the user and store it in the array
    }

    int ans = findSecondLargest(arr, n); // Call the findSecondLargest function to get the second largest element
    cout << ans; // Print the second largest element

    return 0; // Return 0 to indicate successful completion of the program
}
