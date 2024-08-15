
/* Problem statement
Given a generic tree, count and return the sum of all nodes present in the given tree.

For the above tree , total sum of all nodes is 10 + 30 + 50 + 25 + 5 + 45 + 56 + 34 = 225
Detailed explanation ( Input/output format, Notes, Images )
Input format :
Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element
Output Format :
Sum of all nodes
Sample Input :
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output :
190
Explananation
For 10, 3 children are there : 20, 30, 40
For 20. 2 children are there : 40, 50
For 30, 40, 40, 50 no child is there , so the answer for this is 10+20+30+40+40+50 = 190 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Exception class to handle empty queue scenarios
class QueueEmptyException : public exception
{
public:
    const char *what() const throw()
    {
        return "Queue is empty";
    }
};

// Node class representing each element in the queue
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

// A simple implementation of a queue using a linked list
template <typename T>
class QueueUsingLL
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    QueueUsingLL()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Returns the current size of the queue
    int getSize()
    {
        return size;
    }

    // Checks if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Returns the front element of the queue without removing it
    T front()
    {
        if (size == 0)
        {
            throw QueueEmptyException();
        }
        return head->data;
    }

    // Adds an element to the end of the queue
    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (head == nullptr)
        { // If the queue is empty
            head = newNode;
            tail = newNode;
        }
        else
        {                         // If the queue is not empty
            tail->next = newNode; // Link the new node at the end of the queue
            tail = newNode;       // Update the tail to the new node
        }
        size++;
    }

    // Removes and returns the front element of the queue
    T dequeue()
    {
        if (head == nullptr)
        { // If the queue is empty
            throw QueueEmptyException();
        }
        if (head == tail)
        {                   // If there's only one element in the queue
            tail = nullptr; // Update tail to null
        }
        Node<T> *temp = head; // Store the head node
        head = head->next;    // Move the head to the next node
        T data = temp->data;  // Store the data of the head node
        delete temp;          // Delete the old head node
        size--;
        return data; // Return the data of the dequeued node
    }
};

// Node class representing each node in the generic tree
template <typename T>
class TreeNode
{
public:
    T data;                         // Data stored in the node
    vector<TreeNode<T> *> children; // List of children nodes

    TreeNode(T data)
    {
        this->data = data; // Initialize node data
    }
};

// Function to calculate the sum of all nodes in the tree
int sumOfAllNode(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0; // Return 0 if the root is null (base case)
    }
    int total = root->data; // Start with the root's data
    for (int i = 0; i < root->children.size(); ++i)
    {                                             // Iterate over all children
        total += sumOfAllNode(root->children[i]); // Add the sum of all children recursively
    }
    return total; // Return the total sum
}

// Function to take input level-wise and construct the tree
TreeNode<int> *takeInputLevelWise()
{
    QueueUsingLL<TreeNode<int> *> pendingNodes; // Queue of nodes to process
    int rootData;
    cin >> rootData;                                   // Read root data
    TreeNode<int> *root = new TreeNode<int>(rootData); // Create root node
    pendingNodes.enqueue(root);                        // Enqueue root node

    while (!pendingNodes.isEmpty())
    {
        TreeNode<int> *currentNode = pendingNodes.dequeue(); // Dequeue a node
        int numChild;
        cin >> numChild; // Read the number of children
        for (int i = 0; i < numChild; i++)
        { // For each child
            int currentChild;
            cin >> currentChild;                                        // Read child data
            TreeNode<int> *childNode = new TreeNode<int>(currentChild); // Create child node
            pendingNodes.enqueue(childNode);                            // Enqueue child node
            currentNode->children.push_back(childNode);                 // Add child node to current node's children
        }
    }
    return root; // Return the root of the constructed tree
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise(); // Construct the tree
    cout << sumOfAllNode(root) << endl;         // Print the sum of all nodes in the tree
    return 0;
}
