
/*Problem statement
For a given a Binary Tree of type integer, print the complete information of every node, when traversed in a level-order fashion.

To print the information of a node with data D, you need to follow the exact format :

           D:L:X,R:Y

Where D is the data of a node present in the binary tree. 
X and Y are the values of the left(L) and right(R) child of the node.
Print -1 if the child doesn't exist.
Example:
alt text

For the above depicted Binary Tree, the level order travel will be printed as followed:

1:L:2,R:3
2:L:4,R:-1
3:L:5,R:6
4:L:-1,R:7
5:L:-1,R:-1    
6:L:-1,R:-1
7:L:-1,R:-1

Note: There is no space in between while printing the information for each node.
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
Information of all the nodes in the Binary Tree will be printed on a different line where each node will follow a format of D:L:X,R:Y, without any spaces in between.
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
 Sample Output 1:
8:L:3,R:10
3:L:1,R:6
10:L:-1,R:14
1:L:-1,R:-1
6:L:4,R:7
14:L:13,R:-1
4:L:-1,R:-1
7:L:-1,R:-1
13:L:-1,R:-1
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
 Sample Output 2:
1:L:2,R:3
2:L:4,R:5
3:L:6,R:7
4:L:-1,R:-1
5:L:-1,R:-1
6:L:-1,R:-1
7:L:-1,R:-1 */
/*
 * Time complexity: O(N)
 * Space complexity: O(N)
 *
 * where N is the number of nodes in the input tree
 */

#include <iostream>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// Custom exception to indicate an empty queue
class QueueEmptyException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Queue is empty";
    }
};

// BinaryTreeNode class representing each node in the binary tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;                // Data held by the node
    BinaryTreeNode *left;  // Reference to the left child
    BinaryTreeNode *right; // Reference to the right child

    // Constructor to initialize the node with data
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;  // Initially, the left child is null
        this->right = nullptr; // Initially, the right child is null
    }
};

// Method to print the binary tree in level-order fashion with the specified format
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return; // If the tree is empty, return immediately
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root); // Add the root node to the queue

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *frontNode = pendingNodes.front(); // Get the front node
        pendingNodes.pop();                                    // Remove the front node
        cout << frontNode->data << ":L:";

        if (frontNode->left != nullptr)
        {
            // If the left child exists, add it to the queue and print its data
            pendingNodes.push(frontNode->left);
            cout << frontNode->left->data << ",R:";
        }
        else
        {
            // If the left child does not exist, print -1
            cout << "-1,R:";
        }

        if (frontNode->right != nullptr)
        {
            // If the right child exists, add it to the queue and print its data
            pendingNodes.push(frontNode->right);
            cout << frontNode->right->data << endl;
        }
        else
        {
            // If the right child does not exist, print -1
            cout << "-1" << endl;
        }
    }
}

// Method to construct the binary tree from level-order input
BinaryTreeNode<int> *takeInput()
{
    queue<BinaryTreeNode<int> *> pendingNodes;

    // Read input and split it into an array of node data strings
    string input;
    getline(cin, input);
    istringstream iss(input);
    string temp;
    vector<string> nodeDatas;

    while (iss >> temp)
    {
        nodeDatas.push_back(temp);
    }

    // If the input is a single "-1", return null indicating an empty tree
    if (nodeDatas.size() == 1 && nodeDatas[0] == "-1")
    {
        return nullptr;
    }

    // Parse the root data and create the root node
    int start = 0;
    int rootData = stoi(nodeDatas[start++]);
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root); // Add the root node to the queue

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front(); // Get the front node
        pendingNodes.pop();                                      // Remove the front node

        // Parse the left child data
        int leftChildData = stoi(nodeDatas[start++]);

        if (leftChildData != -1)
        {
            // If the left child exists, create and link the left child node
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild;
            pendingNodes.push(leftChild); // Add the left child to the queue
        }

        // Parse the right child data
        int rightChildData = stoi(nodeDatas[start++]);

        if (rightChildData != -1)
        {
            // If the right child exists, create and link the right child node
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild;
            pendingNodes.push(rightChild); // Add the right child to the queue
        }
    }

    return root; // Return the root of the constructed binary tree
}

int main()
{
    BinaryTreeNode<int> *root = takeInput(); // Construct the binary tree from input
    printLevelWise(root);                    // Print the tree in level-order fashion
    return 0;
}
