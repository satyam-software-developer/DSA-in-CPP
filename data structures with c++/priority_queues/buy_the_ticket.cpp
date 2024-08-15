
/* Problem statement
You want to buy a ticket for a well-known concert which is happening in your city. But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets to customers based on some priority.

A queue is maintained for buying the tickets and every person is attached with a priority (an integer, 1 being the lowest priority).

The tickets are sold in the following manner -

1. The first person (pi) in the queue requests for the ticket.
2. If there is another person present in the queue who has higher priority than pi, then ask pi to move at end of the queue without giving him the ticket.
3. Otherwise, give him the ticket (and don't make him stand in queue again).
Giving a ticket to a person takes exactly 1 second and it takes no time for removing and adding a person to the queue. And you can assume that no new person joins the queue.

Given a list of priorities of N persons standing in the queue and the index of your priority (indexing starts from 0). Find and return the time it will take until you get the ticket.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains an integer, that denotes the value of total number of people standing in queue or the size of the array of priorities. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array of priorities.
The following contains an integer, that denotes the value of index of your priority. Let us denote it with symbol k.
Output Format :
The first and only line of output contains the time required for you to get the ticket.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
3
3 9 4
2
Sample Output 1 :
2
Sample Output 1 Explanation :
Person with priority 3 comes out. But there is a person with higher priority than him. So he goes and then stands in the queue at the end. Queue's status :  {9, 4, 3}. Time : 0 secs.
Next, the person with priority 9 comes out. And there is no person with higher priority than him. So he'll get the ticket. Queue's status :  {4, 3}. Time : 1 secs.
Next, the person with priority 4 comes out (which is you). And there is no person with higher priority than you. So you'll get the ticket. Time : 2 secs.
Sample Input 2 :
5
2 3 2 2 4
3
Sample Output 2 :
4
 */

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Method to find the time it takes for a person at index k to get the ticket
int buyTicket(vector<int> &input, int k)
{
    // Queue to maintain the order of people
    queue<int> q;

    // Max-priority queue to keep track of the highest priority
    priority_queue<int> pq;

    // Initialize the queue and priority queue with the input values
    for (int i : input)
    {
        q.push(i);
        pq.push(i);
    }

    int count = 0; // Counter to track the number of tickets given

    // Process the queue until we find the ticket for the person at index k
    while (!pq.empty())
    {
        if (q.front() == pq.top())
        {
            // If the front person has the highest priority
            if (k == 0)
            {
                return count + 1; // Return the time (1-based index)
            }
            else
            {
                count++;  // Increment the count for each ticket given
                q.pop();  // Remove the person from the queue
                pq.pop(); // Remove the person from the priority queue
                k--;      // Adjust the index k
            }
        }
        else
        {
            // If the front person does not have the highest priority
            q.push(q.front()); // Move the front person to the end of the queue
            q.pop();           // Remove the person from the front of the queue
            if (k == 0)
            {
                k = q.size() - 1; // Adjust the index if it was at the front
            }
            else
            {
                k--; // Decrement the index k
            }
        }
    }

    return count; // This should never be reached
}

int main()
{
    int n; // Size of the array
    cin >> n;

    vector<int> input(n); // Initialize the input array with size n

    // Read the elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int k; // Index of the priority
    cin >> k;

    // Find the time for the person at index k to get the ticket and print it
    cout << buyTicket(input, k) << endl;

    return 0;
}
