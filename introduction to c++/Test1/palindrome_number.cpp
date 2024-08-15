
/*Problem statement
Check whether a given number ’n’ is a palindrome number.

Note :
Palindrome numbers are the numbers that don't change when reversed.
You don’t need to print anything. Just implement the given function.
Example:
Input: 'n' = 51415
Output: true
Explanation: On reversing, 51415 gives 51415.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
1032
Sample Output 1 :
false
Explanation Of Sample Input 1:
1032, on being reversed, gives 2301, which is a totally different number.
Sample Input 2 :
121
Sample Output 2 :
true
Explanation Of Sample Input 2:
121, on being reversed, gives 121, which is the same.
Expected time complexity:
The expected time complexity is O(log(n)).
Constraints :
1 <= n <= 10^9
Time Limit: 1 sec*/
#include <iostream>  // Include the necessary header file for input and output operations
using namespace std; // Using the standard namespace to simplify code

int main()
{
    int n;    // Declare a variable to store the input number
    cin >> n; // Read the input number from the standard input

    int temp = n, revNum = 0; // Declare variables to store the reverse and original numbers

    // Reverse the input number
    while (temp > 0)
    {
        int lastDigit = temp % 10;        // Extract the last digit of the number
        temp = temp / 10;                 // Remove the last digit from the number
        revNum = revNum * 10 + lastDigit; // Construct the reverse number
    }

    // Check if the original number is equal to its reverse
    if (n == revNum)
    {
        cout << "true" << endl; // If equal, print "true"
    }
    else
    {
        cout << "false" << endl; // If not equal, print "false"
    }

    return 0; // Indicate successful completion of the program
}
