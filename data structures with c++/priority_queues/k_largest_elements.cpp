
/* Problem statement
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.

Time complexity should be O(nlogk) and space complexity should be not more than O(k).

Order of elements in the output is not important.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k
Output Format :
k largest elements
Sample Input :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4
Sample Output :
12
16
20
25 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to find the k largest elements in the input array
vector<int> kLargest(vector<int> &input, int k)
{
    // Min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> pq;

    // Add the first k elements of the input array to the priority queue
    for (int i = 0; i < k; ++i)
    {
        pq.push(input[i]);
    }

    // Process the remaining elements of the input array
    for (int i = k; i < input.size(); ++i)
    {
        // If the current element is greater than the smallest element in the priority queue
        if (input[i] > pq.top())
        {
            pq.pop();          // Remove the smallest element
            pq.push(input[i]); // Add the current element
        }
    }

    // Create a vector to store the k largest elements
    vector<int> output;

    // Remove elements from the priority queue and add them to the output vector
    while (!pq.empty())
    {
        output.push_back(pq.top());
        pq.pop();
    }

    // Return the list of k largest elements
    return output;
}

int main()
{
    int n;
    cin >> n;

    // Initialize the input vector
    vector<int> input(n);

    // Read the elements of the input vector
    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }

    // Read the value of k
    int k;
    cin >> k;

    // Find the k largest elements in the input vector
    vector<int> output = kLargest(input, k);

    // Print the k largest elements
    for (int i : output)
    {
        cout << i << " " << endl;
    }

    return 0;
}
