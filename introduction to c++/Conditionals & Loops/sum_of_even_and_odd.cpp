
/*Problem statement
Write a program to input an integer 'n' and print the sum of all its even digits and the sum of all its odd digits separately.



Digits mean numbers, not places! That is, if the given integer is "132456", even digits are 2, 4, and 6, and odd digits are 1, 3, and 5.

Constraints
0<= 'n' <=10000


Example :
Input: 'n' = 132456

Output: 12 9

Explanation:
The sum of even digits = 2 + 4 + 6 = 12
The sum of odd digits = 1 + 3 + 5 = 9
Constraints
0<= 'n' <=10000


Example :
Input: 'n' = 132456

Output: 12 9

Explanation:
The sum of even digits = 2 + 4 + 6 = 12
The sum of odd digits = 1 + 3 + 5 = 9
Input format :
 The first line contains an integer 'n'.
Output format :
In a single line, print two space-separated integers, first the sum of even digits and then the sum of odd digits.
Sample Input 1:
132456


Sample Output 1:
12 9


Explanation of sample input 1 :
The sum of even digits = 2 + 4 + 6 = 12
The sum of odd digits = 1 + 3 + 5 = 9


Sample Input 2:
552245


Sample Output 2:
8 15
*/
#include<iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main(){
    int n; // Declare a variable to store the input integer
    cin >> n; // Read an integer from the standard input

    int evenSum = 0, oddSum = 0; // Initialize variables to store the sum of even and odd digits

    // Iterate through each digit of the input number until it becomes zero
    while(n > 0){
        int last = n % 10; // Extract the last digit of the number

        // Check if the last digit is even
        if(last % 2 == 0){
            evenSum = evenSum + last; // Add the even digit to the even sum
        }
        // If the last digit is odd
        else{
            oddSum = oddSum + last; // Add the odd digit to the odd sum
        }
        n = n / 10; // Remove the last digit from the number
    }

    // Print the sum of even and odd digits separated by a space
    cout << evenSum << " " << oddSum;

    return 0; // Indicate successful completion of the program
}
