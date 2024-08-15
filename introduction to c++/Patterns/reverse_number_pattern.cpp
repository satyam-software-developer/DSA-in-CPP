
/*Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 4
1
21
321
4321
Detailed explanation ( Input/output format, Notes, Images )
Constraints
0 <= N <= 50
Sample Input 1:
5
Sample Output 1:
1
21
321
4321
54321
Sample Input 2:
6
Sample Output 2:
1
21
321
4321
54321
654321*/
#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare a variable to store the input number 'n'
    cin >> n; // Read the input number 'n' from the standard input

    int currRow = 1; // Initialize the current row counter
    while (currRow <= n) { // Loop to iterate through each row
        int currCol = currRow; // Initialize the current column counter with the value of the current row
        while (currCol >= 1) { // Loop to print numbers in decreasing order for the current row
            cout << currCol; // Print the value of the current column
            currCol = currCol - 1; // Decrement the current column counter
        }
        cout << endl; // Move to the next line after printing all numbers in the current row
        currRow = currRow + 1; // Move to the next row
    }

    return 0; // Indicate successful completion of the program
}
