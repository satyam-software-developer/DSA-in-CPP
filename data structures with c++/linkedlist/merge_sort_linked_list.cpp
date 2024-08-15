
/*Problem statement
 Given a singly linked list of integers, sort it using 'Merge Sort.'

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec
Sample Input 1 :
1
10 9 8 7 6 5 4 3 -1
Sample Output 1 :
 3 4 5 6 7 8 9 10 
 Sample Input 2 :
2
-1
10 -5 9 90 5 67 1 89 -1
Sample Output 2 :
-5 1 5 9 10 67 89 90  */

/*
 * Time Complexity : O(n * logn)
 * Space Complexity : O(logn)
 * Where 'n' is size of the Singly Linked List
 */

#include <iostream>
using namespace std;

// Node class for representing elements of a linked list
class Node {
public:
    int data; // Data stored in the node
    Node *next; // Pointer to the next node

    // Constructor to initialize the node with given data and next pointer
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to take input for creating a linked list
Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL; // Initialize head and tail pointers to NULL
    while (data != -1) {
        Node *newnode = new Node(data); // Create a new node with the given data
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode; // Connect the new node to the existing linked list
            tail = newnode; // Update the tail pointer to the new node
        }
        cin >> data; // Read the next data value
    }
    return head; // Return the head pointer of the created linked list
}

// Function to print the elements of a linked list
void print(Node *head) {
    Node *temp = head; // Initialize a temporary pointer to traverse the linked list
    while (temp != NULL) {
        cout << temp->data << " "; // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
    cout << endl;
}

// Function to find the middle node of a linked list
Node *findMid(Node *head) {
    if (head == NULL) {
        return head;
    }

    Node *slow = head; // Slow pointer moves one node at a time
    Node *fast = head; // Fast pointer moves two nodes at a time

    // Traverse the linked list until the fast pointer reaches the end
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next; // Move slow pointer one step forward
        fast = fast->next->next; // Move fast pointer two steps forward
    }
    return slow; // Return the middle node
}

// Function to merge two sorted linked lists
Node *merge(Node *head1, Node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    Node *newHead = NULL, *newTail = NULL; // Pointers to maintain the merged list

    // Determine the head of the merged list based on the smaller first element
    if (head1->data <= head2->data) {
        newHead = head1;
        newTail = head1;
        head1 = head1->next;
    } else {
        newHead = head2;
        newTail = head2;
        head2 = head2->next;
    }

    // Merge the two lists by iterating through both lists
    while (head1 != NULL && head2 != NULL) {
        // Compare the first elements of both lists and append the smaller one to the merged list
        if (head1->data <= head2->data) {
            newTail->next = head1;
            newTail = newTail->next;
            head1 = head1->next;
        } else {
            newTail->next = head2;
            newTail = newTail->next;
            head2 = head2->next;
        }
    }

    // If one list is longer than the other, append the remaining nodes to the merged list
    if (head1 != NULL) {
        newTail->next = head1;
    }
    if (head2 != NULL) {
        newTail->next = head2;
    }

    // Advance newTail to the last node of the merged list
    while (newTail->next != NULL) {
        newTail = newTail->next;
    }

    return newHead; // Return the head of the merged list
}

// Function to perform merge sort on a linked list
Node *mergeSort(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head; // Base case: return if the list is empty or has only one node
    }
    // Find the middle node of the linked list
    Node *mid = findMid(head);

    // Split the linked list into two halves from the middle node
    Node *half1 = head;
    Node *half2 = mid->next;
    mid->next = NULL;

    // Recursively sort both halves of the linked list
    half1 = mergeSort(half1);
    half2 = mergeSort(half2);

    // Merge the sorted halves
    Node *finalHead = merge(half1, half2);

    return finalHead; // Return the head of the sorted list
}

// Main function to execute the program
int main() {
    int t; // Number of test cases
    cin >> t; // Input the number of test cases

    // Loop over each test case
    while (t--) {
        Node *head = takeinput(); // Input the elements of the linked list
        head = mergeSort(head); // Perform merge sort on the linked list
        print(head); // Print the sorted linked list
    }

    return 0; // Return 0 to indicate successful execution
}
