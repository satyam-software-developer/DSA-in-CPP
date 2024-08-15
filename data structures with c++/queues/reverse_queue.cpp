
/* Problem statement
You have been given a queue that can store integers as the data. You are required to write a function that reverses the populated queue itself without using any other data structures.

Example:
Alt txt

Alt txt

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first list of input contains an integer 't' denoting the number of test cases/queries to be run.
Then the test cases follow.

The first line input for each test case/query contains an integer N, denoting the total number of elements in the queue.

The second line of input contains N integers separated by a single space, representing the order in which the elements are enqueued into the queue.
Output Format:
For each test case/query, the only line of output prints the order in which the queue elements are dequeued, all of them separated by a single space.

Output for every test case/query will be printed on a new line.
Note:
You are not required to print the expected output explicitly, it has already been taken care of. Just make the changes in the input queue itself.
Constraints:
1 <= t <= 100
1 <= N <= 10^4
-2^31 <= data <= 2^31 - 1

Time Limit: 1sec
Sample Input 1:
1
6
1 2 3 4 5 10
Note:
Here, 1 is at the front and 10 is at the rear of the queue.
Sample Output 1:
10 5 4 3 2 1
Sample Input 2:
2
5
2 8 15 1 10
3
10 20 30
Sample Output 2:
10 1 15 8 2
30 20 10  */

/*
 * Time complexity: O(N)
 * Space complexity: O(N)
 *
 * where N is the size of the input queue
 */

#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    // Base case: if the queue has 0 or 1 element, it is already reversed
    if (q.size() <= 1)
    {
        return;
    }

    // Remove the front element
    int front = q.front();
    q.pop();

    // Recursively reverse the remaining queue
    reverseQueue(q);

    // Add the removed element to the back of the queue
    q.push(front);
}

queue<int> takeInput()
{
    int n;
    cin >> n;

    // Initialize a new queue
    queue<int> q;

    // Read 'n' elements and add them to the queue
    for (int i = 0; i < n; i++)
    {
        int var;
        cin >> var;
        q.push(var);
    }

    return q;
}

int main()
{
    int t;
    cin >> t;

    // Loop through all test cases
    while (t > 0)
    {
        // Take input to create the queue
        queue<int> q = takeInput();

        // Reverse the queue
        reverseQueue(q);

        // Print the reversed queue
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }

        // Print a new line after each test case
        cout << endl;

        // Decrement the test case counter
        t -= 1;
    }

    return 0;
}
