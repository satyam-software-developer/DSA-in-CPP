
/*
Problem statement
You have been given an empty array(ARR) and its size N.
The only input taken from the user will be N and you need not worry about the array.

Your task is to populate the array using the integer values in the range 1 to N(both inclusive) in the order - 1,3,5,.......,6,4,2.

Note:
You need not print the array. You only need to populate it.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
Then the test cases follow.

The first and the only line of each test case or query contains an integer 'N'.
Output Format :
For each test case, print the elements of the array/list separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^4

Time Limit: 1sec
Sample Input 1 :
1
6
Sample Output 1 :
1 3 5 6 4 2
Explanation of Sample Input 1 :
Since the value of N is 6, the number will be stored in the array in such a fashion that 1 will appear at 0th index, then 2 at the last index, in a similar fashion 3 is stored at index 1.
Hence the array becomes 1 3 5 6 4 2.
Sample Input 2 :
2
9
3
Sample Output 2 :
1 3 5 7 9 8 6 4 2
1 3 2

*/
#include <iostream>  // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

// Function to arrange the array elements
void arrange(int *arr, int n)
{
    int left = 0;      // Initialize left pointer to the start of the array
    int right = n - 1; // Initialize right pointer to the end of the array
    int counter = 1;   // Initialize a counter starting from 1

    // Loop until left pointer is less than or equal to right pointer
    while (left <= right)
    {
        if (counter % 2 == 1) // If counter is odd
        {
            arr[left] = counter; // Assign the current counter value to the element at left pointer
            counter++;           // Increment the counter
            left++;              // Move the left pointer to the right
        }
        else // If counter is even
        {
            arr[right] = counter; // Assign the current counter value to the element at right pointer
            counter++;            // Increment the counter
            right--;              // Move the right pointer to the left
        }
    }
}

// Main function
int main()
{
    int t;    // Declare a variable to store the number of test cases
    cin >> t; // Read the number of test cases from the standard input

    // Iterate over each test case
    while (t--)
    {
        int n;    // Declare a variable to store the size of the array for the current test case
        cin >> n; // Read the size of the array from the standard input

        int *arr = new int[n]; // Dynamically allocate memory for the array

        arrange(arr, n); // Call the function to arrange the array elements

        // Output the arranged array elements separated by space
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl; // Move to the next line after printing the array elements

        delete[] arr; // Deallocate memory for the array to avoid memory leaks
    }

    return 0; // Indicate successful completion of the program
}
