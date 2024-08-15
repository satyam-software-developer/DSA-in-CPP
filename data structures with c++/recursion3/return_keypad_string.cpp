
/*Problem statement
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.

Return empty string for numbers 0 and 1.

Note :
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
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
#include <vector>
#include <string>

using namespace std;

// This function returns a vector of strings corresponding to the characters on the given single-digit key on a keypad
vector<string> singleDigit(int n)
{
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

// This function returns all possible strings that can be made using the digits of the input number
vector<string> keypad(int n)
{
    // Base case: if the input number is 0, return a vector with an empty string
    if (n == 0)
    {
        return {""};
    }

    // Recursive case: get the combinations for the smaller number (n / 10)
    vector<string> smallerNumberArray = keypad(n / 10);

    // Get the characters for the last digit of the input number
    vector<string> singleDigitOutput = singleDigit(n % 10);

    // Calculate the total number of combinations and create the output vector
    vector<string> output(singleDigitOutput.size() * smallerNumberArray.size());
    int k = 0; // Index for the output vector

    // Combine each character of the singleDigitOutput with each string in smallerNumberArray
    for (const string &digit : singleDigitOutput)
    {
        for (const string &smaller : smallerNumberArray)
        {
            output[k] = smaller + digit;
            k++;
        }
    }

    return output; // Return the final vector of combinations
}

int main()
{
    int input;
    cout << "Enter a number: ";
    cin >> input;

    // Get all possible strings that can be made using the digits of the input number
    vector<string> output = keypad(input);

    // Print each string in the output vector
    for (const string &str : output)
    {
        cout << str << endl;
    }

    return 0;
}
