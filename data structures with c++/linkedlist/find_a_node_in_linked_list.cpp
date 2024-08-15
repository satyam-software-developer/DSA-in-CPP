
/*
Problem statement
You have been given a singly linked list of integers. Write a function that returns the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.

Note :
Assume that the Indexing for the singly linked list always starts from 0.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 'T' which denotes the number of test cases.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line contains the integer value 'N'. It denotes the data to be searched in the given singly linked list.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence -1 would never be a list element.
Output format :
For each test case, return the index/position of 'N' in the singly linked list. Return -1, otherwise.

Output for every test case will be printed in a separate line.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
 Constraints :
1 <= T <= 10^2
0 <= M <= 10^5

Where 'M' is the size of the singly linked list.

Time Limit: 1 sec
Sample Input 1 :
2
3 4 5 2 6 1 9 -1
5
10 20 30 40 50 60 70 -1
6
Sample Output 1 :
2
-1
 Explanation for Sample Output 1:
In test case 1, 'N' = 5 appears at position 2 (0-based indexing) in the given linked list.

In test case 2, we can see that 'N' = 6 is not present in the given linked list.
Sample Input 2 :
2
1 -1
2
3 4 5 2 6 1 9 -1
6
Sample Output 2 :
-1
4
 Explanation for Sample Output 2:
In test case 1, we can see that 'N' = 2 is not present in the given linked list.

In test case 2, 'N' = 6 appears at position 4 (0-based indexing) in the given linked list.
*/

/*
  Time Complexity : O(N)
  Space Complexity : O(1)

  Where 'N' is the size of singly linked list.
*/

#include <iostream>
using namespace std;

// Define a Node class for the linked list
class Node
{
public:
    int data;   // Data part of the node
    Node *next; // Pointer to the next node in the list

    // Constructor to initialize the node with given data
    Node(int data)
    {
        this->data = data; // Initialize data member with provided data
        this->next = NULL; // Initialize next pointer to NULL
    }
};

// Function to create a linked list
Node *takeinput()
{
    int data;
    cin >> data;       // Read the first data value for the linked list
    Node *head = NULL; // Initialize head pointer to NULL
    Node *tail = NULL; // Initialize tail pointer to NULL

    // Continue reading data until -1 is encountered (end of input)
    while (data != -1)
    {
        Node *newNode = new Node(data); // Create a new node with the read data

        // If the linked list is empty, set both head and tail to the new node
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // If the linked list is not empty, append the new node to the end
            tail->next = newNode; // Update the next pointer of the current tail to the new node
            tail = newNode;       // Update the tail pointer to the new node
        }
        cin >> data; // Read the next data value
    }
    return head; // Return the head pointer of the constructed linked list
}

// Method to find the position of a node with given data in the LinkedList
int findNode(Node *head, int n)
{
    int pos = 0; // Initialize position counter to 0

    // Traverse the linked list until the end is reached
    while (head != NULL)
    {
        // If the current node's data matches the target value, return its position
        if (head->data == n)
        {
            return pos;
        }
        pos++;             // Increment the position counter
        head = head->next; // Move to the next node in the list
    }
    return -1; // Return -1 if the target value is not found in the linked list
}

int main()
{
    int t;
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--)
    {
        Node *head = takeinput(); // Create a linked list based on input
        int val;
        cin >> val;                          // Read the target value to search for in the linked list
        cout << findNode(head, val) << endl; // Print the position of the target value in the linked list

        // Free memory to avoid memory leaks
        Node *temp = head;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp; // Delete the current node
        }
    }
    return 0; // Return 0 to indicate successful execution
}
