
/*
Problem statement
Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.

Do this recursively.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
'true' or 'false'
Constraints :
1 <= N <= 10^3
Sample Input 1 :
3
9 8 10
8
Sample Output 1 :
true
Sample Input 2 :
3
9 8 10
2
Sample Output 2 :
false
*/

/*
  Time Complexity : O(n)
  Space Complexity : O(n)

  where n is size of input array

*/

#include <iostream>
using namespace std;

// Function to check if a number 'x' exists in the array 'input'
// Parameters:
// - input: Pointer to the array
// - size: Size of the array
// - x: Number to search for in the array
bool checkNumber(int input[], int size, int x)
{
    // Base case: If size is 0, the array is empty, so return false
    if (size == 0)
    {
        return false;
    }
    // Check if the first element of the array is equal to 'x'
    else if (input[0] == x)
    {
        return true;
    }
    // Recursive step: Call the function with a pointer to the next element and decrement size
    return checkNumber(input + 1, size - 1, x);
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

    // Call the checkNumber function and print the result
    if (checkNumber(input, n, x))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    // Deallocate memory for the dynamically allocated array
    delete[] input;

    return 0;
}
