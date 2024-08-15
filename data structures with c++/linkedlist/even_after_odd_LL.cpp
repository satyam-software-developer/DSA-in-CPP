

/*Problem statement
For a given singly linked list of integers, arrange the nodes such that all the even number nodes are placed after the all odd number nodes. The relative order of the odd and even terms should remain unchanged.

Note :
1. No need to print the linked list, it has already been taken care. Only return the new head to the list.
2. Don't create a new linked list.
3.  Just change the data, instead rearrange the provided list.
Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space. 
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
2
1 11 3 6 8 0 9 -1
10 20 30 40 -1
Sample Output 2 :
1 11 3 9 6 8 0
10 20 30 40 */

/*
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * Where 'n' is the size of the Singly Linked List
 */

#include <iostream>
using namespace std;

// Node class representing each element of the linked list
class Node
{
public:
    int data;
    Node *next;
    
    // Constructor to initialize a node with data and next pointer
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
    Node *head = NULL, *tail = NULL; // Initialize head and tail pointers

    // Loop to continue taking input until -1 is encountered
    while (data != -1)
    {
        Node *newnode = new Node(data); // Create a new node with the input data
        if (head == NULL)
        {
            head = newnode;
            tail = newnode; // If the list is empty, set both head and tail to the new node
        }
        else
        {
            tail->next = newnode; // Append the new node to the end of the list
            tail = newnode; // Update the tail pointer to the new node
        }
        cin >> data; // Read the next data input
    }
    return head; // Return the head of the constructed list
}

// Function to print the elements of the linked list
void print(Node *head)
{
    Node *temp = head; // Initialize a temporary pointer to traverse the list
    while (temp != NULL)
    {
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
    cout << endl; // Print a newline after printing all elements
}

// Function to rearrange the linked list such that all even numbers appear after odd numbers
Node *evenAfterOdd(Node *head)
{
    if (head == NULL) // If the list is empty, return NULL
    {
        return head;
    }

    Node *evenHead = NULL; // Pointer to the head of the even numbers list
    Node *oddHead = NULL; // Pointer to the head of the odd numbers list
    Node *evenTail = NULL; // Pointer to the tail of the even numbers list
    Node *oddTail = NULL; // Pointer to the tail of the odd numbers list

    // Loop through the original list to categorize nodes into odd and even lists
    while (head != NULL)
    {
        if (head->data % 2 == 0) // If the data is even
        {
            if (evenHead == NULL) // If the even list is empty, set current node as head and tail
            {
                evenHead = head;
                evenTail = head;
            }
            else // Otherwise, append current node to the end of even list
            {
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }
        else // If the data is odd
        {
            if (oddHead == NULL) // If the odd list is empty, set current node as head and tail
            {
                oddHead = head;
                oddTail = head;
            }
            else // Otherwise, append current node to the end of odd list
            {
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        head = head->next; // Move to the next node in the original list
    }

    if (oddHead == NULL) // If there are no odd nodes, return the even list
    {
        return evenHead;
    }
    else // Otherwise, concatenate the even list to the end of the odd list
    {
        oddTail->next = evenHead;
    }

    if (evenHead != NULL) // If the even list is not empty, set its tail's next pointer to NULL to terminate the list
    {
        evenTail->next = NULL;
    }

    return oddHead; // Return the head of the rearranged list
}

// Main function to execute the program
int main()
{
    int t;
    cin >> t; // Input number of test cases
    while (t--) // Loop over each test case
    {
        Node *head = takeinput(); // Take input for the linked list
        head = evenAfterOdd(head); // Rearrange the linked list
        print(head); // Print the rearranged list
    }
    return 0; // Return 0 to indicate successful execution
}
