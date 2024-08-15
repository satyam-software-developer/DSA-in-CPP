
/* Problem statement
Given 2 sorted arrays (in increasing order), find a path through the intersections that produces maximum sum and return the maximum sum.

That is, we can switch from one array to another array only at common elements.

If no intersection element is present, we need to take sum of all elements from the array with greater sum.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
 Line 1 : An integer M i.e. size of first array
 Line 2 : M integers which are elements of first array, separated by spaces
 Line 3 : An integer N i.e. size of second array
 Line 4 : N integers which are elements of second array, separated by spaces
Output Format :
Maximum sum value
Constraints :
1 <= M, N <= 10^6

Sample Input :
6
1 5 10 15 20 25
5
2 4 5 9 15
Sample Output :
81
Explanation :
We start from array 2 and take sum till 5 (sum = 11). 
Then we'll switch to array at element 10 and take till 15. So sum = 36. 
Now, no elements left in array after 15, so we'll continue in array 1. Hence sum is 81
*/

#include <iostream>
#include <vector>
using namespace std;

// Define a function named maximumSumPath that takes two integer vectors as input and returns a long long value
long long maximumSumPath(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size(), n = arr2.size(); // Get the sizes of the two input vectors
    int i = 0, j = 0; // Initialize variables for vector traversal

    long long result = 0, sum1 = 0, sum2 = 0; // Initialize variables to store the result and sums of elements

    // Iterate through the vectors while both vectors have elements to compare
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) { // If the current element of arr1 is smaller
            sum1 += arr1[i++]; // Add it to sum1 and move to the next element of arr1
        } else if (arr1[i] > arr2[j]) { // If the current element of arr2 is smaller
            sum2 += arr2[j++]; // Add it to sum2 and move to the next element of arr2
        } else { // If the elements at the same index in both vectors are equal
            result += max(sum1, sum2); // Add the maximum of sum1 and sum2 to the result

            sum1 = 0; // Reset sum1
            sum2 = 0; // Reset sum2

            // Move through both vectors until elements at current indices are equal
            while (i < m && j < n && arr1[i] == arr2[j]) {
                result += arr1[i++]; // Add the common element to the result
                j++; // Move to the next element in arr2
            }
        }
    }

    // Process remaining elements in arr1 and arr2
    while (i < m) {
        sum1 += arr1[i++];
    }
    while (j < n) {
        sum2 += arr2[j++];
    }

    // Add the maximum of sum1 and sum2 to the result
    result += max(sum1, sum2);

    return result; // Return the final result
}

// Define the main function, the entry point of the program
int main() {
    int m, n;
    cin >> m; // Read the size of the first vector from the user
    vector<int> input1(m); // Create a vector to store the elements of the first vector
    // Input loop: Read 'm' integers from the user and store them in input1
    for (int i = 0; i < m; i++) {
        cin >> input1[i];
    }

    cin >> n; // Read the size of the second vector from the user
    vector<int> input2(n); // Create a vector to store the elements of the second vector
    // Input loop: Read 'n' integers from the user and store them in input2
    for (int i = 0; i < n; i++) {
        cin >> input2[i];
    }

    // Call the maximumSumPath function with the two input vectors and print the result
    cout << maximumSumPath(input1, input2) << endl;

    return 0; // Indicate successful termination of the program
}
