
/*Problem statement
We are given an array of length N.We have to remove an element from the array, such that the sum of resultant array is even.

Find the possible number of ways to convert the array sum even by removing one element from the array.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
First line contains the integer N denoting the size of the array.
Next line contains N spaced integers denoting the array elements.
(Note:All elements are distinct)
Output Format:
Print the possible number of ways for even array sum.
Constraints:
1 <= N <= 10^7
-10^9 <= arr[i] <= 10^9
Sample Input 1:
4
1 3 2 5
Sample Output 1:
3
Explanation:
 Removing 1,3 or 5 would result in even sum of the array. */
 
#include <iostream>
#include <vector>

using namespace std;

// Function to count the number of ways to choose a subset of the array
// such that the sum of its elements is even.
int countWays(const vector<int> &arr)
{
    int even = 0, odd = 0; // Initialize counters for even and odd numbers.

    // Loop through the array to count the number of even and odd elements.
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 2 == 0)
        {           // Check if the element is even.
            even++; // Increment the even counter.
        }
        else
        {          // If the element is not even, it is odd.
            odd++; // Increment the odd counter.
        }
    }

    // If the number of odd elements is even, we can pair them up
    // to make the sum even, so return the number of even elements.
    if (odd % 2 == 0)
    {
        return even;
    }
    else
    {
        // If the number of odd elements is odd, we can only get an even sum
        // by including all odd elements, so return the number of odd elements.
        return odd;
    }
}

int main()
{
    int n;
    cin >> n; // Read the integer value n (size of the array).

    vector<int> arr(n); // Declare a vector of size n.

    // Loop to read n integers into the array.
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Store each integer in the array.
    }

    // Print the result of countWays, which is the number of ways
    // to choose a subset with an even sum.
    cout << countWays(arr) << endl;

    return 0;
}
