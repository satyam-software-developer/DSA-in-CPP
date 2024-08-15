
/*Problem statement
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.

Note:
Array A can contain duplicate elements as well.
Detailed explanation ( Input/output format, Notes, Images )
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0. 
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
Explanation
(2,-2) , (-2,2) will result in 0 , so the answer for the above problem is 2. */

/*
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * where n is the size of input array
 */

/*
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * where n is the size of input array
 */
#include <iostream>      // Include iostream for input-output operations
#include <unordered_map> // Include unordered_map for the hash map implementation
#include <vector>        // Include vector for dynamic array

using namespace std;

// Function to take input from the user
vector<int> takeInput()
{
    int size;
    cin >> size;             // Read the size of the array
    vector<int> input(size); // Initialize a vector of the given size

    // If size is 0, return the empty vector
    if (size == 0)
    {
        return input;
    }

    // Read the elements of the array
    for (int i = 0; i < size; ++i)
    {
        cin >> input[i];
    }

    return input; // Return the integer vector
}

// Function to print the elements of the array
void printArray(const vector<int> &arr)
{
    for (int element : arr)
    {
        cout << element << " "; // Print each element followed by a space
    }
    cout << endl; // Print a newline at the end
}

// Function to find pairs of elements that sum to zero
int PairSum(const vector<int> &input, int size)
{
    unordered_map<int, int> h; // Initialize an unordered_map to store the frequency of each number
    int finalCount = 0;        // Variable to store the final count of pairs that sum to zero

    // Populate the unordered_map with the frequency of each number
    for (int i = 0; i < size; i++)
    {
        int key = input[i];
        if (h.find(key) != h.end())
        {
            h[key] += 1; // Increment frequency value by 1 if key is already present in unordered_map
        }
        else
        {
            h[key] = 1; // Initialize frequency value to 1 if key is not already present in unordered_map
        }
    }

    // Traverse the array and check if the negative of each key is present in the unordered_map
    for (int i = 0; i < size; i++)
    {
        int key = input[i];

        if (h.find(-key) != h.end() && h[key] != 0)
        {
            int times;

            if (key == -key)
            { // True in case of zero
                int occurrences = h[key];
                times = (occurrences * (occurrences - 1)) / 2; // Calculate pairs for zeros
                finalCount += times;
                h[key] = 0; // Set frequency to 0 to avoid counting again
                continue;
            }

            times = h[key] * h[-key]; // Calculate pairs for key and -key
            finalCount += times;
            h[key] = 0;  // Set frequency to 0 to avoid counting again
            h[-key] = 0; // Set frequency to 0 to avoid counting again
        }
    }

    return finalCount; // Return the final count of pairs that sum to zero
}

// Main function to execute the program
int main()
{
    vector<int> arr = takeInput();            // Take input from the user
    cout << PairSum(arr, arr.size()) << endl; // Print the count of pairs that sum to zero

    return 0;
}
