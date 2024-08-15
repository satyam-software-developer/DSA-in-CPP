
/*Problem statement
You have been given a singly linked list of integers. Write a function to print the list in a reverse order.

To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.

Note :
You can’t change any of the pointers in the linked list, just print the linked list in the reverse order.
Detailed explanation ( Input/output format, Notes, Images )
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Output format :
For each test case, print the singly linked list of integers in a reverse fashion, in a row, separated by a single space.

Output for every test case will be printed in a seperate line.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^3


Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Sample Input 1 :
1
1 2 3 4 5 -1
Sample Output 1 :
5 4 3 2 1
Sample Input 2 :
2
1 2 3 -1
10 20 30 40 50 -1
Sample Output 2 :
3 2 1
50 40 30 20 10 */

/*
 *  Time Complexity : O(n)
 *  Space Complexity : O(n)
 *  Where 'n' is the size of the Singly Linked List
 */

#include <iostream>
using namespace std;

// Define a Node class for the linked list
class Node
{
public:
    int data;    // Data of the node
    Node *next;  // Pointer to the next node in the linked list

    // Constructor to initialize the node with data and set next pointer to NULL
    Node(int data)
    {
        this->data = data;  // Set the data of the node
        this->next = NULL;  // Initialize next pointer as NULL
    }
};

// Function to take input and create a linked list
Node *takeinput()
{
    int data;
    cin >> data;          // Read the first data

    Node *head = NULL;    // Initialize head pointer as NULL
    Node *tail = NULL;    // Initialize tail pointer as NULL

    // Read data until -1 is encountered
    while (data != -1)
    {
        Node *newnode = new Node(data);  // Create a new node with the given data

        // If head is NULL, set the new node as head and tail
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            // Otherwise, append the new node to the end of the linked list
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;  // Read the next data
    }
    return head;  // Return the head of the linked list
}

// Function to print the linked list in reverse order using recursion
void printReverse(Node *head)
{
    if (head == NULL)
    {
        return;  // Base case: If the head is NULL, return
    }
    printReverse(head->next);  // Recursively call printReverse on the next node
    cout << head->data << " "; // Print the data of the current node
}

// Main function to execute the program
int main()
{
    int t;
    cin >> t;  // Read the number of test cases

    // Iterate over the test cases
    while (t--)
    {
        Node *head = takeinput();  // Take input and create a linked list
        printReverse(head);        // Print the linked list in reverse order
        cout << endl;              // Print a new line after printing each test case
    }
    return 0;  // Return 0 to indicate successful execution
}
