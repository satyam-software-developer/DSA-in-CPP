
/* Problem statement
Given an array A[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. If frequencies of two elements are same, then smaller number comes first.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:

The first line contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
Output Format:

Print the soted array seperated by a space.
Example:
Input:
6
1 2 2 2 3 3
Output:
2 2 2 3 3 1 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class SortComparator
{
private:
    map<int, int> &freqMap;

public:
    // Constructor to assign the frequency map
    SortComparator(map<int, int> &tFreqMap) : freqMap(tFreqMap) {}

    // Overload the operator() to compare two integers based on frequency and value
    bool operator()(int k1, int k2)
    {
        // Compare value by frequency
        int freqCompare = freqMap[k2] - freqMap[k1];

        // If frequency is equal, then just compare by value, otherwise compare by the frequency.
        if (freqCompare == 0)
        {
            return k1 < k2;
        }
        else
        {
            return freqCompare > 0;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    // Create a map to store the frequency of each element
    map<int, int> freqMap;
    vector<int> outputArray;

    // Assign elements and their count in the list and map
    for (int current : array)
    {
        freqMap[current]++;
        outputArray.push_back(current);
    }

    // Create a comparator using the map
    SortComparator comp(freqMap);

    // Sort the list using the comparator
    sort(outputArray.begin(), outputArray.end(), comp);

    // Final Output
    for (int i : outputArray)
    {
        cout << i << " ";
    }

    return 0;
}
