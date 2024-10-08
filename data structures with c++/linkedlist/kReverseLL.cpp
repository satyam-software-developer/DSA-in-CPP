
/* Problem statement
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.

 'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.

Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4
 Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Detailed explanation ( Input/output format, Notes, Images )
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'k'.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= k <= M

Time Limit:  1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 9 10 -1
4


Sample Output 1 :
4 3 2 1 8 7 6 5 10 9
Sample Input 2 :
2
1 2 3 4 5 -1
0
10 20 30 40 -1
4
Sample Output 2 :
1 2 3 4 5 
40 30 20 10  */

/*
 * Time Complexity : O(n)
 * Space Complexity : O(n / k)
 * for each Linked List of sizes n,
 * n/k or (n/k) + 1 calls will be made during the recursion.
 */

#include <iostream>
using namespace std;

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

// Function to take input for creating a linked list
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

// Function to print the elements of the linked list
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

// Function to perform k-reverse on a linked list
Node *kReverse(Node *head, int k)
{
    if (k == 0 || k == 1)
    {
        return head; // If k is 0 or 1, no need to reverse, return the head
    }
    Node *current = head;
    Node *fwd = NULL;
    Node *prev = NULL;

    int count = 0;

    // Reverse first k nodes of the linked list
    while (count < k && current != NULL)
    {
        fwd = current->next;  // Store the next node
        current->next = prev; // Reverse the pointer of current node
        prev = current;       // Move prev to current node
        current = fwd;        // Move current to next node
        count++;
    }
    if (fwd != NULL)
    {
        head->next = kReverse(fwd, k); // Recursively call kReverse for the remaining list
    }
    return prev; // Return the new head of the reversed sublist
}

int main()
{
    int t;
    cin >> t; // Read the number of test cases

    while (t--)
    {
        Node *head = takeinput(); // Take input to create the linked list
        int k;
        cin >> k; // Read the value of k
        head = kReverse(head, k); // Perform k-reverse on the linked list
        print(head); // Print the reversed linked list
    }

    return 0;
}
