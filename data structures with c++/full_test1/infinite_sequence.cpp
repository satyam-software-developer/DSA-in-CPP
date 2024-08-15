
/* Problem statement
Amit decided to write an infinite sequence. Initially, he wrote 0, and then he started repeating the following process:

* Look at the last element written so far (the l-th element if the sequence has length l so far); let's denote it by x.
*If x does not occur anywhere earlier in the sequence, the next element in the sequence is 0.
*Otherwise, look at the previous occurrence of x in the sequence, i.e. the k-th element, where k<l, this element is equal to x and all elements between the k+1-th and l−1-th are different from x. The next element is l−k, i.e. the distance between the last two occurrences of x.
The resulting sequence is (0,0,1,0,2,0,2,2,1,…): the second element is 0 since 0 occurs only once in the sequence (0), the third element is 1 since the distance between the two occurrences of 0 in the sequence (0,0) is 1, the fourth element is 0 since 1 occurs only once in the sequence (0,0,1), and so on.

Consider the N-th element of the sequence (denoted by x) and the first N elements of the sequence. Find the number of occurrences of x among these N elements.

Input :
The first and only line contains a single integer N.
Output :
 print a single line containing one integer ― the number of occurrences of the N-th element.
Sample Input :
2
Output :
2
Explanation:
(The 2-nd element is 0. It occurs twice among the first two elements, since the first two elements are both 0.) */


#include <iostream>
#include <vector>

using namespace std;

// Function to find the index of the last occurrence of 'x' before the given 'index'
int search(const vector<int> &a, int x, int index)
{
    // Iterate backwards from the position before 'index' to find the last occurrence of 'x'
    for (int i = index - 2; i >= 0; i--)
    {
        if (a[i] == x)
        {
            return i; // Return the index if 'x' is found
        }
    }
    return -1; // Return -1 if 'x' is not found
}

int main()
{
    vector<int> a(128); // Vector to store the sequence, size is 128
    a[0] = 0;           // Initialize the first element of the sequence to 0

    // Generate the sequence up to index 127
    for (int i = 1; i < 128; i++)
    {
        // Find the last occurrence of the value before the current index
        int index = search(a, a[i - 1], i);
        // If the value is not found, set the current element to 0
        if (index == -1)
            a[i] = 0;
        else
            // Otherwise, set the current element to the difference between the current index and the last occurrence index
            a[i] = i - index - 1;
    }

    // Read the integer 'n' which represents the number of elements to consider in the sequence
    int n;
    cin >> n;

    // Variable to count occurrences of the value at index 'n - 1' in the first 'n' elements of the sequence
    int count = 0;

    // Iterate through the first 'n' elements of the sequence
    for (int i = 0; i < n; i++)
    {
        // If the current element equals the value at index 'n - 1', increment the count
        if (a[i] == a[n - 1])
            count++;
    }

    // Print the count of occurrences of the value at index 'n - 1'
    cout << count << endl;

    return 0;
}
