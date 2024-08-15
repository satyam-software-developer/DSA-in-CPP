
/* Problem statement
Given a string, find and return all the possible permutations of the input string.

Note :
The order of permutations are not important.
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
#include <vector>
#include <string>
using namespace std;

// This function returns all permutations of the given input string
vector<string> permutationOfString(string input)
{
    // Base case: if the input string is empty, return a vector with an empty string
    if (input.length() == 0)
    {
        return {""};
    }

    // Recursive call to get permutations of the substring starting from the second character
    vector<string> smallerOutput = permutationOfString(input.substr(1));

    // Create a vector to hold the final permutations
    vector<string> output;

    // Generate permutations by inserting the first character of the input string
    // into every possible position of each string in smallerOutput
    for (string currentString : smallerOutput)
    {
        for (int j = 0; j <= currentString.length(); j++)
        {
            string newPermutation = currentString.substr(0, j) + input[0] + currentString.substr(j);
            output.push_back(newPermutation);
        }
    }

    return output; // Return the final vector of permutations
}

int main()
{
    string input;
    getline(cin, input); // Read a string input from the user

    vector<string> output = permutationOfString(input); // Get all permutations of the input string

    // Print each permutation in the output vector
    for (string s : output)
    {
        cout << s << endl;
    }

    return 0;
}
