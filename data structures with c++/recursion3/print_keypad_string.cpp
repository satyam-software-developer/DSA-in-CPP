
/* Problem statement
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

Note :
The order of strings are not important. Just print different strings in new lines.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PrintKeypadString
{
public:
    // This method returns a vector of strings corresponding to the characters on the given single-digit key on a keypad
    static vector<string> singleDigit(int n)
    {
        // Exit the program if the input is less than or equal to 1 or greater than 10
        if (n <= 1 || n > 10)
        {
            exit(0);
        }

        // Return the corresponding characters for each digit from 2 to 9
        if (n == 2)
        {
            return {"a", "b", "c"};
        }
        else if (n == 3)
        {
            return {"d", "e", "f"};
        }
        else if (n == 4)
        {
            return {"g", "h", "i"};
        }
        else if (n == 5)
        {
            return {"j", "k", "l"};
        }
        else if (n == 6)
        {
            return {"m", "n", "o"};
        }
        else if (n == 7)
        {
            return {"p", "q", "r", "s"};
        }
        else if (n == 8)
        {
            return {"t", "u", "v"};
        }
        else
        {
            return {"w", "x", "y", "z"};
        }
    }

    // This method prints all possible strings that can be made using the digits of the input number
    static void printKeypad(int input, string output)
    {
        // Base case: if the input number is 0, print the accumulated output string
        if (input == 0)
        {
            cout << output << endl;
            return;
        }

        // Get the characters for the last digit of the input number
        vector<string> singleDigitOutput = singleDigit(input % 10);

        // Recursively call the function for the remaining digits and accumulate the results
        for (int i = 0; i < singleDigitOutput.size(); i++)
        {
            printKeypad(input / 10, singleDigitOutput[i] + output);
        }
    }

    // Overloaded method to start the recursion with an empty output string
    static void printKeypad(int input)
    {
        printKeypad(input, "");
    }
};

int main()
{
    // Create a Scanner object to take input from the user
    int input;
    cin >> input; // Read an integer input from the user

    // Print all possible strings that can be made using the digits of the input number
    PrintKeypadString::printKeypad(input);

    return 0;
}
