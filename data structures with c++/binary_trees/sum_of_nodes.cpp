
/*Problem statement
For a given Binary Tree of integers, find and return the sum of all the nodes data.

Example:
ALTIMAGE

When we sum up all the nodes data together, we get 150. Hence, the output will be 150.
Detailed explanation ( Input/output format, Notes, Images )
 Input Format:
The first and the only line of input will contain the nodes data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The first and the only line of output prints the sum of all the nodes data present in the binary tree.
Note:
You are not required to print anything explicitly. It has already been taken care of.
Constraints:
1 <= N <= 10^6
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
2 3 4 6 -1 -1 -1 -1 -1
Sample Output 1:
 15
Explanation :
The binary tree formed using the input values: 2, 3, 4, 6, -1, -1, -1, -1, -1. Hence the sum is 15. 
ALTIMAGE

Sample Input 2:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
 28 */

/*
 * Time complexity: O(N)
 * Space complexity: O(H)
 * 
 * where N is the number of nodes in the input tree and H is the height of the input tree.
 */



#include <iostream> // Include iostream for input/output operations
#include <queue>    // Include queue for the BFS approach

// Define a class for the binary tree nodes
template <typename T>
class BinaryTreeNode
{
public:
    T data;                   // Data held by the node
    BinaryTreeNode<T> *left;  // Pointer to the left child
    BinaryTreeNode<T> *right; // Pointer to the right child

    // Constructor to initialize the node with data and set children to nullptr
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to compute the sum of all nodes in the binary tree
int getSum(BinaryTreeNode<int> *root)
{
    // Base case: if the node is nullptr, return 0
    if (root == nullptr)
    {
        return 0;
    }
    // Recursively compute the sum of the left and right subtrees
    int leftSum = getSum(root->left);
    int rightSum = getSum(root->right);

    // Return the sum of the current node's data and the sums of the left and right subtrees
    return (leftSum + rightSum + root->data);
}

// Function to build a binary tree from level order input
BinaryTreeNode<int> *buildTree(const std::vector<int> &nodes)
{
    // If the input array is empty or the root node is -1, return nullptr
    if (nodes.empty() || nodes[0] == -1)
    {
        return nullptr;
    }

    // Create the root node with the first element in the array
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(nodes[0]);
    // Initialize a queue for level order tree construction
    std::queue<BinaryTreeNode<int> *> queue;
    queue.push(root);

    size_t i = 1; // Index to keep track of the current element in the array
    // Loop through the array to construct the tree
    while (i < nodes.size())
    {
        // Get the current node from the queue
        BinaryTreeNode<int> *current = queue.front();
        queue.pop();

        // If the left child is not nullptr, create the left child and add it to the queue
        if (nodes[i] != -1)
        {
            current->left = new BinaryTreeNode<int>(nodes[i]);
            queue.push(current->left);
        }
        i++;
        // If the right child is not nullptr and within bounds, create the right child and add it to the queue
        if (i < nodes.size() && nodes[i] != -1)
        {
            current->right = new BinaryTreeNode<int>(nodes[i]);
            queue.push(current->right);
        }
        i++;
    }

    // Return the root of the constructed tree
    return root;
}

int main()
{
    std::string inputLine;
    std::getline(std::cin, inputLine); // Read input values as a single line

    // Split input values into an array of integers
    std::vector<int> nodes;
    size_t pos = 0;
    while ((pos = inputLine.find(' ')) != std::string::npos)
    {
        nodes.push_back(std::stoi(inputLine.substr(0, pos)));
        inputLine.erase(0, pos + 1);
    }
    nodes.push_back(std::stoi(inputLine)); // Add the last element

    // Build the binary tree from the input array
    BinaryTreeNode<int> *root = buildTree(nodes);

    // Compute the sum of all nodes in the binary tree
    int sum = getSum(root);
    // Print the computed sum
    std::cout << sum << std::endl;

    return 0;
}
