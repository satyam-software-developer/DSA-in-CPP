
/* 
Problem statement
Suppose you have a string, S, made up of only 'a's and 'b's. 
Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
String S
Output format :
'true' or 'false'
Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
abb
Sample Output 1 :
true
Sample Input 2 :
abababa
Sample Output 2 :
false
Explanation for Sample Input 2
In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.
*/

/*
   Time Complexity : O(n)
   Space Complexity : O(n)
   where n is size of input array
*/


#include <iostream>
using namespace std;

// Function to recursively check if the given string follows the pattern 'a' followed by zero or more 'bb's
bool check_ab(char input[], int startIndex) {
    // Base case: If the current character is null terminator, return true
    if (input[startIndex] == '\0') {
        return true;
    }
    // If the current character is not 'a', return false
    if (input[startIndex] != 'a') {
        return false;
    }
    // If there are at least two more characters after the current one
    if (input[startIndex + 1] != '\0' && input[startIndex + 2] != '\0') {
        // If the next two characters are 'bb', recursively call check_ab with startIndex + 3
        if (input[startIndex + 1] == 'b' && input[startIndex + 2] == 'b') {
            return check_ab(input, startIndex + 3);
        }
    }
    // If the above conditions are not met, recursively call check_ab with startIndex + 1
    return check_ab(input, startIndex + 1);
}

// Wrapper function to initiate the recursive check
bool checkAB(char input[]) {
    // Initialize a boolean variable to store the result of the recursive check
    bool ans;
    // Call the recursive function check_ab starting from index 0
    ans = check_ab(input, 0);
    // Return the result
    return ans;
}

// Main function
int main() {
    // Declare a character array to store the input string
    char input[100];
    bool ans;
    // Prompt the user to enter a string
    cin >> input;
    // Call the checkAB function to check if the input string follows the pattern
    ans = checkAB(input);
    // Print 'true' if the pattern is followed, 'false' otherwise
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
