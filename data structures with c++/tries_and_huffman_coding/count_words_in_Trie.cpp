
/*Problem statement
You are given the Trie class with following functions -

1. insertWord

2. removeWord

Now, you need to create one more function (named "countWords" ) which returns the number of words currently present in Trie in O(1) time complexity.

Note : You can change the already given functions in the Trie class, if required.. */

/*
 * Time complexity: O(N * M)
 * Space complexity: O(N * M)
 * 
 * where N is the number of words in the Trie and M is the average word length
 */
#include <iostream>
#include <string>
#include <vector>
#include <functional> // Include for std::function

using namespace std;

// Class representing a node in the Trie
class TrieNode
{
public:
    char data;              // Character stored in the node
    bool isTerminating;     // Flag indicating if this node marks the end of a word
    TrieNode *children[26]; // Array to store child nodes for each letter a-z
    int childCount;         // Number of children this node has

    // Constructor to initialize a TrieNode with a given character
    TrieNode(char data)
    {
        this->data = data;
        isTerminating = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        childCount = 0;
    }
};

// Class to manage the Trie and count words
class CountWordsInTrie
{
private:
    TrieNode *root; // Root node of the Trie
    int numWords;   // Counter to keep track of the number of words in the Trie

    // Helper method to remove a word from the Trie starting from a given node
    bool remove(TrieNode *root, const string &word)
    {
        if (word.length() == 0)
        {
            if (root->isTerminating)
            {
                root->isTerminating = false; // Unmark the terminating flag
                return true;
            }
            else
            {
                return false;
            }
        }
        int childIndex = word[0] - 'a'; // Calculate index of the child node
        TrieNode *child = root->children[childIndex];
        if (child == nullptr)
        {
            return false; // Word not found
        }
        bool ans = remove(child, word.substr(1));

        // We can remove child node only if it is non-terminating and its number of children are 0
        if (!child->isTerminating && child->childCount == 0)
        {
            root->children[childIndex] = nullptr;
            delete child;
            root->childCount--;
        }
        return ans;
    }

    // Helper method to add a word to the Trie starting from a given node
    bool add(TrieNode *root, const string &word)
    {
        if (word.length() == 0)
        {
            if (root->isTerminating)
            {
                return false; // Word already exists
            }
            else
            {
                root->isTerminating = true; // Mark the terminating flag
                return true;
            }
        }
        int childIndex = word[0] - 'a'; // Calculate index of the child node
        TrieNode *child = root->children[childIndex];
        if (child == nullptr)
        {
            child = new TrieNode(word[0]);
            root->children[childIndex] = child;
            root->childCount++;
        }
        return add(child, word.substr(1));
    }

public:
    // Constructor to initialize the Trie with a root node
    CountWordsInTrie()
    {
        root = new TrieNode('\0'); // Root node with an empty character
        numWords = 0;
    }

    // Method to remove a word from the Trie
    void remove(const string &word)
    {
        if (remove(root, word))
        {
            numWords--; // Decrement the word count if the word was successfully removed
        }
    }

    // Public method to add a word to the Trie
    void add(const string &word)
    {
        if (add(root, word))
        {
            numWords++; // Increment the word count if the word was successfully added
        }
    }

    // Method to get the number of words in the Trie
    int countWords() const
    {
        return numWords;
    }

    // Destructor to clean up memory
    ~CountWordsInTrie()
    {
        // Helper function to delete all nodes
        function<void(TrieNode *)> deleteTrie = [&](TrieNode *node)
        {
            for (int i = 0; i < 26; ++i)
            {
                if (node->children[i] != nullptr)
                {
                    deleteTrie(node->children[i]);
                }
            }
            delete node;
        };

        deleteTrie(root);
    }
};

// Main method to run the program
int main()
{
    CountWordsInTrie t; // Create an instance of the Trie
    string input;
    getline(cin, input); // Read input line

    vector<string> inputStrings;
    string token;
    for (auto &ch : input)
    {
        if (ch == ' ')
        {
            if (!token.empty())
            {
                inputStrings.push_back(token);
                token.clear();
            }
        }
        else
        {
            token += ch;
        }
    }
    if (!token.empty())
    {
        inputStrings.push_back(token);
    }

    int choice = stoi(inputStrings[0]); // First element is the choice
    string word = "Null";               // Default word
    if (inputStrings.size() != 1)
    {
        word = inputStrings[1]; // Second element is the word
    }

    // Loop to process input commands
    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // Insert
            t.add(word);
            break;
        case 2: // Remove
            t.remove(word);
            break;
        case 3: // Count words
            cout << t.countWords() << endl;
            break;
        default: // Exit on invalid choice
            return 0;
        }

        getline(cin, input); // Read next input line
        inputStrings.clear();
        token.clear();
        for (auto &ch : input)
        {
            if (ch == ' ')
            {
                if (!token.empty())
                {
                    inputStrings.push_back(token);
                    token.clear();
                }
            }
            else
            {
                token += ch;
            }
        }
        if (!token.empty())
        {
            inputStrings.push_back(token);
        }

        choice = stoi(inputStrings[0]); // Update choice
        if (inputStrings.size() != 1)
        {
            word = inputStrings[1]; // Update word
        }
    }

    return 0;
}
