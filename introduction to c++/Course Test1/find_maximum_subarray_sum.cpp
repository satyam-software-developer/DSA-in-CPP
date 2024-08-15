/*
Problem statement
You are given an integer array, arr, of size N and a positive integer K. 
Out of all subarrays of 'arr' of size K, find the sum of the subarray that has the maximum sum.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line of the input contains two space-separated integers, N and K
The second line contains N space-separated integers which represent the elements of the array, arr
Output format:
The output only consists of a single integer, the sum of the subarray that has the maximum sum
Constraints:
1 <= N <= 10^6
1 <= K <= N
Time limit: 1 sec 
Sample Input 1:
4 1
1 2 3 4
Sample Output 1:
4
Sample Input 2:
6 2
2 7 3 6 7 7 
Sample Output 2:
14
Explanation for Sample Output 2:
There are 5 subarrays of size 2 in this array. They are {2, 7}, {7, 3}, {3, 6}, {6, 7}, {7, 7}. 
Since the subarray {7, 7} has the maximum sum among all the subarrays, the output will be 7 + 7 = 14
*/

/*
   Time complexity: O(N)
   Space complexity: O(1)

   where N is the size of the array


*/


#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum sum of subarrays of size K
int getMaxSubarraySum(int *arr, int n ,int k) {
    int currentSum = 0;

    // Calculate the sum of the first K elements
    for (int i = 0; i < k; ++i) {
        currentSum += arr[i];
    }

    int maxSum = currentSum;

    // Calculate the sum of subsequent subarrays of size K
    for (int i = k; i < n; ++i) {
        // Update currentSum by subtracting the first element of the previous subarray
        // and adding the next element after the previous subarray
        currentSum = currentSum - arr[i - k] + arr[i];
        // Update maxSum if the current sum is greater
        maxSum = max(maxSum, currentSum);
    }

    // Return the maximum sum
    return maxSum;
}

int main() {
     int n, k;
    cin >> n >> k;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << getMaxSubarraySum(arr, n, k);
    return 0;
}
