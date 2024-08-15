
/*Problem statement
You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

Detailed explanation ( Input/output format, Notes, Images )
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
 Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.
 */

/*
 *  Time Complexity : O(n)
 *  Space Complexity : O(1)
 *  Where 'n' is the size of the Singly Linked List
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
    // Read input data until -1 is encountered
    while (data != -1)
    {
        // Create a new node with the current data
        Node *newnode = new Node(data);
        // If the linked list is empty, set the new node as both head and tail
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            // Otherwise, append the new node to the end of the list
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data; // Read the next input data
    }
    return head; // Return the head of the linked list
}

// Function to reverse a linked list
Node *reverseLinkedList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *fwd = NULL;
    // Iterate through the list and reverse each node's pointer
    while (curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev; // Return the new head of the reversed list
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true; // An empty list or a list with a single node is always a palindrome
    }
    // Find the center of the list using slow and fast pointers
    Node *fast = head;
    Node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // Split the list into two halves and reverse the second half
    Node *secondHead = slow->next;
    slow->next = NULL;
    secondHead = reverseLinkedList(secondHead);

    // Compare the first half with the reversed second half
    Node *firstSubList = head;
    Node *secondSubList = secondHead;
    bool ans = true;
    while (secondSubList != NULL)
    {
        if (firstSubList->data != secondSubList->data)
        {
            ans = false;
            break;
        }
        firstSubList = firstSubList->next;
        secondSubList = secondSubList->next;
    }
    // Revert the reversed second half back to its original order
    secondHead = reverseLinkedList(secondHead);

    // Rejoin the two sublists
    firstSubList = head;
    while (firstSubList->next != NULL)
    {
        firstSubList = firstSubList->next;
    }
    firstSubList->next = secondHead;
    return ans; // Return true if the list is a palindrome, otherwise false
}

int main()
{
    int t;
    cin >> t; // Read the number of test cases

    // Iterate through each test case
    while (t--)
    {
        Node *head = takeinput();      // Take input for the linked list
        bool ans = isPalindrome(head); // Check if the list is a palindrome
        if (ans)
            cout << "true"; // Print true if the list is a palindrome
        else
            cout << "false"; // Print false if the list is not a palindrome
        cout << endl;
    }

    return 0;
}
