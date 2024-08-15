
/* Problem statement
Given a generic tree, count and return the number of leaf nodes present in the given tree. A node is said to be a leaf node if it's not having any child

Leaf nodes in the given tree are 40, 50, 30, 40. So the answer for this is 4.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
Elements in level order form separated by space (as per done in class). Order is -
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element
Output Format :
Count of leaf nodes
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
4 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node structure for the generic tree
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

// Function to count the number of leaf nodes in the tree
int countLeafNodes(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->children.size() == 0)
    {
        return 1;
    }
    int count = 0;
    // Recursively count the leaf nodes in each child
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countLeafNodes(root->children[i]);
    }
    return count;
}

// Function to take tree input level-wise and construct the tree
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;                                   // Read the root data
    TreeNode<int> *root = new TreeNode<int>(rootData); // Create the root node
    queue<TreeNode<int> *> pendingNodes;               // Queue of nodes that are entered themselves but their children aren't added yet
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild; // Read the number of children for the current node
        for (int i = 0; i < numChild; i++)
        {
            int currentChild;
            cin >> currentChild;                                        // Read each child data
            TreeNode<int> *childNode = new TreeNode<int>(currentChild); // Create the child node
            currentNode->children.push_back(childNode);                 // Add the child node to the current node's children
            pendingNodes.push(childNode);
        }
    }
    return root; // Return the root of the constructed tree
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise(); // Take input and construct the tree
    cout << countLeafNodes(root) << endl;       // Print the number of leaf nodes in the tree
    return 0;
}
