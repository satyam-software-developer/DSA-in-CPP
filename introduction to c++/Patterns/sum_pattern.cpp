
/*Problem statement
Write a program to print triangle of user defined integers sum.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 50
Sample Input 1 :
3
Sample Output 1 :
1=1
1+2=3
1+2+3=6
Sample Input 2 :
 5
Sample Output 2 :
1=1
1+2=3
1+2+3=6
1+2+3+4=10
1+2+3+4+5=15*/

#include <iostream>  // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main()
{
    int n;    // Declare a variable to store the input number 'n'
    cin >> n; // Read the input number 'n' from the standard input

    int currRow = 1; // Initialize the current row counter
    int sum = 0;     // Initialize the sum variable to store the cumulative sum
    while (currRow <= n)
    {                    // Loop to iterate through each row
        sum += currRow;  // Add the current row number to the cumulative sum
        int currCol = 1; // Initialize the current column counter
        while (currCol <= currRow)
        {                    // Loop to iterate through each column in the current row
            cout << currCol; // Print the current column number
            if (currCol == currRow)
            {                // If it's the last column in the row
                cout << '='; // Print the equals sign
            }
            else
            {                // If it's not the last column
                cout << '+'; // Print the plus sign
            }
            currCol = currCol + 1; // Move to the next column
        }
        cout << sum << endl;   // Print the cumulative sum after each row
        currRow = currRow + 1; // Move to the next row
    }

    return 0; // Indicate successful completion of the program
}
