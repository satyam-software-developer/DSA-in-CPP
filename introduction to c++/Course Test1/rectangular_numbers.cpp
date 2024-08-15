
/* Problem statement
Print the following pattern for the given number of rows.

Pattern for N = 4
4444444
4333334
4322234
4321234
4322234
4333334
4444444
Input format : N (Total no. of rows)

Output format : Pattern in N lines

Sample Input :
3
Sample Output :
33333
32223
32123
32223
33333
*/

#include <iostream>  // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std::

// Function to print a specific pattern based on the input number n
void printPatt(int n)
{
    int temp; // Declare a temporary variable to hold values during pattern generation

    // First half of the pattern (top part of the diamond)
    for (int i = 1; i <= n; i++)
    {
        temp = n; // Initialize temp to n at the start of each row

        // Print decreasing values from n down to (n-i+2) on the left side
        for (int j = 1; j < i; j++)
            cout << temp--;

        // Print the middle part of the row with (n-i+1) repeated characters
        for (int k = 1; k <= (2 * n) - (2 * i) + 1; k++)
            cout << n - i + 1;

        // Print increasing values from (n-i+2) back up to n on the right side
        for (int l = 1; l < i; l++)
        {
            cout << ++temp;
        }

        cout << endl; // Move to the next line after completing the current row
    }

    // Second half of the pattern (bottom part of the diamond)
    for (int i = n - 1; i >= 1; i--)
    {
        temp = n; // Re-initialize temp to n for the next row

        // Print decreasing values from n down to (n-i+2) on the left side
        for (int j = 1; j < i; j++)
            cout << temp--;

        // Print the middle part of the row with (n-i+1) repeated characters
        for (int k = 1; k <= (2 * n) - (2 * i) + 1; k++)
            cout << n - i + 1;

        // Print increasing values from (n-i+2) back up to n on the right side
        for (int l = 1; l < i; l++)
            cout << ++temp;

        cout << endl; // Move to the next line after completing the current row
    }
}

int main()
{
    int n;                      // Declare a variable to store the user input
    cout << "Enter a number: "; // Prompt the user to enter a number
    cin >> n;                   // Read the user's input

    printPatt(n); // Call the function to print the pattern based on the input

    return 0; // Return 0 to indicate successful program execution
}
