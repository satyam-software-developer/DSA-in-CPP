
/* 
Problem statement
Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.

Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.

You should start traversing your array from 0, not from (N - 1).

Do this recursively. Indexing in the array starts from 0.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
last index or -1
Constraints :
1 <= N <= 10^3

Sample Input :
4
9 8 10 8
8
Sample Output :
3
*/

/*
   Time Complexity : O(n)
   Space Complexity : O(n)

   where n is size of input array
*/

#include <iostream>
using namespace std;

// Function to find the last index of a given number 'x' in an array 'input' of size 'size'.
int lastIndex(int input[], int size, int x)
{
    // Base case: if the size of the array is 0, return -1 (indicating not found).
    if (size == 0)
    {
        return -1;
    }
    // Recursive call: search for 'x' in the sub-array starting from the next element.
    int smallAns = lastIndex(input + 1, size - 1, x);
    // If 'x' is found in the sub-array, return the index shifted by 1.
    if (smallAns != -1)
    {
        return smallAns + 1;
    }
    // If 'x' is found at the current index (0-based), return 0.
    if (input[0] == x)
    {
        return 0;
    }
    else
    {
        // If 'x' is not found, return -1.
        return -1;
    }
}

// Main function to take input and call the lastIndex function.
int main()
{
    int n;
    // Read the size of the array.
    cin >> n;
    // Dynamically allocate memory for the array.
    int *input = new int[n];
    // Read 'n' integers into the array.
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    // Read the number to find its last index.
    int x;
    cin >> x;
    // Call the lastIndex function and print the result.
    cout << lastIndex(input, n, x) << endl;
    // Free the dynamically allocated memory.
    delete[] input;
    return 0;
}
