
/* Problem statement
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. 
You need to print their intersection; An intersection for this problem can be defined when both 
the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.

Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in ascending order.


Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
For each test case, print the intersection elements in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= M <= 10^4

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
2 3 4
10
Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 2 2
Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. 
The first '2' of first array matches with the first '2' of the second array. 
Similarly, the second '2' of the first array matches with the second '2' if the second array.
*/
#include <iostream>
#include <algorithm> // Included for using the sort algorithm
using namespace std;

// Function to find the intersection of two sorted arrays
void intersection(int *arr1, int *arr2, int n, int m)
{
    // Sorting both arrays to perform intersection efficiently
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    int i = 0; // Pointer to iterate over arr1
    int j = 0; // Pointer to iterate over arr2

    // Loop until one of the arrays is exhausted
    while(i < n && j < m)
    {
        // If the elements are equal, print the common element
        if(arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        // If the element in arr1 is less than the element in arr2, move to the next element in arr1
        else if(arr1[i] < arr2[j])
        {
            i++;
        }
        // If the element in arr2 is less than the element in arr1, move to the next element in arr2
        else
        {
            j++;
        }
    }
}

int main()
{
    int t;
    cin >> t; // Input number of test cases
    while (t--)
    {
        int size1, size2;

        // Input size and elements of the first array
        cin >> size1;
        int *input1 = new int[size1];
        for (int i = 0; i < size1; i++)
        {
            cin >> input1[i];
        }

        // Input size and elements of the second array
        cin >> size2;
        int *input2 = new int[size2];
        for (int i = 0; i < size2; i++)
        {
            cin >> input2[i];
        }

        // Find and print the intersection of the two arrays
        intersection(input1, input2, size1, size2);

        // Free the memory allocated for the arrays
        delete[] input1;
        delete[] input2;

        cout << endl; // Output a new line for the next test case
    }

    return 0;
}
