
/*
Problem statement
Given a string, determine if it is a palindrome, considering only alphanumeric characters.

Palindrome
A palindrome is a word, number, phrase, or other sequences of characters which read the same backwards and forwards.
Example:
If the input string happens to be, "malayalam" then as we see that this word can be read the same as forward and backwards, it is said to be a valid palindrome.

The expected output for this example will print, 'true'.
From that being said, you are required to return a boolean value from the function that has been asked to implement.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and only line of input contains a string without any leading and trailing spaces. 
All the characters in the string would be in lower case.
Output Format:
The only line of output prints either 'true' or 'false'.
Note:
You are not required to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1 :
abcdcba
Sample Output 1 :
true 
Sample Input 2:
coding
Sample Output 2:
false
*/

/*
  Time complexity: O(N)
  Space complexity: O(1)

  where N is the length of the input string

*/

#include <iostream>
using namespace std;

// Function to calculate the length of a null-terminated character array
int length(char str[])
{
    int count = 0;

    // Loop until the null terminator is encountered
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

// Function to check if a null-terminated character array is a palindrome
bool checkPalindrome(char str[])
{
    // Loop through the first half of the string
    for (int i = 0; i <= length(str) / 2; i++)
    {
        // Compare characters from both ends of the string
        if (str[i] != str[length(str) - 1 - i])
        {
            return false; // If characters don't match, it's not a palindrome
        }
    }
    return true; // If all characters match, it's a palindrome
}

// Main function where the program starts execution
int main()
{
    // Define the size of the character array
    int size = 1e6;
    char str[size]; // Declare a character array

    // Read input from the user and store it in the character array
    cin >> str;

    // Check if the input string is a palindrome and print the result
    cout << (checkPalindrome(str) ? "true" : "false");

    return 0; // Return 0 to indicate successful completion of the program
}
