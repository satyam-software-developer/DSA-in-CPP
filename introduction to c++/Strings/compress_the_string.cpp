
/*
Problem statement
Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.

Example:
If a string has 'x' repeated 5 times, replace this "xxxxx" with "x5".

The string is compressed only when the repeated character count is more than 1.
Note:
Consecutive count of every character in the input string is less than or equal to 9. You are not required to print anything. It has already been taken care of. Just implement the given function and return the compressed string.
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and only line of input contains a string without any leading and trailing spaces.
Output Format:
The output contains the string after compression printed in single line
Constraints:
0 <= N <= 10^6

Where 'N' is the length of the input string.

Time Limit: 1 sec
Sample Input 1:
aaabbccdsa
Sample Output 1:
a3b2c2dsa
Explanation for Sample Output 1:
In the given string 'a' is repeated 3 times, 'b' is repeated 2 times, 'c' is repeated 2 times and 'd', 's' and 'a' and occuring 1 time hence no compression for last 3 characters.
Sample Input 2:
aaabbcddeeeee
Sample Output 2:
a3b2cd2e5
Explanation for Sample Output 2:
In the given string 'a' is repeated 3 times, 'b' is repeated 2 times, 'c' is occuring single time, 'd' is repeating 2 times and 'e' is repeating 5times.
*/

/*
     Time complexity: O(N)
     Space complexity: O(1)

     Where 'N' is the length of the input string.

*/

#include <iostream>
using namespace std;

// Function to get the compressed string from the input string.
string getCompressedString(string &input)
{
    // If the input string is empty, return an empty string.
    if (input.length() == 0)
    {
        return "";
    }

    // Variables to iterate the string and the count of the current character.
    int startIndex = 0; // Start index for iterating the string.
    int endIndex = 0;   // End index for iterating the string.

    // Resultant string.
    string compressedString = "";

    // Iterate all the characters of the string.
    while (startIndex < input.length())
    {
        // Find the end index of the current character sequence.
        while ((endIndex < input.length()) && (input[endIndex] == input[startIndex]))
        {
            endIndex += 1;
        }

        // Calculate the total count of the current character sequence.
        int totalCharCount = endIndex - startIndex;

        // If count is greater than 1, then append count to the string, else only the character.
        if (totalCharCount != 1)
        {
            compressedString += input[startIndex]; // Append the character to the compressed string.
            compressedString += (char)(totalCharCount + '0'); // Append the count of the character.
        }
        else
        {
            compressedString += input[startIndex]; // Append the character only.
        }

        // Update the start index to the end index for the next character sequence.
        startIndex = endIndex;
    }

    return compressedString; // Return the compressed string.
}

// Main function
int main()
{
    int size = 1e6; // Maximum size of the input string.
    string str; // Declare a string variable to store the input string.
    
    // Input the string from the user.
    cin >> str;
    
    // Get the compressed string.
    str = getCompressedString(str);
    
    // Output the compressed string.
    cout << str << endl;
    
    return 0; // Return 0 to indicate successful completion.
}
