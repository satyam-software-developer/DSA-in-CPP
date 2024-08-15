
/* Problem statement
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).

Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of S.
Output format:
You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 1:
2 10
5 7 */
/*
 * Time complexity: O(N)
 * Space complexity: O(H)
 * 
 * where N is the number of nodes in the input BST
 * and H is the height of the input BST
 */
#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

// Node class representing each node in the binary search tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Function to count the total number of nodes in the binary search tree
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Function to print all pairs of nodes in the BST that sum to a given value S
void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    if (root == nullptr)
    {
        return;
    }
    int totalCount = countNodes(root);
    int count = 0;
    stack<BinaryTreeNode<int> *> inorder;
    stack<BinaryTreeNode<int> *> revInorder;

    // Initialize the inorder traversal stack
    BinaryTreeNode<int> *temp = root;
    while (temp != nullptr)
    {
        inorder.push(temp);
        temp = temp->left;
    }

    // Initialize the reverse inorder traversal stack
    temp = root;
    while (temp != nullptr)
    {
        revInorder.push(temp);
        temp = temp->right;
    }

    // Traverse the tree using two stacks
    while (count < totalCount - 1)
    {
        BinaryTreeNode<int> *top1 = inorder.top();
        BinaryTreeNode<int> *top2 = revInorder.top();

        // If the sum of the two nodes is equal to S, print them
        if (top1->data + top2->data == s)
        {
            cout << top1->data << " " << top2->data << endl;

            // Move the inorder traversal stack to the next node
            BinaryTreeNode<int> *top = top1;
            inorder.pop();
            count++;
            if (top->right != nullptr)
            {
                top = top->right;
                while (top != nullptr)
                {
                    inorder.push(top);
                    top = top->left;
                }
            }

            // Move the reverse inorder traversal stack to the next node
            top = top2;
            revInorder.pop();
            count++;
            if (top->left != nullptr)
            {
                top = top->left;
                while (top != nullptr)
                {
                    revInorder.push(top);
                    top = top->right;
                }
            }
        }
        else if (top1->data + top2->data > s)
        {
            // If the sum is greater than S, move the reverse inorder stack
            BinaryTreeNode<int> *top = top2;
            revInorder.pop();
            count++;
            if (top->left != nullptr)
            {
                top = top->left;
                while (top != nullptr)
                {
                    revInorder.push(top);
                    top = top->right;
                }
            }
        }
        else
        {
            // If the sum is less than S, move the inorder stack
            BinaryTreeNode<int> *top = top1;
            inorder.pop();
            count++;
            if (top->right != nullptr)
            {
                top = top->right;
                while (top != nullptr)
                {
                    inorder.push(top);
                    top = top->left;
                }
            }
        }
    }
}

// Function to read the input and construct the binary search tree
BinaryTreeNode<int> *takeInput()
{
    string line;
    getline(cin, line);
    stringstream ss(line);

    int rootData;
    ss >> rootData;
    if (rootData == -1)
    {
        return nullptr;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root);

    // Construct the tree using level order traversal
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData, rightChildData;
        ss >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild;
            pendingNodes.push(leftChild);
        }
        ss >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

// Main function to run the program
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    return 0;
}
