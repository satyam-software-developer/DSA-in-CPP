
/*Problem statement
Write a program that asks the user for a number N and a choice C. And then give them the possibility to choose between computing the sum and computing the product of all integers in the range 1 to N (both inclusive).

If C is equal to -
 1, then print the sum
 2, then print the product
 Any other number, then print '-1' (without the quotes)
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 12
Sample Input 1 :
10
1
Sample Output 1 :
55
Sample Input 2 :
10
2
Sample Output 2 :
3628800
Sample Input 3 :
10
4
Sample Output 3 :
-1*/
#include <iostream> // Include necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    int n, choice; // Declare variables to store the input number and choice
    cin >> n >> choice; // Read the input number and choice from the standard input

    if (choice == 1) { // Check if the choice is 1
        int sum = 0, num = 1; // Initialize variables for sum and starting number
        while (num <= n) { // Iterate while the current number is less than or equal to the input number
            sum += num; // Add the current number to the sum
            num++; // Increment the current number
        }
        cout << sum; // Output the sum
    } else if (choice == 2) { // Check if the choice is 2
        int product = 1, num = 1; // Initialize variables for product and starting number
        while (num <= n) { // Iterate while the current number is less than or equal to the input number
            product *= num; // Multiply the current number to the product
            num++; // Increment the current number
        }
        cout << product; // Output the product
    } else { // If the choice is neither 1 nor 2
        cout << "-1"; // Output -1 indicating invalid choice
    }
    return 0; // Indicate successful completion of the program
}
