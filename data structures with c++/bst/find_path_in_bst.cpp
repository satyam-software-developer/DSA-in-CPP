/*Problem statement
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.

Note: Assume that BST contains all unique elements.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of k.
Output Format :
The first line and only line of output prints the data of the nodes in the path from node k to root. The data of the nodes is separated by single space.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2


Sample Output 1:
2 5 8 */


/*
 * Time complexity: O(H)
 * Space complexity: O(H)
 *
 * where H is the height of the input BST
 */

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// Custom exception for queue operations
// This exception is thrown when trying to dequeue from an empty queue
class QueueEmptyException : public exception
{
public:
    const char *what() const throw()
    {
        return "Queue is empty";
    }
};

// Node class for binary tree
// Each node contains data and references to the left and right children
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    // Constructor to initialize node with data
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Method to get the path from node k to the root
// Returns a vector of integers representing the path
// If the node with value k is not found, returns an empty vector
vector<int> getPath(BinaryTreeNode<int> *root, int k)
{
    if (root == nullptr)
    {
        return {};
    }
    if (root->data == k)
    {
        return {root->data}; // Add the node data to the path
    }
    else if (k < root->data)
    {
        // If k is less than the current node's data, search in the left subtree
        vector<int> leftOutput = getPath(root->left, k);
        if (!leftOutput.empty())
        {
            leftOutput.push_back(root->data); // Add the current node's data to the path
        }
        return leftOutput;
    }
    else
    {
        // If k is greater than the current node's data, search in the right subtree
        vector<int> rightOutput = getPath(root->right, k);
        if (!rightOutput.empty())
        {
            rightOutput.push_back(root->data); // Add the current node's data to the path
        }
        return rightOutput;
    }
}

// Method to take input and build the BST
// Returns the root node of the BST
BinaryTreeNode<int> *takeInput()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    int rootData;
    ss >> rootData; // Read the root data
    if (rootData == -1)
    {
        return nullptr; // If root data is -1, return null (empty tree)
    }
    queue<BinaryTreeNode<int> *> pendingNodes;                     // Create a queue for level-order traversal
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData); // Create the root node
    pendingNodes.push(root);                                       // Enqueue the root node

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop(); // Dequeue the front node
        int leftChildData, rightChildData;
        ss >> leftChildData; // Read the left child data
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData); // Create the left child node
            currentNode->left = leftChild;                                           // Attach the left child to the current node
            pendingNodes.push(leftChild);                                            // Enqueue the left child
        }
        ss >> rightChildData; // Read the right child data
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData); // Create the right child node
            currentNode->right = rightChild;                                           // Attach the right child to the current node
            pendingNodes.push(rightChild);                                             // Enqueue the right child
        }
    }
    return root; // Return the root of the built tree
}

int main()
{
    BinaryTreeNode<int> *root = takeInput(); // Build the BST from input
    int k;
    cin >> k;                              // Read the value of k
    vector<int> output = getPath(root, k); // Get the path from node k to the root
    for (int i = output.size() - 1; i >= 0; i--)
    {
        cout << output[i] << " "; // Print the path
    }
    return 0;
}
