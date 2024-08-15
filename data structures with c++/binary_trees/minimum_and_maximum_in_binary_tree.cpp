
/* Problem statement
For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.

Return the output as an object of Pair class, which is already created.

Note:
All the node data will be unique and hence there will always exist a minimum and maximum node data.
Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints two integers denoting the minimum and the maximum data values respectively. A single line will separate them both.
Constraints:
2 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 14
Sample Input 2:
10 20 60 -1 -1 3 50 -1 -1 -1 -1 
Sample Output 2:
3 60 */

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
#include <climits>
#include <vector>

using namespace std;

// Exception class for handling empty queue scenarios
class QueueEmptyException : public exception
{
public:
    const char *what() const throw()
    {
        return "Queue is empty";
    }
};

// Node class represents an element in the linked list
template <typename T>
class Node
{
public:
    T data;        // Data contained in the node
    Node<T> *next; // Reference to the next node in the linked list

    // Constructor to initialize the node with data
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Queue implementation using linked list
template <typename T>
class QueueUsingLL
{
private:
    Node<T> *head; // Reference to the head of the queue
    Node<T> *tail; // Reference to the tail of the queue
    int size;      // Number of elements in the queue

public:
    // Constructor
    QueueUsingLL()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Method to get the current size of the queue
    int getSize()
    {
        return size;
    }

    // Method to check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Method to get the front element of the queue without removing it
    T front()
    {
        if (size == 0)
        {
            throw QueueEmptyException();
        }
        return head->data;
    }

    // Method to add an element to the queue
    void enqueue(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Method to remove and return the front element of the queue
    T dequeue()
    {
        if (head == nullptr)
        {
            throw QueueEmptyException();
        }
        if (head == tail)
        {
            tail = nullptr;
        }
        T temp = head->data;
        Node<T> *oldHead = head;
        head = head->next;
        delete oldHead;
        size--;
        return temp;
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

// Pair class to hold minimum and maximum values
template <typename T, typename U>
class Pair
{
public:
    T minimum;
    U maximum;

    Pair(T minimum, U maximum)
    {
        this->minimum = minimum;
        this->maximum = maximum;
    }
};

// Method to get minimum and maximum values from the binary tree
Pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return Pair<int, int>(INT_MAX, INT_MIN);
    }

    Pair<int, int> leftPair = getMinAndMax(root->left);
    Pair<int, int> rightPair = getMinAndMax(root->right);

    int minimum = min(root->data, min(leftPair.minimum, rightPair.minimum));
    int maximum = max(root->data, max(leftPair.maximum, rightPair.maximum));

    return Pair<int, int>(minimum, maximum);
}

// Method to read input and construct the binary tree
BinaryTreeNode<int> *takeInput()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    QueueUsingLL<BinaryTreeNode<int> *> pendingNodes;
    int start = 0;

    // Read the input and split it into an array of node data strings
    string data;
    vector<int> nodeDatas;
    while (ss >> data)
    {
        nodeDatas.push_back(stoi(data));
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
    pendingNodes.enqueue(root);

    // Process the input to construct the tree in level order
    while (!pendingNodes.isEmpty())
    {
        BinaryTreeNode<int> *currentNode = pendingNodes.dequeue();

        // Parse the left child data
        int leftChildData = nodeDatas[start];
        start += 1;

        // If the left child data is not -1, create the left child node and enqueue it
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            currentNode->left = leftChild;
            pendingNodes.enqueue(leftChild);
        }

        // Parse the right child data
        int rightChildData = nodeDatas[start];
        start += 1;

        // If the right child data is not -1, create the right child node and enqueue it
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            currentNode->right = rightChild;
            pendingNodes.enqueue(rightChild);
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
    // Get the minimum and maximum values in the tree
    Pair<int, int> pair = getMinAndMax(root);
    // Print the minimum and maximum values
    cout << pair.minimum << " " << pair.maximum << endl;

    return 0;
}
