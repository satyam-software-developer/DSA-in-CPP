
/* Problem statement
You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). 
Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.

Note :
Duplicate number is always present in the given array/list.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the duplicate element in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^6

Time Limit: 1 sec
Sample Input 1:
1
9
0 7 2 5 4 7 1 3 6
Sample Output 1:
7
Sample Input 2:
2
5
0 2 1 3 1
7
0 3 1 5 4 3 2
Sample Output 2:
1
3
*/


/*
   Time Complexity : O(n)
   Space Complexity : O(1)

   where n is size of input array

*/
/*
   There is another way of solving this using XOR.
   Time and Complexity remains the same as above.

*/

#include<iostream>
using namespace std;

// Function to find the duplicate element in the array
int findDuplicate(int *arr, int n) {
    int sumOfNminusTwoNaturalNumbers = 0;

    // Calculate the sum of the first (n - 2) natural numbers
    for (int i = 0; i < n; i++) {
        sumOfNminusTwoNaturalNumbers += i;
    }

    int sumOfElements = 0;

    // Calculate the sum of all elements in the array
    for (int i = 0; i < n; i++) {
        sumOfElements += arr[i];
    }

    // Return the difference between the sum of elements and the sum of the first (n - 2) natural numbers
    return (sumOfElements - sumOfNminusTwoNaturalNumbers);
}

int main() {
    int t;
	cin >> t; // Input number of test cases

    while (t--) {
        int size;
		cin >> size; // Input size of the array
		int *input = new int[size]; // Allocate memory for the array

        // Input elements of the array
		for (int i = 0; i < size; i++) {
			cin >> input[i];
		}

        // Find and print the duplicate element in the array
		cout << findDuplicate(input, size) << endl;

        delete[] input; // Free the memory allocated for the array
	}
     
    return 0; // Return 0 to indicate successful termination
}
