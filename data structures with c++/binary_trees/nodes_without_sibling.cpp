
/* Problem statement
For a given Binary Tree of type integer, print all the nodes without any siblings.

Example Input :
1 4 5 6 -1 -1 7 20 30 80 90 -1 -1 -1 -1 -1 -1 -1 -1
Explanation:
The input tree when represented in a two-dimensional plane, it would look like this:     
alt txt

In respect to the root, node data in the left subtree that satisfy the condition of not having a sibling would be 6, taken in a top-down sequence. Similarly, for the right subtree, 7 is the node data without any sibling.

Since we print the siblings in the left-subtree first and then the siblings from the right subtree, taken in a top-down fashion, we print 6 7.
Example Output:
6 7  
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the node data in a top to down fashion with reference to the root. 
Node data in the left subtree will be printed first and then the right subtree.
A single space will separate them all.
 Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
9     */

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

// Function to print all nodes without siblings
void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    // If the left child is null and right child is not null, print the right child
    if (root->left == nullptr && root->right != nullptr)
    {
        cout << root->right->data << " ";
    }
    // If the left child is not null and right child is null, print the left child
    else if (root->left != nullptr && root->right == nullptr)
    {
        cout << root->left->data << " ";
    }
    // Recursively print nodes without siblings for the left and right subtrees
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

// Function to construct the binary tree from level-order input
BinaryTreeNode<int> *takeInput()
{
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

    // Print nodes without siblings
    printNodesWithoutSibling(root);

    return 0;
}
