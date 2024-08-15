
/*
Problem statement
You have been given a random integer array/list(ARR) and a number X.
Find and return the number of triplets in the array/list which sum to X.

Note :
Given array/list can contain duplicate elements.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run.
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'X'.
Output format :
For each test case, print the total number of triplets present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 50
0 <= N <= 10^2
0 <= X <= 10^9
Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7
12
Sample Output 1:
5
Sample Input 2:
2
7
1 2 3 4 5 6 7
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5


 Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)

*/
#include <iostream>  // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

// Function to count the number of triplets whose sum is equal to a given value
// Parameters:
// input: Pointer to the array of integers
// size: Size of the array
// x: Target sum
// Returns: Number of triplets whose sum is equal to x
int tripletSum(int *input, int size, int x)
{
    int numTriplets = 0; // Initialize the count of triplets

    // Nested loops to iterate over all possible triplets
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                // If the sum of the current triplet is equal to x, increment the count
                if (input[i] + input[j] + input[k] == x)
                {
                    ++numTriplets;
                }
            }
        }
    }
    return numTriplets; // Return the count of triplets
}

// Main function
int main()
{
    int t;    // Declare a variable to store the number of test cases
    cin >> t; // Read the number of test cases from the standard input

    // Loop over each test case
    while (t--)
    {
        int size;    // Declare a variable to store the size of the array
        int x;       // Declare a variable to store the target sum
        cin >> size; // Read the size of the array from the standard input

        int *input = new int[size]; // Dynamically allocate memory for the array

        // Read the elements of the array from the standard input
        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }
        cin >> x; // Read the target sum from the standard input

        // Call the function to count the number of triplets whose sum is equal to x
        cout << tripletSum(input, size, x) << endl;

        delete[] input; // Free the dynamically allocated memory for the array
    }
    return 0; // Indicate successful completion of the program
}
