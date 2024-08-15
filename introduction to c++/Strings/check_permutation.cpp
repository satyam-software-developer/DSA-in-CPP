
/*
Problem statement
For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.

Permutations of each other
Two strings are said to be a permutation of each other when either of the string's characters can be rearranged so that it becomes identical to the other one.

Example: 
str1= "sinrtg" 
str2 = "string"

The character of the first string(str1) can be rearranged to form str2 and hence we can say that the given strings are a permutation of each other.
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains a string without any leading and trailing spaces, representing the first string 'str1'.

The second line of input contains a string without any leading and trailing spaces, representing the second string 'str2'.
Note:
All the characters in the input strings would be in lower case.
Output Format:
The only line of output prints either 'true' or 'false', denoting whether the two strings are a permutation of each other or not.

You are not required to print anything. It has already been taken care of. Just implement the function. 
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
abcde
baedc
Sample Output 1:
true
Sample Input 2:
abc
cbd
Sample Output 2:
false 
*/

/*
    Time complexity: O(N + M)
    Space complexity: O(1)

    where N and M are the lengths of the two input strings.

*/

#include <iostream>
using namespace std;

// Function to check if two strings are permutations of each other
bool isPermutation(char input1[], char input2[]) {
    // Create an array to store the frequency of characters
    int frequency[256];

    // Initialize the frequency array with 0
    for (int i = 0; i < 256; ++i) {
        frequency[i] = 0;
    }

    // Calculate the frequency of characters in the first string
    for (int i = 0; input1[i] != '\0'; ++i) {
        ++frequency[input1[i]];
    }

    // Decrease the frequency of characters in the second string
    for (int i = 0; input2[i] != '\0'; ++i) {
        --frequency[input2[i]];
    }

    // Check if the frequencies are equal for both strings
    for (int i = 0; i < 256; ++i) {
        if (frequency[i] != 0) {
            return false; // If frequencies are not equal, return false
        }
    }

    return true; // If all frequencies are equal, return true (permutation)
}

int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];

    // Input two strings
    cin >> str1 >> str2;

    // Check if str1 and str2 are permutations of each other and print the result
    cout << (isPermutation(str1, str2) ? "true" : "false");

    return 0;
}
