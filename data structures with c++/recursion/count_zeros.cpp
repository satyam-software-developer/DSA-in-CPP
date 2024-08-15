
/*
Problem statement
Given an integer N, count and return the number of zeros that are present in the given integer using recursion.

Detailed explanation ( Input/output format, Notes, Images )
Input Format :
Integer N
Output Format :
Number of zeros in N
Constraints :
0 <= N <= 10^9
Sample Input 1 :
0
Sample Output 1 :
1
Sample Input 2 :
00010204
Sample Output 2 :
2
Explanation for Sample Output 2 :
Even though "00010204" has 5 zeros, the output would still be 2 because when you convert it to an integer, it becomes 10204.
Sample Input 3 :
708000
Sample Output 3 :
4
*/

/*
  Time Complexity : O(log(n))
  Space Complexity : O(log(n))

*/

#include <iostream>
using namespace std;

// Function to count zeros recursively
int countZeros(int n)
{
    // Base case: if n is a single digit number
    if (n <= 9)
    {
        // If n is zero, return 1, indicating one zero found
        if (n == 0)
        {
            return 1;
        }
        // If n is not zero, return 0, indicating no zeros found
        else
        {
            return 0;
        }
    }

    // If n has more than one digit
    // Extract the last digit of n
    int last = n % 10;
    int count = 0;

    // Check if the last digit is zero
    if (last == 0)
    {
        count = 1;
    }

    // Recursively call countZeros function with n/10 and add the count of zeros
    return count + countZeros(n / 10);
}

// Main function
int main()
{
    // Variable to store user input
    int n;
    // Prompt the user to enter an integer
    cin >> n;
    // Call the countZeros function with the input integer and print the result
    cout << countZeros(n) << endl;

    return 0;
}
