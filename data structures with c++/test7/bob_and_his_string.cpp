
/* Problem statement
King Bob is in playful mood today. He started playing with string S. As he was playing, a weird question came in his mind. He wondered what is the maximum number of characters, between any two same characters in the string. He needs your help in solving this question. Can you help him solve this question?

Note: String S is composed of lowercase letters of the Latin alphabet. If there are no two same characters in the string, print -1.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains one integer T, denoting the number of test cases. 
Each of the next T line contains one string S.
Constraints:
1 < T < 10
1 < |S| < 100000, where S determines the length of the string.
String is composed of lowercase alphabets ranging from a to z.
Time limit : 1 sec
Output Format:
For each test case, output the maximum number of characters between any two same characters in the string. If there are no two same characters in the string, print -1. 
Print answer for each test case in a new line.
Sample Input 1:
2
aba
babcddc
Sample Output 1:
1
2
Explanation:
1) For string = aba
There is only one character between 2 occurrences of a.

2) For string = babcddc
There is one character between 2 occurrences of b, and 2 characters between 2 occurrences of c. So the answer is 2. */

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // Disable synchronization with C I/O streams for faster input
    cin.tie(NULL);                    // Untie cin from cout for faster input

    int t;
    cin >> t; // Read the number of test cases

    while (t-- > 0)
    { // Loop through all test cases
        string s;
        cin >> s;                     // Read the string for the current test case
        int max = INT_MIN;            // Initialize max distance to the smallest possible value
        vector<int> freq_map(26, -1); // Vector to store the first occurrence index of each character, initialized to -1

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a'; // Calculate the index for the character

            // If the character is encountered for the first time
            if (freq_map[index] == -1)
            {
                freq_map[index] = i; // Store the index of the first occurrence
            }
            else
            {
                int distance = i - freq_map[index]; // Calculate the distance between current and first occurrence
                if (distance > max)
                { // Update max if the current distance is greater
                    max = distance;
                }
            }
        }

        // If max is still the initial value, no repeating character was found
        if (max == INT_MIN)
        {
            cout << -1 << endl; // Print -1 indicating no repeating characters
        }
        else
        {
            cout << max - 1 << endl; // Print the maximum distance minus 1
        }
    }

    return 0;
}
