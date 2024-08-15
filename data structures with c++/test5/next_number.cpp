
/*Problem statement
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).

Note: You don't need to print the elements, just update the elements and return the head of updated LL. Input Constraints:
1 <= Length of Linked List <=10^6.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)
Output Format :
Line 1: Updated linked list elements 
Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0  */

#include <iostream>
using namespace std;

// Node class definition for the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(NULL) {}
};

// Function to take input and create a linked list
Node* takeInput() {
    int data;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    // Input loop until -1 is encountered
    while (data != -1) {
        // Create a new node with the given data
        Node* newNode = new Node(data);
        if (head == NULL) {
            // If the list is empty, set the new node as both head and tail
            head = newNode;
            tail = newNode;
        } else {
            // Otherwise, append the new node to the end of the list
            tail->next = newNode;
            tail = newNode;
        }
        // Read the next data value
        cin >> data;
    }
    // Return the head of the constructed linked list
    return head;
}

// Function to print the linked list
void print(Node* head) {
    // Traverse the list and print each node's data
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to reverse a linked list
Node* reverse(Node* head) {
    // Initialize pointers for the reversal process
    Node* prev = NULL;
    Node* current = head;
    // Traverse the list, reversing the pointers
    while (current != NULL) {
        Node* nextNode = current->next; // Store the next node
        current->next = prev; // Reverse the pointer
        prev = current; // Move the pointers one step ahead
        current = nextNode;
    }
    // 'prev' now points to the new head of the reversed list
    return prev;
}

// Function to find the next larger number represented by the linked list
Node* nextLargeNumber(Node* head) {
    // Reverse the list to perform operations from right to left
    head = reverse(head);
    int carry = 1, num;
    Node* ptr = head;
    Node* prev = NULL;
    // Traverse the list, adding carry to each node's data
    while (ptr) {
        num = (ptr->data + carry) % 10; // Calculate the new digit
        carry = (ptr->data + carry) / 10; // Calculate the new carry
        ptr->data = num; // Update the current node's data
        prev = ptr; // Move 'prev' one step ahead
        ptr = ptr->next; // Move to the next node
    }
    // If there's a carry after traversing the list, add a new node with value 1
    if (carry) {
        Node* tail = new Node(carry);
        prev->next = tail;
    }
    // Reverse the list again to restore the original order
    return reverse(head);
}

// Main function
int main() {
    // Take input for the linked list
    Node* head = takeInput();
    // Find the next larger number represented by the linked list
    head = nextLargeNumber(head);
    // Print the resulting linked list
    print(head);
    return 0;
}
