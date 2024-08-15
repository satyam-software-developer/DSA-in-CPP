
/* 
Problem statement
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.

That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
Output will be 1, as 1 is the minimum count of numbers required.

Note : x^y represents x raise to the power y.
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 50

Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/


#include <iostream>
#include <cmath> // Include cmath for square root function
#include <climits> // Include climits for INT_MAX constant
using namespace std;

// Function to calculate the minimum count of perfect squares that sum up to 'n'
int minCount(int n) {
    // Base case: if 'n' is less than or equal to 1, return 'n'
    if (n <= 1) {
        return n;
    }

    // Initialize 'ans' to 'n', as the maximum possible count is 'n'
    int ans = n;

    // Iterate from 1 to 'n'
    for (int i = 1; i <= n; i++) {
        // Calculate the square of 'i'
        int square = i * i;
        // If the square exceeds 'n', break the loop
        if (square > n) {
            break;
        }
        // Recursively calculate the minimum count for 'n - square' and add 1
        // Take the minimum of 'ans' and the calculated count
        ans = min(ans, minCount(n - square) + 1);
    }
    // Return the minimum count
    return ans;
}

// Main function to take input and call minCount function
int main() {
    // Read the number from the user
    int num;
    cin >> num;
    // Calculate and print the minimum count
    cout << minCount(num) << endl;
    return 0;
}
