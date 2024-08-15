
/* Problem statement
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.

Note: If array size is even, take first mid as root.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line of input contains an integer, which denotes the value of n. The following line contains n space separated integers, that denote the values of array.
Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.
Constraints:
Time Limit: 1 second
Sample Input 1:
7
1 2 3 4 5 6 7
Sample Output 1:
4 2 1 3 6 5 7  */

/*
 * Time complexity: O(N)
 * Space complexity: O(N)
 * 
 * where N is the number of nodes in the input Array
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// Class to represent a node in the binary tree
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    // Constructor to initialize the node with data
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to construct BST from a sorted array
BinaryTreeNode<int>* SortedArrayToBST(const vector<int>& arr, int start, int end) {
    // Base case: when the start index exceeds the end index
    if (start > end) {
        return nullptr;
    }

    // Find the middle element of the current array range
    int mid = start + (end - start) / 2;

    // Create a new tree node with the middle element
    BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(arr[mid]);

    // Recursively construct the left subtree with the left half of the current range
    temp->left = SortedArrayToBST(arr, start, mid - 1);

    // Recursively construct the right subtree with the right half of the current range
    temp->right = SortedArrayToBST(arr, mid + 1, end);

    // Return the constructed tree node
    return temp;
}

// Function to perform pre-order traversal of the BST and print the node values
void preOrder(BinaryTreeNode<int>* root) {
    // Base case: if the current node is null, return
    if (root == nullptr) {
        return;
    }

    // Print the data of the current node
    cout << root->data << " ";

    // Recursively perform pre-order traversal on the left subtree
    preOrder(root->left);

    // Recursively perform pre-order traversal on the right subtree
    preOrder(root->right);
}

int main() {
    // Read input from the user
    string line;
    getline(cin, line);
    stringstream ss(line);

    // Read the array size from input
    int len;
    ss >> len;

    // Initialize a vector to store the input elements
    vector<int> arr(len);

    // Check if the array has any elements
    if (len > 0) {
        // Read the array elements from input
        getline(cin, line);
        stringstream ss2(line);
        for (int i = 0; i < len; ++i) {
            ss2 >> arr[i];
        }
    }

    // Construct the BST from the sorted array
    BinaryTreeNode<int>* root = SortedArrayToBST(arr, 0, len - 1);

    // Print the pre-order traversal of the constructed BST
    preOrder(root);

    return 0;
}
