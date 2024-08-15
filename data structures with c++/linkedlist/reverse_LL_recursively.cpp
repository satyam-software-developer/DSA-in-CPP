
/*Problem statement
Given a singly linked list of integers, reverse it using recursion and return the head to the modified list. You have to do this in O(N) time complexity where N is the size of the linked list.

 Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^4
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
Sample Output 1 :
8 7 6 5 4 3 2 1
Sample Input 2 :
2
10 -1
10 20 30 40 50 -1
Sample Output 2 :
10 
50 40 30 20 10  */

/*
 *  Time Complexity : O(n)
 *  Space Complexity : O(n)
 * Where 'n' is size of the Singly Linked List
 */
#include <iostream>
using namespace std;

// Node class representing a node in the linked list
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize a node with given data
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
        cin >> data;
    }
    return head;
}

// Function to print the linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to reverse a linked list recursively
Node *reverseLinkedListRec(Node *head)
{
    // Base case: if the list is empty or has only one node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // Reverse the rest of the list
    Node *smallhead = reverseLinkedListRec(head->next);
    // Reverse the link between the current node and the next node
    head->next->next = head;
    head->next = NULL;
    // Return the new head of the reversed list
    return smallhead;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput(); // Take input for the linked list
        head = reverseLinkedListRec(head); // Reverse the linked list recursively
        print(head); // Print the reversed linked list
    }

    return 0;
}
