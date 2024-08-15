
/* Problem statement
You are given an sorted integer array of size 'n'.

Your task is to find and return all the unique subsets of the input array.

Subsets are arrays of length varying from 0 to 'n', that contain elements of the array. But the order of elements should remain the same as in the input array.

Note:
The order of subsets is not important. You can return the subsets in any order. However, in the output, you will see the subsets in lexicographically sorted order.

Constraints :
1 <= n <= 15
1 <= arr[i] <= 100

Time Limit: 1 sec
Example:
Input: 'n' = 3, 'arr' = [12, 15, 20]

Output: [[], [12], [12, 15], [12, 15, 20], [12, 20], [15], [15, 20], [20]]

Sample Explanation: Since there are no repeated numbers, a total of 8 subsets are generated.
Constraints :
1 <= n <= 15
1 <= arr[i] <= 100

Time Limit: 1 sec
Example:
Input: 'n' = 3, 'arr' = [12, 15, 20]

Output: [[], [12], [12, 15], [12, 15, 20], [12, 20], [15], [15, 20], [20]]

Sample Explanation: Since there are no repeated numbers, a total of 8 subsets are generated.
Input Format :
The first line will contain the value of ‘n’.

The second line will contain n integers, denoting the array 'arr' elements.
Output format :
Return all unique subsets in any order.
Note :
You don't need to print anything. It has already been taken care of. Just implement the given function.
Sample Input 1 :
3
12 15 20
Sample Output 1 :
[] (this represents an empty array)
12
12 15
12 15 20
12 20
15
15 20
20
Explanation Of Sample Input 1 :
Since there are no repeated numbers, 8 subsets are generated.
Sample Input 2 :
3
1 1 2
Sample Output 2 :
[]
1
1 1
1 1 2
1 2
2
Explanation Of Sample Input 2 :
Since there are repeated numbers, the total number of unique subsets is 6.
Expected Time Complexity :
The expected time complexity is O(k * 2^n), where n is the size of the array and 'k' is the average size of a subset.
Expected Space Complexity :
The expected time complexity is O(k * 2^n), where n is the size of the array and 'k' is the average size of a subset. */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to generate all unique subsets of the given input array
void generateSubsets(vector<int> &input, int index, vector<int> &currentSubset, vector<vector<int>> &subsets)
{
    // Add the current subset to the list of subsets
    subsets.push_back(currentSubset);

    for (int i = index; i < input.size(); ++i)
    {
        // Skip duplicates
        if (i > index && input[i] == input[i - 1])
        {
            continue;
        }
        // Add the current element to the subset
        currentSubset.push_back(input[i]);

        // Recursively generate subsets starting from the next index
        generateSubsets(input, i + 1, currentSubset, subsets);

        // Remove the current element from the subset to backtrack
        currentSubset.pop_back();
    }
}

// Function to return all unique subsets of the given input array
vector<vector<int>> getSubsets(vector<int> &input)
{
    // Sort the input array (if it's not already sorted)
    sort(input.begin(), input.end());

    vector<vector<int>> subsets;
    vector<int> currentSubset;
    generateSubsets(input, 0, currentSubset, subsets);

    return subsets;
}

// Function to print all unique subsets of the given input array
void printSubsets(vector<int> &input)
{
    vector<vector<int>> subsets = getSubsets(input);

    // Print the subsets
    for (const auto &subset : subsets)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Function to take input from the user and return it as an array
vector<int> takeInput()
{
    int size;
    cin >> size; // Read the size of the array

    vector<int> arr(size);
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i]; // Read each element of the array
    }

    return arr;
}

int main()
{
    vector<int> input = takeInput(); // Take array input from the user
    printSubsets(input);             // Print all unique subsets of the input array
    return 0;
}
