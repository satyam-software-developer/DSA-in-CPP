
/*Problem statement
For a given singly linked list of integers, find and return the node present at the middle of the list.

Note :
If the length of the singly linked list is even, then return the first middle node.

Example: Consider, 10 -> 20 -> 30 -> 40 is the given list, then the nodes present at the middle with respective data values are, 20 and 30. We return the first node with data 20.
Detailed explanation ( Input/output format, Notes, Images )
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
 Output Format :
For each test case/query, print the data value of the node at the middle of the given list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 2 3 4 5 -1
Sample Output 1 :
3
Sample Input 2 :
2
-1
1 2 3 4 -1
Sample Output 2 :
2 */

/*
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * Where 'n' is the size of the Singly Linked list
 */

#include <iostream>
using namespace std;

// Node class to represent elements of the linked list
class Node
{
public:
    int data;   // Data of the node
    Node *next; // Pointer to the next node

    // Constructor to initialize the node with data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to take input for the linked list
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;

    // Read input until -1 is encountered
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data; // Read next input
    }
    return head; // Return the head of the linked list
}

// Function to find the middle point of the linked list
Node *midPoint(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head; // If the list is empty or has only one element, return the head itself as the middle point
    }
    Node *slow = head;       // Slow pointer initially at the head
    Node *fast = head->next; // Fast pointer initially one step ahead of slow

    // Move slow pointer one step and fast pointer two steps until fast pointer reaches the end of the list
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps
    }
    return slow; // Return the node where slow pointer is pointing, which is the middle point
}

int main()
{
    int t;
    cin >> t; // Read the number of test cases
    while (t--)
    {
        Node *head = takeinput();   // Take input for the linked list
        Node *mid = midPoint(head); // Find the middle point of the linked list
        if (mid != NULL)
        {
            cout << mid->data; // Print the data of the middle node
        }
        cout << endl; // Print a new line after each test case
    }
    return 0;
}
