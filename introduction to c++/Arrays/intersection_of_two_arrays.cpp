
/*
Problem statement
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively.
You need to print their intersection; An intersection for this problem can be defined
when both the arrays/lists contain a particular value or to put it in other words,
when there is a common value that exists in both the arrays/lists.

Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the first array/list(ARR1)

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements of the first the array/list.

Third line contains an integer 'M' representing the size of the second array/list.

Fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
For each test case, print the intersection elements in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= M <= 10^3
Time Limit: 1 sec
Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7
2
10 10
1
10
Sample Output 1 :
2 4 3
10
Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
2 1 2
Explanation for Sample Output 2 :
Since, both input arrays have two '2's,
the intersection of the arrays also have two '2's.
The first '2' of first array matches with the first '2' of the second array.
Similarly, the second '2' of the first array matches with the second '2' if the second array.

*/

#include <iostream>  // Include the necessary header file for input and output operations
#include <climits>   // Include the necessary header file for using INT_MIN constant
using namespace std; // Using the standard namespace to simplify code

// Function to find and print the intersection of two arrays
void intersection(int *input1, int *input2, int size1, int size2)
{
    // Iterate through the elements of the first array
    for (int i = 0; i < size1; i++)
    {
        // Iterate through the elements of the second array
        for (int j = 0; j < size2; j++)
        {
            // If there is a common element, print it and mark the element in the second array as visited
            if (input1[i] == input2[j])
            {
                cout << input1[i] << " "; // Print the common element
                input2[j] = INT_MIN;      // Mark the element as visited by assigning INT_MIN
                break;                    // Break the inner loop to avoid printing duplicate common elements
            }
        }
    }
}

// Main function
int main()
{
    int t;    // Declare a variable to store the number of test cases
    cin >> t; // Read the number of test cases from the standard input

    // Iterate over each test case
    while (t--)
    {
        int size1, size2; // Declare variables to store the sizes of the arrays for the current test case

        // Read the size of the first array and allocate memory for it
        cin >> size1;
        int *input1 = new int[size1];

        // Read the elements of the first array from the standard input
        for (int i = 0; i < size1; i++)
        {
            cin >> input1[i];
        }

        // Read the size of the second array and allocate memory for it
        cin >> size2;
        int *input2 = new int[size2];

        // Read the elements of the second array from the standard input
        for (int i = 0; i < size2; i++)
        {
            cin >> input2[i];
        }

        // Call the function to find and print the intersection of the two arrays
        intersection(input1, input2, size1, size2);

        // Deallocate memory for both arrays to avoid memory leaks
        delete[] input1;
        delete[] input2;

        cout << endl; // Print a newline after processing each test case
    }

    return 0; // Indicate successful completion of the program
}
