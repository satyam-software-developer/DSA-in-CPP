
/*
Problem statement
Sort the given unsorted array 'arr' of size 'N' in non-decreasing order using the selection sort algorithm.

 Note:
Change in the input array/list itself.

Example:
Input:
N = 5
arr = {8, 6, 2, 5, 1}

Output:
1 2 5 6 8
Explanation: add-image

Detailed explanation ( Input/output format, Notes, Images )
Input format :
First line contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output format :
The output contains the integers of the sorted array, separated by a single space.
Note:-
You don’t need to print anything. Just implement the given function.
Sample Input 1:
6
2 13 4 1 3 6
Sample Output 1:
1 2 3 4 6 13
Explanation Of Sample Input 1:
 Select 1 and swap with element at index 0. arr= {1,13,4,2,3,6}

 Select 2 and swap with element at index 1. arr= {1,2,4,13,3,6}

 Select 3 and swap with element at index 2. arr= {1,2,3,13,4,6}

 Select 4 and swap with element at index 3. arr= {1,2,3,4,13,6}

 Select 6 and swap with element at index 4. arr= {1,2,3,4,6,13}
Sample Input 2:
5
9 3 6 2 0
Sample Output 2:
0 2 3 6 9
Constraints :
1 <= N <= 10^3
0 <= arr[i] <= 10^5
Time Limit: 1 sec

*/

/*
   Time Complexity: O(N*N)
   Space Complexity: O(N)
   where 'N' is the length of an array.

*/

#include <iostream>
using namespace std;

// Function to perform selection sort on the given array
void selectionSort(int arr[], int n)
{
    // Loop through the array elements
    for (int i = 0; i < n - 1; i++)
    {
        // Find the index of the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Swap the current element with the minimum element found
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main()
{
    int N;
    cin >> N; // Input the size of the array

    int arr[N]; // Declare an array of size N
    // Input the elements of the array
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // Sort the array using selection sort
    selectionSort(arr, N);

    // Print the sorted array
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
