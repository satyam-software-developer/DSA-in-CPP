
/* Problem statement
Miss. Noor Rashid is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line, and each of them has a score according to performance. Noor wants to give at least one chocolate to each student. She distributes chocolates to them such that If two students sit next to each other, then the one with the higher score must get more chocolates. Miss. Noor wants to save money, so she wants to minimize the total number of chocolates.

Note :
When two students have an equal score, they are allowed to have a different number of chocolates. 
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of the input contains an integer value of N. It denotes the total number of students in Noor's class.

The second line of the input contains N integer values denoting the score of each of the students. A single space will separate them.
Output Format:
Print the minimum number of chocolates Noor must give.
Constraints
1 <= N <= 10^5
1 <= score <= 10^5

Time Limit: 1 sec
Sample Input 1 :
4
1 4 4 6
Sample Output 1 :
6
Explanation:
One of the ways in which the chocolates can be distributed, such Noor has to give minimum number of chocolates, are: The first student can be given one chocolate, second student can be given two chocolates, third student can be one chocolate and fourth can be given two chocolates.  
Sample Input 2 :
3
8 7 5
Sample Output 2 :
6 */

/*
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * where n is the number of elements in input array
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Method to find the minimum number of chocolates needed
int getMin(vector<int> &arr, int N)
{
    vector<int> dp(N, 1); // Vector to store chocolates for each student

    // Traverse from left to right to satisfy increasing score condition
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
    }

    // Traverse from right to left to satisfy decreasing score condition
    for (int i = N - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1] && dp[i] <= dp[i + 1])
        {
            dp[i] = dp[i + 1] + 1;
        }
    }

    // Sum up the total number of chocolates needed
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += dp[i];
    }

    return sum; // Return the total chocolates required
}

// Method to take input for the scores of students
vector<int> takeInput(int &size)
{
    cin >> size;             // Read the number of students
    vector<int> input(size); // Initialize the vector for scores

    // Read the scores from input
    for (int i = 0; i < size; ++i)
    {
        cin >> input[i];
    }

    return input; // Return the vector of scores
}

int main()
{
    int size;
    vector<int> arr = takeInput(size); // Take input for the scores
    cout << getMin(arr, size) << endl; // Print the minimum number of chocolates needed
    return 0;
}
