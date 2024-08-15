
/*Problem statement
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.

Note: Take absolute difference between the elements of the array.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.
Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K. 
Constraints :
0 <= n <= 10^4
Time Limit: 1 sec
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Explanation
(5,2) and (1,4) are the possible combinations as their absolute difference is 3.
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6 */

/*
 * Time complexity: O(N)
 * Space complexity: O(N)
 * 
 * where N is the size of the input array
 */

#include <iostream>      // Include the iostream library for input and output
#include <unordered_map> // Include the unordered_map library for hash maps
#include <vector>        // Include the vector library for dynamic arrays

using namespace std;

// Function to count pairs with a given difference k
int getPairsWithDifferenceK(vector<int> &arr, int k)
{
    unordered_map<int, int> map; // Unordered map to store element frequencies
    int pairCount = 0;           // Initialize pair count to 0

    // Iterate through the array
    for (int i : arr)
    {
        int p1 = i + k; // Calculate the first possible pair value
        bool flag = false;
        if (i == p1)
        {
            flag = true; // Set flag if the element itself forms the pair
        }
        if (map.find(p1) != map.end())
        {
            pairCount += map[p1]; // Add the frequency of p1 to pair count
        }
        int p2 = i - k; // Calculate the second possible pair value
        if (map.find(p2) != map.end() && !flag)
        {
            pairCount += map[p2]; // Add the frequency of p2 to pair count if flag is not set
        }
        // Update the frequency of the current element in the unordered_map
        if (map.find(i) != map.end())
        {
            map[i] += 1; // Increment the frequency
        }
        else
        {
            map[i] = 1; // Initialize the frequency to 1
        }
    }
    return pairCount; // Return the total pair count
}

// Main function to execute the program
int main()
{
    int n;
    cin >> n;           // Read the number of elements in the array
    vector<int> arr(n); // Initialize the vector with the given size

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read each element and store it in the vector
    }

    int k;
    cin >> k; // Read the value of k

    cout << getPairsWithDifferenceK(arr, k) << endl; // Print the number of pairs with difference k

    return 0;
}
