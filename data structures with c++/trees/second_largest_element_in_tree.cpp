
/* Problem statement
Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.

Detailed explanation ( Input/output format, Notes, Images )
Input format :
Elements in level order form separated by space (as per done in class). Order is -

Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element
Output format:
Second Largest node data
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
40 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// TreeNode class representing each node in the tree
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

// Pair class to store the first and second largest nodes
template <typename T>
class Pair
{
public:
    TreeNode<T> *first;
    TreeNode<T> *second;

    Pair(TreeNode<T> *first, TreeNode<T> *second)
    {
        this->first = first;
        this->second = second;
    }
};

// Helper method to find the second largest node
template <typename T>
Pair<T> *findSecondLargestHelper(TreeNode<T> *root)
{
    if (root == nullptr)
    {
        return new Pair<T>(nullptr, nullptr); // If the root is null, return a pair with null values
    }

    Pair<T> *output = new Pair<T>(root, nullptr); // Initialize the output pair with root as the first

    // Traverse each child of the root
    for (TreeNode<T> *child : root->children)
    {
        Pair<T> *childPair = findSecondLargestHelper(child); // Recursively find the largest and second largest in the subtree

        // Update the output pair based on the values from the child pair
        if (childPair->first != nullptr && childPair->first->data > output->first->data)
        {
            if (childPair->second == nullptr || childPair->second->data < output->first->data)
            {
                output->second = output->first;
                output->first = childPair->first;
            }
            else
            {
                output->first = childPair->first;
                output->second = childPair->second;
            }
        }
        else if (childPair->first != nullptr && childPair->first->data != output->first->data &&
                 (output->second == nullptr || childPair->first->data > output->second->data))
        {
            output->second = childPair->first;
        }
        else if (childPair->first != nullptr && childPair->first->data == output->first->data &&
                 childPair->second != nullptr && (output->second == nullptr || childPair->second->data > output->second->data))
        {
            output->second = childPair->second;
        }
    }
    return output;
}

// Public method to find and return the second largest node in the tree
template <typename T>
TreeNode<T> *findSecondLargest(TreeNode<T> *root)
{
    return findSecondLargestHelper(root)->second;
}

// Method to take input level-wise and build the tree
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;                                   // Read the root data
    TreeNode<int> *root = new TreeNode<int>(rootData); // Create the root node

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *currentNode = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild; // Read the number of children for the current node
        for (int i = 0; i < numChild; i++)
        {
            int currentChild;
            cin >> currentChild; // Read the data for each child
            TreeNode<int> *childNode = new TreeNode<int>(currentChild);
            pendingNodes.push(childNode);
            currentNode->children.push_back(childNode);
        }
    }
    return root; // Return the root of the constructed tree
}

// Main method to execute the program
int main()
{
    TreeNode<int> *root = takeInputLevelWise();   // Build the tree from input
    TreeNode<int> *ans = findSecondLargest(root); // Find the second largest node
    if (ans == nullptr)
    {
        cout << INT_MIN; // If no second largest node is found, print the minimum integer value
    }
    else
    {
        cout << ans->data; // Print the data of the second largest node
    }
    return 0;
}
