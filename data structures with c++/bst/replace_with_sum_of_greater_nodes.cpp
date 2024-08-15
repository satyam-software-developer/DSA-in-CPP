
/* Problem statement
Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.

That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.

Note: You don't need to return or print, just change the data of each node.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
In the output, data of the nodes of the tree are printed in level order form. Each level of the tree is printed on a separate line.
Constraints:
Time Limit: 1 second
Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1 :
18 
36 10 
38 31 
25  */

/*
 * Time complexity: O(N)
 * Space complexity: O(H)
 * 
 * where N is the number of nodes in the input BST 
 * and H is the height of the input BST
 */

#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

// Exception for handling empty queue scenarios
class QueueEmptyException : public exception
{
};

// Queue implementation using a linked list
template <typename T>
class QueueUsingLL
{
    // Inner class representing a node in the queue
    class Node
    {
    public:
        T data;     // Data stored in the node
        Node *next; // Pointer to the next node in the queue

        // Constructor to initialize node with data
        Node(T data) : data(data), next(nullptr) {}
    };

    Node *head; // Head of the queue
    Node *tail; // Tail of the queue
    int size;   // Size of the queue

public:
    // Constructor
    QueueUsingLL() : head(nullptr), tail(nullptr), size(0) {}

    // Returns the number of elements in the queue
    int getSize() const
    {
        return size;
    }

    // Checks if the queue is empty
    bool isEmpty() const
    {
        return size == 0;
    }

    // Returns the front element of the queue without removing it
    T front()
    {
        if (isEmpty())
        {
            throw QueueEmptyException(); // Throw exception if queue is empty
        }
        return head->data; // Return the data at the head of the queue
    }

    // Adds an element to the end of the queue
    void enqueue(T element)
    {
        Node *newNode = new Node(element); // Create a new node with the given element
        if (isEmpty())
        { // If queue is empty, set both head and tail to the new node
            head = newNode;
            tail = newNode;
        }
        else
        { // Otherwise, add the new node to the end and update the tail
            tail->next = newNode;
            tail = newNode;
        }
        size++; // Increment the size of the queue
    }

    // Removes and returns the front element of the queue
    T dequeue()
    {
        if (isEmpty())
        { // Throw exception if queue is empty
            throw QueueEmptyException();
        }
        Node *temp = head; // Store the node to return
        T data = head->data;
        head = head->next; // Move head to the next node
        if (head == nullptr)
        { // If the queue is empty after removal, set tail to null
            tail = nullptr;
        }
        size--;      // Decrement the size of the queue
        delete temp; // Free the memory of the removed node
        return data; // Return the data of the removed element
    }
};

// Node class for Binary Tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;                // Data stored in the node
    BinaryTreeNode *left;  // Pointer to the left child
    BinaryTreeNode *right; // Pointer to the right child

    // Constructor to initialize a binary tree node with data
    BinaryTreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

// Helper function to replace each node's data with the sum of all nodes >= to it
int replaceWithLargerNodesSumUtil(BinaryTreeNode<int> *root, int sum)
{
    if (root == nullptr)
    { // Base case: If the node is null, return the current sum
        return sum;
    }
    // Traverse the right subtree first to handle nodes with greater values
    sum = replaceWithLargerNodesSumUtil(root->right, sum);
    // Update the current node's data by adding the accumulated sum
    root->data += sum;
    // Update the sum to include the current node's new data
    sum = root->data;
    // Traverse the left subtree
    return replaceWithLargerNodesSumUtil(root->left, sum);
}

// Public function to start the replacement process
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    replaceWithLargerNodesSumUtil(root, 0); // Initialize sum as 0 and start the recursion
}

// Function to take level-order input and construct the BST
BinaryTreeNode<int> *takeInput()
{
    string line;
    getline(cin, line); // Read input line
    istringstream iss(line);
    int rootData;
    iss >> rootData; // Read the root data
    if (rootData == -1)
    {
        return nullptr; // If root data is -1, the tree is empty
    }

    QueueUsingLL<BinaryTreeNode<int> *> pendingNodes;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData); // Create the root node
    pendingNodes.enqueue(root);                                    // Add the root node to the queue

    while (!pendingNodes.isEmpty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.dequeue(); // Dequeue the current node
        int leftChildData, rightChildData;
        if (iss >> leftChildData)
        {
            if (leftChildData != -1)
            { // If left child data is not -1, create and link the left child
                BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
                currentNode->left = leftChild;
                pendingNodes.enqueue(leftChild); // Add the left child to the queue
            }
        }
        if (iss >> rightChildData)
        {
            if (rightChildData != -1)
            { // If right child data is not -1, create and link the right child
                BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
                currentNode->right = rightChild;
                pendingNodes.enqueue(rightChild); // Add the right child to the queue
            }
        }
    }
    return root; // Return the root of the constructed BST
}

// Function to print the BST in level order
void printLevelWiseAtDiffLevel(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    { // If the tree is empty, do nothing
        return;
    }

    queue<BinaryTreeNode<int> *> q;
    q.push(root);    // Start with the root node
    q.push(nullptr); // Marker for end of level

    while (!q.empty())
    {
        BinaryTreeNode<int> *current = q.front(); // Dequeue the current node
        q.pop();
        if (current == nullptr)
        { // If we encounter the level marker
            if (!q.empty())
            { // If there are more nodes to process, print a new line
                cout << endl;
                q.push(nullptr); // Add marker for the next level
            }
        }
        else
        {
            cout << current->data << " "; // Print the current node's data
            if (current->left != nullptr)
            { // If the left child exists, enqueue it
                q.push(current->left);
            }
            if (current->right != nullptr)
            { // If the right child exists, enqueue it
                q.push(current->right);
            }
        }
    }
}

// Main function to handle input, processing, and output
int main()
{
    BinaryTreeNode<int> *root = takeInput(); // Read input and construct the BST
    replaceWithLargerNodesSum(root);         // Replace node values with sum of greater nodes
    printLevelWiseAtDiffLevel(root);         // Print the updated BST in level-order format
    return 0;
}
