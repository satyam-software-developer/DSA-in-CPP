
/* Problem statement
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form the longest subarray that sum up to zero are: -387, -435, -5, -70, 897 
Note
You don't have to print anything. Just complete the definition of the function given and return the value accordingly. */

/*
 * Time complexity: O(N)
 * Space complexity: O(N)
 * 
 * where N is the size of the input array
 */

#include <iostream>      // Include iostream for input and output operations
#include <unordered_map> // Include unordered_map for storing prefix sums
#include <vector>        // Include vector for storing the input array
#include <string>        // Include string for input handling
#include <sstream>       // Include stringstream for parsing input

using namespace std;

// Function to find the length of the longest subarray with zero sum
int lengthOfLongestSubsetWithZeroSum(vector<int> &arr)
{
    // unordered_map to store the first occurrence of each prefix sum
    unordered_map<int, int> map;
    int n = arr.size();

    // Calculate the prefix sum for the array
    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }

    int len = 0; // Initialize the length of the longest subarray to 0

    // Iterate through the array to find the longest subarray with zero sum
    for (int i = 0; i < n; i++)
    {
        // If the prefix sum is zero, update the length of the longest subarray
        if (arr[i] == 0)
        {
            if (len < i + 1)
            {
                len = i + 1;
            }
        }
        // If the prefix sum has been seen before, update the length of the longest subarray
        else if (map.find(arr[i]) != map.end())
        {
            if (len < i - map[arr[i]])
            {
                len = i - map[arr[i]];
            }
        }
        // If the prefix sum is seen for the first time, store its index
        else
        {
            map[arr[i]] = i;
        }
    }
    return len; // Return the length of the longest subarray with zero sum
}

// Main function to execute the program
int main()
{
    int n;
    string line;

    // Read the first line of input
    getline(cin, line);
    stringstream ss(line);
    ss >> n; // Parse the number of elements in the array

    vector<int> arr(n); // Initialize the array with the given size

    // Read the second line of input
    getline(cin, line);
    stringstream ss2(line);
    for (int i = 0; i < n; i++)
    {
        ss2 >> arr[i]; // Parse each element and store it in the array
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr) << endl; // Print the length of the longest subarray with zero sum

    return 0;
}
