
/* Problem statement
Given a linked list that contain some random integers from 1 to n with many duplicates. You need to replace each duplicate element that is present in the linked list with the values n+1, n+2, and so on (starting from left to right in given LL).

For eg. if input linked list is
1 3 1 4 4 2 1 -1
updated linked list should be -
1 3 5 4 6 2 7
n in the list is 4, so I have to replace each duplicate from left to right with 4, 5 and so on. In that way, element 1 (which is at index 2) will be replaced by 5, element 4 (which is present at index 4) by 6 and element 1 (which is present at index 6) by 7. You don't need to print the elements, just update the elements in LL.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
Linked list elements (separated by space and terminated by-1)
Output Format :
Updated LL elements (separated by space)
Sample Input 1 :
1 3 1 4 4 2 1 -1
Sample Output 1 :
1 3 5 4 6 2 7 */

#include <iostream>
using namespace std;

// Node class template representing a node in a singly linked list
template <typename T>
class Node
{
public:
    T data;         // Data stored in the node
    Node<T> *next;  // Pointer to the next node in the list

    // Constructor to initialize a node with data
    Node(T data)
    {
        this->data = data;
        this->next = NULL;  // Initially, there is no next node
    }
};

// Function to take input and create a linked list
Node<int> *takeinput()
{
    int data;
    cin >> data;
    Node<int> *head = NULL, *tail = NULL;  // Pointers to the head and tail of the linked list
    while (data != -1)
    {
        Node<int> *newNode = new Node<int>(data);  // Create a new node with the given data
        if (head == NULL)
        {
            head = newNode;  // If the list is empty, make the new node the head
            tail = newNode;  // and also the tail
        }
        else
        {
            tail->next = newNode;  // Otherwise, add the new node to the end of the list
            tail = newNode;        // and update the tail pointer
        }
        cin >> data;  // Read the next integer input
    }
    return head;  // Return the head of the linked list
}

// Function to print the elements of a linked list
void print(Node<int> *head)
{
    Node<int> *temp = head;  // Temporary pointer to traverse the list
    while (temp != NULL)
    {
        cout << temp->data << " ";  // Print the data of the current node
        temp = temp->next;          // Move to the next node
    }
    cout << endl;
}

// Function to replace duplicate values in the linked list
void changeLL(Node<int> *head)
{
    int max = 0;            // Variable to store the maximum value encountered in the list
    Node<int> *temp = head; // Temporary pointer for traversing the list

    // Find the maximum value in the linked list
    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;  // Update max if a larger value is found
        }
        temp = temp->next;  // Move to the next node
    }

    // Boolean array to keep track of whether a value has been encountered before
    bool *done = new bool[max + 1];
    for (int i = 0; i <= max; i++)
    {
        done[i] = false;  // Initialize the array to false
    }

    temp = head; // Reset temp to the head of the list

    // Traverse the list again to replace duplicate values
    while (temp != NULL)
    {
        if (done[temp->data])
        {                          // If the value has been encountered before, replace it
            temp->data = max + 1;  // Replace the duplicate value with max + 1
            max++;                 // Increment max
        }
        else
        {  // Otherwise, mark the value as encountered
            done[temp->data] = true;
        }
        temp = temp->next;  // Move to the next node
    }
    delete[] done;  // Deallocate memory for the boolean array
}

// Main function where the program execution begins
int main()
{
    Node<int> *head = takeinput();  // Input a linked list
    changeLL(head);                 // Replace duplicate values
    print(head);                    // Print the modified linked list
    return 0;
}
