
/*
Problem statement
You have been given two sorted arrays/lists(ARR1 and ARR2) of size N and M respectively, 
merge them into a third array/list such that the third array is also sorted.

Note:
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. 
Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements of the first array/list.

Third line contains an integer 'M' representing the size of the second array/list.

Fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output Format :
For each test case, print the sorted array/list(of size N + M) in a single row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
0 <= M <= 10^5
Time Limit: 1 sec 
Note:
Consider the case when size of the two arrays is not same.
Sample Input 1 :
1
5
1 3 4 7 11
4
2 4 6 13
Sample Output 1 :
1 2 3 4 4 6 7 11 13 
Sample Input 2 :
2
3
10 100 500
7
4 7 9 25 30 300 450
4
7 45 89 90
0
Sample Output 2 :
4 7 9 10 25 30 100 300 450 500
7 45 89 90

*/

#include <iostream> // Include the input-output stream header file for standard input and output operations.

using namespace std; // Using the standard namespace to avoid having to prefix standard functions and objects with "std::".

void merge(int arr1[], int size1, int arr2[], int size2, int ans[])
{
    // Function to merge two sorted arrays into one sorted array.
    int i = 0, j = 0, k = 0; // Initialize indices for arr1, arr2, and ans arrays respectively.
    while (i < size1 && j < size2) // Loop until either of the arrays is fully traversed.
    {
        if (arr1[i] < arr2[j]) // If the current element of arr1 is smaller.
        {
            ans[k] = arr1[i]; // Store the element in the ans array.
            i++; // Move to the next element in arr1.
            k++; // Move to the next index in ans.
        }
        else // If the current element of arr2 is smaller or equal.
        {
            ans[k] = arr2[j]; // Store the element in the ans array.
            j++; // Move to the next element in arr2.
            k++; // Move to the next index in ans.
        }
    }

    // Copy remaining elements of arr1 if any.
    while (i < size1)
    {
        ans[k] = arr1[i]; // Copy the element to ans.
        i++; // Move to the next element in arr1.
        k++; // Move to the next index in ans.
    }

    // Copy remaining elements of arr2 if any.
    while (j < size2)
    {
        ans[k] = arr2[j]; // Copy the element to ans.
        j++; // Move to the next element in arr2.
        k++; // Move to the next index in ans.
    }
}

void printArray(int input[], int n)
{
    // Function to print the elements of an array.
    for (int i = 0; i < n; i++) // Iterate over each element of the array.
    {
        cout << input[i] << " "; // Output the current element followed by a space.
    }
    cout << endl; // Output an end-of-line character after printing all elements.
}

int main()
{
    // Main function, entry point of the program.

    int t; // Declare a variable to store the number of test cases.
    cin >> t; // Read the number of test cases from the user.

    while (t--) // Loop through each test case.
    {
        int size1; // Declare a variable to store the size of the first array.
        cin >> size1; // Read the size of the first array from the user.

        int arr1[size1]; // Declare an array to store the elements of the first array.

        // Read elements of the first array from the user.
        for (int i = 0; i < size1; i++) // Iterate over each element of the first array.
        {
            cin >> arr1[i]; // Read an element from the user and store it in the first array.
        }

        int size2; // Declare a variable to store the size of the second array.
        cin >> size2; // Read the size of the second array from the user.

        int arr2[size2]; // Declare an array to store the elements of the second array.

        // Read elements of the second array from the user.
        for (int i = 0; i < size2; i++) // Iterate over each element of the second array.
        {
            cin >> arr2[i]; // Read an element from the user and store it in the second array.
        }

        int ans[size1 + size2]; // Declare an array to store the merged array.

        merge(arr1, size1, arr2, size2, ans); // Call the merge function to merge the two arrays.

        // Print the merged array.
        for (int i = 0; i < size1 + size2; i++) // Iterate over each element of the merged array.
        {
            cout << ans[i] << " "; // Output each element of the merged array followed by a space.
        }

        cout << endl; // Output an end-of-line character after printing the merged array.
    }

    return 0; // Return 0 to indicate successful execution of the program.
}
