/* Problem statement
Given a String s, consisting of non negative integers and +,- operators as well as brackets ( and ).

Your task is to solve the given string and print the output.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
First and only line contains the string s.
Output Format:
Print the result of the given string.
Constraints:
1 <= String length <= 20000
Sample Input 1:
(1+2)
Sample Output 1:
3
Sample Input 2:
(1+(4+5+2)-3)+(6+8)
Sample Output 2:
23 */

#include <iostream> // Include the input-output stream library
#include <stack>    // Include the stack library
#include <string>   // Include the string library
#include <cmath>    // Include the cmath library for mathematical functions like pow

using namespace std; // Use the standard namespace

// Function to evaluate an expression from a stack.
// This function assumes that the expression is in the correct order.
int evaluateExpr(stack<char> &stack)
{
    int res = 0; // Initialize the result to 0.

    // If the stack is not empty, pop the top element to start the calculation.
    if (!stack.empty())
    {
        res = stack.top() - '0'; // The first element is an integer, so subtract '0' to convert from char to int.
        stack.pop();             // Remove the top element.
    }

    // Evaluate the expression until we find a closing parenthesis ')'.
    while (!stack.empty() && stack.top() != ')')
    {
        char sign = stack.top(); // Pop the sign (either '+' or '-').
        stack.pop();             // Remove the sign from the stack.

        // Depending on the sign, add or subtract the next integer.
        if (sign == '+')
        {
            res += (stack.top() - '0');
        }
        else
        {
            res -= (stack.top() - '0');
        }
        stack.pop(); // Remove the operand from the stack.
    }
    return res; // Return the evaluated result.
}

// Function to calculate the value of a mathematical expression given as a string.
int calculate(const string &s)
{
    int operand = 0;   // Initialize the current operand (number) to 0.
    int n = 0;         // Initialize a counter to track the number of digits in the current operand.
    stack<char> stack; // Create a stack to store the operands and operators.

    // Iterate over the string from the end to the beginning.
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char ch = s[i]; // Get the current character in the string.

        // If the character is a digit, form the operand in reverse order.
        if (isdigit(ch))
        {
            operand = pow(10, n) * (ch - '0') + operand;
            n += 1; // Increment the counter to move to the next digit position.
        }
        else if (ch != ' ')
        { // If the character is not a space,
            if (n != 0)
            {
                // Push the formed operand onto the stack when a non-digit is encountered.
                stack.push(operand + '0');
                n = 0; // Reset the operand and counter for the next number.
                operand = 0;
            }
            if (ch == '(')
            {
                // If a '(' is encountered, evaluate the expression inside the parentheses.
                int res = evaluateExpr(stack);
                stack.pop(); // Remove the corresponding ')' from the stack.

                // Push the result of the evaluated sub-expression back onto the stack.
                stack.push(res + '0');
            }
            else
            {
                // For other non-digit characters (like operators), just push them onto the stack.
                stack.push(ch);
            }
        }
    }

    // If there is any remaining operand after the loop, push it onto the stack.
    if (n != 0)
    {
        stack.push(operand + '0');
    }

    // Evaluate any remaining elements in the stack.
    return evaluateExpr(stack);
}

int main()
{
    string str;                     // Declare a string to hold the input expression.
    cin >> str;                     // Read the input string (expression).
    cout << calculate(str) << endl; // Calculate and print the result.
    return 0;
}
