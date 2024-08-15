
/*Problem statement
Write a program that takes a character as input and prints 1, 0, or -1 according to the following rules.



1, if the character is an uppercase alphabet (A - Z).
0, if the character is a lowercase alphabet (a - z).
-1, if the character is not an alphabet.


Example:
Input: The character is 'a'.

Output: 0

Explanation: The input character is lowercase, so our answer is 0.
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The only line contains a single character.


Output format :
The only line contains 1, 0, or -1 according to the above rules.
Sample Input 1 :
v


Sample Output 1 :
0


Explanation of Sample Input 1:
The input character is lowercase, so our answer is 0.


Sample Input 2 :
V


Sample Output 2 :
1


Explanation of Sample Input 2:
The input character is uppercase, so our answer is 1.


Sample Input 3 :
#


Sample Output 3 :
-1


Explanation of Sample Input 3:
The input character is not an alphabet, so our answer is -1.


Constraints :
The input can be any single character.


Hint:
Can you check in which range of characters ‘CH’ lie to check its type?*/

#include<iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main(){
    char c; // Declare a variable to store the input character
    cin >> c; // Read a character from the standard input

    // Check if the input character is an uppercase letter
    if(c >= 'A' && c <= 'Z'){
        cout << 1 << endl; // If the character is uppercase, print 1
    }
    // Check if the input character is a lowercase letter
    else if(c >= 'a' && c <= 'z'){
        cout << 0 << endl; // If the character is lowercase, print 0
    }
    // If the input character is neither uppercase nor lowercase
    else{
        cout << -1 << endl; // Print -1
    }

   return 0; // Indicate successful completion of the program
}
