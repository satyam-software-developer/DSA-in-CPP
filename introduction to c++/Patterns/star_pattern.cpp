
/*Problem statement
Print the following pattern

Pattern for N = 4

Hint
As taught in the video, you just have to modify the code so that instead of printing numbers, it should output stars ('*').
The dots represent spaces.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 50
Sample Input 1 :
3
Sample Output 1 :
   *
  ***
 *****
Sample Input 2 :
4
Sample Output 2 :
    *
   ***
  *****
 ********/
#include <iostream>  // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main()
{
    int n;    // Declare a variable to store the input number 'n'
    cin >> n; // Read the input number 'n' from the standard input

    int currRow = 1; // Initialize the current row counter
    while (currRow <= n)
    {                   // Loop to iterate through each row
        int spaces = 1; // Initialize the spaces counter for leading spaces in each row
        while (spaces <= n - currRow)
        {                        // Loop to print leading spaces based on the current row
            cout << " ";         // Print a space
            spaces = spaces + 1; // Move to the next space position
        }
        int star = 1; // Initialize the star counter for printing stars in each row
        while (star <= 2 * currRow - 1)
        {                    // Loop to print stars in each row based on the current row number
            cout << '*';     // Print a star
            star = star + 1; // Move to the next star position
        }
        cout << endl;          // Move to the next line after printing the stars of the current row
        currRow = currRow + 1; // Move to the next row
    }

    return 0; // Indicate successful completion of the program
}
