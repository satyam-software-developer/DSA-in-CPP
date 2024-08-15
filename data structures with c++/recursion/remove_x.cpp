
/*
Problem statement
Given a string, compute recursively a new string where all 'x' chars have been removed.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S.
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:
*/

/*
   Time Complexity : O(n^2)
   Space Complexity : O(n^2)

   where n is size of input array

*/
#include <iostream>
using namespace std;

// Function to calculate the length of a null-terminated character array.
int length(char input[])
{
    int len = 0;

    // Loop until the null character '\0' is encountered.
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// Recursive function to remove all occurrences of 'x' from a character array starting from a given index 'start'.
void removeX(char input[], int start)
{
    // Base case: if the current character is the null character '\0', return.
    if (input[start] == '\0')
    {
        return;
    }

    // Recursive call: move to the next character.
    removeX(input, start + 1);

    // If the current character is 'x', shift all characters after it to the left.
    if (input[start] == 'x')
    {
        int len = length(input);
        int i;

        for (i = start + 1; i < len; i++)
        {
            input[i - 1] = input[i];
        }
        // Add null character at the end to terminate the string.
        input[i - 1] = '\0';
    }
}

// Function to call the removeX function starting from the beginning of the character array.
void removeX(char input[])
{
    removeX(input, 0);
}

// Main function to take input and call the removeX function.
int main()
{
    char input[100];
    // Read a line of input from the user.
    cin.getline(input, 100);
    // Call the removeX function to remove all occurrences of 'x'.
    removeX(input);
    // Print the modified input.
    cout << input << endl;
    return 0;
}
