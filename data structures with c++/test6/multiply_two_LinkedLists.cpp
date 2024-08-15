
/* Problem statement
1. You are given two linked lists. Data of each node of these linked lists contain a digit from the range: [0, 9].

2. The linked lists represent two numbers.

3. You have to print the product of these two numbers.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
Input has already been managed for cpp and java submissions. In cpp and java, you have to just write a function which receives head nodes of two linked lists. The sizes of linked lists are N and M, respectively.
For other languages, the first line of input contains list of N space separated integers, terminated by -1. The following line of input also contains list of M space separated integers, terminated by -1. The integers form the data of nodes of two linked list.   
Constraints:
N and M lies in the range: [1, 1000].
0 <= |Node Data| <= 9
Output format:
Print the product of numbers, represented by two linked lists.
Sample Input:
1 2 3 4 5 -1
1 2 3 -1
Sample Output:
1 5 1 8 4 3 5 */

#include <iostream>
using namespace std;

// Class representing a node in a linked list
template <typename T>
class LinkedListNode {
public:
    T data; // Data of the node
    LinkedListNode<T>* next; // Reference to the next node

    // Constructor to initialize a node with data
    LinkedListNode(T data) {
        this->data = data;
        this->next = nullptr; // Initialize next as null
    }
};

// Function to calculate the length of a linked list
int length(LinkedListNode<int>* head) {
    int len = 0; // Initialize length counter
    while (head != nullptr) { // Traverse the list until the end
        len += 1; // Increment length counter
        head = head->next; // Move to the next node
    }
    return len; // Return the length of the list
}

// Function to reverse a linked list iteratively
LinkedListNode<int>* reverseIteratively(LinkedListNode<int>* head) {
    if (head == nullptr) { // Check if the list is empty
        return nullptr; // Return null if the list is empty
    }
    LinkedListNode<int>* prev = nullptr; // Initialize previous node as null
    LinkedListNode<int>* curr = head; // Start with the head node
    LinkedListNode<int>* currNext = curr->next; // Reference to the next node

    // Traverse the list and reverse pointers
    while (curr != nullptr && currNext != nullptr) {
        curr->next = prev; // Reverse the current node's pointer
        prev = curr; // Move previous to the current node
        curr = currNext; // Move current to the next node
        currNext = currNext->next; // Move next to the next node's next
    }

    if (curr != nullptr) { // Check if the current node is not null
        curr->next = prev; // Reverse the last node's pointer
    }

    return curr; // Return the new head of the reversed list
}

// Function to create a linked list of a given size initialized with zeros
LinkedListNode<int>* makeLLOfSize(int n) {
    int nc = 0; // Initialize node counter

    LinkedListNode<int>* head = nullptr; // Initialize head of the list
    LinkedListNode<int>* tail = nullptr; // Initialize tail of the list

    // Create 'n' nodes initialized with zero
    while (nc < n) {
        LinkedListNode<int>* newNode = new LinkedListNode<int>(0); // Create a new node with data 0

        if (head == nullptr) { // If the list is empty
            head = newNode; // Set new node as head
            tail = newNode; // Set new node as tail
        } else {
            tail->next = newNode; // Add new node to the end of the list
            tail = newNode; // Update the tail reference
        }
        nc += 1; // Increment node counter
    }
    return head; // Return the head of the list
}

// Function to add a node with value 0 at the beginning of the linked list
LinkedListNode<int>* addFirst(LinkedListNode<int>* head) {
    LinkedListNode<int>* newNode = new LinkedListNode<int>(0); // Create a new node with data 0
    if (head == nullptr) { // If the list is empty
        head = newNode; // Set new node as head
    } else {
        newNode->next = head; // Point new node to the current head
        head = newNode; // Update head to the new node
    }
    return head; // Return the new head of the list
}

// Function to print a linked list
void printL(LinkedListNode<int>* head) {
    if (head == nullptr) { // Check if the list is empty
        return; // Return if the list is empty
    }
    // Skip leading zeros
    while (head != nullptr && head->data == 0) {
        head = head->next; // Move to the next node if the current node is zero
    }
    // Print remaining nodes
    while (head != nullptr) {
        cout << head->data << " "; // Print the data of the current node
        head = head->next; // Move to the next node
    }
    cout << endl; // Print a newline after the list
}

// Function to multiply two linked lists representing numbers
void multiply(LinkedListNode<int>* head1, LinkedListNode<int>* head2) {
    head1 = reverseIteratively(head1); // Reverse the first linked list
    head2 = reverseIteratively(head2); // Reverse the second linked list

    int len1 = length(head1); // Get the length of the first list
    int len2 = length(head2); // Get the length of the second list

    LinkedListNode<int>* first = head1; // Pointer to traverse the first list
    LinkedListNode<int>* second = head2; // Pointer to traverse the second list

    int carry = 0; // Initialize carry for multiplication
    LinkedListNode<int>* res1 = makeLLOfSize(len1 + len2 + 1); // Initialize the result list

    // Outer loop to traverse the second list
    while (second != nullptr) {
        LinkedListNode<int>* res2 = makeLLOfSize(len1 + len2 + 1); // Initialize a temporary result list
        first = head1; // Reset first pointer to head1
        LinkedListNode<int>* temp2 = res2; // Pointer to traverse the temporary result list
        LinkedListNode<int>* temp1 = res1; // Pointer to traverse the main result list
        carry = 0; // Reset carry

        // Inner loop to traverse the first list and perform multiplication
        while (first != nullptr) {
            int ans = temp1->data + carry + second->data * first->data; // Calculate the product and add carry
            temp2->data = ans % 10; // Store the unit place of the result
            carry = ans / 10; // Update carry with the remaining part
            temp2 = temp2->next; // Move to the next node in the temporary result list
            temp1 = temp1->next; // Move to the next node in the main result list
            first = first->next; // Move to the next node in the first list
        }
        if (carry != 0) { // If there is any carry left after the inner loop
            int ans = temp1->data + carry; // Add carry to the current node
            temp2->data = ans; // Store the result
        }

        res1 = res2; // Update the main result list
        head1 = addFirst(head1); // Add a leading zero to the first list

        second = second->next; // Move to the next node in the second list
    }

    res1 = reverseIteratively(res1); // Reverse the result list

    printL(res1); // Print the result
}



// Function to take input from the user and create a linked list
LinkedListNode<int>* takeInput() {
    LinkedListNode<int>* head = nullptr; // Initialize head of the list
    LinkedListNode<int>* tail = nullptr; // Initialize tail of the list

    int data; // Variable to store input data
    cin >> data; // Read data from the user

    // Create nodes until the user enters -1
    while (data != -1) {
        LinkedListNode<int>* newNode = new LinkedListNode<int>(data); // Create a new node with the input data

        if (head == nullptr) { // If the list is empty
            head = newNode; // Set new node as head
            tail = newNode; // Set new node as tail
        } else {
            tail->next = newNode; // Add new node to the end of the list
            tail = newNode; // Update the tail reference
        }
        cin >> data; // Read next data from the user
    }
    return head; // Return the head of the list
}

// Main function to execute the program
int main() {
    // Take input for the two linked lists
    LinkedListNode<int>* head1 = takeInput(); // Read first linked list
    LinkedListNode<int>* head2 = takeInput(); // Read second linked list

    // Multiply the two linked lists
    multiply(head1, head2); // Call the multiply function

    return 0; // Exit the program
}
