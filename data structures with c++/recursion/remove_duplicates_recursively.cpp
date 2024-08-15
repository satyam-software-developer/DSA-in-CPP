
/*
Problem statement
Given a string S, remove consecutive duplicates from it recursively.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
*/

/*
  Time Complexity : O(n)
  Time Complexity : O(n)

  where n is size of input array

*/

#include <iostream>
using namespace std;

// Recursive function to remove consecutive duplicate characters from a C-style string.
void remove(char *input, int newIndex, int index)
{
    // Base case: if the current character is the null character '\0',
    // copy the last non-duplicate character to the new index and terminate the string.
    if (input[index] == '\0')
    {
        input[newIndex] = input[index - 1];
        input[newIndex + 1] = '\0';
        return;
    }

    // If the current character is the same as the previous one, skip it and move to the next character.
    if (input[index] == input[index - 1])
    {
        remove(input, newIndex, index + 1);
        return;
    }
    else
    {
        // If the current character is different from the previous one, copy it to the new index.
        input[newIndex] = input[index - 1];
    }

    // Recursive call: move to the next character and continue removing consecutive duplicates.
    remove(input, newIndex + 1, index + 1);
}

// Function to call the remove function with initial parameters.
void removeConsecutiveDuplicates(char *input)
{
    remove(input, 0, 1);
}

// Main function to take input and call the removeConsecutiveDuplicates function.
int main()
{
    char s[100000];
    // Read input from the user.
    cin >> s;
    // Call the removeConsecutiveDuplicates function to remove consecutive duplicates.
    removeConsecutiveDuplicates(s);
    // Print the modified string.
    cout << s << endl;
    return 0;
}
