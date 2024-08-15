
/* Problem statement
Given a generic tree, print the post-order traversal of given tree.

The post-order traversal is: visit child nodes first and then root node.

For the given tree, the post order traversal will be 40 50 20 30 40 10
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 400 50 0 0 0 0 
Sample Output 1:
400 50 20 30 40 10
Explanation
For 10 , total 3 children are there : 20 30 40
For  20, total 2 children are there : 400 50
So, the output will be 400 50 20 30 40 10 */

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

// Custom exception for empty queue scenario
class QueueEmptyException : public exception
{
public:
    const char *what() const throw()
    {
        return "Queue is empty";
    }
};

// Generic tree node class
template <typename T>
class TreeNode
{
public:
    T data;                         // Data stored in the node
    vector<TreeNode<T> *> children; // List of children nodes

    TreeNode(T data)
    {
        this->data = data;
    }
};

// Prints the post-order traversal of the tree
void printPostOrder(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    for (TreeNode<int> *child : root->children)
    {
        printPostOrder(child);
    }
    cout << root->data << " ";
}

// Takes tree input level-wise and constructs the tree
TreeNode<int> *takeInputLevelWise()
{
    string inputLine;
    getline(cin, inputLine);
    istringstream iss(inputLine);
    int rootData;
    iss >> rootData; // Read the root data

    TreeNode<int> *root = new TreeNode<int>(rootData); // Create the root node
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        iss >> numChild; // Read the number of children for the current node

        for (int i = 0; i < numChild; i++)
        {
            int currentChild;
            iss >> currentChild;                                        // Read each child data
            TreeNode<int> *childNode = new TreeNode<int>(currentChild); // Create the child node
            pendingNodes.push(childNode);
            currentNode->children.push_back(childNode); // Add the child node to the current node's children
        }
    }
    return root; // Return the root of the constructed tree
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise(); // Take input and construct the tree
    printPostOrder(root);                       // Print the post-order traversal of the tree
    return 0;
}
