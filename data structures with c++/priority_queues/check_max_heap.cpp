/*Problem statement
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains true if it represents max-heap and false if it is not a max-heap.
Constraints:
1 <= N <= 10^5
1 <= Ai <= 10^5
Time Limit: 1 sec
Sample Input 1:
8
42 20 18 6 14 11 9 4
Sample Output 1:
true */

/*
 * Time complexity: O(N)
 * Space complexity: O(1)
 * 
 * where N is the size of the the input array
 */


#include <iostream> // For input/output operations
#include <vector>   // For using std::vector

// Function to check if the given vector represents a max heap
bool checkMaxHeap(const std::vector<int> &arr)
{
    int n = arr.size(); // Get the number of elements in the vector

    // Iterate over each element to check heap property
    for (int i = 0; 2 * i + 1 < n; ++i)
    {
        int leftChildIndex = 2 * i + 1;           // Index of the left child
        int rightChildIndex = leftChildIndex + 1; // Index of the right child

        // Check if the left child exists and is greater than the parent
        if (arr[i] < arr[leftChildIndex])
        {
            return false; // If left child is greater than parent, return false
        }

        // Check if the right child exists and is greater than the parent
        if (rightChildIndex < n && arr[i] < arr[rightChildIndex])
        {
            return false; // If right child is greater than parent, return false
        }
    }

    return true; // Return true if all heap properties are satisfied
}

int main()
{
    int n;
    std::cin >> n; // Read the size of the vector

    std::vector<int> input(n); // Initialize the vector with the size n

    // Read the elements of the vector
    for (int i = 0; i < n; ++i)
    {
        std::cin >> input[i];
    }

    // Check if the input vector represents a max heap and print the result
    std::cout << (checkMaxHeap(input) ? "true" : "false") << std::endl;

    return 0;
}
