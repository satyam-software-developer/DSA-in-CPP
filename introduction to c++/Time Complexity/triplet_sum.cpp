
/* Problem statement
You have been given a random integer array/list(ARR) and a number X. 
Find and return the triplet(s) in the array/list which sum to X.

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
1 <= t <= 10^2
0 <= N <= 10^3
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

/*
   Time Complexity : O(n^2)
   Space Complexity : O(1)

   Where n is size of Array/List

*/

#include <iostream>
#include<algorithm> // Include the header file for using the sort() function
using namespace std;

// Function to calculate the number of pairs with the given sum within a specific range of the array
int pairSum(int *arr, int startIndex, int endIndex, int num)
{
    int numPair = 0; // Initialize the count of pairs

    // Loop until the start index is less than the end index
    while (startIndex < endIndex)
    {
        // If the sum of elements at the start and end indices is less than the target number
        if (arr[startIndex] + arr[endIndex] < num)
        {
            startIndex++; // Move the start index forward
        }
        // If the sum of elements at the start and end indices is greater than the target number
        else if (arr[startIndex] + arr[endIndex] > num)
        {
            endIndex--; // Move the end index backward
        }
        else // If the sum of elements at the start and end indices is equal to the target number
        {
            int elementAtStart = arr[startIndex];
            int elementAtEnd = arr[endIndex];

            // If both elements are equal
            if (elementAtStart == elementAtEnd)
            {
                int totalElementsFromStartToEnd = (endIndex - startIndex) + 1;
                // Calculate the number of pairs formed by these occurrences
                numPair += (totalElementsFromStartToEnd * (totalElementsFromStartToEnd - 1)) / 2;

                return numPair; // Return the total count of pairs
            }

            // Move the start index to the next distinct element
            int tempStartIndex = startIndex + 1;
            while (tempStartIndex <= endIndex && arr[tempStartIndex] == elementAtStart)
            {
                tempStartIndex++;
            }
            // Move the end index to the previous distinct element
            int tempEndIndex = endIndex - 1;
            while (tempEndIndex >= startIndex && arr[tempEndIndex] == elementAtEnd)
            {
                tempEndIndex--;
            }

            // Calculate the number of elements from the start and end indices
            int totalElementsFromStart = (tempStartIndex - startIndex);
            int totalElementsFromEnd = (endIndex - tempEndIndex);

            // Update the count of pairs
            numPair += (totalElementsFromStart * totalElementsFromEnd);

            startIndex = tempStartIndex; // Update the start index
            endIndex = tempEndIndex; // Update the end index
        }
    }
    return numPair; // Return the total count of pairs
}

// Function to calculate the number of triplets with the given sum in the array
int tripletSum(int *arr, int n, int num)
{
    sort(arr, arr + n); // Sort the array in non-decreasing order

    int numTriplets = 0; // Initialize the count of triplets

    // Iterate over each element of the array
    for (int i = 0; i < n; i++)
    {
        int pairSumFor = num - arr[i]; // Calculate the sum required for pairs
        int numPairs = pairSum(arr, (i + 1), (n - 1), pairSumFor); // Calculate the number of pairs with the sum

        numTriplets += numPairs; // Update the count of triplets
    }
    return numTriplets; // Return the total count of triplets
}

// Main function
int main()
{
    int t;
    cin >> t; // Input the number of test cases

    while (t--)
    {
        int size, x;
        cin >> size; // Input the size of the array

        int *input = new int[size]; // Dynamically allocate memory for the array

        // Input the elements of the array
        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }
        cin >> x; // Input the target sum 'x'

        // Output the number of triplets with the given sum
        cout << tripletSum(input, size, x) << endl;

        delete[] input; // Free the dynamically allocated memory
    }

    return 0;
}
