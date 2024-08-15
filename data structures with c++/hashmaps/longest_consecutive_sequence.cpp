
/* Problem statement
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.

You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.

Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of  the longest consecutive sequence is 1, then just print the starting element.
Constraints :
0 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6 
Sample Output 1 :
8 12 
Explanation:The longest consecutive sequence here is [8, 9, 10, 11, 12]. So the output is the start and end of this sequence: [8, 12].
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation:There are two sequences of equal length here: [1,2,3] and [7,8,9]. But since [7,8,9] appears first in the array (7 comes before 1), we return this sequence. So the output is [7,9].
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16
Explanation:The longest consecutive sequence here is [15,16]. So the output is [15,16]. */

#include <iostream>      // For input and output operations
#include <vector>        // For the vector class
#include <unordered_map> // For the unordered_map class
#include <sstream>       // For stringstream class

using namespace std;

// Function to take input from the user
vector<int> takeInput()
{
    int size;
    cin >> size;             // Read the size of the array
    vector<int> input(size); // Initialize the vector with the given size

    // If the size is zero, return the empty vector
    if (size == 0)
    {
        return input;
    }

    // Read the input line
    string strNums;
    cin.ignore();          // Ignore the newline character after the size input
    getline(cin, strNums); // Read the line of numbers

    // Parse each element of the string to an integer and store it in the input vector
    stringstream ss(strNums);
    for (int i = 0; i < size; ++i)
    {
        ss >> input[i];
    }

    return input; // Return the input vector
}

// Function to print a vector of integers
void printArray(const vector<int> &arr)
{
    for (int element : arr)
    {
        cout << element << " "; // Print each element
    }
    cout << endl; // Print a newline at the end
}

// Function to find the longest consecutive increasing sequence in the input array
vector<int> longestConsecutiveIncreasingSequence(const vector<int> &arr)
{
    // Unordered map to keep track of visited elements
    unordered_map<int, bool> vis;
    // Unordered map to keep track of the indices of elements
    unordered_map<int, int> map;

    // Populate the maps with the elements of the array
    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        map[num] = i;     // Store the index of the current element
        vis[num] = false; // Initialize the visited map for the current element
    }

    // List to store the result
    vector<int> ls;

    // Variables to keep track of the longest sequence
    int globalMaxSequenceLength = 1;
    int globalMinStartIndex = 0;

    // Iterate through the array to find the longest consecutive sequence
    for (int i = 0; i < arr.size(); i++)
    {
        int num = arr[i];
        int currentMinStartIndex = i; // Initialize the current minimum start index
        int count = 0;
        int tempNum = num;

        // Forward traversal to find the length of the sequence
        while (vis.count(tempNum) && !vis[tempNum])
        {
            vis[tempNum] = true; // Mark visited elements as true
            count++;
            tempNum++;
        }

        // Backward traversal to find the length of the sequence
        tempNum = num - 1;
        while (vis.count(tempNum) && !vis[tempNum])
        {
            vis[tempNum] = true; // Mark visited elements as true
            count++;
            currentMinStartIndex = map[tempNum]; // Update the current minimum start index
            tempNum--;
        }

        // Update the global maximum sequence length and start index if a longer sequence is found
        if (count > globalMaxSequenceLength)
        {
            globalMaxSequenceLength = count;
            globalMinStartIndex = currentMinStartIndex;
        }
        else if (count == globalMaxSequenceLength)
        {
            // Update the start index if the current sequence is equal in length but has a smaller start index
            if (currentMinStartIndex < globalMinStartIndex)
            {
                globalMinStartIndex = currentMinStartIndex;
            }
        }
    }

    int globalStartNum = arr[globalMinStartIndex]; // Get the starting number of the longest sequence
    ls.push_back(globalStartNum);                  // Add the starting number to the result list

    // If the sequence length is greater than 1, add the end number of the sequence
    if (globalMaxSequenceLength > 1)
    {
        ls.push_back(globalStartNum + globalMaxSequenceLength - 1);
    }

    return ls; // Return the result list containing the longest consecutive increasing sequence
}

// Main function to execute the program
int main()
{
    vector<int> arr = takeInput();                               // Take input from the user
    vector<int> ans = longestConsecutiveIncreasingSequence(arr); // Find the longest consecutive increasing sequence
    printArray(ans);                                             // Print the result
    return 0;
}
