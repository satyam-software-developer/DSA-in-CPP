
/*Problem statement
Print the following pattern for the given N number of rows.

Pattern for N = 4
1
22
333
4444
Detailed explanation ( Input/output format, Notes, Images )
Constraints
0 <= N <= 50
Sample Input 1:
5
Sample Output 1:
1
22
333
4444
55555
Sample Input 2:
6
Sample Output 2:
1
22
333
4444
55555
666666*/
#include <iostream>  // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main()
{
    int n;    // Declare a variable to store the input number 'n'
    cin >> n; // Read the input number 'n' from the standard input

    int currRow = 1; // Initialize the current row counter
    while (currRow <= n)
    {                       // Loop to iterate through each row
        int currColumn = 1; // Initialize the current column counter
        while (currColumn <= currRow)
        {                    // Loop to print numbers in the current row
            cout << currRow; // Print the value of the current row
            currColumn++;    // Move to the next column
        }
        cout << endl; // Move to the next line after printing each row
        currRow++;    // Move to the next row
    }

    return 0; // Indicate successful completion of the program
}
