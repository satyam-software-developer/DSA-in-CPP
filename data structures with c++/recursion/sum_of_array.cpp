
/*
Problem statement
Given an array of length N, you need to find and return the sum of all elements of the array.

Do this recursively.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Sum
Constraints :
1 <= N <= 10^3
Sample Input 1 :
3
9 8 9
Sample Output 1 :
26
Sample Input 2 :
3
4 2 1
Sample Output 2 :
7
*/

/*
   Time Complexity : O(n)
   Space Complexity : O(n)

   Where n is size of input array

*/

#include <iostream>
using namespace std;

// Recursive function to calculate the sum of elements in an array
// Parameters:
// - input: Pointer to the array
// - n: Number of elements in the array
int sum(int input[], int n)
{
    // Base case: If there are no elements in the array, return 0
    if (n == 0)
    {
        return 0;
    }
    // Recursive step: Add the first element of the array to the sum of the rest of the array
    return input[0] + sum(input + 1, n - 1);
}

// Main function
int main()
{
    int n;
    // Reading the number of elements in the array from standard input
    cin >> n;

    // Dynamically allocating memory for the array
    int *input = new int[n];

    // Reading elements into the array
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    // Printing the sum of elements in the array by calling the sum function
    cout << sum(input, n) << endl;

    // Freeing dynamically allocated memory
    delete[] input;

    return 0;
}
