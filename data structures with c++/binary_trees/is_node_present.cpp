
/* Problem statement
For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.

Detailed explanation ( Input/output format, Notes, Images )
 Input Format:
The first line of each test case contains elements of the first tree in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

The second line of each test case contains the node value you have to find.
Example
example

The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
Explanation:

Level 1:
The root node of the tree is 1

Level 2:
Left child of 1 = 2
Right child of 1 = 3

Level 3:
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4:
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5:
Left child of 7 = null (-1)
Right child of 7 = null (-1)

The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and so on.
The input ends when all nodes at the last level are null(-1).
Output Format:
The only line of output prints 'true' or 'false'.

The output of each test case should be printed in a separate line.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^5

Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec.
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7
Sample Output 1:
true
Explanation For Output 1:
Clearly, we can see that 7 is present in the tree. So, the output will be true.
Sample Input 2:
2 3 4 -1 -1 -1 -1
10
Sample Output 2:
false */
/*
 * Time complexity: O(N)
 * Space complexity: O(H)
 * 
 * where N is the number of nodes in the tree
 * and H is the height of the tree.
 * 
 * H is equal to log(N) for a balanced tree
 */


#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

// BinaryTreeNode class representing each node in the binary tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;                   // Data held by the node
    BinaryTreeNode<T> *left;  // Pointer to the left child
    BinaryTreeNode<T> *right; // Pointer to the right child

    // Constructor to initialize the node with data
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;  // Initially, the left child is null
        this->right = nullptr; // Initially, the right child is null
    }
};

// Function to check if a node with a specific value exists in the tree
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    // Base case: if the root is null, the node is not present
    if (root == nullptr)
    {
        return false;
    }
    // If the current node's data matches the value x, return true
    if (root->data == x)
    {
        return true;
    }
    // Recursively check the left and right subtrees
    return (isNodePresent(root->left, x) || isNodePresent(root->right, x));
}

// Function to construct the binary tree from level-order input
BinaryTreeNode<int> *takeInput()
{
    // Queue to manage the nodes while constructing the tree
    queue<BinaryTreeNode<int> *> pendingNodes;
    int start = 0;

    // Read the entire input line
    string inputLine;
    getline(cin, inputLine);
    istringstream iss(inputLine);
    string nodeData;

    // If there is only one element and it is -1, the tree is empty
    vector<int> nodeDatas;
    while (iss >> nodeData)
    {
        nodeDatas.push_back(stoi(nodeData));
    }

    if (nodeDatas.size() == 1 && nodeDatas[0] == -1)
    {
        return nullptr;
    }

    // Parse the root data and create the root node
    int rootData = nodeDatas[start];
    start += 1;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    // Add the root node to the queue
    pendingNodes.push(root);

    // Loop until there are no more nodes to process in the queue
    while (!pendingNodes.empty())
    {
        // Remove the front node from the queue
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();

        // Parse the left child data
        int leftChildData = nodeDatas[start];
        start += 1;
        // If the left child is not null, create the node and add it to the queue
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild;
            pendingNodes.push(leftChild);
        }

        // Parse the right child data
        int rightChildData = nodeDatas[start];
        start += 1;
        // If the right child is not null, create the node and add it to the queue
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    // Return the root of the constructed tree
    return root;
}

// Main method to execute the program
int main()
{
    // Construct the binary tree from the input
    BinaryTreeNode<int> *root = takeInput();
    // Read the value to be searched in the tree
    int x;
    cin >> x;

    // Check if the value x is present in the tree
    bool ans = isNodePresent(root, x);

    // Print the result
    cout << (ans ? "true" : "false") << endl;

    return 0;
}
