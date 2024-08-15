
/*Problem statement
For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.

Example:
alt txt

If you see in the above-depicted picture of Binary Tree, we see that there are a total of two paths, starting from the root and ending at the leaves which sum up to a value of K = 13.

The paths are:
a. 2 3 4 4
b. 2 3 8

One thing to note here is, there is another path in the right sub-tree in reference to the root, which sums up to 13 but since it doesn't end at the leaf, we discard it.
The path is: 2 9 2(not a leaf)
Detailed explanation ( Input/output format, Notes, Images )
 Input Format:
The first line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

The second line of input contains an integer value K.
Output Format:
Lines equal to the total number of paths will be printed. All the node data in every path will be printed in a linear fashion taken in the order they appear from top to down bottom in the tree. A single space will separate them all.
Constriants:
1 <= N <= 10^5
0 <= K <= 10^8
Where N is the total number of nodes in the binary tree.

Time Limit: 1 second
Sample Input 1:
2 3 9 4 8 -1 2 4 -1 -1 -1 6 -1 -1 -1 -1 -1
13
 Sample Output 1:
2 3 4 4 
2 3 8
Sample Input 2:
5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
13
 Sample Output 2:
5 6 2
5 7 1 */

/*
 * Time complexity: O(N)
 * Space complexity: O(H)
 *
 * where N is the number of nodes in the input tree
 * and H is the height of the input tree
 */

#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

// Exception class for handling empty queue scenarios
class QueueEmptyException : public exception
{
public:
    const char *what() const throw()
    {
        return "Queue is empty!";
    }
};

// Binary tree node class
template <typename T>
class BinaryTreeNode
{
public:
    T data;                   // Data contained in the node
    BinaryTreeNode<T> *left;  // Reference to the left child
    BinaryTreeNode<T> *right; // Reference to the right child

    // Constructor to initialize the node with data
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Method to print all root-to-leaf paths with a given sum
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, string path, int currSum)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        currSum += root->data;
        if (currSum == k)
        {
            cout << path << root->data << endl;
        }
        return;
    }
    rootToLeafPathsSumToK(root->left, k, path + to_string(root->data) + " ", currSum + root->data);
    rootToLeafPathsSumToK(root->right, k, path + to_string(root->data) + " ", currSum + root->data);
}

// Wrapper method to initiate the recursive path finding
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    rootToLeafPathsSumToK(root, k, "", 0);
}

// Method to read input and construct the binary tree
BinaryTreeNode<int> *takeInput()
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    queue<BinaryTreeNode<int> *> pendingNodes;
    int start = 0;

    // Read the input and split it into an array of node data strings
    vector<int> nodeDatas;
    int value;
    while (iss >> value)
    {
        nodeDatas.push_back(value);
    }

    // If there is only one element, return null as the tree is empty
    if (nodeDatas.size() == 1)
    {
        return nullptr;
    }

    // Parse the root data and create the root node
    int rootData = nodeDatas[start];
    start += 1;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root);

    // Process the input to construct the tree in level order
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();

        // Parse the left child data
        int leftChildData = nodeDatas[start];
        start += 1;

        // If the left child data is not -1, create the left child node and enqueue it
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild;
            pendingNodes.push(leftChild);
        }

        // Parse the right child data
        int rightChildData = nodeDatas[start];
        start += 1;

        // If the right child data is not -1, create the right child node and enqueue it
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    // Return the constructed root of the tree
    return root;
}

// Main method
int main()
{
    // Read the input and construct the binary tree
    BinaryTreeNode<int> *root = takeInput();
    // Read the value of k
    int k;
    cin >> k;
    cin.ignore();
    // Print all root-to-leaf paths with sum equal to k
    rootToLeafPathsSumToK(root, k);
    return 0;
}
