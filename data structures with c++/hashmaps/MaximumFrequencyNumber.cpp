
/*Problem statement
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.

If two or more elements are having the maximum frequency, return the element which occurs in the array first.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains most frequent element in the given array.
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6 
Sample Output 1 :
2
Sample Input 2 :
6
7 2 2 4 8 4
Sample Output 2 :
2
Explanation:
Here, both element '2' and element '4' have same frequency but '2' ocurr first in orignal array that's why we are returning '2' as output. */
/*
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * where n is size of input array
 */


/*
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * where n is size of input array
 */

#include <iostream>      // For input/output operations
#include <unordered_map> // For using the unordered_map container
#include <vector>        // For using the vector container
#include <sstream>       // For string stream operations

using namespace std;

// Function to take input from the user
vector<int> takeInput()
{
    int size;
    cin >> size;             // Read the size of the array
    vector<int> input(size); // Initialize a vector of the given size

    if (size == 0)
    {
        return input; // If size is 0, return the empty vector
    }

    // Ignore the newline character after the size input
    cin.ignore();

    string line;
    getline(cin, line);      // Read the next line containing the elements of the array
    istringstream iss(line); // Create a string stream from the input line

    for (int i = 0; i < size; ++i)
    {
        iss >> input[i]; // Extract each integer from the stream and store it in the vector
    }

    return input; // Return the integer vector
}

// Function to print the elements of the vector
void printArray(const vector<int> &arr)
{
    for (int element : arr)
    {
        cout << element << " "; // Print each element followed by a space
    }
    cout << endl;
}

// Function to find the number with the maximum frequency in the vector
int maxFrequencyNumber(const vector<int> &arr)
{
    // Initialize an unordered_map to store the frequency of each number
    unordered_map<int, int> hm;

    // Iterate through the vector and populate the unordered_map
    for (int i : arr)
    {
        if (hm.find(i) != hm.end())
        {
            hm[i]++; // Increment the frequency if the number is already present
        }
        else
        {
            hm[i] = 1; // Initialize the frequency to 1 if the number is not present
        }
    }

    // Initialize variables to keep track of the maximum frequency and the corresponding number
    int max = 0, ans = INT_MIN;
    // Iterate through the vector again to find the number with the highest frequency
    for (int i : arr)
    {
        if (hm[i] > max)
        {
            max = hm[i]; // Update the maximum frequency
            ans = i;     // Update the number with the highest frequency
        }
    }
    return ans; // Return the number with the highest frequency
}

// Main function to execute the program
int main()
{
    vector<int> arr = takeInput();           // Take input from the user
    cout << maxFrequencyNumber(arr) << endl; // Print the number with the highest frequency

    return 0;
}
