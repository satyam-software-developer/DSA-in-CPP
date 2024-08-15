
/*
Problem statement
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

You need to find and return that number which is unique in the array/list.

 Note:
Unique element is always present in the array/list according to the given condition.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the unique element present in the array.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
Time Limit: 1 sec
Sample Input 1:
1
7
2 3 1 6 3 6 2
Sample Output 1:
1
Explanation: The array is [2, 3, 1, 6, 3, 6, 2]. Here, the numbers 2, 3, and 6 are present twice, 
and the number 1 is present only once. So, the unique number in this array is 1.
Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7
Sample Output 2:
4
Explanation: In the first test case, the array is [2, 4, 7, 2, 7]. Here, 
the numbers 2 and 7 are present twice, and the number 4 is present only once. So, the unique number in this array is 4.

10
Explanation: In the second test case, the array is [1, 3, 1, 3, 6, 6, 7, 10, 7]. Here, 
the numbers 1, 3, 6, and 7 are present twice, and the number 10 is present only once. So, the unique number in this array is 10.

*/
#include <iostream> // Include the necessary header file for input and output operations
#include <climits> // Include the necessary header file for using INT_MIN constant
using namespace std; // Using the standard namespace to simplify code

// Function to find the unique element in the array
int findUnique(int *arr, int size)
{
    // Iterate through the array elements
    for (int i = 0; i < size; ++i)
    {
        int j;
        // Check for duplicates by comparing each element with the others
        for (j = 0; j < size; ++j)
        {
            // If a duplicate is found, break the loop
            if (i != j && arr[i] == arr[j])
            {
                break;
            }
        }
        // If the loop completes without finding a duplicate, return the unique element
        if (j == size)
        {
            return arr[i];
        }
    }
    // Return INT_MIN if no unique element is found
    return INT_MIN;
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
        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        // Call the function to find the unique element and output the result
        cout << findUnique(input, size) << endl;

        delete[] input; // Deallocate memory for the array to avoid memory leaks
    }

    return 0; // Indicate successful completion of the program
}
