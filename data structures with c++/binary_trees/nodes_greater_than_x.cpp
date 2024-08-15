
/* Problem statement
For a given a binary tree of integers and an integer X, find and return the total number of nodes of the given binary tree which are having data greater than X.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains an integer, denoting the value of X.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Output Format:
The only line of output prints the total number of nodes where the node data is greater than X.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 4 2 3 -1 -1 -1
2
Sample Output 1:
2
Explanation for Sample Input 1:
Out of the four nodes of the given binary tree, [3, 4] are the node data that are greater than X = 2.
Sample Input 2:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
5
Sample Output 2:
3 */
/*
 * Time complexity: O(N)
 * Space complexity: O(H)
 *
 * where N is the number of nodes in the input tree
 * and H is the height of the input tree
 */

#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

// Node structure for Binary Tree
template <typename T>
struct BinaryTreeNode
{
    T data;                   // Data stored in the node
    BinaryTreeNode<T> *left;  // Pointer to the left child
    BinaryTreeNode<T> *right; // Pointer to the right child

    // Constructor to initialize a new node with given data
    BinaryTreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

// Queue implementation using linked list for Binary Tree nodes
template <typename T>
class QueueUsingLL
{
    // Node structure for the queue
    struct Node
    {
        T data;     // Data stored in the node
        Node *next; // Pointer to the next node in the queue

        // Constructor to initialize a new node with given data
        Node(T data) : data(data), next(nullptr) {}
    };

    Node *head; // Head of the queue
    Node *tail; // Tail of the queue
    int size;   // Current size of the queue

public:
    // Constructor to initialize an empty queue
    QueueUsingLL() : head(nullptr), tail(nullptr), size(0) {}

    // Method to get the current size of the queue
    int getSize()
    {
        return size;
    }

    // Method to check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Method to get the front element of the queue without removing it
    T front()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }
        return head->data;
    }

    // Method to add an element to the end of the queue
    void enqueue(T data)
    {
        Node *newNode = new Node(data); // Create a new node with given data

        if (isEmpty())
        {
            head = tail = newNode; // If the queue is empty, set head and tail to the new node
        }
        else
        {
            tail->next = newNode; // Link the new node at the end of the queue
            tail = newNode;       // Update the tail to point to the new node
        }

        size++; // Increment the size of the queue
    }

    // Method to remove and return the front element of the queue
    T dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }

        T data = head->data; // Store the data of the head node
        Node *temp = head;   // Store the pointer to the head node

        head = head->next; // Move head to the next node
        delete temp;       // Delete the original head node

        size--; // Decrease the size of the queue
        if (isEmpty())
        {
            tail = nullptr; // If the queue becomes empty, set tail to nullptr
        }

        return data; // Return the data of the dequeued node
    }

    // Destructor to deallocate memory for all nodes in the queue
    ~QueueUsingLL()
    {
        while (head != nullptr)
        {
            Node *temp = head; // Store the pointer to the current head node
            head = head->next; // Move head to the next node
            delete temp;       // Delete the current head node
        }
        tail = nullptr; // Set tail to nullptr after all nodes are deleted
    }
};

// Function to count nodes greater than x in the binary tree
template <typename T>
int countNodesGreaterThanX(BinaryTreeNode<T> *root, T x)
{
    if (root == nullptr)
    {
        return 0; // Base case: If root is null, return 0
    }

    int count = (root->data > x) ? 1 : 0; // Count the current node if its data is greater than x

    // Recursively count nodes in left and right subtrees
    count += countNodesGreaterThanX(root->left, x);
    count += countNodesGreaterThanX(root->right, x);

    return count; // Return the total count of nodes greater than x
}

// Function to build the binary tree from input
template <typename T>
BinaryTreeNode<T> *takeInput()
{
    QueueUsingLL<BinaryTreeNode<T> *> pendingNodes; // Queue to store nodes whose children are yet to be added
    string input;
    getline(cin, input);    // Read the input line
    stringstream ss(input); // Create a stringstream to parse the input
    T rootData;
    ss >> rootData; // Read the root data from stringstream

    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(rootData); // Create the root node
    pendingNodes.enqueue(root);                                // Enqueue the root node

    while (!pendingNodes.isEmpty())
    {
        BinaryTreeNode<T> *currentNode = pendingNodes.dequeue(); // Dequeue the next node to process

        T leftChildData, rightChildData;
        ss >> leftChildData;  // Read the data for the left child
        ss >> rightChildData; // Read the data for the right child

        if (leftChildData != -1)
        {
            BinaryTreeNode<T> *leftChild = new BinaryTreeNode<T>(leftChildData); // Create the left child node
            currentNode->left = leftChild;                                       // Link the left child to the current node
            pendingNodes.enqueue(leftChild);                                     // Enqueue the left child for further processing
        }

        if (rightChildData != -1)
        {
            BinaryTreeNode<T> *rightChild = new BinaryTreeNode<T>(rightChildData); // Create the right child node
            currentNode->right = rightChild;                                       // Link the right child to the current node
            pendingNodes.enqueue(rightChild);                                      // Enqueue the right child for further processing
        }
    }

    return root; // Return the root of the binary tree
}

// Main function to execute the program
int main()
{
    BinaryTreeNode<int> *root = takeInput<int>(); // Build the binary tree from input

    int x;
    cin >> x; // Read the value of x from input

    int count = countNodesGreaterThanX(root, x); // Count nodes greater than x in the binary tree

    cout << count << endl; // Print the count

    return 0; // Return from main
}
