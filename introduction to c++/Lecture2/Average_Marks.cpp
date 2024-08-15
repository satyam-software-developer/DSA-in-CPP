
/*Problem statement
Write a program to input a name(as a single character) and marks of three tests as m1, m2, and m3 of a student considering all the three marks have been given in integer format.

Now, you need to calculate the average of the given marks and print it along with the name as mentioned in the output format section.

All the test marks are in integers and hence calculate the average in integer as well. That is, you need to print the integer part of the average only and neglect the decimal part.




Detailed explanation ( Input/output format, Notes, Images )
Constraints
Marks for each student lie in the range 0 to 100 (both inclusive)
Sample Test 1
Input:
R
0 100 99 
Output:
R 
66
*/
#include <iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main() {
    char name; // Declare a variable to store the name (assumed to be a single character)
    int m1, m2, m3; // Declare variables to store the marks of three subjects
    
    // Input: Read the name and marks of three subjects from the standard input
    cin >> name >> m1 >> m2 >> m3;

    // Calculate the average of the marks
    int avg = (m1 + m2 + m3) / 3; // Integer division to get the integer average
    
    // Output: Print the name followed by the average marks
    cout << name << endl; // Print the name
    cout << avg; // Print the average marks

    return 0; // Indicate successful completion of the program
}
