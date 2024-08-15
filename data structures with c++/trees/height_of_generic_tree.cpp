
/* Problem statement
Given a generic tree, find and return the height of given tree. The height of a tree is defined as the longest distance from root node to any of the leaf node. Assume the height of a tree with a single node is 1.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  

For the above tree, height will be 3 as the leaf nodes which are present at longest distance are 40, 50.(10->20->40) or (10->20->50).
Output Format :
The first and only line of output prints the height of the given generic tree.
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
3 */

/*
 * Time complexity: O(N)
 * Space complexity: O(H)
 * 
 * where N is the number of nodes in the tree and 
 * H is the height/depth of the tree
 */

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

// Exception class to handle the scenario when trying to dequeue from an empty queue
class QueueEmptyException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Queue is empty";
    }
};

// Implementation of a generic queue using a linked list
template <typename T>
class QueueUsingLL
{
private:
    // Node class representing an element in the queue
    class Node
    {
    public:
        T data;     // Data stored in the node
        Node *next; // Pointer to the next node

        // Constructor to initialize the node with data
        Node(T data) : data(data), next(nullptr) {}
    };

    Node *head; // Pointer to the front of the queue
    Node *tail; // Pointer to the rear of the queue
    int size;   // Number of elements in the queue

public:
    // Constructor to initialize the queue
    QueueUsingLL() : head(nullptr), tail(nullptr), size(0) {}

    // Method to get the size of the queue
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
        if (size == 0)
        { // If the queue is empty, throw an exception
            throw QueueEmptyException();
        }
        return head->data;
    }

    // Method to add an element to the rear of the queue
    void enqueue(T element)
    {
        Node *newNode = new Node(element); // Create a new node with the given element
        if (head == nullptr)
        { // If the queue is empty
            head = newNode;
            tail = newNode;
        }
        else
        {                         // If the queue is not empty
            tail->next = newNode; // Link the new node to the end of the queue
            tail = newNode;       // Update the tail to the new node
        }
        size++; // Increment the size of the queue
    }

    // Method to remove and return the front element of the queue
    T dequeue()
    {
        if (head == nullptr)
        { // If the queue is empty, throw an exception
            throw QueueEmptyException();
        }
        if (head == tail)
        {                   // If there's only one element in the queue
            tail = nullptr; // Update the tail to null
        }
        T temp = head->data; // Store the data of the head node
        Node *oldHead = head;
        head = head->next; // Move the head to the next node
        delete oldHead;    // Delete the old head node
        size--;            // Decrement the size of the queue
        return temp;       // Return the data of the dequeued node
    }
};

// Class representing a node in a generic tree
template <typename T>
class TreeNode
{
public:
    T data;                              // Data stored in the node
    std::vector<TreeNode<T> *> children; // List of child nodes

    // Constructor to initialize the node with data
    TreeNode(T data) : data(data) {}
};

// Method to calculate the height of the generic tree
int getHeight(TreeNode<int> *root)
{
    if (root == nullptr)
    { // If the tree is empty
        return 0;
    }
    int maxChildHeight = 0; // Variable to store the maximum height among the children
    for (TreeNode<int> *child : root->children)
    {                                       // Iterate through each child of the root
        int childHeight = getHeight(child); // Recursively calculate the height of each child
        if (childHeight > maxChildHeight)
        { // Update the maximum height if a taller child is found
            maxChildHeight = childHeight;
        }
    }
    return maxChildHeight + 1; // Return the height of the tree
}

// Method to take input level-wise and construct the tree
TreeNode<int> *takeInputLevelWise()
{
    QueueUsingLL<TreeNode<int> *> pendingNodes; // Queue to store nodes whose children are to be added
    std::string line;
    std::getline(std::cin, line); // Read the entire line of input
    std::istringstream iss(line); // Create a string stream from the input line

    int rootData;
    iss >> rootData;                                   // Read the root data
    TreeNode<int> *root = new TreeNode<int>(rootData); // Create the root node
    pendingNodes.enqueue(root);                        // Enqueue the root node

    while (!pendingNodes.isEmpty())
    { // While there are nodes in the queue
        TreeNode<int> *currentNode = nullptr;
        try
        {
            currentNode = pendingNodes.dequeue(); // Dequeue the front node
        }
        catch (QueueEmptyException &e)
        {
            std::cerr << e.what() << std::endl; // Print the exception message
            return nullptr;                     // Return null if an exception occurs
        }
        int numChild;
        iss >> numChild; // Read the number of children
        for (int i = 0; i < numChild; i++)
        { // Iterate through each child
            int currentChild;
            iss >> currentChild;                                        // Read the child data
            TreeNode<int> *childNode = new TreeNode<int>(currentChild); // Create a new child node
            pendingNodes.enqueue(childNode);                            // Enqueue the child node
            currentNode->children.push_back(childNode);                 // Add the child to the current node's children list
        }
    }
    return root; // Return the constructed tree
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise(); // Take input and construct the tree
    if (root != nullptr)
    {                                              // If the tree is not null
        std::cout << getHeight(root) << std::endl; // Print the height of the tree
    }
    return 0;
}
