
/* Problem statement
Given a BST and an integer k. Find if the integer k is present in given BST or not. You have to return true, if node with data k is present, return false otherwise.

Note:
Assume that BST contains all unique elements.
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of k.
Output Format:
The first and only line of output contains a boolean value. Print true, if node with data k is present, print false otherwise. 
Constraints:
Time Limit: 1 second
Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
Sample Output 1 :
true
Sample Input 2 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 2 :
false */

/*
 * Time complexity: O(H)
 * Space complexity: O(H)
 *
 * Where H is the height of the input BST
 */
#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

// Definition of a generic Binary Tree Node class
template <typename T>
class BinaryTreeNode
{
public:
    T data;                   // Data stored in the node
    BinaryTreeNode<T> *left;  // Pointer to the left child
    BinaryTreeNode<T> *right; // Pointer to the right child

    // Constructor to initialize the node with data
    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

/**
 * Method to search for a given integer 'k' in a Binary Search Tree (BST)
 * @param root The root of the BST
 * @param k The integer to search for
 * @return true if 'k' is found in the BST, otherwise false
 */
bool searchInBST(BinaryTreeNode<int> *root, int k)
{
    // Base case: if the root is null, 'k' is not found
    if (root == nullptr)
    {
        return false;
    }

    // If the data in the root matches 'k', return true
    if (root->data == k)
    {
        return true;
    }
    // If the data in the root is greater than 'k', search in the left subtree
    else if (root->data > k)
    {
        return searchInBST(root->left, k);
    }
    // If the data in the root is less than 'k', search in the right subtree
    else
    {
        return searchInBST(root->right, k);
    }
}

/**
 * Method to take input and construct a Binary Search Tree (BST)
 * @return The root of the constructed BST
 */
BinaryTreeNode<int> *takeInput()
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    int rootData;
    iss >> rootData;

    // If the root data is -1, the tree is empty, return null
    if (rootData == -1)
    {
        return nullptr;
    }

    // Queue to manage nodes at different levels of the tree
    queue<BinaryTreeNode<int> *> pendingNodes;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData); // Create the root node
    pendingNodes.push(root);                                       // Add the root to the queue

    // While there are nodes in the queue
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front(); // Get the front node from the queue
        pendingNodes.pop();                                      // Remove the front node from the queue

        // Read the left child data
        int leftChildData;
        if (!(iss >> leftChildData))
            break;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData); // Create the left child node
            currentNode->left = leftChild;                                           // Set the left child of the current node
            pendingNodes.push(leftChild);                                            // Add the left child to the queue
        }

        // Read the right child data
        int rightChildData;
        if (!(iss >> rightChildData))
            break;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData); // Create the right child node
            currentNode->right = rightChild;                                           // Set the right child of the current node
            pendingNodes.push(rightChild);                                             // Add the right child to the queue
        }
    }
    return root; // Return the root of the constructed tree
}

int main()
{
    BinaryTreeNode<int> *root = takeInput(); // Take input and construct the BST
    int k;
    cin >> k;                                                  // Read the integer 'k' to search for
    cout << (searchInBST(root, k) ? "true" : "false") << endl; // Search for 'k' in the BST and print the result
    return 0;
}
