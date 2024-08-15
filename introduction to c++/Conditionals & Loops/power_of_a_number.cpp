
/*Problem statement
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to print the answer.

Note : For this question, you can assume that 0 raised to the power of 0 is 1

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Two integers x and n (separated by space)
Output Format :
x^n (i.e. x raise to the power n)
Constraints:
0 <= x <= 8
0 <= n <= 9
Sample Input 1 :
 3 4
Sample Output 1 :
81
Sample Input 2 :
 2 5
Sample Output 2 :
32*/
#include <iostream>  // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main()
{
    int x, n;      // Declare variables to store the base and exponent values
    cin >> x >> n; // Read the base and exponent values from the standard input

    int ans = 1; // Initialize a variable to store the result of the exponentiation

    // Loop through n times to perform exponentiation by multiplying x to itself
    while (n > 0)
    {
        ans *= x; // Multiply the current value of ans by x
        n--;      // Decrement the exponent value to keep track of the number of iterations
    }

    cout << ans; // Output the result of exponentiation

    return 0; // Indicate successful completion of the program
}
