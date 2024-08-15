
/*Problem statement
Given an array A of size n and an integer K, return all subsets of A which sum to K.

Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note :
The order of subsets are not important.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20

Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1 */

#include <iostream>
#include <vector>
using namespace std;

// Helper function to find subsets that sum to k starting from a given index
vector<vector<int>> subsetsSumKHelper(vector<int> &input, int beginIndex, int k)
{
    // Base case: if beginIndex is equal to the length of the array
    if (beginIndex == input.size())
    {
        // If k is 0, return a vector with one empty subset
        if (k == 0)
        {
            return vector<vector<int>>(1);
        }
        else
        {
            // Otherwise, return an empty vector (no subset found)
            return vector<vector<int>>();
        }
    }

    // Recursively get subsets without including the current element
    vector<vector<int>> smallOutput1 = subsetsSumKHelper(input, beginIndex + 1, k);
    // Recursively get subsets including the current element
    vector<vector<int>> smallOutput2 = subsetsSumKHelper(input, beginIndex + 1, k - input[beginIndex]);

    // Create a new vector to hold the combined results
    vector<vector<int>> output(smallOutput1.size() + smallOutput2.size());

    int index = 0;

    // Copy subsets from smallOutput1 to output
    for (int i = 0; i < smallOutput1.size(); i++)
    {
        output[index++] = smallOutput1[i];
    }

    // Copy subsets from smallOutput2 to output, including the current element
    for (int i = 0; i < smallOutput2.size(); i++)
    {
        output[index].push_back(input[beginIndex]); // Add the current element
        for (int j = 0; j < smallOutput2[i].size(); j++)
        {
            output[index].push_back(smallOutput2[i][j]);
        }
        index++;
    }

    return output;
}

// Public function to find all subsets of input array that sum to k
vector<vector<int>> subsetsSumK(vector<int> &input, int k)
{
    return subsetsSumKHelper(input, 0, k);
}

// Function to take array input from the user
vector<int> takeInput()
{
    int size;
    cin >> size; // Read the size of the array
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i]; // Read each element of the array
    }
    return arr;
}

int main()
{
    vector<int> input = takeInput(); // Take array input from the user
    int k;
    cin >> k;                                           // Read the target sum k
    vector<vector<int>> output = subsetsSumK(input, k); // Get all subsets that sum to k

    // Print all subsets
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
