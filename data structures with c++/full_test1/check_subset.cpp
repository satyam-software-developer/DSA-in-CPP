/*Problem statement
Given two integer arrays. Check if second array is a subset of first array.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : Integer N1 
Line 2 : N1 integers separated be a single space
Line 1 : Integer N2 
Line 2 : N2 integers separated be a single space
Output Format :
 Boolean
Constraints :
 0 <= N1 <= 10^4
 0 <= N2 <= 10^4
Sample Input :
15
3 6 5 8 15 1 14 18 7 9 14 9 3 12 8 
4
18 6 9 8
Sample Output :
true */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to check if arr2 is a subset of arr1
bool isSubset(const vector<int> &arr1, const vector<int> &arr2)
{
    unordered_map<int, int> map;

    // Populate the map with counts of elements from arr1
    for (int num : arr1)
    {
        map[num]++;
    }

    // Check if all elements in arr2 are present in arr1 with sufficient counts
    for (int num : arr2)
    {
        if (map.find(num) == map.end() || map[num] == 0)
        {
            return false; // Element is not present or not enough counts
        }
        map[num]--; // Decrement the count
    }

    return true; // All elements of arr2 are present in arr1 with sufficient counts
}

int main()
{
    int n1, n2;
    cin >> n1;
    vector<int> arr1(n1);

    // Read elements of the first array
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cin >> n2;
    vector<int> arr2(n2);

    // Read elements of the second array
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    // Check if arr2 is a subset of arr1 and print the result
    cout << (isSubset(arr1, arr2) ? "true" : "false") << endl;

    return 0;
}
