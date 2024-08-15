
/*Problem statement
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions and return the new head to the list.

Note :
1. Remember, You need to swap the nodes, not only the data.
2. Indexing starts from 0.
3. No need to print the list, it has already been taken care.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.
 Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4
Sample Output 1 :
3 4 5 6 2 1 9 
 Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6
 Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70  */

/*
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * Where 'n' is size of the Singly Linked List
 */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to take input and create a linked list
Node *takeInput() {
    int data;
    cin >> data;
    Node *head = nullptr, *tail = nullptr;
    
    // Continue taking input until -1 is encountered
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

// Function to print the linked list
void print(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to swap two nodes in a linked list
Node *swapNodes(Node *head, int i, int j) {
    // Check if the indices are the same or the list is empty
    if (i == j || head == nullptr) {
        return head; // Return the original list if no swapping is required
    }

    Node *currentNode = head, *prev = nullptr;
    Node *firstNode = nullptr, *secondNode = nullptr, *firstNodePrev = nullptr, *secondNodePrev = nullptr;

    int pos = 0;

    // Traverse the list to find the nodes at indices i and j
    while (currentNode != nullptr) {
        if (pos == i) {
            firstNodePrev = prev;
            firstNode = currentNode;
        } else if (pos == j) {
            secondNodePrev = prev;
            secondNode = currentNode;
        }

        prev = currentNode;
        currentNode = currentNode->next;
        pos += 1;
    }

    // Adjust the pointers to swap the nodes
    if (firstNodePrev != nullptr) {
        firstNodePrev->next = secondNode;
    } else {
        head = secondNode;
    }
    if (secondNodePrev != nullptr) {
        secondNodePrev->next = firstNode;
    } else {
        head = firstNode;
    }

    // Perform the actual swapping of the nodes
    Node *currentfirstNode = secondNode->next;
    secondNode->next = firstNode->next;
    firstNode->next = currentfirstNode;

    return head; // Return the head of the modified linked list
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int i, j;
        Node *head = takeInput();
        cin >> i;
        cin >> j;
        head = swapNodes(head, i, j);
        print(head);
    }
    return 0;
}
