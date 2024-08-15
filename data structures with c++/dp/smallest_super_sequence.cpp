
/* Problem statement
 Given two strings S and T with lengths M and N. Find and return the length of their shortest 'Super Sequence'.

 The shortest 'Super Sequence' of two strings is defined as the smallest string possible that will have both the given strings as its subsequences.

Note :
If the two strings do not have any common characters, then return the sum of the lengths of the two strings. 
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first only line of input contains a string, that denotes the value of string S. The following line contains a string, that denotes the value of string T.
Output Format:
Length of the smallest super-sequence of given two strings. 
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
ab
ac
Sample Output 1 :
3
Explanation of Sample Output 1 :
Their smallest super sequence can be "abc" which has length = 3.
Sample Input 2 :
pqqrpt
qerepct
Sample Output 2 :
9 */

/*
 * Time Complexity: O(n*m)
 * Space Complexity: O(n*m)
 * 
 * where n and m are lengths of input strings
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to find the length of the smallest super-sequence that contains both input strings
int smallestSuperSequence(const string &str1, const string &str2)
{
    int len1 = str1.length();                                      // Length of the first string
    int len2 = str2.length();                                      // Length of the second string
    vector<vector<int>> superseq(len1 + 1, vector<int>(len2 + 1)); // DP table to store lengths of super-sequences

    // Fill the DP table
    for (int p = 0; p <= len1; p++)
    {
        for (int q = 0; q <= len2; q++)
        {
            if (p == 0)
            {                       // If the first string is empty
                superseq[p][q] = q; // Length of super-sequence is the length of the second string
            }
            else if (q == 0)
            {                       // If the second string is empty
                superseq[p][q] = p; // Length of super-sequence is the length of the first string
            }
            else if (str1[p - 1] == str2[q - 1])
            {                                                // If characters match
                superseq[p][q] = 1 + superseq[p - 1][q - 1]; // Include this character in the super-sequence
            }
            else
            {                                                                     // If characters do not match
                superseq[p][q] = 1 + min(superseq[p - 1][q], superseq[p][q - 1]); // Include either character and take the minimum
            }
        }
    }
    return superseq[len1][len2]; // Return the length of the smallest super-sequence
}

// Function to take input from the user
pair<string, string> takeInput()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    return {str1, str2};
}

int main()
{
    auto input = takeInput(); // Read the input strings
    string str1 = input.first;
    string str2 = input.second;

    int min_len = smallestSuperSequence(str1, str2); // Find the length of the smallest super-sequence
    cout << min_len << endl;                         // Print the length of the smallest super-sequence

    return 0;
}
