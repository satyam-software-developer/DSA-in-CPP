
/* Problem statement
For a given Binary Tree of type integer, update it with its corresponding mirror image.

Example:
Alt text

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the mirrored tree in a level-wise order. 
Each level will be printed on a new line. Elements printed at each level will be separated by a single line.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 
3 2 
7 6 5 4
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 2:
5 
6 10 
3 2 
9 */

/*
 * Time complexity: O(N)
 * Space complexity: O(H)
 *
 * Where N is the number of nodes in the input tree
 * and H is the height of the input tree
 */

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// Exception class for empty queue
class QueueEmptyException : public exception
{
public:
    const char *what() const throw()
    {
        return "Queue is empty";
    }
};

// Template class for queue using linked list
template <typename T>
class QueueUsingLL
{
private:
    // Node class for each element in the queue
    class Node
    {
    public:
        T data;
        Node *next;
        Node(T data) : data(data), next(nullptr) {}
    };

    Node *head; // Head of the queue
    Node *tail; // Tail of the queue
    int size;   // Size of the queue

public:
    QueueUsingLL() : head(nullptr), tail(nullptr), size(0) {}

    // Returns the size of the queue
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
            throw QueueEmptyException();
        }
        return head->data;
    }

    // Adds an element to the queue
    void enqueue(T element)
    {
        Node *newNode = new Node(element);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Removes and returns the front element of the queue
    T dequeue()
    {
        if (isEmpty())
        {
            throw QueueEmptyException();
        }
        Node *temp = head;
        T data = head->data;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        delete temp;
        size--;
        return data;
    }
};

// BinaryTreeNode class representing each node in the binary tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;                // Data held by the node
    BinaryTreeNode *left;  // Reference to the left child
    BinaryTreeNode *right; // Reference to the right child

    // Constructor to initialize the node with data
    BinaryTreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

// Method to update the binary tree to its mirror image
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    // Recursively mirror the left and right subtrees
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    // Swap the left and right children
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Method to construct the binary tree from level-order input
BinaryTreeNode<int> *takeInput()
{
    QueueUsingLL<BinaryTreeNode<int> *> pendingNodes;
    int start = 0;

    // Read the entire input line and split it into individual node values
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> nodeDatas;
    int value;
    while (iss >> value)
    {
        nodeDatas.push_back(value);
    }

    // If there is only one element and it is -1, the tree is empty
    if (nodeDatas.size() == 1 && nodeDatas[0] == -1)
    {
        return nullptr;
    }

    // Parse the root data and create the root node
    int rootData = nodeDatas[start];
    start += 1;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    // Add the root node to the queue
    pendingNodes.enqueue(root);

    // Loop until there are no more nodes to process in the queue
    while (!pendingNodes.isEmpty())
    {
        // Remove the front node from the queue
        BinaryTreeNode<int> *currentNode;
        try
        {
            currentNode = pendingNodes.dequeue();
        }
        catch (QueueEmptyException &e)
        {
            return nullptr;
        }

        // Parse the left child data
        int leftChildData = nodeDatas[start];
        start += 1;
        // If the left child is not null, create the node and add it to the queue
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild;
            pendingNodes.enqueue(leftChild);
        }

        // Parse the right child data
        int rightChildData = nodeDatas[start];
        start += 1;
        // If the right child is not null, create the node and add it to the queue
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild;
            pendingNodes.enqueue(rightChild);
        }
    }

    // Return the root of the constructed tree
    return root;
}

// Method to print the binary tree in level-wise order
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    QueueUsingLL<BinaryTreeNode<int> *> primary;
    QueueUsingLL<BinaryTreeNode<int> *> secondary;

    primary.enqueue(root);

    while (!primary.isEmpty())
    {
        BinaryTreeNode<int> *current = nullptr;
        try
        {
            current = primary.dequeue();
        }
        catch (QueueEmptyException &e)
        {
            cout << "Not possible" << endl;
        }
        cout << current->data << " ";
        if (current->left != nullptr)
        {
            secondary.enqueue(current->left);
        }
        if (current->right != nullptr)
        {
            secondary.enqueue(current->right);
        }
        if (primary.isEmpty())
        {
            cout << endl;
            swap(primary, secondary);
        }
    }
}

// Main method to execute the program
int main()
{
    BinaryTreeNode<int> *root = takeInput();

    mirrorBinaryTree(root);
    printLevelWise(root);

    return 0;
}
