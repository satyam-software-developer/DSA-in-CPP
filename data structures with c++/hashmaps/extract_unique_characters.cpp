
/*Problem statement
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first and only line of input contains a string, that denotes the value of S.
Output format :
The first and only line of output contains the updated string, as described in the task.
Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde */

#include <iostream>      // Include iostream for input and output
#include <unordered_map> // Include unordered_map for HashMap equivalent
#include <string>        // Include string for handling strings

using namespace std;

// Function to take input from the user
string takeInput()
{
    string str;
    getline(cin, str); // Read a line of text from the console
    return str;        // Return the input string
}

// Function to extract unique characters from the input string
string uniqueChar(const string &str)
{
    // If the input string is empty, return an empty string
    if (str.length() == 0)
    {
        return "";
    }

    string ans = "";              // Initialize an empty string to store the result
    unordered_map<char, bool> um; // Create an unordered_map to track characters

    // Iterate over each character in the input string
    for (char currChar : str)
    {
        // If the current character is not already in the unordered_map
        if (um.find(currChar) == um.end())
        {
            um[currChar] = true; // Add the character to the unordered_map
            ans += currChar;     // Append the character to the result string
        }
    }
    return ans; // Return the result string containing unique characters
}

// Main function to execute the program
int main()
{
    string str = takeInput(); // Take input from the user
    cout << uniqueChar(str);  // Print the unique characters in the input string
    return 0;
}
