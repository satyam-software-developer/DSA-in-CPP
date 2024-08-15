
/*
Problem statement
Reverse the given string word wise. That is, the last word in given string should come at 1st place, 
last second word at 2nd place and so on. 
Individual words should remain as it is.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
String in a single line
Output format :
Word wise reversed string in a single line
Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
Sample Input 2:
Always indent your code
Sample Output 2:
code your indent Always
 */

/*
   Time complexity : O(N)
   Space Complexity : O(1)

   where n is size of input  array

*/

#include <iostream> // Include the necessary header file for input and output operations.
using namespace std;

// Function to reverse a portion of the character array from index 'start' to 'end'.
void reverse(char input[], int start, int end)
{
    // Reverse the characters from the 'start' index to the 'end' index using two-pointer technique.
    while (start < end)
    {
        std::swap(input[start++], input[end--]); // Swap characters at 'start' and 'end' indices.
    }
}

// Function to reverse the words in a string while maintaining the order of words.
void reverseStringWordWise(char input[])
{
    int previousSpaceIndex = -1; // Initialize the index of the previous space character.

    int i = 0; // Initialize loop variable.
    // Iterate through the characters of the input string until reaching the null terminator.
    for (; input[i] != '\0'; i++)
    {
        // Check if the current character is a space character.
        if (input[i] == ' ')
        {
            // Reverse the characters between the previous space index and the current index.
            reverse(input, previousSpaceIndex + 1, i - 1);
            // Update the previous space index to the current index.
            previousSpaceIndex = i;
        }
    }
    // Reverse the characters of the last word in the string.
    reverse(input, previousSpaceIndex + 1, i - 1);
    // Reverse the entire string to obtain the words in reverse order.
    reverse(input, 0, i - 1);
}

// Main function where the program execution begins.
int main()
{
    char input[1000]; // Declare a character array to store the input string.

    // Read a line of input string from the standard input stream.
    cin.getline(input, 1000);

    // Call the function to reverse the words in the input string while maintaining the order.
    reverseStringWordWise(input);

    // Print the modified input string with reversed words.
    cout << input << endl;

    return 0; // Indicate successful completion of the program.
}
