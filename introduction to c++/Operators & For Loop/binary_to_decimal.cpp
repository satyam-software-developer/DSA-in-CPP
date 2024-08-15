
/*Problem statement
Given a binary number as an integer N, convert it into decimal and print.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 10^9
Sample Input 1 :
1100
Sample Output 1 :
12
Sample Input 2 :
111
Sample Output 2 :
7
*/
#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int num; // Declare variable to store the binary number entered by the user
    cin >> num; // Read the binary number from the standard input

    int decimal = 0, pow = 1; // Initialize variables for the decimal number and the power of 2
    while (num > 0) { // Continue the loop until the binary number becomes 0
        int last = num % 10; // Extract the last digit of the binary number
        decimal += last * pow; // Update the decimal number by adding the last digit multiplied by the corresponding power of 2
        pow *= 2; // Increment the power of 2 for the next digit
        num = num / 10; // Remove the last digit from the binary number
    }
    cout << decimal; // Output the calculated decimal number
    return 0; // Indicate successful completion of the program
}
