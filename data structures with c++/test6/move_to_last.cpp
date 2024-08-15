
/* Problem statement
Given a linked list and a key in it, the task is to move all occurrences of given key to end of linked list, keeping order of all other elements same.

Return the updated head of LL.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Line 1 : Elements of the linked list ending with -1 (-1 not included)
Line 2 : Key n, Element which has to shifted
Output Format :
Updated linked list
Constraints :
1 <= size of list <= 100

Sample Input 1:
1 2 2 3 4 5 -1
2
Sample Output 1:
1 3 4 5 2 2 
Sample Input 2:
1 1 2 3 4 -1
1
Sample Output 2:
2 3 4 1 1 */

#include <iostream>
using namespace std;

// Node class representing a node in the linked list
template <typename T>
class Node {
public:
    T data; // Data held by the node
    Node* next; // Reference to the next node in the list

    // Constructor to initialize a new node with given data
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to move all occurrences of 'n' to the end of the list
Node<int>* func(Node<int>* head, int n) {
    if (head == nullptr) { // If the list is empty, return null
        return nullptr;
    }

    Node<int>* temp = head;
    Node<int>* prev = nullptr;
    Node<int>* last = nullptr;
    int len = 1;

    // Find the length of the list and the last node
    while (temp->next != nullptr) {
        len++;
        temp = temp->next;
    }
    last = temp; // Set the last node
    temp = head;

    // Iterate through the list to move 'n' to the end
    for (int i = 0; i < len; i++) {
        if (temp->data == n) { // If current node's data is 'n'
            if (prev == nullptr) { // If 'n' is at the head of the list
                head = head->next; // Move head to the next node
                last->next = temp; // Link the current node to the end
                temp = head; // Move to the next node
                last = last->next; // Update the last node
                last->next = nullptr; // Ensure the last node points to null
            } else { // If 'n' is not at the head
                prev->next = temp->next; // Bypass the current node
                last->next = temp; // Link the current node to the end
                temp = temp->next; // Move to the next node
                last = last->next; // Update the last node
                last->next = nullptr; // Ensure the last node points to null
            }
        } else { // If current node's data is not 'n'
            prev = temp; // Move to the next node
            temp = temp->next;
        }
    }
    return head; // Return the modified list
}

// Function to create a linked list from user input
Node<int>* createlist() {
    Node<int>* head = nullptr; // Initialize head of the list
    Node<int>* rear = nullptr; // Initialize rear of the list
    int data; // Variable to hold the data
    cin >> data; // Read the first data item
    while (data != -1) { // Continue until -1 is entered
        Node<int>* newnode = new Node<int>(data); // Create a new node
        if (head == nullptr) { // If list is empty, set new node as head
            head = newnode;
            rear = head;
        } else { // If list is not empty, append the new node to the end
            rear->next = newnode;
            rear = rear->next;
        }
        cin >> data; // Read the next data item
    }
    return head; // Return the created list
}

// Function to print the linked list
void print(Node<int>* head) {
    while (head != nullptr) { // Iterate through the list
        cout << head->data << " "; // Print current node's data
        head = head->next; // Move to the next node
    }
    cout << endl; // Print a new line at the end
}

int main() {
    Node<int>* head1 = createlist(); // Create a list from user input
    int n;
    cin >> n; // Read the value to be moved to the end
    head1 = func(head1, n); // Move all occurrences of 'n' to the end
    print(head1); // Print the modified list
    return 0;
}
