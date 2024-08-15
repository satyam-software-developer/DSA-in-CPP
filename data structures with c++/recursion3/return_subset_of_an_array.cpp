
/*Problem statement
Given an integer array (of length n), find and return all the subsets of input array.

NOTE- Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note :
The order of subsets are not important.


Detailed explanation ( Input/output format, Notes, Images )
Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)

Expected Time Complexity: O(2^N), where N is the size of given array
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12  */

#include <iostream>
#include <vector>

using namespace std;

// Helper method to find all subsets of the array starting from a given index
vector<vector<int>> subsetsHelper(vector<int> &input, int startIndex)
{
    // Base case: if startIndex is equal to the length of the array
    if (startIndex == input.size())
    {
        return {{}};
    }

    // Recursively find subsets for the rest of the array
    vector<vector<int>> smallerOutput = subsetsHelper(input, startIndex + 1);

    // Create a new array to hold the combined results
    vector<vector<int>> output(2 * smallerOutput.size());

    int k = 0;

    // Copy subsets from smallerOutput to output
    for (int i = 0; i < smallerOutput.size(); i++)
    {
        output[k] = smallerOutput[i];
        k++;
    }

    // Copy subsets from smallerOutput to output, including the current element
    for (int i = 0; i < smallerOutput.size(); i++)
    {
        output[k] = vector<int>(smallerOutput[i].size() + 1);
        output[k][0] = input[startIndex]; // Add the current element
        for (int j = 1; j <= smallerOutput[i].size(); j++)
        {
            output[k][j] = smallerOutput[i][j - 1];
        }
        k++;
    }

    return output;
}

// Public method to find all subsets of input array
vector<vector<int>> subsets(vector<int> &input)
{
    return subsetsHelper(input, 0);
}

// Method to take array input from the user
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
    vector<int> input = takeInput();             // Take array input from the user
    vector<vector<int>> output = subsets(input); // Get all subsets of the input array

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
