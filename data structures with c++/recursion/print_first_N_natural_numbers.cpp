
/*
Problem statement
Given the number 'n', write a code to print numbers from 1 to n in increasing order recursively.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Integer n
Output Format :
Numbers from 1 to n (separated by space)
Constraints :
1 <= n <= 10000
Sample Input 1 :
 6
Sample Output 1 :
1 2 3 4 5 6
Sample Input 2 :
 4
Sample Output 2 :
1 2 3 4
*/

/*
   Time Complexity : O(n)
   Space Complexity : O(n)

*/

#include <iostream> // Include the input/output stream library for standard I/O operations

using namespace std; // Using the standard namespace to avoid prefixing standard library functions with std::

// Recursive function to print the first 'n' natural numbers
void print(int n)
{
    // Base case: If n is 1, print 1 and return
    if (n == 1)
    {
        cout << n << " "; // Output the current number followed by a space
        return;           // Return from the function
    }
    // Recursive case: Print the first 'n-1' natural numbers recursively
    print(n - 1);
    // Output the current number followed by a space
    cout << n << " ";
}

// Main function
int main()
{
    int n;    // Declare an integer variable 'n' to store user input
    cin >> n; // Read an integer input from the user
    print(n); // Call the print function to print the first 'n' natural numbers
    return 0; // Indicate successful termination of the program
}
