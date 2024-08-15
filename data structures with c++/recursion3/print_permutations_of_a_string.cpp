
/* Problem statement
Given a string, find and print all the possible permutations of the input string.

Note :
The order of permutations are not important. Just print them in different lines.
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba */

#include <iostream>
#include <string>

using namespace std;

// Helper method to generate and print all permutations of the input string
void permutationsHelper(string input, string output)
{
    // Base case: if the input string is empty, print the output string
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    // Loop through each character in the input string
    for (size_t i = 0; i < input.length(); i++)
    {
        // Recursively call the helper method with the remaining characters in the input string
        // and the current character added to the output string
        permutationsHelper(input.substr(0, i) + input.substr(i + 1), output + input[i]);
    }
}

// Method to initiate the permutation process
void permutations(string input)
{
    // Call the helper method with the input string and an empty output string
    permutationsHelper(input, "");
}

// Main method to take input from the user and print all permutations
int main()
{
    string input;
    getline(cin, input); // Read a string input from the user
    permutations(input); // Call the permutations method to print all permutations of the input string
    return 0;
}
