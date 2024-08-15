
/* Problem statement
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.

Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in ascending order.


Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains an integer 'N' representing the size of the first array/list.

The second line contains 'N' single space separated integers representing the elements of the first the array/list.

The third line contains an integer 'M' representing the size of the second array/list.

The fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output format :
For each test case, print the intersection elements in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec 
Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10
Sample Output 1 :
2 3 4
10
Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 2 2
Explanation for Sample Output 2 :
Since, both input arrays have two '2's, the intersection of the arrays also have two '2's. The first '2' of first array matches with the first '2' of the second array. Similarly, the second '2' of the first array matches with the second '2' if the second array. */

#include <iostream>
#include <vector>
#include <algorithm> // For sort function
#include <sstream>   // For stringstream
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

    // Read the next line containing the elements of the array
    cin.ignore(); // Ignore the newline character after reading the size
    string line;
    getline(cin, line);
    stringstream ss(line);
    for (int i = 0; i < size; ++i)
    {
        ss >> input[i];
    }

    return input; // Return the integer vector
}

// Function to print the elements of the vector
void printVector(const vector<int> &arr)
{
    for (int element : arr)
    {
        cout << element << " "; // Print each element followed by a space
    }
    cout << endl; // Print a newline at the end
}

// Function to find the intersection of two arrays
void intersection(vector<int> &arr1, vector<int> &arr2)
{
    sort(arr1.begin(), arr1.end()); // Sort the first array
    sort(arr2.begin(), arr2.end()); // Sort the second array

    int n = arr1.size(); // Length of the first array
    int m = arr2.size(); // Length of the second array

    int i = 0; // Pointer to iterate over arr1
    int j = 0; // Pointer to iterate over arr2

    // Iterate through both arrays to find common elements
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        { // If elements are equal, print the element
            cout << arr1[i] << " ";
            i += 1; // Move both pointers forward
            j += 1;
        }
        else if (arr1[i] < arr2[j])
        { // If element in arr1 is smaller, move pointer i forward
            i += 1;
        }
        else
        { // If element in arr2 is smaller, move pointer j forward
            j += 1;
        }
    }
    cout << endl; // Print a newline at the end
}

// Main function to execute the program
int main()
{
    int t;
    cin >> t; // Read number of test cases

    // Iterate for each test case
    while (t > 0)
    {
        vector<int> arr1 = takeInput(); // Take input for the first array
        vector<int> arr2 = takeInput(); // Take input for the second array
        intersection(arr1, arr2);       // Find and print the intersection of the two arrays

        t -= 1; // Decrement the test case counter
    }

    return 0;
}
