
/*
 * Problem statement
For a given expression in the form of a string, find if there exist any redundant brackets or not. It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.

A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.

Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.
Note:
You will not get a partial score for this problem. You will get marks only if all the test cases are passed.
Return "false" if no brackets are present in the input.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first and the only line of input contains a string expression, without any spaces in between.
Output Format :
The first and the only line of output will print either 'true' or 'false'(without the quotes) denoting whether the input expression contains redundant brackets or not.
Note:
You are not required to print the expected result. It has already been taken care of.
Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1 second
Sample Input 1:
a+(b)+c
Sample Output 1:
true
Explanation:
The expression can be reduced to a+b+c. Hence, the brackets are redundant.
Sample Input 2:
(a+b)
Sample Output 2:
false
 */

/*
 * Time complexity: O(N)
 * Space complexity: O(N)
 *
 * where N is the length of the input expression
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Utility function to determine if a character is an operator
bool isOperator(char ch)
{
    // Return true if the character is one of the four operators
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to check if the given expression contains redundant brackets
bool checkRedundantBrackets(const string &expression)
{
    // Stack to keep track of characters in the expression
    stack<char> stk;

    // Iterate through each character in the expression
    for (char currentChar : expression)
    {
        // If the character is an opening bracket or an operator, push it onto the stack
        if (currentChar == '(' || isOperator(currentChar))
        {
            stk.push(currentChar);
        }
        // If the character is a closing bracket, check for redundancy
        else if (currentChar == ')')
        {
            bool hasOperator = false;

            // Pop elements from the stack until an opening bracket is found
            while (!stk.empty() && stk.top() != '(')
            {
                stk.pop();
                hasOperator = true; // Set the flag if an operator is found
            }

            // If no operator is found between the brackets, they are redundant
            if (!hasOperator)
            {
                return true;
            }

            // Pop the opening bracket from the stack
            if (!stk.empty())
            {
                stk.pop();
            }
        }
    }
    // If the stack has no redundant brackets, return false
    return false;
}

// Main function to test the checkRedundantBrackets function
int main()
{
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");

    return 0;
}
