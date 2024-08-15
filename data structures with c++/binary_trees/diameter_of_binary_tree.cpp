
/* Problem statement
For a given Binary of type integer, find and return the ‘Diameter’.

Diameter of a Tree
The diameter of a tree can be defined as the maximum distance between two leaf nodes.
Here, the distance is measured in terms of the total number of nodes present along the path of the two leaf nodes, including both the leaves.
Example:
alt txt

The maximum distance can be seen between the leaf nodes 8 and 9. 
The distance is 9 as there are a total of nine nodes along the longest path from 8 to 9(inclusive of both). Hence the diameter according to the definition will be 9.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
2 4 5 6 -1 -1 7 20 30 80 90 -1 -1 8 -1 -1 9 -1 -1 -1 -1 -1 -1 
Sample Output 1:
9
Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
5 */

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
#include <string>
#include <vector>
#include <iterator>

// Pair class to store diameter and height of the tree
class Pair
{
public:
    int diameter; // Diameter of the tree
    int height;   // Height of the tree

    // Constructor to initialize diameter and height
    Pair(int diameter, int height)
    {
        this->diameter = diameter;
        this->height = height;
    }
};

class DiameterOfBinaryTree
{
public:
    // Node class representing each element in the queue
    template <typename T>
    class Node
    {
    public:
        T data;        // Data held by the node
        Node<T> *next; // Reference to the next node

        // Constructor to initialize the node with data
        Node(T data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    // Implementation of a queue using a linked list
    template <typename T>
    class QueueUsingLL
    {
    private:
        Node<T> *head; // Head of the queue
        Node<T> *tail; // Tail of the queue
        int count;     // Size of the queue

    public:
        // Constructor to initialize the queue
        QueueUsingLL()
        {
            head = nullptr;
            tail = nullptr;
            count = 0;
        }

        // Returns the size of the queue
        int size() const
        {
            return count;
        }

        // Checks if the queue is empty
        bool isEmpty() const
        {
            return count == 0;
        }

        // Returns the front element of the queue
        T front() const
        {
            if (count == 0)
            {
                throw std::runtime_error("Queue is empty");
            }
            return head->data;
        }

        // Adds an element to the queue
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

            count++;
        }

        // Removes and returns the front element of the queue
        T dequeue()
        {
            if (head == nullptr)
            {
                throw std::runtime_error("Queue is empty");
            }
            if (head == tail)
            {
                tail = nullptr;
            }
            T temp = head->data;
            Node<T> *tempNode = head;
            head = head->next;
            delete tempNode;
            count--;
            return temp;
        }
    };

    // BinaryTreeNode class representing each node in the binary tree
    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;                   // Data held by the node
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

    // Recursive helper method to calculate the diameter and height of the tree
    static Pair diameterHelper(BinaryTreeNode<int> *root)
    {
        // Base case: if the root is null, return diameter and height as 0
        if (root == nullptr)
        {
            return Pair(0, 0);
        }

        // Recursively get the diameter and height of the left subtree
        Pair leftPair = diameterHelper(root->left);
        // Recursively get the diameter and height of the right subtree
        Pair rightPair = diameterHelper(root->right);

        // Diameter of the left subtree
        int leftDiameter = leftPair.diameter;
        // Diameter of the right subtree
        int rightDiameter = rightPair.diameter;
        // Distance between the deepest nodes of the left and right subtrees
        int dist = leftPair.height + rightPair.height + 1;

        // Calculate the diameter of the current tree
        int diameter = std::max(leftDiameter, std::max(rightDiameter, dist));
        // Calculate the height of the current tree
        int height = std::max(leftPair.height, rightPair.height) + 1;

        // Return the calculated diameter and height
        return Pair(diameter, height);
    }

    // Method to calculate the diameter of the binary tree
    static int diameterOfBinaryTree(BinaryTreeNode<int> *root)
    {
        Pair pair = diameterHelper(root);
        return pair.diameter;
    }

    // Method to construct the binary tree from level-order input
    static BinaryTreeNode<int> *takeInput()
    {
        // Queue to store the nodes at each level
        QueueUsingLL<BinaryTreeNode<int> *> pendingNodes;
        int start = 0;

        // Read the entire input line and split it into individual node values
        std::string input;
        std::getline(std::cin, input);
        std::istringstream ss(input);
        std::vector<std::string> nodeDatas;
        std::string nodeData;
        while (ss >> nodeData)
        {
            nodeDatas.push_back(nodeData);
        }

        // If there is only one element and it is -1, the tree is empty
        if (nodeDatas.size() == 1 && nodeDatas[0] == "-1")
        {
            return nullptr;
        }

        // Parse the root data and create the root node
        int rootData = std::stoi(nodeDatas[start]);
        start += 1;
        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
        // Add the root node to the queue
        pendingNodes.enqueue(root);

        // Loop until there are no more nodes to process in the queue
        while (!pendingNodes.isEmpty())
        {
            BinaryTreeNode<int> *currentNode = pendingNodes.dequeue();

            // Parse the left child data
            int leftChildData = std::stoi(nodeDatas[start]);
            start += 1;
            // If the left child is not null, create the node and add it to the queue
            if (leftChildData != -1)
            {
                BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
                currentNode->left = leftChild;
                pendingNodes.enqueue(leftChild);
            }

            // Parse the right child data
            int rightChildData = std::stoi(nodeDatas[start]);
            start += 1;
            // If the right child is not null, create the node and add it to the queue
            if (rightChildData != -1)
            {
                BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
                currentNode->right = rightChild;
                pendingNodes.enqueue(rightChild);
            }
        }

        // Return the root of the constructed tree
        return root;
    }

    // Main method to execute the program
    static void main()
    {
        // Take input to construct the binary tree
        BinaryTreeNode<int> *root = takeInput();
        // Calculate the diameter of the binary tree
        int d = diameterOfBinaryTree(root);
        // Print the diameter
        std::cout << d << std::endl;
    }
};

int main()
{
    DiameterOfBinaryTree::main();
    return 0;
}
