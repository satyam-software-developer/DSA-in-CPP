
/* Problem statement
In a given Generic Tree, replace each node with its depth value. You need to just update the data of each node, no need to return or print anything. Depth of a node is defined as the distance of the node from root. You may assume that depth of root node is 0.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : Elements in level order form separated by space (as per done in class) in the below given order:
node_data, n (number of children of node), n children, and so on for every element `
Output format :
Print the depth of each node level wise.
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Representation of Input:

Sample Output 1 : (Level wise, each level in new line)
0 
1 1 1 
2 2
Explanation
Since root is 10 , so it's depth is 0
Node 20, 30 , 40 are present at 1st level , so their depth is 1.
Node 40,50 are present at 2nd level, so their depth is 2. */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// TreeNode class representing each node in the tree
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

// Method to replace each node's data with its depth value
void replacedWithDepthValue(TreeNode<int> *root, int depth = 0)
{
    if (root == nullptr)
    {
        return;
    }
    root->data = depth;
    for (TreeNode<int> *child : root->children)
    {
        replacedWithDepthValue(child, depth + 1);
    }
}

// Method to take input level-wise and build the tree
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int currentChild;
            cin >> currentChild;
            TreeNode<int> *childNode = new TreeNode<int>(currentChild);
            currentNode->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    return root;
}

// Method to print the tree level-wise
void printTreeLevelWise(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(nullptr);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();
        if (currentNode == nullptr)
        {
            cout << endl;
            if (!pendingNodes.empty())
            {
                pendingNodes.push(nullptr);
            }
        }
        else
        {
            cout << currentNode->data << " ";
            for (TreeNode<int> *child : currentNode->children)
            {
                pendingNodes.push(child);
            }
        }
    }
}

// Main method to execute the program
int main()
{
    TreeNode<int> *root = takeInputLevelWise(); // Build the tree from input
    replacedWithDepthValue(root);               // Replace each node's data with its depth value
    printTreeLevelWise(root);                   // Print the tree level-wise
    return 0;
}
