
/*Problem statement
We are given a 4 digit number using digits 1 to 9. What is the maximum 3 digit number that 
we can make by removing one digit from the given integer.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input :
5438
Sample Output :
548
Explanation :
1. If we remove 5, the new number is 438.
2. If we remove 4, the new number is 538.
3. If we remove 3, the new number is 548.
4. If we remove 8, the new number is 543.
Out of the 4 cases removing 3 gives us the maximum 3 digit number i.e 548
*/
#include <iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

// Function to find the maximum number by removing one digit from the input number
int max_number(int n) {
    int maxNum = 0; // Variable to store the maximum number
    int i = 1; // Counter variable for digit positions
    // Loop to iterate through each digit position of the input number
    while (n / i > 0) {
        // Construct a new number by excluding one digit at a time
        int newNum = (n / (i * 10)) * i + n % i;
        i = i * 10; // Move to the next digit position
        if (maxNum < newNum) {
            maxNum = newNum; // Update the maximum number if the new number is greater
        }
    }
    return maxNum; // Return the maximum number
}

int main() {
    int n;
    cin >> n; // Read the input number from the standard input
    cout << max_number(n) << endl; // Call the function to find the maximum number and print it
    return 0; // Indicate successful completion of the program
}
