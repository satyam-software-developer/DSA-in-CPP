
/*Problem statement
Write a program to print N number of rows for Half Diamond pattern using stars and numbers

Note : There are no spaces between the characters in a single line.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 50
Sample Input 1 :
3
Sample Output 1 :
*
*1*
*121*
*12321*
*121*
*1*
*
Sample Input 2 :
 5
Sample Output 2 :
*
*1*
*121*
*12321*
*1234321*
*123454321*
*1234321*
*12321*
*121*
*1*
**/

#include <iostream>  // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main()
{
    int n;    // Declare a variable to store the input number
    cin >> n; // Read the input number from the standard input

    cout << '*' << endl; // Print the first row of the pattern which consists of a single '*'

    // Printing the upper half of the pattern
    int currRow = 1; // Initialize the current row counter for the upper half
    while (currRow <= n)
    {                       // Loop for printing the upper half of the pattern
        cout << '*';        // Print the left '*' character of the row
        int currColVal = 1; // Initialize the current column value for the numbers
        // Loop for printing the numbers in increasing order
        while (currColVal <= currRow)
        {
            cout << currColVal;          // Print the current column value
            currColVal = currColVal + 1; // Move to the next column value
        }
        currColVal = currColVal - 2; // Adjust the current column value for the descending order
        // Loop for printing the numbers in descending order
        while (currColVal >= 1)
        {
            cout << currColVal;          // Print the current column value
            currColVal = currColVal - 1; // Move to the next column value
        }
        cout << '*' << endl;   // Print the right '*' character of the row and move to the next line
        currRow = currRow + 1; // Move to the next row
    }

    // Printing the lower half of the pattern
    currRow = 1; // Reset the current row counter for the lower half
    while (currRow <= n - 1)
    {                       // Loop for printing the lower half of the pattern
        cout << '*';        // Print the left '*' character of the row
        int currColVal = 1; // Initialize the current column value for the numbers
        // Loop for printing the numbers in increasing order
        while (currColVal <= n - currRow)
        {
            cout << currColVal;          // Print the current column value
            currColVal = currColVal + 1; // Move to the next column value
        }
        currColVal = currColVal - 2; // Adjust the current column value for the descending order
        // Loop for printing the numbers in descending order
        while (currColVal >= 1)
        {
            cout << currColVal;          // Print the current column value
            currColVal = currColVal - 1; // Move to the next column value
        }
        cout << '*' << endl;   // Print the right '*' character of the row and move to the next line
        currRow = currRow + 1; // Move to the next row
    }
    cout << '*'; // Print the last row which consists of a single '*'

    return 0; // Indicate successful completion of the program
}
