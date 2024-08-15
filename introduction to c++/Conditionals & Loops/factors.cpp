
/*Problem statement
Write a program that takes a number as input and prints all its factors except 1 and the number itself.. If the number has only two factors (1 and the number itself), then the program should print -1.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
A single integer, n
Output Format :
All the factors of n excluding 1 and the number itself
Constraints :
0 <= n <= 10,000
Sample Input 1 :
8
Sample Output 1 :
2 4
Explanation of Sample Output 1 :
The factors for the number excluding 1 and itself are 2 and 4, so the output is 2 4.
Sample Input 2 :
11
Sample Output 2 :
-1
Explanation of Sample Output 2 :
11 is a prime number having factors 1 and 11 so that output will be -1.

*/
#include<iostream> // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main(){
    int n; // Declare a variable to store the input integer
    cin >> n; // Read an integer from the standard input

    int i = 2; // Initialize a variable for the loop counter starting from 2
    bool a = false; // Initialize a boolean variable to track whether any factors are found

    // Iterate through numbers from 2 up to (n - 1) to find factors of n
    while(i < n){
        // Check if i is a factor of n
        if(n % i == 0){
            cout << i << " "; // If i is a factor, print it
            a = true; // Set the flag to true to indicate that factors are found
        }
        i++; // Increment the loop counter
    }

    // If no factors are found, print -1
    if(!a){
        cout << "-1" << endl;
    }

    return 0; // Indicate successful completion of the program
}
