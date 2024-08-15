/* Problem statement
Teaching Assistants at Coding Ninjas are working day and night for resolving doubts of students. On a particular day, Aroma had solved lot of doubts. There is still one left unsolved, so, she is asking for help.

The description of the doubt is - "Help me solve this question."

The question is described as - "You are given a word M and K queries. In every query, there are four integers: W, X, Y and Z. Let us form another word P by the characters at positions: [W, X] of a given word M (characters at position W and X are inclusive). Let us form another word Q by the characters at positions [Y, Z] of the given word M (characters at positions Y and Z are inclusive). For every query, you must answer if it is possible to rearrange the letters of word Q and form word P."

Your task is to help Aroma and write code for this problem.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains the string M. The length of string M lies in the range: [1, 50000]. String M consists only of lowercase letters of English alphabet. The second line of input contains an integer, that denotes the value of K (1 <= K <= 50000). Each of the following K lines contains four integers: W, X, Y, Z. (1 <= W, X <= |M| and 1 <= Y, Z <= |M|).
Constraints:
Time Limit: 1 second
Output Format:
There are K lines of output, one for each query. For each query, print "true" if it possible and "false" otherwise.   
Sample Input 1:
navdeepdvan
2
1 4 8 11
4 5 7 8
Sample Output 1:
true
false
Explanation:
In the first query, the word formed are: P is "navd" and Q is "dvan". Hence, true.
In the second query, the word formed are: P is "de" and Q is "pd". Hence, false. */

#include <iostream>
#include <vector>
using namespace std;

// Frequency array to store the prefix frequency of each character from 'a' to 'z'
int e[50005][26];

int main()
{
    // Read the string M
    string s;
    cin >> s;
    int n = s.length();

    // Number of queries
    int q;
    cin >> q;

    // Initialize the frequency array for the first character
    for (int w = 0; w < 26; w++)
    {
        e[0][w] = 0; // Initialize the array
    }
    e[0][s[0] - 'a']++;

    // Build the prefix frequency array
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            e[i][j] = e[i - 1][j]; // Carry forward the previous frequencies
        }
        e[i][s[i] - 'a']++; // Increment the frequency of the current character
    }

    // Process each query
    for (int v = 0; v < q; v++)
    {
        // Read W, X, Y, Z for the current query
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--; // Convert to zero-based indexing

        // Flag to check if rearrangement is possible
        bool possible = true;

        // Compare the frequency of each character between the two substrings
        for (int l = 0; l < 26; l++)
        {
            int freqP = e[b][l] - (a > 0 ? e[a - 1][l] : 0);
            int freqQ = e[d][l] - (c > 0 ? e[c - 1][l] : 0);

            if (freqP != freqQ)
            {
                possible = false;
                break;
            }
        }

        // Output the result for the current query
        if (possible)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    return 0;
}
