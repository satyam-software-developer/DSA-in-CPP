
/* Problem statement
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

Note:
Assume that the Binary Tree contains only unique elements. 
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^3
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9  */

/*
 * Time complexity: O(N^2)
 * Space complexity: O(H)
 *
 * where N is the number of nodes in the input tree
 * and H is the height of the input tree
 */

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition of the Binary Tree Node
template <typename T>
class BinaryTreeNode
{
public:
    T data;                   // Data held by the node
    BinaryTreeNode<T> *left;  // Pointer to the left child node
    BinaryTreeNode<T> *right; // Pointer to the right child node

    // Constructor to initialize the node with data
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Helper class to store preorder and inorder arrays
class Pair
{
public:
    vector<int> preOrder; // Vector to store preorder traversal
    vector<int> inOrder;  // Vector to store inorder traversal

    // Constructor to initialize the Pair object with preorder and inorder vectors
    Pair(const vector<int> &preOrder, const vector<int> &inOrder)
    {
        this->preOrder = preOrder;
        this->inOrder = inOrder;
    }
};

// Helper method to build the tree from preorder and inorder arrays
BinaryTreeNode<int> *buildTreeHelper(const vector<int> &preOrder, int preStart, int preEnd,
                                     const vector<int> &inOrder, int inStart, int inEnd,
                                     unordered_map<int, int> &inOrderMap)
{
    // Base case: if there are no elements to construct the tree
    if (preStart > preEnd || inStart > inEnd)
    {
        return nullptr;
    }

    // The first element in preorder is the root node
    int rootVal = preOrder[preStart];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);

    // Find the index of the root element in inorder array using a hashmap for O(1) lookup
    int k = inOrderMap[rootVal];

    // Recursively build the left and right subtrees
    root->left = buildTreeHelper(preOrder, preStart + 1, preStart + (k - inStart), inOrder, inStart, k - 1, inOrderMap);
    root->right = buildTreeHelper(preOrder, preStart + (k - inStart) + 1, preEnd, inOrder, k + 1, inEnd, inOrderMap);

    return root; // Return the constructed tree
}

// Public method to initiate the tree building
BinaryTreeNode<int> *buildTree(const vector<int> &preOrder, const vector<int> &inOrder)
{
    int n = preOrder.size(); // Size of the preorder vector

    unordered_map<int, int> inOrderMap; // Hashmap to store the index of elements in inorder array
    for (int i = 0; i < n; i++)
    {
        inOrderMap[inOrder[i]] = i;
    }

    // Call the helper method to build the tree
    return buildTreeHelper(preOrder, 0, n - 1, inOrder, 0, n - 1, inOrderMap);
}

// Method to print the tree in level-order fashion
void printLevelWise(BinaryTreeNode<int> *root)
{
    // Use a queue to facilitate level-order traversal
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);    // Add the root node to the queue
    pendingNodes.push(nullptr); // Add a marker for the end of the current level

    // Continue until the queue is empty
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *frontNode = pendingNodes.front(); // Get the front node
        pendingNodes.pop();                                    // Remove the front node from the queue

        if (frontNode == nullptr)
        {
            cout << endl; // End of the current level
            if (!pendingNodes.empty())
            {
                pendingNodes.push(nullptr); // Add a marker for the next level
            }
        }
        else
        {
            cout << frontNode->data << " "; // Print the node's data
            // Add left and right children to the queue
            if (frontNode->left != nullptr)
            {
                pendingNodes.push(frontNode->left);
            }
            if (frontNode->right != nullptr)
            {
                pendingNodes.push(frontNode->right);
            }
        }
    }
}

// Main method to run the program
int main()
{
    int n;
    cin >> n; // Read the number of nodes

    vector<int> preOrder(n); // Vector to store preorder traversal
    vector<int> inOrder(n);  // Vector to store inorder traversal

    // Read preorder traversal from input
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }

    // Read inorder traversal from input
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }

    BinaryTreeNode<int> *root = buildTree(preOrder, inOrder); // Build the tree

    printLevelWise(root); // Print the tree in level-order

    return 0;
}
