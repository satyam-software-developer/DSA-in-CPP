
/* Problem statement
Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.

LCA
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
Example:
In this example, the green coloured node is the LCA to A and B.
Alt Text

Note:
It is defined that each node is a descendant to itself, so, if there are two nodes X and Y and X has a direct connection from Y, then Y is the lowest common ancestor.
Example:
Alt Text

Note:

1. If out of 2 nodes only one node is present, return that node. 
2. If both are not present, return -1.
3. all the node data will be unique.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 10
Sample Output 1:
8
Sample Input 2:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12 78
Sample Output 3:
-1 */

/*
 * Time complexity: O(H)
 * Space complexity: O(H)
 * 
 * where H is the height of the input BST
 */

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

// Exception for handling empty queue scenarios
class QueueEmptyException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Queue is empty!";
    }
};

// Node class for Binary Tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;                   // Data stored in the node
    BinaryTreeNode<T> *left;  // Pointer to the left child
    BinaryTreeNode<T> *right; // Pointer to the right child

    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Helper function to find the LCA in a BST
BinaryTreeNode<int> *getLCAUtil(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == nullptr || root->data == a || root->data == b)
    {
        // If root is null or root's data matches a or b, root is the LCA
        return root;
    }
    if (root->data < a && root->data < b)
    {
        // If both a and b are greater than root, LCA is in the right subtree
        return getLCAUtil(root->right, a, b);
    }
    else if (root->data > a && root->data > b)
    {
        // If both a and b are smaller than root, LCA is in the left subtree
        return getLCAUtil(root->left, a, b);
    }
    // Otherwise, root is the LCA
    BinaryTreeNode<int> *leftLCA = getLCAUtil(root->left, a, b);
    BinaryTreeNode<int> *rightLCA = getLCAUtil(root->right, a, b);
    if (leftLCA != nullptr && rightLCA != nullptr)
    {
        // If both leftLCA and rightLCA are not null, root is the LCA
        return root;
    }
    else if (leftLCA != nullptr)
    {
        // If leftLCA is not null, return leftLCA
        return leftLCA;
    }
    // Otherwise, return rightLCA
    return rightLCA;
}

// Function to find the LCA in a BST and return its data
int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    BinaryTreeNode<int> *node = getLCAUtil(root, a, b);
    return (node == nullptr) ? -1 : node->data;
}

// Function to take level order input and construct the BST
BinaryTreeNode<int> *takeInput()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    int rootData;
    ss >> rootData;
    if (rootData == -1)
    { // If the root data is -1, the tree is empty
        return nullptr;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData); // Create the root node
    pendingNodes.push(root);                                       // Add the root node to the queue

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData, rightChildData;
        ss >> leftChildData;
        if (leftChildData != -1)
        { // If left child data is not -1, create the left child node
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild; // Link the left child to the current node
            pendingNodes.push(leftChild);  // Add the left child to the queue
        }
        ss >> rightChildData;
        if (rightChildData != -1)
        { // If right child data is not -1, create the right child node
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild; // Link the right child to the current node
            pendingNodes.push(rightChild);   // Add the right child to the queue
        }
    }
    return root; // Return the root of the constructed BST
}

int main()
{
    // Read input and construct the BST
    BinaryTreeNode<int> *root = takeInput();
    string line;
    getline(cin, line);
    stringstream ss(line);
    int a, b;
    ss >> a; // Read the first node value
    ss >> b; // Read the second node value
    // Find and print the LCA of the two nodes
    cout << getLCA(root, a, b) << endl;
    return 0;
}
