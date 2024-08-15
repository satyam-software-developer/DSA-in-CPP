
/* 
Problem statement
You have been given a singly linked list of integers, an integer value called 'data' and a position with the name 'pos.'

 Write a function to add a node to the list with the 'data' at the specified position, 'pos.'

Note :
Assume that the Indexing for the singly linked list always starts from 0.

If the position is greater than the length of the singly linked list, you should return the same linked list without any change.
 Illustration :
The following images depict how the insertion has been taken place.
Image-I :

Alt txt

Image-II :

Alt txt

Image-III :

Alt txt

Image-IV :

Alt txt

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space. 

The second line contains the two integer values of 'data' and 'pos' separated by a single space, respectively
Reminder/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
Output format :
For each test case, print the resulting singly linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a separate line.
 Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
pos >= 0
Time Limit: 1sec
Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 100
Sample Output 1 :
3 4 5 100 2 6 1 9
Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0 20
10 98 7 66 8 -1
5 99
Sample Output 2 :
20 3 4 5 2 6 1 9
10 98 7 66 8 99 

*/

/*
  Time Complexity : O(min(i, n))
  Space Complexity : O(1)
  where i is the position where the new node is 
  to be inserted and n is the size of singly linked list

*/
#include<iostream>
using namespace std;

// Definition of a Node class for the LinkedList
class Node {
public:
    int data;       // Data stored in the node
    Node *next;     // Pointer to the next node in the LinkedList

    // Constructor to initialize the node with data
    Node(int data) : data(data), next(nullptr) {}
};

// Function to take input and create a LinkedList
Node* takeInput() {
    int data;
    cin >> data;
    Node *head = nullptr, *tail = nullptr;  // Initializing head and tail pointers

    // Loop to read data and create nodes until -1 is encountered
    while (data != -1) {
        Node *newNode = new Node(data);  // Creating a new node with the given data

        // If it's the first node
        if (head == nullptr) {
            head = tail = newNode;  // Setting both head and tail to the new node
        } else {
            tail->next = newNode;  // Linking the new node to the end of the list
            tail = newNode;        // Updating the tail to the new node
        }

        cin >> data;  // Reading next data value
    }

    return head;  // Returning the head of the created LinkedList
}

// Function to print the LinkedList
void print(Node *head) {
    Node *temp = head;  // Temporary pointer to traverse the LinkedList

    // Loop to iterate over the LinkedList and print each node's data
    while (temp != nullptr) {
        cout << temp->data << " ";  // Printing data of the current node
        temp = temp->next;          // Moving to the next node
    }

    cout << endl;  // Printing a new line after printing all nodes
}

// Method to insert a node at a given position in the LinkedList
Node* insert(Node* head, int pos, int data) {
    Node* newNode = new Node(data);  // Creating a new node with the given data

    // Inserting at the beginning (pos = 0)
    if (pos == 0) {
        newNode->next = head;  // Linking the new node to the current head
        return newNode;        // Returning the new node as the updated head
    }

    int currPos = 0;          // Variable to keep track of current position
    Node* temp = head;        // Temporary pointer to traverse the LinkedList

    // Loop to find the node at position (pos - 1)
    while (currPos < pos - 1 && temp != nullptr) {
        currPos++;             // Incrementing position
        temp = temp->next;     // Moving to the next node
    }

    // If reached the end of the list before finding the position
    if (temp == nullptr) {
        return head;  // Returning the unchanged head
    }

    // Linking the new node to the next node at the given position
    newNode->next = temp->next;
    // Linking the previous node to the new node
    temp->next = newNode;

    return head;  // Returning the original head of the LinkedList
}

// Main function to execute the program
int main() {
    int t;
    cin >> t;  // Reading the number of test cases

    // Loop to run the program for each test case
    while (t--) {
        Node* head = takeInput();  // Taking input and creating LinkedList
        int pos, data;
        cin >> pos >> data;  // Reading position and data to be inserted

        head = insert(head, pos, data);  // Inserting node at the given position
        print(head);  // Printing the modified LinkedList
    }

    return 0;
}
