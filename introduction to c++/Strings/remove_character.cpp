
/*
Problem statement
For a given a string(str) and a character X, write a function to remove all the occurrences of X from the given string.

The input string will remain unchanged if the given character(X) doesn't exist in the input string.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains a string without any leading and trailing spaces.

The second line of input contains a character(X) without any leading and trailing spaces.
Output Format:
The only line of output prints the updated string. 
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
aabccbaa
a
Sample Output 1:
bccb
Sample Input 2:
xxyyzxx
y
Sample Output 2:
xxzxx
*/

/*
  Time complexity: O(N)
  Space complexity: O(1)

  Where N is the length of the input string

*/

#include <iostream>
#include <cstring>
using namespace std;

// Function to remove all occurrences of a character 'c' from the input string 'input'
void removeAllOccurrencesOfChar(char input[], char c)
{
    int trim = 0; // Variable to keep track of the current position for non-'c' characters
    int i = 0;    // Loop variable to iterate through the input string
    int len = strlen(input); // Calculate the length of the input string

    // Loop through the entire input string
    while (i < len)
    {
        // Check if the current character is not equal to 'c'
        if (input[i] != c)
        {
            // Swap the current character with the character at 'trim' position
            swap(input[i], input[trim]);
            // Move to the next character in the input string
            i++;
            // Move the 'trim' position to the next position
            trim++;
        }
        else
        {
            // If the current character is 'c', replace it with null character '\0'
            input[i] = '\0';
            // Move to the next character in the input string
            i++;
        }
    }
}

int main()
{
    // Define the maximum size of the input string
    int size = 1e6;
    // Declare an array to store the input string
    char str[size];
    // Read a line of input from the user and store it in 'str'
    cin.getline(str, size);
    // Declare a variable to store the character to be removed
    char c;
    // Read the character to be removed from the user
    cin >> c;
    // Call the function to remove all occurrences of 'c' from the input string 'str'
    removeAllOccurrencesOfChar(str, c);
    // Output the modified string after removing all occurrences of 'c'
    cout << str;

    return 0;
}
