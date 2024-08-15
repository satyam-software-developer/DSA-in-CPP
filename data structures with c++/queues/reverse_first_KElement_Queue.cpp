
/* Problem statement
For a given queue containing all integer data, reverse the first K elements.

You have been required to make the desired change in the input queue itself.

Example:
alt txt

For the above input queue, if K = 4 then after reversing the first 4 elements, the queue will be updated as:
alt txt

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input would contain two integers N and K, separated by a single space. They denote the total number of elements in the queue and the count with which the elements need to be reversed respectively.

The second line of input contains N integers separated by a single space, representing the order in which the elements are enqueued into the queue.
Output Format:
The only line of output prints the updated order in which the queue elements are dequeued, all of them separated by a single space. 
Note:
You are not required to print the expected output explicitly, it has already been taken care of. Just make the changes in the input queue itself.
Constraints :
1 <= N <= 10^6
1 <= K <= N
-2^31 <= data <= 2^31 - 1

 Time Limit: 1sec
Sample Input 1:
5 3
1 2 3 4 5
Sample Output 1:
3 2 1 4 5
Sample Input 2:
7 7
3 4 2 5 6 7 8
Sample Output 2:
8 7 6 5 2 4 3 */

/*
 * Time complexity: O(N)
 * Space complexity: O(K)
 *
 * where N is the size of the input queue and
 * K is the number of elements to reverse in the input queue
 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Struct to hold the input data
struct Input
{
    int n;        // Number of elements in the queue
    int k;        // Number of elements to reverse
    queue<int> q; // The queue itself

    // Constructor to initialize the input data
    Input(int n, int k, queue<int> q)
    {
        this->n = n; // Assign the number of elements
        this->k = k; // Assign the number of elements to reverse
        this->q = q; // Assign the queue
    }
};

// Function to reverse the first K elements of a queue
queue<int> reverseKElements(queue<int> &input, int k)
{
    // Check edge cases: empty queue, k greater than the size of the queue, or non-positive k
    if (input.empty() || k > input.size() || k <= 0)
    {
        return input; // Return the original queue if any condition is true
    }

    stack<int> st; // Initialize a stack to reverse elements

    // Push the first K elements from the queue into the stack
    for (int i = 0; i < k; i++)
    {
        st.push(input.front()); // Remove the element from the queue and push it onto the stack
        input.pop();
    }

    // Pop elements from the stack and add them back to the queue
    while (!st.empty())
    {
        input.push(st.top()); // Pop from the stack and add to the queue
        st.pop();
    }

    // Move the remaining elements (if any) from the front to the back of the queue
    int size = input.size() - k; // Calculate the number of remaining elements
    for (int i = 0; i < size; i++)
    {
        input.push(input.front()); // Remove the element from the front and add it to the back
        input.pop();
    }

    return input; // Return the modified queue
}

// Function to take input from the user
Input takeInput()
{
    int n, k;
    cin >> n >> k; // Read the number of elements and the number of elements to reverse

    queue<int> q; // Initialize a new queue

    // Read 'n' elements and add them to the queue
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;  // Read an element
        q.push(val); // Add the element to the queue
    }

    // Return an Input object containing the number of elements, number of elements to reverse, and the queue
    return Input(n, k, q);
}

int main()
{
    Input input = takeInput(); // Call takeInput function to get user input

    int n = input.n;        // Get the number of elements from the input
    int k = input.k;        // Get the number of elements to reverse from the input
    queue<int> q = input.q; // Get the queue from the input

    q = reverseKElements(q, k); // Call reverseKElements function to reverse the first K elements of the queue

    // Print the elements of the modified queue
    while (!q.empty())
    {
        cout << q.front() << " "; // Print the front element of the queue
        q.pop();                  // Remove the front element
    }

    return 0;
}
