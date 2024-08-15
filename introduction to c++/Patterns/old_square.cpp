
/*Problem statement
Write a program to print the pattern for the given N number of rows.

For N = 4

1357
3571
5713
7135
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 50
Sample Input 1 :
3
Sample Output 1 :
135
351
513
Sample Input 2 :
 5
Sample Output 2 :
13579
35791
57913
79135
91357
*/
#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare a variable to store the input number 'n'
    cin >> n; // Read the input number 'n' from the standard input

    int currRow = 1; // Initialize the current row counter
    while (currRow <= n) { // Loop to iterate through each row
        int currColVal = (2 * currRow) - 1; // Calculate the initial value for the current column based on the current row
        int currCol = 1; // Initialize the current column counter
        while (currCol <= n) { // Loop to print the columns in the current row
            cout << currColVal; // Print the current column value
            currColVal = currColVal + 2; // Increment the current column value by 2
            if (currColVal > (2 * n) - 1) { // Check if the current column value exceeds the maximum allowed value
                currColVal = 1; // Reset the current column value to 1 if it exceeds the maximum allowed value
            }
            currCol = currCol + 1; // Move to the next column
        }
        cout << endl; // Move to the next line after printing all columns in the current row
        currRow = currRow + 1; // Move to the next row
    }

    return 0; // Indicate successful completion of the program
}
