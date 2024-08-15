
/*Problem statement
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome or not.

Note: The function should return either true or false. You don't have to print anything.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.
Output Format :
The first and only line of output contains true if the conditions described in the task are met and false otherwise.
Constraints:
0 <= n <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome
Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.' */

/*
 * ----------The Approach We Have Taken To Implement This Problem ------------------
 * 
 * The approach we have taken to solve this problem is to store
 * the reverse of each of the words in the Trie. We then iterate
 * over the words and search that does the Trie contains the same 
 * word or not .
 * 
 * It may happen that some parts of the word or a substring exist
 * in the Trie. We check for the remaining part of the string to 
 * be a palindrome or not.
 * 
 * Vise versa of the above will also be true , that means, it may
 * happen that the word in the Trie may extend further over
 * different number of branches, hence we check all the branches
 * one by one to see if any of the branches make a palindrome.
 */

/*
 * ------Another Possible Solution Could Be------------
 There's another way of solving this problem.It goes like this. First and 
 the reverse of every word in the trie. Then for every word, search it in
 the trie. If you find it, then that means the word was a palindrome itself
 and you can return true. If you don't find it , you need the length of the 
 part that you did find. For example, you're searching for "abcdd" in the 
 trie, you didn't find a match for "abcdd" but you found the word "abc" in
 the trie. Finding "abc" in the trie means that the actual word was "cba"
 since we inserted the reverse of every word in the list.
 Now, you have the word "abcdd", you found the word "abc" in the trie. If you
 can find whether the part of "abcdd" that comes after "abc" , i.e. "dd" is a 
 palindrome, you can conclude that concatenating "abcdd" and "cba" will also
 give a palindrome. So you can return true. If the part isn't a palindrome,
 you move to check for the next word.
 If you traverse through all words without finding a pair of words that 
 combine to form a palindrome or a word that's a palindrome by itself, then 
 you can return false.
 */
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>

// Class representing a node in the Trie
class TrieNode
{
public:
    char data;                                       // Character data for the node
    bool isTerminating;                              // Flag to check if this node is the end of a word
    std::vector<std::shared_ptr<TrieNode>> children; // Vector to hold children nodes (26 for each letter of the alphabet)
    int childCount;                                  // Number of children this node has

    // Constructor for TrieNode
    TrieNode(char data) : data(data), isTerminating(false), childCount(0)
    {
        children.resize(26, nullptr); // Vector for 26 possible children (one for each letter)
    }
};

// Main class to handle palindrome pair detection using Trie
class PalindromePair
{
private:
    std::shared_ptr<TrieNode> root; // Root node of the Trie
public:
    // Constructor for PalindromePair
    PalindromePair() : root(std::make_shared<TrieNode>('\0')) {}

    // Helper method to add a word to the Trie
    void add(std::shared_ptr<TrieNode> root, const std::string &word)
    {
        if (word.empty())
        {                               // Base case: if the word is empty
            root->isTerminating = true; // Mark the node as terminating a word
            return;
        }
        int childIndex = word[0] - 'a';           // Calculate index for the child node
        auto &child = root->children[childIndex]; // Get the child node
        if (!child)
        {                                                // If no such child node exists
            child = std::make_shared<TrieNode>(word[0]); // Create a new child node
            root->childCount++;                          // Increment child count
        }
        add(child, word.substr(1)); // Recursively add the rest of the word
    }

    // Public method to add a word to the Trie
    void add(const std::string &word)
    {
        add(root, word); // Call the recursive add method
    }

    // Recursive helper method to search for a word in the Trie
    bool search(std::shared_ptr<TrieNode> root, const std::string &word)
    {
        if (word.empty())
        {                               // Base case: if the word is empty
            return root->isTerminating; // Return true if the node terminates a word
        }
        int childIndex = word[0] - 'a';          // Calculate index for the child node
        auto child = root->children[childIndex]; // Get the child node
        if (!child)
        {                 // If no such child node exists
            return false; // Word not found
        }
        return search(child, word.substr(1)); // Recursively search in the child node
    }

    // Method to search for a word in the Trie
    bool search(const std::string &word)
    {
        return search(root, word); // Call recursive search method
    }

    void print(std::shared_ptr<TrieNode> root, const std::string &word)
    {
        if (!root)
            return;
        if (root->isTerminating)
        {
            std::cout << word << std::endl;
        }
        for (auto &child : root->children)
        {
            if (!child)
                continue;
            print(child, word + child->data);
        }
    }

    void print()
    {
        print(root, "");
    }

    // Method to check if there is a palindrome pair in the list of words
    bool isPalindromePair(const std::vector<std::string> &words)
    {
        for (const auto &word : words)
        {
            add(reverseWord(word));
        }
        return isPalindromePair(root, words);
    }

    std::string reverseWord(const std::string &word)
    {
        return std::string(word.rbegin(), word.rend());
    }

    bool isPalindromePair(std::shared_ptr<TrieNode> root, const std::vector<std::string> &words)
    {
        if (words.empty())
            return false;
        for (const auto &word : words)
        {
            if (doesPairExistFor(root, word, 0))
                return true;
        }
        return false;
    }

    bool doesPairExistFor(std::shared_ptr<TrieNode> root, const std::string &word, int startIndex)
    {
        if (word.empty())
            return true;

        if (startIndex == word.length())
        {
            if (root->isTerminating)
            {
                return true;
            }
            return checkRemainingBranchesInTrie(root, "");
        }

        int charIndex = word[startIndex] - 'a';
        auto correspondingChild = root->children[charIndex];

        if (!correspondingChild)
        {
            if (root->isTerminating)
            {
                return checkWordForPalindrome(word.substr(startIndex));
            }
            return false;
        }
        return doesPairExistFor(correspondingChild, word, startIndex + 1);
    }

    bool checkRemainingBranchesInTrie(std::shared_ptr<TrieNode> root, const std::string &word)
    {
        if (root->isTerminating)
        {
            if (checkWordForPalindrome(word))
                return true;
        }
        for (auto &child : root->children)
        {
            if (!child)
                continue;
            if (checkRemainingBranchesInTrie(child, word + child->data))
                return true;
        }
        return false;
    }

    bool checkWordForPalindrome(const std::string &word)
    {
        int startIndex = 0;
        int endIndex = word.length() - 1;

        while (startIndex < endIndex)
        {
            if (word[startIndex] != word[endIndex])
                return false;
            startIndex++;
            endIndex--;
        }
        return true;
    }

    static std::vector<std::string> takeInput()
    {
        std::vector<std::string> words;
        int n;
        std::cin >> n;
        std::cin.ignore(); // Ignore the newline character after the number

        if (n == 0)
            return words;

        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string word;
        while (iss >> word)
        {
            words.push_back(word);
        }

        return words;
    }

    static void main()
    {
        PalindromePair root;
        auto words = takeInput();
        std::cout << (root.isPalindromePair(words) ? "true" : "false") << std::endl;
    }
};

int main()
{
    PalindromePair::main();
    return 0;
}
