
/*Problem statement
Print the following pattern for the given number of rows.

Pattern for N = 5
E
DE
CDE
BCDE
ABCDE
Detailed explanation ( Input/output format, Notes, Images )
Constraints
0 <= N <= 26
Sample Input 1:
8
Sample Output 1:
H
GH
FGH
EFGH
DEFGH
CDEFGH
BCDEFGH
ABCDEFGH
Sample Input 2:
7
Sample Output 2:
G
FG
EFG
DEFG
CDEFG
BCDEFG
ABCDEFG
*/
#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare a variable to store the input number
    cin >> n; // Read the input number from the standard input

    int currRow = 1; // Initialize the current row counter
    while (currRow <= n) { // Loop to print each row of the pattern
        int currCol = 1; // Initialize the current column counter for the current row
        char ch = 'A' + n - currRow; // Determine the character to start with based on the row number
        while (currCol <= currRow) { // Loop to print characters for the current row
            cout << char(ch + currCol - 1); // Print the current character
            currCol = currCol + 1; // Move to the next column
        }
        cout << endl; // Move to the next line after printing characters for the current row
        currRow = currRow + 1; // Move to the next row
    }

    return 0; // Indicate successful completion of the program
}
