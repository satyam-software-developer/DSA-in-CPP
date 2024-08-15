/*Problem statement
Given three values - Start Fahrenheit Value (S), End Fahrenheit value (E) and Step Size (W), you need to convert all Fahrenheit values from Start to End at the gap of W, into their corresponding Celsius values and print the table.

Hint : Use type casting
Detailed explanation ( Input/output format, Notes, Images )
Input Format :
3 integers - S, E and W respectively
Output Format :
Fahrenheit to Celsius conversion table. One line for every Fahrenheit and corresponding Celsius value in integer form. The Fahrenheit value and its corresponding Celsius value should be separate by single space.
Constraints :
0 <= S <= 90
S <= E <=  900
0 <= W <= 80
Sample Input 1:
0
100
20
Sample Output 1:
0   -17
20  -6
40  4
60  15
80  26
100 37
Sample Input 2:
20
119
13
Sample Output 2:
20  -6
33  0
46  7
59  15
72  22
85  29
98  36
111 43
Explanation For Input 2:
Start calculating the Celsius values for each Fahrenheit Value which starts from 20. So starting from 20, we need to compute its corresponding Celsius value which computes to -6. We print this information as <Fahrenheit Value> <a single space> <Celsius Value> on each line. Now add 13 to Fahrenheit Value at each step until you reach 119 in this case. You may or may not exactly land on the end value depending on the steps you are taking.

*/
#include <iostream>  // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

// Function to print a temperature conversion table from Fahrenheit to Celsius
void printTable(int start, int end, int step)
{
    // Initialize a variable to store the current Fahrenheit value
    int currentValue = start;

    // Iterate through the range of Fahrenheit values
    while (currentValue <= end)
    {
        // Convert the Fahrenheit value to Celsius using the formula
        int celsiusValue = (int)((5.0 / 9) * (currentValue - 32));

        // Print the current Fahrenheit and corresponding Celsius values, separated by a tab character
        cout << currentValue << '\t' << celsiusValue << endl;

        // Increment the current Fahrenheit value by the specified step
        currentValue += step;
    }
}

// Main function where the execution of the program starts
int main()
{
    int start, end, step; // Declare variables to store the start, end, and step values

    // Read the start, end, and step values from the standard input
    cin >> start >> end >> step;

    // Call the function to print the temperature conversion table
    printTable(start, end, step);

    return 0; // Indicate successful completion of the program
}
