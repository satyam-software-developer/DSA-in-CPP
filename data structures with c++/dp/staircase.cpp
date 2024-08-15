
/*Problem statement
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
9
		int min_len = Solution.smallestSuperSequence(str1, str2);
		System.out.print(min_len);
	}
}
 */

/*
 * Time Complexity: O(n*m)
 * Space Complexity: O(n*m)
 * 
 * where n and m are lengths of input strings
 */

#include <iostream>
#include <vector>
using namespace std;

// Method to calculate the number of ways to reach the nth stair
long staircase(int n)
{
    vector<long> ways(n + 1); // this is our DP array/list of size (n+1)

    // Base Case
    if (n == 0)
    {
        return 1; // There's only one way to stay at the ground (doing nothing)
    }
    if (n == 1 || n == 2)
    {
        return n; // If there's 1 stair, there's 1 way; if there are 2 stairs, there are 2 ways
    }

    // Initialize the base cases for dynamic programming
    ways[0] = 1; // 1 way to stay at the ground
    ways[1] = 1; // 1 way to reach the first stair
    ways[2] = 2; // 2 ways to reach the second stair (1+1 or 2)

    // Fill the DP array
    for (int i = 3; i <= n; i++)
    {
        // Number of ways to reach the ith stair is the sum of ways to reach (i-1)th, (i-2)th, and (i-3)th stairs
        ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3];
    }
    return ways[n]; // Return the number of ways to reach the nth stair
}

int main()
{
    int n;
    cin >> n;                     // Read the input (number of stairs)
    cout << staircase(n) << endl; // Print the result of the staircase method
    return 0;
}
