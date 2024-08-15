
/* Problem statement
An array is Rainbow if it has the following structure:

1.  First a1 elements equal 1.
2.  Next a2 elements equal 2.
3.  Next a3 elements equal 3.
4.  Next a4 elements equal 4.
5.  Next a5 elements equal 5.
6.  Next a6 elements equal 6.
7.  Next a7 elements equal 7.
8.  Next a6 elements equal 6.
9.  Next a5 elements equal 5.
10. Next a4 elements equal 4.
11. Next a3 elements equal 3.
12. Next a2 elements equal 2.
13. Next a1 elements equal 1.
(Here a1,a2,a3... are number of elements).
14. ai can be any non-zero positive integer.
15. There are no other elements in array.
Find out if the given array is a Rainbow Array or not.

Input:
The first line of contains an integer N, denoting the number of elements in the given array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of array.
Output:
 Output a line containing "yes" or "no" (without quotes) corresponding to the case if the array is rainbow array or not.
Constraints:
7 ≤ N ≤ 100
1 ≤ Ai ≤ 10
Sample Input 1:
19
1 2 3 4 4 5 6 6 6 7 6 6 6 5 4 4 3 2 1
Sample output 1:
Yes
Sample input 2:
12
1 2 3 4 5 6 6 5 4 3 2 1
Sample output 2:
No
(has no elements with value 7 after elements with value 6.)
Sample output 3:
14
1 1 2 3 4 5 6 7 6 5 4 3 2 1
Sample output 3:
No
(On the left we have two occurrences of 1, whereas on the right only one occurrence ).  */

#include <iostream>
#include <vector>
using namespace std;

// Function to check if the given array is a "rainbow" array
void israinbow(vector<int> &arr)
{
    int N = arr.size(); // Length of the array

    // If the length of the array is less than 13, it cannot be a rainbow array
    if (N < 13)
    {
        cout << "no" << endl;
        return;
    }

    int start = 0;   // Starting index of the array
    int end = N - 1; // Ending index of the array

    bool isValid = true; // Flag to track if the array is a valid rainbow array

    int cur = 0; // Variable to track the current expected number in the sequence

    // Loop to traverse the array from both ends towards the center
    while (start != end && start < end)
    {

        // Check if elements at corresponding positions from start and end are equal
        if (arr[start] != arr[end])
        {
            isValid = false;
            break;
        }

        // Check if the current element is out of the valid range (1 to 7)
        if (arr[start] < 1 || arr[start] > 7)
        {
            isValid = false;
            break;
        }

        // Check if the current element matches the expected sequence
        if (arr[start] != cur)
        {
            // If the current element is not the next expected value in the sequence, it's invalid
            if (arr[start] != cur + 1)
            {
                isValid = false;
                break;
            }
            else
            {
                // Update the current expected value
                cur = arr[start];
            }
        }
        // Move start index forward and end index backward
        start++;
        end--;
    }

    // After the loop, check if the last element is 7 or if the sequence reached 7 and is valid
    if ((arr[start] == 7 || cur == 7) && isValid)
    {
        cout << "yes" << endl; // It's a valid rainbow array
    }
    else
    {
        cout << "no" << endl; // It's not a valid rainbow array
    }
}

int main()
{
    int n;
    cin >> n;         // Read the size of the array
    vector<int> a(n); // Initialize the array with the given size

    // Read the elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Call the function to check if the array is a rainbow array
    israinbow(a);

    return 0;
}
