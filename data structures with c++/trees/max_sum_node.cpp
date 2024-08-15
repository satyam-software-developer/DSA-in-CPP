
/* Problem statement
Given a tree, find and return the node for which sum of data of all children and the node itself is maximum. In the sum, data of node itself and data of immediate children is to be taken.

Input format :

Line 1 : Elements in level order form separated by space (as per done in class). Order is -

Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

Output format : Node with maximum sum.

Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Representation of input

Sample Output 1 :
1
Explanation
Sum of node 1 and it's child (15) is maximum among all the nodes, so the output for this is 1. */

#include <iostream>
#include <vector>
#include <climits>
#include <stdexcept>

using namespace std;

// TreeNode class
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) : data(data) {}
};

// Class to store a node and its sum
template <typename T>
class MaxNodePair
{
public:
    TreeNode<T> *node;
    int sum;
};

// Forward declaration of the helper function
template <typename T>
MaxNodePair<T> maxSumNodeHelper(TreeNode<T> *root);

// Function to find the node with the maximum sum of its data and its children's data
template <typename T>
TreeNode<T> *maxSumNode(TreeNode<T> *root)
{
    return maxSumNodeHelper(root).node;
}

// Helper function to find the node with the maximum sum
template <typename T>
MaxNodePair<T> maxSumNodeHelper(TreeNode<T> *root)
{
    if (root == nullptr)
    {
        MaxNodePair<T> pair;
        pair.node = nullptr;
        pair.sum = INT_MIN;
        return pair;
    }

    int sum = root->data;
    for (TreeNode<T> *child : root->children)
    {
        sum += child->data;
    }

    MaxNodePair<T> ans;
    ans.node = root;
    ans.sum = sum;

    for (TreeNode<T> *child : root->children)
    {
        MaxNodePair<T> childAns = maxSumNodeHelper(child);
        if (childAns.sum > ans.sum)
        {
            ans = childAns;
        }
    }

    return ans;
}

// QueueNode class
template <typename T>
class QueueNode
{
public:
    T data;
    QueueNode<T> *next;

    QueueNode(T data) : data(data), next(nullptr) {}
};

// Queue implementation using linked list
template <typename T>
class QueueUsingLL
{
private:
    QueueNode<T> *head;
    QueueNode<T> *tail;
    int size;

public:
    QueueUsingLL() : head(nullptr), tail(nullptr), size(0) {}

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {
        QueueNode<T> *newNode = new QueueNode<T>(element);
        if (tail == nullptr)
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

    T dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }
        QueueNode<T> *temp = head;
        T data = head->data;
        head = head->next;
        if (head == nullptr)
        {
            tail = nullptr;
        }
        delete temp;
        size--;
        return data;
    }

    T front()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }
        return head->data;
    }
};

// Function to take tree input level-wise and construct the tree
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
            int childData;
            cin >> childData;
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            pendingNodes.enqueue(childNode);
            currentNode->children.push_back(childNode);
        }
    }

    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *ans = maxSumNode(root);
    if (ans == nullptr)
    {
        cout << INT_MIN << endl;
    }
    else
    {
        cout << ans->data << endl;
    }

    return 0;
}
