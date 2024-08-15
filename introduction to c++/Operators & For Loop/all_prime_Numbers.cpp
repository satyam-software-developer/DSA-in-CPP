
/*Problem statement
Given an integer N, print all the prime numbers that lie in the range 2 to N (both inclusive).

Print the prime numbers in different lines.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 100
Sample Input 1:
9
Sample Output 1:
2
3
5
7
Sample Input 2:
20
Sample Output 2:
2
3
5
7
11
13
17
19
*/
#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n; // Declare variable to store user input for the upper limit
    cin >> n; // Read the upper limit from the standard input

    // Iterate over numbers from 2 to n to find prime numbers
    for (int i = 2; i <= n; i++) {
        bool isPrime = true; // Initialize flag to true assuming the number is prime

        // Check if the current number (i) is prime
        for (int j = 2; j < i; j++) {
            if (i % j == 0) { // If the remainder is 0, the number is divisible
                isPrime = false; // Set the flag to false as the number is not prime
                break; // Break out of the inner loop as we've determined the number is not prime
            }
        }

        // If the number is prime (flag remains true), print it
        if (isPrime) {
            cout << i << endl; // Print the prime number
        }
    }

    return 0; // Indicate successful completion of the program
}
