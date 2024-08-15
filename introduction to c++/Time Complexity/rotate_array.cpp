
/* Problem statement
You have been given a random integer array/list(ARR) of size N. 
Write a function that rotates the given array/list by D elements(towards the left).

 Note:
Change in the input array/list itself.You don't need to return or print the elements.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains the value of 'D' by which the array/list needs to be rotated.
Output Format :
For each test case, print the rotated array/list in a row separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^4
0 <= N <= 10^6
0 <= D <= N
Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2
Sample Input 2:
2
7
1 2 3 4 5 6 7
0
4
1 2 3 4
2
Sample Output 2:
1 2 3 4 5 6 7
3 4 1 2
*/

#include<iostream> // Include the standard input-output stream header
using namespace std; // Using the standard namespace

// Function to swap elements at indices i and j in an array
void swapElements(int *input, int i, int j) {
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
}

// Function to reverse elements in the array from index start to end
void reverse(int *input, int start, int end) {
    int i = start, j = end;

    // Swap elements until the midpoint is reached
    while (i < j) {
        swapElements(input, i, j);
        i++;
        j--;
    }
}

// Function to rotate the array by d positions to the left
void rotate(int *input, int d, int n) {
    // If d is greater than or equal to n, reduce d to its modulo n
    if (d >= n && n != 0) {
        d = d % n;
    } else if (n == 0) {
        return; // If n is 0, return without performing any rotation
    }

    // Reverse the entire array
    reverse(input, 0, n - 1);
    // Reverse the first (n - d) elements
    reverse(input, 0, n - d - 1);
    // Reverse the remaining d elements
    reverse(input, n - d, n - 1);
}

int main() {
    int t;
    cin >> t; // Input the number of test cases

    // Iterate over each test case
    while (t--) {
        int size;
        cin >> size; // Input the size of the array

        int *input = new int[size]; // Dynamically allocate memory for the array

        // Input the elements of the array
        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        int d;
        cin >> d; // Input the number of rotations to the left

        // Perform rotation of the array by d positions to the left
        rotate(input, d, size);

        // Output the rotated array
        for (int i = 0; i < size; ++i) {
            cout << input[i] << " ";
        }

        delete[] input; // Deallocate memory for the array
        cout << endl;
    }

    return 0;
}
