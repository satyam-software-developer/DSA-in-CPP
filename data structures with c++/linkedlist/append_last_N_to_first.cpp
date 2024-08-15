/* Problem statement
You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.

Hint:
Identify how many pointers you require and try traversing them to right places and connect nodes accordingly also don't forget to disconnect what's required else it could create cycles.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line contains the integer value 'N'. It denotes the number of nodes to be moved from last to the front of the singly linked list.
Output format :
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
0 <= N < M
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Sample Input 1 :
2
1 2 3 4 5 -1
3
10 20 30 40 50 60 -1
5
Sample Output 1 :
3 4 5 1 2
20 30 40 50 60 10
Sample Input 2 :
1
10 6 77 90 61 67 100 -1
4
Sample Output 2 :
90 61 67 100 10 6 77
 Explanation to Sample Input 2 :
We have been required to move the last 4 nodes to the front of the list. Here, "90->61->67->100" is the list which represents the last 4 nodes. When we move this list to the front then the remaining part of the initial list which is, "10->6->77" is attached after 100. Hence, the new list formed with an updated head pointing to 90.
*/

/*
   Time Complexity : O(n)
   Space Complexity : O(1)
   Where 'n' is the size of the Singly Linked List

 */

#include <iostream>
using namespace std;

// Define a class for the nodes of the linked list
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize the node with data
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to take input and create a linked list
Node *takeinput()
{
    int data;
    // Read the first integer
    cin >> data;

    // Initialize head and tail pointers to NULL
    Node *head = NULL, *tail = NULL;

    // Loop to create nodes and link them
    while (data != -1)
    {
        // Create a new node with the integer data
        Node *newnode = new Node(data);

        // If head is NULL, set the new node as head and tail
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            // Otherwise, link the new node to the existing list and update the tail
            tail->next = newnode;
            tail = newnode;
        }

        // Read the next integer
        cin >> data;
    }

    // Return the head of the linked list
    return head;
}

// Function to print the linked list
void print(Node *head)
{
    // Initialize a temporary pointer to the head of the list
    Node *temp = head;

    // Loop through the list and print each node's data
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Move to the next line after printing all nodes
    cout << endl;
}

// Function to append the last N nodes to the beginning of the linked list
Node *appendLastNToFirst(Node *head, int n)
{
    // Return if the list is empty or n is zero
    if (n == 0 || head == NULL)
    {
        return head;
    }

    // Initialize fast and slow pointers to head
    Node *fast = head;
    Node *slow = head;
    Node *initialHead = head;

    // Move fast pointer to the Nth node
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    // Move both pointers till fast reaches the end
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Store the new head after appending
    Node *temp = slow->next;
    // Disconnect the list from the slow pointer
    slow->next = NULL;
    // Connect the end of the list to the initial head
    fast->next = initialHead;
    // Update the head of the modified list
    head = temp;

    // Return the new head of the modified list
    return head;
}

// Main method to execute the program
int main()
{
    // Read the number of test cases
    int t;
    cin >> t;

    // Loop through each test case
    while (t--)
    {
        // Take input for the linked list
        Node *head = takeinput();
        // Read the value of N
        int n;
        cin >> n;

        // Append the last N nodes to the first
        head = appendLastNToFirst(head, n);
        // Print the modified linked list
        print(head);
    }

    // Exit the program
    return 0;
}
