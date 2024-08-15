
/*Problem statement
Given a number N, find its square root. You need to find and print only the integral part of square root of N.

For eg. if number given is 18, answer is 4.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 10^8
Sample Input 1 :
10
Sample Output 1 :
3
Sample Input 2 :
4
Sample Output 2 :
2*/
#include <iostream>  // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main()
{
    int n;    // Declare variable to store the input number
    cin >> n; // Read the input number from the standard input

    int output = 0; // Initialize variable to store the result
    while (output * output <= n)
    {                        // Iterate until the square of the current output is less than or equal to the input number
        output = output + 1; // Increment the output by 1 in each iteration
    }
    output = output - 1; // Since the loop exits when the square exceeds the input, decrement the output by 1 to get the correct result
    cout << output;      // Output the result
    return 0;            // Indicate successful completion of the program
}
