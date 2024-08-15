
/* Problem statement
Given two strings, 'S' and 'T' with lengths 'M' and 'N', find the length of the 'Longest Common Subsequence'.

For a string 'str'(per se) of length K, the subsequences are the strings containing characters in the same relative order as they are present in 'str,' but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K.

Example :
Subsequences of string "abc" are:  ""(empty string), a, b, c, ab, bc, ac, abc.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line of input contains the string 'S' of length 'M'.

The second line of the input contains the string 'T' of length 'N'.
Output format :
Return the length of the Longest Common Subsequence.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
adebc
dcadb
Sample Output 1 :
3
Explanation of the Sample Output 1 :
Both the strings contain a common subsequence 'adb', which is the longest common subsequence with length 3. 
Sample Input 2 :
ab
defg
Sample Output 2 :
0
Explanation of the Sample Output 2 :
The only subsequence that is common to both the given strings is an empty string("") of length 0. */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// Forward declaration of the helper function
int lcsdp(const string &s, const string &t, int i, int j, vector<vector<int>> &dp);

// Function to calculate the length of the Longest Common Subsequence (LCS)
int lcs(const string &s, const string &t)
{
    // Create a 2D vector for memoization, initialized with -1
    vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));

    // Call the helper function with initial indices and the memoization vector
    return lcsdp(s, t, 0, 0, dp);
}

// Helper function to calculate LCS using dynamic programming with memoization
int lcsdp(const string &s, const string &t, int i, int j, vector<vector<int>> &dp)
{
    // Base case: if either string is fully traversed, return 0
    if (s.length() == i || t.length() == j)
    {
        return 0;
    }

    // If characters match, add 1 to the result of the subproblem
    if (s[i] == t[j])
    {
        if (dp[i + 1][j + 1] == -1)
        {
            dp[i + 1][j + 1] = lcsdp(s, t, i + 1, j + 1, dp);
        }
        return 1 + dp[i + 1][j + 1];
    }
    else
    {
        // If characters do not match, solve two subproblems and take the maximum result
        if (dp[i + 1][j] == -1)
        {
            dp[i + 1][j] = lcsdp(s, t, i + 1, j, dp);
        }
        if (dp[i][j + 1] == -1)
        {
            dp[i][j + 1] = lcsdp(s, t, i, j + 1, dp);
        }
        return max(dp[i + 1][j], dp[i][j + 1]);
    }
}

// Main function to read input and call the lcs function
int main()
{
    // Read the first string
    string s;
    getline(cin, s);
    // Read the second string
    string t;
    getline(cin, t);

    // Print the length of the Longest Common Subsequence
    cout << lcs(s, t) << endl;

    return 0;
}
