
/* Problem statement
Given n number of words and an incomplete word w. You need to auto-complete that word w.

That means, find and print all the possible words which can be formed using the incomplete word w.

Note : Order of words does not matter.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains the word w, that has to be auto-completed.
Output Format :
Print all possible words in separate lines.
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
7
do dont no not note notes den
no
Sample Output 1 :
no
not
note
notes
Sample Input 2 :
7
do dont no not note notes den
de
Sample Output 2 :
den
Sample Input 3 :
7
do dont no not note notes den
nom
Sample Output 3 :
(Empty) There is no word which starts with "nom" */

/*
 * Time complexity: O(N * M)
 * Space complexity: O(N * M)
 * 
 * where N is the number of  words in the Trie and M is the average word length
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Node class for the Trie data structure
class TrieNode
{
public:
    char data;              // Character data for the node
    bool isTerminating;     // Flag to check if this node is the end of a word
    TrieNode *children[26]; // Array to hold children nodes (26 for each letter of the alphabet)
    int childCount;         // Number of children this node has

    // Constructor for TrieNode
    TrieNode(char data)
    {
        this->data = data;
        isTerminating = false; // Initially, the node does not terminate a word
        for (int i = 0; i < 26; ++i)
        {
            children[i] = nullptr; // Initialize all children to nullptr
        }
        childCount = 0; // Initially, no children
    }
};

class AutoComplete
{
private:
    TrieNode *root; // Root node of the Trie

    // Helper method to add a word to the Trie
    void add(TrieNode *root, const string &word)
    {
        if (word.length() == 0)
        {                               // Base case: if the word is empty
            root->isTerminating = true; // Mark the node as terminating a word
            return;
        }
        int childIndex = word[0] - 'a';               // Calculate index for the child node
        TrieNode *child = root->children[childIndex]; // Get the child node
        if (child == nullptr)
        {                                       // If no such child node exists
            child = new TrieNode(word[0]);      // Create a new child node
            root->children[childIndex] = child; // Add the child node to the array
            root->childCount++;                 // Increment child count
        }
        add(child, word.substr(1)); // Recursively add the rest of the word
    }

    // Method to find the Trie node corresponding to the given word prefix
    TrieNode *findRoot(TrieNode *root, const string &word)
    {
        if (word.length() == 0)
        {
            return root;
        }
        int childIndex = word[0] - 'a';
        TrieNode *child = root->children[childIndex];
        if (child == nullptr)
        {
            return nullptr;
        }
        return findRoot(child, word.substr(1));
    }

    // Helper method to find all root to leaf paths from the given node
    void allRootToLeafPaths(TrieNode *node, string output, const string &word)
    {
        if (node->childCount == 0)
        {
            if (output.length() > 0)
            {
                cout << word + output << endl;
            }
            return;
        }
        if (node->isTerminating)
        {
            cout << word + output << endl;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (node->children[i] != nullptr)
            {
                string ans = output + node->children[i]->data;
                allRootToLeafPaths(node->children[i], ans, word);
            }
        }
    }

public:
    // Constructor for AutoComplete
    AutoComplete()
    {
        root = new TrieNode('\0'); // Initialize root node with null character
    }

    // Public method to add a word to the Trie
    void add(const string &word)
    {
        add(root, word); // Call the recursive add method
    }

    // Method to auto-complete the given word
    void autoComplete(const vector<string> &input, const string &word)
    {
        for (const string &w : input)
        {
            add(w);
        }
        TrieNode *node = findRoot(root, word);
        if (node == nullptr || node->childCount == 0)
        {
            return;
        }
        allRootToLeafPaths(node, "", word);
    }
};

// Main method to take input and execute the auto-complete functionality
int main()
{
    AutoComplete t;
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input
    vector<string> input(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> input[i];
    }
    string pattern;
    cin >> pattern;
    t.autoComplete(input, pattern);
    return 0;
}
