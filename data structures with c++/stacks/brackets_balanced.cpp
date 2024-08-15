
/*
 * Problem statement
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.


Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.
You need to return a boolean value indicating whether the expression is balanced or not.

Note:
The input expression will not contain spaces in between.
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and the only line of input contains a string expression without any spaces in between. Input string will only consists of round brackets.
 Output Format:
The only line of output prints 'true' or 'false'.
Note:
You don't have to print anything explicitly. It has been taken care of. Just implement the function.
Constraints:
1 <= N <= 10^7
 Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1 :
(()()())
Sample Output 1 :
true
Sample Input 2 :
()()(()
Sample Output 2 :
false
Explanation to Sample Input 2:
The initial two pairs of brackets are balanced. But when you see, the opening bracket at the fourth index doesn't have its corresponding closing bracket which makes it imbalanced and in turn, making the whole expression imbalanced. Hence the output prints 'false'.

 */

/*
 * Time complexity: O(N)
 * Space complexity: O(N)
 *
 * where N is the length of the given expression
 */

#include <iostream> // For input and output
#include <stack>    // For the stack data structure

using namespace std;

// Function to check if brackets in the expression are balanced
bool isBalanced(const string &expression)
{
    stack<char> stack; // Create a stack to keep track of opening brackets

    // Iterate over each character in the expression
    for (char ch : expression)
    {
        // If the character is an opening bracket
        if (ch == '(')
        {
            stack.push(ch); // Push it onto the stack
        }
        // If the character is a closing bracket
        else if (ch == ')')
        {
            // Check if the stack is empty (no matching opening bracket)
            if (stack.empty())
            {
                return false; // Unmatched closing bracket, return false
            }
            // Pop the top character from the stack
            char topChar = stack.top();
            stack.pop();
            // Check if the popped character is the matching opening bracket
            if (ch == ')' && topChar == '(')
            {
                continue; // Matching pair found, continue checking
            }
            else
            {
                return false; // Mismatched brackets, return false
            }
        }
    }
    // If the stack is empty after processing the expression, all brackets were matched
    return stack.empty(); // Return true if stack is empty, indicating balanced brackets
}

int main()
{
    string expression; // Declare a string to hold the input expression
    cout << "Enter an expression: ";
    cin >> expression; // Read the expression from user input
    // Print the result of the balance check
    cout << (isBalanced(expression) ? "Balanced" : "Not balanced") << endl;
    return 0;
}
