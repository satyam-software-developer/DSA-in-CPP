
/* Problem statement
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).

Print the elements in increasing order.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line contains two integers, that denote the value of k1 and k2.
Output Format:
 The first and only line of output prints the elements which are in range k1 and k2 (both inclusive). Print the elements in increasing order.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10
Sample Output 1:
6 7 8 10 */

/*
 * Time complexity: O(N)
   Space complexity: O(H)

   where N is the number of nodes in the input BST and
   H is the height of the input BST
 */
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// Class representing a node in the binary tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to print the elements in range k1 to k2 (inclusive) in increasing order
void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    // Base case: if the current node is null, return
    if (root == NULL)
    {
        return;
    }

    // If the current node's data is within the range
    if (root->data >= k1 && root->data <= k2)
    {
        // Recursively process the left subtree
        elementsInRangeK1K2(root->left, k1, k2);
        // Print the current node's data
        cout << root->data << " ";
        // Recursively process the right subtree
        elementsInRangeK1K2(root->right, k1, k2);
    }
    else if (root->data < k1)
    {
        // If the current node's data is less than k1, process the right subtree
        elementsInRangeK1K2(root->right, k1, k2);
    }
    else if (root->data > k2)
    {
        // If the current node's data is greater than k2, process the left subtree
        elementsInRangeK1K2(root->left, k1, k2);
    }
}

// Function to take input and construct the binary tree from level-order data
BinaryTreeNode<int> *takeInput()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    string temp;
    ss >> temp;
    int rootData = stoi(temp);
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    // Loop to construct the tree using the input data
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();

        string leftChildData, rightChildData;
        if (!(ss >> leftChildData))
            break;
        if (leftChildData != "-1")
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(stoi(leftChildData));
            currentNode->left = leftChild;
            pendingNodes.push(leftChild);
        }

        if (!(ss >> rightChildData))
            break;
        if (rightChildData != "-1")
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(stoi(rightChildData));
            currentNode->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

int main()
{
    // Construct the binary tree from input data
    BinaryTreeNode<int> *root = takeInput();
    string line;
    getline(cin, line);
    stringstream ss(line);
    int k1, k2;
    ss >> k1 >> k2;
    // Print elements in range [k1, k2]
    elementsInRangeK1K2(root, k1, k2);
    return 0;
}
