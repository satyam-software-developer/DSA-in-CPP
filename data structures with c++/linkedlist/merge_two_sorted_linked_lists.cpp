
/* Problem statement
You have been given two sorted(in ascending order) singly linked lists of integers.

Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.

Note :
Try solving this in O(1) auxiliary space.

No need to print the list, it has already been taken care.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space. 

The second line of the input contains the elements of the second sorted singly linked list separated by a single space. 
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output :
For each test case/query, print the resulting sorted singly linked list, separated by a single space.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t = 10^2
0 <= N <= 10 ^ 4
0 <= M <= 10 ^ 4
Where N and M denote the sizes of the singly linked lists. 

Time Limit: 1sec
Sample Input 1 :
1
2 5 8 12 -1
3 6 9 -1
Sample Output 1 :
2 3 5 6 8 9 12 
Sample Input 2 :
2
2 5 8 12 -1
3 6 9 -1
10 40 60 60 80 -1
10 20 30 40 50 60 90 100 -1
Sample Output 2 :
2 3 5 6 8 9 12 
10 10 20 30 40 40 50 60 60 60 80 90 100 */

/*
 * Time Complexity : O(N + M)
 * Space Complexity : O(1)
 * Where 'N' and 'M' are the sizes of the first and second Singly Linked Lists respectively.
 */

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize node data and next pointer
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to take input for creating a linked list
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

// Function to print the elements of a linked list
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

// Function to merge two sorted linked lists
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    // If one of the lists is empty, return the other list
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    // Initialize pointers for the new merged list
    Node *newHead = NULL;
    Node *newTail = NULL;

    // Determine the head of the merged list based on the smaller first element
    if (head1->data < head2->data)
    {
        newHead = head1;
        newTail = head1;
        head1 = head1->next;
    }
    else
    {
        newHead = head2;
        newTail = head2;
        head2 = head2->next;
    }

    // Merge the two lists by iterating through both lists
    while (head1 != NULL && head2 != NULL)
    {
        // Compare the first elements of both lists and append the smaller one to the merged list
        if (head1->data < head2->data)
        {
            newTail->next = head1;
            newTail = newTail->next;
            head1 = head1->next;
        }
        else
        {
            newTail->next = head2;
            newTail = newTail->next;
            head2 = head2->next;
        }
    }

    // If one list is longer than the other, append the remaining nodes to the merged list
    if (head1 != NULL)
    {
        newTail->next = head1;
    }
    if (head2 != NULL)
    {
        newTail->next = head2;
    }

    return newHead; // Return the head of the merged list
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // Take input for the first linked list
        Node *head1 = takeinput();
        // Take input for the second linked list
        Node *head2 = takeinput();
        // Merge the two sorted linked lists
        Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
        // Print the merged linked list
        print(head3);
    }
    return 0;
}
