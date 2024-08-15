
/* 
Problem statement
For a given string(str), remove all the consecutive duplicate characters.

Example:
Input String: "aaaa"
Expected Output: "a"

Input String: "aabbbcc"
Expected Output: "abc"
 Input Format:
The first and only line of input contains a string without any leading and trailing spaces. 
All the characters in the string would be in lower case.
Output Format:
The only line of output prints the updated string.
Note:
You are not required to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
aabccbaa
Sample Output 1:
abcba
Sample Input 2:
xxyyzxx
Sample Output 2:
xyzx
*/
/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where N is the length of the input string

*/

#include <iostream>
using namespace std;

// Function to remove consecutive duplicates from a character array
void removeConsecutiveDuplicates(char input[]) {
    // Iterate through the input array starting from the second character
    for (int i = 1; input[i] != '\0'; i++) {
        // If the current character is the same as the previous one, mark the previous character as space
        if (input[i] == input[i - 1]) {
            input[i - 1] = ' ';
        }
    }
    
    int space = 0; // Initialize a variable to keep track of space position
    
    // Iterate through the input array again to shift non-space characters to the beginning of the array
    for (int i = 0; input[i] != '\0'; i++) {
        // If the current character is not a space, swap it with the character at the 'space' position
        if (input[i] != ' ') {
            char tmp = input[i];
            input[i] = input[space];
            input[space] = tmp;
            space++; // Increment space to maintain the position of the next non-space character
        }
    }
}

// Main function
int main() {
    int size = 1e6; // Maximum size of the character array
    char str[size]; // Declare a character array to store input string
    cin >> str; // Read input string from the standard input
    
    // Call the removeConsecutiveDuplicates function to remove consecutive duplicates
    removeConsecutiveDuplicates(str);
    
    // Print the modified string after removing consecutive duplicates
    cout << str;
    
    return 0; // Indicate successful program execution
}
