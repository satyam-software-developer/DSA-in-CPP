

/* Problem statement
Given a singly linked list of integers, sort it using 'Bubble Sort.'

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
0 <= M <= 10^3
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Input 2 :
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90  */

/*
 * Time Complexity : O(n^2)
 * Space Complexity : O(1)
 * Where 'n' is size of the Singly Linked List
 */

#include <iostream>
using namespace std;

// Node class representing individual elements of the linked list
class Node {
public:
    int data; // Data of the node
    Node *next; // Pointer to the next node

    // Constructor to initialize node with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to take input for the linked list
Node *takeInput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
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

// Function to print the elements of the linked list
void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to calculate the length of the linked list
int length(Node *head) {
    if (head == NULL) {
        return 0;
    }
    Node *temp = head;
    int size = 1 + length(temp->next);
    return size;
}

// Function to perform bubble sort on the linked list
Node *bubbleSort(Node *head) {
    // Loop through the list
    for (int i = 0; length(head) > i; i++) {
        Node *prev = NULL;
        Node *curr = head;
        // Traverse the list
        while (curr->next != NULL) {
            // If current node is greater than next node
            if (curr->data > curr->next->data) {
                // Swap nodes
                if (prev != NULL) {
                    Node *temp = curr->next->next;
                    curr->next->next = curr;
                    prev->next = curr->next;
                    curr->next = temp;
                    prev = prev->next;
                } else {
                    head = curr->next;
                    curr->next = head->next;
                    head->next = curr;
                    prev = head;
                }
            } else {
                // Move to next nodes
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return head;
}

// Main function
int main() {
    // Take input for the linked list
    Node *head = takeInput();
    // Perform bubble sort on the linked list
    head = bubbleSort(head);
    // Print the sorted linked list
    print(head);
    return 0;
}
