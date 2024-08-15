
/*Problem statement
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list. Indexing starts from 1.

To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.

Note :
No need to print the list, it has already been taken care. Only return the new head to the list. You can return null in case where all nodes will be deleted.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'M,' and 'N,' respectively. A single space will separate them.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= P <= 10^5
Where P is the size of the singly linked list.
0 <= M <= 10^5
0 <= N <= 10^5 

Time Limit: 1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
2 2
Sample Output 1 :
1 2 5 6
Sample Input 2 :
2
10 20 30 40 50 60 -1
0 1
1 2 3 4 5 6 7 8 -1
2 3
Sample Output 2 :
1 2 6 7
Explanation of Sample Input 2 :
For the first query, we delete one node after every zero elements hence removing all the items of the list. Therefore, nothing got printed.

For the second query, we delete three nodes after every two nodes, resulting in the final list, 1 -> 2 -> 6 -> 7. */

/*
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * Where 'n' is size of the Singly Linked List
 */

#include <iostream>
using namespace std;

// Node class for the linked list
class Node
{
public:
    int data;    // Data stored in the node
    Node *next;  // Pointer to the next node

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
    int data;              // Variable to store input data
    cin >> data;           // Read the first data element
    Node *head = NULL;     // Pointer to the head of the linked list
    Node *tail = NULL;     // Pointer to the tail of the linked list

    // Loop to take input until -1 is encountered
    while (data != -1)
    {
        Node *newnode = new Node(data); // Create a new node with the input data

        // If the list is empty, set the new node as both head and tail
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode; // Append the new node to the end of the list
            tail = newnode;       // Update the tail pointer to the new node
        }
        cin >> data; // Read the next data element
    }
    return head; // Return the head of the constructed linked list
}

// Function to print the elements of the linked list
void print(Node *head)
{
    Node *temp = head; // Temporary pointer to traverse the list

    // Traverse the list and print each element
    while (temp != NULL)
    {
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->next;         // Move to the next node
    }
    cout << endl; // Print a newline after printing all elements
}

// Function to skip M nodes and delete N nodes in the linked list
Node *skipMdeleteN(Node *head, int M, int N)
{
    if (N == 0 || head == NULL)
    {
        return head; // If N is 0, or the list is empty, return the original list
    }

    if (M == 0)
    {
        return head; // If M is 0, no nodes need to be skipped, return the original list
    }

    Node *currentNode = head; // Pointer to traverse the list
    Node *temp = NULL;        // Temporary pointer to keep track of nodes to be retained

    // Traverse the list until currentNode becomes NULL
    while (currentNode != NULL)
    {
        int take = 0; // Counter to keep track of nodes to be retained
        int skip = 0; // Counter to keep track of nodes to be skipped

        // Traverse M nodes and retain them
        while (currentNode != NULL && take < M)
        {
            if (temp == NULL)
            {
                temp = currentNode; // If temp is null, assign the current node to temp
            }
            else
            {
                temp->next = currentNode; // Otherwise, append the current node to temp
                temp = currentNode;
            }
            currentNode = currentNode->next; // Move to the next node
            take += 1;                       // Increment the take counter
        }

        // Traverse N nodes and skip them
        while (currentNode != NULL && skip < N)
        {
            currentNode = currentNode->next; // Move to the next node
            skip += 1;                        // Increment the skip counter
        }

        if (temp != NULL)
        {
            temp->next = currentNode; // Set the next of temp to the current node
        }
    }

    return head; // Return the head of the modified linked list
}

// Main function
int main()
{
    int t; // Number of test cases
    cin >> t; // Read the number of test cases

    // Process each test case
    while (t--)
    {
        Node *head = takeinput(); // Take input for the linked list
        int m, n; // Values of M and N
        cin >> m >> n; // Read the values of M and N
        head = skipMdeleteN(head, m, n); // Skip M nodes and delete N nodes
        print(head); // Print the modified linked list
    }

    return 0; // Exit the program
}
