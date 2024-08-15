
/* Problem statement
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
Output Format:
Print the size of maximum square sub-matrix.
 Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec
Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4 */

/*
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 * 
 * where m is number of rows and n is number of columns
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Function to find the size of the largest square sub-matrix with all zeros
int findMaxSquareWithAllZeros(vector<vector<int>> &input)
{
    int max = 0;
    if (input.size() == 0)
    {
        return 0;
    }
    int n = input.size();
    int m = input[0].size();
    vector<vector<int>> array(n, vector<int>(m, 0));

    // Initialize the first row and column of the array
    for (int i = 0; i < n; i++)
    {
        if (input[i][0] == 0)
        {
            array[i][0] = 1;
            max = 1;
        }
        else
        {
            array[i][0] = 0;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (input[0][j] == 0)
        {
            array[0][j] = 1;
            max = 1;
        }
        else
        {
            array[0][j] = 0;
        }
    }

    // Fill the rest of the array
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (input[i][j] == 1)
            {
                array[i][j] = 0;
            }
            else
            {
                array[i][j] = 1 + min(array[i - 1][j - 1], min(array[i][j - 1], array[i - 1][j]));
                if (array[i][j] > max)
                {
                    max = array[i][j];
                }
            }
        }
    }

    return max;
}

// Function to take input from the user
vector<vector<int>> takeInput()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    return arr;
}

int main()
{
    vector<vector<int>> arr = takeInput();
    cout << findMaxSquareWithAllZeros(arr) << endl;
    return 0;
}
