
/* Problem statement
Given an array arr of N integers, we have to remove the elements from the array such that removal of each ith indexed element costs us the arr[i].

For removal of two elements from the array, we get to remove one element for free but the free element should be less than the two costing elements.

The task is to find the minimum cost to remove all the elements from the array.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains the integer N.
Each of the following N lines contains a single integer Ai, the array elements
Constraints:
1 ≤ N ≤ 100000
1 ≤ Ai ≤ 100000
Time limit : 1 sec
Output Format:
The first and only line of output must contain the required minimal price .
Sample Input 1:
4
3
2
3
2
Sample Output 1:
8
Sample Input 2:
6
6
4
5
5
5
5
Sample Output 2:
21
Explanation:
Clarification of the first example: First remove 3, 3 and 2 for free, cost=6. Now only 2 is left, so the total cost=3+3+2=8
Clarification of the second example: First remove 6,5 and get 5 to remove for free.Then remove 5,5 and get to remove 4 for free.So total cost=6+5+5+5=21. */

#include <iostream>  // Include the iostream library for input and output operations
#include <vector>    // Include the vector library for using dynamic arrays
#include <algorithm> // Include the algorithm library for array manipulation

using namespace std;

// Function to read an array of integers from user input
vector<int> getArray()
{
    int n;
    cin >> n;           // Read the size of the array
    vector<int> arr(n); // Initialize the vector with the given size

    // Loop to fill the vector with input values
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read each integer and store it in the vector
    }
    return arr; // Return the filled vector
}

int main()
{
    vector<int> arr = getArray(); // Call getArray to read the array from input

    // Sort the vector in descending order using reverse iterators
    sort(arr.begin(), arr.end(), greater<int>());

    int sol = 0; // Initialize the solution variable to store the final result

    // Loop to calculate the sum, skipping every third element
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 3 == 2)
        { // If the index is a multiple of 3 (2nd, 5th, etc.), skip the element
            continue;
        }
        sol += arr[i]; // Add the element to the solution
    }

    // Print the final result
    cout << sol << endl;

    return 0;
}
