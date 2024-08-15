
/*
Problem statement
Some of the keys on your keyboard are faulty. When you press a key, it may register more than once. That means if you want to type "code", the keyboard may interpret it as "code", "cccoddee" or "coode" or "codeeeee", etc. So, by pressing the keys C, O, D, and E in that order, you may get any of the above-mentioned words.

However, there are certain words that you will not get like, "cddde", "cod", "coeeeeed", etc.

You will be given 'N' pairs of words. The first word of each pair is what you intended to write and the second one is what the keyboard interprets it as. You need to figure out whether the second word can actually be a possible interpretation of the first word.

Detailed explanation ( Input/output format, Notes, Images )
Input format
The first line of the input contains a positive integer, N which represents the number of pairs of words
Every two lines after it will contain two words. The first one is what you typed, the second one is a potential interpretation of that word by the faulty keyboard.
Output format
The output will contain 'N' lines. Each line will be either "true" if the second word is a possible interpretation of the first word and "false" if it's not.
Constraints
1 <= N <= 10^5
1 <= L <= 10^6
where L is the total number of letters in all of the 2*N words
Time limit: 1 sec
Sample Input 1
2
code
cooodeee
hello
hheeeloo
Sample Output 1
true
false
*/

/*
 Time Complexity: O(N + M)
 Space Complexity: O(N + M)

 where N and M are the lengths of the two strings
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a character and its count
struct Pair
{
    char character;
    int count;

    Pair(char character, int count) : character(character), count(count) {}
};

// Function to split a string into groups of characters and their counts
vector<Pair> makeGroups(const string &s)
{
    vector<Pair> ret;
    char currChar = s[0];
    int currCharCount = 1;

    // Iterate through the string to form groups of characters and their counts
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == currChar)
        {
            ++currCharCount;
        }
        else
        {
            ret.push_back(Pair(currChar, currCharCount));
            currChar = s[i];
            currCharCount = 1;
        }
    }
    // Add the last character and its count to the list
    ret.push_back(Pair(currChar, currCharCount));

    return ret;
}

// Function to check if two strings can be typed with the same characters and counts
bool canType(const string &s1, const string &s2)
{
    // Generate character-count pairs for both strings
    vector<Pair> group1 = makeGroups(s1);
    vector<Pair> group2 = makeGroups(s2);

    // If the number of groups is different, strings cannot be typed the same way
    if (group1.size() != group2.size())
    {
        return false;
    }

    // Iterate through groups and compare characters and counts
    for (size_t i = 0; i < group1.size(); ++i)
    {
        if (group1[i].character != group2[i].character || group1[i].count > group2[i].count)
        {
            return false;
        }
    }
    // If all comparisons pass, strings can be typed the same way
    return true;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // Consume newline character after reading integer

    // Process each test case
    while (t-- > 0)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        // Check if strings can be typed the same way and print result
        cout << (canType(a, b) ? "true" : "false") << endl;
    }

    return 0;
}
