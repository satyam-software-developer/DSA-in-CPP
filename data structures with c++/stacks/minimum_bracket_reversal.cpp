
/* Problem statement
For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.

If the expression can't be balanced, return -1.

Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.
Note:
You don't have to print anything. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1:
{{{
Sample Output 1:
-1
Sample Input 2:
{{{{}}
Sample Output 2:
1 */

/*
 * Time complexity: O(N)
 * Space complexity: O(N)
 *
 * where N is the number of brackets
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class MinimumBracketReversal
{
public:
    // Method to count the minimum number of bracket reversals needed to balance a string
    static int countBracketReversals(const string &input)
    {
        int len = input.length(); // Length of the input string

        // If the string is empty, no reversals are needed
        if (len == 0)
        {
            return 0;
        }
        // If the length of the string is odd, it can't be balanced
        if (len % 2 != 0)
        {
            return -1; // Only even number of brackets can be balanced
        }

        stack<char> stk; // Stack to store unbalanced brackets

        // Iterate through each character in the input string
        for (int i = 0; i < len; i++)
        {
            char currentChar = input[i]; // Current character

            if (currentChar == '{')
            {
                // Push opening bracket '{' onto the stack
                stk.push(currentChar);
            }
            else
            {
                // Check if there is a matching opening bracket at the top of the stack
                if (!stk.empty() && stk.top() == '{')
                {
                    stk.pop(); // Pop the matching opening bracket
                }
                else
                {
                    // Push closing bracket '}' onto the stack
                    stk.push(currentChar);
                }
            }
        }

        int count = 0; // Variable to count the number of reversals needed

        // Process remaining unbalanced brackets in the stack
        while (!stk.empty())
        {
            char char1 = stk.top();
            stk.pop(); // Pop the top character
            char char2 = stk.top();
            stk.pop(); // Pop the next character

            /*
             * When char1 = } and char2 = {, then we need to reverse both of them
             * so count will increased by 2
             */
            if (char1 != char2)
            {
                count += 2; // Mismatched brackets, need 2 reversals
            }
            else
            {
                count += 1; // Matching brackets, need 1 reversal
            }
        }

        return count; // Return the total number of reversals needed
    }
};

int main()
{
    string input;
    cin >> input;                                                         // Read the input string of brackets
    cout << MinimumBracketReversal::countBracketReversals(input) << endl; // Calculate and print the minimum reversals

    return 0;
}
