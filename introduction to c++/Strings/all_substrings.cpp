/*
Problem statement
For a given input string(str), write a function to print all the possible substrings.

Substring
A substring is a contiguous sequence of characters within a string. 
Example: "cod" is a substring of "coding". Whereas, "cdng" is not as the characters taken are not contiguous
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.
Output Format:
Print the total number of substrings possible, where every substring is printed on a single line and hence the total number of output lines will be equal to the total number of substrings.
Note:
The order in which the substrings are printed, does not matter.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
abc
Sample Output 1:
a 
ab 
abc 
b 
bc 
c 
 Sample Input 2:
co
Sample Output 2:
c 
co 
o
*/


/*
   Time complexity: O(N^3)
   Space complexity: O(1)

   where N is the length of the input string
*/

#include <iostream>
#include<cstring> // Include the necessary header file for C-style string functions.
using namespace std;

// Function to print all possible substrings of the given input string.
void printSubstrings(char input[])
{
    int k = 1; // Initialize the length of substrings to be considered.

    // Loop until k reaches the length of the input string.
    while (k <= strlen(input))
    {
        // Iterate through the input string to find substrings of length k.
        for (int i = 0; i <= strlen(input) - k; i++)
        {
            // Print substrings of length k starting from index i.
            for (int j = i; j < i + k; j++)
            {
                cout << input[j]; // Print the character at index j.
            }
            cout << endl; // Move to the next line after printing each substring.
        }
        k++; // Increment the length of substrings to be considered in the next iteration.
    }
}

// Main function where the program execution begins.
int main()
{
    int size = 1e6; // Define the maximum size of the input string.
    char str[size]; // Declare a character array to store the input string.

    // Prompt the user to input a string and store it in the 'str' array.
    cin >> str;

    // Call the function to print all possible substrings of the input string.
    printSubstrings(str);

    return 0; // Indicate successful completion of the program.
}
