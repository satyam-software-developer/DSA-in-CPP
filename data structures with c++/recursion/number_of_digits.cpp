
/*
Problem statement
You are given a number 'n'.

Return number of digits in ‘n’.

Example:
Input: 'n' = 123

Output: 3

Explanation:
The 3 digits in ‘123’ are 1, 2 and 3.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line of input contains an integer ‘n’.

Output Format:
Return an integer as described in the problem statement.

Note
You don’t need to print anything, it has already been taken care of, just complete the given function.
Sample Input 1:
121

Sample Output 1:
3

Explanation of sample output 1:
There are 3 digits in 121 are 1,2 and 1.

Sample Input 2:
38

Sample Output 2:
2

Expected time complexity :
The expected time complexity is O(log n).

Constraints:
1 <= ‘n’ <= 10^9
*/

/*
  Time Complexity: O(1)
  Space Complexity: O(1)

  Where 'n' is the given number.

*/

#include <iostream>  // Include the input/output stream library for standard I/O operations
#include <cmath>     // Include the cmath library for mathematical functions
using namespace std; // Using the standard namespace to avoid prefixing standard library functions with std::

// Function to count the number of digits in an integer 'n'
int countDigits(int n)
{
  return log10(n) + 1; // Using log10() to calculate the number of digits
}

// Main function
int main()
{
  int n;                  // Declare an integer variable 'n' to store user input
  cin >> n;               // Read an integer input from the user
  cout << countDigits(n); // Call the countDigits function with the input 'n' and print the result
  return 0;               // Indicate successful termination of the program
}
