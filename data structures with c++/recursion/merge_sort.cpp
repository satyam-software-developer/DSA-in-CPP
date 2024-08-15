
/*
Problem statement
You are given the starting 'l' and the ending 'r' positions of the array 'ARR'.



You must sort the elements between 'l' and 'r'.



Note:
Change in the input array itself. So no need to return or print anything.
Example:
Input: ‘N’ = 7,
'ARR' = [2, 13, 4, 1, 3, 6, 28]

Output: [1 2 3 4 6 13 28]

Explanation: After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an integer <em>**'N'**</em> representing the size of the array/list.

The second line contains 'N' single space-separated integers representing the elements in the array/list.
Output format :
You don't need to return anything. In the output, you will see the array after you do the modification.
Sample Input 1:
7
2 13 4 1 3 6 28
Sample Output 1:
1 2 3 4 6 13 28
Explanation of Sample Output 1:
After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
Sample Input 2:
5
9 3 6 2 0
Sample Output 2:
0 2 3 6 9
Explanation of Sample Output 2:
After applying 'merge sort' on the input array, the output is [0 2 3 6 9].
Constraints :
1 <= N <= 10^3
0 <= ARR[i] <= 10^9
*/

/*
 *   Time Complexity : O(n * log(n))
 *   Space Complexity : O(n)
 *  
 *   where n is size of input array
 */

#include <iostream>

using namespace std;

// Function to merge two sorted subarrays
void merge(int arr[], int l, int m, int r) {
    // Calculate the sizes of the two subarrays
    int num1 = m - l + 1;
    int num2 = r - m;
    
    // Create temporary arrays to hold the elements of the two subarrays
    int L[num1];
    int R[num2];

    // Copy data to temporary arrays
    for (int i = 0; i < num1; ++i) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < num2; ++j) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the two subarrays back into the original array
    int i = 0, j = 0, k = l;
    while (i < num1 && j < num2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[] if any
    while (i < num1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[] if any
    while (j < num2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on an array
void mergeSort(int arr[], int l, int r) {
    // Base case: If the left index is less than the right index, 
    // it means there is at least one element to sort
    if (l < r) {
        // Finding the middle index
        int m = (l + r) / 2;
        // Recursively sort the first half of the array
        mergeSort(arr, l, m);
        // Recursively sort the second half of the array
        mergeSort(arr, m + 1, r);
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Main function to test the merge sort implementation
int main() {
    // Read the size of the array from the user
    int n;
    cin >> n;

    // Create an array to store the elements
    int arr[n];

    // Read the elements of the array from the user
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call the mergeSort function to sort the array
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
