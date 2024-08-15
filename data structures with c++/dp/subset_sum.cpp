

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Method to determine if there is a subset of the array with a sum equal to the given sum
bool isSubsetPresent(const vector<int> &arr, int n, int sum)
{
    // dp[i][j] is true if we can create a subset with sum j from the first i elements
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // If sum is 0, then the answer is true (empty subset always sums to 0)
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    // If sum is not 0 and set is empty, then the answer is false
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    // Fill the table in a bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // If the current element is greater than the sum, we can't include it
            if (j < arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                // Otherwise, check if the sum can be obtained by including or excluding the current element
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][sum]; // Final result indicating if subset with given sum exists
}

int main()
{
    int size;
    cin >> size;             // Read the number of elements in the array
    vector<int> input(size); // Initialize the array

    if (size == 0)
    { // If there are no elements, print "No" and return
        cout << "No";
        return 0;
    }

    // Read the elements of the array
    cin.ignore(); // Ignore the newline character after the integer input
    string line;
    getline(cin, line);
    istringstream stream(line);
    for (int i = 0; i < size; ++i)
    {
        stream >> input[i];
    }

    int sum;
    cin >> sum; // Read the target sum

    if (isSubsetPresent(input, size, sum))
    { // Check if subset with given sum exists
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
