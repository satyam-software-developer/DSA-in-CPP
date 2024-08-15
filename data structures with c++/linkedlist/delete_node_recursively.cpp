
/*Problem statement
Given a singly linked list of integers and position 'i', delete the node present at the 'i-th' position in the linked list recursively.

 Note :
Assume that the Indexing for the linked list always starts from 0.

No need to print the list, it has already been taken care. Only return the new head to the list.
Detailed explanation ( Input/output format, Notes, Images )
 input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'i'.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M

Time Limit:  2 sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Sample Input 2 :
2
30 -1
0
10 20 30 50 60 -1
4
Sample Output 2 :
10 20 30 50  */

/*
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 * Where 'n' is size of the Singly  Linked List
 */

#include <iostream>
using namespace std;

// Node class representing a node in the linked list
class Node
{
public:
    int data;
    Node *next;
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
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
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

// Function to delete a node recursively at the given position
Node *deleteNodeRec(Node *head, int pos)
{
    // If the list is empty or position is invalid, return head
    if (head == NULL || pos < 0)
    {
        return head;
    }
    // If position is 0, return the next node (delete the current node)
    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    // Recursively call the function for the next node with decremented position
    Node *smallHead = deleteNodeRec(head->next, pos - 1);
    head->next = smallHead;
    return head;
}

int main()
{
    int t;
    cin >> t; // Number of test cases

    while (t--)
    {
        Node *head = takeinput(); // Take input for the linked list
        int pos;
        cin >> pos; // Position of node to delete
        head = deleteNodeRec(head, pos); // Delete node recursively
        print(head); // Print the modified linked list
    }

    return 0;
}
