
/*
Problem statement
You have been given an integer array/list(ARR) and a number X. 
Find and return the total number of pairs in the array/list which sum to X.

Note:
Given array/list can contain duplicate elements. 
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'X'.
Output format :
For each test case, print the total number of pairs present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9
Time Limit: 1 sec
Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7
Sample Output 1:
7
Sample Input 2:
2
9
1 3 6 2 5 4 3 2 4
12
6
2 8 10 5 -2 5
10
Sample Output 2:
0
2


 Explanation for Input 2:
Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).

*/

#include <iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

// Function to count pairs whose sum equals x
// Parameters:
// input: Pointer to the array of integers
// size: Size of the array
// x: Target sum to find pairs
// Returns: Number of pairs whose sum equals x
int pairSum(int *input, int size, int x)
{
    int numPairs = 0; // Initialize the count of pairs to 0
    // Iterate over each element of the array
    for (int i = 0; i < size; i++)
    {
        // Iterate over the elements after the current element
        for (int j = i + 1; j < size; j++)
        {
            // Check if the sum of the current pair equals x
            if (input[i] + input[j] == x)
            {
                ++numPairs; // Increment the count of pairs
            }
        }
    }
    return numPairs; // Return the total count of pairs whose sum equals x
}

// Main function
int main()
{
    int t; // Declare a variable to store the number of test cases
    cin >> t; // Read the number of test cases from the standard input

    // Iterate over each test case
    while (t--)
    {
        int size; // Declare a variable to store the size of the array
        int x; // Declare a variable to store the target sum
        cin >> size; // Read the size of the array from the standard input
        int *input = new int[size]; // Dynamically allocate memory for the array

        // Read the elements of the array from the standard input
        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cin >> x; // Read the target sum from the standard input

        // Call the pairSum function to count pairs whose sum equals x and print the result
        cout << pairSum(input, size, x) << endl;

        delete[] input; // Free the dynamically allocated memory to avoid memory leaks
    }
    return 0; // Indicate successful completion of the program
}
