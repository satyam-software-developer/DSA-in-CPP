
/*Problem statement
Print the following pattern for given number of rows.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input :
   5
Sample Output :
 5432*
 543*1
 54*21
 5*321
 *4321*/
#include<iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare a variable to store the value of 'n'
    cin >> n; // Read the value of 'n' from the standard input

    // Outer loop to iterate through each row from 1 to 'n'
    for (int i = 1; i <= n; i++) {
        // Inner loop to iterate through each column from 'n' to 1
        for (int j = n; j >= 1; j--) {
            if (i == j) { // Check if the current row and column indices are equal
                cout << '*'; // If true, print '*' character
            } else {
                cout << j; // Otherwise, print the current column index 'j'
            }
        }
        cout << endl; // Move to the next line after printing each row
    }
    return 0; // Indicate successful completion of the program
}
