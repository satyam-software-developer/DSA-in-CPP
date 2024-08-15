
/* Problem statement
Print the following pattern for the given number of rows.

Pattern for N = 4


The dots represent spaces.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 50
Sample Input 1:
5
Sample Output 1:
           1
          232
         34543
        4567654
       567898765
Sample Input 2:
4
Sample Output 2:
           1
          232
         34543
        4567654 */


#include <iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare a variable to store the input number 'n'
    cin >> n; // Read the input number 'n' from the standard input

    int currRow = 1; // Initialize the current row counter
    while (currRow <= n) { // Loop to iterate through each row
        int spaces = 1; // Initialize the number of spaces for indentation
        while (spaces <= n - currRow) { // Loop to print spaces for indentation
            cout << " "; // Print space for indentation
            spaces = spaces + 1; // Move to the next space
        }
        
        int currCol = 1; // Initialize the current column counter
        int val = currRow; // Initialize the starting value for the current row
        while (currCol <= currRow) { // Loop to print numbers in increasing order
            cout << val; // Print the current value
            val = val + 1; // Increment the value for the next number
            currCol = currCol + 1; // Move to the next column
        }
        
        val = 2 * (currRow - 1); // Initialize the value for the second half of the row
        while (val >= currRow) { // Loop to print numbers in decreasing order
            cout << val; // Print the current value
            val = val - 1; // Decrement the value for the next number
        }
        
        cout << endl; // Move to the next line after printing the row
        currRow = currRow + 1; // Move to the next row
    }

    return 0; // Indicate successful completion of the program
}
