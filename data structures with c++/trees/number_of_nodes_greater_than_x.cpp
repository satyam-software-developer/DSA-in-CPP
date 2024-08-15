
/* Problem statement
Given a tree and an integer x, find and return number of Nodes which are greater than x.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Single Line : First Integer denotes x and rest of the elements in level order form separated by space. Order is - 
Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element 
Output Format :
Count of nodes greater than x
Sample Input 1 :
35 10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
3
Explanation
Since x=35, the elements which are greater than 35 are 40, 40, 50, so the output for this is 3.
Sample Input 2 :
10 10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 2:
5
Explanation
Since x=10, the elements which are greater than 10 are 20, 30, 40,  40, 50, so the output for this is 5. */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Exception class to handle empty queue scenarios
class QueueEmptyException : public exception
{
};

// A simple implementation of a queue using a linked list
template <typename T>
class QueueUsingLL
{
public:
    // Node class representing each element in the queue
    class Node
    {
    public:
        T data;
        Node *next;

        Node(T data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

private:
    Node *head; // Pointer to the head of the queue
    Node *tail; // Pointer to the tail of the queue
    int size;   // Number of elements in the queue

public:
    // Constructor to initialize the queue
    QueueUsingLL()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Returns the current size of the queue
    int getSize()
    {
        return size;
    }

    // Checks if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Returns the front element of the queue without removing it
    T front()
    {
        if (size == 0)
        {
            throw QueueEmptyException(); // Throws exception if queue is empty
        }
        return head->data;
    }

    // Adds an element to the end of the queue
    void enqueue(T element)
    {
        Node *newNode = new Node(element);
        if (head == nullptr)
        { // If the queue is empty
            head = newNode;
            tail = newNode;
        }
        else
        {                         // If the queue is not empty
            tail->next = newNode; // Link the new node at the end of the queue
            tail = newNode;       // Update the tail to the new node
        }
        size++;
    }

    // Removes and returns the front element of the queue
    T dequeue()
    {
        if (head == nullptr)
        {                                // If the queue is empty
            throw QueueEmptyException(); // Throws exception if queue is empty
        }
        if (head == tail)
        {                   // If there's only one element in the queue
            tail = nullptr; // Update tail to null
        }
        Node *temp = head;   // Store the head node
        head = head->next;   // Move the head to the next node
        T data = temp->data; // Store the data of the dequeued node
        delete temp;         // Delete the dequeued node
        size--;
        return data; // Return the data of the dequeued node
    }
};

// Node class representing each node in the generic tree
template <typename T>
class TreeNode
{
public:
    T data;                         // Data stored in the node
    vector<TreeNode<T> *> children; // List of children nodes

    TreeNode(T data)
    {
        this->data = data; // Initialize node data
    }
};

// Function to count the number of nodes greater than x
int numNodeGreaterThanX(TreeNode<int> *root, int x)
{
    int count = 0;
    if (root == nullptr)
    {
        return 0;
    }
    if (root->data > x)
    {
        count++;
    }
    for (TreeNode<int> *child : root->children)
    {
        count += numNodeGreaterThanX(child, x);
    }
    return count;
}

// Function to take input level-wise and construct the tree
TreeNode<int> *takeInputLevelWise()
{
    QueueUsingLL<TreeNode<int> *> pendingNodes;
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    pendingNodes.enqueue(root);

    while (!pendingNodes.isEmpty())
    {
        TreeNode<int> *currentNode = pendingNodes.dequeue();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int currentChild;
            cin >> currentChild;
            TreeNode<int> *childNode = new TreeNode<int>(currentChild);
            pendingNodes.enqueue(childNode);
            currentNode->children.push_back(childNode);
        }
    }
    return root;
}

int main()
{
    int x;
    cin >> x;
    TreeNode<int> *root = takeInputLevelWise();
    cout << numNodeGreaterThanX(root, x) << endl;
    return 0;
}
