
/*Problem statement
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.

That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1 */
/*
 * Time Complexity : O(n * sqrt(n))
 * Space Complexity : O(n)
 */
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <string>

using namespace std;

class MinimumCount
{

public:
    // Method to find the minimum count of perfect squares that sum up to n
    static int minCount(int n)
    {
        // Vector to store the minimum number of perfect squares required to sum up to each number from 0 to n
        vector<int> minSquareRequired(n + 1);

        // Base cases
        minSquareRequired[0] = 0; // 0 perfect squares are needed to sum up to 0
        minSquareRequired[1] = 1; // 1 perfect square (1^2) is needed to sum up to 1

        // Iterate from 2 to n to fill the minSquareRequired vector
        for (int i = 2; i <= n; ++i)
        {
            // Initialize the count to a large value
            minSquareRequired[i] = INT_MAX;

            // Check all possible perfect squares less than or equal to i
            for (int j = 1; i - (j * j) >= 0; ++j)
            {
                // Update the minimum count for the current number i
                minSquareRequired[i] = min(minSquareRequired[i], minSquareRequired[i - (j * j)]);
            }
            // Add 1 to include the current perfect square
            minSquareRequired[i] += 1;
        }

        // Return the minimum count of perfect squares required for n
        return minSquareRequired[n];
    }
};

int main()
{
    // Read the input number
    int n;
    cin >> n;
    // Print the minimum count of perfect squares required to sum up to the input number
    cout << MinimumCount::minCount(n) << endl;

    return 0;
}
