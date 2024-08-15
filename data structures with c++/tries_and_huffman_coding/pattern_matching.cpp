
/* Problem statement
Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space-separated words.
The following line contains a string, that denotes the value of the pattern p.
Output Format :
The first and only line of output contains true if the pattern is present and false otherwise.
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
de
Sample Output 1 :
true
Sample Input 2 :
4
abc def ghi hg
hi
Sample Output 2 :
true
Sample Input 3 :
4
abc def ghi hg
hif
Sample Output 3 :
false */

/*
 * Time complexity: O(N * M)
 * Space complexity: O(N * M)
 * 
 * where N is the number of words in the Trie and M is the average word length
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>

// Class representing a node in the Trie
class TrieNode
{
public:
    char data;                                       // Character stored in the node
    bool isTerminating;                              // Flag indicating if this node marks the end of a word
    std::vector<std::shared_ptr<TrieNode>> children; // Vector to store child nodes for each letter a-z
    int childCount;                                  // Number of children this node has

    // Constructor to initialize a TrieNode with a given character
    TrieNode(char data) : data(data), isTerminating(false), childCount(0)
    {
        children.resize(26, nullptr); // Each node can have 26 children (for each letter a-z)
    }
};

// Main class to handle pattern matching using Trie
class PatternMatching
{
private:
    std::shared_ptr<TrieNode> root; // Root node of the Trie
public:
    // Constructor for PatternMatching
    PatternMatching() : root(std::make_shared<TrieNode>('\0')) {}

    // Method to search for a word in the Trie
    bool search(const std::string &word)
    {
        return search(root, word); // Call recursive search method
    }

    // Recursive helper method to search for a word in the Trie
    bool search(std::shared_ptr<TrieNode> root, const std::string &word)
    {
        if (word.empty())
        {                // Base case: if the word is empty
            return true; // Return true if the node terminates a word
        }
        int childIndex = word[0] - 'a';                               // Calculate index for the child node
        std::shared_ptr<TrieNode> child = root->children[childIndex]; // Get the child node
        if (!child)
        {                 // If no such child node exists
            return false; // Word not found
        }
        return search(child, word.substr(1)); // Recursively search in the child node
    }

    // Helper method to add a word to the Trie
    void add(std::shared_ptr<TrieNode> root, const std::string &word)
    {
        if (word.empty())
        {                               // Base case: if the word is empty
            root->isTerminating = true; // Mark the node as terminating a word
            return;
        }
        int childIndex = word[0] - 'a';                               // Calculate index for the child node
        std::shared_ptr<TrieNode> child = root->children[childIndex]; // Get the child node
        if (!child)
        {                                                // If no such child node exists
            child = std::make_shared<TrieNode>(word[0]); // Create a new child node
            root->children[childIndex] = child;          // Add the child node to the vector
            root->childCount++;                          // Increment child count
        }
        add(child, word.substr(1)); // Recursively add the rest of the word
    }

    // Public method to add a word to the Trie
    void add(const std::string &word)
    {
        add(root, word); // Call the recursive add method
    }

    // Method to check if a pattern matches any substring of words in the list
    bool patternMatching(const std::vector<std::string> &vect, const std::string &pattern)
    {
        // Add all suffixes of each word to the Trie
        for (const auto &word : vect)
        {
            for (size_t j = 0; j < word.length(); j++)
            {
                add(word.substr(j)); // Add each suffix of the word to the Trie
            }
        }
        return search(pattern); // Search for the pattern in the Trie
    }
};

int main()
{
    PatternMatching t; // Create an instance of PatternMatching
    int n;
    std::cin >> n;                  // Read the number of words
    std::cin.ignore();              // Ignore the newline character after the number
    std::vector<std::string> input; // Vector to store the input words
    std::string line;
    std::getline(std::cin, line); // Read the line of words
    std::istringstream iss(line);
    std::string word;
    for (int i = 0; i < n; i++)
    {
        iss >> word;
        input.push_back(word); // Add each word to the vector
    }
    std::string pattern;
    std::getline(std::cin, pattern);                       // Read the pattern to be matched
    bool result = t.patternMatching(input, pattern);       // Check the result of pattern matching
    std::cout << (result ? "true" : "false") << std::endl; // Print the result as true or false
    return 0;
}
