
/*Problem statement
Implement the function Search for the Trie class.

For a Trie, write the function for searching a word. Return true if the word is found successfully, otherwise return false.

Note : main function is given for your reference which we are using internally to test the code and all characters are from in small case (a-z). */

/*
 * Time complexity: O(N)
 * Space complexity: O(N)
 *
 * where N is the length of the word to be searched
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
            children[i] = nullptr; // Initialize all children as null
        }
        childCount = 0; // Initially, no children
    }
};

// Trie class to manage Trie operations
class Trie
{
private:
    TrieNode *root; // Root node of the Trie

    // Recursive helper method to search for a word in the Trie
    bool search(TrieNode *root, const string &word, int index)
    {
        if (index == word.length())
        {                               // Base case: if the word is fully traversed
            return root->isTerminating; // Return true if the node terminates a word
        }
        int childIndex = word[index] - 'a';           // Calculate index for the child node
        TrieNode *child = root->children[childIndex]; // Get the child node
        if (child == nullptr)
        {                 // If no such child node exists
            return false; // Word not found
        }
        return search(child, word, index + 1); // Recursively search in the child node
    }

    // Helper method to add a word to the Trie
    void add(TrieNode *root, const string &word, int index)
    {
        if (index == word.length())
        {                               // Base case: if the word is fully traversed
            root->isTerminating = true; // Mark the node as terminating a word
            return;
        }
        int childIndex = word[index] - 'a';           // Calculate index for the child node
        TrieNode *child = root->children[childIndex]; // Get the child node
        if (child == nullptr)
        {                                       // If no such child node exists
            child = new TrieNode(word[index]);  // Create a new child node
            root->children[childIndex] = child; // Add the child node to the array
            root->childCount++;                 // Increment child count
        }
        add(child, word, index + 1); // Recursively add the rest of the word
    }

public:
    // Constructor for Trie
    Trie()
    {
        root = new TrieNode('\0'); // Initialize root node with null character
    }

    // Method to search for a word in the Trie
    bool search(const string &word)
    {
        return search(root, word, 0); // Call recursive search method
    }

    // Method to add a word to the Trie
    void add(const string &word)
    {
        add(root, word, 0); // Call the recursive add method
    }
};

int main()
{
    Trie t; // Create an instance of Trie

    string input;
    while (getline(cin, input))
    {
        // Parse the input
        size_t spacePos = input.find(' ');
        string choiceStr = (spacePos == string::npos) ? input : input.substr(0, spacePos);
        string word = (spacePos == string::npos) ? "" : input.substr(spacePos + 1);

        int choice = stoi(choiceStr); // Get the choice of operation (1 for add, 2 for search)

        // Perform actions based on choice
        switch (choice)
        {
        case 1:          // Insert a word into the Trie
            t.add(word); // Add the word to the Trie
            break;
        case 2:                                                  // Search for a word in the Trie
            cout << (t.search(word) ? "true" : "false") << endl; // Print true if found, false otherwise
            break;
        default:
            return 0; // Exit the program for invalid choices
        }
    }

    return 0;
}
