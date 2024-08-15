
/* Problem statement
For a given Binary Tree of integers, find and return the height of the tree. Height is defined as the total number of nodes along the longest path from the root to any of the leaf node.

Example:
ALTIMAGE

Height of the given tree is 3. 
Detailed explanation ( Input/output format, Notes, Images )
 Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The first and the only line of output prints the height of the given binary tree.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
0 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
10 20 30 40 50 -1 -1 -1 -1 -1 -1
Sample Output 1:
3
Sample Input 2:
3 -1 -1
Sample Output 2:
1 */

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
#include <stdexcept>
using namespace std;

// Node structure for Binary Tree
template <typename T>
struct BinaryTreeNode
{
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

// Custom exception for queue empty scenario
struct QueueEmptyException : public exception
{
    const char *what() const throw()
    {
        return "Queue is empty";
    }
};

// Queue implementation using linked list for Binary Tree nodes
template <typename T>
class QueueUsingLL
{
    // Node structure for the queue
    struct Node
    {
        T data;
        Node *next;

        Node(T data) : data(data), next(nullptr) {}
    };

    Node *head; // Head of the queue
    Node *tail; // Tail of the queue
    int size;   // Current size of the queue

public:
    QueueUsingLL() : head(nullptr), tail(nullptr), size(0) {}

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    T front()
    {
        if (isEmpty())
        {
            throw QueueEmptyException();
        }
        return head->data;
    }

    void enqueue(T data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw QueueEmptyException();
        }
        T data = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        return data;
    }

    ~QueueUsingLL()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};

// Function to calculate the height of a binary tree
template <typename T>
int height(BinaryTreeNode<T> *root)
{
    if (root == nullptr)
    {
        return 0; // Base case: height of null node is 0
    }
    int leftHeight = height(root->left);     // Calculate height of left subtree recursively
    int rightHeight = height(root->right);   // Calculate height of right subtree recursively
    return max(leftHeight, rightHeight) + 1; // Height of current node is max of left and right subtree heights + 1
}

// Function to build the binary tree from input
template <typename T>
BinaryTreeNode<T> *takeInput()
{
    QueueUsingLL<BinaryTreeNode<T> *> pendingNodes;
    string input;
    getline(cin, input);
    stringstream ss(input);
    T rootData;
    ss >> rootData;

    if (rootData == -1)
    {
        return nullptr; // If root data is -1, return null (empty tree)
    }

    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(rootData);
    pendingNodes.enqueue(root);

    while (!pendingNodes.isEmpty())
    {
        BinaryTreeNode<T> *currentNode = pendingNodes.dequeue();

        T leftChildData, rightChildData;
        ss >> leftChildData;
        ss >> rightChildData;

        if (leftChildData != -1)
        {
            BinaryTreeNode<T> *leftChild = new BinaryTreeNode<T>(leftChildData);
            currentNode->left = leftChild;
            pendingNodes.enqueue(leftChild);
        }

        if (rightChildData != -1)
        {
            BinaryTreeNode<T> *rightChild = new BinaryTreeNode<T>(rightChildData);
            currentNode->right = rightChild;
            pendingNodes.enqueue(rightChild);
        }
    }

    return root; // Return the root of the binary tree
}

int main()
{
    // Build the binary tree from input
    BinaryTreeNode<int> *root = takeInput<int>();

    // Calculate the height of the binary tree
    int h = height(root);

    // Print the height
    cout << h << endl;

    return 0;
}
