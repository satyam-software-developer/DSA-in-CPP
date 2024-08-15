
/*Problem statement
Given input consists of n numbers. 
Check whether those n numbers form an arithmetic progression or not. 
Print true or false.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6
2 6 10 14 18 22
Sample Output 1 :
true
Sample Input 2 :
6
2 6 10 15 19 23
Sample Output 2 :
false*/

#include <iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare a variable to store the total number of elements in the sequence
    cin >> n; // Read the value of 'n' from the standard input

    int prev; // Declare a variable to store the previous element in the sequence
    cin >> prev; // Read the first element of the sequence

    int current; // Declare a variable to store the current element in the sequence
    cin >> current; // Read the second element of the sequence

    int count = 3; // Initialize the counter to 3 since we have already read two elements

    int d = current - prev; // Calculate the common difference between consecutive elements
    prev = current; // Update the value of 'prev' to the current element

    // Iterate over the remaining elements of the sequence
    while (count <= n) {
        cin >> current; // Read the next element of the sequence
        int tempD = current - prev; // Calculate the difference between the current element and the previous one
        if (tempD != d) { // Check if the difference is consistent with the common difference 'd'
            cout << "false"; // If not, print "false" and terminate the program
            return 0;
        }
        count++; // Increment the counter
        prev = current; // Update the value of 'prev' to the current element for the next iteration
    }
    cout << "true"; // If the sequence satisfies the condition, print "true"
    return 0; // Indicate successful completion of the program
}
