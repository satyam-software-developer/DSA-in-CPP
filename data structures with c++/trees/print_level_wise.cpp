
/* Problem statement
Given a generic tree, print the input tree in level wise order. That is, print the elements at same level in one line (separated by space). Print different levels in different lines.

The output for the above tree should be 
10
20 30 40
40 50
Detailed explanation ( Input/output format, Notes, Images )
Input format :
Elements in level order form separated by space (as per done in class). Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Level wise print
Sample Input :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output :
10
20 30 40 
40 50 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Node class representing each node in the generic tree
template <typename T>
class TreeNode
{
public:
    T data;                         // Data stored in the node
    vector<TreeNode<T> *> children; // List of children nodes

    TreeNode(T data)
    { // Constructor to initialize node data
        this->data = data;
    }
};

// Function to print the tree in level-wise order
void printLevelWise(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<TreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size(); // Number of nodes at current level
        while (n > 0)
        {
            TreeNode<int> *node = q.front();
            q.pop();
            cout << node->data << " ";
            for (TreeNode<int> *child : node->children)
            {
                q.push(child);
            }
            n--;
        }
        cout << endl;
    }
}

// Function to take input level-wise and construct the tree
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
            pendingNodes.push(childNode);
            currentNode->children.push_back(childNode);
        }
    }
    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    return 0;
}
