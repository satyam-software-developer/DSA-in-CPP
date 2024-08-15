
/*Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 4
4444
333
22
1
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 50
Sample Input 1:
5
Sample Output 1:
55555 
4444
333
22
1
Sample Input 2:
6
Sample Output 2:
666666
55555 
4444
333
22
1*/

#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare a variable to store the input number
    cin >> n; // Read the input number from the standard input

    int currRow = 1; // Initialize the current row counter
    while (currRow <= n) { // Loop to print each row of the pattern
        int currCol = n - currRow + 1; // Initialize the current column counter for the current row
        while (currCol >= 1) { // Loop to print the numbers in the current row
            cout << n - currRow + 1; // Print the value corresponding to the current row
            currCol = currCol - 1; // Move to the next column
        }
        cout << endl; // Move to the next line after printing numbers for the current row
        currRow = currRow + 1; // Move to the next row
    }

    return 0; // Indicate successful completion of the program
}
