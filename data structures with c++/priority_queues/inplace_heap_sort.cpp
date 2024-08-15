
/*Problem statement
Given an integer array of size N. Sort this array (in decreasing order) using heap sort.

Note: Space complexity should be O(1).

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2 */

/*
 * Time complexity: O(log(N))
 * Space complexity: O(1)
 * 
 * where N is the size of the input array
 */

/*
 * Time complexity: O(log(N))
 * Space complexity: O(1)
 * 
 * where N is the size of the input array
 */
#include <iostream>
#include <vector>

using namespace std;

// Method to perform in-place heap sort on the array
void inplaceHeapSort(vector<int> &arr)
{
    // Build the min heap
    for (int i = 1; i < arr.size(); i++)
    {
        int childIndex = i;
        int parentIndex = (childIndex - 1) / 2;

        // Percolate up: Swap the child and parent if the child is smaller than the parent
        while (childIndex > 0)
        {
            if (arr[childIndex] > arr[parentIndex])
            {
                break; // Stop if the heap property is satisfied
            }
            // Swap the child and parent
            int temp = arr[childIndex];
            arr[childIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    // Remove the minimum element and place it at the end of the array
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        // Swap the root (minimum element) with the last element
        int min = arr[0];
        arr[0] = arr[i];
        arr[i] = min;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = leftChildIndex + 1;

        // Heapify down: Restore the heap property by moving the root element down
        while (parentIndex < i)
        {
            int minIndex = parentIndex;
            int minValue = arr[minIndex];

            if (leftChildIndex < i)
            {
                int leftChild = arr[leftChildIndex];
                if (leftChild < minValue)
                {
                    minIndex = leftChildIndex;
                    minValue = arr[minIndex];
                }
            }
            if (rightChildIndex < i)
            {
                int rightChild = arr[rightChildIndex];
                if (rightChild < minValue)
                {
                    minIndex = rightChildIndex;
                    minValue = arr[minIndex];
                }
            }
            if (parentIndex == minIndex)
            {
                break; // Stop if the heap property is satisfied
            }
            else
            {
                // Swap the current element with the smaller child
                arr[minIndex] = arr[parentIndex];
                arr[parentIndex] = minValue;
            }
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = leftChildIndex + 1;
        }
    }
}

int main()
{
    // Read the size of the array
    int n;
    cin >> n;
    vector<int> input(n);

    // Read the elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    // Perform in-place heap sort
    inplaceHeapSort(input);

    // Print the sorted array in decreasing order
    for (int i : input)
    {
        cout << i << " ";
    }
    return 0;
}
