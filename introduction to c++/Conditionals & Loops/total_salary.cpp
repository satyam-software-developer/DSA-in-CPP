#include<iostream> // Include the necessary header file for input and output operations
#include<iomanip> // Include the necessary header file for manipulating input/output formatting
#include<cmath> // Include the necessary header file for mathematical operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    double basic; // Declare a variable to store the basic salary
    cin >> basic; // Read the basic salary from the standard input
    char grade; // Declare a variable to store the grade of the employee
    cin >> grade; // Read the grade of the employee from the standard input

    // Calculate the house rent allowance (HRA) and dearness allowance (DA) based on the basic salary
    double hra = 0.2 * basic;
    double da = 0.5 * basic;

    int allowance; // Declare a variable to store the grade-based allowance
    // Determine the allowance based on the employee's grade
    if (grade == 'A') {
        allowance = 1700;
    } else if (grade == 'B') {
        allowance = 1500;
    } else {
        allowance = 1300;
    }

    double pf = 0.11 * basic; // Calculate the provident fund (PF) deduction based on the basic salary

    // Calculate the total salary by adding basic, HRA, DA, allowance, and deducting PF
    double totalSalary = basic + hra + da + allowance - pf;
    int ans = round(totalSalary); // Round off the total salary to the nearest integer using the round function
    cout << ans; // Output the rounded total salary

    return 0; // Indicate successful completion of the program
}
