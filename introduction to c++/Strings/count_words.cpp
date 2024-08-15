
/*
Problem statement
For a given input string(str), find and return the total number of words present in it.

It is assumed that two words will have only a single space in between. 
Also, there wouldn't be any leading and trailing spaces in the given input string.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and only line of input contains a string without any leading and trailing spaces.
Output Format:
The only line of output prints an integer value denoting the tool number of words present in the string.
Note:
You are not required to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 sec
Sample Input 1:
Coding Ninjas!
Sample Output 1:
2
Sample Input 2:
this is a sample string
Sample Output 2:
5
*/
/*
   Time complexity: O(N)
   Space complexity: O(1)

   where N is the length of the input string
*/

#include <iostream>
using namespace std;

// Function to count the number of words in a string
int countWords(string str)
{
    // If the string is empty, return 0
    if (str.length() == 0)
    {
        return 0;
    }

    // Initialize a variable to count spaces
    int spaces = 0;

    // Iterate through the characters of the string
    for (int i = 0; i < str.length(); ++i)
    {
        // If a space character is encountered, increment the spaces count
        if (str[i] == ' ')
        {
            ++spaces;
        }
    }

    // Return the count of spaces plus 1, which represents the number of words
    return spaces + 1;
}

// Main function where the program starts execution
int main()
{
    string str;

    // Read the entire line including spaces from the user
    getline(cin, str);

    // Call the countWords function to count the number of words in the input string
    cout << countWords(str);

    // Indicate successful termination of the program
    return 0;
}
