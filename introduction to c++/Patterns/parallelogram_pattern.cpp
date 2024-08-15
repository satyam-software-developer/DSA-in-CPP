
/*Problem statement
Write a program to print parallelogram pattern for the given N number of rows.

For N = 4

The dots represent spaces.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 50
Sample Input 1 :
3
Sample Output 1 :
***
 ***
  ***
Sample Input 2 :
5
Sample Output 2 :
*****
 *****
  *****
   *****
    *****
*/
#include <iostream>  // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main()
{
    int n;    // Declare a variable to store the input number 'n'
    cin >> n; // Read the input number 'n' from the standard input

    int currRow = 1; // Initialize the current row counter
    while (currRow <= n)
    {                             // Loop to iterate through each row
        int spaces = currRow - 1; // Calculate the number of leading spaces for the current row
        while (spaces > 0)
        {                        // Loop to print leading spaces for the current row
            cout << " ";         // Print a space character
            spaces = spaces - 1; // Decrement the spaces counter
        }
        int currCol = 1; // Initialize the current column counter
        while (currCol <= n)
        {                          // Loop to print '*' characters for the current row
            cout << '*';           // Print a '*' character
            currCol = currCol + 1; // Move to the next column
        }
        cout << endl;          // Move to the next line after printing all '*' characters in the current row
        currRow = currRow + 1; // Move to the next row
    }

    return 0; // Indicate successful completion of the program
}
