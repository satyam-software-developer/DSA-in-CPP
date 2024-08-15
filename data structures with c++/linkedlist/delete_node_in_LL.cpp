
/* 
Problem statement
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.

Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.
Illustration :
The following images depict how the deletion has been performed.
Image-I :

Alt txt

Image-II :

Alt txt

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains the elements of the linked list separated by a single space. 
The second line contains the integer value of 'POS'. It denotes the position in the linked list from where the node has to be deleted.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
Print the resulting linked list of integers in a row, separated by a single space.
Note:

You are not required to print the output, it has already been taken care of. Just implement the function. 
Sample Input 1 :
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Explanation of Sample Output 1 :
The data in the node with index 3 is 2 which has been removed.
Sample Input 2 :
3 4 5 2 6 1 9 -1
0
Sample Output 2 :
4 5 2 6 1 9
Constraints :
0 <= N <= 10^5
POS >= 0

Time Limit: 1sec
Expected Complexity :
Time Complexity  : O(N)
Space Complexity  : O(1)
*/

/*
   Time Complexity : O(min(I, N))
   Space Complexity : O(1)
   where I is the position of the node to be deleted and N is the size of the singly linked list

*/
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

// Definition of the Node class for a linked list
class Node {
public:
    int data;        // Data stored in the node
    Node* next;      // Pointer to the next node in the list
    
    // Constructor to initialize a node with data and next pointer as nullptr
    Node(int data) : data(data), next(nullptr) {}
};

// Definition of the Runner class to handle input, output, and operations on LinkedList
class Runner {
    int pos;           // Position to delete a node
    Node* head = nullptr;  // Pointer to the head of the LinkedList

public:
    // Method to take input for the LinkedList
    void takeInput() {
        int data;
        cin >> data;
        Node* tail = nullptr;  // Pointer to the last node of the LinkedList
        
        // Loop to read data and create nodes until sentinel value (-1) is encountered
        while (data != -1) {
            Node* newNode = new Node(data);  // Creating a new node with the given data
            // Checking if the LinkedList is empty
            if (head == nullptr) {
                head = newNode;   // Setting the new node as the head
                tail = newNode;   // Setting the new node as the tail
            } else {
                tail->next = newNode;  // Linking the new node to the end of the list
                tail = newNode;        // Updating the tail to the new node
            }
            cin >> data;  // Reading the next data value
        }
        cin >> pos;  // Reading the position to delete a node
    }

    // Method to copy a LinkedList
    Node* copyll(Node* chead) {
        // If the original list is empty, return nullptr
        if (chead == nullptr) return nullptr;
        
        Node* nhead = nullptr;  // Pointer to the head of the new copied LinkedList
        Node* tail = nullptr;   // Pointer to the last node of the new copied LinkedList

        // Loop to iterate over the original list and create nodes in the new list
        while (chead != nullptr) {
            Node* newNode = new Node(chead->data);  // Creating a new node with the data from original list
            // Checking if the new list is empty
            if (nhead == nullptr) {
                nhead = newNode;   // Setting the new node as the head
                tail = newNode;    // Setting the new node as the tail
            } else {
                tail->next = newNode;  // Linking the new node to the end of the new list
                tail = newNode;        // Updating the tail to the new node
            }
            chead = chead->next;  // Moving to the next node in the original list
        }
        return nhead;  // Returning the head of the new copied LinkedList
    }

    // Method to print the LinkedList
    void print(Node* head) {
        Node* temp = head;  // Temporary pointer to traverse the LinkedList
        // Loop to iterate over the LinkedList and print each node's data
        while (temp != nullptr) {
            cout << temp->data << " ";  // Printing the data of the current node
            temp = temp->next;  // Moving to the next node
        }
        cout << endl;  // Printing a new line after printing all nodes
    }

    // Method to execute the operations on LinkedList and print the output
    void executeAndPrintOutput() {
        Node* copyhead = copyll(head);  // Copying the original LinkedList
        copyhead = deleteNode(copyhead, pos);  // Deleting a node at the specified position
        print(copyhead);  // Printing the modified LinkedList
        
        // Deleting the copied LinkedList to prevent memory leaks
        while (copyhead != nullptr) {
            Node* temp = copyhead;  // Temporary pointer to store the current node
            copyhead = copyhead->next;  // Moving to the next node
            delete temp;  // Deleting the current node to free memory
        }
    }

    // Method to delete a node at a given position in the LinkedList
    Node* deleteNode(Node* head, int pos) {
        // If the list is empty
        if (head == nullptr) {
            return head;
        }
        
        // Deleting the head node (pos = 0)
        if (pos == 0) {
           Node* temp = head;  // Temporary pointer to store the current head
           head = head->next;  // Moving head to the next node
           delete temp;  // Deleting the previous head to free memory
           return head;  // Returning the updated head
        }
        
        Node* curr = head;  // Variable to traverse the LinkedList
        int currPos = 0;    // Variable to keep track of current position

        // Loop to find the node at position (pos - 1)
        while (curr != nullptr && currPos < pos - 1) {
            ++currPos;
            curr = curr->next;  // Moving to the next node
        }
        
        // If the position is out of bounds
        if (curr == nullptr || curr->next == nullptr) {
            return head;
        }
        
        Node* temp = curr->next;  // Temporary pointer to store the node to be deleted
        curr->next = curr->next->next;  // Removing the node at the specified position
        delete temp;  // Deleting the specified node to free memory
        
        return head;  // Returning the updated head of the LinkedList
    }
};

// Main function to execute the program
int main() {   
    Runner runner;  // Creating an instance of the Runner class
    runner.takeInput();  // Taking input for the LinkedList
    runner.executeAndPrintOutput();  // Executing operations on the LinkedList and printing the output
    return 0;  // Returning 0 to indicate successful execution
}
