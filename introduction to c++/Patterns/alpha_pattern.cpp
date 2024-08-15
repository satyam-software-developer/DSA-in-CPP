
/*Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 3
 A
 BB
 CCC
Detailed explanation ( Input/output format, Notes, Images )
Constraints
0 <= N <= 26
Sample Input 1:
7
Sample Output 1:
A
BB
CCC
DDDD
EEEEE
FFFFFF
GGGGGGG
Sample Input 2:
6
Sample Output 2:
A
BB
CCC
DDDD
EEEEE
FFFFFF*/

#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare a variable to store the input number of rows
    cin >> n; // Read the input number from the standard input

    int currRow = 1; // Initialize the current row counter to 1
    while (currRow <= n) { // Outer loop for iterating through each row
        int currCol = 1; // Initialize the current column counter to 1
        char ch = 'A' + currRow - 1; // Calculate the character based on the current row
        while (currCol <= currRow) { // Inner loop for printing characters in each row
            cout << ch; // Output the character
            currCol = currCol + 1; // Increment the current column counter
        }
        cout << endl; // Move to the next line after printing characters for the current row
        currRow = currRow + 1; // Increment the current row counter
    }

    return 0; // Indicate successful completion of the program
}
