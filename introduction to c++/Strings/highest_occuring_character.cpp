
/*
Problem statement
For a given a string(str), find and return the highest occurring character.

Example:
Input String: "abcdeapapqarr"
Expected Output: 'a'
Since 'a' has appeared four times in the string which happens to be the highest frequency character, the answer would be 'a'.
If there are two characters in the input string with the same frequency, return the character which comes first.

Consider:
Assume all the characters in the given string to be in lowercase always.
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and only line of input contains a string without any leading and trailing spaces.
Output Format:
The only line of output prints the updated string. 
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
abdefgbabfba
Sample Output 1:
b
Sample Input 2:
xy
Sample Output 2:
x
*/

/*
    Time complexity: O(N)
    Space complexity: O(1)

    where N is the length of the input string

*/


#include<iostream>
#include <cstring> // Include the header file for C string operations
using namespace std;

// Function to find the highest occurring character in the input string
char highestOccurringChar(char input[])
{
    int arr[26] = {0}; // Array to store the count of occurrences of each character (assuming lowercase letters only)
    int maxFreq = 0; // Variable to store the maximum frequency of any character

    // Loop through the input string to count the occurrences of each character
    for (int i = 0; input[i] != '\0'; i++)
    {
        arr[int(input[i]) - 'a'] += 1; // Increment the count of the corresponding character
        maxFreq = max(maxFreq, arr[int(input[i]) - 'a']); // Update the maximum frequency
    }
    char ans; // Variable to store the highest occurring character

    // Loop through the input string to find the first character with the maximum frequency
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (arr[int(input[i]) - 'a'] == maxFreq) // If the current character has the maximum frequency
        {
            ans = input[i]; // Store the character as the highest occurring character
            break; // Break the loop after finding the highest occurring character
        }
    }
    return ans; // Return the highest occurring character
}

int main(){
    int size = 1e6; // Maximum size of the input string
    char str[size]; // Declare a character array to store the input string
    cin >> str; // Read the input string from the standard input
    cout << highestOccurringChar(str); // Call the function to find the highest occurring character and print it
    return 0;
}
