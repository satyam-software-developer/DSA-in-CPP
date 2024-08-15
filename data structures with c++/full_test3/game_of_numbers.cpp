
/* Problem statement
Given are two numbers X and Y. Starting from number X, we can perform two functions on the number:

Double: Multiply the number by 2, or
Decrement: Subtract 1 from the number.
Find the minimum number of operations required to convert X to Y.

Detailed explanation ( Input/output format, Notes, Images )
Input Format:
First line contains two space separated integers X and Y.
Output Format:
Print the minimum number of operations required to get Y, starting from X.
Constraints:
1 <= X,Y <= 10^9
Sample Input 1:
2 3
Sample Output 1:
2
Explanation:
Use double operation and then decrement operation {2 -> 4 -> 3}.
Sample Input 2:
1024 1
Sample Output 2:
1023
Explanation:
Use decrement operations 1023 times. */

#include <iostream> // Include the iostream library for input/output operations.

using namespace std;

// Function to find the minimum number of operations needed to convert Y to X.
// The operations are:
// - If Y is odd, increment it by 1.
// - If Y is even, divide it by 2.
int findMin(int X, int Y)
{
    int ans = 0; // Initialize the counter for the number of operations.

    // Loop until Y is greater than X.
    while (Y > X)
    {
        ans++; // Increment the operation counter.

        // If Y is odd, increment it by 1.
        if (Y % 2 == 1)
            Y++;
        // If Y is even, divide it by 2.
        else
            Y /= 2;
    }

    // The total operations needed are the sum of the operations performed
    // and the difference between X and Y after the loop (if any).
    return ans + X - Y;
}

int main()
{
    int x, y; // Declare variables to hold the input values.

    cin >> x >> y; // Read the integer values for X and Y.

    // Print the minimum number of operations needed to convert Y to X.
    cout << findMin(x, y) << endl;

    return 0;
}
