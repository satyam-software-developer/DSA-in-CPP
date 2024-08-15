
/* Problem statement
Given two Generic trees, return true if they are structurally identical i.e. they are made of nodes with the same values arranged in the same way.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : Tree 1 elements in level order form separated by space (as per done in class) in the following order:
root_data, n (number of children of root), n children, and so on for every element.
Line 2 : Tree 2 elements in level order form separated by space (as per done in class). Order is - `
root_data, n (number of children of root), n children, and so on for every element.
Output format :
true or false
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
true
Explanation
If we draw the tree for the above inputs, both the trees will look like this. So the answer for this is true.

Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
10 3 2 30 40 2 40 50 0 0 0 0
Sample Output 2:
false */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define custom exception for queue operations
class QueueEmptyException : public exception
{
    const char *what() const noexcept override
    {
        return "Queue is empty!";
    }
};

// Queue implementation using linked list
template <typename T>
class QueueUsingLL
{
    // Node class to represent each element in the linked list
    class Node
    {
    public:
        T data;     // Data stored in the node
        Node *next; // Pointer to the next node

        Node(T data) : data(data), next(nullptr) {}
    };

    Node *head; // Pointer to the front of the queue
    Node *tail; // Pointer to the rear of the queue
    int size;   // Size of the queue

public:
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

    // Returns the front element of the queue
    T front() const
    {
        if (isEmpty())
        {
            throw QueueEmptyException(); // Throw exception if queue is empty
        }
        return head->data;
    }

    // Adds an element to the end of the queue
    void enqueue(T element)
    {
        Node *newNode = new Node(element); // Create a new node with the element
        if (head == nullptr)
        {                   // If queue is empty
            head = newNode; // Both head and tail will point to the new node
            tail = newNode;
        }
        else
        {
            tail->next = newNode; // Link the new node to the end of the queue
            tail = newNode;       // Update the tail to the new node
        }
        size++; // Increment the size of the queue
    }

    // Removes and returns the front element of the queue
    T dequeue()
    {
        if (isEmpty())
        {
            throw QueueEmptyException(); // Throw exception if queue is empty
        }
        Node *temp = head;   // Pointer to the front node
        T data = head->data; // Retrieve the data from the front node
        head = head->next;   // Move head to the next node
        if (head == nullptr)
        {
            tail = nullptr; // If queue is now empty, update tail to null
        }
        delete temp; // Free memory of the removed node
        size--;      // Decrement the size of the queue
        return data; // Return the removed data
    }
};

// TreeNode class representing a node in the generic tree
template <typename T>
class TreeNode
{
public:
    T data;                      // Data stored in the node
    vector<TreeNode *> children; // Vector of children nodes

    TreeNode(T data) : data(data) {}
};

// Function to check if two trees are structurally identical
bool checkIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        return true; // Both trees are empty
    }
    if (root1 == nullptr || root2 == nullptr)
    {
        return false; // One tree is empty while the other is not
    }
    if (root1->data != root2->data)
    {
        return false; // Data at the current nodes do not match
    }
    if (root1->children.size() != root2->children.size())
    {
        return false; // Number of children does not match
    }
    // Recursively check each pair of children
    for (size_t i = 0; i < root1->children.size(); i++)
    {
        if (!checkIdentical(root1->children[i], root2->children[i]))
        {
            return false; // Trees are not identical if any child pair does not match
        }
    }
    return true; // Trees are identical if all checks pass
}

// Function to take tree input level-wise and construct the tree
TreeNode<int> *takeInputLevelWise()
{
    QueueUsingLL<TreeNode<int> *> pendingNodes; // Queue to manage nodes
    int rootData;
    cin >> rootData;                                   // Read root data
    TreeNode<int> *root = new TreeNode<int>(rootData); // Create the root node
    pendingNodes.enqueue(root);                        // Enqueue the root node

    // Process nodes level-wise
    while (!pendingNodes.isEmpty())
    {
        TreeNode<int> *currentNode = pendingNodes.dequeue(); // Dequeue the next node to process
        int numChild;
        cin >> numChild; // Read the number of children
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;                                        // Read child data
            TreeNode<int> *childNode = new TreeNode<int>(childData); // Create a child node
            pendingNodes.enqueue(childNode);                         // Enqueue the child node
            currentNode->children.push_back(childNode);              // Add the child node to the current node's children
        }
    }
    return root; // Return the constructed tree
}

// Main function to execute the program
int main()
{
    TreeNode<int> *root1 = takeInputLevelWise();                       // Construct the first tree
    TreeNode<int> *root2 = takeInputLevelWise();                       // Construct the second tree
    cout << (checkIdentical(root1, root2) ? "true" : "false") << endl; // Check if the trees are identical and print result

    return 0;
}
