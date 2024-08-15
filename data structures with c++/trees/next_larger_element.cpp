
/* Problem statement
Given a generic tree and an integer n. Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.

Return NULL if no node is present with value greater than n.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Line 1 : Integer n
Line 2 : Elements in level order form separated by space (as per done in class) in the given below order
node_data, n(number of children of node), n children, and so on for every element
Output format :
Node with value just greater than n.
Sample Input 1 :
18
10 3 20 30 40 2 40 50 0 0 0 0
Representation of Input

Sample Output 1 :
20
Explanation
In the given tree, the value which is just greater than 18 is 20.
Sample Input 2 :
21
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 2:
30 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Custom exception for queue operations
class QueueEmptyException : public exception
{
    const char *what() const noexcept override
    {
        return "Queue is empty";
    }
};

// Queue implementation using linked list
template <typename T>
class QueueUsingLL
{
private:
    struct Node
    {
        T data;     // Data stored in the node
        Node *next; // Pointer to the next node

        Node(T data) : data(data), next(nullptr) {}
    };

    Node *head; // Pointer to the front of the queue
    Node *tail; // Pointer to the rear of the queue
    int size;   // Size of the queue

public:
    QueueUsingLL() : head(nullptr), tail(nullptr), size(0) {}

    ~QueueUsingLL()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    int getSize() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    T front() const
    {
        if (isEmpty())
        {
            throw QueueEmptyException();
        }
        return head->data;
    }

    void enqueue(T element)
    {
        Node *newNode = new Node(element);
        if (tail)
        {
            tail->next = newNode;
        }
        else
        {
            head = newNode;
        }
        tail = newNode;
        ++size;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw QueueEmptyException();
        }
        Node *temp = head;
        T data = head->data;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        delete temp;
        --size;
        return data;
    }
};

// TreeNode class representing a node in the generic tree
template <typename T>
class TreeNode
{
public:
    T data;                      // Data stored in the node
    vector<TreeNode *> children; // List of children nodes

    TreeNode(T data) : data(data) {}
};

// Function to find the node with the value just greater than n
TreeNode<int> *findNextLargerNode(TreeNode<int> *root, int n)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode<int> *nextLargerNode = nullptr;

    if (root->data > n)
    {
        nextLargerNode = root;
    }

    for (TreeNode<int> *child : root->children)
    {
        TreeNode<int> *nextLargerInChild = findNextLargerNode(child, n);
        if (nextLargerInChild != nullptr)
        {
            if (nextLargerNode == nullptr || nextLargerNode->data > nextLargerInChild->data)
            {
                nextLargerNode = nextLargerInChild;
            }
        }
    }

    return nextLargerNode;
}

// Function to take tree input level-wise and construct the tree
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    QueueUsingLL<TreeNode<int> *> pendingNodes;
    pendingNodes.enqueue(root);

    while (!pendingNodes.isEmpty())
    {
        TreeNode<int> *currentNode = pendingNodes.dequeue();
        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; ++i)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            pendingNodes.enqueue(childNode);
            currentNode->children.push_back(childNode);
        }
    }

    return root;
}

// Main function to execute the program
int main()
{
    int n;
    cin >> n; // Read the integer n

    TreeNode<int> *root = takeInputLevelWise(); // Construct the tree

    TreeNode<int> *ans = findNextLargerNode(root, n);
    if (ans == nullptr)
    {
        cout << "No node found" << endl; // No node with value greater than n
    }
    else
    {
        cout << ans->data << endl; // Print the value of the node with value just greater than n
    }

    return 0;
}
