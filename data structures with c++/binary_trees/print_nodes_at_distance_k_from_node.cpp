
/* Problem statement
You are given a Binary Tree of type integer, a integer value of target node's data, and an integer value K.

Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.

Example:
For a given input tree(refer to the image below):
1. Target Node: 5
2. K = 2
alt txt

Starting from the target node 5, the nodes at distance K are 7 4 and 1.
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains two integers separated by a single space, representing the value of the target node and K, respectively.
Output Format:
All the node data at distance K from the target node will be printed on a new line.

The order in which the data is printed doesn't matter.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.
1 ≤ data of node ≤ 10^9
1 ≤ target ≤ 10^9

Time Limit: 1 sec
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3 1
Sample Output 1:
9
6
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
3 3
Sample Output 2:
4
5 */

/*
 * Time complexity: O(N)
 * Space complexity: O(H)
 *
 * where N is the number of nodes in the input binary tree and
 * H is the height of the input binary tree
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
    T data;                   // Data stored in the node
    BinaryTreeNode<T> *left;  // Left child node
    BinaryTreeNode<T> *right; // Right child node

    // Constructor to initialize the node with data
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    // Destructor to delete the left and right subtrees
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

// Helper function to print nodes that are K distance down from the given node
void nodesAtDistanceKDown(BinaryTreeNode<int> *root, int k)
{
    // Base case: if root is null, return
    if (root == nullptr)
    {
        return;
    }
    // If K is 0, print the current node's data
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    // Recur for left and right subtrees with reduced distance K-1
    nodesAtDistanceKDown(root->left, k - 1);
    nodesAtDistanceKDown(root->right, k - 1);
}

// Helper function to find the target node and print nodes at distance K
int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int target, int k)
{
    // Base case: if root is null, return -1
    if (root == nullptr)
    {
        return -1;
    }
    // If the current node is the target node
    if (root->data == target)
    {
        // Print nodes at distance K down from the target node
        nodesAtDistanceKDown(root, k);
        return 0; // Return 0 to indicate the target node's level
    }

    // Recur for left subtree
    int leftDistance = nodesAtDistanceKHelper(root->left, target, k);
    // If target node is found in left subtree
    if (leftDistance != -1)
    {
        // Check if the current node is at distance K from target node
        if (leftDistance + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            // Otherwise, find nodes at distance K in the right subtree
            nodesAtDistanceKDown(root->right, k - leftDistance - 2);
        }
        return 1 + leftDistance; // Return distance of the current node from target
    }

    // Recur for right subtree
    int rightDistance = nodesAtDistanceKHelper(root->right, target, k);
    // If target node is found in right subtree
    if (rightDistance != -1)
    {
        // Check if the current node is at distance K from target node
        if (rightDistance + 1 == k)
        {
            cout << root->data << endl;
        }
        else
        {
            // Otherwise, find nodes at distance K in the left subtree
            nodesAtDistanceKDown(root->left, k - rightDistance - 2);
        }
        return 1 + rightDistance; // Return distance of the current node from target
    }
    return -1; // Return -1 if target node is not found
}

// Main function to initiate the process
void nodesAtDistanceK(BinaryTreeNode<int> *root, int target, int k)
{
    nodesAtDistanceKHelper(root, target, k);
}

// Function to take input and build the binary tree
BinaryTreeNode<int> *takeInput()
{
    // Queue to manage nodes during tree construction
    queue<BinaryTreeNode<int> *> pendingNodes;
    // Read node data as a single line and split into a vector
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> nodeDatas;
    int temp;
    while (ss >> temp)
    {
        nodeDatas.push_back(temp);
    }

    // If the vector length is 1, return nullptr (empty tree)
    if (nodeDatas.size() == 1)
    {
        return nullptr;
    }

    // Parse root node data and create the root node
    int rootData = nodeDatas[0];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    // Add root node to the queue
    pendingNodes.push(root);

    int i = 1; // Index for accessing node data vector
    // Loop until there are pending nodes in the queue
    while (!pendingNodes.empty())
    {
        // Remove the front node from the queue
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();

        // Parse left child data and add to the current node
        int leftChildData = nodeDatas[i++];
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild;
            pendingNodes.push(leftChild);
        }

        // Parse right child data and add to the current node
        int rightChildData = nodeDatas[i++];
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root; // Return the root of the constructed binary tree
}

// Main method to run the program
int main()
{
    // Construct the binary tree from input
    BinaryTreeNode<int> *root = takeInput();
    // Read target node and K distance values
    string line;
    getline(cin, line);
    stringstream ss(line);
    int target, k;
    ss >> target >> k;

    // Print nodes at distance K from the target node
    nodesAtDistanceK(root, target, k);

    // Free the allocated memory for the tree
    delete root;

    return 0;
}
