
/*
Problem statement
For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.

Note :
Assume that the Indexing for the singly linked list always starts from 0.

If the given position 'i',  is greater than the length of the given singly linked list, then don't print anything.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line contains the value of 'i'. It denotes the position in the given singly linked list.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Output format :
For each test case, print the node data at the 'i-th' position of the linked list(if exists).

Output for every test case will be printed in a seperate line.
 Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
i  >= 0
Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
2
Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
9 8 4 0 7 8 -1
3
Sample Output 2 :
3
0
*/

/*
  Time Complexity : O(min(i, n))
  Space Complexity : O(1)
  where i is the position of the element to be print 
  and n is the size of singly linked list
*/


#include <iostream>
using namespace std;

// Node class definition
class Node
{
public:
    int data;       // Data stored in the node
    Node *next;     // Pointer to the next node in the linked list

    // Constructor to initialize data and next pointer to NULL
    Node(int data)
    {
        this->data = data;  // Initialize data
        this->next = NULL;  // Initialize next pointer to NULL
    }
};

// Function to take input from the user and create a linked list
Node *takeinput()
{
    int data;
    cin >> data;  // Read the first data input from the user
    Node *head = NULL, *tail = NULL;  // Initialize head and tail pointers to NULL

    // Continue reading data until -1 is encountered
    while (data != -1)
    {
        // Create a new node with the input data
        Node *newNode = new Node(data);

        // If the linked list is empty, set both head and tail to the new node
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // If the linked list is not empty, append the new node to the end
            tail->next = newNode;
            tail = newNode;  // Update tail to point to the new last node
        }

        cin >> data;  // Read the next data input from the user
    }

    return head;  // Return the head of the linked list
}

// Function to print the ith node of the linked list
void printIthNode(Node *head, int i)
{
    int position = 0;  // Initialize position counter to 0
    Node *temp = head;  // Create a temporary pointer and initialize it to the head of the linked list

    // Traverse the linked list until the ith node or end of list is reached
    while (temp != NULL && position < i)
    {
        position++;       // Increment position counter
        temp = temp->next;  // Move to the next node
    }

    // If the ith node exists, print its data
    if (temp != NULL)
    {
        cout << temp->data;
    }
}

// Main function to run the program
int main()
{
    int t;
    cin >> t;  // Read the number of test cases

    // Loop through each test case
    while (t--)
    {
        Node *head = takeinput();  // Take input and create a linked list
        int pos;
        cin >> pos;  // Read the position of the node to be printed
        printIthNode(head, pos);  // Print the ith node of the linked list
        cout << endl;  // Print a new line after each test case
    }

    return 0;  // Return 0 to indicate successful execution
}
