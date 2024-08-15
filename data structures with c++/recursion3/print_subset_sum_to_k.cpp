
/* Problem statement
Given an array A and an integer K, print all subsets of A which sum to K.

Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note :
The order of subsets are not important. Just print them in different lines.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
*/

#include <iostream>
#include <vector>
using namespace std;

// Helper method to find subsets that sum to k starting from a given index
void printSubsetsSumTokHelper(vector<int> &input, int beginIndex, vector<int> &output, int k)
{
    // Base case: if beginIndex is equal to the length of the array
    if (beginIndex == input.size())
    {
        // If k is 0, print the current subset
        if (k == 0)
        {
            for (int i : output)
            {
                cout << i << " ";
            }
            cout << endl;
            return;
        }
        else
        {
            // If k is not 0, return without printing
            return;
        }
    }

    // Create a new vector to hold the current subset including the current element
    vector<int> newOutput = output;
    newOutput.push_back(input[beginIndex]);

    // Recursively call the helper method excluding the current element
    printSubsetsSumTokHelper(input, beginIndex + 1, output, k);
    // Recursively call the helper method including the current element
    printSubsetsSumTokHelper(input, beginIndex + 1, newOutput, k - input[beginIndex]);
}

// Method to find and print all subsets of input array that sum to k
void printSubsetsSumTok(vector<int> &input, int k)
{
    vector<int> output;                            // Initialize an empty output vector
    printSubsetsSumTokHelper(input, 0, output, k); // Call the helper method
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
    vector<int> input = takeInput(); // Take array input from the user
    int k;
    cin >> k;                     // Read the target sum k
    printSubsetsSumTok(input, k); // Print all subsets that sum to k
    return 0;
}
