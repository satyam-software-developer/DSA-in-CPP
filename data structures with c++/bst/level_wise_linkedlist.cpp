
/* Problem statement
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format :
Each level linked list is printed in new line (elements are separated by space).
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9 */

/*
 * Time complexity: O(N)
 * Space complexity: O(H)
 * 
 * where N is the number of nodes in the input BST
 * and H is the height of the input BST
 */

#include <iostream>
#include <queue>
#include <limits>
#include <sstream>
#include <string>

// Class to store information about the largest BST subtree
class BstSubtreeReturn {
public:
    int max; // Maximum value in the subtree
    int min; // Minimum value in the subtree
    int height; // Height of the subtree
    bool isBST; // Boolean flag to check if the subtree is a BST
};

// Binary tree node class
template <typename T>
class BinaryTreeNode {
public:
    T data; // Data stored in the node
    BinaryTreeNode* left; // Left child of the node
    BinaryTreeNode* right; // Right child of the node

    BinaryTreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Method to find the largest BST subtree
BstSubtreeReturn largestBSTSubtreeHelper(BinaryTreeNode<int>* root) {
    if (root == nullptr) {
        BstSubtreeReturn ans;
        ans.max = std::numeric_limits<int>::min(); // Set max to minimum integer value
        ans.min = std::numeric_limits<int>::max(); // Set min to maximum integer value
        ans.isBST = true; // An empty tree is considered a BST
        ans.height = 0; // Height of an empty tree is 0
        return ans;
    }

    // Recursively find the largest BST in the left and right subtrees
    BstSubtreeReturn left = largestBSTSubtreeHelper(root->left);
    BstSubtreeReturn right = largestBSTSubtreeHelper(root->right);

    // Check if the right subtree is a BST and its min value is greater than root's data
    if (!(right.isBST && right.min > root->data)) {
        right.isBST = false;
    }
    // Check if the left subtree is a BST and its max value is less than root's data
    if (!(left.isBST && left.max < root->data)) {
        left.isBST = false;
    }

    BstSubtreeReturn ans;

    // If either left or right subtree is not a BST, or root's data is not in the correct range
    if (!left.isBST || !right.isBST || root->data < left.max || root->data > right.min) {
        // Return the larger subtree
        if (left.height > right.height) {
            left.isBST = false;
            return left;
        } else {
            right.isBST = false;
            return right;
        }
    }

    // If the current tree is a BST
    ans.isBST = true;
    ans.min = std::min(left.min, std::min(right.min, root->data)); // Update min value
    ans.max = std::max(left.max, std::max(right.max, root->data)); // Update max value
    ans.height = std::max(left.height, right.height) + 1; // Update height
    return ans;
}

// Method to find the height of the largest BST subtree
int largestBSTSubtree(BinaryTreeNode<int>* root) {
    return largestBSTSubtreeHelper(root).height;
}

// Method to take input and build the binary tree
BinaryTreeNode<int>* takeInput() {
    std::string inputLine;
    std::getline(std::cin, inputLine);
    std::istringstream iss(inputLine);
    
    int rootData;
    iss >> rootData; // Read the root data
    if (rootData == -1) {
        return nullptr; // If root data is -1, return null
    }
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData); // Create the root node
    std::queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root); // Add the root node to the queue

    while (!pendingNodes.empty()) {
        BinaryTreeNode<int>* currentNode = pendingNodes.front();
        pendingNodes.pop(); // Dequeue the front node

        int leftChildData;
        iss >> leftChildData; // Read the left child data
        if (leftChildData != -1) {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild; // Set the left child
            pendingNodes.push(leftChild); // Add the left child to the queue
        }

        int rightChildData;
        iss >> rightChildData; // Read the right child data
        if (rightChildData != -1) {
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild; // Set the right child
            pendingNodes.push(rightChild); // Add the right child to the queue
        }
    }
    return root; // Return the root of the constructed tree
}

// Main method to drive the program
int main() {
    BinaryTreeNode<int>* root = takeInput(); // Take input to construct the binary tree
    std::cout << largestBSTSubtree(root) << std::endl; // Print the height of the largest BST subtree
    return 0;
}
