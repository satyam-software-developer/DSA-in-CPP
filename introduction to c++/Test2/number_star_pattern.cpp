
/*Problem statement
Print the following pattern for given number of rows.

Input format :

Line 1 : N (Total number of rows)

Sample Input :
   5
Sample Output :
1234554321
1234**4321
123****321
12******21
1********1*/

#include <iostream>  // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main()
{
    int n;
    cin >> n; // Read the value of 'n' from the standard input

    int numStars = 0; // Variable to keep track of the number of stars in each row
    int row = 1;      // Variable to keep track of the current row number

    // Loop to iterate through each row
    while (row <= n)
    {
        int value = 1; // Variable to keep track of the numeric value to be printed

        // Loop to print the first part of the row (numbers in ascending order)
        while (value <= n - row + 1)
        {
            cout << value;     // Print the current numeric value
            value = value + 1; // Move to the next numeric value
        }

        // Loop to print the middle part of the row (stars)
        int stars = 1;
        while (stars <= numStars)
        {
            cout << '*';       // Print the star character
            stars = stars + 1; // Move to the next star
        }

        // Reset the 'value' variable to print the second part of the row (numbers in descending order)
        value = n - row + 1;

        // Loop to print the second part of the row (numbers in descending order)
        while (value >= 1)
        {
            cout << value;     // Print the current numeric value
            value = value - 1; // Move to the next numeric value
        }

        cout << endl;            // Move to the next line after printing the current row
        row = row + 1;           // Move to the next row
        numStars = numStars + 2; // Increment the number of stars for the next row
    }

    return 0; // Indicate successful completion of the program
}
