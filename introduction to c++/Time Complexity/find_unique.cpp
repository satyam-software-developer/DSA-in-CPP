/* Problem statement
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

You need to find and return that number which is unique in the array/list.

 Note:
Unique element is always present in the array/list according to the given condition.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the unique element present in the array.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec
Sample Input 1:
1
7
2 3 1 6 3 6 2
Sample Output 1:
1
Sample Input 2:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7
Sample Output 2:
4
10
*/
/*
   Time complexity : O(n)
   Space complexity: O(1)

   where n is size of input array.

*/

#include <iostream>
using namespace std;

// Function to find the unique element in the array using XOR operation
int findUnique(int *arr, int n) {
    int XOR = 0;

    // Perform XOR operation on all elements of the array
    for (int i = 0; i < n; i++) {
        XOR ^= arr[i];
    }
    return XOR; // Return the result of XOR operation
}

int main() {
    int t;
    cin >> t; // Input number of test cases

    while (t--) {
        int size;
        cin >> size; // Input size of the array
        int *input = new int[size]; // Dynamically allocate memory for the array

        // Input elements of the array
        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        // Find and print the unique element in the array
        cout << findUnique(input, size) << endl;

        delete[] input; // Free the memory allocated for the array
    }

    return 0; // Return 0 to indicate successful execution
}
