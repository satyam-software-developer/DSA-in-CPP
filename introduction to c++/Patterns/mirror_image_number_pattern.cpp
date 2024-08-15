
/*Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 4

The dots represent spaces.

Detailed explanation ( Input/output format, Notes, Images )
Constraints
0 <= N <= 50
Sample Input 1:
3
Sample Output 1:
      1 
    12
  123
Sample Input 2:
4
Sample Output 2:
      1 
    12
  123
1234*/
#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare a variable to store the input number of rows
    cin >> n; // Read the input number of rows from the standard input

    int currRow = 1; // Initialize the current row counter
    while (currRow <= n) { // Loop to iterate through each row
        int spaces = 1; // Initialize the counter for spaces to be printed before the numbers
        while (spaces <= n - currRow) { // Loop to print spaces before the numbers
            cout << " "; // Print a space
            spaces = spaces + 1; // Move to the next space
        }
        int currCol = 1; // Initialize the current column counter for the numbers
        while (currCol <= currRow) { // Loop to print the numbers in the current row
            cout << currCol; // Print the current column number
            currCol = currCol + 1; // Move to the next column
        }
        cout << endl; // Move to the next line after printing numbers for the current row
        currRow = currRow + 1; // Move to the next row
    }

    return 0; // Indicate successful completion of the program
}
