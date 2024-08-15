
/* Problem statement
For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.

The root will remain the same. So you just need to insert nodes in the given Binary Tree.

Example:
alt txt

After making the changes to the above-depicted tree, the updated tree will look like this.
alt txt

You can see that every node in the input tree has been duplicated and inserted to the left of itself.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format :
The updated tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
 Note:
You are not required to print anything explicitly. It has already been taken care of. Just implement the function to achieve the desired structure of the tree.
Hint:
First, store the left node. Next, insert a duplicate node to the left of the current node. Then, call the function for the stored left node, which will return a modified node. Attach this modified node to the left of the duplicate node. Finally, proceed to call the function for the right node of the root
Constraints :
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 1:
10 
10 30 
20 30 60 
20 50 60 
40 50 
40 
Sample Input 2:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 2:
8 
8 10 
5 10 
5 6 
2 6 7 
2 7 */

/*
 * Time complexity : O(N)
 * Space complexity : O(H)
 *
 * where N is the Number of nodes in the tree
 * and H is the height of the tree.
 *
 * H is equal to log(N) for a balanced tree
 */

#include <iostream>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

// Exception class for handling empty queue scenarios
class QueueEmptyException : public exception
{
public:
    const char *what() const throw()
    {
        return "Queue is empty";
    }
};

// Binary tree node class
template <typename T>
class BinaryTreeNode
{
public:
    T data;                   // Data contained in the node
    BinaryTreeNode<T> *left;  // Pointer to the left child
    BinaryTreeNode<T> *right; // Pointer to the right child

    // Constructor to initialize the node with data
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Method to insert duplicate nodes to the left of each node in the binary tree
void insertDuplicateNode(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    // Create a new node with the same data as the current root
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
    // Store the left child of the current root
    BinaryTreeNode<int> *rootLeft = root->left;

    // Set the left child of the current root to the new node
    root->left = newNode;
    // Set the left child of the new node to the stored left child
    newNode->left = rootLeft;

    // Recursively process the left and right subtrees
    insertDuplicateNode(rootLeft);
    insertDuplicateNode(root->right);
}

// Method to read input and construct the binary tree
BinaryTreeNode<int> *takeInput()
{
    string inputLine;
    getline(cin, inputLine);
    stringstream ss(inputLine);

    queue<BinaryTreeNode<int> *> pendingNodes;
    int start = 0;

    // Read the input and split it into an array of node data strings
    string nodeData;
    ss >> nodeData;

    // If there is only one element, return null as the tree is empty
    if (nodeData == "-1")
    {
        return nullptr;
    }

    // Parse the root data and create the root node
    int rootData = stoi(nodeData);
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root);

    // Process the input to construct the tree in level order
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();

        // Parse the left child data
        if (!(ss >> nodeData))
            break;
        int leftChildData = stoi(nodeData);

        // If the left child data is not -1, create the left child node and enqueue it
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild;
            pendingNodes.push(leftChild);
        }

        // Parse the right child data
        if (!(ss >> nodeData))
            break;
        int rightChildData = stoi(nodeData);

        // If the right child data is not -1, create the right child node and enqueue it
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    // Return the constructed root of the tree
    return root;
}

// Method to print the binary tree in level order
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
        return;

    queue<BinaryTreeNode<int> *> primary;
    queue<BinaryTreeNode<int> *> secondary;

    primary.push(root);

    while (!primary.empty())
    {
        BinaryTreeNode<int> *current = primary.front();
        primary.pop();
        cout << current->data << " ";
        if (current->left != nullptr)
        {
            secondary.push(current->left);
        }
        if (current->right != nullptr)
        {
            secondary.push(current->right);
        }
        if (primary.empty())
        {
            swap(primary, secondary);
            cout << endl;
        }
    }
}

// Main method
int main()
{
    // Read the input and construct the binary tree
    BinaryTreeNode<int> *root = takeInput();
    // Insert duplicate nodes into the tree
    insertDuplicateNode(root);
    // Print the modified tree in level order
    printLevelWise(root);
    return 0;
}
