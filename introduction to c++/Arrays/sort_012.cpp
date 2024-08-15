
/*
Problem statement
You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s.
Write a solution to sort this array/list in a 'single scan'.

'Single Scan' refers to iterating over the array/list just once or to put it in other words,
you will be visiting each element in the array/list just once.

Note:
1. You need to change in the given array/list itself. Hence, no need to return or print anything.
2. You are not allowed to sort the list/array directly.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers(all 0s, 1s and 2s) representing the elements in the array/list.
Output Format :
For each test case, print the sorted array/list elements in a row separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1:
1
7
0 1 2 0 2 0 1
Sample Output 1:
0 0 0 1 1 2 2
Explanation:  The array contains three 0s, two 1s, and two 2s.
After sorting the array in a single scan, the 0s should come first,
then the 1s, and finally the 2s. So the output is 0 0 0 1 1 2 2.
Sample Input 2:
2
5
2 2 0 1 1
7
0 1 2 0 1 2 0
Sample Output 2:
0 1 1 2 2
Explanation: The array contains one 0, two 1s, and two 2s.
After sorting, the 0 comes first, then the 1s, and finally the 2s. So the output is 0 1 1 2 2.
0 0 0 1 1 2 2
Explanation: The array contains three 0s, two 1s, and two 2s.
After sorting, the 0s come first, then the 1s, and finally the 2s.
So the output is 0 0 0 1 1 2 2.

*/

#include <iostream>
using namespace std;

// Function to sort an array of 0s, 1s, and 2s
void sort012(int *arr, int n)
{
    int i = 0;
    int nextZero = 0;    // Pointer to the next position to place 0
    int nextTwo = n - 1; // Pointer to the next position to place 2

    // Loop through the array
    while (i <= nextTwo)
    {
        if (arr[i] == 0)
        { // If the current element is 0
            // Swap the current element with the element at nextZero position
            int temp = arr[i];
            arr[i] = arr[nextZero];
            arr[nextZero] = temp;

            // Increment both i and nextZero pointers
            i++;
            nextZero++;
        }
        else if (arr[i] == 2)
        { // If the current element is 2
            // Swap the current element with the element at nextTwo position
            int temp = arr[i];
            arr[i] = arr[nextTwo];
            arr[nextTwo] = temp;

            // Decrement the nextTwo pointer
            nextTwo--;
        }
        else
        { // If the current element is 1, just move to the next element
            i++;
        }
    }
}

// Main function
int main()
{
    int t;
    cin >> t;

    // Iterate through each test case
    while (t--)
    {
        int size;
        cin >> size;

        // Create an array to store the elements
        int *arr = new int[size];

        // Read the elements of the array from the input
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

        // Sort the array of 0s, 1s, and 2s
        sort012(arr, size);

        // Print the sorted array
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        // Free the memory allocated for the array
        delete[] arr;

        cout << endl;
    }

    return 0;
}
