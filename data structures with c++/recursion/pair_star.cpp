
/*
Problem statement
Given a string S, compute recursively a new string where identical chars
that are adjacent in the original string are separated from each other by a "*".

Detailed explanation ( Input/output format, Notes, Images )
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a
*/

/*
  Time Complexity : O(n)
  Space Complexity : O(n)
  where n is size of input array
*/

#include <iostream>
using namespace std;

// Function to calculate the length of a C-style string
int length(char input[])
{
    int len = 0;
    // Iterate through the array until the null terminator '\0' is encountered
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// Function to insert '*' between adjacent characters if they are the same
void pairStar(char input[], int start)
{
    // Base case: if the current character is null terminator, return
    if (input[start] == '\0')
    {
        return;
    }

    // Recursively call pairStar function for the next character
    pairStar(input, start + 1);

    // Check if the current character is the same as the next character
    if (input[start] == input[start + 1])
    {
        // Calculate the length of the string
        int len = length(input);
        // Shift characters to the right to make space for inserting '*'
        for (int i = len; i >= start + 1; i--)
        {
            input[i + 1] = input[i];
        }
        // Insert '*' after the current character
        input[start + 1] = '*';
    }
}

// Function to initiate the pairStar function
void pairStar(char input[])
{
    pairStar(input, 0);
}

// Main function
int main()
{
    // Declare a character array to store the input string
    char input[100];
    // Read a line of input from the user
    cin.getline(input, 100);
    // Call the pairStar function to insert '*' between adjacent characters if they are the same
    pairStar(input);
    // Print the modified string
    cout << input << endl;
    return 0;
}
