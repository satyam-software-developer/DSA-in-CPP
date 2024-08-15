

#include <iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

// Function to calculate the factorial of a number
int fact(int number) {
    int ans = 1; // Initialize the factorial to 1
    // Loop to calculate the factorial of 'number'
    for (int i = 1; i <= number; i++) {
        ans *= i; // Multiply 'ans' by 'i' in each iteration
    }
    return ans; // Return the factorial value
}

// Function to calculate the combination (n choose r)
int ncr(int num, int r) {
    // Calculate the combination using the factorial function
    int ans = fact(num) / (fact(num - r) * fact(r)); 
    return ans; // Return the combination value
}

// Function to calculate the probability
int probability(int n, int x) {
    // Calculate the numerator of the probability formula using combinations
    int ans = ncr(4, x) * ncr(4, n - x);
    // Calculate the probability by dividing the numerator by the total combinations
    double probab = static_cast<double>(ans) / ncr(8, n);
    // Convert the probability to a percentage and return the integer value
    return static_cast<int>(probab * 100);
}

// Main function
int main() {
    int n, x;
    // Read the values of 'n' and 'x' from the standard input
    cin >> n >> x;
    // Calculate and output the probability using the provided functions
    cout << probability(n, x) << endl;
    return 0; // Indicate successful completion of the program
}
