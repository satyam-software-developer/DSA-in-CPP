
/* Problem statement
Implement the BST class which includes following functions -

1. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.

2. search
Given an element, find if that is present in BST or not. Return true or false.

3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.

4. printTree (recursive) -
Print the BST in in the following format -

For printing a node with data N, you need to follow the exact format -

N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.

There is no space in between.

You need to print all nodes in the recursive format in different lines.

Sample Input 1:
6
1 2
1 3
1 1
4
2 2
4
Sample Output 1:
2:L:1,R:3
1:
3:
3:L:1,
1:
Explanation for sample Input 1:
Explanation: The first line 6 indicates that there are 6 operations to be performed on the BST.

The subsequent lines are the operations, which can be understood as follows:
1 2: Insert 2 into the BST.

1 3: Insert 3 into the BST.

1 1: Insert 1 into the BST.

4: Print the BST in the specified format.

2 2: Search for 2 in the BST.

4: Print the BST in the specified format. */

/*
 * Time complexity: O(H) [for all operations]
 * Space complexity: O(N)
 * where N is the number of nodes in the input BST
 * and H is the height of the input BST
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Class representing a node in the binary search tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;                // Data stored in the node
    BinaryTreeNode *left;  // Pointer to the left child node
    BinaryTreeNode *right; // Pointer to the right child node

    // Constructor to initialize node with data
    BinaryTreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

// Class representing the binary search tree
class BinarySearchTree
{
private:
    BinaryTreeNode<int> *root; // Root of the binary search tree

    // Private recursive method to insert a new value into the BST
    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *root)
    {
        if (root == nullptr)
        {
            // If the current root is null, create a new node with the given data
            return new BinaryTreeNode<int>(data);
        }
        if (root->data >= data)
        {
            // If the data to insert is less than or equal to the current node's data,
            // insert it in the left subtree
            root->left = insert(data, root->left);
        }
        else
        {
            // If the data to insert is greater than the current node's data,
            // insert it in the right subtree
            root->right = insert(data, root->right);
        }
        return root; // Return the current root to maintain the tree structure
    }

    // Private recursive method to remove a value from the BST
    BinaryTreeNode<int> *remove(int data, BinaryTreeNode<int> *root)
    {
        if (root == nullptr)
        {
            return nullptr; // If the current root is null, return null (value not found)
        }
        if (data < root->data)
        {
            // If the data to remove is less than the current node's data,
            // search and remove it in the left subtree
            root->left = remove(data, root->left);
            return root; // Return the current root to maintain the tree structure
        }
        else if (data > root->data)
        {
            // If the data to remove is greater than the current node's data,
            // search and remove it in the right subtree
            root->right = remove(data, root->right);
            return root; // Return the current root to maintain the tree structure
        }
        else
        {
            // If the data matches the current node's data, this is the node to be removed
            if (root->left == nullptr && root->right == nullptr)
            {
                // If the node is a leaf node, simply remove it by returning null
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr)
            {
                // If the node has only a right child, replace it with the right child
                BinaryTreeNode<int> *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                // If the node has only a left child, replace it with the left child
                BinaryTreeNode<int> *temp = root->left;
                delete root;
                return temp;
            }
            else
            {
                // If the node has both left and right children
                // Find the minimum value in the right subtree to replace the current node
                BinaryTreeNode<int> *minNode = root->right;
                while (minNode->left != nullptr)
                {
                    minNode = minNode->left;
                }
                root->data = minNode->data;                       // Replace the current node's data with the minimum value
                root->right = remove(minNode->data, root->right); // Remove the minimum value node from the right subtree
                return root;                                      // Return the current root to maintain the tree structure
            }
        }
    }

    // Private recursive method to print the BST
    void printTree(BinaryTreeNode<int> *root)
    {
        if (root == nullptr)
        {
            return; // If the current root is null, return (base case)
        }
        // Print the current node's data and its children's data
        cout << root->data << ":";
        if (root->left != nullptr)
        {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right != nullptr)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printTree(root->left);  // Recursively print the left subtree
        printTree(root->right); // Recursively print the right subtree
    }

    // Private recursive method to search for a value in the BST
    bool search(int data, BinaryTreeNode<int> *root)
    {
        if (root == nullptr)
        {
            return false; // If the current root is null, return false (value not found)
        }
        if (root->data == data)
        {
            return true; // If the data matches the current node's data, return true
        }
        else if (data > root->data)
        {
            return search(data, root->right); // Search in the right subtree
        }
        else
        {
            return search(data, root->left); // Search in the left subtree
        }
    }

public:
    // Constructor to initialize the BST with an empty root
    BinarySearchTree() : root(nullptr) {}

    // Public method to insert a new value into the BST
    void insert(int data)
    {
        root = insert(data, root); // Call the recursive insert method
    }

    // Public method to remove a value from the BST
    void remove(int data)
    {
        root = remove(data, root); // Call the recursive remove method
    }

    // Public method to print the BST
    void printTree()
    {
        printTree(root); // Call the recursive print method
    }

    // Public method to search for a value in the BST
    bool search(int data)
    {
        return search(data, root); // Call the recursive search method
    }
};

int main()
{
    BinarySearchTree bst; // Create an instance of BinarySearchTree
    int choice, input, q;
    string line;

    // Read the number of operations
    getline(cin, line);
    istringstream iss(line);
    iss >> q;

    // Read and perform each operation
    while (q-- > 0)
    {
        getline(cin, line);
        istringstream iss(line);
        iss >> choice;
        switch (choice)
        {
        case 1: // Insert operation
            iss >> input;
            bst.insert(input);
            break;
        case 2: // Remove operation
            iss >> input;
            bst.remove(input);
            break;
        case 3: // Search operation
            iss >> input;
            cout << bst.search(input) << endl;
            break;
        default: // Print tree operation
            bst.printTree();
            break;
        }
    }

    return 0;
}
