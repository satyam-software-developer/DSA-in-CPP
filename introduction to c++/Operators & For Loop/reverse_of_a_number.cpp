
/*Problem statement
Write a program to generate the reverse of a given number N. Print the corresponding reverse number.

Note : If a number has trailing zeros, then its reverse will not include them. For e.g., reverse of 10400 will be 401 instead of 00401.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
0 <= N < 10^8
Sample Input 1 :
1234
Sample Output 1 :
4321
Sample Input 2 :
1980
Sample Output 2 :
891
*/
#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare variable to store the input number
    cin >> n; // Read the input number from the standard input

    int temp = n, revNum = 0; // Declare variables to store temporary values and the reversed number

    while (temp > 0) { // Loop until all digits of the number are processed
        int lastDigit = temp % 10; // Extract the last digit of the number
        temp = temp / 10; // Remove the last digit from the number
        revNum = revNum * 10 + lastDigit; // Append the last digit to the reversed number
    }

    cout << revNum; // Output the reversed number
    return 0; // Indicate successful completion of the program
}
