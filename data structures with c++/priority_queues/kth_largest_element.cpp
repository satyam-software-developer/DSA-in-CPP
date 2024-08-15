
/* Problem statement
Given an array 'arr' of random integers and an integer 'k', return the kth largest element in the array.



Note: Try to do this in O(n*log k) time.


Example:
Input:
5
3 2 5 1 4
2
Output:
4
Explanation:
Array in non increasing form is [5,4,3,2,1]. So the 2nd largest is 4.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains an integer 'n', that denotes the size of the array.
The next line contains 'n' space separated integers, that denote the value of the elements of the array 'arr'.
The next line contains an integer, that denotes the value of 'k'.
Output Format :
The output contains the kth largest element.
Sample Input 1 :
6
9 4 8 7 11 3
2
Sample Output 1 :
9
Explanation of sample input 1:
arr = [9,4,8,7,11,3]
Array 'arr' in non increasing form is [11,9,8,7,4,3]. So the 2nd largest is 9.
Sample Input 2 :
8
2 6 10 11 13 4 1 20
4
Sample Output 2 :
10
Constraints :
1 <= n <= 10^5
1 <= arr[i] <= 10^5
1 <= k <= n
Time Limit: 1 sec */

/*
 * Time complexity: O(N * log(K))
 * Space complexity: O(K)
 * 
 * where N is the size of the input array
 * and K is the number of largest element that is to be found
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the kth largest element in the input array
int kthLargest(const vector<int> &input, int k)
{
    // Create a min-priority queue (min-heap) to maintain the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Add the first k elements to the min-heap
    for (int i = 0; i < k; i++)
    {
        minHeap.push(input[i]);
    }

    // Process the remaining elements in the input array
    for (int i = k; i < input.size(); i++)
    {
        // If the current element is larger than the smallest element in the min-heap
        if (input[i] > minHeap.top())
        {
            minHeap.pop();          // Remove the smallest element from the min-heap
            minHeap.push(input[i]); // Add the current element to the min-heap
        }
    }

    // The root of the min-heap is the kth largest element
    return minHeap.top();
}

int main()
{
    int n;    // Size of the array
    cin >> n; // Read the size of the array

    vector<int> input(n); // Initialize the input vector with the size n

    // Read the elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;    // Value of k
    cin >> k; // Read the value of k

    // Find the kth largest element and print it
    cout << kthLargest(input, k) << endl;

    return 0;
}
