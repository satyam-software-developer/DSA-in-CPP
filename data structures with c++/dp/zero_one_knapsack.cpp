
/* Problem statement
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of the input contains an integer value N, which denotes the total number of items.

The second line of input contains the N number of weights separated by a single space.

The third line of input contains the N number of values separated by a single space.

The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.
Output Format :
Print the maximum value of V that the thief can steal.
Constraints :
1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
Sample Input 2 :
5
12 7 11 8 9
24 13 23 15 16
26
Sample Output 2 :
51 */

/*
 * Time Complexity : O(3^n)
 * Space Complexity : O(N)
 * 
 * Where N is the total number of weights
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Class to handle input
class Input
{
public:
    int n;               // Number of items
    vector<int> weights; // Array of item weights
    vector<int> values;  // Array of item values
    int maxWeight;       // Maximum weight the knapsack can carry

    // Constructor to initialize the Input object
    Input(vector<int> w, vector<int> v, int numItems, int maxW)
        : weights(w), values(v), n(numItems), maxWeight(maxW) {}
};

// Function to take input from the user
Input takeInput()
{
    int n;
    cin >> n; // Read the number of items

    if (n == 0)
    {
        return Input({}, {}, 0, 0); // If no items, return an empty Input object
    }

    vector<int> weights(n);
    vector<int> values(n);

    // Read weights
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }

    // Read values
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight; // Read the maximum weight

    return Input(weights, values, n, maxWeight); // Return a new Input object with the read values
}

// Function to solve the knapsack problem using recursion and memoization
int knapsack(const vector<int> &weights, const vector<int> &values, int n, int maxWeight, vector<vector<int>> &dp)
{
    if (n == 0 || maxWeight == 0)
    {
        return 0; // Base case: no items or no capacity left
    }

    if (dp[n][maxWeight] != -1)
    {
        return dp[n][maxWeight]; // Return precomputed result if available
    }

    if (weights[n - 1] > maxWeight)
    {
        // If the item is too heavy, skip it
        dp[n][maxWeight] = knapsack(weights, values, n - 1, maxWeight, dp);
    }
    else
    {
        // Include the item
        int includeItem = values[n - 1] + knapsack(weights, values, n - 1, maxWeight - weights[n - 1], dp);
        // Exclude the item
        int excludeItem = knapsack(weights, values, n - 1, maxWeight, dp);
        // Take the maximum value of including or excluding the item
        dp[n][maxWeight] = max(includeItem, excludeItem);
    }

    return dp[n][maxWeight]; // Return the computed value for the current subproblem
}

// Main function to run the program
int main()
{
    Input input = takeInput(); // Read input

    int n = input.n;                     // Get number of items
    vector<int> weights = input.weights; // Get weights vector
    vector<int> values = input.values;   // Get values vector
    int maxWeight = input.maxWeight;     // Get maximum weight

    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, -1)); // Initialize memoization table

    // Compute and print the maximum value that can be stolen
    cout << knapsack(weights, values, n, maxWeight, dp) << endl;

    return 0;
}
