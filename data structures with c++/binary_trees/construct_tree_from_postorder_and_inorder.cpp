/*Problem statement
For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.

Note:
Assume that the Binary Tree contains only unique elements. 
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the Postorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
4 5 2 6 7 3 1 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
2 9 3 6 10 5 
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

/*
 * Time complexity: O(N^2)
 * Space complexity: O(H)
 *
 * where N is the number of nodes in the input tree
 * and H is the height of the input tree
 */

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

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

// Helper class to store postorder and inorder arrays
class Pair
{
public:
    vector<int> postOrder; // Vector to store postorder traversal
    vector<int> inOrder;   // Vector to store inorder traversal

    // Constructor to initialize the Pair object with postorder and inorder arrays
    Pair(vector<int> postOrder, vector<int> inOrder)
    {
        this->postOrder = postOrder;
        this->inOrder = inOrder;
    }
};

// Helper method to build the tree from postorder and inorder arrays
BinaryTreeNode<int> *buildTreeHelper(vector<int> &postOrder, int postStart, int postEnd, vector<int> &inOrder,
                                     int inStart, int inEnd)
{
    // Base case: if there are no elements to construct the tree
    if (postStart > postEnd || inStart > inEnd)
    {
        return nullptr;
    }

    // The last element in postorder is the root node
    int rootVal = postOrder[postEnd];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);

    // Find the index of the root element in the inorder array
    int k = 0;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (rootVal == inOrder[i])
        {
            k = i;
            break;
        }
    }

    // Recursively build the left and right subtrees
    root->left = buildTreeHelper(postOrder, postStart, postStart + k - inStart - 1, inOrder, inStart, k - 1);
    root->right = buildTreeHelper(postOrder, postStart + k - inStart, postEnd - 1, inOrder, k + 1, inEnd);

    return root; // Return the constructed tree
}

// Public method to initiate the tree building
BinaryTreeNode<int> *buildTree(vector<int> &postOrder, vector<int> &inOrder)
{
    int n = postOrder.size(); // Size of the postorder array

    int postStart = 0;   // Start index for postorder array
    int postEnd = n - 1; // End index for postorder array
    int inStart = 0;     // Start index for inorder array
    int inEnd = n - 1;   // End index for inorder array

    // Call the helper method to build the tree
    return buildTreeHelper(postOrder, postStart, postEnd, inOrder, inStart, inEnd);
}

// Method to take input and return a Pair object containing postorder and inorder arrays
Pair takeInput()
{
    int n;
    cin >> n; // Read the number of nodes

    vector<int> post(n); // Vector to store postorder traversal
    vector<int> in(n);   // Vector to store inorder traversal

    // Read postorder traversal from input
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }

    // Read inorder traversal from input
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }

    return Pair(post, in); // Return the Pair object containing both arrays
}

// Method to print the tree in level-order fashion
void printLevelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> pendingNodes; // Use a queue to facilitate level-order traversal
    pendingNodes.push(root);                   // Add the root node to the queue
    pendingNodes.push(nullptr);                // Add a marker for the end of the current level

    // Continue until the queue is empty
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *frontNode = pendingNodes.front(); // Get the front node
        pendingNodes.pop();                                    // Remove the front node

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
    Pair input = takeInput(); // Take input for postorder and inorder arrays

    vector<int> postOrder = input.postOrder; // Get the postorder array
    vector<int> inOrder = input.inOrder;     // Get the inorder array

    BinaryTreeNode<int> *root = buildTree(postOrder, inOrder); // Build the tree

    printLevelWise(root); // Print the tree in level-order

    return 0;
}
