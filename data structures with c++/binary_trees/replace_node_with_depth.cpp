
/*Problem statement
For a given a Binary Tree of integers, replace each of its data with the depth of the tree.

Root is at depth 0, hence the root data is updated with 0. Replicate the same further going down the in the depth of the given tree.

The modified tree will be printed in the in-order fashion.

Example:
Alt text

The above tree after updating will look like this:
Alt text

Output: 2 1 2 0 2 1 2 (printed in the in-order fashion)
Detailed explanation ( Input/output format, Notes, Images )
 Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The first and the only line of output prints the updated tree in the in-order fashion.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1sec
 Sample Input 1:
2 35 10 2 3 5 2 -1 -1 -1 -1 -1 -1 -1 -1 
Sample Output 1:
2 1 2 0 2 1 2 
 Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
2 1 2 0 2 1 2  */

/*
 * Time complexity: O(N)
 * Space complexity: O(H)
 *
 * where N is the number of nodes in the input tree
 * and H is the height of the input tree
 */

#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

// Class representing a node in a binary tree
template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    // Constructor to initialize a node with given data
    BinaryTreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

// Function to modify each node in the binary tree to store its depth
template <typename T>
void changeToDepthTreeHelper(BinaryTreeNode<T> *root, int level)
{
    if (root == nullptr)
    {
        return;
    }
    root->data = level;

    changeToDepthTreeHelper(root->left, level + 1);  // Recursively process left subtree
    changeToDepthTreeHelper(root->right, level + 1); // Recursively process right subtree
}

// Function to initiate modification of each node to store its depth
template <typename T>
void changeToDepthTree(BinaryTreeNode<T> *root)
{
    changeToDepthTreeHelper(root, 0); // Start recursive depth modification from root
}

// Function to build the binary tree from input
template <typename T>
BinaryTreeNode<T> *takeInput()
{
    string input;
    getline(cin, input);
    stringstream ss(input);

    queue<BinaryTreeNode<T> *> pendingNodes;
    T rootData;
    ss >> rootData;

    if (rootData == -1)
    {
        return nullptr;
    }

    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(rootData);
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<T> *currentNode = pendingNodes.front();
        pendingNodes.pop();

        T leftChildData, rightChildData;
        ss >> leftChildData;
        if (leftChildData != -1)
        {
            currentNode->left = new BinaryTreeNode<T>(leftChildData);
            pendingNodes.push(currentNode->left);
        }

        ss >> rightChildData;
        if (rightChildData != -1)
        {
            currentNode->right = new BinaryTreeNode<T>(rightChildData);
            pendingNodes.push(currentNode->right);
        }
    }

    return root;
}

// Function to perform inorder traversal of the binary tree and print node data
template <typename T>
void inOrder(BinaryTreeNode<T> *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left);       // Traverse left subtree recursively
    cout << root->data << " "; // Print current node data
    inOrder(root->right);      // Traverse right subtree recursively
}

// Main method to execute the program
int main()
{
    BinaryTreeNode<int> *root = takeInput<int>(); // Build the binary tree from input

    changeToDepthTree(root); // Modify each node to store its depth

    inOrder(root); // Perform inorder traversal and print node data
    cout << endl;

    return 0;
}
