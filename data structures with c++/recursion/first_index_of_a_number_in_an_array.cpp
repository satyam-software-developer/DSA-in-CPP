
/*
Problem statement
Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array.
Return -1 if it is not present in the array.

First index means, the index of first occurrence of x in the input array.

Do this recursively. Indexing in the array starts from 0.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
first index or -1
Constraints :
1 <= N <= 10^3

Sample Input :
4
9 8 10 8
8
Sample Output :
1
*/

/*
  Time Complexity : O(n)
  Space Complexity : O(n)
  where n is size of input array

*/

#include <iostream>
using namespace std;

// Function to find the first index of the number 'x' in the array 'input'
// Parameters:
// - input: Pointer to the array
// - size: Size of the array
// - x: Number to search for in the array
int firstIndex(int input[], int size, int x)
{
    // Base case: If size is 0, the array is empty, so return -1 (indicating not found)
    if (size == 0)
    {
        return -1;
    }
    // Check if the first element of the array is equal to 'x'
    if (input[0] == x)
    {
        return 0; // Return the index of the first occurrence of 'x'
    }
    // Recursive step: Call the function with a pointer to the next element and decrement size
    int ans = firstIndex(input + 1, size - 1, x);

    // If 'x' is found in the subarray starting from index 1, return the adjusted index
    if (ans != -1)
    {
        return ans + 1;
    }
    else
    {
        return ans; // Otherwise, return -1
    }
}

// Main function
int main()
{
    int n;
    // Read the number of elements in the array from standard input
    cin >> n;

    // Dynamically allocate memory for the array
    int *input = new int[n];

    // Read the elements into the array
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;
    // Read the number to search for in the array
    cin >> x;

    // Call the firstIndex function and print the result
    cout << firstIndex(input, n, x) << endl;

    // Deallocate memory for the dynamically allocated array
    delete[] input;

    return 0;
}
