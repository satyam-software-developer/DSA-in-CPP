
/*Problem statement
Given two binary search trees ,merge the two given balanced BSTs into a balanced binary search tree.

Note: You just have to return the root of the balanced BST.

Give solution of O(m+n) time complexity.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 :  Elements in level order form of first tree (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2: Elements in level order form of second tree (separated by space)
(If any node does not have left or right child, take -1 in its place)
Output Format :
Print the inorder form of new BST
Sample Input 1:
2 1 3 -1 -1 -1 -1
4 -1 -1
Sample Output 1:
 1 2 3 4 */
#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

// Exception class for handling empty queue cases
class QueueEmptyException : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Queue is empty!";
    }
};

// Node class for the queue to hold data and the reference to the next node
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    // Constructor to initialize the node with data
    Node(T data) : data(data), next(nullptr) {}
};

// Queue implementation
template <typename T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    // Constructor to initialize an empty queue
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    // Method to get the current size of the queue
    int getSize() const
    {
        return size;
    }

    // Method to check if the queue is empty
    bool isEmpty() const
    {
        return size == 0;
    }

    // Method to get the front element of the queue
    // Throws an exception if the queue is empty
    T front() const
    {
        if (isEmpty())
        {
            throw QueueEmptyException();
        }
        return head->data;
    }

    // Method to add an element to the queue
    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);

        // If the queue is empty, set the new node as both head and tail
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode; // Link the new node to the last node
            tail = newNode;       // Update the tail to the new node
        }
        size++; // Increment the size of the queue
    }

    // Method to remove and return the front element of the queue
    // Throws an exception if the queue is empty
    T dequeue()
    {
        if (isEmpty())
        {
            throw QueueEmptyException();
        }

        Node<T> *temp = head;
        T data = head->data;

        head = head->next; // Move the head to the next node
        if (head == nullptr)
        {
            tail = nullptr; // If queue becomes empty, set tail to nullptr
        }

        delete temp; // Free the memory of the dequeued node
        size--;      // Decrement the size of the queue

        return data; // Return the data of the removed node
    }
};

// BinaryTreeNode class for tree nodes
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    // Constructor to initialize the node with data
    BinaryTreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

// Utility function for inorder traversal of the tree
// Prints the tree data in sorted order
void inorder(BinaryTreeNode<int> *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorder(node->left);       // Recursively traverse the left subtree
    cout << node->data << " "; // Print the data
    inorder(node->right);      // Recursively traverse the right subtree
}

// Utility Method that stores inorder traversal of a tree in a list
vector<int> storeInorderUtil(BinaryTreeNode<int> *node, vector<int> &list)
{
    if (node == nullptr)
        return list;

    // Recur on the left child
    storeInorderUtil(node->left, list);

    // Add the node's data to the list
    list.push_back(node->data);

    // Recur on the right child
    storeInorderUtil(node->right, list);

    return list;
}

// Method that stores the inorder traversal of a tree
vector<int> storeInorder(BinaryTreeNode<int> *node)
{
    vector<int> list;
    return storeInorderUtil(node, list); // Recursively store inorder traversal
}

// Method that merges two vectors into one sorted list
vector<int> merge(const vector<int> &list1, const vector<int> &list2)
{
    vector<int> list3;
    int i = 0, j = 0;

    // Traverse through both vectors
    while (i < list1.size() && j < list2.size())
    {
        // Add the smaller element to list3
        if (list1[i] < list2[j])
        {
            list3.push_back(list1[i]);
            i++;
        }
        else
        {
            list3.push_back(list2[j]);
            j++;
        }
    }

    // Add remaining elements of list1 into list3
    while (i < list1.size())
    {
        list3.push_back(list1[i]);
        i++;
    }

    // Add remaining elements of list2 into list3
    while (j < list2.size())
    {
        list3.push_back(list2[j]);
        j++;
    }

    return list3;
}

// Method that converts a sorted vector to a balanced BST
BinaryTreeNode<int> *ALtoBST(const vector<int> &list, int start, int end)
{
    // Base case
    if (start > end)
        return nullptr;

    // Get the middle element and make it root
    int mid = (start + end) / 2;
    BinaryTreeNode<int> *node = new BinaryTreeNode<int>(list[mid]);

    // Recursively construct the left subtree and make it left child of root
    node->left = ALtoBST(list, start, mid - 1);

    // Recursively construct the right subtree and make it right child of root
    node->right = ALtoBST(list, mid + 1, end);

    return node;
}

// Method that merges two BSTs into a single balanced BST
BinaryTreeNode<int> *mergeTrees(BinaryTreeNode<int> *node1, BinaryTreeNode<int> *node2)
{
    // Store inorder traversal of tree1 in list1
    vector<int> list1 = storeInorder(node1);

    // Store inorder traversal of tree2 in list2
    vector<int> list2 = storeInorder(node2);

    // Merge both lists into list3
    vector<int> list3 = merge(list1, list2);

    // Convert the merged list into a balanced BST
    return ALtoBST(list3, 0, list3.size() - 1);
}

// Method to print the merged BST using inorder traversal
void printMergeTrees(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    BinaryTreeNode<int> *node = mergeTrees(root1, root2); // Merge the two trees
    inorder(node);                                        // Print the merged tree using inorder traversal
    cout << endl;
}

// Method to take input and construct a BST from user input
BinaryTreeNode<int> *takeInput()
{
    Queue<BinaryTreeNode<int> *> pendingNodes;

    int rootData;
    cin >> rootData; // Take root data input
    if (rootData == -1)
    {
        return nullptr;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    pendingNodes.enqueue(root); // Enqueue the root node

    // Construct the tree level by level using a queue
    while (!pendingNodes.isEmpty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.dequeue(); // Dequeue the front node

        int leftChildData, rightChildData;
        cin >> leftChildData; // Take left child data input
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild;   // Set the left child
            pendingNodes.enqueue(leftChild); // Enqueue the left child
        }

        cin >> rightChildData; // Take right child data input
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild;  // Set the right child
            pendingNodes.enqueue(rightChild); // Enqueue the right child
        }
    }

    return root; // Return the root of the constructed tree
}

// Main method to run the program
int main()
{
    BinaryTreeNode<int> *root1 = takeInput(); // Take input for the first BST
    BinaryTreeNode<int> *root2 = takeInput(); // Take input for the second BST

    printMergeTrees(root1, root2); // Merge and print the merged BST

    return 0;
}
