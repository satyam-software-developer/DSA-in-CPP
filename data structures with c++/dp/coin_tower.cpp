
/* Problem statement
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?

Detailed explanation ( Input/output format, Notes, Images )
 Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus
Explanation to Sample Input 1:
Initially, there are 4 coins,  In the first move, Beerus can remove either 1, 2, or 3 coins in all three cases, Whis can win by removing all the remaining coins.  */
/*
 * Time complexity : O(n)
 * Space complexity : O(n)
 * 
 * Where n is the initial number of coins
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Function to determine the winner of the Coin Tower game
string findWinner(int n, int x, int y)
{
    // Ensure x is less than or equal to y
    if (x > y)
    {
        swap(x, y);
    }

    // dp[i] represents whether Beerus will win with i coins remaining
    vector<bool> dp(n + 1, false);

    // Iterate through the number of remaining coins
    for (int i = 1; i <= n; i++)
    {
        // Trivial case: Beerus wins if he can take all remaining coins
        if (i == 1 || i == x || i == y)
        {
            dp[i] = true;
        }
        // If fewer than x coins remain, Beerus can only take 1 coin
        else if (i < x)
        {
            dp[i] = !dp[i - 1];
        }
        // If remaining coins are between x and y, Beerus can take 1 or x coins
        else if (i < y)
        {
            dp[i] = !(dp[i - x] && dp[i - 1]);
        }
        // If remaining coins are greater than or equal to y
        else
        {
            dp[i] = !(dp[i - x] && dp[i - y] && dp[i - 1]);
        }
    }

    // Return the result based on dp[n]
    return dp[n] ? "Beerus" : "Whis";
}

// Function to take input from the user
vector<int> takeInput()
{
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> result;
    int value;

    // Parse input values and store them in the vector
    while (ss >> value)
    {
        result.push_back(value);
    }

    return result;
}

// Main function to read input and call findWinner
int main()
{
    vector<int> input = takeInput();
    int n = input[0];
    int x = input[1];
    int y = input[2];

    cout << findWinner(n, x, y) << endl;

    return 0;
}
