
/*Problem statement
Given a decimal number (integer N), convert it into binary and print.

Note: The given input number could be large, so the corresponding binary number can exceed the integer range. So you may want to take the answer as long for CPP and Java.
Note for C++ coders: Do not use the inbuilt implementation of "pow" function. The implementation of that function is done for 'double's and it may fail when used for 'int's, 'long's, or 'long long's. Implement your own "pow" function to work for non-float data types.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 10^5
Sample Input 1 :
12
Sample Output 1 :
1100
Sample Input 2 :
7
Sample Output 2 :
111
*/
#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare variable to store the decimal number entered by the user
    cin >> n; // Read the decimal number from the standard input

    long binary = 0, pow = 1; // Initialize variables for the binary number and the power of 10
    while (n > 0) { // Continue the loop until the decimal number becomes 0
        int lastBit = n % 2; // Extract the last bit of the decimal number by taking the remainder when divided by 2
        binary += lastBit * pow; // Update the binary number by adding the last bit multiplied by the corresponding power of 10
        pow *= 10; // Increment the power of 10 for the next bit position
        n = n / 2; // Divide the decimal number by 2 to remove the last bit
    }
    cout << binary; // Output the calculated binary number
    return 0; // Indicate successful completion of the program
}
