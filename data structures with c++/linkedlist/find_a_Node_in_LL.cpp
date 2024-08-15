
/*Problem statement
Given a singly linked list of integers and an integer n, find and return the index for the first occurrence of 'n' in the linked list. -1 otherwise.

Follow a recursive approach to solve this.

Note :
Assume that the Indexing for the linked list always starts from 0.
Detailed explanation ( Input/output format, Notes, Images )
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'n'.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
 Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit:  1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
100
Sample Output 1 :
-1
Sample Input 2 :
2
10 20010 30 400 600 -1
20010
100 200 300 400 9000 -34 -1
-34
Sample Output 2 :
1
5 */

/*
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 * Where 'n' is size of the Singly Linked List
 */
#include <iostream>
using namespace std;

// Node class for representing elements of the linked list
class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize a node with data
    Node(int data) : data(data), next(nullptr) {}
};

// Function to take input for the linked list
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = nullptr, *tail = nullptr;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
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

// Recursive method to find the index of a node with value n
int findNodeRec(Node *head, int n)
{
    if (head == nullptr)
    {
        return -1; // If the end of the list is reached, return -1 (indicating node not found)
    }
    else if (head->data == n)
    {
        return 0; // If the current node contains the value n, return 0 (indicating found at index 0)
    }
    // Recursively search for the node with value n in the remaining list
    int smallAns = findNodeRec(head->next, n);

    // If the node with value n is not found in the remaining list, return -1
    if (smallAns == -1)
    {
        return -1;
    }
    // If the node with value n is found in the remaining list, return its index incremented by 1
    return smallAns + 1;
}

int main()
{
    int t;
    cin >> t; // Read the number of test cases

    // Iterate through each test case
    while (t--)
    {
        Node *head = takeinput(); // Take input for the linked list
        int val;
        cin >> val;                             // Read the value of n to find
        cout << findNodeRec(head, val) << endl; // Find and print the index of the node with value n
    }

    return 0;
}
