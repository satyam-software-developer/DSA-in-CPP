
/*Problem statement
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.

Time complexity should be O(n * logk) and space complexity should not be more than O(k).

Note: Order of elements in the output is not important.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of k.
Output Format :
The first and only line of output print k smallest elements. The elements in the output are separated by a single space.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6
4
Sample Output 1 :
1 2 3 5
 */

/*
 * Time complexity: O(N * log(K))
 * Space complexity: O(K)
 *
 * where N is the size of the input array
 * and K is the number of smallest elements that are to be found
 */

#include <iostream>  // For standard I/O operations
#include <queue>     // For using priority queue (max-heap)
#include <vector>    // For using vector to store the k smallest elements
#include <algorithm> // For using the sort function

using namespace std;

// Function to find the k smallest elements in the input array
vector<int> kSmallest(int n, vector<int> &input, int k)
{
    // Create a max-priority queue (max-heap) to keep track of the k smallest elements
    priority_queue<int> pq;

    // Add the first k elements of the input array to the priority queue
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }

    // Process the remaining elements of the input array
    for (int i = k; i < n; i++)
    {
        // If the current element is smaller than the largest element in the priority queue
        if (input[i] < pq.top())
        {
            pq.pop();          // Remove the largest element from the priority queue
            pq.push(input[i]); // Add the current element to the priority queue
        }
    }

    // Create a vector to store the k smallest elements
    vector<int> output;

    // Remove elements from the priority queue and add them to the output vector
    while (!pq.empty())
    {
        output.push_back(pq.top());
        pq.pop();
    }

    // Sort the output vector to ensure the elements are in ascending order
    sort(output.begin(), output.end());

    // Return the vector of k smallest elements
    return output;
}

int main()
{
    int n;
    cin >> n; // Read the size of the input array

    vector<int> input(n); // Initialize the input vector with size n

    // Read the elements of the input array
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k;
    cin >> k; // Read the value of k

    // Find the k smallest elements in the input array
    vector<int> output = kSmallest(n, input, k);

    // Print the k smallest elements separated by spaces
    for (int i : output)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
