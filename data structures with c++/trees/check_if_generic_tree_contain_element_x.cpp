
/* Problem statement
Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.

Input format :

Line 1 : Integer x

Line 2 : Elements in level order form separated by space (as per done in class). Order is -

Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

Output format : true or false

Sample Input 1 :
40
10 3 20 30 40 2 40 50 0 0 0 0 
 Sample Output 1 :
true
Explanation
Since, 40 is present in the given tree, so the answer will be true.
Sample Input 2 :
4
10 3 20 30 40 2 40 50 0 0 0 0 
 Sample Output 2:
false
Explanation
Since, 4 is not present in the given tree, so the answer is false. */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Tree node class
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

// Function to check if the tree contains the integer x
bool checkIfContainsX(TreeNode<int> *root, int x)
{
    if (root == nullptr)
    { // If the tree is empty, return false
        return false;
    }
    if (root->data == x)
    { // If the root node contains x, return true
        return true;
    }
    // Recursively check each child
    for (auto child : root->children)
    {
        if (checkIfContainsX(child, x))
        {
            return true;
        }
    }
    return false; // If x is not found in any node, return false
}

// Function to take tree input level-wise and construct the tree
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;                                   // Read the root data
    TreeNode<int> *root = new TreeNode<int>(rootData); // Create the root node
    queue<TreeNode<int> *> pendingNodes;
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
            pendingNodes.push(childNode);
            currentNode->children.push_back(childNode); // Add the child node to the current node's children
        }
    }
    return root; // Return the root of the constructed tree
}

int main()
{
    int x;
    cin >> x;                                                       // Read the integer x
    TreeNode<int> *root = takeInputLevelWise();                     // Take input and construct the tree
    cout << (checkIfContainsX(root, x) ? "true" : "false") << endl; // Check if x is in the tree and print the result
    return 0;
}
