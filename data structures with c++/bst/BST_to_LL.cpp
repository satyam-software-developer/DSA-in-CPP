/* Problem statement
Given a BST, convert it into a sorted linked list. You have to return the head of LL.

Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
1<=n<=10^5
Note:
In case if you are facing any issue to solve this problem, please prefer to use the helper function.
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1


Sample Output 1:
2 5 6 7 8 10 */

/*
 * Time complexity: O(N)
 * Space complexity: O(N)
 * 
 * where N is the number of nodes in the input Array
 */
#include <iostream>
#include <queue>
#include <sstream>
#include <string>

// Node class for Binary Tree
template <typename T>
class BinaryTreeNode
{
public:
    T data;                // Data stored in the node
    BinaryTreeNode *left;  // Pointer to the left child
    BinaryTreeNode *right; // Pointer to the right child

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Node class for Linked List
template <typename T>
class LinkedListNode
{
public:
    T data;               // Data stored in the node
    LinkedListNode *next; // Pointer to the next node in the linked list

    LinkedListNode(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

// Helper function to add a new node to the linked list
LinkedListNode<int> *addNode(BinaryTreeNode<int> *currBSTNode, LinkedListNode<int> *currLLNode)
{
    LinkedListNode<int> *newNode = new LinkedListNode<int>(currBSTNode->data);
    currLLNode->next = newNode;
    return newNode;
}

// Helper function to convert BST to linked list using in-order traversal
LinkedListNode<int> *helper(BinaryTreeNode<int> *currBSTNode, LinkedListNode<int> *currLLNode)
{
    if (currBSTNode == nullptr)
    {
        return currLLNode;
    }

    // Traverse the left subtree
    currLLNode = helper(currBSTNode->left, currLLNode);

    // Add current BST node to linked list
    currLLNode = addNode(currBSTNode, currLLNode);

    // Traverse the right subtree
    currLLNode = helper(currBSTNode->right, currLLNode);

    return currLLNode;
}

// Main function to construct linked list from BST
LinkedListNode<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    // Dummy head to simplify edge cases
    LinkedListNode<int> *dummyHead = new LinkedListNode<int>(-1);
    // Convert the BST to a linked list
    helper(root, dummyHead);
    // Return the next node after dummy head as the real head of the linked list
    return dummyHead->next;
}

// Function to take level order input and construct BST
BinaryTreeNode<int> *takeInput()
{
    std::string inputLine;
    std::getline(std::cin, inputLine);
    std::istringstream iss(inputLine);

    int rootData;
    iss >> rootData;

    if (rootData == -1)
    {
        return nullptr;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    // Queue to manage nodes for level order traversal
    std::queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        iss >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild;
            pendingNodes.push(leftChild);
        }

        int rightChildData;
        iss >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}

int main()
{
    // Read input and construct the BST
    BinaryTreeNode<int> *root = takeInput();
    // Convert the BST to a sorted linked list
    LinkedListNode<int> *head = constructLinkedList(root);

    // Print the sorted linked list
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }

    return 0;
}
