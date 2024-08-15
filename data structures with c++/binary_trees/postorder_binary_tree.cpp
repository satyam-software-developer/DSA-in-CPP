
/* Problem statement
For a given Binary Tree of integers, print the post-order traversal.

ALTIMAGE

The postorder traversal for the given binary tree will be 40 50 20 30 10
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the post-order traversal of the given binary tree.
Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 Sample Output 1:
4 5 2 6 7 3 1 
Sample Input 2:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 Sample Output 1:
2 9 3 6 10 5  */

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
#include <string>
#include <stdexcept>

using namespace std;

// Custom exception for handling empty queue scenario
class QueueEmptyException : public exception
{
public:
    const char *what() const throw()
    {
        return "Queue is empty";
    }
};

// Node class for the binary tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;                // Data stored in the node
    BinaryTreeNode *left;  // Left child of the node
    BinaryTreeNode *right; // Right child of the node

    // Constructor to create a new node with given data
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Method to perform postorder traversal of the binary tree
void postOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return; // Base case: If the node is null, return
    }

    postOrder(root->left);     // Recursively traverse the left subtree
    postOrder(root->right);    // Recursively traverse the right subtree
    cout << root->data << " "; // Print the data of the node
}

// Method to build the binary tree from input
BinaryTreeNode<int> *takeInput()
{
    // Queue to store nodes whose children are yet to be added
    queue<BinaryTreeNode<int> *> pendingNodes;
    int start = 0;

    // Read the input and split it into an array of strings
    string input;
    getline(cin, input);
    stringstream ss(input);
    string nodeData;
    vector<string> nodeDatas;
    while (ss >> nodeData)
    {
        nodeDatas.push_back(nodeData);
    }

    // Read the root data and create the root node
    int rootData = stoi(nodeDatas[start]);
    start += 1;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root); // Enqueue the root node

    // Loop until all nodes are processed
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop(); // Dequeue the next node to process

        // Read and process the left child
        int leftChildData = stoi(nodeDatas[start]);
        start += 1;

        if (leftChildData != -1)
        {
            // Create the left child node and link it to the current node
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild;
            pendingNodes.push(leftChild); // Enqueue the left child
        }

        // Read and process the right child
        int rightChildData = stoi(nodeDatas[start]);
        start += 1;

        if (rightChildData != -1)
        {
            // Create the right child node and link it to the current node
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild;
            pendingNodes.push(rightChild); // Enqueue the right child
        }
    }

    return root; // Return the root of the binary tree
}

// Main method to execute the program
int main()
{
    // Build the binary tree from input
    BinaryTreeNode<int> *root = takeInput();
    // Perform postorder traversal of the binary tree
    postOrder(root);
    return 0;
}
