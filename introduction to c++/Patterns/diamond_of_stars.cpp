
/*Problem statement
Print the following pattern for the given number of rows.

Note: N is always odd.

Pattern for N = 5

The dots represent spaces.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 49
Sample Input 1:
5
Sample Output 1:
  *
 ***
*****
 ***
  *
Sample Input 2:
3
Sample Output 2:
  *
 ***
  **/

#include <iostream>  // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main()
{
    int n;    // Declare a variable to store the input number
    cin >> n; // Read the input number from the standard input

    // First part N1 of the pattern
    int currRow = 1; // Initialize the current row counter for the first part
    while (currRow <= (n / 2) + 1)
    {                   // Loop for printing the upper half of the pattern
        int spaces = 1; // Initialize the spaces counter for each row
        while (spaces <= (n / 2) + 1 - currRow)
        {                        // Loop for printing leading spaces
            cout << " ";         // Output a space
            spaces = spaces + 1; // Move to the next space
        }
        int currCol = 1; // Initialize the current column counter for each row
        while (currCol <= (2 * currRow) - 1)
        {                          // Loop for printing '*' characters
            cout << "*";           // Output a '*'
            currCol = currCol + 1; // Move to the next column
        }
        cout << endl;          // Move to the next line after printing the current row
        currRow = currRow + 1; // Move to the next row
    }

    // Second part N2 of the pattern
    currRow = 1; // Reset the current row counter for the second part
    while (currRow <= n / 2)
    {                   // Loop for printing the lower half of the pattern
        int spaces = 1; // Initialize the spaces counter for each row
        while (spaces <= currRow)
        {                        // Loop for printing leading spaces
            cout << " ";         // Output a space
            spaces = spaces + 1; // Move to the next space
        }
        int currCol = 2 * ((n / 2) - currRow + 1) - 1; // Calculate the number of '*' characters for each row
        while (currCol >= 1)
        {                          // Loop for printing '*' characters
            cout << "*";           // Output a '*'
            currCol = currCol - 1; // Move to the next column
        }
        cout << endl;          // Move to the next line after printing the current row
        currRow = currRow + 1; // Move to the next row
    }

    return 0; // Indicate successful completion of the program
}
