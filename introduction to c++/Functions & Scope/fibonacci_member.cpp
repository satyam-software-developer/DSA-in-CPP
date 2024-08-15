

#include <iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

// Function to check if a number is a member of the Fibonacci series
bool checkMember(int n) {
    int a = 0; // Initialize the first number of the Fibonacci series
    int b = 1; // Initialize the second number of the Fibonacci series
    int c; // Declare a variable to store the sum of the previous two numbers
    while (a < n) { // Iterate until the current Fibonacci number is less than the given number
        c = a + b; // Calculate the next Fibonacci number
        a = b; // Update the first number to the value of the second number
        b = c; // Update the second number to the value of the sum of the previous two numbers
    }
    return a == n; // Return true if the given number is equal to the current Fibonacci number
}

// Main function
int main() {
    int n; // Declare a variable to store the input number
    cin >> n; // Read the input number from the standard input

    // Check if the input number is a member of the Fibonacci series
    if (checkMember(n)) {
        cout << "true" << endl; // If it is a member, print "true"
    } else {
        cout << "false" << endl; // If it is not a member, print "false"
    }

    return 0; // Indicate successful completion of the program
}

